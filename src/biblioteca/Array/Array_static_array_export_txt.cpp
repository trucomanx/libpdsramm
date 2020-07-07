#include <iostream>
#include <fstream>
#include <iomanip>

#include <cstdlib>
#include <Pds/Array>
#include <Pds/RaDefines>
#include <Pds/RaTools>
#include <Pds/RaString>
#include <Pds/RaFile>

// Instantiate Pds::Array for the supported template type parameters
template class Pds::Array<double>;
template class Pds::Array<unsigned char>;
template class Pds::Array<unsigned int >;

template <class Datum>
bool Pds::Array<Datum>::ArraySave(const std::string &filepath,Datum **array,unsigned int Nlin,unsigned int Ncol)
{
    std::ofstream myfile;
    unsigned int lin,col;

    if(filepath.size()==0)  return false;
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

   
////////////////////////////////////////////////////////////////////////////////

#include <cstdlib>

template <class Datum>
Datum** Pds::Array<Datum>::ArrayLoad(const std::string &filepath,unsigned int& Nlin,unsigned int& Ncol)
{
    unsigned int nlin,ncol;
    unsigned int i,j;

    if(filepath.size()==0)  return NULL;
    //if(array!=NULL)     return false;

    if(Pds::Ra::ArraySizeInFile(filepath.c_str(),nlin,ncol)==false) return NULL;

    Datum **arr=Pds::Array<Datum>::ArrayAllocate(nlin,ncol);
    if(arr==NULL)   return NULL;


    std::ifstream ifs(filepath.c_str(), std::ifstream::in);	
    if(ifs.is_open()==false)
    {
        Pds::Array<Datum>::ArrayRelease(arr,nlin);
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

template <class Datum>
Datum** Pds::Array<Datum>::ArrayColLoad(const std::string &filepath,unsigned int& Nlin,unsigned int& Ncol)
{
    unsigned int nlin,ncol;
    unsigned int i;

    if(filepath.size()==0)  return NULL;

    if(Pds::Ra::ElementsInFile(filepath.c_str(),nlin)==false) return NULL;
    ncol=1;

    Datum **arr=Pds::Array<Datum>::ArrayAllocate(nlin,ncol);
    if(arr==NULL)   return NULL;


    std::ifstream ifs(filepath, std::ifstream::in);	
    if(ifs.is_open()==false)
    {
        Pds::Array<Datum>::ArrayRelease(arr,nlin);
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

