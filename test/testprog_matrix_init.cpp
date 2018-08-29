/** \example testprog_matrix_init.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <cmath>
#include <Pds/RealArrays>
    
int main(void)
{
    Pds::Matrix A(4,3);
    
    A.Fill(-1);
    A.Print("\nA:\n");
    
    A.FillId();
    A.Print("\nA:\n");
    
    A.LinSpace(0,22);
    A.Print("\nA:\n");
    
    return 0;
}
