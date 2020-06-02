/** \example example_matrix_assignment.cpp
 *  \brief Programa para el testeo de las funciones.
    
Para compilar o código example_matrix_assignment.cpp:
\code{.sh}
g++ -static -o example_matrix_assignment example_matrix_assignment.cpp -lpdsramm 
\endcode
Para executar o programa:
\code{.sh}
    ./example_matrix_assignment
\endcode  
Retornando por consola:
\verbatim
    
A:
0	0	0
0	0	0
0	0	0
    
B:
1	2	3
4	5	6
7	8	9
    
A:
0	0	0
0	1	2
0	4	5
    
\endverbatim
 *
 * Código example_matrix_assignment.cpp:
 */
    
#include <iostream>
#include <Pds/Ra>
    
int main(void)
{
    Pds::Matrix A=Pds::Matrix(3,3);
    Pds::Matrix B("1 2 3\n4 5 6\n7 8 9");
    
    A.Print("\nA:\n");
    B.Print("\nB:\n");
    
    A.AddAssigAt(B,1,1);
    A.Print("\nA:\n");
    
    return 0;
}
