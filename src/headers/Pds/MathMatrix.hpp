/*
 * MathMatrix.hpp
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

/** \file MathMatrix.hpp
 *  \author Fernando Pujaico Rivera
 *  \brief Funciones que trabajan con matrices.
 *  
 *  <br>Estas funciones trabajan con una matriz de la forma.<br>
 *  \image html matrix.png "Matriz de NlinxNcol"
 *  \b Nlin es el número de lineas y \b Ncol es el número de columnas.
 */



#ifndef __PDS_MATHMATRIX_HPP__
#define __PDS_MATHMATRIX_HPP__


/** \defgroup MathMatrixGroup Funciones para Pds::Matrix - math.
 *  \brief Funciones matemáticas que trabajan con matrices.
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
    

/** @name Sobrecarga de funciones trigonometricas
 *  Descripcion de algunas funciones matematicas que usan  Pds::Matrix.
 * @{
 */
    
    /** 
     *  \brief Retorna el el resultado de evaluar la funcion seno.  
     *
     *  \f[ sin(A) \f]
     *  \param[in] A La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \see Pds::Matrix::Apply()
     *  \ingroup MathMatrixGroup
     */
    Matrix Sin(const Matrix A);
    
    /** 
     *  \brief Retorna el el resultado de evaluar la funcion coseno.  
     *
     *  \f[ cos(A) \f]
     *  \param[in] A La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \see Pds::Matrix::Apply()
     *  \ingroup MathMatrixGroup
     */
    Matrix Cos(const Matrix A);
    
    /** 
     *  \brief Retorna el el resultado de evaluar la funcion tangente.  
     *
     *  \f[ tan(A) \f]
     *  \param[in] A La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \see Pds::Matrix::Apply()
     *  \ingroup MathMatrixGroup
     */
    Matrix Tan(const Matrix A);
/**
 * @}
 */


/** @name Sobrecarga de funciones exponencial
 *  Descripcion de algunas funciones matematicas que usan  Pds::Matrix.
 * @{
 */
    /** 
     *  \brief Retorna el el resultado de evaluar la funcion exponente.  
     *
     *  \f[ e^A \f]
     *  \param[in] A La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \see Pds::Matrix::Apply()
     *  \ingroup MathMatrixGroup
     */
    Matrix Exp(const Matrix A);
    
    /** 
     *  \brief Retorna el el resultado de evaluar la funcion exponente de 2.  
     *
     *  \f[ 2^A \f]
     *  \param[in] A La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \see Pds::Matrix::Apply()
     *  \ingroup MathMatrixGroup
     */
    Matrix Exp2(const Matrix A);
    
    /** 
     *  \brief Retorna el el resultado de evaluar la funcion logaritmo natural.
     *
     *  \f[ ln(A) \f]
     *  \param[in] A La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \see Pds::Matrix::Apply()
     *  \ingroup MathMatrixGroup
     */
    Matrix Log(const Matrix A);
    
    /** 
     *  \brief Retorna el el resultado de evaluar la funcion logaritmo de base 2.
     *
     *  \f[ log_2(A) \f]
     *  \param[in] A La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \see Pds::Matrix::Apply()
     *  \ingroup MathMatrixGroup
     */
    Matrix Log2(const Matrix A);

    /** 
     *  \brief Retorna el el resultado de evaluar la funcion logaritmo de base 10.
     *
     *  \f[ log_{10}(A) \f]
     *  \param[in] A La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \see Pds::Matrix::Apply()
     *  \ingroup MathMatrixGroup
     */
    Matrix Log10(const Matrix A);

/**
 * @}
 */


/** @name Sobrecarga de funciones potencia
 *  Descripcion de algunas funciones matematicas que usan  Pds::Matrix.
 * @{
 */
 
    /** 
     *  \brief Retorna el el resultado de evaluar la funcion raiz cuadrada.
     *
     *  \f[ \sqrt{A} \f]
     *  \param[in] A La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \see Pds::Matrix::Apply()
     *  \ingroup MathMatrixGroup
     */
    Matrix Sqrt(const Matrix A);
/**
 * @}
 */

} //namespace Pds
/**
 * @}
 */

#endif
