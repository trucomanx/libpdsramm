/** \example example_matrix_algebra.cpp
 *  \brief Programa para el testeo de las funciones.
    
Para compilar o código example_matrix_algebra.cpp:
\code{.sh}
g++ -static -o example_matrix_algebra example_matrix_algebra.cpp -lpdsramm 
\endcode
Para executar o programa:
\code{.sh}
    ./example_matrix_algebra
\endcode  
Retornando por consola:
\verbatim
    
A:
1	2	1
1	-1	1
1	1	2
    
ID.T():
1	3	2
    
V=A.Multiindex(ID) :
8
-1
4
    
\endverbatim
 *
 * Código example_matrix_algebra.cpp:
 */
    
#include <cmath>
#include <Pds/Ra>
    
int main(void)
{
    Pds::Matrix A("1 2 1\n-3 -2 1\n1 1 2");
    A.Print("\nA:\n");
    
    Pds::Vector ID({1,3,2});    
    ID.T().Print("\nID.T():\n");

    Pds::Vector V=A.Multiindex(ID);

    V.Print("\nV=A.Multiindex(ID) :\n");
    
    std::cout<<"A.Det():\t"<<A.Det()<<std::endl;
    
    return 0;
}
