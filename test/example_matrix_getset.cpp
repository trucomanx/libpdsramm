/** \example example_matrix_getset.cpp
 *  \brief Programa para el testeo de las funciones.
    
Para compilar o código example_matrix_getset.cpp:
\code{.sh}
g++ -static -o example_matrix_getset example_matrix_getset.cpp -lpdsramm 
\endcode
Para executar o programa:
\code{.sh}
    ./example_matrix_getset
\endcode  
Retornando por consola:
\verbatim
A=
0	4	8	12
1	5	9	13
2	6	10	14
3	7	11	15
    
A.Get(1,1)         =5
A.Bilinear(1.0,1.0)=5
A.Bilinear(1.5,1.5)=7.5
    
A.GetMatrix( 1,1,A.LinEnd(),A.ColEnd() ):
5	9	13
6	10	14
7	11	15
    
A.GetMatrix( 1,1,Pds::Size(2,2) ):
5	9
6	10
\endverbatim
 *
 * Código example_matrix_getset.cpp:
 */
    
#include <cmath>
#include <Pds/Ra>
    
int main(void)
{
    Pds::Matrix A(4,4);
    Pds::Matrix Sa1;
    Pds::Matrix Sa2;
    
    A.FillId();
    A.Print("A=\n");
    
    std::cout<<std::endl;
    std::cout<<"A.Get(1,1)         ="<<A.Get(1,1)<<std::endl;
    std::cout<<"A.Bilinear(1.0,1.0)="<<A.Bilinear(1.0,1.0)<<std::endl;
    std::cout<<"A.Bilinear(1.5,1.5)="<<A.Bilinear(1.5,1.5)<<std::endl;
    
    Sa1=A.GetMatrix(1,1,A.LinEnd(),A.ColEnd());
    Sa1.Print("\nA.GetMatrix( 1,1,A.LinEnd(),A.ColEnd() ):\n");
    
    Sa2=A.GetMatrix(1,1,Pds::Size(2,2));
    Sa2.Print("\nA.GetMatrix( 1,1,Pds::Size(2,2) ):\n");
    return 0;
}
