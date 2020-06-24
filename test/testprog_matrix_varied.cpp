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
    
    Z=Pds::Peaks(256);
    Z.ExportBmpFile(Pds::Colormap::Jet,"PeaksColormapJet.bmp");
    
    Z=Pds::Mountain(256);
    Z.ExportBmpFile(Pds::Colormap::Jet,"MountainColormapJet.bmp");
    
    Pds::Matrix X,Y;
    
    Pds::Vector Space=Pds::LinSpace(-2,2,256);
    Pds::Meshgrid(Space,Space,X,Y);
    
    //Z=126*(X & Pds::Exp(-(X^2.0)-(Y^2.0)))+127.0;
    
    auto func = [](double x,double y)->double {return 126.0*x*exp(-x*x-y*y)+127.0;};
    Z=Pds::Operate(func,X,Y);
    
    Z.ExportBmpFile(Pds::Colormap::Jet,"ColormapJet.bmp");

    Pds::Matrix C,D;
    
    return 0;
}
