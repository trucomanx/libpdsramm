/** \example testprog_matrix_rows.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <Pds/Ra>
    
int main(void)
{
    Pds::Matrix A("1 1 1 24\n4 6 10 148\n0.5 0.25 0.3333333333 9");
    Pds::Matrix B;

    
    B=A;
    B.RowReduction();
    
    A.Print("\nA:\n");
    B.Print("\nB:\n");
    
    
    return 0;
}
