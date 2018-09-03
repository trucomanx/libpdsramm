/** \example testprog_matrix_statistics.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <Pds/RealArrays>
    
int main(void)
{
    Pds::Matrix A(200,200);
    A.FillRandN();
    
    Pds::Matrix B=A+2.0*Pds::Matrix::RandU(200,200);
    
    
    std::cout<<"A.Max()  : "<<A.Max() <<std::endl;
    std::cout<<"A.Min()  : "<<A.Min() <<std::endl;
    std::cout<<"A.Sum()  : "<<A.Sum() <<std::endl;
    std::cout<<"A.Mean() : "<<A.Mean()<<std::endl;
    std::cout<<"A.Std()  : "<<A.Std() <<std::endl;
    std::cout<<"A.Corr(B): "<<A.Corr(B)<<std::endl;

    
    return 0;
}
