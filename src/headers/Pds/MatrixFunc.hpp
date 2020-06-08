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


/** \defgroup MatrixFuncGroup Funciones Pds::Matrix -- Básicos
 *  \brief Funciones que usan Pds::Matrix, Ejemplo: Pds::Diag(), Pds::Eye(), Pds::Ones(), Pds::Zeros(), etc 
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
\end{matrix}\right)
   \f]
   \f[
A\equiv [a_{i,j}]
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
    Pds::Matrix MatrixId(unsigned int N);
   
   /** 
     *  \brief Crea una matriz con datos correspondentes ao Id de cada elemento.
     *  \param[in] S Tamaño de la matriz.
     *  \return Retorna una matriz no vacía si todo fue bien o una matriz vacía en caso de error.
     *  \ingroup MatrixFuncGroup
     */
    Pds::Matrix MatrixId(const Pds::Size &S);
   
   /** 
     *  \brief Crea una matriz con datos correspondentes ao Id de cada elemento.
     *  \param[in] Nlin Número de lineas.
     *  \param[in] Ncol Número de columnas.
     *  \return Retorna una matriz no vacía si todo fue bien o una matriz vacía en caso de error.
     *  \ingroup MatrixFuncGroup
     */
    Pds::Matrix MatrixId(unsigned int Nlin,unsigned int Ncol);
    
   /** 
     *  \brief Crea una matriz con datos aleatorios con distribución Normal
     *  de media cero 0.0 y desvío padrón 1.0.
     *  \param[in] N Número de lineas y columnas.
     *  \return Retorna una matriz no vacía si todo fue bien o una matriz vacía en caso de error.
     *  \ingroup MatrixFuncGroup
     */
    Pds::Matrix RandN(unsigned int N);
   
   /** 
     *  \brief Crea una matriz con datos aleatorios con distribución Normal
     *  de media cero 0.0 y desvío padrón 1.0.
     *  \param[in] S Tamaño de la matriz.
     *  \return Retorna una matriz no vacía si todo fue bien o una matriz vacía en caso de error.
     *  \ingroup MatrixFuncGroup
     */
    Pds::Matrix RandN(const Pds::Size &S);
   
   /** 
     *  \brief Crea una matriz con datos aleatorios con distribución Normal
     *  de media cero 0.0 y desvío padrón 1.0.
     *  \param[in] Nlin Número de lineas.
     *  \param[in] Ncol Número de columnas.
     *  \return Retorna una matriz no vacía si todo fue bien o una matriz vacía en caso de error.
     *  \ingroup MatrixFuncGroup
     */
    Pds::Matrix RandN(unsigned int Nlin,unsigned int Ncol);
    
   /** 
     *  \brief Crea una matriz con datos aleatorios uniformemente distribuidos entre 0.0 y 1.0.
     *  \param[in] N Número de lineas y columnas.
     *  \return Retorna una matriz no vacía si todo fue bien o una matriz vacía en caso de error.
     *  \ingroup MatrixFuncGroup
     */
    Pds::Matrix RandU(unsigned int N);
    
   /** 
     *  \brief Crea una matriz con datos aleatorios uniformemente distribuidos entre 0.0 y 1.0.
     *  \param[in] S Tamaño de la matriz.
     *  \return Retorna una matriz no vacía si todo fue bien o una matriz vacía en caso de error.
     *  \ingroup MatrixFuncGroup
     */
    Pds::Matrix RandU(const Pds::Size &S);
    
   /** 
     *  \brief Crea una matriz con datos aleatorios uniformemente distribuidos entre 0.0 y 1.0.
     *  \param[in] Nlin Número de lineas.
     *  \param[in] Ncol Número de columnas.
     *  \return Retorna una matriz no vacía si todo fue bien o una matriz vacía en caso de error.
     *  \ingroup MatrixFuncGroup
     */
    Pds::Matrix RandU(unsigned int Nlin,unsigned int Ncol);
    
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
    Pds::Matrix Diag(Matrix A);

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
    Pds::Matrix Eye(unsigned int N);
    
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
    Pds::Matrix Ones(const Pds::Size &S);
    
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
    Pds::Matrix Ones(unsigned int Nlin, unsigned int Ncol);
    
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
    Pds::Matrix Ones(unsigned int N);
    
    
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
    Pds::Matrix Zeros(const Pds::Size &S);
    
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
    Pds::Matrix Zeros(unsigned int Nlin, unsigned int Ncol);
    
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
    Pds::Matrix Zeros(unsigned int N);


