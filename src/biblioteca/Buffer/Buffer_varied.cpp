/*
 * Buffer_varied.cpp
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
#include <iostream>

// Instantiate Pds::Buffer for the supported template type parameters
template class Pds::Buffer<double>;
template class Pds::Buffer<unsigned char>;
template class Pds::Buffer<unsigned int >;


template<typename Datum> 
bool Pds::Buffer<Datum>::IsEmpty(void) const
{
    if((this->nel==0)||(this->data==NULL))  return true;
    return false;
}
template<typename Datum> 
void Pds::Buffer<Datum>::Print(const std::string &str) const
{
    if(this->nel==0)    return ;
    
    std::cout<<str;
    for(unsigned int i=0;i<this->nel;i++)
    {
        unsigned int pos=(this->front+i)%this->nel;
        std::cout<<this->data[pos];
        if(i==(this->nel-1))    std::cout<<"\n";
        else                    std::cout<<"\t";
    }    
}

