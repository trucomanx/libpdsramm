/*
 * testprog_matrix_static_matrix.cpp
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

/** \example testprog_matrix_static_matrix.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
        
#include <Pds/RealArrays>
        
int main(int argc, char** argv)
{
    char filepath[]="filedat.txt";

    Pds::Matrix A=Pds::Eye(5); 

    bool state=Pds::Matrix::Save(filepath,A);
    if(state==true) A.Print("A:\n");

    Pds::Matrix B=Pds::Matrix::Load(filepath);
    B.Print("B:\n");
    
    Pds::Matrix C("filedat.txt");
    C.Print("C:\n");

    return 0;
}