/**
 * @}
 */

/** @name funciones para monomios en matrices
 *  Descripción de algunas funciones que usan  Pds::Matrix.
 * @{
 */

     /** 
     *  \brief Retorna una matriz \f$\mathbf{S}_{N}(M)\f$ de \f$N\f$ columnas y \f${{N+M-1} \choose M}\f$ lineas.
     *  La lineas de \f$\mathbf{S}_{N}(M)\f$ tienen todas las combinaciones de \f$N\f$ numeros enteros que sumen \f$M\f$.
     *  Para obter \f$\mathbf{S}_{N}(M)\f$ es usada recursivamente la siguiente ecuación
     *
\f[
\mathbf{S}_{N}(M)=\left(\begin{matrix}
\mathbf{S}_{N-1}(M) & \mathbf{\overline{0}}\\ 
\mathbf{S}_{N-1}(M-1) & \mathbf{\overline{1}}\\
\mathbf{S}_{N-1}(M-2) & \mathbf{\overline{2}}\\
\vdots & \vdots \\
\mathbf{S}_{N-1}(1) & \mathbf{\overline{M-1}}\\
\mathbf{S}_{N-1}(0) & \mathbf{\overline{M}}\\
\end{matrix}\right)
\f]

Donde se sabe que

\f[
\mathbf{S}_{1}(M) =M, \qquad \mathbf{S}_{N}(0)=[ 0\quad 0\quad ... \quad 0] 
\f]
     *  \param[in] N Número de numeros usados en la suma.
     *  \param[in] M Suma que tien que tener los N números.
     *  \return Retorna la matriz con los indices.
     *  \ingroup MatrixFuncGroup
     */
    Pds::Matrix MultisetIndexSum(unsigned int N,unsigned int M);


     /** 
     *  \brief Retorna una cadena que representa una matriz de indices \f$\mathbf{ID}\f$ con \f$L\f$ lineas
     *  y \f$N\f$ columnas. Los indices \f$\mathbf{d}_l\f$ estan agrupados en las
     *  \f$L\f$ lineas de la matriz \f$\mathbf{ID}\f$.
     *
\f[
\mathbf{ID}= \left(\begin{matrix}
\mathbf{d}_1\\ 
\mathbf{d}_2 \\
\mathbf{d}_3 \\
\vdots  \\
\mathbf{d}_{L-1} \\
\mathbf{d}_{L} \\
\end{matrix}\right)
\leftarrow Pds::MultisetIndexSum(N,M)
\f]

Donde el indice \f$\mathbf{d}_l\f$ genera el monomio 
\f$\mathbf{\overline{X}}^{\mathbf{d}_l}\equiv \mathbf{x}_1^{d_{l1}} \mathbf{x}_2^{d_{l2}} \mathbf{x}_3^{d_{l3}} ... \mathbf{x}_N^{d_{lN}}\f$
.
     *  \param[in] ID Una matriz con indices en las lineas.
     *  \param[in] Separator El texto separador entre monomios.
     *  \param[in] xinit Valor inicial de x, si xinit=0 inicia en x_{0}
     *  \return Una cadena con los indices.
     *  \ingroup MatrixFuncGroup
     */
    std::string MultisetIndexSumToString(const Pds::Matrix &ID,std::string Separator=", ",unsigned int xinit=1);

     /** 
     *  \brief Dada uma matriz \f$\mathbf{X}=\left[\mathbf{x}_1,\quad \mathbf{x}_2,\quad ...,\quad \mathbf{x}_n,\quad ...,\quad \mathbf{x}_N\right]\f$,
     *  compuesta por la concatenacion de \f$N\f$ vectores columna \f$\mathbf{x}_n\f$.
     *  La funcion retorna una matriz \f$\overline{\mathbf{X}}^{M}\f$ compuesta por \f$L=\left({N \choose M}\right)\f$ 
     *  vectores columnas \f$\mathbf{\overline{X}}^{\mathbf{d}_l}\f$ que representan monomios de orden \f$M\f$.

\f[
\overline{\mathbf{X}}^{M}=\left[
\mathbf{\overline{X}}^{\mathbf{d}_1},\quad 
\mathbf{\overline{X}}^{\mathbf{d}_2}, \quad
\mathbf{\overline{X}}^{\mathbf{d}_3}, \quad
...,\quad 
\mathbf{\overline{X}}^{\mathbf{d}_l}, \quad
...,\quad 
\mathbf{\overline{X}}^{\mathbf{d}_{L}}
\right]
\f]

Donde \f$\mathbf{\overline{X}}^{\mathbf{c}}\equiv \mathbf{x}_1^{c_1} \mathbf{x}_2^{c_2} \mathbf{x}_3^{c_3} ... \mathbf{x}_N^{c_N}\f$,
es la multiplicación elemento a elemento de las potencias de los vectores columna \f$\mathbf{x}_n\f$,
donde \f$c_1+c_2+c_3+...+c_n+...+c_N=M\f$.
Los indices estan agrupados en las lineas de la matriz \f$\mathbf{ID}\f$, 
esta tiene \f$L\f$ lineas y \f$N\f$ columnas

\f[
\mathbf{ID}= \left(\begin{matrix}
\mathbf{d}_1\\ 
\mathbf{d}_2 \\
\mathbf{d}_3 \\
\vdots  \\
\mathbf{d}_{L-1} \\
\mathbf{d}_{L} \\
\end{matrix}\right)
\leftarrow 
Pds::MultisetIndexSum(N,M) 
\f]

La funcion calcula los exponentes en los monomios usando Pds::MultisetIndexSum(N,M).
     *  \param[in] X Matriz \f$\mathbf{X}=\left[\mathbf{x}_1,\quad \mathbf{x}_2,\quad ...,\quad \mathbf{x}_N\right]\f$.
     *  \param[in] M Orden de los monomios.
     *  \param[out] ID Matriz de indices (en las lineas) de todos los monomios en las columnas de la matriz \f$\overline{\mathbf{X}}^{M}\f$.
     *  \return Retorna la matriz \f$\overline{\mathbf{X}}^{M}\f$ con los monomios.
     *  \ingroup MatrixFuncGroup
     */
    Pds::Matrix Monomials(const Pds::Matrix &X,unsigned int M,Pds::Matrix &ID);

     /** 
     *  \brief Dada uma matriz \f$\mathbf{X}=\left[\mathbf{x}_1,\quad \mathbf{x}_2,\quad ...,\quad \mathbf{x}_n,\quad ...,\quad \mathbf{x}_N\right]\f$,
     *  compuesta por la concatenacion de \f$N\f$ vectores columna \f$\mathbf{x}_n\f$.
     *  La funcion retorna una matriz \f$\overline{\mathbf{X}}^{M}\f$ compuesta por \f$L=\left({N \choose M}\right)\f$ 
     *  vectores columnas \f$\mathbf{\overline{X}}^{\mathbf{d}_l}\f$ que representan monomios de orden \f$M\f$.

\f[
\overline{\mathbf{X}}^{M}=\left[
\mathbf{\overline{X}}^{\mathbf{d}_1},\quad 
\mathbf{\overline{X}}^{\mathbf{d}_2}, \quad
\mathbf{\overline{X}}^{\mathbf{d}_3}, \quad
...,\quad 
\mathbf{\overline{X}}^{\mathbf{d}_l}, \quad
...,\quad 
\mathbf{\overline{X}}^{\mathbf{d}_{L}}
\right]
\f]

Donde \f$\mathbf{\overline{X}}^{\mathbf{c}}\equiv \mathbf{x}_1^{c_1} \mathbf{x}_2^{c_2} \mathbf{x}_3^{c_3} ... \mathbf{x}_N^{c_N}\f$,
es la multiplicación elemento a elemento de las potencias de los vectores columna \f$\mathbf{x}_n\f$,
donde \f$c_1+c_2+c_3+...+c_n+...+c_N=M\f$.
Los indices estan agrupados en las lineas de la matriz \f$\mathbf{ID}\f$, 
esta tiene \f$L\f$ lineas y \f$N\f$ columnas

\f[
\mathbf{ID}= \left(\begin{matrix}
\mathbf{d}_1\\ 
\mathbf{d}_2 \\
\mathbf{d}_3 \\
\vdots  \\
\mathbf{d}_{L-1} \\
\mathbf{d}_{L} \\
\end{matrix}\right)
\leftarrow 
Pds::MultisetIndexSum(N,M) 
\f]

La funcion calcula los exponentes en los monomios usando Pds::MultisetIndexSum(N,M).
     *  \param[in] X Matriz \f$\mathbf{X}=\left[\mathbf{x}_1,\quad \mathbf{x}_2,\quad ...,\quad \mathbf{x}_N\right]\f$.
     *  \param[in] M Orden de los monomios.
     *  \return Retorna la matriz \f$\overline{\mathbf{X}}^{M}\f$ con los monomios.
     *  \ingroup MatrixFuncGroup
     */
    Pds::Matrix Monomials(const Pds::Matrix &X,unsigned int M);

