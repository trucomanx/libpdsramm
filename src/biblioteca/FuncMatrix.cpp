/*
 * FuncMatrix.cpp
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
#include <Pds/FuncMatrix>

Pds::Matrix Pds::Eye(unsigned int N)
{
    unsigned int lin;
    
    Pds::Matrix A(N);
    
    if(A.IsVoid())  return A;
    
    for(lin=0;lin<N;lin++)
    A.Set(1.0,lin,lin);
    
    return A;
}

Pds::Matrix Pds::Ones(unsigned int Nlin,unsigned int Ncol)
{
    Pds::Matrix A(Nlin,Ncol);
    
    if(A.IsVoid())  return A;
    
    A.Fill(1.0);
    return A;
}

Pds::Matrix Pds::Ones(unsigned int N)
{
    Pds::Matrix A(N,N);
    
    if(A.IsVoid())  return A;
    
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

////////////////////////////////////////////////////////////////////////

Pds::Matrix Pds::X2D(void)
{
    Pds::Matrix A(2,1);
    A.Set(1.0,0,0);
    return A;
}

Pds::Matrix Pds::Y2D(void)
{
    Pds::Matrix A(2,1);
    A.Set(1.0,1,0);
    return A;
}

////////////////////////////////////////////////////////////////////////

Pds::Matrix Pds::X3D(void)
{
    Pds::Matrix A(3,1);
    A.Set(1.0,0,0);
    return A;
}

Pds::Matrix Pds::Y3D(void)
{
    Pds::Matrix A(3,1);
    A.Set(1.0,1,0);
    return A;
}

Pds::Matrix Pds::Z3D(void)
{
    Pds::Matrix A(3,1);
    A.Set(1.0,2,0);
    return A;
}

////////////////////////////////////////////////////////////////////////

Pds::Matrix Pds::Rot2D(double RadAngle)
{
    Pds::Matrix A(2,2);
    A.Set(+cos(RadAngle),0,0); A.Set(-sin(RadAngle),0,1);
    A.Set(+sin(RadAngle),1,0); A.Set(+cos(RadAngle),1,1);
    return A;
}

Pds::Matrix Pds::RotX(double RadAngle)
{
    Pds::Matrix A(3,3);
    A.Set(1.0,0,0);A.Set(0.0           ,0,1); A.Set(0.0           ,0,2);
    A.Set(0.0,1,0);A.Set(+cos(RadAngle),1,1); A.Set(-sin(RadAngle),1,2);
    A.Set(0.0,2,0);A.Set(+sin(RadAngle),2,1); A.Set(+cos(RadAngle),2,2);
    return A;
}

Pds::Matrix Pds::RotY(double RadAngle)
{
    Pds::Matrix A(3,3);
    A.Set(+cos(RadAngle),0,0);A.Set(0.0,0,1); A.Set(+sin(RadAngle),0,2);
    A.Set(0.0           ,1,0);A.Set(1.0,1,1); A.Set(0.0           ,1,2);
    A.Set(-sin(RadAngle),2,0);A.Set(0.0,2,1); A.Set(+cos(RadAngle),2,2);
    return A;
}

Pds::Matrix Pds::RotZ(double RadAngle)
{
    Pds::Matrix A(3,3);
    A.Set(+cos(RadAngle),0,0);A.Set(-sin(RadAngle),0,1); A.Set(0.0,0,2);
    A.Set(+sin(RadAngle),1,0);A.Set(+cos(RadAngle),1,1); A.Set(0.0,1,2);
    A.Set(0.0           ,2,0);A.Set(0.0           ,2,1); A.Set(1.0,2,2);
    return A;
}
