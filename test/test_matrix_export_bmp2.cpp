/** \file test_matrix_export_bmp2.cpp
 *  \brief Programa para el testeo de las funciones.
    
Para compilar o código test_matrix_export_bmp2.cpp:
\code{.sh}
g++ -static -o test_matrix_export_bmp2 test_matrix_export_bmp2.cpp -lpdsramm 
\endcode
Para executar o programa:
\code{.sh}
    ./test_matrix_export_bmp2
\endcode  
Retornando por consola:
\verbatim
    
A:
0	2	4
1	3	5

\endverbatim
 *
 * Código test_matrix_export_bmp2.cpp:
 */
    
#include <cmath>
#include <Pds/Ra>
    
int main(void)
{
    Pds::Matrix Z;    
    Pds::Matrix X,Y;
    
    Pds::Vector SpaceX=Pds::LinSpace(-2,2,480);
    Pds::Vector SpaceY=Pds::LinSpace(-2,2,512);
    Pds::Meshgrid(SpaceX,SpaceY,X,Y);   
    auto func = [](double x,double y)->double 
    {double z=2*x*exp(-x*x-y*y); return 126.0*z+127.0;};
    Z=Pds::Operate(func,X,Y);
    
    Z.ExportBmpFile(Pds::Colormap::Jet,"ColormapJet.bmp");
    Z.Scale(0,255).ExportBmpFile(Pds::Colormap::Steps,"ColormapSteps.bmp");

    Z.Resize(1.2).ExportBmpFile(Pds::Colormap::Jet,"ColormapJet_resize.bmp");

    Pds::Matrix::ExportBmpFile(Z.Scale(0,255),Z.Scale(0,255),Z.Scale(0,255),"ColormapRGB.bmp");
    
    return 0;
}
