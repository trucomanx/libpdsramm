/*
 * MatrixFunc.cpp
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

#include <cmath>

#include <Pds/Matrix>
#include <Pds/MatrixFunc>

Pds::Matrix Pds::Diag(Pds::Matrix A)
{
    unsigned int id;
    
    if(A.IsEmpty())
    {
        Pds::Matrix B;
        return B;
    }
    
    unsigned int N=A.Nlin()*A.Ncol();
    Pds::Matrix B(N,N);
    
    for(id=0;id<N;id++)
    {
        B.Set(A.Get(id),id,id);
    }
    return B;
}


Pds::Matrix Pds::Eye(unsigned int N)
{
    unsigned int lin;
    
    Pds::Matrix A(N);
    
    if(A.IsEmpty())  return A;
    
    for(lin=0;lin<N;lin++)
    A.Set(1.0,lin,lin);
    
    return A;
}

Pds::Matrix Pds::Ones(unsigned int Nlin,unsigned int Ncol)
{
    Pds::Matrix A(Nlin,Ncol);
    
    if(A.IsEmpty())  return A;
    
    A.Fill(1.0);
    return A;
}

Pds::Matrix Pds::Ones(unsigned int N)
{
    Pds::Matrix A(N,N);
    
    if(A.IsEmpty())  return A;
    
    A.Fill(1.0);
    return A;
}


Pds::Matrix Pds::Zeros(unsigned int Nlin,unsigned int Ncol)
{
    Pds::Matrix A(Nlin,Ncol);
    
    return A;
}

Pds::Matrix Pds::Zeros(unsigned int N)
{
    Pds::Matrix A(N,N);
    
    return A;
}

