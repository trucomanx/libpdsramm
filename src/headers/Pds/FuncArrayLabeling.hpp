/*
 * FuncArrayLabeling.hpp
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

/** \file FuncArrayLabeling.hpp
 *  \author Fernando Pujaico Rivera
 *  \brief Funciones que trabajan con complejos.
 *  
 */



#ifndef __PDS_FUNCARRAYLABELING_HPP__
#define __PDS_FUNCARRAYLABELING_HPP__


/** \defgroup FuncArrayLabelingGroup Funciones Pds::Array -- Image labeling
 *  \brief Funciones que usan Pds::Quaternion, Ejemplo: etc 
 *  <div class="fragment"> \#include <Pds/FuncArrayLabeling> </div>
 *   
 * Informacion adicional puede ser encontrada en @cite tutorialmatvec
 * @{
 */

#include <Pds/Ra>
#include <vector>

namespace Pds{

namespace Image{

/** @name Funciones para Connected-component labeling
 *  Herramientas genéricas que pueden ser usadas para Connected-component labeling.
 * @{
 */

    /** 
     *  \brief Connected-component labeling para 4 conectividad.
     *
<table>
<caption id="IdMapUsingCC4">IdMapUsingCC4</caption>
    <tr><td>BW <td> ID_MAP
    <tr><td><img src="A-binary-circle.bmp"  alt="Binary circles"> <td> <img src="A-ID-circle.bmp"  alt="ID map"> 
</table> 
     *  \param[in] BW matriz de 1s y 0s (grupos de unos).
     *  \return Retorna una matriz ID_MAP con indices en cada grupo en B.
     *  \ingroup FuncArrayLabelingGroup
     */
    Pds::Array<unsigned int> IdMapUsingCC4(const Pds::Array<unsigned char> &BW);

    /** 
     *  \brief Retorna todos los grupos de posiciones (std::vector<Pds::Position>) 
     *  agrupados en un vector (std:vector), provenientes de analizar un mapa de indices, ID_MAP.
     *
     *  \param[in] ID_MAP Matriz con los indices.
     *  \return Retorna todos los grupos de posiciones de un mapa de indices ID_MAP,
     *  ordenandos en un vector Data, donde el grupo de posiciones Data[i] es un vector de elementos Pds::Position.
     *  \ingroup FuncArrayLabelingGroup
     */
    std::vector<std::vector<Pds::Position>> VectorGroupFromIdMap(const Pds::Array<unsigned int>  &ID_MAP);

    /** 
     *  \brief Calcula el grupo de posiciones de um perimetro de un grupo.
     *  EL perimetro es calculado usando un criterio de conectividad 4 
     *
     *  \param[in] Group Un vector de elementos Pds::Position.
     *  \return Retorna un grupo de posiciones describiendo el perimetro.
     *  \ingroup FuncArrayLabelingGroup
     */
    std::vector<Pds::Position> PerimeterGroupOfGroup(const std::vector<Pds::Position> &Group);

    /** 
     *  \brief Calcula el perimetro de un grupo si este es convexo.
     *  EL perimetro es calculado usando un criterio de conectividad 4 
     *
     *  \param[in] Group Un vector de elementos Pds::Position.
     *  \return Calcula el perimetro de un grupo si este es convexo.
     *  Si no es convexo en la mayoria de casos da error.
     *  En caso de error retorna Pds::Ra::Nan.
     *  \ingroup FuncArrayLabelingGroup
     */
    double PerimeterOfConvexGroup(const std::vector<Pds::Position> &Group);

/**
 * @}
 */


} //Image

} //Pds
/**
 * @}
 */

#endif

