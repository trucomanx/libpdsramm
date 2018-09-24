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


/** \defgroup MatrixGroup Métodos de Pds::Matrix
 *  \brief Métodos de la clase Pds::Matrix, una matriz 
 *  <div class="fragment"> \#include <Pds/Matrix> </div>
 *  
 *  <br>Estas funciones trabajan con una matriz de la forma.<br>
 * 
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
 *  
 *  \b Nlin es el número de lineas y \b Ncol es el número de columnas.
 *  
 * Información adicional puede ser encontrada en @cite tutorialmatvec
 * @{
 */


#include <string>
#include <Pds/Size>
#include <Pds/RaDefines>

namespace Pds{

class Vector;

/*! \class Matrix
 *  \brief La clase tipo  Pds::Matrix .
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
\mathbf{A}=A_{0,0}\equiv []_{0,0}
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
     * 
   \f[
\mathbf{A}=\left(\begin{matrix}
0 & 0 & \hdots & 0\\ 
0 & 0 & \hdots & 0\\
\vdots & \vdots & \vdots & \vdots \\
0 & 0 & \hdots & 0\\ 
0 & 0 & \hdots & 0\\
\end{matrix}\right)\equiv A_{N,N}
   \f]
   \f[
A_{N,N}\equiv [0]_{N,N}
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
     * 
   \f[
\mathbf{A}=\left(\begin{matrix}
0 & 0 & \hdots & 0\\ 
0 & 0 & \hdots & 0\\
\vdots & \vdots & \vdots & \vdots \\
0 & 0 & \hdots & 0\\ 
0 & 0 & \hdots & 0\\
\end{matrix}\right)\equiv A_{Nlin,Ncol}
   \f]
   \f[
A_{Nlin,Ncol}\equiv [0]_{Nlin,Ncol}
   \f]
   Para crear una matriz A de 4 filas y 3 columnas:
\code{.cpp}
    Pds::Matrix B(4,3);
    Pds::Matrix A(B.Size);
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] S El tamaño de la matriz.
     *  \ingroup MatrixGroup
     */
    Matrix(const Pds::Size &S);

    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix copiando datos desde 
     *  otra matriz. Este es un Copy assignment constructor.
     * 
   \f[
B_{Nlin,Ncol}\equiv [b_{i,j}]_{Nlin,Ncol}
   \f]
   \f[
\mathbf{A} \leftarrow \mathbf{B}
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
    Matrix(const Pds::Matrix &B);
    


    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix copiando datos desde 
     *  una cadena.
     * 
   Para crear una matriz A con los datos de una cadena:
\code{.cpp}
    Pds::Matrix A="1 2 3\n4 5 6\n";
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] str Cadena a leer.
     *  \ingroup MatrixGroup
     */
    Matrix(const char *str);
    
    
    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix con elementos inicializados con cero.
     * 
   \f[
\mathbf{A}=\left(\begin{matrix}
0 & 0 & \hdots & 0\\ 
0 & 0 & \hdots & 0\\
\vdots & \vdots & \vdots & \vdots \\
0 & 0 & \hdots & 0\\ 
0 & 0 & \hdots & 0\\
\end{matrix}\right)\equiv A_{Nlin,Ncol}
   \f]
   \f[
A_{Nlin,Ncol}\equiv [0]_{Nlin,Ncol}
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
     * 
   \f[
\mathbf{A}=\left(\begin{matrix}
val & val & \hdots & val\\ 
val & val & \hdots & val\\
\vdots & \vdots & \vdots & \vdots \\
val & val & \hdots & val\\ 
val & val & \hdots & val\\
\end{matrix}\right)\equiv A_{Nlin,Ncol}
   \f]
   \f[
A_{Nlin,Ncol}\equiv [val]_{Nlin,Ncol}
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
     *  \brief Crea un objeto de tipo Pds::Matrix, evaluando mediante una función, 
     *  los datos de otra matriz.
     * 
   \f[
B_{Nlin,Ncol}\equiv [b_{i,j}]_{Nlin,Ncol}
   \f]
   \f[
\mathbf{A} \leftarrow func(\mathbf{B})
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
    Matrix(double (*func)(double),const Pds::Matrix &B );
    

    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix copiando datos desde 
     *  un archivo.
     * 
\code{.cpp}
    Pds::Matrix A(Pds::Ra::TextFormat,"textfile.txt");
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] Type Tipo de archivo de fuente de datos. Los tipos aceptados son:
     *  <table>
     *  <tr><td> Pds::Ra::TextFormat    <td> Lee en formato de texto.
     *  </table>
     *  \param[in] filepath Path del archivo cargado.
     *  \ingroup MatrixGroup
     */
    Matrix(Pds::Ra::FormatType Type,std::string filepath);
    
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
     *  Una matriz\f$\mathbf{A}\f$ está vacía si  \f$ \mathbf{A}=[]_{0,0}\f$.
     *  \return Retorna true si es nula e false si no.
     *  \ingroup MatrixGroup
     */
    bool IsEmpty(void) const;

    /** 
     *  \brief Verifica si la matriz NO es nula, es decir con lineas y columnas diferentes cero y arreglo diferente de NULL.
     * 
     *  Una matriz \f$\mathbf{A}\f$ está vacía si  \f$ \mathbf{A}=[]_{0,0}\f$.
     *  \return Retorna true si NO es nula e false si lo es.
     *  \ingroup MatrixGroup
     */
    bool IsNotEmpty(void) const;


    /** 
     *  \brief Verifica si las matrices son similares en tamaño.
     * 
     *  Una matriz\f$A_{M,N}\f$ es similar a \f$B_{P,Q}\f$ 
     *  si  \f$M=P\f$ y \f$N=Q\f$.
     *  \param[in] B Matriz en consulta.
     *  \return Retorna true si son similares y false si no.
     *  \ingroup MatrixGroup
     */
    bool IsSimilarTo(const Pds::Matrix &B) const;

    /** 
     *  \brief Verifica si las matrices son similares en tamaño.
     * 
     *  Una matriz\f$A_{M,N}\f$ es similar a \f$B_{P,Q}\f$ 
     *  si  \f$M=P\f$ y \f$N=Q\f$.
     *  \param[in] B Matriz en consulta.
     *  \return Retorna false si son similares y true si no.
     *  \ingroup MatrixGroup
     */
    bool IsNotSimilarTo(const Pds::Matrix &B) const;
    
    /** 
     *  \brief Verifica si las matrices son multiplicables.
     * 
     *  Una matriz\f$A_{M,N}\f$ es multiplicable por \f$B_{P,Q}\f$ 
     *  si  \f$N=P\f$ y ambas son no vacías.
     *  \param[in] B Matriz en consulta.
     *  \return Retorna true si son multiplicables y false si no.
     *  \ingroup MatrixGroup
     */
    bool IsMulBy(const Pds::Matrix &B) const;

    /** 
     *  \brief Verifica si las matrices son multiplicables.
     * 
     *  Una matriz\f$A_{M,N}\f$ es multiplicable por \f$B_{P,Q}\f$ 
     *  si  \f$N= P\f$ y ambas son no vacías.
     *  \param[in] B Matriz en consulta.
     *  \return Retorna false si son multiplicables y true si no.
     *  \ingroup MatrixGroup
     */
    bool IsNotMulBy(const Pds::Matrix &B) const;

    /** 
     *  \brief Verifica si la posición pertenece a la matriz.
     * 
     *  Dada una matriz\f$A_{M,N}\f$; la posición \f$(lin,col)\f$ 
     *  está en rango de \f$\mathbf{A}\f$ si cualquier valor entero de \f$0\leq lin \leq M-1\f$
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
     *  Dada una matriz\f$A_{M,N}\f$; la posición \f$(lin,col)\f$ 
     *  está en rango de \f$\mathbf{A}\f$ si cualquier valor entero de \f$0\leq lin \leq M-1\f$
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
     *  Dada una matriz\f$A_{M,N}\f$; la posición \f$(lin,col)\f$ 
     *  está en rango de \f$\mathbf{A}\f$ si cualquier valor real de \f$0\leq lin \leq M-1\f$
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
   \f[
\left(\begin{matrix}
0 & 0 & \hdots & 0\\ 
0 & 0 & \hdots & 1\\
\vdots & \vdots & \vdots & \vdots \\
1 & 0 & \hdots & 0\\ 
0 & 1 & \hdots & 0\\
\end{matrix}\right) \overleftarrow{IsInf} \left(\begin{matrix}
1 & NaN & \hdots & NaN\\ 
0 & 2 & \hdots & -\infty\\
\vdots & \vdots & \vdots & \vdots \\
\infty & 0 & \hdots & 0\\ 
3 & -\infty & \hdots & NaN\\
\end{matrix}\right)
   \f]
     *  \return Retorna una nueva matriz con 1 donde es infinito y 0 donde no lo es.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix IsInf(void) const;
    
    /** 
     *  \brief Verifica si la matriz tiene elementos con valores NAN (Not A Number).
     * 
     *  Los valores NAN pueden producirse con \f$\frac{0}{0}\f$.
   \f[
\left(\begin{matrix}
0 & 1 & \hdots & 1\\ 
0 & 0 & \hdots & 0\\
\vdots & \vdots & \vdots & \vdots \\
0 & 0 & \hdots & 0\\ 
0 & 0 & \hdots & 1\\
\end{matrix}\right) \overleftarrow{IsNan} \left(\begin{matrix}
1 & NaN & \hdots & NaN\\ 
0 & 2 & \hdots & -\infty\\
\vdots & \vdots & \vdots & \vdots \\
\infty & 0 & \hdots & 0\\ 
3 & -\infty & \hdots & NaN\\
\end{matrix}\right)
   \f]
     *  \return Retorna una nueva matriz con 1 donde es NAN y 0 donde no lo es.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix IsNan(void) const;
    
    /** 
     *  \brief Verifica si la matriz tiene elementos con valores finitos (no +inf, no -inf y no NAN).
     * 
   \f[
\left(\begin{matrix}
1 & 0 & \hdots & 0\\ 
1 & 1 & \hdots & 0\\
\vdots & \vdots & \vdots & \vdots \\
0 & 1 & \hdots & 1\\ 
1 & 0 & \hdots & 0\\
\end{matrix}\right) \overleftarrow{IsFinite} \left(\begin{matrix}
1 & NaN & \hdots & NaN\\ 
0 & 2 & \hdots & -\infty\\
\vdots & \vdots & \vdots & \vdots \\
\infty & 0 & \hdots & 0\\ 
3 & -\infty & \hdots & NaN\\
\end{matrix}\right)
   \f]
     *  \return Retorna una nueva matriz con 1 donde es finito y 0 donde no lo es.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix IsFinite(void) const;
    
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
     * 
   \f[ f_{X}(x)=\frac {1}{\sqrt {2\pi }} e^{-{\frac {1}{2}}x^{2}},~~x \in R \f]
   \f[ \mathbf{A}\equiv [a_{i,j}]_{M,N} \f]
   \f[ a_{i,j}\leftarrow X_{l} \in X \f]
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool FillRandN(void);
    
    /** 
     *  \brief Inicializa la matriz con números aleatorios, distribuidos uniformemente,
     *  desde 0 a 1.0, incluyendo 0 y excluyendo 1.0.
     * 
   \f[ f_{X}(x)= 1,~~0\leq x<1, x \in R \f]
   \f[ \mathbf{A}\equiv [a_{i,j}]_{M,N} \f]
   \f[ a_{i,j}\leftarrow X_{l} \in X \f]
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool FillRandU(void);
    
    /** 
     *  \brief Inicializa la matriz con números aleatorios, distribuidos uniformemente,
     *  desde 0 a 1.0, incluyendo 0 y excluyendo 1.0.
     * 
   \f[ f_{X}(x)= 1,~~min(a,b)\leq x\leq max(a,b), x \in R \f]
   \f[ \mathbf{A}\equiv [a_{i,j}]_{M,N} \f]
   \f[ a_{i,j}\leftarrow X_{l} \in X \f]
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool FillRandU(int a, int b);
    
    /** 
     *  \brief Inicializa la matriz con números aleatorios, distribuidos uniformemente,
     *  desde 0 a 1.0, incluyendo 0 y excluyendo 1.0.
     * 
   \f[ f_{X}(x)= 1,~~min(a,b)\leq x\leq max(a,b), x \in R \f]
   \f[ \mathbf{A}\equiv [a_{i,j}]_{M,N} \f]
   \f[ a_{i,j}\leftarrow X_{l} \in X \f]
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool FillRandU(double a, double b);
    
    /** 
     *  \brief Inicializa la matriz con el valor de la posición de cada elemento.
     * 
     * En el caso de una matriz A de 4 lineas y 3 columnas:
   \f[
\mathbf{A} \leftarrow \left(\begin{matrix}
0 & 4 & 8\\ 
1 & 5 & 9\\
2 & 6 & 10\\ 
3 & 7 & 11\\
\end{matrix}\right)
   \f]
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool FillId(void );

    /** 
     *  \brief Inicializa la matriz con un valor constante.
     * 
   \f[
\mathbf{A} \leftarrow \left(\begin{matrix}
val & val & \hdots & val\\ 
val & val & \hdots & val\\
\vdots & \vdots & \vdots & \vdots \\
val & val & \hdots & val\\ 
val & val & \hdots & val\\
\end{matrix}\right)
   \f]
     *  \param[in] val El valor a ser usado.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool Fill(double val);

    /** 
     *  \brief Inicializa la matriz con un espacio linear entre begin y end.
     *  Se inicializa primero una columna ante de pasar ala siguiente.
     * 
     * En el caso de una matriz A de Nlin=4 lineas y Ncol=3 columnas:
   \f[\alpha= \frac{b-a}{Nlin~Ncol- 1}\f]
   \f[
\mathbf{A} \leftarrow \left(\begin{matrix}
a         & 4\alpha+a & 8\alpha+a\\ 
\alpha+a  & 5\alpha+a & 9\alpha+a\\
2\alpha+a & 6\alpha+a & 10\alpha+a\\ 
3\alpha+a & 7\alpha+a & 11\alpha+a\\
\end{matrix}\right)
   \f]
     *  \param[in] a El valor inicial.
     *  \param[in] b El valor final.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool FillLinSpace(double a,double b);
/**
 * @}
 */

public:

/** @name Métodos get y set
 *  Herramientas genéricas para lectura y escritura de datos.
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
     *  \brief Retorna un puntero a la posición (lin,col), hace una verificación
     *  si la posición existe. 
     *  \param[in] lin La linea en consulta.
     *  \param[in] col La columna en consulta.
     *  \return Retorna el valor en la posición (lin,col) o cero si la 
     *  posición no existe.
     *  \ingroup MatrixGroup
     */
    const double *Pointer(unsigned int lin,unsigned int col) const;
    
    /** 
     *  \brief Retorna el valor en la posición (lin,col),  usando una
     *  interpolación bilinear, valores fuera del rango de la matriz retornan cero.
     *
     *  \f[ return \leftarrow a_0 + a_1~lin+ a_2~col+ a_3~lin~col\f]
     *  \param[in] lin La linea en consulta.
     *  \param[in] col La columna en consulta.
     *  \return Retorna el valor en la posición (lin,col) o cero si lin<0
     *  o col<0 o lin>(Nlin-1) o col>(Ncol-1).
     *  \ingroup MatrixGroup
     */
    double Bilinear(double lin,double col) const;
    
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
     *  \brief Retorna el numero de elementos de la matriz (Nlin x Ncol).
     *  \return Retorna el numero de elementos de la matriz.
     *  \ingroup MatrixGroup
     */
    unsigned int Nel() const;
    
/**
 * @}
 */

public:

/** @name Métodos get y set, extras
 *  Herramientas genericas para lectura y escritura de datos.
 * @{
 */
 
    /** 
     *  \brief Retorna un vector columna copia de los valores de la diagonal de la matriz. 
     *  \return Retorna el vector columna en la posición (col) o un vector vacío
     *  en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Vector GetDiagonal(void) const;
    
    /** 
     *  \brief Copia un vector columna en una diagonal de la matriz. Si los 
     *  tamaños son diferentes, se interceptan las matrices y se copia 
     *  solamente en la intersección.
     *  \param[in] V El vector a copiar.
     *  \return Retorna true si la copia fue hecha 
     *  o false si hubo algún problema. En caso de retornar false no se modifica la matriz.
     *  \ingroup MatrixGroup
     */
    bool SetDiagonal(const Pds::Vector V);
    
    /** 
     *  \brief Retorna un vector columna copia de una columna de la matriz. 
     *  \param[in] col La columna en consulta.
     *  \return Retorna el vector columna en la posición (col) o un vector vacío si la 
     *  posición no existe.
     *  \ingroup MatrixGroup
     */
    Pds::Vector GetColVector(unsigned int col) const;
    
    /** 
     *  \brief Copia un vector columna en una columna de la matriz. Si los 
     *  tamaños son diferentes, se interceptan las matrices y se copia 
     *  solamente en la intersección.
     *  \param[in] V El vector a copiar.
     *  \param[in] col La columna en consulta.
     *  \return Retorna true si la copia fue hecha y la posición (col) existe
     *  o false si hubo algún problema. En caso de retornar false no se modifica la matriz.
     *  \ingroup MatrixGroup
     */
    bool SetColVector(const Pds::Vector V,unsigned int col);
    
    /** 
     *  \brief Copia un vector columna en una columna de la matriz, despues
     *  de evaluar el vector en una funcion. Si los 
     *  tamaños son diferentes, se interceptan las matrices y se copia 
     *  solamente en la intersección.
     *  \param[in] func funcion a evaluar.
     *  \param[in] V El vector a evaluar y copiar.
     *  \param[in] col La columna en consulta.
     *  \return Retorna true si la copia fue hecha y la posición (col) existe
     *  o false si hubo algún problema. En caso de retornar false no se modifica la matriz.
     *  \ingroup MatrixGroup
     */
    bool SetColVector(double (*func)(double),const Pds::Vector V,unsigned int col);
    
    /** 
     *  \brief Copia un vector columna en una columna de la matriz, despues
     *  de evaluar el vector en una funcion. Si los 
     *  tamaños son diferentes, se interceptan las matrices y se copia 
     *  solamente en la intersección.
     *  \param[in] func funcion a evaluar.
     *  \param[in] V El vector a evaluar y copiar.
     *  \param[in] var Segunda variable a evaluar.
     *  \param[in] col La columna en consulta.
     *  \return Retorna true si la copia fue hecha y la posición (col) existe
     *  o false si hubo algún problema. En caso de retornar false no se modifica la matriz.
     *  \ingroup MatrixGroup
     */
    bool SetColVector(double (*func)(double,double),const Pds::Vector V,double var,unsigned int col);
    
        
    /** 
     *  \brief Retorna un objeto de tipo Pds::Size con el numero de lineas y columans.
     *  \return Retorna el tamano de la matriz.
     *  \ingroup MatrixGroup
     */
    Pds::Size Size(void) const;
/**
 * @}
 */


public:

/** @name Métodos que trabajan con las lineas de la matriz
 *  operaciones con lineas
 * @{
 */
    /** 
     *  \brief Intercambia los valores de las lineas de una matriz.
     *  \param[in] lin1 Lineas a intercambiar.
     *  \param[in] lin2 Lineas a intercambiar.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool RowSwap(unsigned int lin1,unsigned int lin2);
    
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
    int RowDizSwapBelow(unsigned int n);

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
    bool RowAddAssig(unsigned int lin1,unsigned int lin2,double alpha);
    
    /** 
     *  \brief Multiplica la linea lin por alpha
     * 
     *  \f[ row[lin] \leftarrow \alpha ~ row[lin] \f]
     *  \param[in] lin Linea a multiplicar.
     *  \param[in] alpha Factor multiplicador.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool RowMulAssig(unsigned int lin,double alpha);
    
    /** 
     *  \brief Divide la linea lin por alpha
     * 
     *  \f[ row[lin] \leftarrow  row[lin]/\alpha \f]
     *  \param[in] lin Linea a dividir.
     *  \param[in] alpha Factor multiplicador.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool RowDivAssig(unsigned int lin,double alpha);
    
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

/** @name Métodos estadísticos
 *  Herramientas genéricas
 * @{
 */
    /** 
     *  \brief Calcula el valor de la suma de elementos de la matriz.
     *
     *  \return Retorna el valor de la suma de elementos de la matriz. En caso de que la matriz sea vacía
     *  se retorna 0.0.
     *  \ingroup MatrixGroup
     */
    double Sum(void) const;
      
    /** 
     *  \brief Calcula el valor medio de la matriz.
     *
     *  \return Retorna el valor medio de la matriz. En caso de que la matriz sea vacía
     *  se retorna 0.0.
     *  \ingroup MatrixGroup
     */
    double Mean(void) const;
    
    /** 
     *  \brief Calcula el valor del desvío padrón de la matriz.
     *
     *  \return Retorna el valor del desvío padrón de la matriz. En caso de que la matriz sea vacía
     *  se retorna 0.0.
     *  \ingroup MatrixGroup
     */
    double Std(double *mean=NULL) const;

    
    /** 
     *  \brief Calcula la correlación de Pearson con la matriz.
     *
     *  \return Retorna el valor de la correlación. En caso de que la matriz sea vacía
     *  se retorna 0.0.
     *  \ingroup MatrixGroup
     */
    double Corr(const Pds::Matrix &B) const;
    
    /** 
     *  \brief Calcula el máximo valor del valor absoluto de la matriz.
     *
     *  \param[in] id Se retorna el id do valor máximo.
     *  \return Retorna el máximo valor del valor absoluto de la matriz. En caso de que la matriz sea vacía
     *  se retorna 0.0.
     *  \ingroup MatrixGroup
     */
    double MaxAbs(unsigned int *id=NULL) const;
    
    /** 
     *  \brief Calcula el mínimo valor del valor absoluto de la matriz.
     *
     *  \param[in] id Se retorna el id do valor mínimo.
     *  \return Retorna el mínimo valor del valor absoluto de la matriz. En caso de que la matriz sea vacía
     *  se retorna 0.0.
     *  \ingroup MatrixGroup
     */
    double MinAbs(unsigned int *id=NULL) const;
    
    /** 
     *  \brief Calcula el máximo valor de la matriz.
     *
     *  \param[in] id Se retorna el id do valor máximo.
     *  \return Retorna el máximo valor de la matriz. En caso de que la matriz sea vacía
     *  se retorna 0.0.
     *  \ingroup MatrixGroup
     */
    double Max(unsigned int *id=NULL) const;
    
    /** 
     *  \brief Calcula el mínimo valor de la matriz.
     *
     *  \param[in] id Se retorna el id do valor mínimo.
     *  \return Retorna el mínimo valor de la matriz. En caso de que la matriz sea vacía
     *  se retorna 0.0.
     *  \ingroup MatrixGroup
     */
    double Min(unsigned int *id=NULL) const;
/**
 * @}
 */


public:

/** @name Métodos de base para calculos de álgebra lineal
 *  Herramientas genéricas
 * @{
 */
    
    /** 
     *  \brief Calcula el producto punto entre dos matrices.
     *
     *  \f[ \mathbf{A} \equiv [a_{i,j}]_{Nlin,Ncol}  \f]
     *  \f[ \mathbf{B} \equiv [b_{i,j}]_{Nlin,Ncol}  \f]
     *  \f[ d \leftarrow \sum \limits_{i,j} a_{i,j}b_{i,j} \f]
     *  \param[in] B Matriz a multiplicar.
     *  \return Retorna la norma de un vector. En caso de que la matriz sea vacía
     *  se retorna 0.0.
     *  \ingroup MatrixGroup
     */
    double Dot(const Pds::Matrix &B) const;
    
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
 * @}
 */


public:

/** @name Métodos variados
 *  Herramientas genéricas
 * @{
 */

    /** 
     *  \brief libera los datos internos de la matriz y la convierte en una matriz nula.
     *  es decir con lineas y columnas cero.
     * 
     *  Una matriz\f$\mathbf{A}\f$ está vacía si  \f$ \mathbf{A}=[]_{0,0}\f$.
     *  \ingroup MatrixGroup
     */
    void MakeEmpty(void);
    
    /** 
     *  \brief Convierte los datos de la matriz en un std::string.
     *  \return Retorna un std::string. Si la matriz es nula retorna un string sin caracteres.
     *  \ingroup MatrixGroup
     */
    std::string ToString(void) const;


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
     *  \brief Escribe en un archivo de texto el contenido de la matriz.
     *  \param[in] filepath El archivo donde se escribirán los datos.
     *  \return Retorna true si todo fue bien o false en caso de error.
     *  \ingroup MatrixGroup
     */
    bool Save(const char* filepath) const;

   /** 
     *  \brief Escribe en un archivo de cualquier tipo el contenido de la matriz.
     *  \param[in] type El formato del archivo. Los tipos aceptados son:
     *  <table>
     *  <tr><td> Pds::Ra::TextFormat    <td> Escribe en formato de texto.
     *  <tr><td> Pds::Ra::MatFileFormat <td> Escribe en formato binario, MAT-File 1.0 de MATLAB.
     *  </table>
     *  \param[in] filepath El archivo donde se escribirán los datos.
     *  \return Retorna true si todo fue bien o false en caso de error.
     *  \ingroup MatrixGroup
     */
    bool Write(Pds::Ra::FormatType type,const char* filepath) const;
    

/**
 * @}
 */


public:

/** @name Métodos Static con Matrices
 *  Herramientas genéricas que pueden ser usadas desde Pds::Matrix
 * @{
 */
    
   /** 
     *  \brief Crea una nueva martiz con el resultado de func(B).
     *
     *  \f[ A_\leftarrow func(B) \f]
     *  \param[in] func La función evaluadora.
     *  \param[in] B La matriz a evaluar.
     *  \return Retorna una matriz evaluada.
     *  \ingroup MatrixGroup
     */
    static Pds::Matrix Apply(double (*func)(double),const Pds::Matrix &B);
    
   /** 
     *  \brief Lee de un archivo una matriz de Nlin lineas y Ncol columnas.
     *  \param[in] filepath El archivo donde se leerán los datos.
     *  \return Retorna una matriz no vacia si todo fue bien o una matriz vacia en caso de error.
     *  \ingroup MatrixGroup
     */
    static Pds::Matrix Load(const char* filepath);

   /** 
     *  \brief Escribe en un archivo una matriz de Nlin lineas y Ncol columnas.
     *  \param[in] filepath El archivo donde se escribirán los datos.
     *  \param[in] A matriz a escribir.
     *  \return Retorna true si todo fue bien o false en caso de error.
     *  \ingroup MatrixGroup
     */
    static bool Save(const char* filepath,const Pds::Matrix &A);
    

    /** 
     *  \brief Convierte un sdt::string a una Matriz de Nlin lineas y Ncol columnas.
     *  \param[in] str Cadena a leer.
     *  \return Retorna una matriz. en caso de error se retorna una matriz vacía.
     *  \ingroup MatrixGroup
     */
    static Pds::Matrix FromString(const std::string &str);
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
     * la memoria. Esta memoria debe ser liberada siempre com ArrayRelease
     *  \ingroup MatrixGroup
     */
    static double** ArrayAllocate(double (*func)(double),const Pds::Matrix &A);
    
    /** 
     *  \brief crea dinámicamente un arreglo de A.Nlin() lineas y A.Ncol() columnas,
     *  con los datos copiados de una matriz A.
     *  \param[in] A Matriz de donde se copiaran datos.
     *  \return Retorna un puntero al arreglo, o NULL si no consiguió reservar
     * la memoria. Esta memoria debe ser liberada siempre com ArrayRelease
     *  \ingroup MatrixGroup
     */
    static double** ArrayAllocate(const Pds::Matrix &A);
    
    /** 
     *  \brief crea dinámicamente un arreglo de Nlin lineas y Ncol columnas,
     *  con elementos inicializado con un valor.
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \param[in] Ncol El numero de columnas en el arreglo.
     *  \param[in] val El valor a usar.
     *  \return Retorna un puntero al arreglo, o NULL si no consiguió reservar
     * la memoria. Esta memoria debe ser liberada siempre com ArrayRelease
     *  \ingroup MatrixGroup
     */
    static double** ArrayAllocate(unsigned int Nlin,unsigned int Ncol,double val);
    
    /** 
     *  \brief crea dinámicamente un arreglo de Nlin lineas y Ncol columnas
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \param[in] Ncol El numero de columnas en el arreglo.
     *  \return Retorna un puntero al arreglo, o NULL si no consiguió reservar
     * la memoria. Esta memoria debe ser liberada siempre com ArrayRelease
     *  \ingroup MatrixGroup
     */
    static double** ArrayAllocate(unsigned int Nlin,unsigned int Ncol);

   /** 
     *  \brief Libera un arreglo de Nlin lineas y Ncol columnas (arreglo de arreglos)
     * Adicionalmente carga con NULL al arreglo a liberar.
     *  \param[in] array El arreglo de arreglos de de Nlin lineas y Ncol columnas
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \ingroup MatrixGroup
     */
    static void ArrayRelease(double** &array,unsigned int Nlin);

   /** 
     *  \brief Convierte a un arreglo unidimensional un arreglo de Nlin
     *  lineas y Ncol columnas (arreglo de arreglos). Lee primero una columna entera.
     *  \param[in] array El arreglo de arreglos de de Nlin lineas y Ncol columnas
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \param[in] Ncol El numero de columnas en el arreglo.
     *  \return Retorna un double *. Si la matriz es nula retorna NULL.
     *  \ingroup MatrixGroup
     */
    static double *ArrayToArray(double **array,unsigned int Nlin,unsigned int Ncol);

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
     *  \brief Convierte un sdt::string con arreglo de Nlin lineas y Ncol columnas a un arreglo.
     *  \param[in] str Cadena a leer.
     *  \param[out] Nlin El numero de lineas en el arreglo.
     *  \param[out] Ncol El numero de columnas en el arreglo.
     *  \return Retorna un arreglo. en caso de error se retorna NULL.
     *  \ingroup MatrixGroup
     */
    static double **ArrayFromString(const std::string &str,unsigned int &Nlin,unsigned int &Ncol);

   /** 
     *  \brief Convierte un sdt::string con arreglo de Nlin lineas y 1 columna a un arreglo.
     *  \param[in] str Cadena a leer.
     *  \param[out] Nlin El numero de lineas en el arreglo.
     *  \param[out]  Ncol El numero de columnas en el arreglo. En caso de exito 
     *  este valor sera 1 en otro caso el valor original no es alterado.
     *  \return Retorna un arreglo. en caso de error se retorna NULL.
     *  \ingroup MatrixGroup
     */
    static double **ArrayColFromString(const std::string &str,unsigned int &Nlin,unsigned int &Ncol);
    
   /** 
     *  \brief Salva en un archivo un arreglo de Nlin lineas y Ncol columnas (arreglo de arreglos).
     *  \param[in] filepath El archivo donde se guardaran los datos.
     *  \param[in] array El arreglo de arreglos de de Nlin lineas y Ncol columnas
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \param[in] Ncol El numero de columnas en el arreglo.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    static bool ArraySave(const char* filepath,double **array,unsigned int Nlin,unsigned int Ncol);

   /** 
     *  \brief Lee de un archivo un arreglo de Nlin lineas y Ncol columnas (arreglo de arreglos).
     *  \param[in] filepath El archivo donde se leerán los datos.
     *  \param[out] Nlin Donde se escribirá el numero de lineas en el arreglo.
     *  \param[out] Ncol Donde se escribirá el numero de columnas en el arreglo.
     *  \return El arreglo de arreglos de de Nlin lineas y Ncol columnas. Si el numero de columnas 
     *  no es constante se retorna NULL. Si la función retorna NULL entonces los valores
     *  de entrada Nlin e Ncol no son alterados.
     *  \ingroup MatrixGroup
     */
    static double** ArrayLoad(const char* filepath,unsigned int& Nlin,unsigned int& Ncol);

   /** 
     *  \brief Lee de un archivo un arreglo de Nlin lineas y Ncol=1 columna (arreglo de arreglos).
     *  \param[in] filepath El archivo donde se leerán los datos.
     *  \param[out] Nlin Donde se escribirá el numero de lineas en el arreglo.
     *  \param[out] Ncol Donde se escribirá el numero de columnas en el arreglo.
     *  \return El arreglo de arreglos de de Nlin lineas y Ncol=1 columnas.
     *  No importa si el numero de columnas en el archivo no es constante,
     *  la funcion so se interesa por la cantidad de elementos no vacios. 
     *  Si la función retorna NULL entonces los valores
     *  de entrada Nlin e Ncol no son alterados. En caso de acierto Ncol 
     *  siempre es cargado con 1.
     *  \ingroup MatrixGroup
     */
    static double** ArrayColLoad(const char* filepath,unsigned int& Nlin,unsigned int& Ncol);

   /** 
     *  \brief Escribe en un archivo binario en formato de octave un
     *  arreglo de Nlin lineas y Ncol columnas (arreglo de arreglos).
     *  Es usado el nombre MAT0 como identificador de matriz.
     * 
     *  Version 4 MAT-File Format:[Documento externo](https://www.eiscat.se/wp-content/uploads/2016/03/Version-4-MAT-File-Format.pdf)
     *  [Documento oficial](https://www.mathworks.com/help/pdf_doc/matlab/matfile_format.pdf)
     *  \param[in] fp El descriptor de fichero que apunta a donde se guardaran los datos.
     *  \param[in] array El arreglo de arreglos de de Nlin lineas y Ncol columnas
     *  \param[in] pname El nombre de la matriz.
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \param[in] Ncol El numero de columnas en el arreglo.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    static bool ArrayWriteMatFile(FILE *fp,const char *pname,double **array,unsigned int Nlin,unsigned int Ncol);

   /** 
     *  \brief Escribe en un archivo binario en formato de octave un
     *  arreglo de Nlin lineas y Ncol columnas (arreglo de arreglos).
     *  Es usado el nombre MAT0 como identificador de matriz.
     * 
     *  Version 4 MAT-File Format:[Documento externo](https://www.eiscat.se/wp-content/uploads/2016/03/Version-4-MAT-File-Format.pdf)
     *  [Documento oficial](https://www.mathworks.com/help/pdf_doc/matlab/matfile_format.pdf)
     *  \param[in] fp El descriptor de fichero que apunta a donde se guardaran los datos.
     *  \param[in] arrayr El arreglo real de arreglos de de Nlin lineas y Ncol columnas.
     *  \param[in] arrayi El arreglo imag de arreglos de de Nlin lineas y Ncol columnas.
     *  \param[in] pname El nombre de la matriz.
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \param[in] Ncol El numero de columnas en el arreglo.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    static bool ArrayWriteMatFile(FILE *fp,const char *pname,double **arrayr,double **arrayi,unsigned int Nlin,unsigned int Ncol);

   /** 
     *  \brief Escribe en un archivo binario en formato de octave un
     *  arreglo de Nlin lineas y Ncol columnas (arreglo de arreglos).
     *  Es usado el nombre MAT0 como nombre para de matriz.
     *
     *  Version 4 MAT-File Format: https://www.eiscat.se/wp-content/uploads/2016/03/Version-4-MAT-File-Format.pdf
     *  https://www.mathworks.com/help/pdf_doc/matlab/matfile_format.pdf
     *  \param[in] filepath El archivo donde se guardaran los datos.
     *  \param[in] array El arreglo de arreglos de de Nlin lineas y Ncol columnas.
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \param[in] Ncol El numero de columnas en el arreglo.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    static bool ArrayWriteMatFile(const char* filepath,double **array,unsigned int Nlin,unsigned int Ncol);
   /** 
     *  \brief Escribe en un archivo binario en formato de octave un
     *  arreglo de Nlin lineas y Ncol columnas (arreglo de arreglos).
     *  Es usado el nombre MAT0 como nombre para de matriz.
     *
     *  Version 4 MAT-File Format: https://www.eiscat.se/wp-content/uploads/2016/03/Version-4-MAT-File-Format.pdf
     *  https://www.mathworks.com/help/pdf_doc/matlab/matfile_format.pdf
     *  \param[in] filepath El archivo donde se guardaran los datos.
     *  \param[in] arrayr El arreglo real de arreglos de de Nlin lineas y Ncol columnas.
     *  \param[in] arrayi El arreglo imag de arreglos de de Nlin lineas y Ncol columnas.
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \param[in] Ncol El numero de columnas en el arreglo.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    static bool ArrayWriteMatFile(const char* filepath,double **arrayr,double **arrayi,unsigned int Nlin,unsigned int Ncol);


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
    Pds::Matrix T(void) const;
    
    /** 
     *  \brief Retorna A.T()*A cargado en B. 
     *
     *  \f[ B \leftarrow A^{T}A \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B;
    
    A.FillRandU();
    
    B=A.TnoT();
    
    std::cout<<B;
\endcode
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix TnoT(void) const;
    
    
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
    Pds::Matrix Inv(double *rcond=NULL) const;
    
    /** 
     *  \brief Procesa esta matriz A y retorna B la matriz pseudo 
     *  inversa de Moore Penrose.
     *
     *  \f[ B \leftarrow (A^T A)^{-1}A^T \f]
     *  \param[out] rcond Esta variable es cargada con el valor del
     *  reciproco del condicional de la matriz A^T A:
     *  \f[ rcond \leftarrow \frac{1.0}{||A^T A||_1 ||(A^T A)^{-1}||_1} \f]
     * Si la matriz está bien condicionada entonces rcond es próximo a 1.0 y si la matriz
     * esta pobremente condicionada este valor estará proximo a 0.0.
     * Si la variable rcond no es entregada entonces sera mostrado un mensaje
     * de advertencia por consola si el valor de rcond es menor a Pds::Ra::WarningRCond.
     *  \return Retorna la matriz inversa si todo fue bien o una matriz vacia si no.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix PInv(double *rcond=NULL) const;
    
    
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
    Pds::Matrix operator -(void) const;
    
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
    Pds::Matrix Minus(void) const;
    
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
    Pds::Matrix operator +(void) const;
    
    /** 
     *  \brief Asigna el signo + a si mismo (A), el resultado es
     * cargado en B. Este método es similar al operador unario + 
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
    Pds::Matrix Plus(void) const;
/**
 * @}
 */
    
    
/** @name Operadores binarios y sus métodos equivalentes
 *  Descripción de algunos operadores habilitados a trabajar con Pds::Matrix.
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
    Pds::Matrix operator + (double b) const;
    
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
    Pds::Matrix operator + (const Pds::Matrix &B) const;
    
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
    Pds::Matrix Add(double b) const;
    
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
    Pds::Matrix Add(const Pds::Matrix &B) const;
    
    
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
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \see Add
     *  \ingroup MatrixGroup
     */
    Pds::Matrix operator - (double b) const;
    
    /** 
     *  \brief Resta con sigo mismo (A), una matriz B y el resultado es
     * cargado en C. Este operador es similar al método Sub
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
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix operator -(const Pds::Matrix &B) const;
    
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
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix Sub(double b) const;
    
    /** 
     *  \brief Resta con sigo mismo (A), una matriz B y el resultado es
     * cargado en C. Este método es similar al operador - 
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
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix Sub(const Pds::Matrix &B) const;
    
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
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \see Mul
     *  \ingroup MatrixGroup
     */
    Pds::Matrix operator * (double b) const;
    
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
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \see Mul
     *  \ingroup MatrixGroup
     */
    Pds::Matrix operator * (const Pds::Matrix &B) const;
    
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
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix Mul(double b) const;
    
    /** 
     *  \brief Multiplica con sigo mismo (A), una matriz B y el resultado es
     * cargado en C. Este método  es similar al operador * 
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
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix Mul(const Pds::Matrix &B) const;
    
    /** 
     *  \brief Multiplica con sigo mismo (A), la transpuesta de una matriz B y el resultado es
     * cargado en C. Este método  es similar al operador * 
     *
     *  \f[ C \leftarrow A*B^T \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    B.Fill(1.0);
    
    C=A.MulT(B);
    
    std::cout<<C;
\endcode
     *  \param[in] B la matriz a multiplicar
     *  \return Retorna C con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix MulT(const Pds::Matrix &B) const;
/**
 * @}
 */
    
    
/** @name Operadores binarios acumuladores y sus métodos equivalentes
 *  Descripción de algunos operadores habilitados a trabajar con Pds::Matrix.
 * @{
 */
    
    /** 
     *  \brief Resta y acumula en si mismo (A), un valor b. Este operador 
     *  es similar al método SubAssig() 
     *
     *  \f[ A \leftarrow A-b \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    double b=1.2;
    B.Fill(1.0);
    A-=b;
\endcode
     *  \param[in] b El valor a substraer
     *  \return Retorna el operador de la izquierda (acumulador) con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \see SubAssig
     *  \ingroup MatrixGroup
     */
    Pds::Matrix& operator -=(double b);
    
    /** 
     *  \brief Resta y acumula en si mismo (A), una matriz B. Este operador 
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
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \see SubAssig
     *  \ingroup MatrixGroup
     */
    Pds::Matrix& operator -=(const Pds::Matrix &B);
    
    /** 
     *  \brief Resta y acumula en si mismo (A), un valor b. Este es similar al
     *  operador -= 
     *
     *  \f[ A \leftarrow A-b \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    double b=1.2;
    A.SubAssig(b);
\endcode
     *  \param[in] b valor a substraer
     *  \return Retorna true si todo fue bien o false si no. Si se retorna false
     *  el acumulador no altera su contenido.
     *  \ingroup MatrixGroup
     */
    bool SubAssig(double b);
    
    /** 
     *  \brief Resta y acumula en si mismo (A), una matriz B. Este es similar al
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
    bool SubAssig(const Pds::Matrix &B);
    
    /** 
     *  \brief Suma y acumula en si mismo (A), un valor b. Este operador 
     *  es similar al método AddAssig() 
     *
     *  \f[ A \leftarrow A+b \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    double b=1.2;
    A+=b;
\endcode
     *  \param[in] b El valor a acumular
     *  \return Retorna el operador de la izquierda (acumulador) con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \see AddAssig
     *  \ingroup MatrixGroup
     */
    Pds::Matrix& operator +=(double b);
    
    /** 
     *  \brief Suma y acumula en si mismo (A), una matriz B. Este operador 
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
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \see AddAssig
     *  \ingroup MatrixGroup
     */
    Pds::Matrix& operator +=(const Pds::Matrix &B);
    
    /** 
     *  \brief Suma y acumula en si mismo (A), un valor b. Este es similar al
     *  perador += 
     *
     *  \f[ A \leftarrow A+b \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    A.AddAssig(1.2);
\endcode
     *  \param[in] b Valor a acumular
     *  \return Retorna true si todo fue bien o false si no. Si se retorna false
     *  el acumulador no altera su contenido.
     *  \ingroup MatrixGroup
     */
    bool AddAssig(double b);

    /** 
     *  \brief Suma y acumula en si mismo (A), una matriz B. Este es similar al
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
    bool AddAssig(const Pds::Matrix &B);
    

    /** 
     *  \brief Suma y acumula en si mismo (A), una matriz B desde un punto (lin,col)
     *  haciendo una intersección.
     *
     *  \f[ A(lin:end,col:end) \leftarrow A(lin:end,col:end)+B(0:lin_end,0:col_end) \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(3,3);
    B.Fill(1.0);
    A.AddAssigAt(B,2,2);
\endcode
     *  \param[in] B la matriz a acumular
     *  \param[in] lin Suma desde esta linea
     *  \param[in] col Suma desde esta columna
     *  \return Retorna true si todo fue bien o false si no. Si se retorna false
     *  el acumulador no altera su contenido. Retorna false si la intersección
     *  no existe o si alguna de las matrices son nulas.
     *  \ingroup MatrixGroup
     */
    bool AddAssigAt(const Pds::Matrix &B,unsigned int lin,unsigned int col);
    
    /** 
     *  \brief Multiplica y acumula en si mismo (A), un valor b. Este operador 
     *  es similar al método MulAssig() 
     *
     *  \f[ A \leftarrow A*b \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    double b=1.2;
    A*=b;
\endcode
     *  \param[in] b El valor a acumular
     *  \return Retorna el operador de la izquierda (acumulador) con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \see AddAssig
     *  \ingroup MatrixGroup
     */
    Pds::Matrix& operator *=(double b);
    
    /** 
     *  \brief Multiplica y acumula en si mismo (A), una matriz B. Este operador 
     *  es similar al método MulAssig() 
     *
     *  \f[ A \leftarrow A*B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(4,4);
    A*=B;
\endcode
     *  \param[in] B El valor a acumular
     *  \return Retorna el operador de la izquierda (acumulador) con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \see AddAssig
     *  \ingroup MatrixGroup
     */
    Pds::Matrix& operator *=(const Pds::Matrix &B);
    
    /** 
     *  \brief Multiplica y acumula en si mismo (A), un valor b. Este es similar al
     *  operador *= 
     *
     *  \f[ A \leftarrow A*b \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    A.MulAssig(1.2);
\endcode
     *  \param[in] b Valor a acumular
     *  \return Retorna true si todo fue bien o false si no. Si se retorna false
     *  el acumulador no altera su contenido.
     *  \ingroup MatrixGroup
     */
    bool MulAssig(double b);
    
    /** 
     *  \brief Multiplica y acumula en si mismo (A), una matriz B. Este es similar al
     *  operador *= 
     *
     *  \f[ A \leftarrow A*B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(4,4);
    A.MulAssig(B);
\endcode
     *  \param[in] B Valor a acumular
     *  \return Retorna true si todo fue bien o false si no. Si se retorna false
     *  el acumulador no altera su contenido.
     *  \ingroup MatrixGroup
     */
    bool MulAssig(const Pds::Matrix &B);
    
    
    
    /** 
     *  \brief Copia en si mismo (A), una matriz B. Este operador es 
     *  similar al método Copy().
     *  No importa  el tamaño de A, sus datos son liberados y un nuevo
     *  arreglo de datos es reservado.
     *
     *  \f[ A \leftarrow B \f]
     * Cuando acontece:
\code{.cpp}
    Pds::Matrix B(nlin,ncol);
    A=B;
\endcode
     * Cuando NO acontece:
\code{.cpp}
    Pds::Matrix A=Pds::Matrix(nlin,ncol);
\endcode
     *  \param[in] B la matriz a copiar
     *  \return Retorna el operador de la izquierda (acumulador) con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \see Copy
     *  \ingroup MatrixGroup
     */
    Pds::Matrix& operator = (const Pds::Matrix &B);
    
    /** 
     *  \brief Copia en si mismo (A), el contenido de una matriz B. Este 
     *  método es similar a usar el operador = .
     *  No importa  el tamaño de A, sus datos son liberados y un nuevo
     *  arreglo de datos es reservado.
     *
     *  \f[ A \leftarrow B \f]
     *  \param[in] B la matriz a copiar
     *  \return Retorna true si todo fue bien o false si no. Si se retorna false
     *  el receptor no altera su contenido.
     *  \see Copy
     *  \ingroup MatrixGroup
     */
    bool Copy(const Pds::Matrix &B);

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
     *  \brief Retorna el contenido de la matriz por la salida estándar
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
     *  \return Retorna la misma salida estándar out.
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
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
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
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
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
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
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

