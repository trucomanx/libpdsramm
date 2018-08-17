/*
 * Eye.cpp
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


#include <PDS/Eye>

PDS::Eye::Eye(void)
{
    return;
}

PDS::Eye::Eye(unsigned int N): PDS::Matrix(N)
{
    unsigned int lin,col;
    
    if((this->nlin!=0)&&(this->ncol!=0)&&(this->array!=NULL))
    {
        for(lin=0;lin<N;lin++)
        this->array[lin][lin]=1.0;
    }
}

PDS::Eye::~Eye(void)
{
    PDS::Matrix::ReleaseArray(this->array,this->nlin);

    this->nlin=0;
    this->ncol=0;
}

