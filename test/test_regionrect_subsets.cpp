/** \example test_regionrect_subsets.cpp 
 *  \brief Programa para el testeo de las funciones.
 *
    
Para compilar o código test_regionrect_subsets.cpp:
\code{.sh}
g++ -static -o example_matrix_create test_regionrect_subsets.cpp -lpdsramm 
\endcode
Para executar o programa:
\code{.sh}
    ./example_matrix_create
\endcode  
Retornando por consola:
\verbatim
    
\endverbatim
 *
 * Código test_regionrect_subsets.cpp:
 */
    
#include <Pds/Ra>
#include <cstdio>
    
int main(void)
{
    Pds::RegionRect R0;
    Pds::RegionRect R1(3,4,8,4);
    Pds::RegionRect R2(6,7,2,2);
    Pds::RegionRect R;

    R0.Print("R0:\t");
    R1.Print("R1:\t");
    R2.Print("R2:\t");
    
    R=R1.Superior(R2);
    R.Print("R:\t");

    
    return 0;
}
