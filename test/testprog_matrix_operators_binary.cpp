/** \example testprog_matrix_operators_binary.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <iostream>
#include <Pds/Ra>
    
int main(void)
{
    Pds::Matrix A(2,2);
    Pds::Matrix B(2,2);
    Pds::Matrix B1(1,2,3);
    Pds::Matrix C;

    
    A.Fill(1.0);    std::cout<<"A:\n"<<A;
    B.Fill(2.0);    std::cout<<"B:\n"<<B;
    
    
    // + operator
    std::cout<<std::endl;
    
    C=A.Add(B);
    C.Print("A.Add(B)\n");
    
    C=A+B;
    C.Print("A+B\n");
    
    C=2-A+5;
    C.Print("2-A+5\n");
    
    // * operator
    std::cout<<std::endl;
    
    C=A.Mul(B);
    C.Print("A.Mul(B)\n");
    
    C=A*B;
    C.Print("A*B\n");
    
    // / operator
    std::cout<<std::endl;
    
    C=A.Div(2);
    C.Print("A.Div(2)\n");
    
    C=A/2;
    C.Print("A/2\n");
    
    // Geq y Leq
    C=Pds::MatrixId(4,4);
    C.Print("\nC\n");

    C.Geq(8).Print("\nC.Geq(8)\n");

    C.Leq(8).Print("\nC.Leq(8)\n");

    A.Print("\nA\n");
    B1.Print("B1\n");

    C=A.AddRowMatrix(B1);
    C.Print("A.AddRowMatrix(B1)\n");

    C=A.SubRowMatrix(B1);
    C.Print("A.SubRowMatrix(B1)\n");
    return 0;
}
