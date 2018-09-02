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
    
    Pds::Vector  C=A.GetVector(2);
    C.Print("C=\n");
    
    Pds::Matrix     M=A.GetVector(2);
    M.Print("A(:,2)=\n");
    
    
    C.Fill(-1.0);
    A.SetVector(C,2);
    A.Print("A=\n");
    
    return 0;
}
