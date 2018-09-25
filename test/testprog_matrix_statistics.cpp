/** \example testprog_matrix_statistics.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <Pds/Ra>
    
int main(void)
{
    Pds::Matrix A(200,200);
    A.FillRandN();
    
    Pds::Matrix B=A+2.0*Pds::RandU(200,200);
    
    
    std::cout<<"A.Max()  : "<<A.Max() <<std::endl;
    std::cout<<"A.Min()  : "<<A.Min() <<std::endl;
    std::cout<<"A.Sum()  : "<<A.Sum() <<std::endl;
    std::cout<<"A.Mean() : "<<A.Mean()<<std::endl;
    std::cout<<"A.Std()  : "<<A.Std() <<std::endl;
    std::cout<<"A.Corr(B): "<<A.Corr(B)<<std::endl;
    
    Pds::Matrix C("1 2 2 \n-1 2 -1\n 1 0 3");
    Pds::Matrix D("1 1\n1 1");
    
    C.Print("C:\n");
    D.Print("D:\n");
    
    C.XCorr(D).Print("C.XCorr(D):\n");
    C.XCorr(D,true).Print("C.XCorr(D,true):\n");
    
    return 0;
}
