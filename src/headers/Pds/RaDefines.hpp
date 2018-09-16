/*
 * RaDefines.hpp
 * 
 * Copyright 2018 Fernando Pujaico Rivera <fernando.pujaico.rivera@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */

/** \file RaDefines.hpp
 * \brief Archivo de definición de macro defines.
 * 
 */
    

/** \defgroup DefinesGroup Funciones con namespace Pds::Ra -- Constantes y Defines
 *  \brief Constantes y macros: pds_print_error_message(), Pds::Ra::WarningRCond, etc
 *  <div class="fragment"> \#include <Pds/RaDefines> </div>
 *  
 * @{
 */

    
#ifndef __PDS_RADEFINES_HPP__
#define __PDS_RADEFINES_HPP__
    
#include <iostream>
    
    
#ifndef pds_print_error_message
/*!
 * \def pds_print_error_message
 * Mensaje de error.
 * \ingroup DefinesGroup
*/
#define pds_print_error_message(msg) \
    std::cout<<"----ERROR :: "<<__FILE__<<"::"<<__FUNCTION__<<"::line "<<__LINE__<<std::endl \
    <<"----ERROR :: "<<msg<<std::endl
#endif

    
    
#ifndef pds_print_warning_message
/*!
 * \def pds_print_warning_message
 * Mensaje de advertencia.
 * \ingroup DefinesGroup
*/
#define pds_print_warning_message(msg) \
    std::cout<<"--WARNING :: "<<msg<<std::endl
#endif
    
    
#ifndef pds_print_info_message
/*!
 * \def pds_print_info_message
 * Mensaje con informaciones genericas.
 * \ingroup DefinesGroup
*/
#define pds_print_info_message(msg) \
    std::cout<<"-----INFO :: "<<msg<<std::endl
#endif
    
    
    
namespace Pds{
namespace Ra{
    
    
    /*!
     * Número PI.
     * \ingroup DefinesGroup
    */
    const double Pi =3.14159265358979323846264338327950288;
    
    /*!
     * Número aureo.
     * \ingroup DefinesGroup
    */
    const double Phi=1.61803398874989484820458683436563811;
    
    /*!
     * Número de decimales a mostrar cuando se imprime en pantalla o en archivo.
     * \ingroup DefinesGroup
    */
    const unsigned int StringPrecision=14;
    
    /*!
     * Valor máximo que puede tener rcond para mostrar un mensaje en pantalla.
     * \ingroup DefinesGroup
    */
    const double WarningRCond=0.000000001;
    
    /*!
     * Factor de conversión de grados a radianes.
     * \ingroup DefinesGroup
    */
    const double ToRadians =Pi/180.0;
    
    /*!
     * \brief Tipo de dato en la carga de información desde archivo.
     *
     * Cuando existe una carga de datos esta puede proceder de varios tipos de fuentes.
     * \ingroup DefinesGroup
    */
    typedef enum {
        /*!
         * Carga una matriz desde un archivo de texto.
         */
        LoadText=0  
    } LoadType;
    
}
}
/*!
 * @}
 */
    
    
#endif /* __PDS_RADEFINES_HPP__ */
