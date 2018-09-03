#include <string>
#include <Pds/RealArrays>

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

bool Pds::Matrix::Apply( double (*func)(double) )
{
    if(this->IsEmpty())   return false;
    
    unsigned int lin,col;

    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        this->array[lin][col]=(*func)(this->array[lin][col]);
    }
    return true;
}

////////////////////////////////////////////////////////////////////////

bool Pds::Matrix::Save(const char* filepath) const
{
    return Pds::Matrix::ArraySave(filepath,this->array,this->nlin,this->ncol);
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
////////////////////////////////////////////////////////////////////////
