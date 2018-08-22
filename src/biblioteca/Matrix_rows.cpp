/*
 * Matrix_rows.cpp
 * 
 * Copyright 2018 Fernando Pujaico Rivera <fernando.pujaico.rivera@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */

#include <Pds/RealArrays>

bool Pds::Matrix::SwapRows(unsigned int lin1,unsigned int lin2)
{
    if( (lin1>=this->nlin)||(lin2>=this->nlin) )    return false;
    
    double *tmp=this->array[lin1];
    
    this->array[lin1]=this->array[lin2];
    this->array[lin2]=tmp;
    
    return true;
}


bool Pds::Matrix::RowMul(unsigned int lin,double alpha)
{
    if( (lin>=this->nlin))    return false;
    
    for(unsigned int col=0;col<this->ncol;col++)
    this->array[lin][col]=this->array[lin][col]*alpha;
    
    return true;
}

bool Pds::Matrix::RowDiv(unsigned int lin,double alpha)
{
    if( (lin>=this->nlin))    return false;
    
    for(unsigned int col=0;col<this->ncol;col++)
    this->array[lin][col]=this->array[lin][col]/alpha;
    
    return true;
}


int Pds::Matrix::DiagonalIsZeroSwapBelow(unsigned int n)
{
    if( (n>=this->nlin)||(n>=this->ncol) )    return -1;
    
    if(this->array[n][n]!=0)    return (int)n;
    
    for(unsigned int i=n+1;i<this->nlin;i++)
    if(this->array[i][n]!=0)
    {
        double *tmp=this->array[i];
        this->array[i]=this->array[n];
        this->array[n]=tmp;
        return n;
    }
    return -1;
}

bool Pds::Matrix::AccumulateRow(unsigned int lin1,unsigned int lin2,double alpha)
{
    if( (lin1>=this->nlin)||(lin2>=this->nlin) )    return false;
    
    for(unsigned int col=0;col<this->ncol;col++)
    this->array[lin1][col]=this->array[lin1][col]+alpha*this->array[lin2][col];
    
    return true;
}

bool Pds::Matrix::RowReduction(void)
{
    unsigned int lin,i,all;
    double alpha;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return false;
    
    // obtengo una matriz escalonada
    for(lin=0;lin<this->nlin;lin++)
    {
        if(DiagonalIsZeroSwapBelow(lin)>=0)
        {
            // genero una linea con 1 en la posicion (lin,lin)
            alpha=this->array[lin][lin];
            for(all=0;all<this->ncol;all++)
            {
                this->array[lin][all]=this->array[lin][all]/alpha;
            }
            
            // Abajo de la columna (:,lin) todo sera cerado
            for(i=lin+1;i<this->nlin;i++)
            {
                alpha=this->array[i][lin];
                if(this->array[i][lin]!=0)
                {
                    for(all=lin;all<this->ncol;all++)
                    this->array[i][all]=this->array[i][all]-alpha*(this->array[lin][all]);
                }
            }
            
        }
        else return false;
    }

    // reduzco la matriz
    for(lin=1;lin<this->nlin;lin++)
    {
        for(i=1;i<=lin;i++)
        {
            alpha=this->array[lin-i][lin];
            
            for(all=lin;all<this->ncol;all++)
            this->array[lin-i][all]=this->array[lin-i][all]-alpha*(this->array[lin][all]);
        }
    }
    return true;
}

Pds::Matrix Pds::Matrix::GetInv(void) const
{
    double det;
    return GetInv(det);
}

Pds::Matrix Pds::Matrix::GetInv(double &det) const
{
    unsigned int lin,i,all;
    int id;
    double alpha;
    double determinant=1.0;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL)||(this->ncol!=this->nlin))
    {
        Pds::Matrix A;
        return A;
    }
    
    Pds::Matrix B(*this);
    Pds::Matrix A= Pds::Eye(this->nlin);
    
    // obtengo una matriz escalonada
    for(lin=0;lin<B.nlin;lin++)
    {
        id=B.DiagonalIsZeroSwapBelow(lin);
        if(id>=0)
        {
            if(((unsigned int)id)!=lin)
            {
                determinant=-determinant;
                A.SwapRows((unsigned int)id,lin);
            }
            
            // genero una linea con 1 en la posicion (lin,lin)
            alpha=B.array[lin][lin];
            A.RowDiv(lin,alpha);
            determinant=alpha*determinant;
            for(all=lin;all<B.ncol;all++)
            {
                B.array[lin][all]=B.array[lin][all]/alpha;
            }
            
            // Abajo de la columna (:,lin) todo sera cerado
            for(i=lin+1;i<B.nlin;i++)
            {
                alpha=B.array[i][lin];
                if(B.array[i][lin]!=0)
                {
                    A.AccumulateRow(i,lin,-alpha);
                    
                    for(all=lin;all<B.ncol;all++)
                    B.array[i][all]=B.array[i][all]-alpha*(B.array[lin][all]);
                }
            }
            
            
        }
        else
        {
            A.MakeVoid();
            return A;
        }
    }

    // reduzco la matriz
    for(lin=1;lin<B.nlin;lin++)
    {
        for(i=1;i<=lin;i++)
        {
            alpha=B.array[lin-i][lin];

            A.AccumulateRow(lin-i,lin,-alpha);
            
            for(all=lin;all<B.ncol;all++)
            B.array[lin-i][all]=B.array[lin-i][all]-alpha*(B.array[lin][all]);
        }
    }

    det=determinant;
    return A;
}
