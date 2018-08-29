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


/** \defgroup MatrixGroup Clase Pds::Matrix.
 *  \brief Metodos de la clase Pds::Matrix, una matriz.
 *  
 *  <br>Estas funciones trabajan con una matriz de la forma.<br>
 *  <center>
   \f[
A=\left(\begin{matrix}
a_{00} & a_{01} & \hdots & a_{0(Ncol-1)}\\ 
a_{10} & a_{11} & \hdots & a_{1(Ncol-1)}\\
\vdots & \vdots & \vdots & \vdots \\
a_{(Nlin-2)0} & a_{(Nlin-2)1} & \hdots & a_{(Nlin-2)(Ncol-1)}\\ 
a_{(Nlin-1)0} & a_{(Nlin-1)1} & \hdots & a_{(Nlin-1)(Ncol-1)}\\
\end{matrix}\right)\equiv A_{(Nlin-1)(Ncol-1)}
   \f]
   \f[
A_{(Nlin-1)(Ncol-1)}\equiv [a_{ij}]_{(Nlin-1)(Ncol-1)}
   \f]
 *  </center>
 *  \b Nlin es el número de lineas y \b Ncol es el número de columnas.
 *  
 * Informacion adicional puede ser encontrada en @cite tutorialmatvec
 * @{
 */


#include <string>

namespace Pds{

class ColVector;

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
     *  \brief Crea un objeto de tipo Pds::Matrix vacio.
     * 
   \f[
A_{0,0}\equiv []_{0,0}
   \f]
   Para crear una matriz vacia:
\code{.cpp}
    Pds::Matrix A;
    
    if(A.IsEmpty()) std::cout<<"Yes,always\n";
\endcode
     *  \ingroup MatrixGroup
     */
    Matrix(void);

    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix de N lineas y N columnas,
     *  con elementos inicializados con cero.
   \f[
A=\left(\begin{matrix}
0 & 0 & \hdots & 0\\ 
0 & 0 & \hdots & 0\\
\vdots & \vdots & \vdots & \vdots \\
0 & 0 & \hdots & 0\\ 
0 & 0 & \hdots & 0\\
\end{matrix}\right)\equiv A_{N,N}
   \f]
   \f[
A_{N,N}\equiv [a_{i,j}]_{N,N}\equiv [0]_{N,N}
   \f]
   Para crear una matriz A de 4 filas y 4 columnas:
\code{.cpp}
    Pds::Matrix A(4);
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] N El numero de lineas y columnas de la matriz.
     *  \ingroup MatrixGroup
     */
    Matrix(unsigned int N);
    
    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix con elementos inicializados con cero.
   \f[
A=\left(\begin{matrix}
0 & 0 & \hdots & 0\\ 
0 & 0 & \hdots & 0\\
\vdots & \vdots & \vdots & \vdots \\
0 & 0 & \hdots & 0\\ 
0 & 0 & \hdots & 0\\
\end{matrix}\right)\equiv A_{Nlin,Ncol}
   \f]
   \f[
A_{Nlin,Ncol}\equiv [a_{i,j}]_{Nlin,Ncol}\equiv [0]_{Nlin,Ncol}
   \f]
   Para crear una matriz A de 4 filas y 3 columnas:
\code{.cpp}
    Pds::Matrix A(4,3);
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] Nlin El numero de lineas de la matriz.
     *  \param[in] Ncol El numero de columnas de la matriz.
     *  \ingroup MatrixGroup
     */
    Matrix(unsigned int Nlin,unsigned int Ncol);
    
    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix con elementos inicializados con val.
   \f[
A=\left(\begin{matrix}
val & val & \hdots & val\\ 
val & val & \hdots & val\\
\vdots & \vdots & \vdots & \vdots \\
val & val & \hdots & val\\ 
val & val & \hdots & val\\
\end{matrix}\right)\equiv A_{Nlin,Ncol}
   \f]
   \f[
A_{Nlin,Ncol}\equiv [a_{i,j}]_{Nlin,Ncol}\equiv [val]_{Nlin,Ncol}
   \f]
   Para crear una matriz A de 4 filas y 3 columnas inicializado con -1:
\code{.cpp}
    Pds::Matrix A(4,3,-1.0);
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] Nlin El numero de lineas de la matriz.
     *  \param[in] Ncol El numero de columnas de la matriz.
     *  \param[in] val El valor a usar.
     *  \ingroup MatrixGroup
     */
    Matrix(unsigned int Nlin,unsigned int Ncol,double val);

    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix copiando datos desde 
     *  otra matriz. Este es un Copy assignment constructor.
   \f[
B_{Nlin,Ncol}\equiv [b_{i,j}]_{Nlin,Ncol}
   \f]
   \f[
A \leftarrow B
   \f]
   Para crear una matriz A con copia de datos de una matriz B:
