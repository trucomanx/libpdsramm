#include <cstdlib>
#include <Pds/Matrix>
#include <Pds/RaDefines>
#include <Pds/RaTools>

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
            Pds::Matrix::ArrayRelease(array,lin);
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
            Pds::Matrix::ArrayRelease(array,lin);
            return NULL;
        }
        for (col = 0; col < A.ncol; col++) array[lin][col]=(*func)(A.array[lin][col],var);
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
            Pds::Matrix::ArrayRelease(array,lin);
            return NULL;
        }
        for (col = 0; col < A.ncol; col++) array[lin][col]=A.array[lin][col];
    }
    return array;
    
}
////////////////////////////////////////////////////////////////////////

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
            Pds::Matrix::ArrayRelease(array,lin);
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
            Pds::Matrix::ArrayRelease(array,lin);
            return NULL;
        }
        for (col = 0; col < Ncol; col++) array[lin][col]=0.0;
    }
    return array;
    
}


void Pds::Matrix::ArrayRelease(double** &array,unsigned int Nlin)
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

double **Pds::Matrix::ArrayFromString(const std::string &str,unsigned int &Nlin,unsigned int &Ncol)
{
    unsigned int nlin;
    unsigned int ncol;
    bool state=Pds::Ra::ArraySizeInString(str,nlin,ncol);
    if(state==false)    return NULL;
    
    double **array=ArrayAllocate(nlin,ncol);
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
    
    double **array=ArrayAllocate(nlin,ncol);
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

#include <iostream>
#include <fstream>
bool Pds::Matrix::ArraySave(const char* filepath,double **array,unsigned int Nlin,unsigned int Ncol)
{
    std::ofstream myfile;
    unsigned int lin,col;

    if(filepath==NULL)  return false;
    if(array==NULL)     return false;

    myfile.open(filepath);
    if(myfile.is_open()==false)    return false;

    myfile<<std::setprecision(Pds::Ra::StringPrecision);
    for(lin=0;lin<Nlin;lin++)
    {
        if(array[lin]!=NULL)
        for(col=0;col<Ncol;col++)
        {
            myfile <<array[lin][col];
            if(col!=(Ncol-1))   myfile<<"\t";
            else                myfile<<"\n";
        }
    }

    myfile.close();
    return true;
}
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
////////////////////////////////////////////////////////////////////////
#include <cstdio>
#include <cstring>
#include <cstdlib>
typedef struct {
    long type;  /* type */
    long nlins; /* row dimension */
    long ncols; /* column dimension */
    long imag_flag; /* flag indicating imag part */
    long name_length; /* name length (including NULL) */
} Fmatrix;
 

// Version 1.0 MAT File Format
bool Pds::Matrix::ArrayWriteMatFile(FILE *fp,const char *pname,double **array,unsigned int Nlin,unsigned int Ncol)
{
    if(fp==NULL)    return false;
    if(Nlin==0)         return false;
    if(Ncol==0)         return false;
    if(pname==NULL) return false;
    if(array==NULL) return false;
    
    
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
    fwrite(&array[lin][col], sizeof(double), 1, fp);
    
    return true;
}


// Version 1.0 MAT File Format
bool Pds::Matrix::ArrayWriteMatFile(FILE *fp,const char *pname,double **arrayr,double **arrayi,unsigned int Nlin,unsigned int Ncol)
{
    if(fp==NULL)        return false;
    if(Nlin==0)         return false;
    if(Ncol==0)         return false;
    if(pname==NULL)     return false;
    if((arrayr==NULL)&&(arrayi==NULL))    return false;
    
    
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
        fwrite(&arrayr[lin][col], sizeof(double), 1, fp);
    }
    
    if(HEAD.imag_flag!=0)
    {
       for(unsigned int col=0;col<Ncol;col++)
       for(unsigned int lin=0;lin<Nlin;lin++)
       fwrite(&arrayi[lin][col], sizeof(double), 1, fp);
    }
    
    return true;
}
   
bool Pds::Matrix::ArrayWriteMatFile(const char* filepath,double **array,unsigned int Nlin,unsigned int Ncol)
{
    if(filepath==NULL)    return false;
    
    FILE *fd=fopen(filepath,"wb");
    if(fd==NULL)    return false;
    
    bool ret=Pds::Matrix::ArrayWriteMatFile(fd,"MAT0",array,Nlin,Ncol);
    fclose(fd);
    
    return ret;
}
   
bool Pds::Matrix::ArrayWriteMatFile(const char* filepath,double **arrayr,double **arrayi,unsigned int Nlin,unsigned int Ncol)
{
    if(filepath==NULL)    return false;
    
    FILE *fd=fopen(filepath,"wb");
    if(fd==NULL)    return false;
    
    bool ret=Pds::Matrix::ArrayWriteMatFile(fd,"MAT0",arrayr,arrayi,Nlin,Ncol);
    fclose(fd);
    
    return ret;
}

////////////////////////////////////////////////////////////////////////
#include <cstdlib>
double** Pds::Matrix::ArrayLoad(const char* filepath,unsigned int& Nlin,unsigned int& Ncol)
{
    unsigned int nlin,ncol;
    unsigned int i,j;

    if(filepath==NULL)  return NULL;
    //if(array!=NULL)     return false;

    if(Pds::Ra::ArraySizeInFile(filepath,nlin,ncol)==false) return NULL;

    double **arr=Pds::Matrix::ArrayAllocate(nlin,ncol);
    if(arr==NULL)   return NULL;


    std::ifstream ifs(filepath, std::ifstream::in);	
    if(ifs.is_open()==false)
    {
        Pds::Matrix::ArrayRelease(arr,nlin);
        return NULL;
    }

    std::string word;

    i=0;j=0;
    for(i=0;(!ifs.eof())&&(i<nlin);i++)
    for(j=0;(!ifs.eof())&&(j<ncol);j++)
    {

        ifs >> word;
        arr[i][j]=strtod(word.c_str(),NULL);

    }
    ifs.close();

    Nlin=nlin;
    Ncol=ncol;

    return arr;
}

////////////////////////////////////////////////////////////////////////

#include <cstdlib>
double** Pds::Matrix::ArrayColLoad(const char* filepath,unsigned int& Nlin,unsigned int& Ncol)
{
    unsigned int nlin,ncol;
    unsigned int i;

    if(filepath==NULL)  return NULL;

    if(Pds::Ra::ElementsInFile(filepath,nlin)==false) return NULL;
    ncol=1;

    double **arr=Pds::Matrix::ArrayAllocate(nlin,ncol);
    if(arr==NULL)   return NULL;


    std::ifstream ifs(filepath, std::ifstream::in);	
    if(ifs.is_open()==false)
    {
        Pds::Matrix::ArrayRelease(arr,nlin);
        return NULL;
    }

    std::string word;

    i=0;
    for(i=0;(!ifs.eof())&&(i<nlin);i++)
    {
        ifs >> word;
        arr[i][0]=strtod(word.c_str(),NULL);
    }
    ifs.close();

    Nlin=nlin;
    Ncol=ncol;

    return arr;
}



