#include <Pds/Matrix>



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

bool Pds::Matrix::Apply( double (*func)(double,double),double var)
{
    if(this->IsEmpty())   return false;
    
    unsigned int lin,col;

    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        this->array[lin][col]=(*func)(this->array[lin][col],var);
    }
    return true;
}

////////////////////////////////////////////////////////////////////////

bool Pds::Matrix::ApplyInCol(unsigned int col,double (*func)(double))
{
    if(this->IsEmpty())   return false;
    
    unsigned int lin;

    for(lin=0;lin<this->nlin;lin++)
    {
        this->array[lin][col]=(*func)(this->array[lin][col]);
    }
    return true;
}


////////////////////////////////////////////////////////////////////////

bool Pds::Matrix::ApplyInCol(unsigned int col, double (*func)(double,double),double var)
{
    if(this->IsEmpty())   return false;
    
    unsigned int lin;

    for(lin=0;lin<this->nlin;lin++)
    {
        this->array[lin][col]=(*func)(this->array[lin][col],var);
    }
    return true;
}

