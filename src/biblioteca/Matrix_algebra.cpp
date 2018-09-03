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
