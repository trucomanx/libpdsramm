/*
 * Vector_memory.cpp
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


#include <Pds/Vector>
#include <Pds/Matrix>
#include <iostream>
#include <list>

bool Pds::Vector::Reshape(unsigned int Nlin,unsigned int Ncol)
{
    return this->Reshape(Nlin*Ncol);
}

bool Pds::Vector::Reshape(unsigned int Nel)
{
    if((Nel==0))    return false;
    
    double **new_array= Pds::Array<double>::ArrayReshape(*this,Nel,1);
    if(new_array==NULL)       return false;
    
    Pds::Array<double>::ArrayRelease(this->array,this->nlin);

    this->array=new_array;
    this->nlin=Nel;
    this->ncol=1;
    return true;
}

bool Pds::Vector::FusionVer(std::list<Pds::Matrix> &list)
{
    unsigned int Nlin=0;
    
    this->MakeEmpty();
    
    unsigned int i=0;
    for (auto pmat = list.begin(); pmat != list.end(); pmat++) 
    {

        if(pmat->Ncol()!=1)
        {
            pds_print_error_message("The "<<i<<"-th matrix in list don't have the same column length of 0-th.");
            return false;
        }


        Nlin=Nlin+pmat->Nlin();
        i++;
    }
    
    this->array= new double*[Nlin];
    if(this->array==NULL) return false;
    this->nlin=Nlin;
    this->ncol=1;    

    unsigned int lin=0;
    for (auto pmat = list.begin(); pmat != list.end(); pmat++) 
    {        
        for(unsigned int i=0;i<pmat->nlin;i++,lin++)
        {
            this->array[lin]=pmat->array[i];
            pmat->array[i]=NULL;
        }
        pmat->MakeEmpty();
    }

    return true;
}

