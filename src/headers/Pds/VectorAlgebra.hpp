/*
 * VectorAlgebra.hpp
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

/** \file VectorAlgebra.hpp
 *  \author Fernando Pujaico Rivera
 *  \brief Funciones que trabajan con vectores.
 *  
 *  <br>Estas funciones trabajan con una vector de la forma.<br>
 *  \image html vecto.png "Matriz de NlinxNcol"
 *  \b Nlin es el número de lineas y \b Ncol es el número de columnas.
 */



#ifndef __PDS_VECTORALGEBRA_HPP__
#define __PDS_VECTORALGEBRA_HPP__


/** \defgroup VectorAlgebraGroup Clase Pds::Vector :: Funciones Algebraicas.
 *  \brief Funciones PolyMat 
 *  <div class="fragment"> \#include <Pds/VectorAlgebra> </div>
 *  
 *  <br>Estas funciones trabajan con una matriz de la forma.<br>
   \f[
\left(\begin{matrix}
a_{0} \\ 
a_{1} \\
... \\
a_{Nlin-1} 
\end{matrix}\right)
   \f]
 *  
 * Informacion adicional puede ser encontrada en @cite tutorialmatvec
 * @{
 */


#include <Pds/Vector>
#include <Pds/Matrix>
#include <Pds/RaDefines>

namespace Pds{


/** @name funciones para polinomios
 *  Descripción de algunas funciones que usan  Pds::Vector.
 * @{
 */
    
    /** 
     *  \brief Retorna la Matriz de Vandermonde del vector X de M elementos.
     *
   \f[
\left(\begin{matrix}
1 & x_0^1 x_0^2   & ... &  x_0^{N-1} & x_0^N \\
1 & x_1^1 x_1^2   & ... &  x_1^{N-1} & x_1^N \\
\hdots & \hdots    & ... & \hdots & \hdots & \hdots \\ 
1 & x_{M-1}^1 x_{M-1}^2   & ... &  x_{M-1}^{N-1} & x_{M-1}^N \\
\end{matrix}\right)
   \f]
     *  \param[in] X Vector a evaluar.
     *  \param[in] N Orden del polinomio.
     *  \return Retorna una matriz con el resultado.
     *  \ingroup VectorAlgebraGroup
     */
    Pds::Matrix PolyMat(Vector X, unsigned int N);
    
    /** 
     *  \brief Retorna Un polinomio de grado N con el menor error
     *  cuadrático medio para el par X e Y.
     *
   \f[
A=\left(\begin{matrix}
X^0 &  X^1  & X^2  & ... & X^{N-1} & X^N \\
\end{matrix}\right)
   \f]
   \f[
P \leftarrow (A^T A )^{-1}A^T Y
   \f]
     *  \param[in] X Vector a evaluar.
     *  \param[in] Y Vector a evaluar.
     *  \param[in] N Orden del polinomio.
     *  \return Retorna el polinomio de grado N con el menor error
     *  cuadrático medio para el par X e Y.
     *  \ingroup VectorAlgebraGroup
     */
    Pds::Vector PolyFit(Pds::Vector X, Pds::Vector Y, unsigned int N);
    
    /** 
     *  \brief Retorna El resultado de evaluar un polinomio P de grado N.
     *
   \f[
y= p_0 x^0 + p_1 x^1 + p_2 x^2 + ... + p_{N-1} x^{N-1} + p_{N} x^N 
   \f]
   \f[
Y= P(X)
   \f]
     *  \param[in] P Polinomio a evaluar.
     *  \param[in] X Vector a evaluar.
     *  \return Retorna Y=P(X).
     *  \ingroup VectorAlgebraGroup
     */
    Pds::Vector PolyVal(Pds::Vector P,Pds::Vector X);
/**
 * @}
 */



}
/**
 * @}
 */

#endif
