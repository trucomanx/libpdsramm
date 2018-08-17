/*
 * testprog_matrix_static.cpp
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

/** \example testprog_matrix_static.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones de reducción e inversión de matrices.
 *  
 */
    
    
#include <iostream>
#include <PDS/RealArrays>


    
int main(int argc, char** argv)
{
    PDS::Matrix A(4,4);
    PDS::Matrix B(4,4);
    PDS::Matrix C;
    
    A.Fill(2.0);
    B.Fill(1.0);
    
    A+B;
    std::cout<<"Answer:\n"<<PDS::Matrix::Answer;
    
    A+B+B+A+A+B;
    
    std::cout<<"C:\n"<<C;
    std::cout<<"Answer:\n"<<PDS::Matrix::Answer;
    
    return 0;
}
