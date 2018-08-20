
#include <iostream>
#include <Pds/RealArrays.hpp>
    
int main(int argc, char** argv)
{
    Pds::Matrix A(2,2);
    Pds::Matrix B(2,2);
    Pds::Matrix C(2,2);
    
    A.Fill(1.0);        // Fill data with a value
    
    B.FillRandU();       // Fill data randomly between [0.0, 1.0>.
    
    std::cout<<"A:\n"<<A;
    std::cout<<"B:\n"<<B;
    
    C+=A;
    C+=B;
    
    std::cout<<"C:\n"<<C;
    return 0;
}
