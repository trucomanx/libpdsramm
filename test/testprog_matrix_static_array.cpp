/*
 * testprog_matrix_static_array.cpp
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

/** \example testprog_matrix_static_array.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
    
#include <iostream>
#include <Pds/RealArrays>
#include <cmath>


    
int main(void)
{
    std::string str;
    Pds::Matrix A=Pds::Eye(3);
    
    unsigned int Nlin=2;
    unsigned int Ncol=2;
    double **array=NULL;
    
    char filepath[]="filedat.txt";
    
    array=Pds::Matrix::AllocateArray(Nlin,Ncol);
    if(array==NULL)   return 0; 
    
    array[0][0]=0.0/0.0;
    array[0][1]=0.0/1.0;
    array[1][0]=1.0/0.0;
    array[1][1]=1.0/1.0;
    
    str=Pds::Matrix::ArrayToString(array,Nlin,Ncol);
    std::cout<<str;
    
    Pds::Matrix::SaveArray(filepath,array,Nlin,Ncol);

    Pds::Matrix::ReleaseArray(array,Nlin);
    std::cout<<std::endl<<"array="<<array<<std::endl<<std::endl;
    
    
    array=Pds::Matrix::AllocateArray(A);
    if(array==NULL)   return 0;
    
    str=Pds::Matrix::ArrayToString(array,A.Nlin(),A.Ncol());
    std::cout<<str;
    
    Pds::Matrix::ReleaseArray(array,A.Nlin());
    std::cout<<std::endl<<"array="<<array<<std::endl<<std::endl;
    
    
    array=Pds::Matrix::AllocateArray(A,sin);
    if(array==NULL)   return 0;
    
    str=Pds::Matrix::ArrayToString(array,A.Nlin(),A.Ncol());
    std::cout<<str;
    
    Pds::Matrix::ReleaseArray(array,A.Nlin());
    std::cout<<std::endl<<"array="<<array<<std::endl<<std::endl;
    
    
    Pds::Matrix::LoadArray(filepath,array,Nlin,Ncol);
    str=Pds::Matrix::ArrayToString(array,Nlin,Ncol);
    std::cout<<str;

    return 0;
}
