/*
 * Buffer.cpp
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


#include <Pds/Buffer>
#include <stdexcept>
#include <iostream>

// Instantiate Pds::Buffer for the supported template type parameters
template class Pds::Buffer<double>;
template class Pds::Buffer<unsigned char>;
template class Pds::Buffer<unsigned int >;


template<typename Datum> 
Pds::Buffer<Datum>::Buffer(void)
{
    this->nel = 0;    
    this->data = NULL;
    this->front = 0;
}


template<typename Datum> 
Pds::Buffer<Datum>::Buffer(unsigned int Nel)
{
    this->data = NULL;
    this->front = 0;
    this->nel = 0;    

    if (Nel==0) return;
    
    this->data = new Datum[Nel];
    if(this->data==NULL)    return;
    
    for(unsigned int i=0;i<Nel;i++) this->data[i]=0;
    this->nel = Nel;
    this->front = 0;
}


template<typename Datum> 
Pds::Buffer<Datum>::Buffer(const Pds::Buffer<Datum> &B)
{
    this->data = NULL;
    this->front = 0;
    this->nel = 0;    

    if (B.nel==0) return;
    
    this->data = new Datum[B.nel];
    if(this->data==NULL)    return;
    
    for(unsigned int i=0;i<B.nel;i++) this->data[i]=B.data[i];
    this->nel = B.nel;
    this->front = B.front;
}

template<typename Datum> 
Pds::Buffer<Datum>::~Buffer() 
{
    delete[] this->data;
    this->data = NULL;
    this->front = 0;
    this->nel = 0;  
}



