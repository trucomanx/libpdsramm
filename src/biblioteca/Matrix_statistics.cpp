#include <Pds/Matrix>
#include <cmath>
////////////////////////////////////////////////////////////////////////
double Pds::Matrix::MaxAbs(unsigned int *id) const
{
    unsigned int lin,col;
    double S;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return 0.0;
    
    S=fabs(this->array[0][0]);
    if(id!=NULL) *id=0;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    if(fabs(this->array[lin][col])>S)
    {
        S=fabs(this->array[lin][col]);
        if(id!=NULL) *id=col*(this->nlin)+lin;
    }

    return S;
}

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
double Pds::Matrix::MinAbs(unsigned int *id) const
{
    unsigned int lin,col;
    double S;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return 0.0;
    
    S=fabs(this->array[0][0]);
    if(id!=NULL) *id=0;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    if(fabs(this->array[lin][col])<S)
    {
        S=fabs(this->array[lin][col]);
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

////////////////////////////////////////////////////////////////////////
Pds::Matrix Pds::Matrix::XCorr(const Pds::Matrix &B, bool Same) const
{
    if(this->IsEmpty()) return Pds::Matrix();
    if(B.IsEmpty())     return Pds::Matrix();
    
    unsigned int Nlin=this->nlin;
    if(Same==false)  Nlin+=B.nlin-1;
    
    unsigned int Ncol=this->ncol;
    if(Same==false)  Ncol+=B.ncol-1;
    

    unsigned int lin,col;
    
    Pds::Matrix C(Nlin,Ncol);
    double S;
    
    int q_init,q_end;
    int r_init,r_end;
    int q,r;
    int k,l;
    
    for(lin=0;lin<Nlin;lin++)
    for(col=0;col<Ncol;col++)
    {
        
        k =  (Same==true) ? 0: 1-(int)B.nlin;
        k+=lin;
        l =  (Same==true) ? 0: 1-(int)B.ncol;
        l+=col;
        
        q_init=std::max(0,k);
        r_init=std::max(0,l);
        q_end=std::min(this->nlin-1,B.nlin+k-1);
        r_end=std::min(this->ncol-1,B.ncol+l-1);
    
        S=0;
        for(q=q_init;q<=q_end;q++)
        for(r=r_init;r<=r_end;r++)
        S+=this->array[q][r]*B.array[q-k][r-l];
        
        C.array[lin][col]=S;
    }
    
    return C;
}
