/** \example testprog_matrix_varied.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <cmath>
#include <Pds/Ra>
    
#include <list>


int main(void)
{
    Pds::Matrix A="1 2 3\n4 5 6";
    A.Print("A\n");
    A.Save("filedat.txt");
    
    Pds::Matrix B(Pds::Ra::TextFormat,"filedat.txt");
    B.Print("B\n");
    
    return 0;
}