\code{.cpp}
    Pds::Matrix B(4,3,-1.0);
    Pds::Matrix A(B);
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] B Matriz a copiar.
     *  \ingroup MatrixGroup
     */
    Matrix(const Matrix &B);
    
    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix, evaluando mediante una funcion, 
     *  los datos de otra matriz.
   \f[
B_{Nlin,Ncol}\equiv [b_{i,j}]_{Nlin,Ncol}
   \f]
   \f[
A \leftarrow func(B)
   \f]
   Para crear una matriz A , copia de sin(B):
\code{.cpp}
    Pds::Matrix B(4,3,1.0);
    Pds::Matrix A(B,sin);
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] B Matriz a evaluar para copiar los resultados.
     *  \param[in] func Función a aplicar, esta debe tener a forma double func(double).
     *  \ingroup MatrixGroup
     */
    Matrix(const Matrix &B, double (*func)(double) );
    
    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix copiando datos desde 
     *  un archivo. 
     * 
     * Considerando el archivo "filedat.txt":
\code{.cpp}
0.1 -1.0  3
9   4    -3
\endcode
   Para crear una matriz A con los datos del archivo "filedat.txt":
\code{.cpp}
    Pds::Matrix A("filedat.txt");
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem,"
                             <<"possible file not found,etc\n";
    else            std::cout<<"No,all fine\n";
