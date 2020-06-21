/** \example example_matrix_create.cpp 
 *  \brief Programa para el testeo de las funciones.
 *
    
Para compilar o código example_matrix_create.cpp:
\code{.sh}
g++ -static -o example_matrix_create example_matrix_create.cpp -lpdsramm 
\endcode
Para executar o programa:
\code{.sh}
    ./example_matrix_create
\endcode  
Retornando por consola:
\verbatim
A:
    
B:
0	0
0	0
    
C:
0.523598776	0.523598776	0.523598776
0.523598776	0.523598776	0.523598776
    
D:
0.523598776	0.523598776	0.523598776
0.523598776	0.523598776	0.523598776
    
E:
0.50000000034788	0.50000000034788	0.50000000034788
0.50000000034788	0.50000000034788	0.50000000034788
    
F:
1	2	3
4	5	6
    
G:
1	2	3
4	5	6
    
\endverbatim
 *
 * Código example_matrix_create.cpp:
 */
    
#include <cmath>
#include <Pds/Ra>
    
int main(void)
{
    Pds::Matrix A;
    Pds::Matrix B(2,2);
    Pds::Matrix C(2,3,0.523598776);
    Pds::Matrix D(C);
    Pds::Matrix E(sin,D);
    Pds::Matrix F="1 2 \n 3 4";
    
    A.Print("\nA:\n");
    B.Print("\nB:\n");
    C.Print("\nC:\n");
    D.Print("\nD:\n");
    E.Print("\nE:\n");
    F.Print("\nF:\n");
         
    F.Save("filedat.txt");
    Pds::Matrix G(Pds::Ra::TextFormat,"filedat.txt");
    G.Print("\nG:\n");
    
    Pds::Matrix H(pow,F,F);
    H.Print("\nH:\n");
    
    return 0;
}
