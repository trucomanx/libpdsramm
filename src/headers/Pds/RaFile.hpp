/*
 * RaFile.hpp
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

/** \file RaFile.hpp
 *  \author Fernando Pujaico Rivera
 *  \brief Archivo de definición herramientas para a biblioteca Ra.
 *  
 */
    
    
#ifndef __PDS_RAFILE_HPP__
#define __PDS_RAFILE_HPP__
    
#include <string>
#include <cstdio>
#include <list>

/** \defgroup PdsRaFileGroup Extras Pds::Ra -- File
 *  \brief Funciones con archivos: Pds::Ra::ElementsInFile(), etc
 *  <div class="fragment"> \#include <Pds/RaFile> </div>
 *  
 *  
 * @{
 */

//! Nombre de espacion para PDS (Procesamiento Digital de Senales)
namespace Pds{
/**
 *  \brief Nombre de espacio para RA (Real Arrays)
 *  \ingroup PdsRaFileGroup
 */
namespace Ra{


/** @name Trabajar con archivos
 *  Salva datos de matrices
 * @{
 */

    /** 
     *  \brief std::string con un separador de fichero "\\" para WINDOWS y "/" para linux.
     *
     *  \ingroup PdsRaFileGroup
     */
    const std::string FileSep =
    #if defined(WIN32) || defined(_WIN32) 
                                "\\";
    #else
                                "/";
    #endif
    
    /** 
     *  \brief std::string con un separador de fichero "\\" para WINDOWS y "/" para linux.
     *
     *  \ingroup PdsRaFileGroup
     */
    const char CharFileSep =
    #if defined(WIN32) || defined(_WIN32) 
                                '\\';
    #else
                                '/';
    #endif
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
     *  \ingroup PdsRaFileGroup
     */
    long SignificativeLinesInFile(const std::string &filepath);


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
     *  \ingroup PdsRaFileGroup
     */
    bool ElementsInFile(const std::string &filepath,unsigned int &Nel);

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
     *  \ingroup PdsRaFileGroup
     */
    bool ArraySizeInFile(const std::string &filepath,unsigned int &Nlin,unsigned int &Ncol);

    /** 
     *  \brief Retorna una linea leida desde un desriptor de fichero de texto.
     *  No descarta el salto de linea '\\n' y no descarta 1 retorno de carro '\\r' 
     *  si este existe depues del salto de linea.
     *
     *  \param[in] fd Descriptor de fichero de texto a analizar.
     *  \return Retorna una nueva cadena de texto con una copia de la linea leida 
     *  incluyendo los caracteres de control finales exepto EOF.
     *  \ingroup PdsRaFileGroup
     */
    char *Fgets(FILE *fd);
    
    /** 
     *  \brief Retorna una nueva cadena con un filepath creado por la union de 
     *  las cadenas de entrada, usando para concatenar Pds::Ra::FileSep.
     *
    \code{.h}
     std::string str_out=FullFile({"/usr","share","program_name","icons"});
     std::cout<<str_out<<std::endl;
    \endcode
     *  
     *  \param[in] str_text_list Lista de argumentos a concatenar.
     *  \return Retorna una nueva cadena con un filepath creado por la union de 
     *  las cadenas de entrada, usando para concatenar Pds::Ra::FileSep.
     *  \ingroup PdsRaFileGroup
     */
    std::string FullFile( std::initializer_list<std::string> str_text_list );

    /** \brief Retorna una nueva cadena de texto con la dirección del directorio de 
     *  usuario. HOME en gnu-linux y {HOMEDRIVE,HOMEPATH} en Windows.
     *  \return Retorna el directorio de usuario o NULL en caso de problemas en la
     *  reserva de memoria.
     *  \ingroup PdsRaFileGroup
     */
    std::string HomeDir(void);
    
    /** \brief Retorna un std::string con la ruta del programa que lo invoca.
     *  \return Retorna un std::string con la ruta del programa que lo invoca.
     *  \ingroup PdsRaFileGroup
     */
    std::string Programpath(void);
    
    /** \brief Retorna un std::string con la ruta actual.
     *  \return Retorna un std::string con la ruta actual.
     *  \ingroup PdsRaFileGroup
     */
    std::string Pwd(void);

    /** \brief Retorna un std::string con el directorio de un filepath.
     *
    \code{.h}
     std::string filepath="/usr/share/program_name/icons/image.png";
     std::cout<<Pds::Ra::Dirname(filepath)<<std::endl;
    \endcode
     * Retorna:
    \code{.sh}
     /usr/share/program_name/icons
    \endcode
     *  \return Retorna un std::string con el directorio de un filepath.
     *  \ingroup PdsRaFileGroup
     */
    std::string Dirname(std::string filepath);
    
