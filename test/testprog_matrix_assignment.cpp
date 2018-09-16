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
    Pds::Matrix A(5,5);
    Pds::Matrix B(2,2);
    Pds::Matrix C=Pds::Matrix(2,2);    
    
    
    std::cout<<"Assignment operator\n";    
    std::cout<<"C= Pds::Matrix(2,2);\n";
    C=Pds::Matrix(2,2);
    std::cout<<C;
    
    A.Fill(1.0);
    B.Fill(1.0);

    A.AddAssigAt(B,2,2);
    A.Print("A:\n");
    
    return 0;
}
