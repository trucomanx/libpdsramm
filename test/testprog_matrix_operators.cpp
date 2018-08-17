/*
 * testprog_matrix_operators.cpp
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

/** \example testprog_matrix_operators.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones de reducción e inversión de matrices.
 *  
 */
    
    
#include <iostream>
#include <PDS/RealArrays>


    
int main(int argc, char** argv)
{
    PDS::Matrix A(2,2);
    PDS::Matrix B(2,2);
    PDS::Matrix C;
    
    A.Fill(1.0);    std::cout<<"A:\n"<<A;
    B.Fill(2.0);    std::cout<<"B:\n"<<B;
    
    // = operator
    std::cout<<std::endl;
    
    C= PDS::Matrix(2,2);    // A Matrix object was created, the data were copied
                            // and later the Matrix object was destroyed.
    
    if((C=A).IsNotVoid())   C.Print("C=A\n");
    if(C.Copy(B))           C.Print("C=B\n");
    
    // += operator
    std::cout<<std::endl;
    
    if((C+=A).IsNotVoid())  C.Print("C+=A\n");
    if(C.Accumulate(B))     C.Print("C+=B\n");
    
    // + operator
    std::cout<<std::endl;
    
    A.Add(B);
    
    PDS::Matrix::Answer.Print("A+B\n");
    
    // * operator
    std::cout<<std::endl;
    
    A.Mul(B);
    
    PDS::Matrix::Answer.Print("A*B\n");
    
    return 0;
}
