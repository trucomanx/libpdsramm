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
    
    A.FillRandU();
    A.Print("A=\n");
    
    Pds::ColVector  C=A.GetColVector(2);
    C.Print("A(:,2)=\n");
    
    Pds::Matrix     M=A.GetColVector(2);
    M.Print("A(:,2)=\n");
    return 0;
}
