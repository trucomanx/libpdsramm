/** \example testprog_matrix_assignment.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <iostream>
#include <Pds/Ra>
    
int main(void)
{
    Pds::Matrix C=Pds::Matrix(2,2);    
    
    
    std::cout<<"Assignment operator\n";    
    std::cout<<"C= Pds::Matrix(2,2);\n";
    C=Pds::Matrix(2,2);
    std::cout<<C;
    
    return 0;
}
