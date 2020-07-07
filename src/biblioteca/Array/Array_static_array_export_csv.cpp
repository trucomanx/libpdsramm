#include <cstdlib>
#include <Pds/Array>
#include <Pds/RaDefines>
#include <Pds/RaTools>
#include <Pds/RaString>
#include <Pds/RaFile>

#include <iostream>
#include <fstream>
#include <iomanip>


// Instantiate Pds::Array for the supported template type parameters
template class Pds::Array<double>;
template class Pds::Array<unsigned char>;
template class Pds::Array<unsigned int >;

template <class Datum>
bool Pds::Array<Datum>::ArrayWriteCsvFile(const std::string &filepath,Datum **array,unsigned int Nlin,unsigned int Ncol, char delimitador)
{
    std::ofstream myfile;
    unsigned int lin,col;

    if(filepath.size()==0)  return false;
    if(array==NULL)     return false;

    myfile.open(filepath.c_str());
    if(myfile.is_open()==false)    return false;

    //if(delimitador!=',')    myfile<<"sep="<<delimitador<<"\n";

    myfile<<std::setprecision(Pds::Ra::StringPrecision);
    for(lin=0;lin<Nlin;lin++)
    {
        if(array[lin]!=NULL)
        for(col=0;col<Ncol;col++)
        {
            myfile <<array[lin][col];
            if(col!=(Ncol-1))   myfile<<delimitador;
            else                myfile<<"\n";
        }
    }

    myfile.close();
    return true;
}
