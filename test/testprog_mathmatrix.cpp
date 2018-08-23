/** \example testprog_mathmatrix.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <Pds/RealArrays>
    
int main(void)
{
    Pds::Matrix A(2);
    
    A.Fill(3.14159*45.0/180.0);
    
    A.Print("\nA:\n");
    
    Pds::Sin(A).Print("sin(A):\n");
    Pds::Cos(A).Print("cos(A):\n");
    Pds::Tan(A).Print("tan(A):\n");
    
    A.Fill(1.0);
    A.Print("\nA:\n");
    
    Pds::Exp(A).Print("exp(A):\n");
    Pds::Exp2(A).Print("exp2(A):\n");
    Pds::Log(A).Print("log(A):\n");
    Pds::Log2(A).Print("log2A):\n");
    Pds::Log10(A).Print("log10(A):\n");
    
    A.Fill(2.0);
    A.Print("\nA:\n");
    
    Pds::Sqrt(A).Print("sqrt(A):\n");
    return 0;
}
