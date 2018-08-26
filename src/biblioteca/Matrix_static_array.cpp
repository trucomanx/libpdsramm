#include <cstdlib>
#include <Pds/Matrix>
#include <Pds/RealArraysDefines>
#include <Pds/RealArraysTools>


double** Pds::Matrix::AllocateArray(const Pds::Matrix &A,double (*func)(double))
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
            Pds::Matrix::ReleaseArray(array,lin);
            return NULL;
        }
        for (col = 0; col < A.ncol; col++) array[lin][col]=(*func)(A.array[lin][col]);
    }
    return array;
    
}

double** Pds::Matrix::AllocateArray(const Pds::Matrix &A)
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
            Pds::Matrix::ReleaseArray(array,lin);
            return NULL;
        }
        for (col = 0; col < A.ncol; col++) array[lin][col]=A.array[lin][col];
    }
    return array;
    
}

double** Pds::Matrix::AllocateArray(unsigned int Nlin,unsigned int Ncol, double val)
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
            Pds::Matrix::ReleaseArray(array,lin);
            return NULL;
        }
        for (col = 0; col < Ncol; col++) array[lin][col]=val;
    }
    return array;
    
}

double** Pds::Matrix::AllocateArray(unsigned int Nlin,unsigned int Ncol)
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
            Pds::Matrix::ReleaseArray(array,lin);
            return NULL;
        }
        for (col = 0; col < Ncol; col++) array[lin][col]=0.0;
    }
    return array;
    
}


void Pds::Matrix::ReleaseArray(double** &array,unsigned int Nlin)
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



#include <sstream>
#include <iomanip>      // std::setprecision
namespace patch
{
    template <typename T>
    std::string ToString(T val)
    {
        std::stringstream stream;
        stream <<std::setprecision(Pds::Ra::SetPrecision)<< val;
        return stream.str();
    }
}

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
            str=str+patch::ToString(array[lin][col]);
            if(col!=(Ncol-1))   str=str+"\t";
            else                str=str+"\n";
        }
    }
    return str;
}


#include <iostream>
#include <fstream>
bool Pds::Matrix::SaveArray(const char* filepath,double **array,unsigned int Nlin,unsigned int Ncol)
{
    std::ofstream myfile;
    unsigned int lin,col;

    if(filepath==NULL)  return false;
    if(array==NULL)     return false;

    myfile.open(filepath);
    if(myfile.is_open()==false)    return false;

    myfile<<std::setprecision(Pds::Ra::SetPrecision);
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


#include <cstdlib>
bool Pds::Matrix::LoadArray(const char* filepath,double** &array,unsigned int& Nlin,unsigned int& Ncol)
{
    unsigned int nlin,ncol;
    unsigned int i,j;

    if(filepath==NULL)  return false;
    //if(array!=NULL)     return false;

    if(Pds::Ra::ArraySizeInFile(filepath,nlin,ncol)==false) return false;

    double **arr=Pds::Matrix::AllocateArray(nlin,ncol);
    if(arr==NULL)   return false;


    std::ifstream ifs(filepath, std::ifstream::in);	
    if(ifs.is_open()==false)
    {
        Pds::Matrix::ReleaseArray(arr,nlin);
        return false;
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
    array=arr;

    return true;
}

