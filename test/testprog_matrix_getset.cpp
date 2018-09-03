/** \example testprog_matrix_getset.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <cmath>
#include <Pds/Ra>
    
int main(void)
{
    Pds::Matrix A(4,4);
    
    A.FillRandU();
    A.Print("A=\n");
    
    std::cout<<std::endl;
    std::cout<<"A.Get(1,1)s         ="<<A.Get(1,1)<<std::endl;
    std::cout<<"A.Bilinear(1.0,1.0)="<<A.Bilinear(1.0,1.0)<<std::endl;
    std::cout<<"A.Bilinear(1.5,1.5)="<<A.Bilinear(1.5,1.5)<<std::endl;
    std::cout<<"A.Bilinear(2.0,2.0)="<<A.Bilinear(2.0,2.0)<<std::endl;

    
    return 0;
}
