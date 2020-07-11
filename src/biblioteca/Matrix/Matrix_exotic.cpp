#include <string>
#include <Pds/Matrix>
#include <Pds/Vector>
////////////////////////////////////////////////////////////////////////
#include <cmath>

////////////////////////////////////////////////////////////////////////////////

Pds::Matrix Pds::Matrix::MultipleMse(const std::vector<Pds::Matrix> &Block) const
{
    if(this->IsEmpty())     return Pds::Matrix();
    if(Block.size()==0)     return Pds::Matrix();
    if(Block[0].IsEmpty())  return Pds::Matrix();
    for(unsigned int i=1;i<Block.size();i++)
    if(Block[0].IsNotSimilarTo(Block[i]))   return Pds::Matrix();
    if(this->ncol!=Block.size())            return Pds::Matrix();

    unsigned int NlinA=this->nlin;
    unsigned int N=Block.size();
    
    Pds::Matrix C(NlinA,Block[0].Nel());
    unsigned int lina,elem,n;
    unsigned int lin,col;
    double tmp,S;

    for(lina=0;lina<NlinA;lina++)
    {
        elem=0;
        for(col=0;col<Block[0].ncol;col++)
        for(lin=0;lin<Block[0].nlin;lin++)
        {
            S=0;
            for(n=0;n<N;n++)
            {
                tmp=this->array[lina][n]-Block[n].array[lin][col];
                S+=tmp*tmp;
            }

            C.array[lina][elem]=S/N;
            elem++;
        }
    }
    return C;
}

Pds::Matrix Pds::Matrix::MultipleMse(const Pds::Matrix &B) const
{
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))   return Pds::Matrix();
    if((B.nlin==0)||(B.ncol==0)||(B.array==NULL))   return Pds::Matrix();
    if(this->ncol!=B.ncol)    return Pds::Matrix();

    unsigned int NlinA=this->nlin;
    unsigned int NlinB=B.nlin;
    unsigned int Ncol =this->ncol;
    
    Pds::Matrix C(NlinA,NlinB);
    unsigned int lina,linb,n;
    double tmp,S;

    for(lina=0;lina<NlinA;lina++)
    for(linb=0;linb<NlinB;linb++)
    {
        S=0;
        for(n=0;n<Ncol;n++)
        {
            tmp=this->array[lina][n]-B.array[linb][n];
            S+=tmp*tmp;
        }

        C.array[lina][linb]=S/Ncol;
    }
    return C;
}

////////////////////////////////////////////////////////////////////////////////

Pds::Array<unsigned int> Pds::Matrix::IdInMultipleMse(const Pds::Matrix &B) const
{
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))   return Pds::Array<unsigned int>();
    if((B.nlin==0)||(B.ncol==0)||(B.array==NULL))               return Pds::Array<unsigned int>();
    if(this->ncol!=B.ncol)    return Pds::Array<unsigned int>();

    unsigned int NlinA=this->nlin;
    unsigned int NlinB=B.nlin;
    unsigned int Ncol =this->ncol;

    Pds::Array<unsigned int> Lin(NlinB,1);

    unsigned int lina,linb,n;
    double tmp,S=0;
    double Min=0;
    unsigned int id_min;


    for(linb=0;linb<NlinB;linb++)
    {   
        id_min=0;
        for(lina=0;lina<NlinA;lina++)
        {
            S=0;
            for(n=0;n<Ncol;n++)
            {
                tmp=this->array[lina][n]-B.array[linb][n];
                S+=tmp*tmp;
            }
            S=S/Ncol;

            if(lina==0)
            {
                Min=S;  id_min=lina;
            }
            else if(S<Min)
            {
                Min=S;  id_min=lina;
            }
        }
        Lin.array[linb][0]=id_min;
    }    
    return Lin;
}


Pds::Array<unsigned int> Pds::Matrix::IdInMultipleMse(const std::vector<Pds::Matrix> &Block) const
{
    if(this->IsEmpty())     return Pds::Array<unsigned int>();
    if(Block.size()==0)     return Pds::Array<unsigned int>();
    if(Block[0].IsEmpty())  return Pds::Array<unsigned int>();
    for(unsigned int i=1;i<Block.size();i++)
    if(Block[0].IsNotSimilarTo(Block[i]))   return Pds::Array<unsigned int>();
    if(this->ncol!=Block.size())            return Pds::Array<unsigned int>();

    unsigned int NlinA=this->nlin;
    unsigned int N=Block.size();

    Pds::Array<unsigned int> Lin(Block[0].nlin,Block[0].ncol);
    
    //Pds::Matrix C(NlinA,Block[0].Nel());
    unsigned int lina,n;
    unsigned int lin,col;
    double tmp,S;
    double Min=0;
    unsigned int id_min;

    for(col=0;col<Block[0].ncol;col++)
    for(lin=0;lin<Block[0].nlin;lin++)
    {
        id_min=0;
        for(lina=0;lina<NlinA;lina++)
        {
            S=0;
            for(n=0;n<N;n++)
            {
                tmp=this->array[lina][n]-Block[n].array[lin][col];
                S+=tmp*tmp;
            }
            S=S/N;

            if(lina==0)
            {
                Min=S;  id_min=lina;
            }
            else if(S<Min)
            {
                Min=S;  id_min=lina;
            }

        }
        Lin.array[lin][col]=id_min;
    }
    return Lin;
}


