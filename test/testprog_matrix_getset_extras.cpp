/** \example testprog_matrix_getset_extras.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <cmath>
#include <Pds/RealArrays>
    
int main(void)
{
    Pds::Matrix A(4,4);
    
    A.FillId();
    A.Print("A=\n");
    
    Pds::Vector  C=A.GetColVector(2);
    C.Print("C=\n");
    
    C.Fill(-1.0);
    A.SetColVector(C,2);
    A.Print("A=\n");
    
    Pds::Vector  D=A.GetDiagonal();
    D.Print("D=\n");
    
    return 0;
}
