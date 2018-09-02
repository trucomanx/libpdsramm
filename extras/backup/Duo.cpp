/*
 * Duo.cpp
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


#include <Pds/Duo>



// Instantiate Pds::Duo for the supported template type parameters
template class Pds::Duo<float>;
template class Pds::Duo<double>;
template class Pds::Duo<char>;
template class Pds::Duo<int >;
template class Pds::Duo<long>;

template <class Datum>
Pds::Duo<Datum>::Duo(void)
{
    this->dat0=0;
    this->dat1=0;
}

template <class Datum>
Pds::Duo<Datum>::Duo(Datum D0,Datum D1)
{
    this->dat0=D0;
    this->dat1=D1;
}

template <class Datum>
Pds::Duo<Datum>::~Duo(void)
{
    this->dat0=0;
    this->dat1=0;
}

////////////////////////////////////////////////////////////////////////
#include <Pds/RealArraysDefines>
#include <iostream>
#include <iomanip>      // std::setprecision

template <class Datum>
void Pds::Duo<Datum>::Print(std::string str) const
{
    std::cout<<str;
    
    std::cout<<std::setprecision(Pds::Ra::StringPrecision);
    
    std::cout<<this->dat0<<"\t"<<this->dat1<<"\n";
    
}

template <class Datum>
void Pds::Duo<Datum>::Print(const char *str) const
{
    std::cout<<str;
    
    std::cout<<std::setprecision(Pds::Ra::StringPrecision);
    
    std::cout<<this->dat0<<"\t"<<this->dat1<<"\n";
    
}

template <class Datum>
void Pds::Duo<Datum>::Print(void) const
{
    std::cout<<std::setprecision(Pds::Ra::StringPrecision);
    
    std::cout<<this->dat0<<"\t"<<this->dat1<<"\n";
    
}

////////////////////////////////////////////////////////////////////////

template <class Datum>
Datum Pds::Duo<Datum>::Dot(void) const
{
    return this->dat0*this->dat0+this->dat1*this->dat1;
}

template <class Datum>
Datum Pds::Duo<Datum>::Dot(const Pds::Duo<Datum> B) const
{
    return this->dat0*B.dat0+this->dat1*B.dat1;
}
////////////////////////////////////////////////////////////////////////

template <class Datum>
Pds::Duo<Datum> Pds::Duo<Datum>::Add(Datum beta) const
{
    return Pds::Duo<Datum>(this->dat0+beta,this->dat1+beta);
}

template <class Datum>
Pds::Duo<Datum> Pds::Duo<Datum>::operator+(Datum beta) const
{
    return Pds::Duo<Datum>(this->dat0+beta,this->dat1+beta);
}

template <class Datum>
Pds::Duo<Datum> Pds::Duo<Datum>::Add(const Pds::Duo<Datum> B) const
{
    return Pds::Duo<Datum>(this->dat0+B.dat0,this->dat1+B.dat1);
}

template <class Datum>
Pds::Duo<Datum> Pds::Duo<Datum>::operator+(const Pds::Duo<Datum> B) const
{
    return Pds::Duo<Datum>(this->dat0+B.dat0,this->dat1+B.dat1);
}

////////////////////////////////////////////////////////////////////////

template <class Datum>
Pds::Duo<Datum> Pds::Duo<Datum>::Mul(Datum beta) const
{
    return Pds::Duo<Datum>(this->dat0*beta,this->dat1*beta);
}

template <class Datum>
Pds::Duo<Datum> Pds::Duo<Datum>::operator*(Datum beta) const
{
    return Pds::Duo<Datum>(this->dat0*beta,this->dat1*beta);
}

template <class Datum>
Pds::Duo<Datum> Pds::Duo<Datum>::operator*(Pds::Duo<Datum> B) const
{
    return Pds::Duo<Datum>(this->dat0*B.dat0-this->dat1*B.dat1,this->dat0*B.dat1+this->dat1*B.dat0);
}


////////////////////////////////////////////////////////////////////////
// Instantiate Pds::Duo functions for the supported template type parameters
template std::ostream& operator<<<float>(std::ostream &out,const Pds::Duo<float> &B);
template std::ostream& operator<<<double>(std::ostream &out,const Pds::Duo<double> &B);
template std::ostream& operator<<<char>(std::ostream &out,const Pds::Duo<char> &B);
template std::ostream& operator<<<int >(std::ostream &out,const Pds::Duo<int > &B);
template std::ostream& operator<<<long>(std::ostream &out,const Pds::Duo<long> &B);

template <class Datum>
std::ostream& operator<<(std::ostream &out,const Pds::Duo<Datum> &B)
{
    out<<B.dat0<<"\t"<<B.dat1<<"\n";
    return out;
}

////////////////////////////////////////////////////////////////////////
// Instantiate Pds::Duo functions for the supported template type parameters
template Pds::Duo<float > operator+<float >(float  alpha,const Pds::Duo<float > &B);
template Pds::Duo<double> operator+<double>(double alpha,const Pds::Duo<double> &B);
template Pds::Duo<char> operator+<char>(char alpha,const Pds::Duo<char> &B);
template Pds::Duo<int > operator+<int >(int  alpha,const Pds::Duo<int > &B);
template Pds::Duo<long> operator+<long>(long alpha,const Pds::Duo<long> &B);

template <class Datum>
Pds::Duo<Datum> operator+(Datum alpha,const Pds::Duo<Datum> &B)
{
    return Pds::Duo<Datum>(alpha+(B.dat0),alpha+(B.dat1));
}

template Pds::Duo<float > operator+<float >(int  alpha,const Pds::Duo<float > &B);
template Pds::Duo<double> operator+<double>(int alpha,const Pds::Duo<double> &B);
template Pds::Duo<char> operator+<char>(int alpha,const Pds::Duo<char> &B);
template Pds::Duo<long> operator+<long>(int alpha,const Pds::Duo<long> &B);

template <class Datum,class T>
Pds::Duo<Datum> operator+(T alpha,const Pds::Duo<Datum> &B)
{
    return Pds::Duo<Datum>(alpha+(B.dat0),alpha+(B.dat1));
}
////////////////////////////////////////////////////////////////////////
// Instantiate Pds::Duo functions for the supported template type parameters
template Pds::Duo<float > operator*<float >(float  alpha,const Pds::Duo<float > &B);
template Pds::Duo<double> operator*<double>(double alpha,const Pds::Duo<double> &B);
template Pds::Duo<char> operator*<char>(char alpha,const Pds::Duo<char> &B);
template Pds::Duo<int > operator*<int >(int  alpha,const Pds::Duo<int > &B);
template Pds::Duo<long> operator*<long>(long alpha,const Pds::Duo<long> &B);

template <class Datum>
Pds::Duo<Datum> operator*(Datum alpha,const Pds::Duo<Datum> &B)
{
    return Pds::Duo<Datum>(alpha*(B.dat0),alpha*(B.dat1));
}

template Pds::Duo<float > operator*<float >(int alpha,const Pds::Duo<float > &B);
template Pds::Duo<double> operator*<double>(int alpha,const Pds::Duo<double> &B);
template Pds::Duo<char> operator*<char>(int alpha,const Pds::Duo<char> &B);
template Pds::Duo<long> operator*<long>(int alpha,const Pds::Duo<long> &B);

template <class Datum,class T>
Pds::Duo<Datum> operator*(T alpha,const Pds::Duo<Datum> &B)
{
    return Pds::Duo<Datum>(alpha*(B.dat0),alpha*(B.dat1));
}

