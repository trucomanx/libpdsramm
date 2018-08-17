#include <string>
#include <PDS/Matrix>

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

std::string PDS::Matrix::ToString(void) const
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

void PDS::Matrix::Print(std::string str) const
{
    std::cout<<str;

    if(this->IsVoid())   return;
    
    unsigned int lin,col;

    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        if(col!=(this->ncol-1))
        std::cout<<patch::ToString(this->array[lin][col])+"\t";
        else
        std::cout<<patch::ToString(this->array[lin][col])+"\n";
    }
}

void PDS::Matrix::Print(void) const
{
    this->Print("");
}
