/** \example example_matrix_export.cpp
 *  \brief Programa para el testeo de las funciones.
    
Para compilar o código example_matrix_export.cpp:
\code{.sh}
g++ -static -o example_matrix_export example_matrix_export.cpp -lpdsramm 
\endcode
Para executar o programa:
\code{.sh}
    ./example_matrix_export
\endcode  
Retornando por consola:
\verbatim
    
A:
0	2	4
1	3	5

\endverbatim
 *
 * Código example_matrix_export.cpp:
 */
    
#include <cmath>
#include <Pds/Ra>
    
int main(void)
{
    Pds::Matrix A(2,3);
    
    A.FillId();
    A.Print("\nA:\n");
    
    A.ExportCsvFile("filename.csv",';');
    A.Save("filedat.txt");
    
    Pds::Matrix B(Pds::Ra::TextFormat,"filedat.txt");
    B.Print("B\n");
    
    B.ExportMatFile("B","matfile.mat");
    return 0;
}
