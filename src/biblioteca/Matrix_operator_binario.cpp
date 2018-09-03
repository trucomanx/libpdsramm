/*
 * Matrix_operator.cpp
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

#include <string>
#include <iostream>

#include <Pds/Ra>

////////////////////////////////////////////////////////////////////////
Pds::Matrix operator+(double b,const Pds::Matrix &mat)
{
    return mat.Add(b);
}


Pds::Matrix Pds::Matrix::operator +(double b) const
{
    return this->Add(b);
}

Pds::Matrix Pds::Matrix::Add(double b) const
{
    if( this->IsEmpty() )                return Pds::Matrix();

    Pds::Matrix Ans(this->nlin,this->ncol);

    //this->Print("(+)this\n");

    unsigned int lin,col;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        Ans.array[lin][col]=this->array[lin][col]+b;
    }

    return Ans;
}

////////////////////////////////////////////////////////////////////////
Pds::Matrix Pds::Matrix::operator +(const Pds::Matrix &B) const
{
    return this->Add(B);
}

Pds::Matrix Pds::Matrix::Add(const Pds::Matrix &B) const
{
    if( this->IsNotSimilarTo(B) )   return Pds::Matrix();
    if( B.IsEmpty() )                return Pds::Matrix();

    Pds::Matrix Ans(B.nlin,B.ncol);

    //this->Print("(+)this\n");

    unsigned int lin,col;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        Ans.array[lin][col]=this->array[lin][col]+B.array[lin][col];  
    }

    return Ans;
}

////////////////////////////////////////////////////////////////////////
Pds::Matrix operator-(double b,const Pds::Matrix &mat)
{
    Pds::Matrix C=mat;
    return -(C.Sub(b));
}


Pds::Matrix Pds::Matrix::operator -(double b) const
{
    return this->Sub(b);
}

Pds::Matrix Pds::Matrix::Sub(double b) const
{
    if( this->IsEmpty() )                return Pds::Matrix();

    Pds::Matrix Ans(this->nlin,this->ncol);

    //this->Print("(+)this\n");

    unsigned int lin,col;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        Ans.array[lin][col]=this->array[lin][col]-b;
    }

    return Ans;
}

////////////////////////////////////////////////////////////////////////
Pds::Matrix Pds::Matrix::operator -(const Pds::Matrix &B) const
{
    return this->Sub(B);
}

Pds::Matrix Pds::Matrix::Sub(const Pds::Matrix &B) const
{
    if( this->IsNotSimilarTo(B) )   return Pds::Matrix();
    if( B.IsEmpty() )                return Pds::Matrix();

    Pds::Matrix Ans(B.nlin,B.ncol);

    //this->Print("(+)this\n");

    unsigned int lin,col;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        Ans.array[lin][col]=this->array[lin][col]-B.array[lin][col];  
    }

    return Ans;
}
////////////////////////////////////////////////////////////////////////

Pds::Matrix operator*(double b,const Pds::Matrix &mat)
{
    return mat.Mul(b);
}


Pds::Matrix Pds::Matrix::operator *(double b) const
{
    return this->Mul(b);
}

Pds::Matrix Pds::Matrix::Mul(double b) const
{
    if( this->IsEmpty() )                return Pds::Matrix();

    Pds::Matrix Ans(this->nlin,this->ncol);

    //this->Print("(+)this\n");

    unsigned int lin,col;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        Ans.array[lin][col]=this->array[lin][col]*b;
    }

    return Ans;
}
////////////////////////////////////////////////////////////////////////
Pds::Matrix Pds::Matrix::operator *(const Pds::Matrix &B) const
{
    return this->Mul(B);
}

Pds::Matrix Pds::Matrix::Mul(const Pds::Matrix &B) const
{
    if( this->IsNotMulBy(B) )    return Pds::Matrix();
    
    Pds::Matrix Ans(this->nlin,B.ncol);

    //this->Print("(*)this\n");
    
    unsigned int lin,col,k;
    double S;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<B.ncol;col++)
    {
        S=0.0;
        for(k=0;k<B.nlin;k++)
        {
            S=S+this->array[lin][k]*B.array[k][col];  
        }
        
        Ans.array[lin][col]=S;
    }
    return Ans;
}
