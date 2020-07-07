/*
 * FuncArrayLabeling.cpp
 * 
 * Copyright 2018 Fernando Pujaico Rivera <fernando.pujaico.rivera@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */



#include <Pds/FuncArrayLabeling>
#include <Pds/Ra>
#include <vector>
#include <set>
#include <list>
#include <iostream>


////////////////////////////////////////////////////////////////////////////////

/*
void print_stdvector_set(std::vector<std::set<unsigned int>> equiv)
{
    std::cout<<std::endl;
    for(unsigned int i=0;i<equiv.size();i++)
    {
        std::set<unsigned int>::iterator dat=equiv[i].begin();

        std::cout<<"equiv["<<i<<"]:\t";
        for(unsigned int j=0;j<equiv[i].size();j++)
        {
            std::cout<<*dat<<"\t";
            dat++;
        }
        std::cout<<std::endl;
    }
}


void print_stdvector_set(std::vector<unsigned int>  vec_equiv)
{
    unsigned int N=vec_equiv.size();
    
    for(unsigned int i=0;i<N;i++)   std::cout<<i<<"\t";
    std::cout<<"\n";
    for(unsigned int i=0;i<N;i++)   std::cout<<vec_equiv[i]<<"\t";
    std::cout<<"\n";
}
*/

void sort_stdvector_set(std::vector<std::set<unsigned int>> &equiv)
{
    std::set<unsigned int> CurrentSet;
    unsigned int check;

    for(unsigned int i=0;i<equiv.size();i++)
    if(equiv[i].size()>0)
    {
        // busco el id i en todos los equiv
        for(unsigned int j=0;j<equiv.size();j++)
        if(i!=j)
        if(equiv[j].size()>1)
        if(equiv[j].count(i)>0)
        {
            equiv[i].insert(equiv[j].begin(), equiv[j].end());
            equiv[j].clear();
        }

        do{
            CurrentSet=equiv[i];
            check=0;
            // Copio todos los Id de i em i
            for(std::set<unsigned int>::iterator dat=CurrentSet.begin(); dat!=CurrentSet.end(); ++dat)
            {
                if(*dat!=i)
                for(unsigned int k=0;k<equiv.size();k++)
                if(k!=i)
                if(equiv[k].size()>0)
                if(equiv[k].count(*dat)>0)
                {
                    equiv[i].insert(equiv[k].begin(), equiv[k].end());
                    equiv[k].clear();
                    check++;
                }
            }
        }while(check!=0);
    }
}


std::vector<unsigned int> vectorize_stdvector_set(std::vector<std::set<unsigned int>> &equiv)
{
    unsigned int N=equiv.size();
    std::vector<unsigned int> vec_equiv(N);
    unsigned int id=0;

    //for(unsigned int i=0;i<N;i++)   vec_equiv[i]=i;

    for(unsigned int i=0;i<N;i++)
    if(equiv[i].size()>0)
    {
        for(std::set<unsigned int>::iterator dat=equiv[i].begin(); dat!=equiv[i].end(); ++dat)
        {
            vec_equiv[*dat]=id;
        } 
        id++;
    }

    return vec_equiv;
}