\endcode
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
     *  
     *  Una matriz\f$A\f$ está vacia si  \f$ A=[]_{0,0}\f$.
     *  \return Retorna true si es nula e false si no.
     *  \ingroup MatrixGroup
     */
    bool IsEmpty(void) const;

    /** 
     *  \brief Verifica si la matriz NO es nula, es decir con lineas y columnas diferentes cero y arreglo diferente de NULL.
     * 
     *  Una matriz\f$A\f$ está vacia si  \f$ A=[]_{0,0}\f$.
     *  \return Retorna true si NO es nula e false si lo es.
     *  \ingroup MatrixGroup
     */
    bool IsNotEmpty(void) const;

    /** 
     *  \brief libera los datos internos de la matriz y la convierte en una matriz nula.
     *  es decir con lineas y columnas cero.
     * 
     *  Una matriz\f$A\f$ está vacia si  \f$ A=[]_{0,0}\f$.
     *  \ingroup MatrixGroup
     */
    void MakeEmpty(void);

    /** 
     *  \brief Verifica si las matrices son similares en tamaño.
     * 
     *  Una matriz\f$A=[a_{i,j}]_{M,N}\f$ es similar a \f$B=[b_{i,j}]_{P,Q}\f$ 
     *  si  \f$M=P\f$ y \f$N=Q\f$.
     *  \param[in] B Matriz en consulta.
     *  \return Retorna true si son similares y false si no.
     *  \ingroup MatrixGroup
     */
    bool IsSimilarTo(const Matrix &B) const;

    /** 
     *  \brief Verifica si las matrices son similares en tamaño.
     * 
     *  Una matriz\f$A=[a_{i,j}]_{M,N}\f$ es similar a \f$B=[b_{i,j}]_{P,Q}\f$ 
     *  si  \f$M=P\f$ y \f$N=Q\f$.
     *  \param[in] B Matriz en consulta.
     *  \return Retorna false si son similares y true si no.
     *  \ingroup MatrixGroup
     */
    bool IsNotSimilarTo(const Matrix &B) const;
    
    /** 
     *  \brief Verifica si las matrices son multiplicables.
     * 
     *  Una matriz\f$A=[a_{i,j}]_{M,N}\f$ es multiplicable por \f$B=[b_{i,j}]_{P,Q}\f$ 
     *  si  \f$N=P\f$ y ambas son no vacias.
     *  \param[in] B Matriz en consulta.
     *  \return Retorna true si son multiplicables y false si no.
     *  \ingroup MatrixGroup
     */
    bool IsMulBy(const Matrix &B) const;

    /** 
     *  \brief Verifica si las matrices son multiplicables.
     * 
     *  Una matriz\f$A=[a_{i,j}]_{M,N}\f$ es multiplicable por \f$B=[b_{i,j}]_{P,Q}\f$ 
     *  si  \f$N= P\f$ y ambas son no vacias.
     *  \param[in] B Matriz en consulta.
     *  \return Retorna false si son multiplicables y true si no.
     *  \ingroup MatrixGroup
     */
    bool IsNotMulBy(const Matrix &B) const;

    /** 
     *  \brief Verifica si la posición pertenece a la matriz.
     * 
     *  Dada una matriz\f$A=[a_{i,j}]_{M,N}\f$; la posición \f$(lin,col)\f$ 
     *  está en rango de \f$A\f$ si cualquier valor entero de \f$0\leq lin \leq M-1\f$
     *  y  cualquier valor entero de \f$0\leq col \leq N-1\f$.
     *  \param[in] lin Linea en consulta.
     *  \param[in] col columna en consulta.
     *  \return Retorna true si pertenece y false si no.
     *  \ingroup MatrixGroup
     */
    bool IsInRange(unsigned int lin,unsigned int col) const;
    
    /** 
     *  \brief Verifica si la posición NO pertenece a la matriz.
     * 
     *  Dada una matriz\f$A=[a_{i,j}]_{M,N}\f$; la posición \f$(lin,col)\f$ 
     *  está en rango de \f$A\f$ si cualquier valor entero de \f$0\leq lin \leq M-1\f$
     *  y  cualquier valor entero de \f$0\leq col \leq N-1\f$.
     *  \param[in] lin Linea en consulta.
     *  \param[in] col columna en consulta.
     *  \return Retorna false si pertenece y true si no.
     *  \ingroup MatrixGroup
     */
    bool IsNotInRange(unsigned int lin,unsigned int col) const;
    
    /** 
     *  \brief Verifica si la posición (lin,col) pertenece al rango de la matriz.
     * 
     *  Dada una matriz\f$A=[a_{i,j}]_{M,N}\f$; la posición \f$(lin,col)\f$ 
     *  está en rango de \f$A\f$ si cualquier valor real de \f$0\leq lin \leq M-1\f$
     *  y  cualquier valor real de \f$0\leq col \leq N-1\f$.
     *  \param[in] lin Linea en consulta.
     *  \param[in] col columna en consulta.
     *  \return Retorna true si pertenece y false si no.
     *  \ingroup MatrixGroup
     */
    bool IsInSizeRange(double lin,double col) const;
    
    /** 
     *  \brief Verifica si la matriz tiene elementos con valores infinitos.
     * 
     * Los valores infinitos pueden producirse con \f$+\frac{1}{0},-\frac{1}{0} y \frac{1}{0}\f$.
     *  \return Retorna una nueva matriz con 1 donde es infinito y 0 donde no lo es.
     *  \ingroup MatrixGroup
     */
    Matrix IsInf(void) const;
    
    /** 
     *  \brief Verifica si la matriz tiene elementos con valores NAN (Not A Number).
     * 
     *  Los valores NAN pueden producirse con \f$\frac{0}{0}\f$.
     *  \return Retorna una nueva matriz con 1 donde es NAN y 0 donde no lo es.
     *  \ingroup MatrixGroup
     */
    Matrix IsNan(void) const;
    
    /** 
     *  \brief Verifica si la matriz tiene elementos con valores finitos (no +inf, no -inf y no NAN).
     *  \return Retorna una nueva matriz con 1 donde es finito y 0 donde no lo es.
     *  \ingroup MatrixGroup
     */
    Matrix IsFinite(void) const;
    
/**
 * @}
 */

public:

/** @name Métodos de inicialización
 *  Establecen los valores de las matrices.
 * @{
 */
    /** 
     *  \brief Inicializa la matriz con números aleatorios, distribuidos usando una distribución
     * Gaussiana normalizada con media 0 y desvío padrón 1.0.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool FillRandN(void);
    
    /** 
     *  \brief Inicializa la matriz con números aleatorios, distribuidos uniformemente,
     *  desde 0 a 1.0, incluyendo 0 y excluyendo 1.0.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool FillRandU(void);

    /** 
     *  \brief Inicializa la matriz con el valor de la posicion de cada elemento.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool FillId(void);

    /** 
     *  \brief Inicializa la matriz con un valor constante.
     *  \param[in] val El valor a ser usado.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool Fill(double val);

    /** 
     *  \brief Inicializa la matriz con un espacio linear entre begin y end.
     *  Se inicializa primero una columna ante de pasar ala siguiente.
     *  \param[in] begin El valor inicial.
     *  \param[in] end El valor final.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool LinSpace(double begin,double end);
/**
 * @}
 */
public:

