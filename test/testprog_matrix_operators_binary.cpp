/** \example testprog_matrix_operators_binary.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <iostream>
#include <Pds/RealArrays>
    
int main(void)
{
    Pds::Matrix A(2,2);
    Pds::Matrix B(2,2);
    Pds::Matrix C;
    
    A.Fill(1.0);    std::cout<<"A:\n"<<A;
    B.Fill(2.0);    std::cout<<"B:\n"<<B;
    
    
    // + operator
    std::cout<<std::endl;
    
    C=A.Add(B);
    C.Print("A+B\n");
    
    C=A+B;
    C.Print("A+B\n");
    
    C=2-A+5;
    C.Print("2-A+5\n");
    
    // * operator
    std::cout<<std::endl;
    
    C=A.Mul(B);
    C.Print("A*B\n");
    
    C=A*B;
    C.Print("A*B\n");
    
    return 0;
}
