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
    
    A.Fill(-1);
    A.Print("\nA:\n");
    
    A.FillId();
    A.Print("\nA:\n");
    
    A.FillLinSpace(0,22);
    A.Print("\nA:\n");
    
    A.FillRandU(-2,2);
    A.Print("\nA:\n");
    
    A.FillRandU(-2.0,2.0);
    A.Print("\nA:\n");
    
    return 0;
}
