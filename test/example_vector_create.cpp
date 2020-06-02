/** \example example_vector_create.cpp
 *  \brief Programa para el testeo de las funciones.
    
Para compilar o código example_vector_create.cpp:
\code{.sh}
g++ -static -o example_vector_create example_vector_create.cpp -lpdsramm 
\endcode
Para executar o programa:
\code{.sh}
    ./example_vector_create
\endcode  
Retornando por consola:
\verbatim
    
A.T():
0	0
    
B.T():
0	1	2	3
    
C.T():
2	3
    
D.T():
1	2	4	5
    
E.T():
0	0	0	0
    
F.T():
1	1
    
G.T():
1	0.54030230586814	-0.41614683654714	-0.98999249660045
    
H.T():
-1.2	-1.2	-1.2
    
I.T():
1	2	3	4	5	6

\endverbatim
 *
 * Código example_vector_create.cpp:
 */
    
    
#include <Pds/Ra>
#include <cmath>
    
int main(void)
{
    Pds::Matrix Mat("0 2\n1 3");
    
    Pds::Vector A(2);           // All zeros
    Pds::Vector B(Mat);         // Vectorize matrix
    Pds::Vector C(Mat,1);       // Use column 1 of matrix Mat
    Pds::Vector D("1 2\n4 5");  // Load from string and ignores \n
    Pds::Vector E(Mat.Size());  // Vectorize size
    Pds::Vector F(cos,A);       // Evaluate cos(A)
    Pds::Vector G(cos,Mat);     // Vectorize matrix and evaluate cos(Mat)
    Pds::Vector H(3,-1.2);      // Initialize all -1.2
    
    A.T().Print("\nA.T():\n");    // Transpose of A
    B.T().Print("\nB.T():\n");    // Transpose of B
    C.T().Print("\nC.T():\n");    // Transpose of C
    D.T().Print("\nD.T():\n");    // Transpose of D
    E.T().Print("\nE.T():\n");    // Transpose of E
    F.T().Print("\nF.T():\n");    // Transpose of F
    G.T().Print("\nG.T():\n");    // Transpose of G
    H.T().Print("\nH.T():\n");    // Transpose of H
    
    Pds::Ra::SaveString("filedat.txt","1 2 3\n4 5 6\n");
    Pds::Vector I(Pds::Ra::TextFormat,"filedat.txt"); // Load from string and ignores \n
    
    I.T().Print("\nI.T():\n");    // Transpose of I
    
    return 0;
}
