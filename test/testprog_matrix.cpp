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
    
    
#include <cmath>

#include <Pds/RealArrays>


    
int main(void)
{
    Pds::Matrix A;
    Pds::Matrix B(1);
    Pds::Matrix C(2,2);
    Pds::Matrix D(3,2,0.523598776);
    Pds::Matrix E(D);
    Pds::Matrix F(D,sin);
    
    F.Save("filedat.txt");
    Pds::Matrix G("filedat.txt");
    
    
    A.Print("\nA:\n");
    B.Print("\nB:\n");
    C.Print("\nC:\n");
    D.Print("\nD:\n");
    E.Print("\nE:\n");
    F.Print("\nF:\n");
    G.Print("\nG:\n");
    
    
    
    return 0;
}
