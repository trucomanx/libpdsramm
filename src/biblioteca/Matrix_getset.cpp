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
#include <cmath>


double Pds::Matrix::Get(unsigned int id) const
{
    if((this->ncol==0)||(this->nlin==0)||(this->array==NULL)) return 0.0;
    
    if(id>=((this->nlin)*(this->ncol))) return 0.0;
    
    
    return this->array[id%this->nlin][id/this->nlin];
}

bool Pds::Matrix::Set(double val,unsigned int id)
{
    if((this->ncol==0)||(this->nlin==0)||(this->array==NULL)) return false;
    
    if(id>=((this->nlin)*(this->ncol))) return false;
    
    this->array[id%this->nlin][id/this->nlin]=val;
    
    return  true;
}
    
double Pds::Matrix::Get(unsigned int lin,unsigned int col) const
{
    if(this->IsInRange(lin,col))   return this->array[lin][col];
    else                           return 0.0;
}
    
double Pds::Matrix::GetBilinear(double lin,double col) const
{
    if((lin<0.0)||(col<0.0)||(lin>(this->nlin-1))||(col>(this->ncol-1)))
    return 0.0;

    unsigned int Ll=floor(lin);
    unsigned int Lc=floor(col);
    unsigned int Hl=ceil(lin);
    unsigned int Hc=ceil(col);
    
    double alpha=col-floor(col);
    double beta=lin-floor(lin);

    double P1=this->array[Ll][Lc];
    double P2=this->array[Ll][Hc];
    double P3=this->array[Hl][Lc];
    double P4=this->array[Hl][Hc];

    return  (1.0-beta)*(1.0-alpha)*P1+
            (1.0-beta)*(    alpha)*P2+
            (    beta)*(1.0-alpha)*P3+
            (    beta)*(    alpha)*P4;
}
    

bool Pds::Matrix::Set(double val,unsigned int lin,unsigned int col)
{
    if(this->IsNotInRange(lin,col))   return false;
    
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
