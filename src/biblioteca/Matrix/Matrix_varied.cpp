#include <string>
#include <iostream>
#include <Pds/Matrix>
#include <Pds/RaDefines>
#include <Pds/RaTools>
#include <Pds/RaString>

////////////////////////////////////////////////////////////////////////

bool Pds::Matrix::Scale(double minval,double maxval)
{
    unsigned int lin,col;
    if(minval==maxval)  return false;
    if(this->IsEmpty()) return false;

    double a=minval>maxval?maxval:minval;
    double b=maxval>minval?maxval:minval;
    minval=a;
    maxval=b;
    
    double mindat=this->Min();
    double maxdat=this->Max();

    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        this->array[lin][col]=minval+(maxval-minval)*(this->array[lin][col]-mindat)/(maxdat-mindat);
    }

    return true;
}

////////////////////////////////////////////////////////////////////////

void Pds::Matrix::MakeEmpty(void)
{
    Pds::Matrix::ArrayRelease(this->array,this->nlin);
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



