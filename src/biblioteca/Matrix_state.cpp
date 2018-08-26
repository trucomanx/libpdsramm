/*
 * Matrix_state.cpp
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

#include <cmath>

#include <Pds/Matrix>


bool Pds::Matrix::IsVoid(void) const
{
    if((this->nlin)==0)    return true;
    if((this->ncol)==0)    return true;
    if((this->array)==NULL)    return true;

    return false;
}

bool Pds::Matrix::IsNotVoid(void) const
{
    if((this->nlin)==0)    return false;
    if((this->ncol)==0)    return false;
    if((this->array)==NULL)    return false;

    return true;
}

void Pds::Matrix::MakeVoid(void)
{
    Pds::Matrix::ReleaseArray(this->array,this->nlin);
    this->nlin=0;
    this->ncol=0;
}

bool Pds::Matrix::IsSimilarTo(const Pds::Matrix &B) const
{
    if((this->nlin)!=B.nlin)    return false;
    if((this->ncol)!=B.ncol)    return false;
    
    if( ((this->array)==NULL)&&(B.array==NULL) )    return true;
    if( ((this->array)!=NULL)&&(B.array==NULL) )    return false;
    if( ((this->array)==NULL)&&(B.array!=NULL) )    return false;
    
    return true;
}
bool Pds::Matrix::IsNotSimilarTo(const Pds::Matrix &B) const
{
    if((this->nlin)!=B.nlin)    return true;
    if((this->ncol)!=B.ncol)    return true;
    
    if( ((this->array)==NULL)&&(B.array==NULL) )    return false;
    if( ((this->array)!=NULL)&&(B.array==NULL) )    return true;
    if( ((this->array)==NULL)&&(B.array!=NULL) )    return true;
 
    return false;
}

bool Pds::Matrix::IsMulBy(const Pds::Matrix &B) const
{
    if(this->IsVoid())  return false;
    if(B.IsVoid())      return false;
    
    if((this->ncol)!=B.nlin)    return false;
    
    return true;
}

bool Pds::Matrix::IsNotMulBy(const Pds::Matrix &B) const
{
    if(this->IsVoid())  return true;
    if(B.IsVoid())      return true;
    
    if((this->ncol)!=B.nlin)    return true;
    
    return false;
}


bool Pds::Matrix::IsInSizeRange(double lin,double col) const
{
    if(this->IsVoid())      return false;
    if(col<0)               return false;    
    if(lin<0)               return false;
    if(col>(this->ncol-1))  return false;    
    if(lin>(this->nlin-1))  return false;
    
    return true;
}


bool Pds::Matrix::IsInRange(unsigned int lin,unsigned int col) const
{
    if(this->IsVoid())  return false;
    if(col>=this->ncol) return false;    
    if(lin>=this->nlin) return false;
    
    return true;
}

bool Pds::Matrix::IsNotInRange(unsigned int lin,unsigned int col) const
{
    if(this->IsVoid())  return true;
    if(col>=this->ncol) return true;    
    if(lin>=this->nlin) return true;
    
    return false;
}


Pds::Matrix Pds::Matrix::IsInf(void) const
{
    Pds::Matrix A(this->nlin,this->ncol);
    
    if(A.IsVoid())      return A;
    if(this->IsVoid())  return A;
    
    unsigned int lin,col;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    A.array[lin][col]=std::isinf(this->array[lin][col]);
    
    return A;
}


Pds::Matrix Pds::Matrix::IsNan(void) const
{
    Pds::Matrix A(this->nlin,this->ncol);
    
    if(A.IsVoid())      return A;
    if(this->IsVoid())  return A;
    
    unsigned int lin,col;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    A.array[lin][col]=std::isnan(this->array[lin][col]);
    
    return A;
}


Pds::Matrix Pds::Matrix::IsFinite(void) const
{
    Pds::Matrix A(this->nlin,this->ncol);
    
    if(A.IsVoid())      return A;
    if(this->IsVoid())  return A;
    
    unsigned int lin,col;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    A.array[lin][col]=std::isfinite(this->array[lin][col]);
    
    return A;
}
