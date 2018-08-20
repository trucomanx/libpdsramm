/*
 * Ones.hpp
 * 
 * Copyright 2011 Fernando Pujaico Rivera <fernando.pujaico.rivera@gmail.com>
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

/** \file Ones.hpp
 *  \author Fernando Pujaico Rivera
 *  \date 01-04-2011
 *  \brief Funciones que trabajan con matrices.
 *  
 *  <br>Estas funciones trabajan con una matriz de la forma.<br>
 *  \image html matrix.png "Matriz de NlinxNcol"
 *  \b Nlin es el número de lineas y \b Ncol es el número de columnas.
 */



#ifndef __PDS_ONES_HPP__
#define __PDS_ONES_HPP__


/** \defgroup OnesGroup Módulo Matrix: Ones.
 *  \brief Funciones que trabajan con matrices.
 *  
 *  <br>Estas funciones trabajan con una matriz de la forma.<br>
 *  <center>
 *  \image html matrix.png "Matriz"
 *  </center>
 *  \b nlin es el número de lineas y \b ncol es el número de columnas.
 *  
 * Informacion adicional puede ser encontrada en @cite tutorialmatvec
 * @{
 */


#include <Pds/Matrix>

namespace Pds{

/*! \class Ones
 *  \brief La clase tipo  Ones .
 *  Esta clase genera una matriz de Nlin lineas y Ncol columnas.
 *  Para usar incluir Pds/Ones.
 *  \ingroup OnesGroup
 *  \author Fernando Pujaico Rivera
 */
class Ones: public Matrix
{

public:

/** @name Varios tipos de constructores
 *  Crean una objeto Pds::Ones
 * @{
 */

    /** 
     *  \brief Crea un objeto de tipo Pds::Ones
     *  \return un objeto de tipo Pds::Ones.
     *  \ingroup OnesGroup
     */
    Ones(void);

    /** 
     *  \brief Crea un objeto de tipo Pds::Ones
     *  \param[in] Nlin El numero de lineas de la matriz.
     *  \param[in] Ncol El numero de columnas de la matriz.
     *  \return un objeto de tipo Pds::Ones.
     *  \ingroup OnesGroup
     */
    Ones(unsigned int Nlin,unsigned int Ncol);
    
    /** 
     *  \brief Crea un objeto de tipo Pds::Ones
     *  \param[in] N El numero de lineas y columnas de la matriz.
     *  \return un objeto de tipo Pds::Ones.
     *  \ingroup OnesGroup
     */
    Ones(unsigned int N);

    ~Ones(); 
    
/**
 * @}
 */



}; // Class Ones


} // namespace Pds


/*!
 * @}
 */

#endif

