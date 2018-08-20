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

namespace Pds{

/*! \class Matrix
 *  \brief La clase tipo  Matrix .
 *  Esta clase genera una matriz de Nlin lineas y Ncol columnas.
 *  Para usar incluir Pds/Matrix.
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
 *  Crean una objeto Pds::Matrix
 * @{
 */

    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix
     *  \return un objeto de tipo Pds::Matrix.
     *  \ingroup MatrixGroup
     */
    Matrix(void);

    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix
     *  \param[in] N El numero de lineas y columnas de la matriz.
     *  \return un objeto de tipo Pds::Matrix.
     *  \ingroup MatrixGroup
     */
    Matrix(unsigned int N);
    
    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix
     *  \param[in] Nlin El numero de lineas de la matriz.
     *  \param[in] Ncol El numero de columnas de la matriz.
     *  \return un objeto de tipo Pds::Matrix.
     *  \ingroup MatrixGroup
     */
    Matrix(unsigned int Nlin,unsigned int Ncol);

    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix copiando datos desde 
     *  otra matriz. Este es un Copy assignment constructor. 
     *  \return un objeto de tipo Pds::Matrix.
     *  \ingroup MatrixGroup
     */
    Matrix(const Matrix &A);

    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix copiando datos desde 
     *  un archivo. 
     *  \return un objeto de tipo Pds::Matrix.
     *  \ingroup MatrixGroup
     */
    Matrix(const char *filepath);
    
    
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
     *  \param[in] B Matriz en consulta.
     *  \return Retorna true si son similares y false si no.
     *  \ingroup MatrixGroup
     */
    bool IsSimilarTo(const Matrix &B) const;

    /** 
     *  \brief Verifica si las matrices son similares en tamanho.
     *  \param[in] B Matriz en consulta.
     *  \return Retorna false si son similares y true si no.
     *  \ingroup MatrixGroup
     */
    bool IsNotSimilarTo(const Matrix &B) const;
    
    /** 
     *  \brief Verifica si las matrices son multiplicables.
     *  \param[in] B Matriz en consulta.
     *  \return Retorna true si son multiplicables y false si no.
     *  \ingroup MatrixGroup
     */
    bool IsMulBy(const Matrix &B) const;

    /** 
     *  \brief Verifica si las matrices son multiplicables.
     *  \param[in] B Matriz en consulta.
     *  \return Retorna false si son multiplicables y true si no.
     *  \ingroup MatrixGroup
     */
    bool IsNotMulBy(const Matrix &B) const;

    /** 
     *  \brief Verifica si la posicion pertenece a la matriz.
     *  \param[in] lin Linea en consulta.
     *  \param[in] col columna en consulta.
     *  \return Retorna true si pertenece y false si no.
     *  \ingroup MatrixGroup
     */
    bool HasThePosition(double lin,double col) const;

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
     *  \return Retorna un std::string. Si la matriz es nula retorna un string sin caracteres.
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
     *  \brief Aplica la funcion func a cada elemento de la matriz.
     * \param func Función a aplicar, esta debe tener a forma double func(double).
     * \return true si todo fue bien o false si la matriz era nula.
     *  \ingroup MatrixGroup
     */
    bool Apply( double (*func)(double) );


/**
 * @}
 */


public:

/** @name Métodos Static con Matrices
 *  Herramientas genericas que pueden ser usadas desde Pds::Matrix
 * @{
 */


   /** 
     *  \brief Lee de un archivo una matriz de Nlin lineas y Ncol columnas.
     *  \param[in] filepath El archivo donde se leeran los datos.
     *  \return Retorna una matriz no vacia si todo fue bien o una matriz vacia en caso de error.
     *  \ingroup MatrixGroup
     */
    static Pds::Matrix Load(const char* filepath);

