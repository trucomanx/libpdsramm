/*
 * testprog_matrix.cpp
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

/** \example testprog_matrix.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones de reducción e inversión de matrices.
 *  
 */
    
    
#include <iostream>
#include <cmath>

#include <Pds/RealArrays>


    
int main(void)
{
    Pds::Matrix P =Pds::X3D();
    Pds::Matrix P0=Pds::Y3D();
    Pds::Matrix J =Pds::RotX(M_PI/2.0);
    
    
    P.Print("P:\n");
    P0.Print("P0:\n");
    J.Print("J:\n");
    
    Pds::Matrix F=P0 + J*(P-P0);

    F.Print("\nF:\n");
    
    return 0;
}
