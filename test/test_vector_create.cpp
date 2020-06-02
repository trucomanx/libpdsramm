/** \file test_vector_create.cpp
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
    Pds::Ra::SaveString("filedat.txt","1 2 3\n4 5 6\n");
    Pds::Vector J(Pds::Ra::TextFormat,"filedat.txt");
    
    
    A.T().Print("A.T():\n");
    B.T().Print("B.T():\n");
    C.T().Print("C.T():\n");
    D.T().Print("D.T():\n");
    E.T().Print("E.T():\n");
    F.T().Print("F.T():\n");
    G.T().Print("G.T():\n");
    H.T().Print("H.T():\n");
    I.T().Print("I.T():\n");
    J.T().Print("J.T():\n");
    
    return 0;
}
