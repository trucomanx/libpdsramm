/*
 * FuncArrayDataset.hpp
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

/** \file FuncArrayDataset.hpp
 *  \author Fernando Pujaico Rivera
 *  \brief Funciones que trabajan con complejos.
 *  
 */



#ifndef __PDS_FUNCARRAYDATASET_HPP__
#define __PDS_FUNCARRAYDATASET_HPP__


/** \defgroup FuncArrayDatasetGroup Funciones Pds::Array -- Image datset
 *  \brief Funciones que usan Pds::Quaternion, Ejemplo: etc 
 *  <div class="fragment"> \#include <Pds/FuncArrayDataset> </div>
 *   
 * Informacion adicional puede ser encontrada en @cite tutorialmatvec
 * @{
 */

#include <Pds/Ra>
#include <vector>

namespace Pds{


namespace Image{


namespace DataSet{

/** @name Funciones para Array dataset
 *  Herramientas genéricas que pueden ser usadas para Connected-component labeling.
 * @{
 */

    /** 
     *  \brief Generando datos de grupos de 1s formando cuadrados.
     *
     *  \image html A-binary-square.bmp "Binary squares"
     *  \param[in] BW matriz de datos a cargar con 1s y 0s.
     *  \param[in] L Seran generados alredor de L*L regiones.
     *  \param[in] Offset Desvio (aleatório) de la posicíon de los cuadrados.
     *  \ingroup FuncArrayDatasetGroup
     */
    bool LoadDataSquares(Pds::Array<unsigned char> &BW,unsigned int L=4,double Offset=1);

    /** 
     *  \brief Generando datos de grupos de 1s formando circulos.
     *
     *  \image html A-binary-circle.bmp "Binary circles"
     *  \param[in] BW matriz de datos a cargar con 1s y 0s.
     *  \param[in] L Seran generados alredor de L*L regiones.
     *  \param[in] Offset Desvio (aleatório) de la posicíon de los circulos.
     *  \ingroup FuncArrayDatasetGroup
     */
    bool LoadDataCircles(Pds::Array<unsigned char> &BW,unsigned int L=4,double Offset=1);

    /** 
     *  \brief Generando datos de grupos de 1s formando elipses.
     *
     *  \image html A-binary-ellipse.bmp "Binary ellipses"
     *  \param[in] BW matriz de datos a cargar con 1s y 0s.
     *  \param[in] L Seran generados alredor de L*L regiones.
     *  \param[in] Offset Desvio (aleatório) de la posicíon de las elipses.
     *  \ingroup FuncArrayDatasetGroup
     */
    bool LoadDataEllipses(Pds::Array<unsigned char> &BW,unsigned int L=4,double Offset=1);


/**
 * @}
 */

} // DataSet

} // Image

} // Pds
/**
 * @}
 */

#endif

