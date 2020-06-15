/** \example testprog_ra_tools.cpp
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <Pds/Ra>
#include <ctime>

int main(void)
{
    Pds::Matrix A(8,8);
    A.FillId();
    A.Print("\nA:\n");

    std::srand(std::time(0));
    
    std::list<unsigned int> List=Pds::Ra::IndicesRand(2,7,4);
        
    std::cout<<std::endl;
    for (auto pmat = List.begin(); pmat != List.end(); pmat++) 
    std::cout<<*pmat<<"\t";
    std::cout<<std::endl;

    Pds::Matrix B=A.GetRows(List);
    B.Print("\nB:\n");

    return 0;
}