/** @name Métodos get y set, extras
 *  Herramientas genericas para lectura y escritura de datos.
 * @{
 */
 
    /** 
     *  \brief Retorna un vector columna copia de una columna de la matriz. 
     *  \param[in] col La columna en consulta.
     *  \return Retorna el vector columna en la posición (col) o un vector vacio si la 
     *  posición no existe.
     *  \ingroup MatrixGroup
     */
    Pds::ColVector GetColVector(unsigned int col) const;
    
    /** 
     *  \brief Copia un vector columna en una columna de la matriz. Si los 
     *  tamanos son diferentes, se intersectan las matrices y se copia 
     *  solamente en la interseccion.
     *  \param[in] V El vector a copiar.
     *  \param[in] col La columna en consulta.
     *  \return Retorna true si la copia fue hecha y la posición (col) existe
     *  o false si hubo algún problema. En caso de retornar false no se modifica la matriz.
     *  \ingroup MatrixGroup
     */
    bool SetColVector(const Pds::ColVector V,unsigned int col);
    
/**
 * @}
 */

public:

/** @name Métodos get y set
 *  Herramientas genericas para lectura y escritura de datos.
 * @{
 */
    /** 
     *  \brief Retorna el valor en la posición del índice id, hace una verificación
     *  si la posición existe. 
     *  \param[in] id índice de un elemento de la matriz.
     *  \return Retorna el valor en la posición (id\%Nlin,id/Nlin) o cero si la 
     *  posición no existe.
     *  \ingroup MatrixGroup
     */
    double Get(unsigned int id) const;
    
    /** 
     *  \brief Escribe el valor en la posición del índice id, hace una verificación
     *  si la posición existe. 
     *  \param[in] val valor a escribir.
     *  \param[in] id índice de un elemento de la matriz.
     *  \return Retorna true si consiguió escribir el valor en la 
     *  posición (id\%Nlin,id/Nlin) o false si no.
     *  \ingroup MatrixGroup
     */
    bool Set(double val,unsigned int id);
    
    /** 
     *  \brief Retorna el valor en la posición (lin,col), hace una verificación
     *  si la posición existe. 
     *  \param[in] lin La linea en consulta.
     *  \param[in] col La columna en consulta.
     *  \return Retorna el valor en la posición (lin,col) o cero si la 
     *  posición no existe.
     *  \ingroup MatrixGroup
     */
    double Get(unsigned int lin,unsigned int col) const;
    
    /** 
     *  \brief Retorna el valor en la posición (lin,col), hace una verificación
     *  si la posición existe. 
     *  \param[in] lin La linea en consulta.
     *  \param[in] col La columna en consulta.
     *  \return Retorna el valor en la posición (lin,col) o cero si la 
     *  posición no existe.
     *  \ingroup MatrixGroup
     */
    const double *GetPointer(unsigned int lin,unsigned int col) const;
    
    /** 
     *  \brief Escribe el valor en la posición (lin,col), hace una verificación
     *  si la posición existe. 
     *  \param[in] val valor a escribir.
     *  \param[in] lin La linea en consulta.
     *  \param[in] col La columna en consulta.
     *  \return Retorna true si consiguió escribir el valor en la 
     *  posicion (lin,col) o false si no.
     *  \ingroup MatrixGroup
     */
    bool Set(double val,unsigned int lin,unsigned int col);
    
    /** 
     *  \brief Retorna el valor en la posición (lin,col),  usando una
     *  interpolacion bilinear, valores fuera del rango de la matriz retornan cero.
     *
     *  \f[ return \leftarrow a_0 + a_1~lin+ a_2~col+ a_3~lin~col\f]
     *  \param[in] lin La linea en consulta.
     *  \param[in] col La columna en consulta.
     *  \return Retorna el valor en la posición (lin,col) o cero si lin<0
     *  o col<0 o lin>(Nlin-1) o col>(Ncol-1).
     *  \ingroup MatrixGroup
     */
    double GetBilinear(double lin,double col) const;
    
    /** 
     *  \brief Retorna el numero de lineas de la matriz.
     *  \return Retorna el numero de lineas de la matriz.
     *  \ingroup MatrixGroup
     */
    unsigned int Nlin() const;
    
    /** 
     *  \brief Retorna el numero de columnas de la matriz.
     *  \return Retorna el numero de columnas de la matriz.
     *  \ingroup MatrixGroup
     */
    unsigned int Ncol() const;
/**
 * @}
 */

public:

