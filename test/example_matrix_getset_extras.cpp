/** \example example_matrix_getset_extras.cpp
 *  \brief Programa para el testeo de las funciones.
    
Para compilar o código example_matrix_getset_extras.cpp:
\code{.sh}
g++ -static -o example_matrix_getset_extras example_matrix_getset_extras.cpp -lpdsramm 
\endcode
Para executar o programa:
\code{.sh}
    ./example_matrix_getset_extras
\endcode  
Retornando por consola:
\verbatim
    
A=
0	3	6
1	4	7
2	5	8
    
C=A.GetColVector(1)=
3
4
5
    
A=
0	3	-1
1	4	-1
2	5	-1

D=A.GetDiagonal()=
0
4
-1
\endverbatim
 *
 * Código example_matrix_getset_extras.cpp:
 */
    
#include <cmath>
#include <Pds/Ra>
    
int main(void)
{
    Pds::Matrix A("0 3 6\n1 4 7\n2 5 8");
    
    A.Print("\nA=\n");
    
    Pds::Vector  C=A.GetColVector(1);
    C.Print("\nC=A.GetColVector(1)=\n");

    
    A.GetRowAsColVector(1).Print("\nA.GetRowAsColVector(1)\n");
    
    C.Fill(-1.0);
    A.SetColVector(2,C);
    A.Print("\nA=\n");
    
    Pds::Vector  D=A.GetDiagonal();
    D.Print("\nD=A.GetDiagonal()=\n");
    
    return 0;
}
