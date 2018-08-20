/*
 * testprog_ratools.cpp
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

/** \example testprog_ratools.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
    
#include <iostream>
#include <Pds/RealArrays>
    
int main(int argc, char** argv)
{
    char filepath[]="filedat.txt";
    char str1[]=" \t \t \n";
    char str2[]=" Hola como\testas \n";
    long N;
    
    if(Pds::Ra::IsSpace(str1))  std::cout<<"str1 is a space line\n";
    else                        std::cout<<"str1 is not a space line\n";
    
    if(Pds::Ra::IsSpace(str2))  std::cout<<"str2 is a space line\n";
    else                        std::cout<<"str2 is not a space line\n";
    
    N=Pds::Ra::NumberOfElements(str1);
    std::cout<<"str1 has "<<N<<" elements\n";
    
    N=Pds::Ra::NumberOfElements(str2);
    std::cout<<"str2 has "<<N<<" elements\n";


    N=Pds::Ra::SignificativeLinesInFile(filepath);
    std::cout<<"Number of significative lines in "<<filepath<<" is "<<N<<std::endl;

    unsigned int Nlin=0,Ncol=0,Nel=0;
    bool status;

    status=Pds::Ra::ArraySizeInFile(filepath,Nlin,Ncol);
    if(status==true)
    std::cout<<"Nlin:"<<Nlin<<"\nNcol"<<Ncol<<std::endl;

    status=Pds::Ra::ElementsInFile(filepath,Nel);
    if(status==true)
    std::cout<<"Nel:"<<Nel<<std::endl;

    
    return 0;
}