Pds::Array<unsigned int> Pds::Image::IdMapUsingCC4(const Pds::Array<unsigned char> &B)
{
    if(B.IsEmpty()) return Pds::Array<unsigned int>();
    
    Pds::Array<unsigned int> ID(B.Size());
    
    unsigned int lin,col;
    unsigned int max_id=0;
    unsigned int id,id_up;
    
    //std::vector<unsigned int> lin_init;
    //lin_init.push_back(0);

    std::vector<std::set<unsigned int>> equiv;
    equiv.push_back({0});

    std::vector<unsigned int> vec_equiv;

    ////////////////////////////////////////////////////////////////////////////
    // Calculando ID con repeticion    
    for(lin=0;lin<B.Nlin();lin++)
    for(col=0;col<B.Ncol();col++)
    if(B.Get(lin,col)>0)
    {
        if(B.Get(lin,col-1)>0)
        {
            id=ID.At(lin,col)=ID.Get(lin,col-1);
            
            id_up=ID.Get(lin-1,col);
            if((id_up!=0)&&(id!=id_up))
            equiv[id].insert(ID.Get(lin-1,col));
        }
        else if(B.Get(lin-1,col)>0)
        {
            ID.At(lin,col)=ID.Get(lin-1,col);
        }
        else
        {
            max_id++;
            ID.At(lin,col)=max_id;
            // lin_init.push_back(lin);
            equiv.push_back({max_id});
        }
    }

    ////////////////////////////////////////////////////////////////////////////
    // Ordenando indices de repetidos
    
    //print_stdvector_set(equiv);
    sort_stdvector_set(equiv);  // Mejorar este codigo
    //print_stdvector_set(equiv);
    vec_equiv=vectorize_stdvector_set(equiv);
    //print_stdvector_set(vec_equiv);

    ////////////////////////////////////////////////////////////////////////////
    // aplicando cambios de ID
    for(lin=0;lin<ID.Nlin();lin++)
    {
        for(col=0;col<ID.Ncol();col++)
        {
            id=ID.Get(lin,col);
            if(id>0)
            {
                if(vec_equiv[id]!=id)
                ID.At(lin,col)=vec_equiv[id];
            }
        }
    }
    return ID;
}



std::vector<std::vector<Pds::Position>> Pds::Image::VectorGroupFromIdMap(const Pds::Array<unsigned int>  &B)
{   
    std::vector<std::vector<Pds::Position>> tmp;
    if(B.IsEmpty()) return tmp;
   
    unsigned int lin,col;
    unsigned int N=0;   

    ////////////////////////////////////////////////////////////////////////////
    // Averiguo el numero de grupos
    for(lin=0;lin<B.Nlin();lin++)
    for(col=0;col<B.Ncol();col++)
    if(B.Get(lin,col)>N)  
    N=B.Get(lin,col);

    std::vector<std::vector<Pds::Position>> Data(N);
    
    for(lin=0;lin<B.Nlin();lin++)
    for(col=0;col<B.Ncol();col++)
    if(B.Get(lin,col)!=0)
    Data[B.Get(lin,col)-1].push_back(Pds::Position(lin,col));
 
    return Data;   
}


Pds::RegionRect RegionOfGroup(const std::vector<Pds::Position> &Group)
{
    unsigned int min_lin,max_lin;
    unsigned int min_col,max_col;
    unsigned int N=Group.size();
    
    if(N==0) return Pds::RegionRect();

    for(unsigned int i=0;i<N;i++)
    {
        if(i==0)
        {
            min_lin=max_lin=Group[i].Lin;
            min_col=max_col=Group[i].Col;
        }
        else 
        {
            if(Group[i].Lin>(int)max_lin)    max_lin=Group[i].Lin;
            if(Group[i].Col>(int)max_col)    max_col=Group[i].Col;
            if(Group[i].Lin<(int)min_lin)    min_lin=Group[i].Lin;
            if(Group[i].Col<(int)min_col)    min_col=Group[i].Col;
        }
    }
    return Pds::RegionRect(min_lin,min_col,max_lin-min_lin+1,max_col-min_col+1);
}


std::vector<Pds::Position> Pds::Image::PerimeterGroupOfGroup(const std::vector<Pds::Position> &Data)
{
    Pds::RegionRect R;
    unsigned int N=Data.size();
    unsigned i;
    std::vector<Pds::Position> tmp;
    if(N==0)    return tmp;
    
    R=RegionOfGroup(Data);

    Pds::Array<unsigned char> A(R.Nlin+2,R.Ncol+2);
    unsigned int lin,col;

    for(i=0;i<N;i++)    A.At(Data[i].Lin-R.L0+1,Data[i].Col-R.C0+1)=1;
    
    ////////////////////////////////////////////////////////////////////////////
    std::vector<Pds::Position> Per;

    //Pds::Matrix Test(A.Size());
    
    for(lin=0;lin<A.Nlin();lin++)
    for(col=0;col<A.Ncol();col++)
    if(A.Get(lin,col)==0)
    if((A.Get(lin,col-1)==1)||(A.Get(lin,col+1)==1)||(A.Get(lin-1,col)==1)||(A.Get(lin+1,col)==1))
    {
        Per.push_back(Pds::Position(lin-1+R.L0,col-1+R.C0));
        //Test.At(lin,col)=1;
    }
    
    //Test.Scale(0,255).ExportBmpFile(Pds::Colormap::Gray,"Region.bmp");
    //A.Scale(0,255).ExportBmpFile(Pds::Colormap::Gray,"RegionA.bmp");
    return Per;
}

