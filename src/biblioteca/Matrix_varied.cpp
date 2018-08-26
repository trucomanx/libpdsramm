#include <string>
#include <Pds/RealArrays>

////////////////////////////////////////////////////////////////////////
#include <cmath>
double Pds::Matrix::Norm(void) const
{
    unsigned int lin,col;
    double S=0;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return 0.0;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    S=S+this->array[lin][col]*this->array[lin][col];

    return sqrt(S);
}

double Pds::Matrix::Norm1(void) const
{
    unsigned int lin,col;
    double S,max=0;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return 0.0;
    
    for(col=0;col<this->ncol;col++)
    {
        S=0;
        
        for(lin=0;lin<this->nlin;lin++)
        S=S+fabs(this->array[lin][col]);
        
        if(S>max)   max=S;
    }
    return max;
}

////////////////////////////////////////////////////////////////////////

#include <iomanip>      // std::setprecision
void Pds::Matrix::Print(std::string str) const
{
    std::cout<<str;

    if(this->IsVoid())   return;
    
    std::cout<<std::setprecision(Pds::Ra::SetPrecision);
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
    if(this->IsVoid())   return false;
    
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
    return Pds::Matrix::SaveArray(filepath,this->array,this->nlin,this->ncol);
}

////////////////////////////////////////////////////////////////////////
std::string Pds::Matrix::ToString(void) const
{
    std::string str="";
    if(this->IsVoid())   return str;
    
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
