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

Pds::Matrix Pds::Sin(const Pds::Matrix &A)
{
    Pds::Matrix B(sin,A);
    return B;
}

Pds::Matrix Pds::Cos(const Pds::Matrix &A)
{
    Pds::Matrix B(cos,A);
    return B;
}

Pds::Matrix Pds::Tan(const Pds::Matrix &A)
{
    Pds::Matrix B(tan,A);
    return B;
}

////////////////////////////////////////////////////////////////////////

Pds::Matrix Pds::Exp(const Pds::Matrix &A)
{
    Pds::Matrix B(exp,A);
    return B;
}


Pds::Matrix Pds::TwoExp(const Pds::Matrix &A)
{
    Pds::Matrix B(exp2,A);
    return B;
}

Pds::Matrix Pds::Log(const Pds::Matrix &A)
{
    Pds::Matrix B(log,A);
    return B;
}

Pds::Matrix Pds::Ln(const Pds::Matrix &A)
{
    Pds::Matrix B(log,A);
    return B;
}

Pds::Matrix Pds::Log2(const Pds::Matrix &A)
{
    Pds::Matrix B(log2,A);
    return B;
}

Pds::Matrix Pds::Log10(const Pds::Matrix &A)
{
    Pds::Matrix B(log10,A);
    return B;
}

////////////////////////////////////////////////////////////////////////

Pds::Matrix Pds::Sqrt(const Pds::Matrix &A)
{
    Pds::Matrix B(sqrt,A);
    return B;
}

////////////////////////////////////////////////////////////////////////

Pds::Matrix Pds::Pow(const Pds::Matrix &A,double var)
{
    Pds::Matrix B(pow,A,var);
    return B;
}

////////////////////////////////////////////////////////////////////////
// Finciones de activacion
////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
double Pds::SQNL(double x)
{   
    if (x>2.0)      return 1.0;
    else if(x>0.0)  return x-x*x/4;
    else if(x>-2.0) return x+x*x/4;
    else            return -1.0;
}

Pds::Matrix Pds::SQNL(const Pds::Matrix &A)
{
    Pds::Matrix B(Pds::SQNL,A);
    return B;
}

////////////////////////////////////////////////////////////////////////
double Pds::Gaussian(double x)
{   
    return exp(-x*x);
}

Pds::Matrix Pds::Gaussian(const Pds::Matrix &A)
{
    Pds::Matrix B(Pds::Gaussian,A);
    return B;
}


////////////////////////////////////////////////////////////////////////
Pds::Matrix Pds::Tanh(const Pds::Matrix &A)
{
    Pds::Matrix B(tanh,A);
    return B;
}

////////////////////////////////////////////////////////////////////////
double Pds::Sigmoid(double x)
{   
    return 1/(1+exp(-x));
}

Pds::Matrix Pds::Sigmoid(const Pds::Matrix &A)
{
    Pds::Matrix B(Pds::Sigmoid,A);
    return B;
}


////////////////////////////////////////////////////////////////////////
// Otros
////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
double Pds::Logit(double x)
{   
    return log(x/(1.0-x));
}

Pds::Matrix Pds::Logit(const Pds::Matrix &A)
{
    Pds::Matrix B(Pds::Logit,A);
    return B;
}

////////////////////////////////////////////////////////////////////////
double Pds::Sinc(double x)
{   
    if (x==0)   return 1;
    else        return sin(x)/x;
}

Pds::Matrix Pds::Sinc(const Pds::Matrix &A)
{
    Pds::Matrix B(Pds::Sinc,A);
    return B;
}

////////////////////////////////////////////////////////////////////////
double Pds::Hb(double x)
{   
    return -x*log2(x)-(1.0-x)*log2(1.0-x);
}

Pds::Matrix Pds::Hb(const Pds::Matrix &A)
{
    Pds::Matrix B(Pds::Hb,A);
    return B;
}

////////////////////////////////////////////////////////////////////////
// Integration
////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
double Pds::SimpsonIntegration(double (*f)(double), double a,double b,unsigned int n)
{
	double S0,Si,Sp,h;
	unsigned int i;

	if(b<a)		return 0.0;
	if(n<=0)	return 0.0;
	if(n%2!=0)	n=n+1;
	h=(b-a)/n;

	S0=(*f)(a)+(*f)(b);
    
	for(i=1,Si=0;i<n;i=i+2)
	{
		Si=Si+(*f)(a+h*i);
	}
	
	for(i=2,Sp=0;i<n;i=i+2)
	{
		Sp=Sp+(*f)(a+h*i);
	}

	return (S0+4.0*Si+2.0*Sp)*h/3.0;
}

////////////////////////////////////////////////////////////////////////
double Pds::SimpsonIntegration(double (*f)(double,double),double r, double a,double b,unsigned int n)
{
	double S0,Si,Sp,h;
	unsigned int i;

	if(b<a)		return 0.0;
	if(n<=0)	return 0.0;
	if(n%2!=0)	n=n+1;
	h=(b-a)/n;

	S0=(*f)(a,r)+(*f)(a+h*n,r);
	
	for(i=1,Si=0;i<n;i=i+2)
	{
		Si=Si+(*f)(a+h*i,r);
	}
	
	for(i=2,Sp=0;i<n;i=i+2)
	{
		Sp=Sp+(*f)(a+h*i,r);
	}

	return (S0+4.0*Si+2.0*Sp)*h/3.0;
}

////////////////////////////////////////////////////////////////////////
double Pds::ImproperIntegration(double (*f)(double), double a,unsigned int n)
{
	double S0,Si,Sp,h;
	unsigned int i;

    double x0,Sm;
	if(n<=0)	return 0.0;
	if(n%2!=0)	n=n+1;

	if(a>=0.0)
    {	
        Sm=0.0;
        x0=a;
    }
    else
    {
        Sm=Pds::SimpsonIntegration(f,a,0,n);
        x0=0;
    }

	h=1.0/((x0+1.0)*n);

	S0=0.0+(*f)(x0)*(x0+1.0)*(x0+1.0);

	for(i=1,Si=0;i<n;i=i+2)
	{
		Si=Si+(*f)((1.0/(h*i))-1.0)/((h*i)*(h*i));
	}
	
	for(i=2,Sp=0;i<n;i=i+2)
	{
		Sp=Sp+(*f)((1.0/(h*i))-1.0)/((h*i)*(h*i));
	}
	return Sm+(S0+4.0*Si+2.0*Sp)*h/3.0;
}


double Pds::ImproperIntegration(double (*f)(double,double),double r, double a,unsigned int n)
{
	double S0,Si,Sp,h;
	unsigned int i;

    double x0,Sm;
	if(n<=0)	return 0.0;
	if(n%2!=0)	n=n+1;

	if(a>=0.0)
    {	
        Sm=0.0;
        x0=a;
    }
    else
    {
        Sm=Pds::SimpsonIntegration(f,r,a,0,n);
        x0=0;
    }

	h=1.0/((x0+1.0)*n);

	S0=0.0+(*f)(x0,r)*(x0+1.0)*(x0+1.0);

	for(i=1,Si=0;i<n;i=i+2)
	{
		Si=Si+(*f)((1.0/(h*i))-1.0,r)/((h*i)*(h*i));
	}
	
	for(i=2,Sp=0;i<n;i=i+2)
	{
		Sp=Sp+(*f)((1.0/(h*i))-1.0,r)/((h*i)*(h*i));
	}
	return Sm+(S0+4.0*Si+2.0*Sp)*h/3.0;
}
