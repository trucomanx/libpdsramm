#include <Pds/Ra>

int main(void)
{
    Pds::Matrix P =Pds::X3D();
    Pds::Matrix P0=Pds::Y3D();
    Pds::Matrix J =Pds::RotX(Pds::Ra::Pi/2.0);
    
    Pds::Matrix F=P0 + J*(P-P0);

    F.Print("\nF:\n");
    
    Pds::Ra::PrintVersion("Version:\t");
    Pds::Ra::PrintPackage("Package:\t");
    
    return 0;
}