   /** 
     *  \brief Escribe en un archivo una matriz de Nlin lineas y Ncol columnas.
     *  \param[in] filepath El archivo donde se escribiran los datos.
     *  \param[in] A matriz a escribir.
     *  \return Retorna true si todo fue bien o false en caso de error.
     *  \ingroup MatrixGroup
     */
    static bool Save(const char* filepath,const Pds::Matrix &A);
/**
 * @}
 */


public:

/** @name Métodos Static con arrays
 *  Herramientas genericas que pueden ser usadas desde Pds::Matrix
 * @{
 */
    
  
    /** 
     *  \brief crea diamicamente un arreglo de Nlin lineas y Ncol clumnas
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \param[in] Ncol El numero de columnas en el arreglo.
     *  \return Retorna un puntero al arreglo, o NULL si no consiguio reservar
     * la memoria. Esta memoria debe ser liberada siempre com ReleaseArray
     *  \ingroup MatrixGroup
     */
    static double** AllocateArray(unsigned int Nlin,unsigned int Ncol);

   /** 
     *  \brief Libera un arreglo de Nlin lineas y Ncol clumnas (arreglo de arreglos)
     * Adicionalmente carga con NULL al arreglo a liberar.
     *  \param[in] array El arreglo de arreglos de de Nlin lineas y Ncol columnas
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \ingroup MatrixGroup
     */
    static void ReleaseArray(double** &array,unsigned int Nlin);


   /** 
     *  \brief Convierte a un sdt::string un arreglo de Nlin lineas y Ncol columnas (arreglo de arreglos).
     *  \param[in] array El arreglo de arreglos de de Nlin lineas y Ncol columnas
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \param[in] Ncol El numero de columnas en el arreglo.
     *  \return Retorna un std::string. Si la matriz es nula retorna un string sin caracteres.
     *  \ingroup MatrixGroup
     */
    static std::string ArrayToString(double **array,unsigned int Nlin,unsigned int Ncol);

   /** 
     *  \brief Salva en un archivo un arreglo de Nlin lineas y Ncol columnas (arreglo de arreglos).
     *  \param[in] filepath El archivo donde se guardaran los datos.
     *  \param[in] array El arreglo de arreglos de de Nlin lineas y Ncol columnas
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \param[in] Ncol El numero de columnas en el arreglo.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    static bool SaveArray(const char* filepath,double **array,unsigned int Nlin,unsigned int Ncol);


   /** 
     *  \brief Lee de un archivo un arreglo de Nlin lineas y Ncol columnas (arreglo de arreglos).
     *  \param[in] filepath El archivo donde se leeran los datos.
     *  \param[out] array Donde se escribira el arreglo de arreglos de de Nlin lineas y Ncol columnas.
     *  La funcion no libera a memoria de array, entonces se le debe entregar siempre un array==NULL.
     *  \param[out] Nlin Donde se escribira el numero de lineas en el arreglo.
     *  \param[out] Ncol Donde se escribira el numero de columnas en el arreglo.
     *  \return Retorna true si todo fue bien o false si no. Si el numero de columnas 
     *  no es constante se retorna false. Si la funcion retorna false entonces los valores
     *  de entrada no son alterados.
     *  \ingroup MatrixGroup
     */
    static bool LoadArray(const char* filepath,double** &array,unsigned int& Nlin,unsigned int& Ncol);

/**
 * @}
 */

public:

/** @name Operadores y sus métodos equivalentes
 *  Descripcion de algunos operadores habilitados a trabajar con Pds::Matrix.
 * @{
 */
    /** 
     *  \brief Cambia de signo a si mismo (A), el resultado es
     * cargado en B. Este operador es similar al metodo unario - 
     *
     *  \f[ B \leftarrow -A \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B;
    
    A.Fill(2.0);
    
    B=-A;
    
    std::cout<<B;
\endcode
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vazia (this->IsVoid() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Matrix operator -(void);
    
    /** 
     *  \brief Cambia de signo a si mismo (A), el resultado es
     * cargado en B. Este metodo es similar al operador unario - 
     *
     *  \f[ B \leftarrow -A \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B;
    
    A.Fill(2.0);
    
    B=A.Minus();
    
    std::cout<<B;
\endcode
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vazia (this->IsVoid() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Matrix Minus(void);

    /** 
     *  \brief Transpuesta de si mismo (A), el resultado es
     * cargado en B. 
     *
     *  \f[ B \leftarrow transpose(A) \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B;
    
    A.FillRandU();
    
    B=A.T();
    
    std::cout<<B;
\endcode
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vazia (this->IsVoid() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Matrix T(void);

    /** 
     *  \brief Suma con sigo mismo (A), una matriz B y el resultado es
     * cargado en C. Este operador 
     *  es similar al método Add() 
     *
     *  \f[ C \leftarrow A+B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    B.Fill(1.0);
    
    C=A+B;
    
    std::cout<<C;
\endcode
     *  \param[in] B la matriz a sumar
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vazia (this->IsVoid() igual a true) en caso de error.
     *  \see Add
     *  \ingroup MatrixGroup
     */
    Matrix operator + (const Matrix &B);
    
