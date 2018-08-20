/*
 * ColVector.hpp
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

/** \file ColVector.hpp
 *  \author Fernando Pujaico Rivera
 *  \date 01-04-2011
 *  \brief Funciones que trabajan con matrices.
 *  
 *  <br>Estas funciones trabajan con una matriz de la forma.<br>
 *  \image html matrix.png "Matriz de Nlinx1"
 *  \b Nlin es el número de lineas.
 */



#ifndef __PDS_COLVECTOR_HPP__
#define __PDS_COLVECTORss_HPP__


/** \defgroup ColVectorGroup Módulo ColVector.
 *  \brief Funciones que trabajan con matrices/vectores columna.
 *  
 *  <br>Estas funciones trabajan con una matriz de la forma.<br>
 *  <center>
 *  \image html matrix.png "Matriz"
 *  </center>
 *  \b nlin es el número de lineas.
 *  
 * Informacion adicional puede ser encontrada en @cite tutorialmatvec
 * @{
 */


#include <Pds/Matrix>

namespace Pds{

/*! \class ColVector
 *  \brief La clase tipo  ColVector .
 *  Esta clase genera una matriz de Nlin lineas y 1 columna.
 *  Para usar incluir Pds/ColVector.
 *  \ingroup ColVectorGroup
 *  \author Fernando Pujaico Rivera
 */
class ColVector: public Matrix
{

public:

/** @name Varios tipos de constructores
 *  Crean una objeto Pds::ColVector
 * @{
 */

    /** 
     *  \brief Crea un objeto de tipo Pds::ColVector
     *  \return un objeto de tipo Pds::ColVector.
     *  \ingroup ColVectorGroup
     */
    ColVector(void);
    
    /** 
     *  \brief Crea un objeto de tipo Pds::ColVector
     *  \param[in] N El numero de lineas de la matriz.
     *  \return un objeto de tipo Pds::ColVector.
     *  \ingroup ColVectorGroup
     */
    ColVector(unsigned int N);

    ~ColVector(); 
    
/**
 * @}
 */



}; // Class ColVector

typedef ColVector Vector;

} // namespace Pds


/*!
 * @}
 */

#endif

