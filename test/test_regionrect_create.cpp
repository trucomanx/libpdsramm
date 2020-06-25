/** \example test_regionrect_create.cpp 
 *  \brief Programa para el testeo de las funciones.
 *
    
Para compilar o código test_regionrect_create.cpp:
\code{.sh}
g++ -static -o example_matrix_create test_regionrect_create.cpp -lpdsramm 
\endcode
Para executar o programa:
\code{.sh}
    ./example_matrix_create
\endcode  
Retornando por consola:
\verbatim
    
\endverbatim
 *
 * Código test_regionrect_create.cpp:
 */
    
#include <Pds/Ra>
#include <cstdio>
    
int main(void)
{
    Pds::RegionRect R0;
    Pds::RegionRect R1(3,3,8,8);
    Pds::RegionRect R2(5,5,8,8);
    Pds::RegionRect R(5,4,2,2);

    R0.Print("R0:\t");
    R1.Print("R1:\t");
    R2.Print("R2:\t");
    R.Print("R:\t");

    if(R.IsInside(R1))  std::cout<<"R is inside R1"<<std::endl;
    else                std::cout<<"R is not inside R1"<<std::endl;

    if(R.IsInside(R2))  std::cout<<"R is inside R2"<<std::endl;
    else                std::cout<<"R is not inside R2"<<std::endl;
    
    std::cout<<std::endl;
    
    std::cout<<"R=R1.Intersection(R2);"<<std::endl;
    R=R1.Intersection(R2);
    R.Print("R:\t");
    
    std::cout<<std::endl;
    
    std::cout<<"R.LoadString(\"1 2 3 4\");"<<std::endl;
    R.LoadString("1 2 3 4");
    R.Print("R:\t");
    
    std::cout<<std::endl;
    
    std::cout<<"R.LoadString(\"4 3 2\\t1\");"<<std::endl;
    R.LoadString("4 3 2\t1");
    R.Print("R:\t");
    
    std::cout<<std::endl;
    
    FILE *fd=fopen("data_region.txt","w");
    R0.FilePrint(fd);
    R1.FilePrint(fd);
    R2.FilePrint(fd);
    fclose(fd);

    fd=fopen("data_region.txt","r");
    while(feof(fd)==0)
    {
        R.FileScan(fd);
        R.Print("R:\t");
    }
    fclose(fd);
    
    return 0;
}
