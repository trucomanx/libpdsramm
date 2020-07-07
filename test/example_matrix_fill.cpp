/** \example example_matrix_fill.cpp
 *  \brief Programa para el testeo de las funciones.
    
Para compilar o código example_matrix_fill.cpp:
\code{.sh}
g++ -static -o example_matrix_fill example_matrix_fill.cpp -lpdsramm 
\endcode
Para executar o programa:
\code{.sh}
    ./example_matrix_fill
\endcode  
Retornando por consola:
\verbatim
    
A:
-1	-1	-1
-1	-1	-1
    
A:
0	2	4
1	3	5
    
A:
0	8.8	17.6
4.4	13.2	22
    
A:
1	-1	0
-2	1	-2
    
A:
-0.65910897714044	1.0729183792476	-0.88890115678725
0.21587982318172	-0.090411792551359	0.5154836990477

\endverbatim
 *
 * Código example_matrix_fill.cpp:
 */
    
#include <cmath>
#include <Pds/Ra>
    
int main(void)
{
    Pds::Matrix A(2,3);
    
    A.Fill(-1);
    A.Print("\nA:\n");
    
    A.FillId();
    A.Print("\nA:\n");
    
    A.FillLinSpace(0,22);
    A.Print("\nA:\n");
    
    A.FillRandU(-2,2);
    A.Print("\nA:\n");
    
    A.FillRandU(-2.0,2.0);
    A.Print("\nA:\n");

    A=255*Pds::Zeros(1007,507);
    A.InitRegion(Pds::RegionRect(0,0,100,100),255);
    
    A.ExportBmpFile(Pds::Colormap::Jet,"test.bmp");
    Pds::Matrix::ExportBmpFile(A,A,A,"test2.bmp");
    return 0;
}
