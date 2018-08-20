/*
 * Eye.hpp
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

/** \file Eye.hpp
 *  \author Fernando Pujaico Rivera
 *  \date 01-04-2011
 *  \brief Funciones que trabajan con matrices.
 *  
 *  <br>Estas funciones trabajan con una matriz de la forma.<br>
 *  \image html matrix.png "Matriz de NlinxNcol"
 *  \b Nlin es el número de lineas y \b Ncol es el número de columnas.
 */



#ifndef __PDS_EYE_HPP__
#define __PDS_EYE_HPP__


/** \defgroup EyeGroup Módulo Matrix: Eye.
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

#include <Pds/Matrix>

namespace Pds{

/*! \class Eye
 *  \brief La clase tipo  Eye .
 *  Esta clase genera una matriz de Nlin lineas y Ncol columnas.
 *  Para usar incluir Pds/Eye.
 *  \ingroup EyeGroup
 *  \author Fernando Pujaico Rivera
 */
class Eye: public Matrix
{

public:

/** @name Varios tipos de constructores
 *  Crean una objeto Pds::Eye
 * @{
 */

    /** 
     *  \brief Crea un objeto de tipo Pds::Eye
     *  \return un objeto de tipo Pds::Eye.
     *  \ingroup EyeGroup
     */
    Eye(void);
    
    /** 
     *  \brief Crea un objeto de tipo Pds::Eye
     *  \param[in] N El numero de lineas y columnas de la matriz.
     *  \return un objeto de tipo Pds::Eye.
     *  \ingroup EyeGroup
     */
    Eye(unsigned int N);

    ~Eye(); 
    
/**
 * @}
 */



}; // Class Eye


} // namespace Pds


/*!
 * @}
 */

#endif

