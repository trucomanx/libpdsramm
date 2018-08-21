/*
 * testprog_matrix_state.cpp
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

/** \example testprog_matrix_state.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones de reducción e inversión de matrices.
 *  
 *  \n\n Este programa hace una prueba de la función para reducción de una matriz, 
 *  y de inversión de una matriz. Ambas funciones usan el método de gauss para 
 *  cumplir su objetivo.
 */
    
    
#include <iostream>
#include <Pds/RealArrays>
    
int main(void)
{
    Pds::Matrix A;
    Pds::Matrix B(3,3);
    Pds::Matrix C(3,3);

    B.Set(+1.0/0.0,0,0);
    B.Set( 0.0/0.0,1,1);
    B.Set(-1.0/0.0,2,2);

    B.Print("B:\n");
    
    
    pds_print_info_message("... is void?");
    
    if(A.IsVoid())      std::cout<<"A is NULL"<<std::endl;
    else                std::cout<<"A is not NULL"<<std::endl;
    
    if(B.IsNotVoid())   std::cout<<"B is not NULL"<<std::endl;
    else                std::cout<<"B is NULL"<<std::endl;
    
    if(C.IsNotVoid())   std::cout<<"C is not NULL"<<std::endl;
    else                std::cout<<"C is NULL"<<std::endl;
    
    
    pds_print_info_message("... is similar to ... ?");
    
    if(A.IsNotSimilarTo(B)) std::cout<<"A is not similar to B"<<std::endl;
    else                    std::cout<<"A is similar to B"<<std::endl;

    if(B.IsSimilarTo(C))    std::cout<<"B is similar to C"<<std::endl;
    else                    std::cout<<"B is not similar to C"<<std::endl;
    
    
    pds_print_info_message("... is multipliable to ... ?");
    
    if(A.IsNotMulBy(C))     std::cout<<"A is not multipliable by C"<<std::endl;
    else                    std::cout<<"A is multipliable by C"<<std::endl;
    
    if(B.IsMulBy(C))        std::cout<<"B is multipliable by C"<<std::endl;
    else                    std::cout<<"B is not multipliable by C"<<std::endl;  
    
    
    pds_print_info_message("... has the position ... ?");
    
    if(B.HasThePosition(1,1))   std::cout<<"B has the position (1,1)"<<std::endl;
    else                        std::cout<<"B dont have the position (1,1)"<<std::endl;
    
    
    pds_print_info_message("... is in size range ... ?");
    
    if(B.IsInSizeRange(1.5,0.1))    std::cout<<"(1.5,0.1) is in size range of B"<<std::endl;
    else                            std::cout<<"(1.5,0.1) is not in size range of B"<<std::endl;
    
    B.IsInf().Print("\nB.IsInf()\n");
    
    B.IsNan().Print("\nB.IsNan()\n");
    
    B.IsFinite().Print("\nB.IsFinite()\n");
    return 0;
}
