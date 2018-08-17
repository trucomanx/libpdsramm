/*
 * Matrix.hpp
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

/** \file Matrix.hpp
 *  \author Fernando Pujaico Rivera
 *  \date 01-04-2011
 *  \brief Funciones que trabajan con matrices.
 *  
 *  <br>Estas funciones trabajan con una matriz de la forma.<br>
 *  \image html matrix.png "Matriz de NlinxNcol"
 *  \b Nlin es el número de lineas y \b Ncol es el número de columnas.
 */



#ifndef __PDS_MATRIX_HPP__
#define __PDS_MATRIX_HPP__


/** \defgroup MatrixGroup Módulo Matrix.
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


#include <string>
#include <iostream>

namespace PDS{

/*! \class Matrix
 *  \brief La clase tipo  Matrix .
 *  Esta clase genera una matriz de Nlin lineas y Ncol columnas.
 *  Para usar incluir PDS/Matrix.
 *  \ingroup MatrixGroup
 *  \author Fernando Pujaico Rivera
 */
class Matrix
{
protected:
    /*! Un arreglo de Nlin lineas y Ncol elementos por linea. */
    double **array;
    /*! Número de lineas. */
    unsigned int nlin;
    /*! Número de columnas. */
    unsigned int ncol;
    
public:

/** @name Varios tipos de constructores
 *  Crean una objeto PDS::Matrix
 * @{
 */

    /** 
     *  \brief Crea un objeto de tipo PDS::Matrix
     *  \return un objeto de tipo PDS::Matrix.
     *  \ingroup MatrixGroup
     */
    Matrix(void);

    /** 
     *  \brief Crea un objeto de tipo PDS::Matrix
     *  \param[in] N El numero de lineas y columnas de la matriz.
     *  \return un objeto de tipo PDS::Matrix.
     *  \ingroup MatrixGroup
     */
    Matrix(unsigned int N);
    
    /** 
     *  \brief Crea un objeto de tipo PDS::Matrix
     *  \param[in] Nlin El numero de lineas de la matriz.
     *  \param[in] Ncol El numero de columnas de la matriz.
     *  \return un objeto de tipo PDS::Matrix.
     *  \ingroup MatrixGroup
     */
    Matrix(unsigned int Nlin,unsigned int Ncol);

    /** 
     *  \brief Crea un objeto de tipo PDS::Matrix copiando datos desde 
     *  otra matriz. Este es un Copy assignment constructor. 
     *  \return un objeto de tipo PDS::Matrix.
     *  \ingroup MatrixGroup
     */
    Matrix(const Matrix &A);


    //Matrix(Matrix&& A);
    
    ~Matrix(); 
    
/**
 * @}
 */

public:

/** @name Métodos de estado
 *  Indican o establecen el estado de una matriz.
 * @{
 */

    /** 
     *  \brief Verifica si la matriz es nula es decir con lineas o columnas cero o arreglo NULL.
     *  \return Retorna true si es nula e false si no.
     *  \ingroup MatrixGroup
     */
    bool IsVoid(void) const;

    /** 
     *  \brief Verifica si la matriz NO es nula, es decir con lineas y columnas diferentes cero y arreglo diferente de NULL.
     *  \return Retorna true si NO es nula e false si lo es.
     *  \ingroup MatrixGroup
     */
    bool IsNotVoid(void) const;

    /** 
     *  \brief libera los datos internos de la matriz y la convierte en una matriz nula.
     *  es decir con lineas y columnas cero.
     *  \ingroup MatrixGroup
     */
    void MakeVoid(void);

    /** 
     *  \brief Verifica si las matrices son similares en tamanho.
     *  \return Retorna true si son similares y false si no.
     *  \ingroup MatrixGroup
     */
    bool IsSimilarTo(const Matrix &B) const;

    /** 
     *  \brief Verifica si las matrices son similares en tamanho.
     *  \return Retorna false si son similares y true si no.
     *  \ingroup MatrixGroup
     */
    bool IsNotSimilarTo(const Matrix &B) const;
    
    /** 
     *  \brief Verifica si las matrices son multiplicables.
     *  \return Retorna true si son multiplicables y false si no.
     *  \ingroup MatrixGroup
     */
    bool IsMulBy(const Matrix &B) const;

    /** 
     *  \brief Verifica si las matrices son multiplicables.
     *  \return Retorna false si son multiplicables y true si no.
     *  \ingroup MatrixGroup
     */
    bool IsNotMulBy(const Matrix &B) const;
/**
 * @}
 */

public:

/** @name Métodos de inicialización
 *  Establecen los valores de las matrices.
 * @{
 */
    
    /** 
     *  \brief Inicializa la matriz con números aleatorios, distribuidos uniformemente,
     *  desde 0 a 1.0, incluyendo 0 y excluyendo 1.0.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool FillRandU(void);

    /** 
     *  \brief Inicializa la matriz con un valor constante.
     *  \param[in] val El valor a ser usado.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool Fill(double val);

/**
 * @}
 */

public:

/** @name Métodos variados
 *  Herramientas gnereicas
 * @{
 */

