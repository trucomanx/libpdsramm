/*
 * testprog_funcmatrix.cpp
 * 
 * Copyright 2011 Fernando Pujaico Rivera <fernando.pujaico.rivera@gmail.com>
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

/** \example testprog_funcmatrix.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones de reducción e inversión de matrices.
 *  
 */
    
    
#include <iostream>

#include <Pds/RealArrays>


    
int main(void)
{
    Pds::Matrix A = Pds::Eye(3);
    Pds::Matrix B = Pds::Ones(3);
    Pds::Matrix C = Pds::Zeros(3);
    
    A.Print("\nA:\n");
    B.Print("\nB:\n");
    C.Print("\nC:\n");
    
    Pds::Matrix X2 = Pds::X2D();
    Pds::Matrix Y2 = Pds::Y2D();
    
    X2.Print("\nX2:\n");
    Y2.Print("\nY2:\n");
    
    Pds::Matrix X = Pds::X3D();
    Pds::Matrix Y = Pds::Y3D();
    Pds::Matrix Z = Pds::Z3D();
    
    X.Print("\nX:\n");
    Y.Print("\nY:\n");
    Z.Print("\nZ:\n");
    
    return 0;
}
