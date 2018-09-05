/*
 * MatrixMath.cpp
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


#include <Pds/MatrixMath>
#include <cmath>

Pds::Matrix Pds::Sin(const Pds::Matrix A)
{
    Pds::Matrix B(sin,A);
    return B;
}

Pds::Matrix Pds::Cos(const Pds::Matrix A)
{
    Pds::Matrix B(cos,A);
    return B;
}

Pds::Matrix Pds::Tan(const Pds::Matrix A)
{
    Pds::Matrix B(tan,A);
    return B;
}

////////////////////////////////////////////////////////////////////////

Pds::Matrix Pds::Exp(const Pds::Matrix A)
{
    Pds::Matrix B(exp,A);
    return B;
}


Pds::Matrix Pds::Exp2(const Pds::Matrix A)
{
    Pds::Matrix B(exp2,A);
    return B;
}

Pds::Matrix Pds::Log(const Pds::Matrix A)
{
    Pds::Matrix B(log,A);
    return B;
}

Pds::Matrix Pds::Log2(const Pds::Matrix A)
{
    Pds::Matrix B(log2,A);
    return B;
}

Pds::Matrix Pds::Log10(const Pds::Matrix A)
{
    Pds::Matrix B(log10,A);
    return B;
}

////////////////////////////////////////////////////////////////////////

Pds::Matrix Pds::Sqrt(const Pds::Matrix A)
{
    Pds::Matrix B(sqrt,A);
    return B;
}

