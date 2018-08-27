/*
 * Matrix_operator_acumulate.cpp
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

#include <Pds/RealArrays>



////////////////////////////////////////////////////////////////////////

Pds::Matrix& Pds::Matrix::operator = (const Pds::Matrix &A)
{
    if(false==this->Copy(A))
        this->MakeVoid();

    //std::cout<<"used copy assignment\n";
    return *this;
}

bool Pds::Matrix::Copy(const Pds::Matrix &A)
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

        newarray= Pds::Matrix::AllocateArray(A.nlin,A.ncol);
        if(newarray==NULL) 
        {
            return false;
        }

        for (lin = 0; lin < A.nlin; lin++)
        for (col = 0; col < A.ncol; col++)
        {
                newarray[lin][col]=A.array[lin][col];
        }

        Pds::Matrix::ReleaseArray(this->array,this->nlin);
        this->nlin=A.nlin;
        this->ncol=A.ncol;
        this->array=newarray;
        
    }
    return true;
}

////////////////////////////////////////////////////////////////////////
/*
Pds::Matrix& Pds::Matrix::operator = (Pds::Matrix &&A)
{
    if(false==this->Move(A))
        this->MakeVoid();

    std::cout<<"used move assignment\n";
    return *this;
}
*/

bool Pds::Matrix::Move( Pds::Matrix &A)
{
    if(this!=&A) //Comprueba que no se esté intentando igualar un objeto a sí mismo
    {
        if(A.IsVoid())
        {
            return false;
        }
            
        if(this->IsNotVoid())
            Pds::Matrix::ReleaseArray(this->array,this->nlin);

        this->array = A.array;
        this->nlin = A.nlin;
        this->ncol = A.ncol;
        
        A.array=NULL;
        A.nlin=0;
        A.ncol=0;
        
    }
    return true;
}

////////////////////////////////////////////////////////////////////////

Pds::Matrix& Pds::Matrix::operator -=(const Pds::Matrix &B)
{
    if(false==this->SubAssig(B))
        this->MakeVoid();
    
    return *this;
}

bool Pds::Matrix::SubAssig(const Pds::Matrix &B)
{
    if( this->IsNotSimilarTo(B) )   return false;
    if( B.IsVoid() )                return true;

    unsigned int lin,col;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        this->array[lin][col]=this->array[lin][col]-B.array[lin][col];  
    }

    return true;
}
////////////////////////////////////////////////////////////////////////

Pds::Matrix& Pds::Matrix::operator +=(const Pds::Matrix &B)
{
    if(false==this->AddAssig(B))
        this->MakeVoid();
    
    return *this;
}

bool Pds::Matrix::AddAssig(const Pds::Matrix &B)
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
