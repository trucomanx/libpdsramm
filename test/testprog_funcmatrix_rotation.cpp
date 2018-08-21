/*
 * testprog_funcmatrix_rotation.cpp
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

/** \example testprog_funcmatrix_rotation.cpp
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
    Pds::Matrix X2 = Pds::X2D();
    X2.Print("\nX2:\n");
    
    Pds::Matrix R2 = Pds::Rot2D(M_PI/4.0);
    (R2*X2).Print("\nR2(45grad)*X2\n");
    
    Pds::Matrix Z = Pds::Z3D();
    Z.Print("\nZ:\n");
    
    Pds::Matrix RX = Pds::RotX(M_PI/4.0);
    (RX*Z).Print("\nRX(45grad)*Z\n");
    
    Pds::Matrix RY = Pds::RotY(M_PI/4.0);
    (RY*Z).Print("\nRY(45grad)*Z\n");
    
    Pds::Matrix RZ = Pds::RotZ(M_PI/4.0);
    (RZ*Z).Print("\nRZ(45grad)*Z\n");
    
    return 0;
}