/** @name Métodos que trabajan con las lineas de la matriz
 *  operaciones con lineas
 * @{
 */
    /** 
     *  \brief Intercambia los valres de las lineas de una matriz.
     *  \param[in] lin1 Lineas a intercambiar.
     *  \param[in] lin2 Lineas a intercambiar.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool SwapRows(unsigned int lin1,unsigned int lin2);
    
    /** 
     *  \brief Si el n-avo elemento de la diagonal es cero entonces intercambia 
     *  la linea n de la matriz con cualquier linea inferior con elemento 
     *  diferente de cero en la columna n.
     *  \param[in] n Linea a intercambiar.
     *  \return Retorna el numero de la fila con quien intercambio o -1
     *  en caso de error. Si el n-avo 
     *  elemento de la diagonal ja es diferente de cero no se hace nada y
     *  se retorna n.
     *  \ingroup MatrixGroup
     */
    int DiagonalIsZeroSwapBelow(unsigned int n);

    /** 
     *  \brief Multiplica los valores de la linea lin2 por alfa y el 
     *  resultado es sumado a los valores de la linea lin1.
     * 
     *  \f[ row[lin1] \leftarrow row[lin1]+\alpha ~ row[lin2] \f]
     *  \param[in] lin1 Lineas a intercambiar.
     *  \param[in] lin2 Lineas a intercambiar.
     *  \param[in] alpha Factor multiplicador.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool AddAssigRow(unsigned int lin1,unsigned int lin2,double alpha);
    
    /** 
     *  \brief Multiplica la linea lin por alpha
     * 
     *  \f[ row[lin] \leftarrow \alpha ~ row[lin] \f]
     *  \param[in] lin Linea a multiplicar.
     *  \param[in] alpha Factor multiplicador.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool RowMul(unsigned int lin,double alpha);
    
    /** 
     *  \brief Divide la linea lin por alpha
     * 
     *  \f[ row[lin] \leftarrow  row[lin]/\alpha \f]
     *  \param[in] lin Linea a dividir.
     *  \param[in] alpha Factor multiplicador.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool RowDiv(unsigned int lin,double alpha);
    
    /** 
     *  \brief Convierte la matriz en una matriz reducida.
     * 
     *  \return Retorna true si todo fue bien o false si no.
     * Si retorna false la matriz es modificada hasta donde consiguió 
     * avanzar el proceso de reducción.
     *  \ingroup MatrixGroup
     */
    bool RowReduction(void);

/**
 * @}
 */


public:

/** @name Métodos variados
 *  Herramientas genéricas
 * @{
 */
    /** 
     *  \brief Calcula la 2-norm de un vector.
     *
     *  \f[ ||A||_2=\sqrt{\sum \limits_{i} \sum \limits_{j} {|a_{ij}|}^2} \f]
     *  \return Retorna la norma de un vector. En caso de que la matriz sea vacía
     *  se retorna 0.0.
     *  \ingroup MatrixGroup
     */
    double Norm(void) const;
    
    /** 
     *  \brief Calcula la 1-norm de un vector.
     *
     *  \f[ ||A||_1=\max \limits_{j} \sum \limits_{i} {|a_{ij}|} \f]
     *  \return Retorna la norma de un vector. En caso de que la matriz sea vacía
     *  se retorna 0.0.
     *  \ingroup MatrixGroup
     */
    double Norm1(void) const;
    
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
     *  \brief Imprime en pantalla el contenido de la matriz después del
     * texto indicado en str.
     * \param str Texto a mostrar antes de imprimir.
     *  \ingroup MatrixGroup
     */
    void Print(std::string str) const;
    
    /** 
     *  \brief Aplica la función func a cada elemento de la matriz.
     * \param[in] func Función a aplicar, esta debe tener a forma double func(double).
     * \return true si todo fue bien o false si la matriz era vacia.
     *  \ingroup MatrixGroup
     */
    bool Apply( double (*func)(double) );
    
   /** 
     *  \brief Escribe en un archivo el contenido de la matriz.
     *  \param[in] filepath El archivo donde se escribirán los datos.
     *  \return Retorna true si todo fue bien o false en caso de error.
     *  \ingroup MatrixGroup
     */
    bool Save(const char* filepath) const;

/**
 * @}
 */


public:

/** @name Métodos Static con Matrices
 *  Herramientas genéricas que pueden ser usadas desde Pds::Matrix
 * @{
 */
    
   /** 
     *  \brief Lee de un archivo una matriz de Nlin lineas y Ncol columnas.
     *  \param[in] filepath El archivo donde se leerán los datos.
     *  \return Retorna una matriz no vacia si todo fue bien o una matriz vacia en caso de error.
     *  \ingroup MatrixGroup
     */
    static Matrix Load(const char* filepath);

   /** 
     *  \brief Escribe en un archivo una matriz de Nlin lineas y Ncol columnas.
     *  \param[in] filepath El archivo donde se escribirán los datos.
     *  \param[in] A matriz a escribir.
     *  \return Retorna true si todo fue bien o false en caso de error.
     *  \ingroup MatrixGroup
     */
    static bool Save(const char* filepath,const Matrix &A);
