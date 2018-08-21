/*
 * testprog_mathmatrix.cpp
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

/** \example testprog_mathmatrix.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
    
#include <cmath>

#include <Pds/RealArrays>


    
int main(void)
{
    Pds::Matrix A(2);
    
    A.Fill(M_PI*45.0/180.0);
    
    A.Print("\nA:\n");
    
    Pds::Sin(A).Print("sin(A):\n");
    Pds::Cos(A).Print("cos(A):\n");
    Pds::Tan(A).Print("tan(A):\n");
    
    A.Fill(1.0);
    A.Print("\nA:\n");
    
    Pds::Exp(A).Print("exp(A):\n");
    Pds::Exp2(A).Print("exp2(A):\n");
    Pds::Log(A).Print("log(A):\n");
    Pds::Log2(A).Print("log2A):\n");
    Pds::Log10(A).Print("log10(A):\n");
    
    A.Fill(2.0);
    A.Print("\nA:\n");
    
    Pds::Sqrt(A).Print("sqrt(A):\n");
    return 0;
}
