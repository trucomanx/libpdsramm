#include <cstdlib>
#include <Pds/Matrix>
#include <Pds/RaDefines>
#include <Pds/RaTools>
#include <Pds/RaString>
#include <Pds/RaFile>

////////////////////////////////////////////////////////////////////////

double** Pds::Matrix::ArrayAllocate(double (*func)(double),const Pds::Matrix &A)
{
    double **array=NULL;
    unsigned int lin,col;
    
    if((A.nlin==0)||(A.ncol==0)||(A.array==NULL))    return NULL;

    array= new double*[A.nlin];
    if(array==NULL) return NULL;
    
    
    for (lin = 0; lin < A.nlin; lin++)
    {
        array[lin] = new double[A.ncol];
        if(array[lin]==NULL)
        {
            Pds::Array<double>::ArrayRelease(array,lin);
            return NULL;
        }
        for (col = 0; col < A.ncol; col++) array[lin][col]=(*func)(A.array[lin][col]);
    }
    return array;
    
}
////////////////////////////////////////////////////////////////////////

double** Pds::Matrix::ArrayAllocate(double (*func)(double,double),const Pds::Matrix &A,double var)
{
    double **array=NULL;
    unsigned int lin,col;
    
    if((A.nlin==0)||(A.ncol==0)||(A.array==NULL))    return NULL;

    array= new double*[A.nlin];
    if(array==NULL) return NULL;
    
    
    for (lin = 0; lin < A.nlin; lin++)
    {
        array[lin] = new double[A.ncol];
        if(array[lin]==NULL)
        {
            Pds::Array<double>::ArrayRelease(array,lin);
            return NULL;
        }
        for (col = 0; col < A.ncol; col++) array[lin][col]=(*func)(A.array[lin][col],var);
    }
    return array;
    
}
////////////////////////////////////////////////////////////////////////

double** Pds::Matrix::ArrayAllocate(double (*func)(double,double),const Pds::Matrix &A,const Pds::Matrix &B)
{
    double **array=NULL;
    unsigned int lin,col;
    
    if((A.nlin==0)||(A.ncol==0)||(A.array==NULL))   return NULL;
    if((B.nlin==0)||(B.ncol==0)||(B.array==NULL))   return NULL;
    if((A.nlin!=B.nlin)||(A.ncol!=B.ncol))          return NULL;

    array= new double*[A.nlin];
    if(array==NULL) return NULL;
    
    
    for (lin = 0; lin < A.nlin; lin++)
    {
        array[lin] = new double[A.ncol];
        if(array[lin]==NULL)
        {
            Pds::Array<double>::ArrayRelease(array,lin);
            return NULL;
        }
        for (col = 0; col < A.ncol; col++) array[lin][col]=(*func)(A.array[lin][col],B.array[lin][col]);
    }
    return array;
    
}
////////////////////////////////////////////////////////////////////////

double** Pds::Matrix::ArrayAllocate(double (*func)(double,double,double),const Pds::Matrix &A,const Pds::Matrix &B,double var)
{
    double **array=NULL;
    unsigned int lin,col;
    
    if((A.nlin==0)||(A.ncol==0)||(A.array==NULL))   return NULL;
    if((B.nlin==0)||(B.ncol==0)||(B.array==NULL))   return NULL;
    if((A.nlin!=B.nlin)||(A.ncol!=B.ncol))          return NULL;

    array= new double*[A.nlin];
    if(array==NULL) return NULL;
    
    
    for (lin = 0; lin < A.nlin; lin++)
    {
        array[lin] = new double[A.ncol];
        if(array[lin]==NULL)
        {
            Pds::Array<double>::ArrayRelease(array,lin);
            return NULL;
        }
        for (col = 0; col < A.ncol; col++) 
        array[lin][col]=(*func)(A.array[lin][col],B.array[lin][col],var);
    }
    return array;
    
}

////////////////////////////////////////////////////////////////////////

