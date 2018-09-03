#include <Pds/Matrix>
#include <cmath>

////////////////////////////////////////////////////////////////////////
double Pds::Matrix::Max(unsigned int *id) const
{
    unsigned int lin,col;
    double S;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return 0.0;
    
    S=this->array[0][0];
    if(id!=NULL) *id=0;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    if(this->array[lin][col]>S)
    {
        S=this->array[lin][col];
        if(id!=NULL) *id=col*(this->nlin)+lin;
    }

    return S;
}

////////////////////////////////////////////////////////////////////////
double Pds::Matrix::Min(unsigned int *id) const
{
    unsigned int lin,col;
    double S;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return 0.0;
    
    S=this->array[0][0];
    if(id!=NULL) *id=0;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    if(this->array[lin][col]<S)
    {
        S=this->array[lin][col];
        if(id!=NULL) *id=col*(this->nlin)+lin;
    }

    return S;
}

////////////////////////////////////////////////////////////////////////
double Pds::Matrix::Sum(void) const
{
    unsigned int lin,col;
    double S;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return 0.0;
    
    S=0;
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    S=S+this->array[lin][col];
    
    return S;
}

////////////////////////////////////////////////////////////////////////
double Pds::Matrix::Mean(void) const
{
    unsigned int lin,col;
    double S;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return 0.0;
    
    S=0;
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    S=S+this->array[lin][col];
    
    return S/(this->nlin*this->ncol);
}

////////////////////////////////////////////////////////////////////////
double Pds::Matrix::Std(double *mean) const
{
    unsigned int lin,col;
    double S;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return 0.0;
    
    double m=this->Mean();
    if(mean!=NULL)  *mean=m;
    
    S=0;
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    S=S+(this->array[lin][col]-m)*(this->array[lin][col]-m);
    
    return sqrt(S/(this->nlin*this->ncol));
}

////////////////////////////////////////////////////////////////////////
double Pds::Matrix::Corr(const Pds::Matrix &B) const
{
    unsigned int lin,col;
    double S;
    
    if((B.nlin==0)||(B.ncol==0)||(B.array==NULL))
    return 0.0;
        
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return 0.0;

    double m1;
    double m2;
    double std1=this->Std(&m1);
    double std2=B.Std(&m2);
    
    S=0;
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    S=S+(this->array[lin][col]-m1)*(B.array[lin][col]-m2);
    
    return S/(this->nlin*this->ncol*std1*std2);
}
