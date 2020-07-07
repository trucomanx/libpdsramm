/*
 * RaBmp.hpp
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

/** \file RaBmp.hpp
 *  \author Fernando Pujaico Rivera
 *  \brief Archivo de definición herramientas para a biblioteca Ra.
 *  
 */
    
    
#ifndef __PDS_RABMP_HPP__
#define __PDS_RABMP_HPP__
    
#include <string>
#include <cstdio>
#include <list>

/** \defgroup PdsRaBmpGroup Extras Pds::Ra -- BMP files
 *  \brief Funciones con archivos: Pds::Ra::ReadBmpHeader(), etc
 *  <div class="fragment"> \#include <Pds/RaBmp> </div>
 *  
 *  
 * @{
 */

//! Nombre de espacion para PDS (Procesamiento Digital de Senales)
namespace Pds{
/**
 *  \brief Nombre de espacio para RA (Real Arrays)
 *  \ingroup PdsRaBmpGroup
 */
namespace Ra{

typedef struct {             // Total: 54 bytes
    // Cabecera BMP 
  unsigned char  type[2];             // Magic identifier: 0x4d42
  uint32_t  size;             // File size in bytes
  uint16_t  reserved1;        // Not used
  uint16_t  reserved2;        // Not used
  uint32_t  offset;           // Offset to image data in bytes from beginning of file (54 bytes)
    // Encabezado DIB 
  uint32_t  dib_header_size;  // DIB Header size in bytes (40 bytes)
  int32_t   width_px;         // Width of the image
  int32_t   height_px;        // Height of image
  uint16_t  num_planes;       // Number of color planes
  uint16_t  bits_per_pixel;   // Bits per pixel
  uint32_t  compression;      // Compression type
  uint32_t  image_size_bytes; // Image size in bytes
  int32_t   x_resolution_ppm; // Pixels per meter
  int32_t   y_resolution_ppm; // Pixels per meter
  uint32_t  num_colors;       // Number of colors  
  uint32_t  important_colors; // Important colors 
} BmpHeader; // 54 bytes


/** @name Trabajar con archivos BMP
 *  Salva datos de matrices
 * @{
 */

    /** 
     *  \brief Retorna una estructura con los datos de cabecera de un archivo bmp.
     *
     *  \param[in] fd Descriptor del fichero de una rchivo BMP.
     *  \return Retorna una estructura con los datos de cabecera de un archivo bmp.
     *  \ingroup PdsRaBmpGroup
     */
    Pds::Ra::BmpHeader ReadBmpHeader(FILE *fd);

    /** 
     *  \brief Retorna una estructura con los datos de cabecera de un archivo bmp.
     *
     *  \param[in] filename Nombre completo de un archivo BMP.
     *  \return Retorna una estructura con los datos de cabecera de un archivo bmp.
     *  \ingroup PdsRaBmpGroup
     */
    Pds::Ra::BmpHeader ReadBmpHeader(const std::string &filename);

    /** 
     *  \brief Imprime los datos de una estructura con los datos de cabecera de un archivo bmp.
     *
     *  \param[in] Header Estructura con los datos de cabecera de un archivo bmp.
     *  \ingroup PdsRaBmpGroup
     */
    void PrintBmpHeader(Pds::Ra::BmpHeader Header);



/**
 * @}
 */

    
} // namespace Ra
} // namespace Pds


/**
 * @}
 */
    
#endif /* __PDS_RABMP_HPP__ */
