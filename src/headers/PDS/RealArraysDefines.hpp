/*
 * RealArraysDefines.hpp
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

/** \file RealArraysDefines.hpp
 * \brief Archivo de definición de macro defines.
 * 
 */
    

/** \defgroup DefinesGroup Macro Defines.
 *  \brief Algunas macros interesantes.
 *  
 * @{
 */

    
#ifndef __PDS_REALARRAYSDEFINES_HPP__
#define __PDS_REALARRAYSDEFINES_HPP__
    
    
#ifndef print_error_message
/*!
 * \def print_error_message
 * Mensaje de error.
 * \ingroup DefinesGroup
*/
#define print_error_message(msg) \
    std::cout<<"----ERROR :: "<<__FILE__<<"::"<<__FUNCTION__<<"::line "<<__LINE__<<std::endl \
    <<"----ERROR :: "<<msg<<std::endl
#endif
    
    
#ifndef print_warning_message
/*!
 * \def print_warning_message
 * Mensaje de advertencia.
 * \ingroup DefinesGroup
*/
#define print_warning_message(msg) \
    std::cout<<"--WARNING :: "<<__FILE__<<"::"<<__FUNCTION__<<"::line "<<__LINE__<<std::endl \
    <<"--WARNING :: "<<msg<<std::endl
#endif
    
    
#ifndef print_info_message
/*!
 * \def print_info_message
 * Mensaje con informaciones genericas.
 * \ingroup DefinesGroup
*/
#define print_info_message(msg) \
    std::cout<<"-----INFO :: "<<msg<<std::endl
#endif


/*!
 * @}
 */

    
#endif /* __PDS_REALARRAYSDEFINES_HPP__ */
