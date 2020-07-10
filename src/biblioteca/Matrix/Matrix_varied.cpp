#include <string>
#include <list>
#include <iostream>
#include <Pds/Matrix>
#include <Pds/RaDefines>
#include <Pds/RaTools>
#include <Pds/RaString>
////////////////////////////////////////////////////////////////////////

Pds::Matrix Pds::Matrix::Round(unsigned int decimal) const
{
    unsigned int lin,col;
    if(this->IsEmpty()) return Pds::Matrix();

    Pds::Matrix Ans(this->Size());
    if(Ans.IsEmpty())  return Pds::Matrix();
    
    double a=pow(10,decimal);
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        Ans.array[lin][col]=round(this->array[lin][col]*a)/a;
    }

    return Ans;
}
////////////////////////////////////////////////////////////////////////

Pds::Matrix Pds::Matrix::Scale(double minval,double maxval) const
{
    unsigned int lin,col;
    if(minval==maxval)  return Pds::Matrix();
    if(this->IsEmpty()) return Pds::Matrix();

    Pds::Matrix Ans(this->Size());
    if(Ans.IsEmpty())  return Pds::Matrix();
    
    double a=minval>maxval?maxval:minval;
    double b=maxval>minval?maxval:minval;
    minval=a;
    maxval=b;
    
    double mindat=this->Min();
    double maxdat=this->Max();

    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        Ans.array[lin][col]=minval+(maxval-minval)*(this->array[lin][col]-mindat)/(maxdat-mindat);
    }

    return Ans;
}

////////////////////////////////////////////////////////////////////////

void Pds::Matrix::MakeEmpty(void)
{
    Pds::Array<double>::ArrayRelease(this->array,this->nlin);
    this->nlin=0;
    this->ncol=0;
}
////////////////////////////////////////////////////////////////////////

#include <iomanip>      // std::setprecision
void Pds::Matrix::Print(std::string str) const
{
    std::cout<<str;

    if(this->IsEmpty())   return;
    
    std::cout<<std::setprecision(Pds::Ra::StringPrecision);
    unsigned int lin,col;

    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        std::cout<<this->array[lin][col];

        if(col!=(this->ncol-1)) std::cout<<"\t";
        else                    std::cout<<"\n";
    }

}

void Pds::Matrix::Print(void) const
{
    this->Print("");
}

////////////////////////////////////////////////////////////////////////

std::string Pds::Matrix::ToString(void) const
{
    std::string str="";
    if(this->IsEmpty())   return str;
    
    unsigned int lin,col;

    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        if(col!=(this->ncol-1))
        str=str+Pds::Ra::ToString(this->array[lin][col])+"\t";
        else
        str=str+Pds::Ra::ToString(this->array[lin][col])+"\n";
    }

    return str;
}

///////////////////////////////////////////////////////////////////////////////

bool Pds::Matrix::Reshape(unsigned int Nlin,unsigned int Ncol)
{
    if((Nlin==0)||(Ncol==0))    return false;
    
    double **new_array= Pds::Array<double>::ArrayReshape(*this,Nlin,Ncol);
    if(new_array==NULL)       return false;
    
    Pds::Array<double>::ArrayRelease(this->array,this->nlin);

    this->array=new_array;
    this->nlin=Nlin;
    this->ncol=Ncol;
    return true;
}


////////////////////////////////////////////////////////////////////////////////
bool Pds::Matrix::FusionVer(std::list<Pds::Matrix> &list)
{
    unsigned int Ncol=0;
    unsigned int Nlin=0;
    
    this->MakeEmpty();
    
    unsigned int i=0;
    for (auto pmat = list.begin(); pmat != list.end(); pmat++) 
    {
        if(i==0)    Ncol=pmat->Ncol();
        else
        {
            if(pmat->Ncol()!=Ncol)
            {
                pds_print_error_message("The "<<i<<"-th matrix in list don't have the same column length of 0-th.");
                return false;
            }
        }

        Nlin=Nlin+pmat->Nlin();
        i++;
    }
    
    this->array= new double*[Nlin];
    if(this->array==NULL) return false;
    this->nlin=Nlin;
    this->ncol=Ncol;    

    unsigned int lin=0;
    for (auto pmat = list.begin(); pmat != list.end(); pmat++) 
    {        
        for(unsigned int i=0;i<pmat->nlin;i++,lin++)
        {
            this->array[lin]=pmat->array[i];
            pmat->array[i]=NULL;
        }
        pmat->MakeEmpty();
    }

    return true;
}


