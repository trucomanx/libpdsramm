/*
 * Matrix_getset.cpp
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

double Pds::Matrix::Get(unsigned int lin,unsigned int col) const
{
    if(this->HasThePosition(lin,col))   return this->array[lin][col];
    else                                return 0.0;
}
    

bool Pds::Matrix::Set(double val,unsigned int lin,unsigned int col)
{
    if(this->DontHaveThePosition(lin,col))   return false;
    
    this->array[lin][col]=val;
    return true;
}
    
unsigned int Pds::Matrix::Nlin(void) const
{
    return this->nlin;
}

unsigned int Pds::Matrix::Ncol(void) const
{
    return this->ncol;
}
