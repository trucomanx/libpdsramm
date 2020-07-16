/*
 * Array_region.cpp
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
Pds::Vector Pds::Array<Datum>::HistogramNorm(const Pds::RegionRect &R,unsigned int min,unsigned int max) const
{
    if(min>max)                     return Pds::Vector();
    if(R.IsInside(*this)==false)    return Pds::Vector();

    unsigned int L=max-min+1;
    Pds::Vector H(L);
    unsigned int lin,col;
    unsigned int LinEnd=R.L0+R.Nlin-1;
    unsigned int ColEnd=R.C0+R.Ncol-1;
    unsigned int id;
    
    for(lin=R.L0;lin<=LinEnd;lin++)
    for(col=R.C0;col<=ColEnd;col++)
    {
        id=this->array[lin][col];
        if((id>=min)&&(id<=max))
        H.ElementAddAssigRaw(id-min,1);
    }
    double Sum=H.Sum();
    if(Sum!=0)  H.MulAssig(1.0/Sum);
    return H;
}

template <class Datum>
Pds::RegionRect Pds::Array<Datum>::GetRegion(void) const
{

	if(this->IsEmpty()) return Pds::RegionRect();

    return Pds::RegionRect(0,0,this->nlin,this->ncol);
}
