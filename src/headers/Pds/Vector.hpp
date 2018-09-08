/*
 * Vector.hpp
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

/** \file Vector.hpp
 *  \author Fernando Pujaico Rivera
 *  \date 01-04-2011
 *  \brief Funciones que trabajan con matrices columna.
 *  
 *  <br>Estas funciones trabajan con una matriz de la forma.<br>
 *  \image html matrix.png "Matriz de Nlinx1"
 *  \b Nlin es el número de lineas.
 */



#ifndef __PDS_VECTOR_HPP__
#define __PDS_VECTOR_HPP__


/** \defgroup VectorGroup Clase Pds::Vector.
 *  \brief Metodos de la clase Pds::Vector, un vector columna/matriz 
 *  <div class="fragment"> \#include <Pds/Vector> </div>
 *  
 *  <br>Estas funciones trabajan con una matriz de la forma.<br>
   \f[
\mathbf{A}=\left(\begin{matrix}
a_{00}  \\ 
a_{10}  \\
\vdots  \\
a_{(Nlin-2)0}  \\ 
a_{(Nlin-1)0} \\
\end{matrix}\right)\equiv A_{(Nlin-1),1}
   \f]
   \f[
A_{(Nlin-1),1}\equiv [a_{ij}]_{(Nlin-1),1}
   \f]
 *  \b nlin es el número de lineas.
 *  
 * Informacion adicional puede ser encontrada en @cite tutorialmatvec
 * @{
 */


#include <Pds/Matrix>
#include <Pds/Size>

namespace Pds{

/*! \class Vector
 *  \brief La clase tipo  Vector .
 *  Esta clase genera una matriz de Nlin lineas y 1 columna.
 *  Para usar incluir Pds/Vector.
 *  \ingroup VectorGroup
 *  \author Fernando Pujaico Rivera
 */
class Vector: public Matrix
{

public:

/** @name Varios tipos de constructores
 *  Crean una objeto Pds::Vector
 * @{
 */

    /** 
     *  \brief Crea un objeto de tipo Pds::Vector
     *  \return un objeto de tipo Pds::Vector.
     *  \ingroup VectorGroup
     */
    Vector(void);
    
    /** 
     *  \brief Crea un objeto de tipo Pds::Vector
     *  \param[in] N El numero de lineas de la matriz.
     *  \return un objeto de tipo Pds::Vector.
     *  \ingroup VectorGroup
     */
    Vector(unsigned int N);

    /** 
     *  \brief Crea un objeto de tipo Pds::Vector copiando datos desde 
     *  una matriz. Toda la matriz es vectorizada leyendo columna a columna.
     * 
   \f[
B_{Nlin,1}\equiv [b_{i,j}]_{Nlin,Ncol}
   \f]
   \f[
\mathbf{A} \leftarrow \mathbf{B\{:\}}
   \f]
   Para crear una matriz A con copia de datos de una matriz B:
\code{.cpp}
    Pds::Matrix B(4,5);
    Pds::Vector A(B);
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] B Matriz a copiar.
     *  \ingroup VectorGroup
     */
    Vector(const Pds::Matrix &B);


    /** 
     *  \brief Crea un objeto de tipo Pds::Vector copiando datos desde
     *  una columna de una matriz. 
     * 
   \f[
B_{Nlin,1}\equiv [b_{i,j}]_{Nlin,Ncol}
   \f]
   \f[
\mathbf{A} \leftarrow \mathbf{B\{:,col\}}
   \f]
   Para crear una matriz A con copia de datos de una matriz B:
\code{.cpp}
    Pds::Matrix B(4,5);
    Pds::Vector A(B,2);
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] B Matriz a copiar.
     *  \param[in] col columna a copiar.
     *  \ingroup VectorGroup
     */
    Vector(const Pds::Matrix &B,unsigned int col);

    
    ~Vector(); 
    
/**
 * @}
 */
    
    
/** @name Operadores binarios acumuladores y sus métodos equivalentes
 *  Descripción de algunos operadores habilitados a trabajar con Pds::Vector.
 * @{
 */
    
    /** 
     *  \brief Copia en si mismo (A), una matriz B. Este operador es 
     *  similar al método Copy().
     *  No importa  el tamaño de A, sus datos son liberados y un nuevo
     *  arreglo de datos es reservado.
     *
     *  \f[ A \leftarrow B \f]
     * Cuando acontece:
\code{.cpp}
    Pds::Vector B(nlin,ncol);
    A=B;
\endcode
     * Cuando NO acontece:
\code{.cpp}
    Pds::Vector A=Pds::Vector(nlin,ncol);
\endcode
     *  \param[in] B la matriz a copiar
     *  \return Retorna el operador de la izquierda (acumulador) con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \see Copy
     *  \ingroup VectorGroup
     */
    Pds::Vector& operator = (const Pds::Vector &B);


/**
 * @}
 */

}; // Class Vector

} // namespace Pds


/*!
 * @}
 */

#endif

