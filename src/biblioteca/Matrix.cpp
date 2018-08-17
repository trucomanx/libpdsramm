/*
 * Matrix.cpp
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


#include <PDS/Matrix>

PDS::Matrix::Matrix(void)
{

    this->nlin=0;
    this->ncol=0;
    this->array=NULL;
}

PDS::Matrix::Matrix(unsigned int N)
{

    this->nlin=N;
    this->ncol=N;
    this->array=NULL;

    if(N==0)    return;

    
    this->array= PDS::Matrix::AllocateArray(N,N);
    if(this->array==NULL) 
    {
        this->nlin=0;
        this->ncol=0;

        return;
    }
    //std::cout<<"Matrix(n);\n";
}

PDS::Matrix::Matrix(unsigned int nlin,unsigned int ncol)
{

    this->nlin=nlin;
    this->ncol=ncol;
    this->array=NULL;

    if((nlin==0)||(ncol==0))
    {
        this->nlin=0;
        this->ncol=0;
        this->array=NULL;

        return;
    }
    
    this->array= PDS::Matrix::AllocateArray(nlin,ncol);
    if(this->array==NULL) 
    {
        this->nlin=0;
        this->ncol=0;

        return;
    }
    //std::cout<<"Matrix(nlin,ncol);\n";
}

// Copy assignment  constructor
PDS::Matrix::Matrix(const Matrix &A)
{
    unsigned int lin,col;
    
    if(this!=&A) //Comprueba que no se esté intentando igualar un objeto a sí mismo
    {
        this->nlin=0;
        this->ncol=0;
        this->array=NULL;
        
        if(A.IsVoid())  return;


        this->array= PDS::Matrix::AllocateArray(A.nlin,A.ncol);
        if(this->array==NULL)  return;
        
        for (lin = 0; lin < A.nlin; lin++)
        for (col = 0; col < A.ncol; col++)
        {
                this->array[lin][col]=A.array[lin][col];
        }
    
        this->nlin=A.nlin;
        this->ncol=A.ncol;
    }
    //std::cout<<"Copy asignment contructor\n";

    return;
}
/*
PDS::Matrix::Matrix(PDS::Matrix &&A)
{
    if(this!=&A) //Comprueba que no se esté intentando igualar un objeto a sí mismo
    {
        this->nlin=0;
        this->ncol=0;
        this->array=NULL;
        
        if(A.IsVoid())  return;
            
        this->array = A.array;
        this->nlin = A.nlin;
        this->ncol = A.ncol;
        
        A.array=NULL;
        A.nlin=0;
        A.ncol=0;
        
    }
    
    std::cout<<"Move asignment contructor\n";
    
    return;
}

*/

PDS::Matrix::~Matrix(void)
{
    PDS::Matrix::ReleaseArray(this->array,this->nlin);

    this->nlin=0;
    this->ncol=0;
}

