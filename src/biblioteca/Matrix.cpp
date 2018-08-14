/*
 * Matrix.cpp
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

#include <cstdlib>
#include <string>
#include <iostream>

#include <PDS/Matrix>
#include <PDS/RealArraysDefines>



#include <sstream>
namespace patch
{
    template <typename T>
    std::string ToString(T val)
    {
        std::stringstream stream;
        stream << val;
        return stream.str();
    }
}


PDS::Matrix::Matrix(void)
{

    this->nlin=0;
    this->ncol=0;
    this->array=NULL;

}

PDS::Matrix::Matrix(unsigned int nlin,unsigned int ncol)
{

    this->nlin=nlin;
    this->ncol=ncol;
    this->array=NULL;

    if((nlin==0)||(ncol==0))
    {
        this->nlin=0;
        this->ncol=0;
        this->array=NULL;

        return;
    }
    
    this->array= PDS::Matrix::AllocateArray(nlin,ncol);
    if(this->array==NULL) 
    {
        this->nlin=0;
        this->ncol=0;

        return;
    }
}


PDS::Matrix::~Matrix(void)
{
    PDS::Matrix::ReleaseArray(this->array,this->nlin);

    this->nlin=0;
    this->ncol=0;
}

bool PDS::Matrix::IsNull(void) const
{
    if((this->nlin)==0)    return true;
    if((this->ncol)==0)    return true;
    if((this->array)==NULL)    return true;

    return false;
}

bool PDS::Matrix::IsNotNull(void) const
{
    if((this->nlin)==0)    return false;
    if((this->ncol)==0)    return false;
    if((this->array)==NULL)    return false;

    return true;
}

void PDS::Matrix::MakeNull(void)
{
    PDS::Matrix::ReleaseArray(this->array,this->nlin);
    this->nlin=0;
    this->ncol=0;
}

bool PDS::Matrix::IsSimilarTo(const PDS::Matrix &B) const
{
    if((this->nlin)!=B.nlin)    return false;
    if((this->ncol)!=B.ncol)    return false;
    
    if( ((this->array)==NULL)&&(B.array==NULL) )    return true;
    if( ((this->array)!=NULL)&&(B.array==NULL) )    return false;
    if( ((this->array)==NULL)&&(B.array!=NULL) )    return false;
    
    return true;
}
bool PDS::Matrix::IsNotSimilarTo(const PDS::Matrix &B) const
{
    if((this->nlin)!=B.nlin)    return true;
    if((this->ncol)!=B.ncol)    return true;
    
    if( ((this->array)==NULL)&&(B.array==NULL) )    return false;
    if( ((this->array)!=NULL)&&(B.array==NULL) )    return true;
    if( ((this->array)==NULL)&&(B.array!=NULL) )    return true;
 
    return false;
}

bool PDS::Matrix::InitRand(void)
{
    if(this->IsNull())   return false;
    
    unsigned int lin,col;

    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        this->array[lin][col]=rand()/(RAND_MAX+1.0);
    }

    return true;
}

bool PDS::Matrix::Init(double val)
{
    if(this->IsNull())   return false;

    unsigned int lin,col;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        this->array[lin][col]=val;
    }

    return true;
}



std::string PDS::Matrix::ToString(void) const
{
    std::string str="";
    if(this->IsNull())   return str;
    
    unsigned int lin,col;

    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        if(col!=(this->ncol-1))
        str=str+patch::ToString(this->array[lin][col])+"\t";
        else
        str=str+patch::ToString(this->array[lin][col])+"\n";
    }

    return str;
}

bool PDS::Matrix::operator = (const PDS::Matrix &A)
{
    return this->Copy(A);
}

bool PDS::Matrix::Copy(const PDS::Matrix &A)
{
    unsigned int lin,col;
    double **array=NULL;
    
    if(this!=&A) //Comprueba que no se esté intentando igualar un objeto a sí mismo
    {

        if(A.IsNull())
        {
            this->MakeNull();
            return true;
        }

        array= PDS::Matrix::AllocateArray(A.nlin,A.ncol);
        if(array==NULL) 
        {
            return false;
        }

        for (lin = 0; lin < A.nlin; lin++)
        for (col = 0; col < A.ncol; col++)
        {
                array[lin][col]=A.array[lin][col];
        }

        PDS::Matrix::ReleaseArray(this->array,this->nlin);

        this->nlin=A.nlin;
        this->ncol=A.ncol;
        this->array=array;
        
    }
    return true;
}


bool PDS::Matrix::operator +=(const PDS::Matrix &B)
{
    return this->Accumulate(B);
}

bool PDS::Matrix::Accumulate(const PDS::Matrix &B)
{
    if( this->IsNotSimilarTo(B) )    return false;
    if( B.IsNull() )                return true;

    unsigned int lin,col;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        this->array[lin][col]=this->array[lin][col]+B.array[lin][col];  
    }

    return true;
}

double** PDS::Matrix::AllocateArray(unsigned int Nlin,unsigned int Ncol)
{
    double **array=NULL;
    unsigned int lin,col;
    
    if((Nlin==0)||(Ncol==0))    return NULL;

    array= new double*[Nlin];
    if(array==NULL) return NULL;
    
    
    for (lin = 0; lin < Nlin; lin++)
    {
        array[lin] = new double[Ncol];
        if(array[lin]==NULL)
        {
            PDS::Matrix::ReleaseArray(array,lin);
            return NULL;
        }
        for (col = 0; col < Ncol; col++) array[lin][col]=0.0;
    }
    return array;
    
}

void PDS::Matrix::ReleaseArray(double** &array,unsigned int Nlin)
{
    if(array!=NULL)
    {
        for (unsigned int j = 0; j < Nlin; j++)
        { 
            delete [] array[j];
            array[j]=NULL;
        }
        delete [] array;
        array=NULL;
    }
}

std::ostream& operator<<(std::ostream &out,const PDS::Matrix &mat)
{
    out<<mat.ToString();
    return out;
}
