/*
 * FuncMatrixImage.hpp
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

/** \file FuncMatrixImage.hpp
 *  \author Fernando Pujaico Rivera
 *  \brief Funciones que trabajan con matrices.
 *  
 *  <br>Estas funciones trabajan con una matriz de la forma.<br>
 *  \image html matrix.png "Matriz de NlinxNcol"
 *  \b Nlin es el número de lineas y \b Ncol es el número de columnas.
 */



#ifndef __PDS_MATRIXIMAGEN_HPP__
#define __PDS_MATRIXIMAGEN_HPP__


/** \defgroup FuncMatrixImageGroup Funciones Pds::Matrix -- Image
 *  \brief Funciones que usan Pds::Matrix, Ejemplo: Pds::ChromaticityCoordinates(), etc
 *  <div class="fragment"> \#include <Pds/FuncMatrixImage> </div>
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

namespace Image{

/** @name funciones para imagenes
 *  Descripción de algunas funciones que usan  Pds::Matrix.
 * @{
 */
    
    /** 
     *  \brief Retorna un bloque de matrices en coordenadas cromáticas.
     *
\f[
(Block[0], Block[1],...,Block[N-1]) 
\qquad \rightarrow \qquad 
\left(\frac{Block[0]}{S}, \frac{Block[1]}{S}, ...,\frac{Block[N-1]}{S}\right)
\f]
\f[
S\equiv Block[0]+...+Block[N-1]
\f]
     * En el caso de 3 matrices.
     *  \f[(R,G,B) \qquad \rightarrow \qquad (\frac{R}{R+G+B},\frac{G}{R+G+B},\frac{B}{R+G+B})\f]
<table>
<caption id="ChromaticityCoordinates">ChromaticityCoordinates</caption>
    <tr><td>Original <td> Chromaticity Coordinates factor=255
    <tr><td><img src="imagen.bmp"  alt="Original"> <td> <img src="imagen_cc.bmp"  alt="Chromaticity Coordinates factor=255"> 
</table> 
     *  \param[in] Block Matriz original.
     *  \param[in] factor Valor |factor| por qual se multiplicará el resultado.
     *  \return Retorna un bloque de matrices en coordenadas cromáticas.
     *  \ingroup FuncMatrixImageGroup
     */
    std::vector<Pds::Matrix> ChromaticityCoordinates(const std::vector<Pds::Matrix> &Block,double factor=1.0);
    
    std::vector<Pds::Matrix> WhitePatch(const std::vector<Pds::Matrix> &Block);

/**
 * @}
 */

} //Image

} //Pds
/**
 * @}
 */

#endif

