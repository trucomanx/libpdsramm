/*
 * FuncMatrix.hpp
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

/** \file FuncMatrix.hpp
 *  \author Fernando Pujaico Rivera
 *  \brief Funciones que trabajan con matrices.
 *  
 *  <br>Estas funciones trabajan con una matriz de la forma.<br>
 *  \image html matrix.png "Matriz de NlinxNcol"
 *  \b Nlin es el número de lineas y \b Ncol es el número de columnas.
 */



#ifndef __PDS_FUNCMATRIX_HPP__
#define __PDS_FUNCMATRIX_HPP__


/** \defgroup FuncMatrixGroup Funciones para Pds::Matrix - basicos.
 *  \brief Funciones Eye, Ones, Zeros, X2D, Y2D, X3D, Y3D, Z3D.
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

/** @name funciones con matrices especiales
 *  Descripción de algunas funciones que usan  Pds::Matrix.
 * @{
 */

    /** 
     *  \brief Retorna una matriz con unos en la diagonal y el resto ceros.  
     *
     *  \param[in] N El numero de lineas y columnas de la matriz.
     *  \return Retorna la matriz o una matriz vacía en caso de error.
     *  \ingroup FuncMatrixGroup
     */
    Matrix Eye(unsigned int N);
    
    /** 
     *  \brief Retorna una matriz con unos.  
     *
     *  \param[in] Nlin El numero de lineas de la matriz.
     *  \param[in] Ncol El numero de columnas de la matriz.
     *  \return Retorna la matriz o una matriz vacía en caso de error.
     *  \ingroup FuncMatrixGroup
     */
    Matrix Ones(unsigned int Nlin, unsigned int Ncol);
    
    /** 
     *  \brief Retorna una matriz con unos.  
     *
     *  \param[in] N El numero de lineas y columnas de la matriz.
     *  \return Retorna la matriz o una matriz vacía en caso de error.
     *  \ingroup FuncMatrixGroup
     */
    Matrix Ones(unsigned int N);
    
    
    /** 
     *  \brief Retorna una matriz con ceros.  
     *
     *  \param[in] Nlin El numero de lineas de la matriz.
     *  \param[in] Ncol El numero de columnas de la matriz.
     *  \return Retorna la matriz o una matriz vacía en caso de error.
     *  \ingroup FuncMatrixGroup
     */
    Matrix Zeros(unsigned int Nlin, unsigned int Ncol);
    
    /** 
     *  \brief Retorna una matriz con ceros.  
     *
     *  \param[in] N El numero de lineas y columnas de la matriz.
     *  \return Retorna la matriz o una matriz vacía en caso de error.
     *  \ingroup FuncMatrixGroup
     */
    Matrix Zeros(unsigned int N);
    
/**
 * @}
 */

/** @name funciones para crear vectores eje en 2 dimensiones
 *  Descripción de algunas funciones que usan  Pds::Matrix.
 * @{
 */
    
    /** 
     *  \brief Retorna una matriz vector columna eje X en 2 dimensiones.
     *
   \f[
\left(\begin{matrix}
1 \\ 
0
\end{matrix}\right)
   \f]
     *  \return Retorna una matriz vector columna eje X en 2 dimensiones.
     *  \ingroup FuncMatrixGroup
     */
    Matrix X2D(void);
    
    /** 
     *  \brief Retorna una matriz vector columna eje Y en 2 dimensiones.
     *
   \f[
\left(\begin{matrix}
0 \\ 
1
\end{matrix}\right)
   \f]
     *  \return Retorna una matriz vector columna eje Y en 2 dimensiones.
     *  \ingroup FuncMatrixGroup
     */
    Matrix Y2D(void);
/**
 * @}
 */

/** @name funciones para crear vectores eje en 3 dimensiones
 *  Descripción de algunas funciones que usan  Pds::Matrix.
 * @{
 */
    
    /** 
     *  \brief Retorna una matriz vector columna eje X en 3 dimensiones.
     *
   \f[
\left(\begin{matrix}
1 \\ 
0 \\
0
\end{matrix}\right)
   \f]
     *  \return Retorna una matriz vector columna eje X en 3 dimensiones.
     *  \ingroup FuncMatrixGroup
     */
    Matrix X3D(void);
    
    /** 
     *  \brief Retorna una matriz vector columna eje Y en 3 dimensiones.
     *
   \f[
\left(\begin{matrix}
0 \\ 
1 \\
0
\end{matrix}\right)
   \f]
     *  \return Retorna una matriz vector columna eje Y en 3 dimensiones.
     *  \ingroup FuncMatrixGroup
     */
    Matrix Y3D(void);
    
    /** 
     *  \brief Retorna una matriz vector columna eje Z en 3 dimensiones.
     *
   \f[
\left(\begin{matrix}
0 \\ 
0 \\
1
\end{matrix}\right)
   \f]
     *  \return Retorna una matriz vector columna eje Z en 3 dimensiones.
     *  \ingroup FuncMatrixGroup
     */
    Matrix Z3D(void);
/**
 * @}
 */


}
/**
 * @}
 */

#endif

