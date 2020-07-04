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
    
    B.ExportMatFile("B","matfile.mat");
    
    Pds::Matrix Z;

    unsigned int N=480;    

    Z=Pds::Peaks(N);
    Z.Scale(0,255).ExportBmpFile(Pds::Colormap::Jet,"PeaksColormapJet.bmp");
    Z.Scale(0,255).ExportBmpFile(Pds::Colormap::Steps,"PeaksColormapSteps.bmp");
    
    Z=Pds::Mountain(N);
    Z.Scale(0,255).ExportBmpFile(Pds::Colormap::Jet,"MountainColormapJet.bmp");
    Z.Scale(0,255).ExportBmpFile(Pds::Colormap::Steps,"MountainColormapSteps.bmp");
    
    Pds::Matrix X,Y;
    
    Pds::Vector Space=Pds::LinSpace(-2,2,256);
    Pds::Meshgrid(Space,Space,X,Y);
    
    //Z=126*(X & Pds::Exp(-(X^2.0)-(Y^2.0)))+127.0;
    
    auto func = [](double x,double y)->double 
    {double z=2*x*exp(-x*x-y*y); return 126.0*z+127.0;};
    Z=Pds::Operate(func,X,Y);
    
    Z.Scale(0,255).ExportBmpFile(Pds::Colormap::Jet,"ColormapJet.bmp");
    Z.Scale(0,255).ExportBmpFile(Pds::Colormap::Steps,"ColormapSteps.bmp");

    Pds::Matrix::ExportBmpFile(Z,Z,Z,"ColormapRGB.bmp");
    
    return 0;
}
