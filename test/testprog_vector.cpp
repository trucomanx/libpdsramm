/** \example testprog_vector.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
    
#include <Pds/Ra>
#include <cmath>
    
int main(void)
{
    Pds::Matrix M(2,2,1.5);
    
    Pds::Vector A(2);
    Pds::Vector B(3);
    Pds::Vector C(M);
    Pds::Vector D(M,1);
    Pds::Vector E("1 2 3\n4 5 6");
    Pds::Vector F(M.Size());
    Pds::Vector G(cos,B);
    Pds::Vector H(cos,M);
    Pds::Vector I(3,-1.2);
    
    A.Fill(1.0);
    B.Fill(1.0);
    
    A.T().Print("A.T():\n");
    B.T().Print("B.T():\n");
    C.T().Print("C.T():\n");
    D.T().Print("D.T():\n");
    E.T().Print("E.T():\n");
    F.T().Print("F.T():\n");
    G.T().Print("G.T():\n");
    H.T().Print("H.T():\n");
    I.T().Print("I.T():\n");
    
    
    A.Conv(B).T().Print("A.Conv(B).T():\n");
    A.XCorr(B).T().Print("A.XCorr(B).T():\n");
    B.XCorr(A).T().Print("B.XCorr(A).T():\n");
    A.XCorr(B,true).T().Print("A.XCorr(B,true).T():\n");
    return 0;
}
