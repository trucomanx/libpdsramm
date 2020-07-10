
#include <Pds/RaIndices>
#include <Pds/RaDefines>


#include <string>
#include <iostream>
#include <cstdlib>
#include <algorithm>    // std::count
#include <ctime>
#include <vector>

////////////////////////////////////////////////////////////////////////////////
std::vector<unsigned int> Pds::Ra::IndicesRandVector(unsigned int Init,unsigned int End, unsigned int N)
{
    std::vector<unsigned int> Vec(0);
    unsigned int M=End-Init+1;
    unsigned int dat;
    

    for(unsigned int id=0;id<N;id++)
    {   
        do{
            dat=Init+std::rand()%M;
        }while( (Vec.size()!=0)&&(std::count(Vec.begin(), Vec.end(), dat)!=0)&&(M>=N) );
        
        Vec.push_back(dat);
    }
    return Vec;
}

////////////////////////////////////////////////////////////////////////////////
std::list<unsigned int> Pds::Ra::IndicesRandList(unsigned int Init,unsigned int End, unsigned int N)
{
    std::list<unsigned int> List;
    unsigned int M=End-Init+1;
    unsigned int dat;
    

    for(unsigned int id=0;id<N;id++)
    {   
        do{
            dat=Init+std::rand()%M;
        }while( (std::count(List.begin(), List.end(), dat)!=0)&&(M>=N) );
        
        List.push_front(dat);
    }
    return List;
}


////////////////////////////////////////////////////////////////////////////////
std::string Pds::Ra::IndicesToString(std::list<unsigned int> IDs, std::string separator)
{
    unsigned int i=0;
    std::string str;
    
    for (auto pmat = IDs.begin(); pmat != IDs.end(); pmat++)
    { 
        if(i==0)    str=std::to_string(*pmat);
        else        str=str+separator+std::to_string(*pmat);
        i++;
    }
    return str;
}
////////////////////////////////////////////////////////////////////////////////

