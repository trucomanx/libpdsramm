/*
 * Fir.cpp
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


#include <Pds/Fir>
#include <iostream>

#include <Pds/Buffer>

Pds::Fir::Fir(void)
{
    this->M=0;
    this->H=NULL;
    this->X=NULL;
    return;
}

Pds::Fir::Fir(const Pds::Vector &VecH) 
{
    this->M=0;
    this->H=NULL;
    this->X=NULL;
    if(VecH.IsEmpty()) return;

    unsigned int N=VecH.Nel();
    this->M=N-1;
    this->H=new double[N];
    this->X=new double[N];
    
    for(unsigned int i=0;i<N;i++)
    {
        this->H[i]=VecH.Get(i);
        this->X[i]=0.0;
    }

}


Pds::Fir::~Fir(void)
{
    this->M=0;
    if(this->H!=NULL) 
    {
        delete[] this->H; 
        this->H=NULL;
    }

    if(this->X!=NULL)
    { 
        delete[] this->X; 
        this->X=NULL;
    }
}

