/** \file test_array_create.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <cmath>
#include <Pds/Ra>
    
int main(void)
{
    Pds::Ra::Randomize();

    Pds::Array<unsigned int> A;
    Pds::Array<unsigned char> B(2,2);
    B.At(2)=9;
    Pds::Array<double> C(3,4,0.5);

    Pds::Matrix D(3,3); D.FillId(); D=D*1.5+0.1;
    D.Print("\nD:\n");
    Pds::Array<unsigned char> E(D);
    E.Print("\nE:\n");

    Pds::Matrix M(B);
        
    A.Print("\nA:\n");
    B.Print("\nB:\n");
    C.Print("\nC:\n");

    std::cout<<"B.Get(0,1):"<<0+B.Get(0,1)<<std::endl;


    M.Print("\nM(B):\n");

    C.FillRandC(0.6);
    C.Print("\nC:\n");
    C.Reshape(4,3);
    C.Print("\nC:\n");
    
    return 0;
}
