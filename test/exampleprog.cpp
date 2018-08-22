#include <Pds/RealArrays.hpp>
    
int main(void)
{
    Pds::Matrix P =Pds::X3D();
    Pds::Matrix P0=Pds::Y3D();
    Pds::Matrix J =Pds::RotX(3.14159/2.0);
    
    
    P.Print("P:\n");
    P0.Print("P0:\n");
    J.Print("J:\n");
    
    Pds::Matrix F=P0 + J*(P-P0);

    F.Print("\nF:\n");
    
    return 0;
}
