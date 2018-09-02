/*
 * Vector.hpp
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

/** \file Vector.hpp
 *  \author Fernando Pujaico Rivera
 *  \date 01-04-2011
 *  \brief Funciones que trabajan con matrices columna.
 *  
 *  <br>Estas funciones trabajan con una matriz de la forma.<br>
 *  \image html matrix.png "Matriz de Nlinx1"
 *  \b Nlin es el número de lineas.
 */



#ifndef __PDS_VECTOR_HPP__
#define __PDS_VECTOR_HPP__


/** \defgroup VectorGroup Clase Pds::Vector.
 *  \brief Metodos de la clase Pds::Vector, un vector columna/matriz 
 *  <div class="fragment"> \#include <Pds/Vector> </div>
 *  
 *  <br>Estas funciones trabajan con una matriz de la forma.<br>
   \f[
\mathbf{A}=\left(\begin{matrix}
a_{00}  \\ 
a_{10}  \\
\vdots  \\
a_{(Nlin-2)0}  \\ 
a_{(Nlin-1)0} \\
\end{matrix}\right)\equiv A_{(Nlin-1),1}
   \f]
   \f[
A_{(Nlin-1),1}\equiv [a_{ij}]_{(Nlin-1),1}
   \f]
 *  \b nlin es el número de lineas.
 *  
 * Informacion adicional puede ser encontrada en @cite tutorialmatvec
 * @{
 */


#include <Pds/Matrix>

namespace Pds{

/*! \class Vector
 *  \brief La clase tipo  Vector .
 *  Esta clase genera una matriz de Nlin lineas y 1 columna.
 *  Para usar incluir Pds/Vector.
 *  \ingroup VectorGroup
 *  \author Fernando Pujaico Rivera
 */
class Vector: public Matrix
{

public:

/** @name Varios tipos de constructores
 *  Crean una objeto Pds::Vector
 * @{
 */

    /** 
     *  \brief Crea un objeto de tipo Pds::Vector
     *  \return un objeto de tipo Pds::Vector.
     *  \ingroup VectorGroup
     */
    Vector(void);
    
    /** 
     *  \brief Crea un objeto de tipo Pds::Vector
     *  \param[in] N El numero de lineas de la matriz.
     *  \return un objeto de tipo Pds::Vector.
     *  \ingroup VectorGroup
     */
    Vector(unsigned int N);

    ~Vector(); 
    
/**
 * @}
 */



}; // Class Vector

typedef Vector Vector;

} // namespace Pds


/*!
 * @}
 */

#endif

