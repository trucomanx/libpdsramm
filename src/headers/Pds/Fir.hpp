/*
 * Fir.hpp
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

/** \file Fir.hpp
 *  \author Fernando Pujaico Rivera
 *  \date 01-09-2018
 *  \brief Funciones que trabajan con objetos tipo Fir.
 *  
 */



#ifndef __PDS_FIR_HPP__
#define __PDS_FIR_HPP__

#include <string>
#include <vector>
#include <Pds/Ra>

/** \defgroup FirGroup Métodos Pds::Fir
 *  \brief Metodos de la clase Pds::Fir, el tamaño de una matriz 
 *  <div class="fragment"> \#include <Pds/Fir> </div>
 *  
 *  
 * Informacion adicional puede ser encontrada en @cite tutorialmatvec
 * @{
 */

namespace Pds{

/*! \class Fir
 *  \brief La clase tipo  Pds::Fir .
 *  Esta clase genera un objeto con dos parametros Nlin y Ncol.
 *  Para usar incluir Pds/Fir.
 *  \ingroup FirGroup
 *  \author Fernando Pujaico Rivera
 */
class Fir
{

private:
	/*! The order of filter */
	unsigned int M;

	/*! vector de pesos
     */
	double *H;

	/*! vector de datos
     */
	double *X;


public:

/** @name Varios tipos de constructores
 *  Crean una objeto Pds::Fir
 * @{
 */

    /** 
     *  \brief Crea un objeto de tipo Pds::Fir
     *  \return un objeto de tipo Pds::Fir.
     *  \ingroup FirGroup
     */
    Fir(void);
    

    /** 
     *  \brief Crea un filtro fir de orden N
     *  
     *  \param[in] H Vetor de datos H.
     *  \return un objeto de tipo Pds::Fir.
     *  \ingroup PdsFirGroup
     */
    Fir(const Pds::Vector &H);

    
    ~Fir(); 
    
/**
 * @}
 */

public:

/** @name Métodos para evaluar la estructura Pds::Fir
 *  evaluan
 * @{
 */

    /** 
     *  \brief Evalua el filtro FIR
     *  
     *  \param[in] x Valor de entrada do filtro.
     *  \return Retorna el valor filtrado.
     *  \ingroup FirGroup
     */
    double Evaluate(double x);

    /** 
     *  \brief Evalua cada elemento de um vector num filtro FIR
     *  
     *  \param[in] X Vector de entrada do filtro.
     *  \return Retorna un vector filtrado.
     *  \ingroup FirGroup
     */
    Pds::Vector Evaluate(const Pds::Vector &X);
/**
 * @}
 */

public:

/** @name Métodos de estado para Pds::Fir
 *  Indican o establecen el estado.
 * @{
 */

    /** 
     *  \brief Verifica si el bloque del algoritmo está inicializado es decir k=0 y N=0.
     *  
     *  \return Retorna true si es nula e false si no.
     *  \ingroup FirGroup
     */
    bool IsEmpty(void) const;

/**
 * @}
 */
    
public:

/** @name Mostrando datos
 *   
 * @{
 */
 
    /** 
     *  \brief Muestra en pantalla el contenido de Pds::Fir, elementos separados por tabulador.
     *  \param[in] str Texto a mostrar antes de imprimir el contenido.
     *  \ingroup FirGroup
     */
    void Print(std::string str="") const;
 
/**
 * @}
 */


}; // Class Fir

} // namespace Pds


/*!
 * @}
 */

#endif

