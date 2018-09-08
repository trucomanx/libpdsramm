/*
 * Vector.cpp
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


#include <Pds/Vector>

Pds::Vector::Vector(void)
{
    return;
}

Pds::Vector::Vector(unsigned int N): Pds::Matrix(N,1)
{
    return;
}


Pds::Vector::Vector(const Matrix &A)
{
    if(this!=&A) //Comprueba que no se esté intentando igualar un objeto a sí mismo
    {
        this->nlin=0;
        this->ncol=0;
        this->array=NULL;
        
        if(A.IsEmpty()) return;
        
        unsigned int N=A.Nlin()*A.Ncol();
        unsigned int id;
        
        this->array= Pds::Matrix::ArrayAllocate(N,1);
        if(this->array==NULL)  return;
        
        for(id=0;id<N;id++)
        this->Set(A.Get(id),id);
        
        this->nlin=N;
        this->ncol=1;
    }

    return;
}

Pds::Vector::Vector(const Matrix &A, unsigned int col)
{

    this->nlin=0;
    this->ncol=0;
    this->array=NULL;
       
    if(A.IsEmpty())     return;
    if(col>=A.Ncol())   return;
        
    unsigned int lin;
        
    this->array= Pds::Matrix::ArrayAllocate(A.Nlin(),1);
    if(this->array==NULL)  return;
        
    for(lin=0;lin<A.Nlin();lin++)
    this->Set(A.Get(lin,col),lin,0);
        
    this->nlin=A.Nlin();
    this->ncol=1;
    
    return;
}


Pds::Vector::~Vector(void)
{
    Pds::Matrix::ArrayRelease(this->array,this->nlin);

    this->nlin=0;
    this->ncol=0;
}

