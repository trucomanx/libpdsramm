/** \file test_matrix_export_bmp.cpp
 *  \brief Programa para el testeo de las funciones.
    
Para compilar o código test_matrix_export_bmp.cpp:
\code{.sh}
g++ -static -o test_matrix_export_bmp test_matrix_export_bmp.cpp -lpdsramm 
\endcode
Para executar o programa:
\code{.sh}
    ./test_matrix_export_bmp
\endcode  
Retornando por consola:
\verbatim
    
A:
0	2	4
1	3	5

\endverbatim
 *
 * Código test_matrix_export_bmp.cpp:
 */
    
#include <cmath>
#include <Pds/Ra>
    
int main(void)
{
    Pds::Matrix Z;
    unsigned int N=480;    

    Z=Pds::Peaks(N);
    Z.Scale(0,255).ExportBmpFile(Pds::Colormap::Jet,"PeaksColormapJet.bmp");
    Z.Scale(0,255).ExportBmpFile(Pds::Colormap::Steps,"PeaksColormapSteps.bmp");
    
    Z=Pds::Mountain(N);
    Z.Scale(0,255).ExportBmpFile(Pds::Colormap::Jet,"MountainColormapJet.bmp");
    Z.Scale(0,255).ExportBmpFile(Pds::Colormap::Steps,"MountainColormapSteps.bmp");
    
    return 0;
}
