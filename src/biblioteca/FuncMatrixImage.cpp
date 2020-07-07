/*
 * FuncMatrixImage.cpp
 * 
 * Copyright 2018 Fernando Pujaico Rivera <fernando.pujaico.rivera@gmail.com>
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

#include <cmath>

#include <Pds/Matrix>
#include <Pds/FuncMatrixImage>

////////////////////////////////////////////////////////////////////////
std::vector<Pds::Matrix> Pds::Image::ChromaticityCoordinates(const std::vector<Pds::Matrix> &Block,double factor)
{
    //verifico las entradas
    std::vector<Pds::Matrix> tmp(0);
    if(Block.size()==0) return tmp;
    for(unsigned int i=1;i<Block.size();i++)
    if(Block[0].IsNotSimilarTo(Block[i])) return tmp;

    // Calculando suma
    Pds::Matrix Sum(Block[0].Size());
    for(unsigned int i=0;i<Block.size();i++)
    Sum.AddAssig(Block[i]);    

    factor=fabs(factor);

    std::vector<Pds::Matrix> CC(Block.size());
    for(unsigned int i=0;i<Block.size();i++)
    if(factor==1.0) CC[i]=Block[i].Div(Sum); 
    else            CC[i]=factor*Block[i].Div(Sum); 
    return CC;
}


////////////////////////////////////////////////////////////////////////
std::vector<Pds::Matrix> Pds::Image::WhitePatch(const std::vector<Pds::Matrix> &Block)
{
    //verifico las entradas
    std::vector<Pds::Matrix> tmp(0);
    if(Block.size()==0) return tmp;
    for(unsigned int i=1;i<Block.size();i++)
    if(Block[0].IsNotSimilarTo(Block[i])) return tmp;
    
    // Calculando maximos
    std::vector<double> Max(Block.size());
    for(unsigned int i=0;i<Block.size();i++)
    Max[i]=Block[i].Max();    

    //WhitePatch
    std::vector<Pds::Matrix> WPI(Block.size());
    for(unsigned int i=0;i<Block.size();i++)
    WPI[i]=Block[i].Mul(255.0/Max[i]);
     
    return WPI;
}

