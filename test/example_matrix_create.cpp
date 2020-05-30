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
0
    
C:
0	0
0	0
    
D:
0.523598776	0.523598776	0.523598776
0.523598776	0.523598776	0.523598776
    
E:
0.523598776	0.523598776	0.523598776
0.523598776	0.523598776	0.523598776
    
F:
0.50000000034788	0.50000000034788	0.50000000034788
0.50000000034788	0.50000000034788	0.50000000034788
    
G:
1	2	3
4	5	6
    
H:
0.50000000034788	0.50000000034788	0.50000000034788
0.50000000034788	0.50000000034788	0.50000000034788
    
\endverbatim
 *
 * Los datos de consola no estan colorizados.
 */
    
#include <cmath>
#include <Pds/Ra>
    
int main(void)
{
    Pds::Matrix A;
    Pds::Matrix B(1);
    Pds::Matrix C(2,2);
    Pds::Matrix D(2,3,0.523598776);
    Pds::Matrix E(D);
    Pds::Matrix F(sin,D);
    Pds::Matrix G="1 2 3\n4 5 6";
    
    A.Print("\nA:\n");
    B.Print("\nB:\n");
    C.Print("\nC:\n");
    D.Print("\nD:\n");
    E.Print("\nE:\n");
    F.Print("\nF:\n");
    G.Print("\nG:\n");
         
    F.Save("filedat.txt");
    Pds::Matrix H(Pds::Ra::TextFormat,"filedat.txt");
    H.Print("\nH:\n");
    
    return 0;
}