/**
 * @}
 */


public:

/** @name Métodos Static con arrays
 *  Herramientas genéricas que pueden ser usadas desde Pds::Matrix
 * @{
 */
    /** 
     *  \brief crea dinámicamente un arreglo de A.Nlin() lineas y A.Ncol() columnas,
     *  con los datos copiados de aplicar func(A).
     *  \param[in] A Matriz de donde se copiaran datos.
     *  \param[in] func Función a aplicar, esta debe tener a forma double func(double).
     *  \return Retorna un puntero al arreglo, o NULL si no consiguió reservar
     * la memoria. Esta memoria debe ser liberada siempre com ReleaseArray
     *  \ingroup MatrixGroup
     */
    static double** AllocateArray(const Matrix &A,double (*func)(double));
    
    /** 
     *  \brief crea diamicamente un arreglo de A.Nlin() lineas y A.Ncol() columnas,
     *  con los datos copiados de una matriz A.
     *  \param[in] A Matriz de donde se copiaran datos.
     *  \return Retorna un puntero al arreglo, o NULL si no consiguio reservar
     * la memoria. Esta memoria debe ser liberada siempre com ReleaseArray
     *  \ingroup MatrixGroup
     */
    static double** AllocateArray(const Matrix &A);
    
    /** 
     *  \brief crea dinámicamente un arreglo de Nlin lineas y Ncol columnas,
     *  con elementos inicializado con un valor.
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \param[in] Ncol El numero de columnas en el arreglo.
     *  \param[in] val El valor a usar.
     *  \return Retorna un puntero al arreglo, o NULL si no consiguió reservar
     * la memoria. Esta memoria debe ser liberada siempre com ReleaseArray
     *  \ingroup MatrixGroup
     */
    static double** AllocateArray(unsigned int Nlin,unsigned int Ncol,double val);
    
    /** 
     *  \brief crea dinámicamente un arreglo de Nlin lineas y Ncol clumnas
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \param[in] Ncol El numero de columnas en el arreglo.
     *  \return Retorna un puntero al arreglo, o NULL si no consiguió reservar
     * la memoria. Esta memoria debe ser liberada siempre com ReleaseArray
     *  \ingroup MatrixGroup
     */
    static double** AllocateArray(unsigned int Nlin,unsigned int Ncol);

   /** 
     *  \brief Libera un arreglo de Nlin lineas y Ncol columnas (arreglo de arreglos)
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
     *  \param[out] array Donde se escribirá el arreglo de arreglos de de Nlin lineas y Ncol columnas.
     *  La función no libera a memoria de array, entonces se le debe entregar siempre un array==NULL.
     *  \param[out] Nlin Donde se escribirá el numero de lineas en el arreglo.
     *  \param[out] Ncol Donde se escribirá el numero de columnas en el arreglo.
     *  \return Retorna true si todo fue bien o false si no. Si el numero de columnas 
     *  no es constante se retorna false. Si la función retorna false entonces los valores
     *  de entrada no son alterados.
     *  \ingroup MatrixGroup
     */
    static bool LoadArray(const char* filepath,double** &array,unsigned int& Nlin,unsigned int& Ncol);

/**
 * @}
 */

public:

/** @name Operadores unarios y sus métodos equivalentes
 *  Descripción de algunos operadores habilitados a trabajar con Pds::Matrix.
 * @{
 */
    
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
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Matrix T(void) const;
    
    
    /** 
     *  \brief Retorna la matriz inversa.
     *
     *  \param[out] rcond Esta variable es cargada con el valor del
     *  reciproco del condicional de la matriz. Si esta es la matriz A,
     * rcond es:
     *  \f[ rcond \leftarrow \frac{1.0}{||A||_1 ||A^{-1}||_1} \f]
     * Si la matriz esta bien condicionada entonces rcond es próximo a 1.0 y si la matriz
     * esta pobremente condicionada este valor estará proximo a 0.0.
     * Si la variable rcond no es entregada entonces sera mostrado un mensaje
     * de advertencia por consola si el valor de rcond es menor a Pds::Ra::WarningRCond.
     *  \return Retorna la matriz inversa si todo fue bien o una matriz vacia si no.
     *  \ingroup MatrixGroup
     */
    Matrix Inv(double *rcond=NULL) const;
    
    
    /** 
     *  \brief Cambia de signo a si mismo (A), el resultado es
     * cargado en B. Este operador es similar al método unario Minus 
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
     *  resultado, o una matriz vazia (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Matrix operator -(void) const;
    
    /** 
     *  \brief Cambia de signo a si mismo (A), el resultado es
     * cargado en B. Este método es similar al operador unario - 
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
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Matrix Minus(void) const;
    
    /** 
     *  \brief Asigna el signo + a si mismo (A), el resultado es
     * cargado en B. Este operador es similar al método unario Plus 
     *
     *  \f[ B \leftarrow +A \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B;
    
    A.Fill(2.0);
    
    B=+A;
    
    std::cout<<B;
\endcode
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Matrix operator +(void) const;
    
    /** 
     *  \brief Asigna el signo + a si mismo (A), el resultado es
     * cargado en B. Este metodo es similar al operador unario + 
     *
     *  \f[ B \leftarrow +A \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B;
    
    A.Fill(2.0);
    
    B=A.Plus();
    
    std::cout<<B;
\endcode
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vazia (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Matrix Plus(void) const;
/**
 * @}
 */
    
    
