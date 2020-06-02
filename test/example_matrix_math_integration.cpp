/** \example example_matrix_math_integration.cpp
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <Pds/Ra>
#include <iostream>
#include <cmath>
    
double func1(double x)
{
    if (x*x<2)  return sqrt(2-x*x);
    else        return 0;
}
    
double func2(double x)
{
    return 2/(1+x*x);
}
   
int main(void)
{
    double S;
    
    S = Pds::SimpsonIntegration(func1,-sqrt(2.0),+sqrt(2.0),10000);
    std::cout<<"S:"<<S<<std::endl;
    
    S = Pds::ImproperIntegration(func2,0.0,10000);
    std::cout<<"S:"<<S<<std::endl;
    
    return 0;
}
