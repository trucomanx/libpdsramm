/** \example example_vector_statistics.cpp
 *  \brief Programa para el testeo de las funciones.
    
Para compilar o código example_vector_statistics.cpp:
\code{.sh}
g++ -static -o example_vector_statistics example_vector_statistics.cpp -lpdsramm 
\endcode
Para executar o programa:
\code{.sh}
    ./example_vector_statistics
\endcode  
Retornando por consola:
\verbatim
    
A.T():
1	2
    
B.T():
1	2	3
    
A.Conv(B).T():
1	4	7	6
    
A.Conv(B,true).T():
4	7
    
A.XCorr(B).T():
3	8	5	2
    
A.XCorr(B,true).T():
5	2
    
\endverbatim
 *
 * Código example_vector_statistics.cpp:
 */
    
    
#include <Pds/Ra>
#include <cmath>
    
int main(void)
{
    Pds::Vector R;
    Pds::Vector A("1 2");
    Pds::Vector B("1 2 3");
        
    A.T().Print("\nA.T():\n");  // Transpose of A
    B.T().Print("\nB.T():\n");  // Transpose of B

    
    R=A.Conv(B);        // Conv(A,B)
    R.T().Print("\nA.Conv(B).T():\n");
    
    R=A.Conv(B,true);   // Conv(A,B) with size of A
    R.T().Print("\nA.Conv(B,true).T():\n");
    
    R=A.XCorr(B);       // XConv(A,B)
    R.T().Print("\nA.XCorr(B).T():\n");
    
    R=A.XCorr(B,true);  // XConv(A,B) with size of A
    R.T().Print("\nA.XCorr(B,true).T():\n");
    return 0;
}