    /** 
     *  \brief Suma con sigo mismo (A), una matriz B y el resultado es
     * cargado en C. Este metodo 
     *  es similar al operador + 
     *
     *  \f[ C \leftarrow A+B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    B.Fill(1.0);
    
    C=A.Add(B);
    
    std::cout<<C;
\endcode
     *  \param[in] B la matriz a sumar
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vazia (this->IsVoid() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Matrix Add(const Matrix &B);
    
    /** 
     *  \brief Multiplica con sigo mismo (A), una matriz B y el resultado es
     * cargado en C. Este operador es similar al método Mul() 
     *
     *  \f[ C \leftarrow A*B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    B.Fill(1.0);
    
    C=A*B;
    
    std::cout<<C;
\endcode
     *  \param[in] B la matriz a multiplicar
     *  \return Retorna C con el
     *  resultado, o una matriz vazia (this->IsVoid() igual a true) en caso de error.
     *  \see Mul
     *  \ingroup MatrixGroup
     */
    Matrix operator * (const Matrix &B);
    
    /** 
     *  \brief Multiplica con sigo mismo (A), una matriz B y el resultado es
     * cargado en C. Este metodo  es similar al operador * 
     *
     *  \f[ C \leftarrow A*B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    B.Fill(1.0);
    
    C=A.Mul(B);
    
    std::cout<<C;
\endcode
     *  \param[in] B la matriz a multiplicar
     *  \return Retorna C con el
     *  resultado, o una matriz vazia (this->IsVoid() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Matrix Mul(const Matrix &B);
    
    /** 
     *  \brief Suma y acumula en si mismo (B), una matriz A. Este operador 
     *  es similar al método Accumulate() 
     *
     *  \f[ A \leftarrow A+B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(4,4);
    B.Fill(1.0);
    A+=B;
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
     *  \f[ A \leftarrow A+B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(4,4);
    B.Fill(1.0);
    A+=B;
\endcode
     *  \param[in] B la matriz a acumular
     *  \return Retorna true si todo fue bien o false si no. Si se retorna false
     *  el acumulador no altera su contenido.
     *  \ingroup MatrixGroup
     */
    bool Accumulate(const Matrix &B);
    
    /** 
     *  \brief Copia en si mismo (B), una matriz A. Este operador es 
     *  similar al método Copy() 
     *
     *  \f[ B \leftarrow A \f]
     * Cuando acontece:
\code{.cpp}
    A=Pds::Matrix(nlin,ncol);
    B=A;
\endcode
     * Cuando NO acontece:
\code{.cpp}
    Pds::Matrix A=Pds::Matrix(nlin,ncol);
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

} // namespace Pds




/** @name Operadores no miembros
 *  Descripcion de algunos operadores habilitados a trabajar con Pds::Matrix.
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
     *  \see Pds::Matrix::ToString();
     *  \ingroup MatrixGroup
     */
std::ostream& operator<<(std::ostream &out,const Pds::Matrix &mat);

/**
 * @}
 */

/** @name Sobrecarga de funciones matematicas cmath
 *  Descripcion de algunas funciones matematica que usan  Pds::Matrix.
 * @{
 */

    /** 
     *  \brief Retorna el el resultado de evaluar la funcion seno.  
     *
     *  \param[in] A La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \ingroup MatrixGroup
     */
Pds::Matrix sin(const Pds::Matrix A);
/**
 * @}
 */

/**
 * @}
 */

#endif

