
#include <Pds/Matrix>

////////////////////////////////////////////////////////////////////////

Pds::Matrix Pds::Matrix::Round(unsigned int decimal) const
{
    unsigned int lin,col;
    if(this->IsEmpty()) return Pds::Matrix();

    Pds::Matrix Ans(this->Size());
    if(Ans.IsEmpty())  return Pds::Matrix();
    
    double a=pow(10,decimal);
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        Ans.array[lin][col]=round(this->array[lin][col]*a)/a;
    }

    return Ans;
}
////////////////////////////////////////////////////////////////////////

Pds::Matrix Pds::Matrix::Scale(double minval,double maxval) const
{
    unsigned int lin,col;
    if(minval==maxval)  return Pds::Matrix();
    if(this->IsEmpty()) return Pds::Matrix();

    Pds::Matrix Ans(this->Size());
    if(Ans.IsEmpty())  return Pds::Matrix();
    
    double a=minval>maxval?maxval:minval;
    double b=maxval>minval?maxval:minval;
    minval=a;
    maxval=b;
    
    double mindat=this->Min();
    double maxdat=this->Max();

    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        Ans.array[lin][col]=minval+(maxval-minval)*(this->array[lin][col]-mindat)/(maxdat-mindat);
    }

    return Ans;
}

////////////////////////////////////////////////////////////////////////

Pds::Matrix Pds::Matrix::OperateRows(double (*func)(const Pds::Matrix &Row)) const
{
    if(this->IsEmpty())   return Pds::Matrix();
    
    unsigned int lin;
    Pds::Matrix matrow;
    Pds::Matrix Ans(this->nlin,1);

    for(lin=0;lin<this->nlin;lin++)
    {
        matrow=this->GetRow(lin);
        Ans.array[lin][0]=(*func)(matrow);
    }
    return Ans;
}

Pds::Matrix Pds::Matrix::OperateCols(double (*func)(const Pds::Matrix &Col)) const
{
    if(this->IsEmpty())   return Pds::Matrix();
    
    unsigned int col;
    Pds::Matrix matcol;
    Pds::Matrix Ans(1,this->ncol);

    for(col=0;col<this->ncol;col++)
    {
        matcol=this->GetCol(col);
        Ans.array[0][col]=(*func)(matcol);
    }
    return Ans;
}


