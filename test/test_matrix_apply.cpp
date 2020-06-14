/** \file test_matrix_apply.cpp 
 *  \brief Programa para el testeo de las funciones.
 *
    
Para compilar o código test_matrix_apply.cpp:
\code{.sh}
g++ -static -o test_matrix_apply test_matrix_apply.cpp -lpdsramm 
\endcode
Para executar o programa:
\code{.sh}
    ./test_matrix_apply
\endcode  
Retornando por consola:
\verbatim
    
\endverbatim
 *
 * Código test_matrix_apply.cpp:
 */
    
#include <cmath>
#include <Pds/Ra>
    
int main(void)
{
    Pds::Matrix A(3,2);
    Pds::Matrix B;

    A.FillId();
    A.Print("\nA:\n");

    B=A.OperateCols(Pds::SumSquare);
    B.Print("\nA.OperateCols(Pds::SumSquare):\n");

    B=A.OperateRows(Pds::SumSquare);
    B.Print("\nA.OperateRows(Pds::SumSquare):\n");

    B=A.OperateRows(Pds::Rms);
    B.Print("\nA.OperateRows(Pds::Rms):\n");
    
    return 0;
}
