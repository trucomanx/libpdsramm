/*
 * Matrix_getset_extras.cpp
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
#include <Pds/Vector>

#include <cmath>


Pds::Vector Pds::Matrix::GetVector(unsigned int col) const
{   
    if(col>=this->ncol) return Pds::Vector();
    
    double** array=Pds::Matrix::AllocateArray(this->nlin,1);
    if(array==NULL)     return Pds::Vector();
    
    Pds::Vector C;
    
    for(unsigned int lin=0;lin<this->nlin;lin++)
    array[lin][0]=this->array[lin][col];
    
    C.array=array;
    C.nlin=this->nlin;
    C.ncol=1;
    return C;
}
    
bool Pds::Matrix::SetVector(const Pds::Vector V,unsigned int col)
{   
    if(col>=this->ncol) return false;
    
    if(this->IsEmpty()) return false;
    if(V.IsEmpty())     return false;
    
    unsigned int Nlin=std::min(V.Nlin(),this->nlin);
    
    for(unsigned int lin=0;lin<Nlin;lin++)
    this->array[lin][col]=V.Get(lin);
    
    return true;
}
    
