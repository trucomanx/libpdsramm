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


#include <Pds/Matrix>

Pds::Matrix::Matrix(void)
{

    this->nlin=0;
    this->ncol=0;
    this->array=NULL;
}

Pds::Matrix::Matrix(unsigned int N)
{

    this->nlin=N;
    this->ncol=N;
    this->array=NULL;

    if(N==0)    return;

    
    this->array= Pds::Matrix::ArrayAllocate(N,N);
    if(this->array==NULL) 
    {
        this->nlin=0;
        this->ncol=0;

        return;
    }
    //std::cout<<"Matrix(n);\n";
}

Pds::Matrix::Matrix(const Pds::Size &A)
{
    this->nlin=0;
    this->ncol=0;
    this->array=NULL;
    
    if((A.nlin==0)||(A.ncol==0))    return;
    
    this->array= Pds::Matrix::ArrayAllocate(A.nlin,A.ncol);
    if(this->array==NULL)       return;
    
    this->nlin=A.nlin;
    this->ncol=A.ncol;
}


Pds::Matrix::Matrix(const char *str)
{
    this->array=NULL;
    this->nlin=0;
    this->ncol=0;
    this->array=Pds::Matrix::ArrayFromString(str,this->nlin,this->ncol);
    
    return;
}

Pds::Matrix::Matrix(unsigned int nlin,unsigned int ncol)
{
    this->nlin=0;
    this->ncol=0;
    this->array=NULL;
    
    if((nlin==0)||(ncol==0))    return;
    
    this->array= Pds::Matrix::ArrayAllocate(nlin,ncol);
    if(this->array==NULL)       return;
    
    this->nlin=nlin;
    this->ncol=ncol;
    //std::cout<<"Matrix(nlin,ncol);\n";
}

Pds::Matrix::Matrix(unsigned int nlin,unsigned int ncol,double val)
{

    this->nlin=0;
    this->ncol=0;
    this->array=NULL;
    
    if((nlin==0)||(ncol==0))    return;
    
    this->array= Pds::Matrix::ArrayAllocate(nlin,ncol,val);
    if(this->array==NULL)       return;
    
    this->nlin=nlin;
    this->ncol=ncol;
    //std::cout<<"Matrix(nlin,ncol);\n";
}

// Copy assignment  constructor
Pds::Matrix::Matrix(const Matrix &A)
{
    if(this!=&A) //Comprueba que no se esté intentando igualar un objeto a sí mismo
    {
        this->nlin=0;
        this->ncol=0;
        this->array=NULL;
        
        if(A.IsEmpty())  return;


        this->array= Pds::Matrix::ArrayAllocate(A);
        if(this->array==NULL)  return;
    
        this->nlin=A.nlin;
        this->ncol=A.ncol;
    }
    //std::cout<<"Copy asignment contructor\n";

    return;
}

Pds::Matrix::Matrix(double (*func)(double),const Pds::Matrix &A)
{
    this->nlin=0;
    this->ncol=0;
    this->array=NULL;
        
    if(A.IsEmpty())  return;


    this->array= Pds::Matrix::ArrayAllocate(func,A);
    if(this->array==NULL)  return;
    
    this->nlin=A.nlin;
    this->ncol=A.ncol;
    
    return;
}

Pds::Matrix::Matrix(double (*func)(double,double),const Pds::Matrix &B,double var)
{
    this->nlin=0;
    this->ncol=0;
    this->array=NULL;
        
    if(B.IsEmpty())  return;


    this->array= Pds::Matrix::ArrayAllocate(func,B,var);
    if(this->array==NULL)  return;
    
    this->nlin=B.nlin;
    this->ncol=B.ncol;
    
    return;
}


Pds::Matrix::Matrix(double (*func)(double,double),const Pds::Matrix &B,const Pds::Matrix &C)
{
    this->nlin=0;
    this->ncol=0;
    this->array=NULL;
        
    if(B.IsEmpty())  return;
    if(C.IsEmpty())  return;
    if(B.IsNotSimilarTo(C)) return;

    this->array= Pds::Matrix::ArrayAllocate(func,B,C);
    if(this->array==NULL)  return;
    
    this->nlin=B.nlin;
    this->ncol=B.ncol;
    
    return;
}

Pds::Matrix::Matrix(Pds::Ra::FormatType Type,std::string filepath)
{
    this->array=0;
    this->nlin=0;
    this->ncol=0;
        
    if(Type==Pds::Ra::TextFormat)
    {
        this->array=Pds::Matrix::ArrayLoad(filepath.c_str(),this->nlin,this->ncol);
    }
        
    return;
}

Pds::Matrix::~Matrix(void)
{
    Pds::Matrix::ArrayRelease(this->array,this->nlin);
    //std::cout<<"matrix destructr\n";
    this->nlin=0;
    this->ncol=0;
}

