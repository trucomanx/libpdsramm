/*
 * testprog_colvector.cpp
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

/** \example testprog_colvector.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones de reducción e inversión de matrices.
 *  
 */
    
    
#include <iostream>
#include <Pds/RealArrays>


    
int main(void)
{
    Pds::ColVector A(3);
    Pds::ColVector B(3);
    Pds::ColVector C(3);
    
    C.FillRandU();       // Fill data randomly between [0.0, 1.0>.
    
    std::cout<<"C:\n"<<C;
    std::cout<<"B:\n"<<B;
    std::cout<<"A:\n"<<A;

    return 0;
}