double** Pds::Matrix::ArrayAllocate(double (*func)(double,double,double),const Pds::Matrix &A,const Pds::Matrix &B,const Pds::Matrix &C)
{
    double **array=NULL;
    unsigned int lin,col;
    
    if((A.nlin==0)||(A.ncol==0)||(A.array==NULL))   return NULL;
    if((B.nlin==0)||(B.ncol==0)||(B.array==NULL))   return NULL;
    if((C.nlin==0)||(C.ncol==0)||(C.array==NULL))   return NULL;
    if((A.nlin!=B.nlin)||(A.ncol!=B.ncol))          return NULL;
    if((A.nlin!=C.nlin)||(A.ncol!=C.ncol))          return NULL;

    array= new double*[A.nlin];
    if(array==NULL) return NULL;
    
    
    for (lin = 0; lin < A.nlin; lin++)
    {
        array[lin] = new double[A.ncol];
        if(array[lin]==NULL)
        {
            Pds::Array<double>::ArrayRelease(array,lin);
            return NULL;
        }
        for (col = 0; col < A.ncol; col++) 
        array[lin][col]=(*func)(A.array[lin][col],B.array[lin][col],C.array[lin][col]);
    }
    return array;
    
}

////////////////////////////////////////////////////////////////////////

double** Pds::Matrix::ArrayAllocate(double (*func)(double,double,double,double),
                                    const Pds::Matrix &A,
                                    const Pds::Matrix &B,
                                    const Pds::Matrix &C,
                                    double var)
{
    double **array=NULL;
    unsigned int lin,col;
    
    if((A.nlin==0)||(A.ncol==0)||(A.array==NULL))   return NULL;
    if((B.nlin==0)||(B.ncol==0)||(B.array==NULL))   return NULL;
    if((C.nlin==0)||(C.ncol==0)||(C.array==NULL))   return NULL;
    if((A.nlin!=B.nlin)||(A.ncol!=B.ncol))          return NULL;
    if((A.nlin!=C.nlin)||(A.ncol!=C.ncol))          return NULL;

    array= new double*[A.nlin];
    if(array==NULL) return NULL;
    
    
    for (lin = 0; lin < A.nlin; lin++)
    {
        array[lin] = new double[A.ncol];
        if(array[lin]==NULL)
        {
            Pds::Array<double>::ArrayRelease(array,lin);
            return NULL;
        }
        for (col = 0; col < A.ncol; col++) 
        array[lin][col]=(*func)(A.array[lin][col],B.array[lin][col],C.array[lin][col],var);
    }
    return array;
    
}

////////////////////////////////////////////////////////////////////////

double** Pds::Matrix::ArrayAllocate(double (*func)(double,double,double,double),
                                    const Pds::Matrix &A,
                                    const Pds::Matrix &B,
                                    const Pds::Matrix &C,
                                    const Pds::Matrix &D)
{
    double **array=NULL;
    unsigned int lin,col;
    
    if((A.nlin==0)||(A.ncol==0)||(A.array==NULL))   return NULL;
    if((B.nlin==0)||(B.ncol==0)||(B.array==NULL))   return NULL;
    if((C.nlin==0)||(C.ncol==0)||(C.array==NULL))   return NULL;
    if((D.nlin==0)||(D.ncol==0)||(D.array==NULL))   return NULL;
    if((A.nlin!=B.nlin)||(A.ncol!=B.ncol))          return NULL;
    if((A.nlin!=C.nlin)||(A.ncol!=C.ncol))          return NULL;
    if((A.nlin!=D.nlin)||(A.ncol!=D.ncol))          return NULL;

    array= new double*[A.nlin];
    if(array==NULL) return NULL;
    
    
    for (lin = 0; lin < A.nlin; lin++)
    {
        array[lin] = new double[A.ncol];
        if(array[lin]==NULL)
        {
            Pds::Array<double>::ArrayRelease(array,lin);
            return NULL;
        }
        for (col = 0; col < A.ncol; col++) 
        array[lin][col]=(*func)(A.array[lin][col],B.array[lin][col],C.array[lin][col],D.array[lin][col]);
    }
    return array;
    
}

////////////////////////////////////////////////////////////////////////
/*
double** Pds::Matrix::ArrayAllocate(const Pds::Matrix &A)
{
    double **array=NULL;
    unsigned int lin,col;
    
    if((A.nlin==0)||(A.ncol==0)||(A.array==NULL))    return NULL;

    array= new double*[A.nlin];
    if(array==NULL) return NULL;
    
    
    for (lin = 0; lin < A.nlin; lin++)
    {
        array[lin] = new double[A.ncol];
        if(array[lin]==NULL)
        {
            Pds::Array<double>::ArrayRelease(array,lin);
            return NULL;
        }
        for (col = 0; col < A.ncol; col++) array[lin][col]=A.array[lin][col];
    }
    return array;
    
}

*/
////////////////////////////////////////////////////////////////////////


