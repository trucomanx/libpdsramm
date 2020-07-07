/*
 * Array.cpp
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


#include <Pds/Array>
#include <iostream>


// Instantiate Pds::Array for the supported template type parameters
template class Pds::Array<double>;
template class Pds::Array<unsigned char>;
template class Pds::Array<unsigned int >;

template <class Datum>
Pds::Array<Datum>::Array(void)
{
    this->array=NULL;
    this->nlin=0;
    this->ncol=0;
}

template <class Datum>
Pds::Array<Datum>::Array(unsigned int nlin,unsigned int ncol)
{
    this->nlin=0;
    this->ncol=0;
    this->array=NULL;
    
    if((nlin==0)||(ncol==0))    return;
    
    this->array= Pds::Array<Datum>::ArrayAllocate(nlin,ncol);
    if(this->array==NULL)       return;
    
    this->nlin=nlin;
    this->ncol=ncol;
    return;
}

template <class Datum>
Pds::Array<Datum>::Array(unsigned int nlin,unsigned int ncol,Datum val)
{

    this->nlin=0;
    this->ncol=0;
    this->array=NULL;
    
    if((nlin==0)||(ncol==0))    return;
    
    this->array= Pds::Array<Datum>::ArrayAllocate(nlin,ncol,val);
    if(this->array==NULL)       return;
    
    this->nlin=nlin;
    this->ncol=ncol;
    return;
}

template <class Datum>
Pds::Array<Datum>::Array(const Pds::Size &A)
{
    this->nlin=0;
    this->ncol=0;
    this->array=NULL;
    
    if((A.nlin==0)||(A.ncol==0))    return;
    
    this->array= Pds::Array<Datum>::ArrayAllocate(A.nlin,A.ncol);
    if(this->array==NULL)       return;
    
    this->nlin=A.nlin;
    this->ncol=A.ncol;
}



template <class Datum>
Pds::Array<Datum>::Array(const Pds::Array<Datum> &A)
{
    if(this!=&A) //Comprueba que no se esté intentando igualar un objeto a sí mismo
    {
        this->nlin=0;
        this->ncol=0;
        this->array=NULL;
        
        if(A.IsEmpty())  return;


        this->array= Pds::Array<Datum>::ArrayAllocate(A);
        if(this->array==NULL)  return;
    
        this->nlin=A.nlin;
        this->ncol=A.ncol;
    }
    //std::cout<<"Copy asignment contructor\n";

    return;
}


template <class Datum>
Pds::Array<Datum>::~Array(void)
{
    Pds::Array<Datum>::ArrayRelease(this->array,this->nlin);
    this->array=NULL;
    this->nlin=0;
    this->ncol=0;
    
}


template <class Datum>
Pds::Array<Datum>& Pds::Array<Datum>::operator = (const Pds::Array<Datum> &A)
{
    if(false==this->Copy(A))
        this->MakeEmpty();

    //std::cout<<"used copy assignment\n";
    return *this;
}

template <class Datum>
bool Pds::Array<Datum>::Copy(const Pds::Array<Datum> &A)
{
   
    if(this!=&A) //Comprueba que no se esté intentando igualar un objeto a sí mismo
    {
        unsigned int lin,col;


        
        Datum **tmparray=NULL;

        if((A.nlin==0)||(A.ncol==0)||(A.array==NULL))    return false;

        tmparray= new Datum*[A.nlin];
        if(tmparray==NULL) return false;
        
        
        for (lin = 0; lin < A.nlin; lin++)
        {
            tmparray[lin] = new Datum[A.ncol];
            if(tmparray[lin]==NULL)
            {
                Pds::Array<Datum>::ArrayRelease(tmparray,lin);
                tmparray=NULL;
                return false;
            }
            for (col = 0; col < A.ncol; col++) tmparray[lin][col]=A.array[lin][col];
        }

        Pds::Array<Datum>::ArrayRelease(this->array,A.nlin);
        this->array=tmparray;
        this->nlin=A.nlin;
        this->ncol=A.ncol;
    }
    return true;
}

