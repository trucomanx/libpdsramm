/** \file test_matrix_resize.cpp
 *  \brief Programa para el testeo de las funciones.
    
Para compilar o código test_matrix_resize.cpp:
\code{.sh}
g++ -static -o test_matrix_resize test_matrix_resize.cpp -lpdsramm 
\endcode
Para executar o programa:
\code{.sh}
    ./test_matrix_resize
\endcode  
Retornando por consola:
\verbatim
    
A:
0	2	4
1	3	5

\endverbatim
 *
 * Código test_matrix_resize.cpp:
 */
    
#include <cmath>
#include <Pds/Ra>
    
int main(void)
{
    Pds::Matrix Z;

    std::vector<Pds::Matrix> Block;
    Block= Pds::Matrix::ImportBmpFile("image.bmp");
    std::cout<<"Block.size(): "<<Block.size()<<std::endl;
    
    if(Block.size()>0)
    {
        Block[0].ExportBmpFile(Pds::Colormap::Gray,"image_copy.bmp");
        Block[0].Resize(1.2).ExportBmpFile(Pds::Colormap::Gray,"image_resize.bmp");
    }
}
