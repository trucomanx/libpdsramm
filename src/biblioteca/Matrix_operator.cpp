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

#include <PDS/Matrix>

////////////////////////////////////////////////////////////////////////

PDS::Matrix& PDS::Matrix::operator = (const PDS::Matrix &A)
{
    if(false==this->Copy(A))
        this->MakeVoid();

    //std::cout<<"used copy assignment\n";
    return *this;
}

bool PDS::Matrix::Copy(const PDS::Matrix &A)
{
    unsigned int lin,col;
    double **newarray=NULL;
    
    if(this!=&A) //Comprueba que no se esté intentando igualar un objeto a sí mismo
    {

        if(A.IsVoid())
        {
            this->MakeVoid();
            return true;
        }

        newarray= PDS::Matrix::AllocateArray(A.nlin,A.ncol);
        if(newarray==NULL) 
        {
            return false;
        }

        for (lin = 0; lin < A.nlin; lin++)
        for (col = 0; col < A.ncol; col++)
        {
                newarray[lin][col]=A.array[lin][col];
        }

        PDS::Matrix::ReleaseArray(this->array,this->nlin);
        this->nlin=A.nlin;
        this->ncol=A.ncol;
        this->array=newarray;
        
    }
    return true;
}

////////////////////////////////////////////////////////////////////////
/*
PDS::Matrix& PDS::Matrix::operator = (PDS::Matrix &&A)
{
    if(false==this->Move(A))
        this->MakeVoid();

    std::cout<<"used move assignment\n";
    return *this;
}
*/

bool PDS::Matrix::Move( PDS::Matrix &A)
{
    if(this!=&A) //Comprueba que no se esté intentando igualar un objeto a sí mismo
    {
        if(A.IsVoid())
        {
            return false;
        }
            
        if(this->IsNotVoid())
            PDS::Matrix::ReleaseArray(this->array,this->nlin);

        this->array = A.array;
        this->nlin = A.nlin;
        this->ncol = A.ncol;
        
        A.array=NULL;
        A.nlin=0;
        A.ncol=0;
        
        return true;
    }
}

////////////////////////////////////////////////////////////////////////

PDS::Matrix& PDS::Matrix::operator +=(const PDS::Matrix &B)
{
    if(false==this->Accumulate(B))
        this->MakeVoid();
    
    return *this;
}

bool PDS::Matrix::Accumulate(const PDS::Matrix &B)
{
    if( this->IsNotSimilarTo(B) )   return false;
    if( B.IsVoid() )                return true;

    unsigned int lin,col;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        this->array[lin][col]=this->array[lin][col]+B.array[lin][col];  
    }

    return true;
}
////////////////////////////////////////////////////////////////////////

PDS::Matrix PDS::Matrix::operator +(const PDS::Matrix &B)
{
    return this->Add(B);
}
PDS::Matrix PDS::Matrix::Add(const PDS::Matrix &B)
{
    if( this->IsNotSimilarTo(B) )   return PDS::Matrix();
    if( B.IsVoid() )                return PDS::Matrix();

    PDS::Matrix Ans(B.nlin,B.ncol);

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
PDS::Matrix PDS::Matrix::operator *(const PDS::Matrix &B)
{
    return this->Mul(B);
}

PDS::Matrix PDS::Matrix::Mul(const PDS::Matrix &B)
{
    if( this->IsNotMulBy(B) )    return PDS::Matrix();
    
    PDS::Matrix Ans(this->nlin,B.ncol);

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
////////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream &out,const PDS::Matrix &mat)
{
    out<<mat.ToString();
    return out;
}
