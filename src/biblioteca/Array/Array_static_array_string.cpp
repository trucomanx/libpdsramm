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

////////////////////////////////////////////////////////////////////////

template <class Datum>
Datum **Pds::Array<Datum>::ArrayFromString(const std::string &str,unsigned int &Nlin,unsigned int &Ncol)
{
    unsigned int nlin;
    unsigned int ncol;
    bool state=Pds::Ra::ArraySizeInString(str,nlin,ncol);
    if(state==false)    return NULL;
    
    Datum **array=Pds::Array<Datum>::ArrayAllocate(nlin,ncol);
    if(array==NULL)     return NULL;
    
    unsigned int lin,col;
    
    std::list<std::string> strlist=Pds::Ra::SplitString(str," \t\n\v\f\r");
    std::list<std::string>::iterator it=strlist.begin();
    
    for(lin=0;lin<nlin;lin++)
    for(col=0;col<ncol;col++)
    {
        array[lin][col]=(Datum)std::stod(*it);
        it++;
    }
    
    Ncol=ncol;
    Nlin=nlin;
    
    return array;
}

////////////////////////////////////////////////////////////////////////
template <class Datum>
Datum **Pds::Array<Datum>::ArrayColFromString(const std::string &str,unsigned int &Nlin,unsigned int &Ncol)
{
    unsigned int nlin;
    unsigned int ncol=1;
    
    int N=Pds::Ra::ElementsInString(str);
    if(N<0) return NULL;
    
    nlin=(unsigned int)N;
    
    Datum **array=Pds::Array<Datum>::ArrayAllocate(nlin,ncol);
    if(array==NULL)     return NULL;
    
    unsigned int lin,col;
    
    std::list<std::string> strlist=Pds::Ra::SplitString(str," \t\n\v\f\r");
    std::list<std::string>::iterator it=strlist.begin();
    
    for(lin=0;lin<nlin;lin++)
    for(col=0;col<ncol;col++)
    {
        array[lin][col]=(Datum)std::stod(*it);
        it++;
    }
    
    Nlin=nlin;
    Ncol=ncol;
    
    return array;
}
////////////////////////////////////////////////////////////////////////

#include <iomanip>      // std::setprecision

template <class Datum>
std::string Pds::Array<Datum>::ArrayToString(Datum **array,unsigned int Nlin,unsigned int Ncol)
{
    std::string str="";    
    unsigned int lin,col;

    if(array==NULL) return str;

    for(lin=0;lin<Nlin;lin++)
    {
        if(array[lin]!=NULL)
        for(col=0;col<Ncol;col++)
        {
            str=str+Pds::Ra::ToString((double)array[lin][col]);
            if(col!=(Ncol-1))   str=str+"\t";
            else                str=str+"\n";
        }
    }
    return str;
}

////////////////////////////////////////////////////////////////////////
