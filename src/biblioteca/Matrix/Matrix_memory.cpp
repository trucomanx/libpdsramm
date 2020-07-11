#include <string>
#include <list>
#include <iostream>
#include <Pds/Matrix>
#include <Pds/RaDefines>
#include <Pds/RaTools>
#include <Pds/RaString>
////////////////////////////////////////////////////////////////////////

void Pds::Matrix::MakeEmpty(void)
{
    Pds::Array<double>::ArrayRelease(this->array,this->nlin);
    this->nlin=0;
    this->ncol=0;
}

///////////////////////////////////////////////////////////////////////////////

bool Pds::Matrix::Reshape(unsigned int Nlin,unsigned int Ncol)
{
    if((Nlin==0)||(Ncol==0))    return false;
    
    double **new_array= Pds::Array<double>::ArrayReshape(*this,Nlin,Ncol);
    if(new_array==NULL)       return false;
    
    Pds::Array<double>::ArrayRelease(this->array,this->nlin);

    this->array=new_array;
    this->nlin=Nlin;
    this->ncol=Ncol;
    return true;
}


////////////////////////////////////////////////////////////////////////////////
bool Pds::Matrix::FusionVer(std::list<Pds::Matrix> &list)
{
    unsigned int Ncol=0;
    unsigned int Nlin=0;
    
    this->MakeEmpty();
    
    unsigned int i=0;
    for (auto pmat = list.begin(); pmat != list.end(); pmat++) 
    {
        if(i==0)    Ncol=pmat->Ncol();
        else
        {
            if(pmat->Ncol()!=Ncol)
            {
                pds_print_error_message("The "<<i<<"-th matrix in list don't have the same column length of 0-th.");
                return false;
            }
        }

        Nlin=Nlin+pmat->Nlin();
        i++;
    }
    
    this->array= new double*[Nlin];
    if(this->array==NULL) return false;
    this->nlin=Nlin;
    this->ncol=Ncol;    

    unsigned int lin=0;
    for (auto pmat = list.begin(); pmat != list.end(); pmat++) 
    {        
        for(unsigned int i=0;i<pmat->nlin;i++,lin++)
        {
            this->array[lin]=pmat->array[i];
            pmat->array[i]=NULL;
        }
        pmat->MakeEmpty();
    }

    return true;
}

