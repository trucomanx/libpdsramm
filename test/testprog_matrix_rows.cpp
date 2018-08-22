/*
 * testprog_matrix_rows.cpp
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

/** \example testprog_matrix_rows.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones de reducción e inversión de matrices.
 *  
 */
    
    
#include <cmath>

#include <Pds/RealArrays>


    
int main(void)
{
    Pds::Matrix A(3,4);
    Pds::Matrix B;
    A.Set(1.0,0,0);A.Set(1.0,0,1); A.Set(1.0,0,2);     A.Set(24.0,0,3);
    A.Set(4.0,1,0);A.Set(6.0,1,1); A.Set(10.0,1,2);    A.Set(148.0,1,3);
    A.Set(0.5,2,0);A.Set(0.25,2,1);A.Set(1.0/3.0,2,2); A.Set(9.0,2,3);
    
    B=A;
    B.RowReduction();
    
    A.Print("\nA:\n");
    B.Print("\nB:\n");

    Pds::Matrix C(5,5);
    Pds::Matrix D;
    C.FillRandU();
    D=C.GetInv();

    (C*D).Print("\nC*D:\n");
    
    
    return 0;
}
