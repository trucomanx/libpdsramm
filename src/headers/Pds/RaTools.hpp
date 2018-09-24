/*
 * RaTools.hpp
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

/** \file RaTools.hpp
 *  \author Fernando Pujaico Rivera
 *  \brief Archivo de definición herramientas para a biblioteca Ra.
 *  
 */
    
    
#ifndef __PDS_RATOOLS_HPP__
#define __PDS_RATOOLS_HPP__
    
#include <string>
#include <list>


/** \defgroup PdsRaToolsGroup Funciones con namespace Pds::Ra -- Útiles
 *  \brief Funciones con cadenas y archivos: Pds::Ra::ElementsInFile(), Pds::Ra::ToString(), etc
 *  <div class="fragment"> \#include <Pds/RaTools> </div>
 *  
 *  
 * @{
 */

//! Nombre de espacion para PDS (Procesamiento Digital de Senales)
namespace Pds{
/**
 *  \brief Nombre de espacio para RA (Real Arrays)
 *  \ingroup PdsRaToolsGroup
 */
namespace Ra{


/** @name Datos de la biblioteca
 *  Datos importantes de la biblioteca.
 * @{
 */

/** 
 *  \brief Retorna la versión de la biblioteca.
 *
 *  Given a version number MAJOR.MINOR.PATCH, increment the:
 *
 *  - MAJOR version when you make incompatible API changes,
 *  - MINOR version when you add functionality in a backwards-compatible manner, and
 *  - PATCH version when you make backwards-compatible bug fixes.
 *
 *  \return Retorna la versión de la biblioteca.
 *  \ingroup PdsRaToolsGroup
 */
std::string Version(void);


/** 
 *  \brief Imprime em pantalla la versión de la biblioteca, imprime un salto de linea al final.
 *
 *  \param[in] str Texto a mostrar antes de la version
 *  \ingroup PdsRaToolsGroup
 */
void PrintVersion(std::string str);

/** 
 *  \brief Retorna el nombre de la biblioteca.
 *
 *  \return Retorna el nombre de la biblioteca.
 *  \ingroup PdsRaToolsGroup
 */
std::string Package(void);


/** 
 *  \brief Imprime em pantalla el nombre de la biblioteca, imprime un salto de linea al final.
 *
 *  \param[in] str Texto a mostrar antes del nombre
 *  \ingroup PdsRaToolsGroup
 */
void PrintPackage(std::string str);
/**
 * @}
 */

/** @name Trabajar con archivos
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


/**
 * @}
 */



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
 *  \param[in] str Cadena a leer.
 *  \return Retorna true si la cadena solo contiene white-spaces y false si no.
 *  \ingroup PdsRaToolsGroup
 */
bool IsSpacesString(const std::string &str);


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
 * 
\code{.h}
char str[]="abc  104\t\r\tde10j \n  ";
\endcode
 *  \param[in] str Cadena a testar.
 *  \return Retorna el número de elementos en la cadena o negativo en caso de error.
 *  \ingroup PdsRaToolsGroup
 */
int ElementsInString(const std::string &str);



/**
 *  \brief Retorna una lista con los elementos en la cadena.
 *  
 *  Por ejemplo la siguiente cadena contiene 3 elementos ("abc", "104","de10j"):
\code{.h}
char str[]="abc;104\tde10j";

std::list<std::string> token=Pds::Ra::SplitString(str,"\t;,");
\endcode
 *  \param[in] str Cadena a dividir.
 *  \param[in] delimeters Cadena con posibles delimitadores.
 *  \return Retorna una lista con los elementos separados por alguno de los delimitadores.
 *  \ingroup PdsRaToolsGroup
 */
std::list<std::string> SplitString(std::string str, std::string delimeters);

/**
 *  \brief Convierte en std::sring un int,long,unsigned int, unsigned long, float o double.
 *  
 *  \param[in] val El elemento a convertir en std::string.
 *  \return Retorna el valor convertido en std::string.
 *  \ingroup PdsRaToolsGroup
 */
template  <typename T>
extern std::string ToString(T val);


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
 *  \param[in] str Cadena a leer.
 *  \param[out] Nlin Variable donde se guardara el numero de lineas.
 *  \param[out] Ncol Variable donde se guardara el numero de columnas.
 *  \return Retorna true si todo fue bien o false si no. Si el numero de columnas 
 *  no es constante entonces se retorna false. Si fue retornado false
 *  entonces Nlin y Ncol no son modificados. 
 *  \ingroup PdsRaToolsGroup
 */
bool ArraySizeInString(std::string str,unsigned int &Nlin,unsigned int &Ncol);


/**
 *  \brief Save the string in a text file
 *  
 *  Por ejemplo:
\code{.h}
std::string str="abc;104\tde10j";

if(Pds::Ra::SaveString("filedat.txt",str))   sdt::cout<<"All OK\n";
else                                         std::cout<<"Error saving the file\n";
\endcode
 *  \param[in] filepath Direccion y nombre del archivo donde se escribira la cadena.
 *  \param[in] str Cadena a escribir.
 *  \return Retorna true si todo salio bien o false en caso de error.
 *  \ingroup PdsRaToolsGroup
 */
bool SaveString(std::string filepath, std::string str);
/**
 * @}
 */

/** @name Variados
 *  Funciones interesantes
 * @{
 */

/**
 *  \brief Indica si es big endian
 *  
 *  \return Retorna true es bigendian o false en caso contrario.
 *  \ingroup PdsRaToolsGroup
 */
bool IsBigEndian(void);

/**
 * @}
 */
    
} // namespace Ra
} // namespace Pds


/**
 * @}
 */
    
#endif /* __PDS_RATOOLS_HPP__ */