/** @name Operadores binarios y sus métodos equivalentes
 *  Descripcion de algunos operadores habilitados a trabajar con Pds::Matrix.
 * @{
 */
    
    /** 
     *  \brief Suma con sigo mismo (A), un valor b y el resultado es
     * cargado en C. Este operador 
     *  es similar al método Add() 
     *
     *  \f[ C \leftarrow A+b \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    
    C=A+2.0;
    
    std::cout<<C;
\endcode
     *  \param[in] b El valor a sumar
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vazia (this->IsEmpty() igual a true) en caso de error.
     *  \see Add
     *  \ingroup MatrixGroup
     */
    Matrix operator + (double b) const;
    
    /** 
     *  \brief Suma con sigo mismo (A), una valor b y el resultado es
     * cargado en C. Este método 
     *  es similar al operador + 
     *
     *  \f[ C \leftarrow A+b \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    
    C=A.Add(2.0);
    
    std::cout<<C;
\endcode
     *  \param[in] b El valor a sumar
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vazia (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Matrix Add(double b) const;
    
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
     *  resultado, o una matriz vazia (this->IsEmpty() igual a true) en caso de error.
     *  \see Add
     *  \ingroup MatrixGroup
     */
    Matrix operator + (const Matrix &B) const;
    
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
     *  resultado, o una matriz vazia (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Matrix Add(const Matrix &B) const;
    
    /** 
     *  \brief Resta con sigo mismo (A), un valor b y el resultado es
     * cargado en C. Este operador 
     *  es similar al método Sub() 
     *
     *  \f[ C \leftarrow A-b \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    
    C=A-2.0;
    
    std::cout<<C;
\endcode
     *  \param[in] b El valor a restar
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vazia (this->IsEmpty() igual a true) en caso de error.
     *  \see Add
     *  \ingroup MatrixGroup
     */
    Matrix operator - (double b) const;
    
    /** 
     *  \brief Resta con sigo mismo (A), una valor b y el resultado es
     * cargado en C. Este método 
     *  es similar al operador - 
     *
     *  \f[ C \leftarrow A-b \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    
    C=A.Sub(2.0);
    
    std::cout<<C;
\endcode
     *  \param[in] b El valor a restar
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vazia (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Matrix Sub(double b) const;
    
    
    /** 
     *  \brief Resta con sigo mismo (A), una matriz B y el resultado es
     * cargado en C. Este operador es similar al metodo Sub
     *
     *  \f[ C \leftarrow A-B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    B.Fill(1.0);
    
    C=A-B;
    
    std::cout<<C;
\endcode
     *  \param[in] B la matriz que resta
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vazia (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Matrix operator -(const Matrix &B) const;
    
    /** 
     *  \brief Resta con sigo mismo (A), una matriz B y el resultado es
     * cargado en C. Este metodo es similar al operador - 
     *
     *  \f[ C \leftarrow A-B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    B.Fill(1.0);
    
    C=A.Sub(B);
    
    std::cout<<C;
\endcode
     *  \param[in] B la matriz que resta
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vazia (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Matrix Sub(const Matrix &B) const;
    
    /** 
     *  \brief Multiplica con sigo mismo (A), un valor b y el resultado es
     * cargado en C. Este operador es similar al método Mul() 
     *
     *  \f[ C \leftarrow A*b \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    
    C=A*2.0;
    
    std::cout<<C;
\endcode
     *  \param[in] b el valor a multiplicar
     *  \return Retorna C con el
     *  resultado, o una matriz vazia (this->IsEmpty() igual a true) en caso de error.
     *  \see Mul
     *  \ingroup MatrixGroup
     */
    Matrix operator * (double b) const;
    
    /** 
     *  \brief Multiplica con sigo mismo (A), un valor b y el resultado es
     * cargado en C. Este método  es similar al operador * 
     *
     *  \f[ C \leftarrow A*b \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    
    C=A.Mul(2.0);
    
    std::cout<<C;
\endcode
     *  \param[in] b el valor a multiplicar
     *  \return Retorna C con el
     *  resultado, o una matriz vazia (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Matrix Mul(double b) const;
    
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
     *  resultado, o una matriz vazia (this->IsEmpty() igual a true) en caso de error.
     *  \see Mul
     *  \ingroup MatrixGroup
     */
    Matrix operator * (const Matrix &B) const;
    
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
     *  resultado, o una matriz vazia (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Matrix Mul(const Matrix &B) const;
/**
 * @}
 */
    
    
/** @name Operadores binarios acumuladores y sus métodos equivalentes
 *  Descripción de algunos operadores habilitados a trabajar con Pds::Matrix.
 * @{
 */
    
    /** 
     *  \brief Resta y acumula en si mismo (B), una matriz A. Este operador 
     *  es similar al método SubAssig() 
     *
     *  \f[ A \leftarrow A-B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(4,4);
    B.Fill(1.0);
    A-=B;
\endcode
     *  \param[in] B la matriz a substraer
     *  \return Retorna el operador de la izquierda (acumulador) con el
     *  resultado, o una matriz vazia (this->IsEmpty() igual a true) en caso de error.
     *  \see SubAssig
     *  \ingroup MatrixGroup
     */
    Matrix& operator -=(const Matrix &B);

    /** 
     *  \brief Resta y acumula en si mismo (B), una matriz A. Este es similar al
     *  operador -= 
     *
     *  \f[ A \leftarrow A-B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(4,4);
    B.Fill(1.0);
    A.SubAssig(B);
\endcode
     *  \param[in] B la matriz que substrae
     *  \return Retorna true si todo fue bien o false si no. Si se retorna false
     *  el acumulador no altera su contenido.
     *  \ingroup MatrixGroup
     */
    bool SubAssig(const Matrix &B);
    
    /** 
     *  \brief Suma y acumula en si mismo (B), una matriz A. Este operador 
     *  es similar al método AddAssig() 
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
     *  resultado, o una matriz vazia (this->IsEmpty() igual a true) en caso de error.
     *  \see AddAssig
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
    A.AddAssig(B);
\endcode
     *  \param[in] B la matriz a acumular
     *  \return Retorna true si todo fue bien o false si no. Si se retorna false
     *  el acumulador no altera su contenido.
     *  \ingroup MatrixGroup
     */
    bool AddAssig(const Matrix &B);
    
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
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \see Copy
     *  \ingroup MatrixGroup
     */
    Matrix& operator = (const Matrix &A);
    
    /** 
     *  \brief Copia en si mismo (B), el contenido de una matriz A. Este 
     *  método es similar a usar el operador = 
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
     *  convierte a la matriz A en una matriz vacia.
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
     *  \brief Suma con sigo mismo (A), un valor b y el resultado es
     * cargado en C. Este operador 
     *  es similar al método Add() 
     *
     *  \f[ C \leftarrow b+A \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    
    C=2.0+A;
    
    std::cout<<C;
\endcode
     *  \param[in] b El valor a sumar
     *  \param[in] mat matriz a sumar
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vazia (this->IsEmpty() igual a true) en caso de error.
     *  \see Add
     *  \ingroup MatrixGroup
     */
Pds::Matrix operator+(double b,const Pds::Matrix &mat);

    /** 
     *  \brief Resta con sigo mismo (A), un valor b y el resultado es
     * cargado en C. Este operador 
     *  es similar al método Add() 
     *
     *  \f[ C \leftarrow b-A \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    
    C=2.0-A;
    
    std::cout<<C;
\endcode
     *  \param[in] b El valor a operar
     *  \param[in] mat matriz a restar
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vazia (this->IsEmpty() igual a true) en caso de error.
     *  \see Sub
     *  \ingroup MatrixGroup
     */
Pds::Matrix operator-(double b,const Pds::Matrix &mat);

    /** 
     *  \brief Multiplica con sigo mismo (A), un valor b y el resultado es
     * cargado en C. Este operador 
     *  es similar al método Mul() 
     *
     *  \f[ C \leftarrow b*A \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    
    C=2.0*A;
    
    std::cout<<C;
\endcode
     *  \param[in] b El valor a operar
     *  \param[in] mat matriz a multiplicar
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vazia (this->IsEmpty() igual a true) en caso de error.
     *  \see Mul
     *  \ingroup MatrixGroup
     */
Pds::Matrix operator*(double b,const Pds::Matrix &mat);

/**
 * @}
 */

/**
 * @}
 */

#endif

