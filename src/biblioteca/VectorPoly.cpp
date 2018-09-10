/*
 * VectorPoly.cpp
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
#include <Pds/Vector>
#include <Pds/VectorPoly>
#include <iostream>


Pds::Matrix Pds::PolyMat(Pds::Vector X, unsigned int ORDER)
{
    unsigned int col;

    Pds::Matrix P(X.Nlin(),ORDER+1);
    if(P.IsEmpty()) return P;
    
    for(col=0;col<=ORDER;col++)
    {
        P.SetColVector(pow,X,col,col);
    }
    
    return P;
}

Pds::Vector Pds::PolyFit(Pds::Vector X, Pds::Vector Y, unsigned int ORDER)
{
    unsigned int col;

    if(X.Nlin()!=Y.Nlin())  return Pds::Matrix();
    
    Pds::Matrix B(X.Nlin(),ORDER+1);
    if(B.IsEmpty())         return B;
    
    for(col=0;col<=ORDER;col++)
    {
        B.SetColVector(pow,X,col,col);
    }
    
    double rcond=0;
    
    Pds::Matrix mat=(B.TnoT()).Inv(&rcond);
    
    
    if(rcond<Pds::Ra::WarningRCond)
    return Pds::Matrix();
    
    return mat.MulT(B)*Y;
}

Pds::Vector Pds::PolyVal(Pds::Vector P,Pds::Vector X)
{
    Pds::Vector B;
    B=Pds::PolyMat(X,P.Nlin()-1)*P;
    return B;
}
