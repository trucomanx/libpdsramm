/** \example testprog_matrixrotation.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <Pds/RealArrays>
    
int main(void)
{
    Pds::Matrix X2 = Pds::X2D();
    X2.Print("\nX2:\n");
    
    Pds::Matrix R2 = Pds::Rot2D(Pds::Ra::Pi/4.0);
    (R2*X2).Print("\nR2(45grad)*X2\n");
    
    Pds::Matrix Z = Pds::Z3D();
    Z.Print("\nZ:\n");
    
    Pds::Matrix RX = Pds::RotX(Pds::Ra::Pi/4.0);
    (RX*Z).Print("\nRX(45grad)*Z\n");
    
    Pds::Matrix RY = Pds::RotY(Pds::Ra::Pi/4.0);
    (RY*Z).Print("\nRY(45grad)*Z\n");
    
    Pds::Matrix RZ = Pds::RotZ(Pds::Ra::Pi/4.0);
    (RZ*Z).Print("\nRZ(45grad)*Z\n");
    
    return 0;
}
