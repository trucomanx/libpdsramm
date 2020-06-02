/** \file test_vector_statistics.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-09-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
    
#include <Pds/Ra>
#include <cmath>
    
int main(void)
{
    
    Pds::Vector A(2);
    Pds::Vector B(3);
    
    A.Fill(1.0);
    B.Fill(1.0);
    
    A.T().Print("A.T():\n");
    B.T().Print("B.T():\n");

    
    A.Conv(B).T().Print("A.Conv(B).T():\n");
    A.XCorr(B).T().Print("A.XCorr(B).T():\n");
    B.XCorr(A).T().Print("B.XCorr(A).T():\n");
    A.XCorr(B,true).T().Print("A.XCorr(B,true).T():\n");
    return 0;
}
