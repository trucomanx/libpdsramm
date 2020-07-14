/*
 * Buffer_getset.cpp
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

// Instantiate Pds::Buffer for the supported template type parameters
template class Pds::Buffer<double>;
template class Pds::Buffer<unsigned char>;
template class Pds::Buffer<unsigned int >;


// returns true if add was successful, false if the buffer is already IsFull
template<typename Datum> 
bool Pds::Buffer<Datum>::Push(const Datum &Dat) 
{
    if(this->nel==0)    return false;

    this->front = (this->nel+this->front -1) % this->nel;
    this->data[this->front] = Dat;
    return true;
}

