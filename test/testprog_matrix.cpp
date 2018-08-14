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
 *  \n\n Este programa hace una prueba de la función para reducción de una matriz, 
 *  y de inversión de una matriz. Ambas funciones usan el método de gauss para 
 *  cumplir su objetivo.
 */
    
    
#include <iostream>
#include <PDS/RealArrays>


    
int main(int argc, char** argv)
{
    PDS::Matrix A(2,2);
    PDS::Matrix B(2,2);
    PDS::Matrix C(2,2);
    
    A.Init(1.0);        // Init data with a value
    
    B.InitRand();       // Init data randomly between [0.0, 1.0>.
    
    std::cout<<"A:\n"<<A;
    std::cout<<"B:\n"<<B;
    
    C+=A;
    C+=B;
    
    std::cout<<"C:\n"<<C;
    return 0;
}
