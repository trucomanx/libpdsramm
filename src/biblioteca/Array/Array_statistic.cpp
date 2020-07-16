/*
 * Array_statistic.cpp
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

#include <cstdlib>
#include <cmath>
#include <Pds/Array>
#include <Pds/Vector>
#include <Pds/Matrix>

// Instantiate Pds::Array for the supported template type parameters
template class Pds::Array<double>;
template class Pds::Array<unsigned char>;
template class Pds::Array<unsigned int >;

template <class Datum>
Datum Pds::Array<Datum>::Sum(void) const
{
    if((this->array==NULL)||(this->nlin==0)||(this->ncol==0))    return 0;
    unsigned int lin,col;
    
    Datum sum=0;
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    sum+=this->array[lin][col];

    return sum;
}
