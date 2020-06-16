#include <string>
#include <Pds/Matrix>
#include <Pds/Vector>
////////////////////////////////////////////////////////////////////////
#include <cmath>




double Pds::Matrix::Rms(void) const
{
    unsigned int lin,col;
    double S=0;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return Pds::Ra::Nan;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    S=S+this->array[lin][col]*this->array[lin][col];

    return sqrt(S/((this->ncol)*(this->nlin)));
}

double Pds::Matrix::MeanAbsolute(void) const
{
    unsigned int lin,col;
    double S=0;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return Pds::Ra::Nan;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    S=S+fabs(this->array[lin][col]);

    return S/((this->ncol)*(this->nlin));
}
 
double Pds::Matrix::MeanSquare(void) const
{
    unsigned int lin,col;
    double S=0;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return Pds::Ra::Nan;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    S=S+this->array[lin][col]*this->array[lin][col];

    return S/((this->ncol)*(this->nlin));
}


double Pds::Matrix::SumSquare(void) const
{
    unsigned int lin,col;
    double S=0;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return Pds::Ra::Nan;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    S=S+this->array[lin][col]*this->array[lin][col];

    return S;
}

double Pds::Matrix::Norm(void) const
{
    unsigned int lin,col;
    double S=0;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return Pds::Ra::Nan;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    S=S+this->array[lin][col]*this->array[lin][col];

    return sqrt(S);
}


double Pds::Matrix::PNorm1(void) const
{
    unsigned int lin,col;
    double S,max=0;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return Pds::Ra::Nan;
    
    for(col=0;col<this->ncol;col++)
    {
        S=0;
        
        for(lin=0;lin<this->nlin;lin++)
        S=S+fabs(this->array[lin][col]);
        
        if(S>max)   max=S;
    }
    return max;
}

double Pds::Matrix::PNormInf(void) const
{
    unsigned int lin,col;
    double S,max=0;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return Pds::Ra::Nan;
    
    for(lin=0;lin<this->nlin;lin++)
    {
        S=0;
        
        for(col=0;col<this->ncol;col++)
        S=S+fabs(this->array[lin][col]);
        
        if(S>max)   max=S;
    }
    return max;
}

////////////////////////////////////////////////////////////////////////

double Pds::Matrix::Dot(const Pds::Matrix &B) const
{
    unsigned int lin,col;
    double S=0;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return Pds::Ra::Nan;
    
    if((B.nlin!=this->nlin)||(B.ncol!=this->ncol))
    return Pds::Ra::Nan;
    
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    S=S+this->array[lin][col]*B.array[lin][col];

    return S;
}

////////////////////////////////////////////////////////////////////////
Pds::Vector Pds::Matrix::Multiindex(const Pds::Vector &ID) const
{
    if(ID.IsEmpty())            return Pds::Matrix();
    if(ID.Nel()!=this->Ncol())  return Pds::Matrix();
    
    Pds::Vector V(this->Nlin(),1.0);
    
    unsigned int lin,col;
    double col_index;
    for(col=0;col<this->Ncol();col++)
    {
        col_index=ID.Get(col);
        for(lin=0;lin<this->Nlin();lin++)
        {
            V.array[lin][0]=V.array[lin][0]*pow(this->array[lin][col],col_index);
        }
    }
    return V;
}
