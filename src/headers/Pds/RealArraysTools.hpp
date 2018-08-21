/*
 * RealArraysTools.hpp
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

/** \file RealArraysTools.hpp
 *  \author Fernando Pujaico Rivera
 *  \brief Archivo de definición ferramentas para a biblioteca RealArrays.
 *  
 */
    
    
#ifndef __PDS_REALARRAYSTOOLS_HPP__
#define __PDS_REALARRAYSTOOLS_HPP__
    
#include <string>

/** \defgroup PdsRaToolsGroup Funciones genericas.
 *  \brief Funciones utiles para toda la biblioteca
 *  
 *  
 * @{
 */

//! Nombre de espacion para PDS (Procesamiento Digital de Senales)
namespace Pds{
/**
 *  \brief Nombre de espacion para RA (Real Arrays)
 *  \ingroup PdsRaToolsGroup
 */
namespace Ra{

/** @name Trabajar con cadenas de archivos
 *  Salva datos de matrices
 * @{
 */

/** 
 *  \brief Retorna el número de lineas significativas de un archivo.
 *  Se asume que es un archivo de texto.
 *
 *  Una linea no significativa solo contiene white-spaces:
\code{.h}
' '     (0x20)	space (SPC)
'\t'    (0x09)	horizontal tab (TAB)
'\n'    (0x0a)	newline (LF)
'\v'    (0x0b)	vertical tab (VT)
'\f'    (0x0c)	feed (FF)
'\r'    (0x0d)	carriage return (CR)
\endcode
 *  \param[in] filepath Dirección de archivo a testar.
 *  \return Retorna el número de lineas significativas de un archivo
 *  o negativo en caso de error
 *  \ingroup PdsRaToolsGroup
 */
long SignificativeLinesInFile(const char*filepath);


/** 
 *  \brief Retorna el número de elementos de un archivo.
 *  Se asume que es un archivo de texto.
 *
 *  Una un elemento e cualquier grupo de caracteres con elementos que no contienen white-spaces:
\code{.h}
' '     (0x20)	space (SPC)
'\t'    (0x09)	horizontal tab (TAB)
'\n'    (0x0a)	newline (LF)
'\v'    (0x0b)	vertical tab (VT)
'\f'    (0x0c)	feed (FF)
'\r'    (0x0d)	carriage return (CR)
\endcode
 *  \param[in] filepath Dirección de archivo a testar.
 *  \param[out] Nel Variable donde se guardara el numero de elementos.
 *  \return Retorna true si todo fue bien o false si no. Si fue retornado false
 *  entonces Nel no es modificado.
 *  \ingroup PdsRaToolsGroup
 */
bool ElementsInFile(const char*filepath,unsigned int &Nel);

/** 
 *  \brief Retorna el número de lineas significativas y columnas de un archivo.
 *  Se asume que es un archivo de texto.
 *
 *  Una linea no significativa solo contiene white-spaces:
\code{.h}
' '     (0x20)	space (SPC)
'\t'    (0x09)	horizontal tab (TAB)
'\n'    (0x0a)	newline (LF)
'\v'    (0x0b)	vertical tab (VT)
'\f'    (0x0c)	feed (FF)
'\r'    (0x0d)	carriage return (CR)
\endcode
 *  \param[in] filepath Dirección de archivo a testar.
 *  \param[out] Nlin Variable donde se guardara el numero de lineas.
 *  \param[out] Ncol Variable donde se guardara el numero de columnas.
 *  \return Retorna true si todo fue bien o false si no. Si el numero de columnas 
 *  no es constante entonces se retorna false. Si fue retornado false
 *  entonces Nlin y Ncol no son modificados. 
 *  \ingroup PdsRaToolsGroup
 */
bool ArraySizeInFile(const char*filepath,unsigned int &Nlin,unsigned int &Ncol);

//@}



/** @name Trabajar con cadenas de caracteres
 *  Salva datos de matrices
 * @{
 */

/**
 *  \brief Esta función comprueba si los caracteres en la cadena son caracteres
 *  no visibles (white-spaces).
 *
 *  Estos son:
\code{.h}
' '     (0x20)	space (SPC)
'\t'    (0x09)	horizontal tab (TAB)
'\n'    (0x0a)	newline (LF)
'\v'    (0x0b)	vertical tab (VT)
'\f'    (0x0c)	feed (FF)
'\r'    (0x0d)	carriage return (CR)
\endcode
 *  \param[in] cstr Cadena a leer.
 *  \return Retorna true si la cadena solo contiene white-spaces y false si no.
 *  \ingroup PdsRaToolsGroup
 */
bool IsSpace(const char *cstr);

/**
 *  \brief Esta función comprueba si los caracteres en la cadena son caracteres
 *  no visibles (white-spaces).
 *
 *  Estos son:
\code{.h}
' '     (0x20)	space (SPC)
'\t'    (0x09)	horizontal tab (TAB)
'\n'    (0x0a)	newline (LF)
'\v'    (0x0b)	vertical tab (VT)
'\f'    (0x0c)	feed (FF)
'\r'    (0x0d)	carriage return (CR)
\endcode
 *  \param[in] str Cadena a leer.
 *  \return Retorna true si la cadena solo contiene white-spaces y false si no.
 *  \ingroup PdsRaToolsGroup
 */
bool IsSpace(std::string str);

/**
 *  \brief Retorna el número de elementos en la cadena.
 *
 *  Un elemento es un grupo de caracteres consecutivos que no contienen white-spaces:
\code{.h}
' '     (0x20)	space (SPC)
'\t'    (0x09)	horizontal tab (TAB)
'\n'    (0x0a)	newline (LF)
'\v'    (0x0b)	vertical tab (VT)
'\f'    (0x0c)	feed (FF)
'\r'    (0x0d)	carriage return (CR)
\endcode
 *  
 *  Por ejemplo la siguiente cadena contiene 3 elementos ("abc", "104","de10j"):
\code{.h}
char str[]="abc  104\t\r\tde10j \n  ";
\endcode
 *  \param[in] cstr Cadena a testar.
 *  \return Retorna el número de elementos en la cadena o negativo en caso de error.
 *  \ingroup PdsRaToolsGroup
 */
int NumberOfElements(const char *cstr);

/**
 *  \brief Retorna el número de elementos en la cadena.
 *
 *  Un elemento es un grupo de caracteres consecutivos que no contienen white-spaces:
\code{.h}
' '     (0x20)	space (SPC)
'\t'    (0x09)	horizontal tab (TAB)
'\n'    (0x0a)	newline (LF)
'\v'    (0x0b)	vertical tab (VT)
'\f'    (0x0c)	feed (FF)
'\r'    (0x0d)	carriage return (CR)
\endcode
 *  
 *  Por ejemplo la siguiente cadena contiene 3 elementos ("abc", "104","de10j"):
\code{.h}
char str[]="abc  104\t\r\tde10j \n  ";
\endcode
 *  \param[in] str Cadena a testar.
 *  \return Retorna el número de elementos en la cadena o negativo en caso de error.
 *  \ingroup PdsRaToolsGroup
 */
int NumberOfElements(std::string str);

/**
 * @}
 */
    
} // namespace Ra
} // namespace Pds


/**
 * @}
 */
    
#endif /* __PDS_REALARRAYSTOOLS_HPP__ */
