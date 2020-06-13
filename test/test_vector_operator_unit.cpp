/** \file test_vector_operator_unit.cpp
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
    
#include <Pds/Ra>
#include <cmath>
    
int main(void)
{
    
    Pds::Vector A(2);
    A.Fill(1.0);
    
    A.T().Print("A.T():\n");
    A.Unit().T().Print("A.Unit().T():\n");

    return 0;
}
