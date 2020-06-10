/** \example testprog_matrix_state.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
    
#include <iostream>
#include <Pds/Ra>
    
int main(void)
{
    Pds::Matrix A;
    Pds::Matrix B(3,3);
    Pds::Matrix C(3,3);
    
    C.At(4)=1.0/0.0;

    B.Set(0,0,+1.0/0.0);
    B.Set(1,1, 0.0/0.0);
    B.Set(2,2,-1.0/0.0);

    B.Print("B:\n");
    
    pds_print_info_message("... is void?");
    
    if(A.IsEmpty())     std::cout<<"A is NULL"<<std::endl;
    else                std::cout<<"A is not NULL"<<std::endl;
    
    if(B.IsNotEmpty())  std::cout<<"B is not NULL"<<std::endl;
    else                std::cout<<"B is NULL"<<std::endl;
    
    if(C.IsNotEmpty())  std::cout<<"C is not NULL"<<std::endl;
    else                std::cout<<"C is NULL"<<std::endl;
    
    
    
    pds_print_info_message("... is similar to ... ?");
    
    if(A.IsNotSimilarTo(B)) std::cout<<"A is not similar to B"<<std::endl;
    else                    std::cout<<"A is similar to B"<<std::endl;

    if(B.IsSimilarTo(C))    std::cout<<"B is similar to C"<<std::endl;
    else                    std::cout<<"B is not similar to C"<<std::endl;
    
    
    
    pds_print_info_message("... is multipliable to ... ?");
    
    if(A.IsNotMulBy(C))     std::cout<<"A is not multipliable by C"<<std::endl;
    else                    std::cout<<"A is multipliable by C"<<std::endl;
    
    if(B.IsMulBy(C))        std::cout<<"B is multipliable by C"<<std::endl;
    else                    std::cout<<"B is not multipliable by C"<<std::endl;  
    
    
    
    pds_print_info_message("... has the position ... ?");
    
    if(B.IsInRange(1,1))   std::cout<<"B has the position (1,1)"<<std::endl;
    else                   std::cout<<"B dont have the position (1,1)"<<std::endl;
    
    
    
    pds_print_info_message("... is in size range ... ?");
    
    if(B.IsInSizeRange(1.5,0.1))    std::cout<<"(1.5,0.1) is in size range of B"<<std::endl;
    else                            std::cout<<"(1.5,0.1) is not in size range of B"<<std::endl;
    
    
    B.IsInf().Print("\nB.IsInf()\n");
    
    B.IsNan().Print("\nB.IsNan()\n");
    
    B.IsFinite().Print("\nB.IsFinite()\n");
    
    C.Print("\nC:\n");
    std::cout<<"C.HasInf()      :\t"<<C.HasInf()<<std::endl;
    std::cout<<"C.HasNan()      :\t"<<C.HasNan()<<std::endl;
    std::cout<<"C.HasNotFinite():\t"<<C.HasNotFinite()<<std::endl;
    return 0;
}
