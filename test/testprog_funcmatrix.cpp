
/** \example testprog_funcmatrix.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <Pds/RealArrays>
    
int main(void)
{
    Pds::Matrix A = Pds::Eye(3);
    Pds::Matrix B = Pds::Ones(3);
    Pds::Matrix C = Pds::Zeros(3);
    
    A.Print("\nA:\n");
    B.Print("\nB:\n");
    C.Print("\nC:\n");
    
    
    A.FillRandN();
    A.Print("\nA:\n");
    Pds::Diag(A).Print("D:\n");
    
    return 0;
}
