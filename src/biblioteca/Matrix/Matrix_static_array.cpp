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
////////////////////////////////////////////////////////////////////////
/*
double** Pds::Matrix::ArrayAllocate(unsigned int Nlin,unsigned int Ncol, double val)
{
    double **array=NULL;
    unsigned int lin,col;
    
    if((Nlin==0)||(Ncol==0))    return NULL;

    array= new double*[Nlin];
    if(array==NULL) return NULL;
    
    
    for (lin = 0; lin < Nlin; lin++)
    {
        array[lin] = new double[Ncol];
        if(array[lin]==NULL)
        {
            Pds::Array<double>::ArrayRelease(array,lin);
            return NULL;
        }
        for (col = 0; col < Ncol; col++) array[lin][col]=val;
    }
    return array;
    
}
////////////////////////////////////////////////////////////////////////

double** Pds::Matrix::ArrayAllocate(unsigned int Nlin,unsigned int Ncol)
{
    double **array=NULL;
    unsigned int lin,col;
    
    if((Nlin==0)||(Ncol==0))    return NULL;

    array= new double*[Nlin];
    if(array==NULL) return NULL;
    
    
    for (lin = 0; lin < Nlin; lin++)
    {
        array[lin] = new double[Ncol];
        if(array[lin]==NULL)
        {
            Pds::Array<double>::ArrayRelease(array,lin);
            return NULL;
        }
        for (col = 0; col < Ncol; col++) array[lin][col]=0.0;
    }
    return array;
    
}
*/

////////////////////////////////////////////////////////////////////////

double **Pds::Matrix::ArrayFromString(const std::string &str,unsigned int &Nlin,unsigned int &Ncol)
{
    unsigned int nlin;
    unsigned int ncol;
    bool state=Pds::Ra::ArraySizeInString(str,nlin,ncol);
    if(state==false)    return NULL;
    
    double **array=Pds::Array<double>::ArrayAllocate(nlin,ncol);
    if(array==NULL)     return NULL;
    
    unsigned int lin,col;
    
    std::list<std::string> strlist=Pds::Ra::SplitString(str," \t\n\v\f\r");
    std::list<std::string>::iterator it=strlist.begin();
    
    for(lin=0;lin<nlin;lin++)
    for(col=0;col<ncol;col++)
    {
        array[lin][col]=std::stod(*it);
        it++;
    }
    
    Ncol=ncol;
    Nlin=nlin;
    
    return array;
}

////////////////////////////////////////////////////////////////////////

double **Pds::Matrix::ArrayColFromString(const std::string &str,unsigned int &Nlin,unsigned int &Ncol)
{
    unsigned int nlin;
    unsigned int ncol=1;
    
    int N=Pds::Ra::ElementsInString(str);
    if(N<0) return NULL;
    
    nlin=(unsigned int)N;
    
    double **array=Pds::Array<double>::ArrayAllocate(nlin,ncol);
    if(array==NULL)     return NULL;
    
    unsigned int lin,col;
    
    std::list<std::string> strlist=Pds::Ra::SplitString(str," \t\n\v\f\r");
    std::list<std::string>::iterator it=strlist.begin();
    
    for(lin=0;lin<nlin;lin++)
    for(col=0;col<ncol;col++)
    {
        array[lin][col]=std::stod(*it);
        it++;
    }
    
    Nlin=nlin;
    Ncol=ncol;
    
    return array;
}
////////////////////////////////////////////////////////////////////////

#include <iomanip>      // std::setprecision

std::string Pds::Matrix::ArrayToString(double **array,unsigned int Nlin,unsigned int Ncol)
{
    std::string str="";    
    unsigned int lin,col;

    if(array==NULL) return str;

    for(lin=0;lin<Nlin;lin++)
    {
        if(array[lin]!=NULL)
        for(col=0;col<Ncol;col++)
        {
            str=str+Pds::Ra::ToString(array[lin][col]);
            if(col!=(Ncol-1))   str=str+"\t";
            else                str=str+"\n";
        }
    }
    return str;
}

////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////
double *Pds::Matrix::ArrayToArray(double **array,unsigned int Nlin,unsigned int Ncol)
{
    double *real_dat=NULL; /* pointer to real data */
    unsigned int lin,col,id;
        
    if(array==NULL) return NULL;
    for(lin=0;lin<Nlin;lin++)
    if(array[lin]==NULL) return NULL;

    real_dat=(double *)calloc(Nlin*Ncol,sizeof(double));
    if(real_dat==NULL)  return NULL;
    
    id=0;
    for(col=0;col<Ncol;col++)
    for(lin=0;lin<Nlin;lin++,id++)
    real_dat[id]=array[lin][col];
    
    return real_dat;
}



////////////////////////////////////////////////////////////////////////////////


