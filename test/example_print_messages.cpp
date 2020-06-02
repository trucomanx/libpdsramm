/** \example example_print_messages.cpp
 *  \brief Programa para el testeo de las funciones.
    
Para compilar o código example_print_messages.cpp:
\code{.sh}
g++ -static -o example_print_messages example_print_messages.cpp -lpdsramm 
\endcode
Para executar o programa:
\code{.sh}
    ./example_print_messages
\endcode  
Retornando por consola:
\verbatim
----ERROR :: example_print_messages.cpp::main::line 28
----ERROR :: testing error
--WARNING :: testing warning
-----INFO :: testing info number 1
\endverbatim
 *
 * Código example_print_messages.cpp:
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
