#include <string>
#include <iostream>
#include <Pds/Array>
#include <Pds/Matrix>
#include <Pds/RaDefines>
#include <Pds/RaTools>
#include <Pds/RaString>


// Instantiate Pds::Array for the supported template type parameters
template class Pds::Array<double>;
template class Pds::Array<unsigned char>;
template class Pds::Array<unsigned int >;


template <class Datum>
void Pds::Array<Datum>::MakeEmpty(void)
{
    Pds::Array<Datum>::ArrayRelease(this->array,this->nlin);
    this->nlin=0;
    this->ncol=0;
}
////////////////////////////////////////////////////////////////////////

#include <iomanip>      // std::setprecision

template <class Datum>
void Pds::Array<Datum>::Print(std::string str) const
{
    std::cout<<str;

    if(this->IsEmpty())   return;
    
    std::cout<<std::setprecision(Pds::Ra::StringPrecision);
    unsigned int lin,col;

    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        std::cout<<(0+(this->array[lin][col]));

        if(col!=(this->ncol-1)) std::cout<<"\t";
        else                    std::cout<<"\n";
    }

}

template <class Datum>
void Pds::Array<Datum>::Print(void) const
{
    this->Print("");
}

////////////////////////////////////////////////////////////////////////////////
template <class Datum>
bool Pds::Array<Datum>::Reshape(unsigned int Nlin,unsigned int Ncol)
{
    if((Nlin==0)||(Ncol==0))    return false;
    
    Datum **new_array= Pds::Array<Datum>::ArrayReshape(*this,Nlin,Ncol);
    if(new_array==NULL)       return false;
    
    Pds::Array<Datum>::ArrayRelease(this->array,this->nlin);

    this->array=new_array;
    this->nlin=Nlin;
    this->ncol=Ncol;
    return true;
}
////////////////////////////////////////////////////////////////////////////////
template <class Datum>
Pds::Matrix Pds::Array<Datum>::Centroids(const std::vector<Pds::Matrix> &Block) const 
{
    if(this->IsEmpty())     return Pds::Matrix();
    if(Block.size()==0)     return Pds::Matrix();
    if(Block[0].IsEmpty())  return Pds::Matrix();
    for(unsigned int i=1;i<Block.size();i++)
    if(Block[0].IsNotSimilarTo(Block[i]))   return Pds::Matrix();
    if(this->Nel()!=Block[0].Nel())         return Pds::Matrix();

    unsigned int N=Block.size();
    unsigned int M;
    unsigned int lin,col;
    unsigned int n,ll,cc;
    unsigned int elem,id_of_elem;

    M=0;
    for(col=0;col<this->ncol;col++)
    for(lin=0;lin<this->nlin;lin++)
    if(this->array[lin][col]>M) M=this->array[lin][col];
    M=M+1;
    
    std::vector<unsigned int> P(M);
    Pds::Matrix C(M,N);

    elem=0;
    for(col=0;col<this->ncol;col++)
    for(lin=0;lin<this->nlin;lin++)
    {
        id_of_elem=this->array[lin][col];
        
        ll=elem%Block[0].nlin;
        cc=elem/Block[0].nlin;
        for(n=0;n<N;n++)
        {
            C.array[id_of_elem][n]+=Block[n].array[ll][cc];
        }

        P[id_of_elem]=P[id_of_elem]+1;
        elem++;
    }

    for(lin=0;lin<M;lin++)
    for(col=0;col<N;col++)
    C.array[lin][col]=C.array[lin][col]/P[lin];
    
    return C;
}

////////////////////////////////////////////////////////////////////////////////
template <class Datum>
Pds::Matrix Pds::Array<Datum>::Centroids(const Pds::Matrix &X) const 
{
    if(this->IsEmpty()) return Pds::Matrix();
    if(X.IsEmpty())     return Pds::Matrix();
    if(this->Nel()!=X.Nlin())   return Pds::Matrix();

    unsigned int N=X.Ncol();
    unsigned int M;
    unsigned int lin,col;
    unsigned int n;
    unsigned int elem,id_of_elem;

    M=0;
    for(col=0;col<this->ncol;col++)
    for(lin=0;lin<this->nlin;lin++)
    if(this->array[lin][col]>M) M=this->array[lin][col];
    M=M+1;
    
    std::vector<unsigned int> P(M);
    Pds::Matrix C(M,N);

    elem=0;
    for(col=0;col<this->ncol;col++)
    for(lin=0;lin<this->nlin;lin++)
    {
        id_of_elem=this->array[lin][col];
        
        for(n=0;n<N;n++)
        {
            C.array[id_of_elem][n]+=X.array[elem][n];
        }

        P[id_of_elem]=P[id_of_elem]+1;
        elem++;
    }

    for(lin=0;lin<M;lin++)
    for(col=0;col<N;col++)
    C.array[lin][col]=C.array[lin][col]/P[lin];
    
    return C;
}
