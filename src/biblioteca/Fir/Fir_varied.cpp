/*
 * Fir_varied.cpp
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


bool Pds::Fir::IsEmpty(void) const
{
    if((this->M==0)||(this->H==NULL)||(this->X==NULL))    return true;
    return false;
}

void Pds::Fir::Print(std::string str) const
{
    unsigned int i=0;
    if((this->M==0)||(this->H==NULL)||(this->X==NULL))    return;

    std::cout<<str;

    std::cout<<"M:\t"<<M<<std::endl;

    std::cout<<"H:";
    for(i=0;i<this->M;i++)  
    std::cout<<"\t"<<this->H[i];
    std::cout<<std::endl;

    std::cout<<"X:";
    for(i=0;i<this->M;i++)  
    std::cout<<"\t"<<this->X[i];
    std::cout<<std::endl;

    return;
}
