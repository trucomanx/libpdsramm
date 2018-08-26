
/** \example testprog_funcmatrix.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <Pds/RealArrays>
    
int main(void)
{
    Pds::Matrix A = Pds::Eye(3);
    Pds::Matrix B = Pds::Ones(3);
    Pds::Matrix C = Pds::Zeros(3);
    
    A.Print("\nA:\n");
    B.Print("\nB:\n");
    C.Print("\nC:\n");
    
    Pds::Matrix X2 = Pds::X2D();
    Pds::Matrix Y2 = Pds::Y2D();
    
    X2.Print("\nX2:\n");
    Y2.Print("\nY2:\n");
    
    Pds::Matrix X = Pds::X3D();
    Pds::Matrix Y = Pds::Y3D();
    Pds::Matrix Z = Pds::Z3D();
    
    X.Print("\nX:\n");
    Y.Print("\nY:\n");
    Z.Print("\nZ:\n");
    
    return 0;
}
