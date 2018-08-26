/** \example testprog_defines.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <iostream>
#include <Pds/RealArrays>
    
int main(void)
{
    pds_print_error_message("testing error");
    pds_print_warning_message("testing warning");
    pds_print_info_message("testing info"<<" number "<< 1);
        
    return 0;
}
