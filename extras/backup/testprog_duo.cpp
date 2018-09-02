/** \example testprog_duo.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <iostream>
#include <Pds/Duo>

#define TYPEVAR int
    
int main(void)
{
    Pds::Duo<TYPEVAR> A;
    Pds::Duo<TYPEVAR> B(1,2);
    Pds::Duo<TYPEVAR> C(1,1);
    
    std::cout<<"A = "<<A;
    std::cout<<"B = "<<B;
    std::cout<<"C = "<<C;
    
    std::cout<<std::endl;
    
    std::cout<<"B.Dot()  = "<<B.Dot() <<std::endl;
    std::cout<<"B.Dot(C) = "<<B.Dot(C)<<std::endl;
    
    std::cout<<std::endl;
    
    B.Add(C).Print("B.Add(C) = ");
    B.Add(1).Print("B.Add(1) = ");
    
    std::cout<<std::endl;
    
    B.Mul(2).Print("B.Mul(2) = ");
    std::cout<<"B*2      = "<<(B*2);
    std::cout<<"2*B      = "<<(2*B);
    
    std::cout<<std::endl;
    
    std::cout<<"A = "<<A;
    std::cout<<"B = "<<B;
    std::cout<<"C = "<<C;
    
    std::cout<<std::endl;
    
    std::cout<<"2+C = "<<(2+C);
    std::cout<<"C+2 = "<<(C+2);
    std::cout<<"B+C = "<<(B+C);
    
    std::cout<<std::endl;
    
    std::cout<<"B*B = "<<(B*B);
    
    return 0;
}
