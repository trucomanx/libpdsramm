/** \file test_matrix_export_bmp3.cpp
 *  \brief Programa para el testeo de las funciones.
    
Para compilar o código test_matrix_export_bmp3.cpp:
\code{.sh}
g++ -static -o test_matrix_export_bmp3 test_matrix_export_bmp3.cpp -lpdsramm 
\endcode
Para executar o programa:
\code{.sh}
    ./test_matrix_export_bmp3
\endcode  
Retornando por consola:
\verbatim
    
A:
0	2	4
1	3	5

\endverbatim
 *
 * Código test_matrix_export_bmp3.cpp:
 */
    
#include <cmath>
#include <Pds/Ra>
    
int main(void)
{
    Pds::Matrix Z;
    unsigned int N=480;    

    Z=Pds::Peaks(N);
    Pds::Matrix::ExportBmpFile(Z.Scale(0,255),Z.Scale(0,255),Z.Scale(0,255),"ColormapRGB.bmp");
    
    std::vector<Pds::Matrix> Block;
    //Block=Pds::Matrix::ImportBmpFile("IMG-20200503-WA0011.bmp");
    Block=Pds::Matrix::ImportBmpFile("ColormapRGB.bmp");

    if(Block.size()==1)
    Block[0].Scale(0,255).ExportBmpFile(Pds::Colormap::Jet,"ColormapRGB_new.bmp");

    if(Block.size()==3)
    Pds::Matrix::ExportBmpFile(Block[0],Block[1],Block[2],"ColormapRGB_new.bmp");
    
    return 0;
}