    /** \brief Retorna un std::string con el basename de un filepath.
     *
    \code{.h}
     std::string filepath="/usr/share/program_name/icons/image.png";
     std::cout<<Pds::Ra::Basename(filepath)<<std::endl;
    \endcode
     * Retorna:
    \code{.sh}
     image.png
    \endcode
     *  \return Retorna un std::string con el basename de un filepath.
     *  \ingroup PdsRaFileGroup
     */
    std::string Basename(std::string filepath);
    
    /** \brief Retorna un std::string con el extension de un filepath.
     *
    \code{.h}
     std::string filepath="/usr/share/program_name/icons/image.png";
     std::cout<<Pds::Ra::Extension(filepath)<<std::endl;
    \endcode
     * Retorna:
    \code{.sh}
    .png
    \endcode
     *  \return Retorna un std::string con el extension de un filepath.
     *  \ingroup PdsRaFileGroup
     */
    std::string Extension(std::string filepath);
    
    /** \brief Retorna un std::string con el filename de un filepath.
     *
    \code{.h}
     std::string filepath="/usr/share/program_name/icons/image.png";
     std::cout<<Pds::Ra::Filename(filepath)<<std::endl;
    \endcode
     * Retorna:
    \code{.sh}
    image
    \endcode
     *  \return Retorna un std::string con el filename de un filepath.
     *  \ingroup PdsRaFileGroup
     */ 
    std::string Filename(std::string filepath);
    
    /** \brief Retorna un std::string con un filepath con otra extension de un filepath.
     *
    \code{.h}
     std::string filepath="/usr/share/program_name/icons/image.png";
     std::cout<<Pds::Ra::ReplaceExtension(filepath,".bmp")<<std::endl;
    \endcode
     * Retorna:
    \code{.sh}
    /usr/share/program_name/icons/image.bmp
    \endcode
     *  \return Retorna un std::string con un filepath con otra extension de un filepath.
     *  \ingroup PdsRaFileGroup
     */ 
    std::string ReplaceExtension(std::string filepath,std::string new_ext);
    
    /** \brief Retorna true si es un fichero existenteste (simbólico o real) no directorio, 
     * o false si no.
     *
     *  \param[in] path Dirección de fichero a testar.
     *  \return Retorna true si es un fichero existenteste (simbólico o real) no directorio, 
     * o false si no.
     *  \ingroup PdsRaFileGroup
     */
    bool IsFile(std::string path);
    
    /** \brief Retorna true si es un directorio existenteste (simbólico o real) no fichero, 
     * o false si no.
     *
     *  \param[in] path Dirección de directorio a testar.
     *  \return Retorna true si es un directorio existenteste (simbólico o real) no fichero, 
     * o false si no.
     *  \ingroup PdsRaFileGroup
     */
    bool IsDir(std::string path);
    
    /** \brief Obtiene el dato de tipo std::string que va después del 
     *  parámetro param en una cadena de parámetros argv de argc elementos. si el 
     *  parámetro param no es encontrado la función retorna default_data. 
     *  Si existen parámetros data repetidos, solo se atiende al primero.
    \code{.h}
    std::string data;
    std::string default_data="/home/user/data.dat";
    data=GetParamString(argc,argv,"--input-file",default_data);
    \endcode
     *  \retu
     *  \param[in] argc Cantidad de elementos de argv.
     *  \param[in] argv Cadenas de caracteres con  parámetros de entrada.
     *  \param[in] param Parametro a buscar en las cadenas argv.
     *  \param[in] default_data Dato por defecto. 
     *  \return El dato correspondiente ou default_data.
     *  \ingroup PdsRaFileGroup
     */
    std::string GetParamString( int argc,
                                char* const argv[],
                                std::string param,
                                std::string default_data);
                                

    /** \brief Retorna true si existe el parámetro param.
     *  \param[in] argc Cantidad de elementos de argv.
     *  \param[in] argv Cadenas de caracteres con  parámetros de entrada.
     *  \param[in] param Dato a buscar en las cadenas argv.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup PdsRaFileGroup
     */
    bool ExistParam(int argc, char* const argv[], std::string param);

/**
 * @}
 */

    
} // namespace Ra
} // namespace Pds


/**
 * @}
 */
    
#endif /* __PDS_RAFILE_HPP__ */
