/** \example example_print_messages.cpp
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <iostream>
#include <Pds/Ra>
    
int main(void)
{
    pds_print_error_message("testing error");
    pds_print_warning_message("testing warning");
    pds_print_info_message("testing info"<<" number "<< 1);
        
    return 0;
}
