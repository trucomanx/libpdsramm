#include <cstdlib>
#include <Pds/Array>
#include <Pds/Matrix>
#include <Pds/RaDefines>
#include <Pds/RaTools>
#include <Pds/RaString>
#include <Pds/RaFile>

// Instantiate Pds::Array for the supported template type parameters
template class Pds::Array<double>;
template class Pds::Array<unsigned char>;
template class Pds::Array<unsigned int >;



////////////////////////////////////////////////////////////////////////////////
template <class Datum>
Datum** Pds::Array<Datum>::ArrayAllocate(const Pds::Matrix &A)
{
    Datum **array=NULL;
    unsigned int lin,col;
    
    if((A.nlin==0)||(A.ncol==0)||(A.array==NULL))    return NULL;

    array= new Datum*[A.nlin];
    if(array==NULL) return NULL;
    
    
    for (lin = 0; lin < A.nlin; lin++)
    {
        array[lin] = new Datum[A.ncol];
        if(array[lin]==NULL)
        {
            Pds::Array<Datum>::ArrayRelease(array,lin);
            return NULL;
        }
        for (col = 0; col < A.ncol; col++) array[lin][col]=(Datum)A.array[lin][col];
    }
    return array;
    
}

////////////////////////////////////////////////////////////////////////////////

template <class Datum>
Datum** Pds::Array<Datum>::ArrayAllocate(unsigned int Nlin,unsigned int Ncol, Datum val)
{
    Datum **array=NULL;
    unsigned int lin,col;
    
    if((Nlin==0)||(Ncol==0))    return NULL;

    array= new Datum*[Nlin];
    if(array==NULL) return NULL;
    
    
    for (lin = 0; lin < Nlin; lin++)
    {
        array[lin] = new Datum[Ncol];
        if(array[lin]==NULL)
        {
            Pds::Array<Datum>::ArrayRelease(array,lin);
            return NULL;
        }
        for (col = 0; col < Ncol; col++) array[lin][col]=val;
    }
    return array;
    
}

template <class Datum>
Datum** Pds::Array<Datum>::ArrayAllocate(unsigned int Nlin,unsigned int Ncol)
{
    Datum **array=NULL;
    unsigned int lin,col;
    
    if((Nlin==0)||(Ncol==0))    return NULL;

    array= new Datum*[Nlin];
    if(array==NULL) return NULL;
    
    
    for (lin = 0; lin < Nlin; lin++)
    {
        array[lin] = new Datum[Ncol];
        if(array[lin]==NULL)
        {
            Pds::Array<Datum>::ArrayRelease(array,lin);
            return NULL;
        }
        for (col = 0; col < Ncol; col++) array[lin][col]=0;
    }
    return array;
    
}

template <class Datum>
void Pds::Array<Datum>::ArrayRelease(Datum** &array,unsigned int Nlin)
{
    if(array!=NULL)
    {
        for (unsigned int j = 0; j < Nlin; j++)
        { 
            delete [] array[j];
            array[j]=NULL;
        }
        delete [] array;
        array=NULL;
    }
}


////////////////////////////////////////////////////////////////////////
template <class Datum>
Datum *Pds::Array<Datum>::ArrayToLineArray(Datum **array,unsigned int Nlin,unsigned int Ncol)
{
    Datum *real_dat=NULL; /* pointer to real data */
    unsigned int lin,col,id;
        
    if(array==NULL) return NULL;
    for(lin=0;lin<Nlin;lin++)
    if(array[lin]==NULL) return NULL;

    real_dat=(Datum *)calloc(Nlin*Ncol,sizeof(Datum));
    if(real_dat==NULL)  return NULL;
    
    id=0;
    for(col=0;col<Ncol;col++)
    for(lin=0;lin<Nlin;lin++,id++)
    real_dat[id]=array[lin][col];
    
    return real_dat;
}

