
#include <iostream>
#include <PDS/RealArrays.hpp>
    
int main(int argc, char** argv)
{
    PDS::Matrix A(2,2);
    PDS::Matrix B(2,2);
    PDS::Matrix C(2,2);
    
    A.Init(1.0);        // Init data with a value
    
    B.InitRand();       // Init data randomly between [0.0, 1.0>.
    
    std::cout<<"A:\n"<<A;
    std::cout<<"B:\n"<<B;
    
    C+=A;
    C+=B;
    
    std::cout<<"C:\n"<<C;
    return 0;
}
