#include <string>
#include <Pds/Matrix>
#include <Pds/RealArraysDefines>

#include <iomanip>      // std::setprecision
void Pds::Matrix::Print(std::string str) const
{
    std::cout<<str;

    if(this->IsVoid())   return;
    
    std::cout<<std::setprecision(PDS_SET_PRECISION);
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


bool Pds::Matrix::Apply( double (*func)(double) )
{
    if(this->IsVoid())   return false;
    
    unsigned int lin,col;

    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        this->array[lin][col]=(*func)(this->array[lin][col]);
    }
    return true;
}

bool Pds::Matrix::Save(const char* filepath) const
{
    return Pds::Matrix::SaveArray(filepath,this->array,this->nlin,this->ncol);
}

#include <sstream>
#include <iomanip>      // std::setprecision
namespace patch
{
    template <typename T>
    std::string ToString(T val)
    {
        std::stringstream stream;
        stream <<std::setprecision(PDS_SET_PRECISION)<< val;
        return stream.str();
    }
}

std::string Pds::Matrix::ToString(void) const
{
    std::string str="";
    if(this->IsVoid())   return str;
    
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
