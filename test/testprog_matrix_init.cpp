/** \example testprog_matrix_init.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <cmath>
#include <Pds/Ra>
    
int main(void)
{
    Pds::Matrix A(4,3);
    Pds::Matrix B(4,4);
    
    A.Fill(-1);
    A.Print("\nA:\n");
    
    A.FillId();
    A.Print("\nA:\n");
    
    A.LinSpace(0,22);
    A.Print("\nA:\n");
    
    B.FillRandU(-2,2);
    B.Print("\nB:\n");
    
    B.FillRandU(-2.0,2.0);
    B.Print("\nB:\n");
    
    return 0;
}
