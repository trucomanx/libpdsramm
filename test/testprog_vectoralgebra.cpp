/** \example testprog_vectoralgebra.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
    
#include <iostream>
#include <Pds/Ra>


    
int main(void)
{
    
    Pds::Vector X=5.0*Pds::RandU(1000,1);
    Pds::Vector Y=X+Pds::RandN(X.Size());
    
    Pds::Vector P=Pds::PolyFit(X,Y,1);
    P.Print("P:\n");
    
    Pds::Vector Xa=Pds::LinSpace(0,5,6);
    Xa.Print("Xa:\n");
    Pds::PolyVal(P,Xa).Print("P(Xa):\n");
    
    
    Pds::Matrix M=Pds::PolyMat(X,1);
    //M.Print("M:\n");
    
    Pds::Vector Q=M.PInv()*Y;
    Q.Print("Q:\n");
    
    
    return 0;
}