    /** 
     *  \brief Convierte los datos de la matriz en un std::string.
     *  \return Retorna un string. Si la matriz es nula retorna un string sin caracteres.
     *  \ingroup MatrixGroup
     */
    std::string ToString(void) const;

    /** 
     *  \brief Imprime en pantalla el cntenido de la matriz
     *  \ingroup MatrixGroup
     */
    void Print(void) const;

    /** 
     *  \brief Imprime en pantalla el cntenido de la matriz despues del
     * texto indicado en str.
     * \param str Texto a mostrar antes de imprimir.
     *  \ingroup MatrixGroup
     */
    void Print(std::string str) const;

/**
 * @}
 */

public:

/** @name Métodos Static
 *  Herramientas genericas que pueden ser usadas desde PDS::Matrix
 * @{
 */
    
    /** 
     *  \brief Variable donde se almacena la respuesta de las operaciones
     * que no acumulan resultado en si mismo, ejemplo: +,-,*,etc.
     *
     * Esta variable puede ser consultada siempre, pero su contenido es
     * destruido (MakeVoid()) cada vez que se usa el operador =.
\code{.cpp}
    PDS::Matrix A(4,4);
    PDS::Matrix B(4,4);
    
    A.FillRandU();
    B.Fill(1.0);
    
    A+B;
    
    std::cout<<PDS::Matrix::Answer;
\endcode
     *  \ingroup MatrixGroup
     */
    static Matrix Answer;
    
    /** 
     *  \brief crea diamicamente un arreglo de Nlin lineas y Ncol clumnas
     *  \return Retorna un puntero al arreglo, o NULL si no consiguio reservar
     * la memoria. Esta memoria debe ser liberada siempre com ReleaseArray
     *  \ingroup MatrixGroup
     */
    static double** AllocateArray(unsigned int Nlin,unsigned int Ncol);

   /** 
     *  \brief Libera un arreglo de Nlin lineas y Ncol clumnas (arreglo de arreglos)
     * Adicionalmente carga con NULL al arreglo a liberar.
     *  \ingroup MatrixGroup
     */
    static void ReleaseArray(double** &array,unsigned int Nlin);

/**
 * @}
 */

public:

/** @name Operadores y sus métodos equivalentes
 *  Descripcion de algunos operadores habilitados a trabajar con PDS::Matrix.
 * @{
 */
    /** 
     *  \brief Suma con sigo mismo (A), una matriz B y el resultado es
     * cargado en PDS::Matrix::Answer. Este operador 
     *  es similar al método Add() 
     *
     *  \f[ Answer \leftarrow A+B \f]
\code{.cpp}
    PDS::Matrix A(4,4);
    PDS::Matrix B(4,4);
    
    A.FillRandU();
    B.Fill(1.0);
    
    A+B;
    
    std::cout<<PDS::Matrix::Answer;
\endcode
     *  \param[in] B la matriz a sumar
     *  \return Retorna PDS::Matrix::Answer con el
     *  resultado, o una matriz vazia (this->IsVoid() igual a true) en caso de error.
     *  \see Add
     *  \ingroup MatrixGroup
     */
    Matrix operator + (const Matrix &B);
    
    /** 
     *  \brief Suma con sigo mismo (A), una matriz B y el resultado es
     * cargado en PDS::Matrix::Answer. Este metodo 
     *  es similar al operador + 
     *
     *  \f[ Answer \leftarrow A+B \f]
\code{.cpp}
    PDS::Matrix A(4,4);
    PDS::Matrix B(4,4);
    
    A.FillRandU();
    B.Fill(1.0);
    
    A.Add(B);
    
    std::cout<<PDS::Matrix::Answer;
\endcode
     *  \param[in] B la matriz a sumar
*  \return Retorna true si tdo fue bien o false en caso de error.
     *  Si hubo error entonces PDS::Matrix:Answer es una matriz vacia.
     *  \ingroup MatrixGroup
     */
    bool Add(const Matrix &B);
    
    /** 
     *  \brief Multiplica con sigo mismo (A), una matriz B y el resultado es
     * cargado en PDS::Matrix::Answer. Este operador 
     *  es similar al método Mul() 
     *
     *  \f[ Answer \leftarrow A+B \f]
\code{.cpp}
    PDS::Matrix A(4,4);
    PDS::Matrix B(4,4);
    
    A.FillRandU();
    B.Fill(1.0);
    
    A*B;
    
    std::cout<<PDS::Matrix::Answer;
\endcode
     *  \param[in] B la matriz a multiplicar
     *  \return Retorna PDS::Matrix::Answer con el
     *  resultado, o una matriz vazia (this->IsVoid() igual a true) en caso de error.
     *  \see Add
     *  \ingroup MatrixGroup
     */
    Matrix operator * (const Matrix &B);
    