double Pds::Image::PerimeterOfConvexGroup(const std::vector<Pds::Position> &Data)
{
    Pds::RegionRect R;
    unsigned int N=Data.size();
    unsigned i;
    if(N==0)    return Pds::Ra::Nan;
    
    R=RegionOfGroup(Data);

    Pds::Array<unsigned char> A(R.Nlin+2,R.Ncol+2);
    unsigned int lin,col;

    for(i=0;i<N;i++)    A.At(Data[i].Lin-R.L0+1,Data[i].Col-R.C0+1)=1;
    
    ////////////////////////////////////////////////////////////////////////////

    unsigned int last_col=0;
    unsigned int last_lin=0;
    unsigned int per_size=0;

    Pds::Matrix Test(A.Size());
    double sqrt_of_2=sqrt(2);
    
    for(lin=0;lin<A.Nlin();lin++)
    for(col=0;col<A.Ncol();col++)
    if(A.Get(lin,col)==0)
    if((A.Get(lin,col-1)==1)||(A.Get(lin,col+1)==1)||(A.Get(lin-1,col)==1)||(A.Get(lin+1,col)==1))
    {
        Test.At(lin,col)=1;
        last_lin=lin;
        last_col=col;
        per_size++;
    }
    
    //Test.Scale(0,255).ExportBmpFile(Pds::Colormap::Gray,std::to_string(N)+"Region.bmp");

    if(Test.Get(last_lin,last_col)!=1)  return Pds::Ra::Nan;

    double Per=0;
    unsigned int lin0=last_lin;
    unsigned int col0=last_col;
    
    Test.Set(lin0,col0,0);
    for(unsigned int i=0;i<per_size;i++)
    {
        if(i==2) Test.Set(lin0,col0,1);
        
        if(Test.Get(last_lin-1,last_col-1)==1)
        {
            Per=Per+sqrt_of_2;
            last_lin=last_lin-1;
            last_col=last_col-1;
        }
        else if(Test.Get(last_lin-1,last_col+1)==1)
        {
            Per=Per+sqrt_of_2;
            last_lin=last_lin-1;
            last_col=last_col+1;
        }
        else if(Test.Get(last_lin+1,last_col-1)==1)
        {
            Per=Per+sqrt_of_2;
            last_lin=last_lin+1;
            last_col=last_col-1;
        }
        else if(Test.Get(last_lin+1,last_col+1)==1)
        {
            Per=Per+sqrt_of_2;
            last_lin=last_lin+1;
            last_col=last_col+1;
        }
        else if(Test.Get(last_lin-1,last_col)==1)
        {
            Per=Per+1;
            last_lin=last_lin-1;
        }
        else if(Test.Get(last_lin,last_col-1)==1)
        {
            Per=Per+1;
            last_col=last_col-1;
        }
        else if(Test.Get(last_lin,last_col+1)==1)
        {
            Per=Per+1;
            last_col=last_col+1;
        }
        else if(Test.Get(last_lin+1,last_col)==1)
        {
            Per=Per+1;
            last_lin=last_lin+1;
        }
        else 
        {
            return Pds::Ra::Nan;
        }

        Test.Set(last_lin,last_col,0);

    //Test.Scale(0,255).ExportBmpFile(Pds::Colormap::Gray,
    //std::to_string(N)+"-"+
    //std::to_string(Per)+"-"+
    //std::to_string(i)+"Region.bmp");
    }
    return Per;
}
