#include <Pds/Array>
#include <Pds/RaDefines>
#include <Pds/RaTools>
#include <Pds/RaString>
#include <Pds/RaFile>

////////////////////////////////////////////////////////////////////////
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstdint>


// Instantiate Pds::Array for the supported template type parameters
template class Pds::Array<double>;
template class Pds::Array<unsigned char>;
template class Pds::Array<unsigned int >;


typedef struct {
    int32_t type;  /* type - 4 bytes */ 
    int32_t nlins; /* row dimension - 4 bytes */
    int32_t ncols; /* column dimension - 4 bytes */
    int32_t imag_flag; /* flag indicating imag part - 4 bytes */
    int32_t name_length; /* name length (including NULL) - 4 bytes */
} Fmatrix;
 

// Version 1.0 MAT File Format
template <class Datum>
bool Pds::Array<Datum>::ArrayWriteMatFile(FILE *fp,const char *pname,Datum **array,unsigned int Nlin,unsigned int Ncol)
{
    if(fp==NULL)    return false;
    if(Nlin==0)         return false;
    if(Ncol==0)         return false;
    if(pname==NULL) return false;
    if(array==NULL) return false;
    double tmp;
    
    Fmatrix HEAD;
    
    HEAD.type=0;
    if(Pds::Ra::IsBigEndian())  HEAD.type=HEAD.type+1000;
    if(sizeof(double)==4)       HEAD.type=HEAD.type+10;
    HEAD.nlins=Nlin;
    HEAD.ncols=Ncol;
    HEAD.imag_flag=0;
    HEAD.name_length=strlen(pname)+1;    
    
    size_t nel;
    
    nel=fwrite(&HEAD   , sizeof(Fmatrix), 1               , fp);
    if(nel!=(size_t)1)    return false;
    
    nel=fwrite(pname   , sizeof(char)   , HEAD.name_length, fp);
    if(nel!=(size_t)HEAD.name_length)    return false;
    

    for(unsigned int col=0;col<Ncol;col++)
    for(unsigned int lin=0;lin<Nlin;lin++)
    {
        tmp=(double)array[lin][col];
        fwrite(&tmp, sizeof(double), 1, fp);
    }
    
    return true;
}


// Version 1.0 MAT File Format
template <class Datum>
bool Pds::Array<Datum>::ArrayWriteMatFile(FILE *fp,const char *pname,Datum **arrayr,Datum **arrayi,unsigned int Nlin,unsigned int Ncol)
{
    if(fp==NULL)        return false;
    if(Nlin==0)         return false;
    if(Ncol==0)         return false;
    if(pname==NULL)     return false;
    if((arrayr==NULL)&&(arrayi==NULL))    return false;
    double tmp;
    
    Fmatrix HEAD;
    
    HEAD.type=0;
    if(Pds::Ra::IsBigEndian())  HEAD.type=HEAD.type+1000;
    if(sizeof(double)==4)       HEAD.type=HEAD.type+10;

    HEAD.nlins=Nlin;
    HEAD.ncols=Ncol;
    if(arrayi==NULL)    HEAD.imag_flag=0;
    else                HEAD.imag_flag=1;
    HEAD.name_length=strlen(pname)+1;    
    
    size_t nel;
    nel=fwrite(&HEAD   , sizeof(Fmatrix), 1               , fp);
    if(nel!=(size_t)1)    return false;
    
    nel=fwrite(pname   , sizeof(char)   , HEAD.name_length, fp);
    if(nel!=(size_t)HEAD.name_length)    return false;
    
    if(arrayr==NULL)
    {
        double dat=0;
        for(unsigned int col=0;col<Ncol;col++)
        for(unsigned int lin=0;lin<Nlin;lin++)
        fwrite(&dat, sizeof(double), 1, fp);
    }
    else
    {
        for(unsigned int col=0;col<Ncol;col++)
        for(unsigned int lin=0;lin<Nlin;lin++)
        {
            tmp=(double)arrayr[lin][col];
            fwrite(&tmp, sizeof(double), 1, fp);
        }
    }
    
    if(HEAD.imag_flag!=0)
    {
       for(unsigned int col=0;col<Ncol;col++)
       for(unsigned int lin=0;lin<Nlin;lin++)
       {
            tmp=(double)arrayi[lin][col];
            fwrite(&tmp, sizeof(double), 1, fp);
       }
    }
    
    return true;
}
