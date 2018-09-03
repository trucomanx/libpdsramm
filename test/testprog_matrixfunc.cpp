
/** \example testprog_matrixfunc.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <Pds/Ra>
    
int main(void)
{
    Pds::Matrix A = Pds::Eye(3);
    Pds::Matrix B = Pds::Ones(3);
    Pds::Matrix C = Pds::Zeros(3);
    Pds::Matrix D = Pds::RandU(3);
    Pds::Matrix E = Pds::RandN(3);
    Pds::Matrix F = Pds::MatrixId(3);
    Pds::Matrix G = Pds::Diag(F);
    
    A.Print("\nA:\n");
    B.Print("\nB:\n");
    C.Print("\nC:\n");
    D.Print("\nD:\n");
    E.Print("\nE:\n");
    F.Print("\nF:\n");
    G.Print("\nG:\n");
    
    return 0;
}
