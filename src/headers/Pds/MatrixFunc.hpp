/*
 * MatrixFunc.hpp
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

/** \file MatrixFunc.hpp
 *  \author Fernando Pujaico Rivera
 *  \brief Funciones que trabajan con matrices.
 *  
 *  <br>Estas funciones trabajan con una matriz de la forma.<br>
 *  \image html matrix.png "Matriz de NlinxNcol"
 *  \b Nlin es el número de lineas y \b Ncol es el número de columnas.
 */



#ifndef __PDS_MATRIXFUNC_HPP__
#define __PDS_MATRIXFUNC_HPP__


/** \defgroup MatrixFuncGroup Clase Pds::Matrix :: Funciones básicas.
 *  \brief Funciones Diag, Eye, Ones, Zeros, etc 
 *  <div class="fragment"> \#include <Pds/MatrixFunc> </div>
 *  
 *  <br>Estas funciones trabajan con una matriz de la forma.<br>
   \f[
\mathbf{A}=\left(\begin{matrix}
a_{00} & a_{01} & \hdots & a_{0(Ncol-1)}\\ 
a_{10} & a_{11} & \hdots & a_{1(Ncol-1)}\\
\vdots & \vdots & \vdots & \vdots \\
a_{(Nlin-2)0} & a_{(Nlin-2)1} & \hdots & a_{(Nlin-2)(Ncol-1)}\\ 
a_{(Nlin-1)0} & a_{(Nlin-1)1} & \hdots & a_{(Nlin-1)(Ncol-1)}\\
\end{matrix}\right)\equiv A_{(Nlin-1),(Ncol-1)}
   \f]
   \f[
A_{(Nlin-1),(Ncol-1)}\equiv [a_{i,j}]_{(Nlin-1),(Ncol-1)}
   \f]
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
     *  \brief Crea una matriz con datos correspondentes ao Id de cada elemento.
     *  \param[in] N Número de lineas y columnas.
     *  \return Retorna una matriz no vacía si todo fue bien o una matriz vacía en caso de error.
     *  \ingroup MatrixFuncGroup
     */
    Matrix MatrixId(unsigned int N);
   
   /** 
     *  \brief Crea una matriz con datos correspondentes ao Id de cada elemento.
     *  \param[in] S Tamaño de la matriz.
     *  \return Retorna una matriz no vacía si todo fue bien o una matriz vacía en caso de error.
     *  \ingroup MatrixFuncGroup
     */
    Matrix MatrixId(const Pds::Size &S);
   
   /** 
     *  \brief Crea una matriz con datos correspondentes ao Id de cada elemento.
     *  \param[in] Nlin Número de lineas.
     *  \param[in] Ncol Número de columnas.
     *  \return Retorna una matriz no vacía si todo fue bien o una matriz vacía en caso de error.
     *  \ingroup MatrixFuncGroup
     */
    Matrix MatrixId(unsigned int Nlin,unsigned int Ncol);
    
   /** 
     *  \brief Crea una matriz con datos aleatorios con distribución Normal
     *  de media cero 0.0 y desvío padrón 1.0.
     *  \param[in] N Número de lineas y columnas.
     *  \return Retorna una matriz no vacía si todo fue bien o una matriz vacía en caso de error.
     *  \ingroup MatrixFuncGroup
     */
    Matrix RandN(unsigned int N);
   
   /** 
     *  \brief Crea una matriz con datos aleatorios con distribución Normal
     *  de media cero 0.0 y desvío padrón 1.0.
     *  \param[in] S Tamaño de la matriz.
     *  \return Retorna una matriz no vacía si todo fue bien o una matriz vacía en caso de error.
     *  \ingroup MatrixFuncGroup
     */
    Matrix RandN(const Pds::Size &S);
   
   /** 
     *  \brief Crea una matriz con datos aleatorios con distribución Normal
     *  de media cero 0.0 y desvío padrón 1.0.
     *  \param[in] Nlin Número de lineas.
     *  \param[in] Ncol Número de columnas.
     *  \return Retorna una matriz no vacía si todo fue bien o una matriz vacía en caso de error.
     *  \ingroup MatrixFuncGroup
     */
    Matrix RandN(unsigned int Nlin,unsigned int Ncol);
    
   /** 
     *  \brief Crea una matriz con datos aleatorios uniformemente distribuidos entre 0.0 y 1.0.
     *  \param[in] N Número de lineas y columnas.
     *  \return Retorna una matriz no vacía si todo fue bien o una matriz vacía en caso de error.
     *  \ingroup MatrixFuncGroup
     */
    Matrix RandU(unsigned int N);
    
   /** 
     *  \brief Crea una matriz con datos aleatorios uniformemente distribuidos entre 0.0 y 1.0.
     *  \param[in] S Tamaño de la matriz.
     *  \return Retorna una matriz no vacía si todo fue bien o una matriz vacía en caso de error.
     *  \ingroup MatrixFuncGroup
     */
    Matrix RandU(const Pds::Size &S);
    
   /** 
     *  \brief Crea una matriz con datos aleatorios uniformemente distribuidos entre 0.0 y 1.0.
     *  \param[in] Nlin Número de lineas.
     *  \param[in] Ncol Número de columnas.
     *  \return Retorna una matriz no vacía si todo fue bien o una matriz vacía en caso de error.
     *  \ingroup MatrixFuncGroup
     */
    Matrix RandU(unsigned int Nlin,unsigned int Ncol);
    
    /** 
     *  \brief Retorna una matriz diagonal usando los dats de tra matriz,
     *  se lee primero todos los elementos de una columna y lueg se pasa a la
     *  siguiente
     *
   \f[
\left(\begin{matrix}
a_{00} & 0 & 0 & 0\\ 
0 & a_{10} & 0 & 0\\
0 & 0 & a_{01} & 0\\
0 & 0 & 0 & a_{11}
\end{matrix}\right)
\leftarrow A=\left(\begin{matrix}
a_{00} & a_{01} \\ 
a_{10} & a_{11} 
\end{matrix}\right)
   \f]
     *  \param[in] A La matriz donde se extraen los datos.
     *  \return Retorna la matriz diagonal.
     *  \ingroup MatrixFuncGroup
     */
    Matrix Diag(Matrix A);

    /** 
     *  \brief Retorna una matriz con unos en la diagonal y el resto ceros.  
     *
   \f[
\left(\begin{matrix}
1 & 0 & 0 & 0\\ 
0 & 1 & 0 & 0\\
0 & 0 & 1 & 0\\
0 & 0 & 0 & 1
\end{matrix}\right)
   \f]
     *  \param[in] N El numero de lineas y columnas de la matriz.
     *  \return Retorna la matriz o una matriz vacía en caso de error.
     *  \ingroup MatrixFuncGroup
     */
    Matrix Eye(unsigned int N);
    
    /** 
     *  \brief Retorna una matriz con unos.  
     *
   \f[
\left(\begin{matrix}
1 & 1 & 1 & 1\\ 
1 & 1 & 1 & 1\\
1 & 1 & 1 & 1\\
1 & 1 & 1 & 1
\end{matrix}\right)
   \f]
     *  \param[in] S El tamaño de la matriz.
     *  \return Retorna la matriz o una matriz vacía en caso de error.
     *  \ingroup MatrixFuncGroup
     */
    Matrix Ones(const Pds::Size &S);
    
    /** 
     *  \brief Retorna una matriz con unos.  
     *
   \f[
\left(\begin{matrix}
1 & 1 & 1 & 1\\ 
1 & 1 & 1 & 1\\
1 & 1 & 1 & 1\\
1 & 1 & 1 & 1
\end{matrix}\right)
   \f]
     *  \param[in] Nlin El numero de lineas de la matriz.
     *  \param[in] Ncol El numero de columnas de la matriz.
     *  \return Retorna la matriz o una matriz vacía en caso de error.
     *  \ingroup MatrixFuncGroup
     */
    Matrix Ones(unsigned int Nlin, unsigned int Ncol);
    
    /** 
     *  \brief Retorna una matriz con unos.  
     *
   \f[
\left(\begin{matrix}
1 & 1 & 1 & 1\\ 
1 & 1 & 1 & 1\\
1 & 1 & 1 & 1\\
1 & 1 & 1 & 1
\end{matrix}\right)
   \f]
     *  \param[in] N El numero de lineas y columnas de la matriz.
     *  \return Retorna la matriz o una matriz vacía en caso de error.
     *  \ingroup MatrixFuncGroup
     */
    Matrix Ones(unsigned int N);
    
    
    /** 
     *  \brief Retorna una matriz con ceros.  
     *
   \f[
\left(\begin{matrix}
0 & 0 & 0 & 0\\ 
0 & 0 & 0 & 0\\
0 & 0 & 0 & 0\\
0 & 0 & 0 & 0
\end{matrix}\right)
   \f]
     *  \param[in] S El tamaño de la matriz.
     *  \return Retorna la matriz o una matriz vacía en caso de error.
     *  \ingroup MatrixFuncGroup
     */
    Matrix Zeros(const Pds::Size &S);
    
    /** 
     *  \brief Retorna una matriz con ceros.  
     *
   \f[
\left(\begin{matrix}
0 & 0 & 0 & 0\\ 
0 & 0 & 0 & 0\\
0 & 0 & 0 & 0\\
0 & 0 & 0 & 0
\end{matrix}\right)
   \f]
     *  \param[in] Nlin El numero de lineas de la matriz.
     *  \param[in] Ncol El numero de columnas de la matriz.
     *  \return Retorna la matriz o una matriz vacía en caso de error.
     *  \ingroup MatrixFuncGroup
     */
    Matrix Zeros(unsigned int Nlin, unsigned int Ncol);
    
    /** 
     *  \brief Retorna una matriz con ceros.  
     *
   \f[
\left(\begin{matrix}
0 & 0 & 0 & 0\\ 
0 & 0 & 0 & 0\\
0 & 0 & 0 & 0\\
0 & 0 & 0 & 0
\end{matrix}\right)
   \f]
     *  \param[in] N El numero de lineas y columnas de la matriz.
     *  \return Retorna la matriz o una matriz vacía en caso de error.
     *  \ingroup MatrixFuncGroup
     */
    Matrix Zeros(unsigned int N);
    
/**
 * @}
 */


}
/**
 * @}
 */

#endif

