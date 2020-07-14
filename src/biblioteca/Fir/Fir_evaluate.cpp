/*
 * Fir_evaluate.cpp
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


#include <Pds/Fir>
#include <iostream>


double Pds::Fir::Evaluate(double x)
{
    unsigned int i;
    double S=0;

    for(i=0;i<this->M;i++)  this->X[M-i]=this->X[M-1-i];    
    this->X[0]=x;
    
    for(i=0;i<=this->M;i++)  S+=this->X[i]*this->H[i];
    
    return S;
}


Pds::Vector Pds::Fir::Evaluate(const Pds::Vector &V)
{
    unsigned int i,j;
    double S=0;

    if(V.IsEmpty()) return Pds::Vector();

    Pds::Vector Y(V.Nel());

	unsigned int N=this->M;
    unsigned int Lv=V.Nel();

	// Evaluó salida y tramo1.
	for(j=0;(j<N)&&(j<Lv);j++)
	{
		S=0;
		for(i=0;i<=j;i++)
		{
			S=S+this->H[i]*V[j-i];
		}
		for(i=j+1;i<N;i++)
		{
			S=S+this->H[i]*this->X[i-(j+1)];
		}	
		Y.Set(j,S);
	}
	// Evaluó salida y tramo2.
	for(j=N;j<Lv;j++)
	{
		S=0;
		for(i=0;i<N;i++)
		{
			S=S+this->H[i]*V[j-i];
		}
		Y.Set(j,S);
	}


	// Ordenamiento final.
	if(N>Lv)	M=N-Lv;
	else		M=0;

	for(j=0;j<M;j++)
	{
		this->X[N-1-j]=this->X[M-1-j];
	}
	for(j=0;(j<Lv)&&(j<N);j++)
	{
		this->X[j]=V[Lv-1-j];
	}
    
    return Y;
}

