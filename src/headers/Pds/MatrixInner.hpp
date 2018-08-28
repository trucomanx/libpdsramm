/*
 * MatrixInner.hpp
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

/** \file MatrixInner.hpp
 *  \author Fernando Pujaico Rivera
 *  \date 01-04-2011
 *  \brief Funciones que trabajan con matrices.
 *  
 *  <br>Estas funciones trabajan con una matriz de la forma.<br>
 *  \image html matrix.png "Matriz de Nlinx1"
 *  \b Nlin es el número de lineas.
 */



#ifndef __PDS_MATRIXINNER_HPP__
#define __PDS_MATRIXINNER_HPP__


/** \defgroup MatrixInnerGroup Clase Pds::MatrixInner.
 *  \brief Metodos de la clase Pds::MatrixInner, una matriz que es un pedazo interno de otra matriz.
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

/*! \class MatrixInner
 *  \brief La clase tipo  MatrixInner .
 *  Esta clase genera una matriz de Nlin lineas y 1 columna.
 *  Para usar incluir Pds/MatrixInner.
 *  \ingroup MatrixInnerGroup
 *  \author Fernando Pujaico Rivera
 */
class MatrixInner: public Matrix
{

public:

/** @name Varios tipos de constructores
 *  Crean una objeto Pds::MatrixInner
 * @{
 */

    /** 
     *  \brief Crea un objeto de tipo Pds::MatrixInner
     *  \return un objeto de tipo Pds::MatrixInner.
     *  \ingroup MatrixInnerGroup
     */
    MatrixInner(void);
    
    /** 
     *  \brief Crea un objeto de tipo Pds::MatrixInner con un pedazo de la matriz A.
     *  A(lin_begin:lin_end,col_begin:col_end)
     *  \param[in] A La matriz a anlizar.
     *  \param[in] lin_begin La linea inicial.
     *  \param[in] lin_end La linea final.
     *  \param[in] col_begin La columna inicial.
     *  \param[in] col_end La columna final.
     *  \return un objeto de tipo Pds::MatrixInner.
     *  \ingroup MatrixInnerGroup
     */
    Pds::MatrixInner::MatrixInner(Pds::Matrix A, unsigned int lin_begin,unsigned int col_begin, unsigned int lin_end,unsigned int col_end);

    ~MatrixInner(); 
    
/**
 * @}
 */



}; // Class MatrixInner

typedef MatrixInner Vector;

} // namespace Pds


/*!
 * @}
 */

#endif

