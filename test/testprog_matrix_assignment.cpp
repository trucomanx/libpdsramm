/** \example testprog_matrix_assignment.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <iostream>
#include <Pds/RealArrays>
    
int main(void)
{
    Pds::Matrix C=Pds::Matrix(2,2);    
    Pds::Matrix B;
    
    std::cout<<"B.Move(C);\n";
    B.Move(C);
    std::cout<<B<<"\n";
    
    if(C.IsVoid())  std::cout<<"C is null\n\n";
    
    std::cout<<"Assignment operator\n";    
    std::cout<<"C= Pds::Matrix(2,2);\n";
    C=Pds::Matrix(2,2);
    std::cout<<C;
    
    return 0;
}