    /** 
     *  \brief Multiplica con sigo mismo (A), una matriz B y el resultado es
     * cargado en PDS::Matrix::Answer. Este metodo 
     *  es similar al operador * 
     *
     *  \f[ Answer \leftarrow A+B \f]
\code{.cpp}
    PDS::Matrix A(4,4);
    PDS::Matrix B(4,4);
    
    A.FillRandU();
    B.Fill(1.0);
    
    A.Mul(B);
    
    std::cout<<PDS::Matrix::Answer;
\endcode
     *  \param[in] B la matriz a multiplicar
     *  \return Retorna true si tdo fue bien o false en caso de error.
     *  Si hubo error entonces PDS::Matrix:Answer es una matriz vacia.
     *  \ingroup MatrixGroup
     */
    bool Mul(const Matrix &B);
    
    /** 
     *  \brief Suma y acumula en si mismo (B), una matriz A. Este operador 
     *  es similar al método Accumulate() 
     *
     *  \f[ B \leftarrow B+A \f]
\code{.cpp}
    PDS::Matrix A(4,4);
    PDS::Matrix B(4,4);
    A.FillRandU();
    B+=A;
\endcode
     *  \param[in] B la matriz a acumular
     *  \return Retorna el operador de la izquierda (acumulador) con el
     *  resultado, o una matriz vazia (this->IsVoid() igual a true) en caso de error.
     *  \see Accumulate
     *  \ingroup MatrixGroup
     */
    Matrix& operator +=(const Matrix &B);

    /** 
     *  \brief Suma y acumula en si mismo (B), una matriz A. Este es similar al
     *  perador += 
     *
     *  \f[ B \leftarrow B+A \f]
\code{.cpp}
    PDS::Matrix A(4,4);
    PDS::Matrix B(4,4);
    A.FillRandU();
    B.Accumulate(A);
\endcode
     *  \param[in] A la matriz a acumular
     *  \return Retorna true si todo fue bien o false si no. Si se retorna false
     *  el acumulador no altera su contenido.
     *  \ingroup MatrixGroup
     */
    bool Accumulate(const Matrix &A);
    
    /** 
     *  \brief Copia en si mismo (B), una matriz A. Este operador es 
     *  similar al método Copy() 
     *
     *  \f[ B \leftarrow A \f]
     * Cuando acontece:
\code{.cpp}
    A=PDS::Matrix(nlin,ncol);
    B=A;
\endcode
     * Cuando NO acontece:
\code{.cpp}
    PDS::Matrix A=PDS::Matrix(nlin,ncol);
\endcode
     *  \param[in] A la matriz a copiar
     *  \return Retorna el operador de la izquierda (acumulador) con el
     *  resultado, o una matriz vazia (this->IsVoid() igual a true) en caso de error.
     *  \see Copy
     *  \ingroup MatrixGroup
     */
    Matrix& operator = (const Matrix &A);
    
    /** 
     *  \brief Copia en si mismo (B), el contenido de una matriz A. Este 
     *  metodo es similar a usar el operador = 
     *
     *  \f[ B \leftarrow A \f]
     *  \param[in] A la matriz a copiar
     *  \return Retorna true si todo fue bien o false si no. Si se retorna false
     *  el receptor no altera su contenido.
     *  \see Copy
     *  \ingroup MatrixGroup
     */
    bool Copy(const Matrix &A);

    /** 
     *  \brief Mueve datos a si mismo (B), desde una matriz A. Esta operación 
     *  covierte a la matriz A en una matriz vacia.
     *
     *  \f[ B \leftarrow A \f]
     *  \f[ A \leftarrow 0 \f]
     * 
     * Internamente la funcion intercambia  el contenido moviendo direcciones de memoria.
     *  \param[in] A la matriz a acumular
     *  \return Retorna true si todo fue bien o false si no. Si se retorna false
     *  el receptor no altera su contenido.
     *  \see Copy
     *  \ingroup MatrixGroup
     */
    bool Move(Matrix &A);
    
/**
 * @}
 */


};// class Matrix

typedef Matrix Zeros;

} // namespace PDS


/** @name Operadores no miembros
 *  Descripcion de algunos operadores habilitados a trabajar con PDS::Matrix.
 * @{
 */
    /** 
     *  \brief Retorna el contenido de la matriz por la salida estandar
     *
\code{.cpp}
    std::cout<<mat;
\endcode
     * es equivalente a :
\code{.cpp}
    std::cout<<mat.ToString();
\endcode
     *  \param[in] out La salida
     *  \param[in] mat La matriz a mostrar
     *  \return Retorna la misma salida estandar out.
     *  \see PDS::Matrix::ToString();
     *  \ingroup MatrixGroup
     */
std::ostream& operator<<(std::ostream &out,const PDS::Matrix &mat);

/**
 * @}
 */




/*!
 * @}
 */

#endif

