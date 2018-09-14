/** \example testprog_vector.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
    
#include <iostream>
#include <Pds/Ra>


    
int main(void)
{
    
    Pds::Vector A(3);
    Pds::Vector B(2);
    
    A.FillId();
    A=A+1;
    B.FillId();
    B=B+1;
    
    A.Print("A:\n");
    B.Print("B:\n");
    
    A.Conv(B).Print("A.Conv(B):\n");
    A.XCorr(B).Print("A.XCorr(B):\n");
    B.XCorr(A).Print("B.XCorr(A):\n");
    A.XCorr(B,true).Print("A.XCorr(B,true):\n");
    return 0;
}
