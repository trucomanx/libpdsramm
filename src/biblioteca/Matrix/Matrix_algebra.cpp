#include <string>
#include <Pds/Matrix>
#include <Pds/Vector>
////////////////////////////////////////////////////////////////////////
#include <cmath>




double Pds::Matrix::Rms(void) const
{
    unsigned int lin,col;
    double S=0;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return Pds::Ra::Nan;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    S=S+this->array[lin][col]*this->array[lin][col];

    return sqrt(S/((this->ncol)*(this->nlin)));
}

double Pds::Matrix::MeanAbsolute(void) const
{
    unsigned int lin,col;
    double S=0;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return Pds::Ra::Nan;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    S=S+fabs(this->array[lin][col]);

    return S/((this->ncol)*(this->nlin));
}
 
double Pds::Matrix::MeanSquare(void) const
{
    unsigned int lin,col;
    double S=0;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return Pds::Ra::Nan;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    S=S+this->array[lin][col]*this->array[lin][col];

    return S/((this->ncol)*(this->nlin));
}


double Pds::Matrix::SumSquare(void) const
{
    unsigned int lin,col;
    double S=0;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return Pds::Ra::Nan;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    S=S+this->array[lin][col]*this->array[lin][col];

    return S;
}
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


////////////////////////////////////////////////////////////////////////////////
double Pds::Matrix::Norm(void) const
{
    unsigned int lin,col;
    double S=0;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return Pds::Ra::Nan;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    S=S+this->array[lin][col]*this->array[lin][col];

    return sqrt(S);
}


double Pds::Matrix::PNorm1(void) const
{
    unsigned int lin,col;
    double S,max=0;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return Pds::Ra::Nan;
    
    for(col=0;col<this->ncol;col++)
    {
        S=0;
        
        for(lin=0;lin<this->nlin;lin++)
        S=S+fabs(this->array[lin][col]);
        
        if(S>max)   max=S;
    }
    return max;
}

double Pds::Matrix::PNormInf(void) const
{
    unsigned int lin,col;
    double S,max=0;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return Pds::Ra::Nan;
    
    for(lin=0;lin<this->nlin;lin++)
    {
        S=0;
        
        for(col=0;col<this->ncol;col++)
        S=S+fabs(this->array[lin][col]);
        
        if(S>max)   max=S;
    }
    return max;
}
////////////////////////////////////////////////////////////////////////////////

double Pds::Matrix::Det(void) const
{
    unsigned int lin,i,col;
    double beta,a_head;
    double det=1;

    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return Pds::Ra::Nan;

    Pds::Matrix Ans=(*this);
    
    // obtengo una matriz escalonada
    for(lin=0;lin<Ans.nlin;lin++)
    {
        if(Ans.array[lin][lin]==0.0)
        {
            if(Ans.RowSwapBelow(lin)>=0)    det=-det; 
            else                            return Pds::Ra::Nan;
        }

        // 
        beta=Ans.array[lin][lin];
        
        // Abajo de la columna (:,lin) todo sera cerado
        for(i=lin+1;i<Ans.nlin;i++)
        {
            a_head=Ans.array[i][lin];
            if(Ans.array[i][lin]!=0.0)
            {
                for(col=lin;col<Ans.ncol;col++)
                Ans.array[i][col]=Ans.array[i][col]-(a_head/beta)*Ans.array[lin][col];
            }
        }
    }

    for(lin=0;lin<Ans.nlin;lin++)
    det=det*Ans.array[lin][lin];
    
    return det;
}

////////////////////////////////////////////////////////////////////////////////

double Pds::Matrix::Dot(const Pds::Matrix &B) const
{
    unsigned int lin,col;
    double S=0;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return Pds::Ra::Nan;
    
    if((B.nlin!=this->nlin)||(B.ncol!=this->ncol))
    return Pds::Ra::Nan;
    
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    S=S+this->array[lin][col]*B.array[lin][col];

    return S;
}

////////////////////////////////////////////////////////////////////////
Pds::Vector Pds::Matrix::Multiindex(const Pds::Vector &ID) const
{
    if(ID.IsEmpty())            return Pds::Matrix();
    if(ID.Nel()!=this->Ncol())  return Pds::Matrix();
    
    Pds::Vector V(this->Nlin(),1.0);
    
    unsigned int lin,col;
    double col_index;
    for(col=0;col<this->Ncol();col++)
    {
        col_index=ID.Get(col);
        for(lin=0;lin<this->Nlin();lin++)
        {
            V.array[lin][0]=V.array[lin][0]*pow(this->array[lin][col],col_index);
        }
    }
    return V;
}
