/** \example testprog_funccolvector.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
    
#include <iostream>
#include <Pds/RealArrays>


    
int main(void)
{
    
    Pds::ColVector W=Pds::LinSpace(0,10,5);
    std::cout<<"W:\n"<<W;
    

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
