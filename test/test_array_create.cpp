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
    Pds::Array<unsigned int> A;
    Pds::Array<unsigned char> B(2,2);
    B.At(2)=9;
    Pds::Array<double> C(3,2,0.5);

    Pds::Matrix M(B);
        
    A.Print("\nA:\n");
    B.Print("\nB:\n");
    C.Print("\nC:\n");

    std::cout<<"B.Get(0,1):"<<0+B.Get(0,1)<<std::endl;


    M.Print("\nM(B):\n");
    
    return 0;
}