/**
 * @}
 */

/** @name funciones de concatenacion
 *  Descripción de algunas funciones que usan  Pds::Matrix.
 * @{
 */

    /** 
     *  \brief Retorna una matriz concatenando verticalmente otras.  
     *  Si las matrices no tienen el mismo número de columnas se considera um error.
     *
     *  \param[in] list La lista de matrices a concatenar.
     *  \return Retorna la matriz concatenada o una matriz vacía en caso de error.
     *  \ingroup MatrixFuncGroup
     */
    Pds::Matrix  MergeVer(const std::initializer_list<Pds::Matrix> list);

    /** 
     *  \brief Retorna una matriz concatenando horizontalmente otras.  
     *  Si las matrices no tienen el mismo número de lineas se considera um error.
     *
     *  \param[in] list La lista de matrices a concatenar.
     *  \return Retorna la matriz concatenada o una matriz vacía en caso de error.
     *  \ingroup MatrixFuncGroup
     */
    Pds::Matrix  MergeHor(const std::initializer_list<Pds::Matrix> list);

    /** 
     *  \brief Retorna una Regressor Matrix \f$\mathbf{R}\f$, creado concatenando 
     *  verticalmente las matrices \f$\mathbf{list_n}\f$ en una lista \f$\mathbf{list}\f$.  
     *  Si las matrices no tienen el mismo número de columnas se considera um error.
     *
   \f[
\mathbf{R}=\left(\begin{matrix}
\overline{1} & \mathbf{list_0}\\ 
\overline{1} & \mathbf{list_1}\\
\overline{1} & \mathbf{list_2}\\
\vdots & \vdots\\
\overline{1} & \mathbf{list_{N-1}}\\
\end{matrix}\right)
   \f]
     *  \param[in] list La lista de matrices \f$\mathbf{list_n}\f$ a concatenar.
     *  \return Retorna una Regressor Matrix o una matriz vacía en caso de error.
     *  \ingroup MatrixFuncGroup
     */
    Pds::Matrix RegressorMatrix(const std::initializer_list<Pds::Matrix> list);


    /** 
     *  \brief Retorna una Regressor Matrix \f$\mathbf{R}\f$ creado concatenando 
     * horizontalmente un vector de unos \f$\overline{\mathbf{1}}\f$ con una matriz \f$\mathbf{B}\f$.
     *
   \f[
\mathbf{R}=\left(\begin{matrix}
\overline{\mathbf{1}} & \mathbf{B}
\end{matrix}\right)
   \f]
     *  \param[in] B La matriz a usar.
     *  \return Retorna una Regressor Matrix o una matriz vacía en caso de error.
     *  \ingroup MatrixFuncGroup
     */
    Pds::Matrix RegressorMatrix(const Pds::Matrix &B);

    /** 
     *  \brief Retorna una Regressor Matrix \f$\mathbf{R}\f$ para una forma polinomial multivariada de orden M.
     *  \f$\mathbf{R}\f$ es creado concatenando horizontalmente matrices \f$\overline{\mathbf{B}}^{m},~\forall m \in \{0,1,2,...,M\}\f$.
     *
   \f[
\mathbf{R}=\left(\begin{matrix}
\overline{1} & \overline{\mathbf{B}}^{1} & \overline{\mathbf{B}}^{2} & ... & \overline{\mathbf{B}}^{m} & ... & \overline{\mathbf{B}}^{M}
\end{matrix}\right)
   \f]
Donde \f$\overline{\mathbf{B}}^{m}\f$ es una matriz con todos los monomios de grado \f$m\f$
creado a partir de la matriz \f$\mathbf{B}=[\mathbf{x}_1,\mathbf{x}_2,\mathbf{x}_3,...,\mathbf{x}_N]\f$,
es decir \f$\overline{\mathbf{B}}^{m}\f$=Pds::Monomials(B,m).
     *  \param[in] B La matriz a usar.
     *  \param[in] M El orden del polinomio multivariado.
     *  \return Retorna una Regressor Matrix o una matriz vacía en caso de error.
     *  \see Pds::Monomials()
     *  \ingroup MatrixFuncGroup
     */
    Pds::Matrix  RegressorMatrix(const Pds::Matrix &B,unsigned int M);

    /** 
     *  \brief Retorna una Regressor Matrix \f$\mathbf{R}\f$ para una forma polinomial multivariada de orden M.
     *  \f$\mathbf{R}\f$ es creado concatenando horizontalmente matrices \f$\overline{\mathbf{B}}^{m},~\forall m \in \{0,1,2,...,M\}\f$.
     *
   \f[
\mathbf{R}=\left(\begin{matrix}
\overline{1} & \overline{\mathbf{B}}^{1} & \overline{\mathbf{B}}^{2} & ... & \overline{\mathbf{B}}^{m} & ... & \overline{\mathbf{B}}^{M}
\end{matrix}\right)
   \f]
Donde \f$\overline{\mathbf{B}}^{m}\f$ es una matriz con todos los monomios de grado \f$m\f$
creado a partir de la matriz \f$\mathbf{B}=[\mathbf{x}_1,\mathbf{x}_2,\mathbf{x}_3,...,\mathbf{x}_N]\f$,
es decir \f$\overline{\mathbf{B}}^{m}\f$=Pds::Monomials(B,m).
     *  \param[in] B La matriz a usar.
     *  \param[in] M El orden del polinomio multivariado.
     *  \param[out] ID La matriz donde sus lineas representan los indices de 
     *  los monomios en las columnas de \f$\mathbf{R}\f$.
     *  \return Retorna una Regressor Matrix o una matriz vacía en caso de error.
     *  \see Pds::Monomials()
     *  \ingroup MatrixFuncGroup
     */
    Pds::Matrix  RegressorMatrix(const Pds::Matrix &B,unsigned int M,Pds::Matrix &ID);
    
/**
 * @}
 */




}
/**
 * @}
 */

#endif

