/** \example testprog_matrix.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <cmath>
#include <Pds/Ra>
    
int main(void)
{
    Pds::Matrix A;
    Pds::Matrix B(1);
    Pds::Matrix C(2,2);
    Pds::Matrix D(3,2,0.523598776);
    Pds::Matrix E(D);
    Pds::Matrix F(sin,D);
    
    F.Save("filedat.txt");
    Pds::Matrix G("filedat.txt");
    
    A.Print("\nA:\n");
    B.Print("\nB:\n");
    C.Print("\nC:\n");
    D.Print("\nD:\n");
    E.Print("\nE:\n");
    F.Print("\nF:\n");
    G.Print("\nG:\n");
    
    
    std::cout<<std::endl<<(13/10)<<std::endl;
    std::cout<<std::endl<<(16/10)<<std::endl;
    
    Pds::Matrix *X= new Pds::Matrix(F);
    std::cout<<"X->Nlin():"<<X->Nlin()<<std::endl;
    std::cout<<"X->Ncol():"<<X->Ncol()<<std::endl;
    
    return 0;
}
