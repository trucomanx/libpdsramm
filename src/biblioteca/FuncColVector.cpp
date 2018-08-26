/*
 * FuncColVector.cpp
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

#include <Pds/ColVector>
#include <Pds/FuncColVector>

Pds::ColVector Pds::LinSpace(double start,double end,unsigned int N)
{
    Pds::ColVector V(N);
    unsigned int id;
    double factor=(end-start)/(N-1.0);
    
    for(id=0;id<N;id++)
    V.Set(start+factor*id,id);

    return V;
}

Pds::ColVector Pds::GeomSpace(double start,double end,unsigned int N)
{
    if((start==0)||(start*end<0))
    {
        Pds::ColVector V;
        return V;
    }
    
    Pds::ColVector V(N);
    unsigned int id;
    double factor=pow(end/start,1.0/(N-1.0));
    
    for(id=0;id<N;id++)
    V.Set(start+factor*id,id);

    return V;
}


////////////////////////////////////////////////////////////////////////

Pds::ColVector Pds::X2D(void)
{
    Pds::ColVector A(2);
    A.Set(1.0,0,0);
    return A;
}

Pds::ColVector Pds::Y2D(void)
{
    Pds::ColVector A(2);
    A.Set(1.0,1);
    return A;
}

////////////////////////////////////////////////////////////////////////

Pds::ColVector Pds::X3D(void)
{
    Pds::ColVector A(3);
    A.Set(1.0,0);
    return A;
}

Pds::ColVector Pds::Y3D(void)
{
    Pds::ColVector A(3);
    A.Set(1.0,1);
    return A;
}

Pds::ColVector Pds::Z3D(void)
{
    Pds::ColVector A(3);
    A.Set(1.0,2);
    return A;
}
