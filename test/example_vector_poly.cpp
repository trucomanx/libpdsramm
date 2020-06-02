/** \example example_vector_poly.cpp
 *  \brief Programa para el testeo de las funciones.
    
Para compilar o código example_vector_poly.cpp:
\code{.sh}
g++ -static -o example_vector_poly example_vector_poly.cpp -lpdsramm 
\endcode
Para executar o programa:
\code{.sh}
    ./example_vector_poly
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
 * Código example_vector_poly.cpp:
 */
    
#include <cmath>    
#include <Pds/Ra>
    
int main(void)
{
    // Creating Vectors X in [0,6> and Y: Y=X^2+noise
    Pds::Vector X=6.0*Pds::RandU(1000,1);
    Pds::Vector Y=Pds::Pow(X,2) +0.1*Pds::RandN(X.Size());
    
    // Print size of vectors
    X.Size().Print("X.Size(): ");
    Y.Size().Print("Y.Size(): ");
    
    // Getting the polynomial P of order 2 that fit (X,Y)
    Pds::Vector P=Pds::PolyFit(X,Y,3);
    P.T().Print("\nP=Pds::PolyFit(X,Y,3);\tP.T():\n");
    
    // Creating vector Xa
    Pds::Matrix U("0 1 2\n3 4 5\n6 7 8");
    U.Print("\nU:\n");
    
    // Getting Ya=p(U)
    Pds::Matrix Ya=Pds::PolyVal(P,U);
    Ya.Print("\nPds::PolyVal(P,U):\n");
    
    return 0;
}
