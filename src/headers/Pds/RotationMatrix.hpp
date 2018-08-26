/*
 * RotationMatrix.hpp
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

/** \file RotationMatrix.hpp
 *  \author Fernando Pujaico Rivera
 *  \brief Funciones que trabajan con matrices.
 *  
 *  <br>Estas funciones trabajan con una matriz de la forma.<br>
 *  \image html matrix.png "Matriz de NlinxNcol"
 *  \b Nlin es el número de lineas y \b Ncol es el número de columnas.
 */



#ifndef __PDS_ROTATIONMATRIX_HPP__
#define __PDS_ROTATIONMATRIX_HPP__


/** \defgroup RotationMatrixGroup Funciones para Pds::Matrix - Rotacion.
 *  \brief Funciones que trabajan con rotaciones en 2D y 3D con matrices.
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

/** @name funciones para rotar coordenadas en 2 dimensines
 *  Descripción de algunas funciones que usan  Pds::Matrix.
 * @{
 */
    
    /** 
     *  \brief Retorna una matriz de rotación anti-horaria en 2 dimensiones.
     *
   \f[
\left(\begin{matrix}
cos(\theta)&-sin(\theta) \\ 
sin(\theta)&cos(\theta)
\end{matrix}\right)
   \f]
     *  \param[in] theta Ángulo de rotación anti-horaria en radianes.
     *  \return Retorna una matriz de rotación anti-horaria en 2 dimensiones.
     *  \ingroup RotationMatrixGroup
     */
    Matrix Rot2D(double theta);
    
    /** 
     *  \brief Retorna una matriz de rotación anti-horaria al rededor
     *  del eje X en 3 dimensiones.
     *
   \f[
\left(\begin{matrix}
1&0&0\\
0&cos(\theta)&-sin(\theta) \\ 
0&sin(\theta)&cos(\theta)
\end{matrix}\right)
   \f]
     *  \param[in] RadAngle Ángulo de rotación horaria en radianes.
     *  \return Retorna una matriz de rotación anti-horaria al rededor
     *  del eje X en 3 dimensiones.
     *  \ingroup RotationMatrixGroup
     */
    Matrix RotX(double RadAngle);
    
    /** 
     *  \brief Retorna una matriz de rotación anti-horaria al rededor
     *  del eje Y en 3 dimensiones.
     *
   \f[
\left(\begin{matrix}
cos(\theta)&0&sin(\theta)\\
0&1&0 \\ 
-sin(\theta)&0&cos(\theta)
\end{matrix}\right)
   \f]
     *  \param[in] RadAngle Ángulo de rotación horaria en radianes.
     *  \return Retorna una matriz de rotación anti-horaria al rededor
     *  del eje Y en 3 dimensiones.
     *  \ingroup RotationMatrixGroup
     */
    Matrix RotY(double RadAngle);
    
    /** 
     *  \brief Retorna una matriz de rotación anti-horaria al rededor
     *  del eje Z en 3 dimensiones.
     *
   \f[
\left(\begin{matrix}
cos(\theta)&-sin(\theta)&0\\
sin(\theta)&cos(\theta)&0 \\ 
0&0&1
\end{matrix}\right)
   \f]
     *  \param[in] RadAngle Ángulo de rotación horaria en radianes.
     *  \return Retorna una matriz de rotación anti-horaria al rededor
     *  del eje Z en 3 dimensiones.
     *  \ingroup RotationMatrixGroup
     */
    Matrix RotZ(double RadAngle);
/**
 * @}
 */

}
/**
 * @}
 */

#endif

