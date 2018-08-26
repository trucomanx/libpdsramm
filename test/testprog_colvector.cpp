/** \example testprog_colvector.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
    
#include <iostream>
#include <Pds/RealArrays>


    
int main(void)
{
    Pds::ColVector A(3);
    Pds::ColVector B(3);
    Pds::ColVector C(3);
    
    C.FillRandU();       // Fill data randomly between [0.0, 1.0>.
    
    std::cout<<"C:\n"<<C;
    std::cout<<"B:\n"<<B;
    std::cout<<"A:\n"<<A;

    return 0;
}
