/*
 * Array_export.cpp
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

// Instantiate Pds::Array for the supported template type parameters
template class Pds::Array<double>;
template class Pds::Array<unsigned char>;
template class Pds::Array<unsigned int >;

template <class Datum>
bool Pds::Array<Datum>::ExportBmpFile(const unsigned char colormap[256][3],const std::string &filepath) const
{
    if(filepath.size()==0)  return false;

    if(this->IsEmpty()) return false;
    if(colormap==NULL)  return false;
    
    bool ret=Pds::Array<Datum>::ArrayWriteBmpWithColormap(this->array,this->nlin,this->ncol,colormap,filepath.c_str());
    return ret;
}


template <class Datum>
bool Pds::Array<Datum>::ExportBmpFile(const Pds::Array<unsigned char> &Colormap,const std::string &filepath) const
{
    if(filepath.size()==0)  return false;

    if(this->IsEmpty())     return false;
    if(Colormap.IsEmpty())  return false;
    
    bool ret=Pds::Array<Datum>::ArrayWriteBmpWithColormap(this->array,this->nlin,this->ncol,Colormap,filepath.c_str());
    return ret;
}
