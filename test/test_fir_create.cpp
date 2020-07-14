/** \file test_fir_create.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <iomanip>
#include <Pds/Ra>
    
int main(void)
{
    double result;
    unsigned int N=10000000;
    
    Pds::Fir FIR(Pds::Vector(100,1)/100.0);

    double Tmax=10;
    double fs=1.0;
    Pds::Vector T=Pds::LinSpace(0,Tmax,N);
    Pds::Vector V=Pds::Sin((2*Pds::Ra::Pi*fs)*T);

    Pds::Ra::Tic();
    for(unsigned int i=0;i<N;i++)
    result=FIR.Evaluate(V.Get(i));
    Pds::Ra::Toc();
    
    std::cout<<"Final:"<<result<<"\n";

    Pds::Vector X(5,1);
    X.Print("X\n");
}
