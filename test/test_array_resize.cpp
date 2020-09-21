/** \file test_array_resize.cpp
 *  \brief Programa para el testeo de las funciones.
    
Para compilar o código test_array_resize.cpp:
\code{.sh}
g++ -static -o test_array_resize test_array_resize.cpp -lpdsramm 
\endcode
Para executar o programa:
\code{.sh}
    ./test_array_resize
\endcode  
Retornando por consola:
\verbatim
    
A:
0	2	4
1	3	5

\endverbatim
 *
 * Código test_array_resize.cpp:
 */
    
#include <cmath>
#include <Pds/Ra>
    
int main(void)
{
    Pds::Array<unsigned char> Z;

    std::vector<Pds::Array<unsigned char>> Block;
    Block= Pds::Array<unsigned char>::ImportBmpFile("image.bmp");
    std::cout<<"Block.size(): "<<Block.size()<<std::endl;
    
    if(Block.size()>0)
    {
        Block[0].ExportBmpFile(Pds::Colormap::Gray,"image_copy.bmp");
        Block[0].Resize(1.2).ExportBmpFile(Pds::Colormap::Gray,"image_resize.bmp");
    }
}
