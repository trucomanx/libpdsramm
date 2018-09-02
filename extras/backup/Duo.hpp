/*
 * Duo.hpp
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

/** \file Duo.hpp
 *  \author Fernando Pujaico Rivera
 *  \date 01-09-2018
 *  \brief Funciones que trabajan con un grupo de 2 datos.
 *  
 */



#ifndef __PDS_DUO_HPP__
#define __PDS_DUO_HPP__


/** \defgroup DuoGroup Clase Pds::Duo.
 *  \brief Metodos de la clase Pds::Duo, una agrupación de 2 datos
 *  <div class="fragment"> \#include <Pds/Duo> </div>
 *  
 *  
 * Informacion adicional puede ser encontrada en @cite tutorialmatvec
 * @{
 */


#include <string>
//#include <iostream>


namespace Pds{

/*! \class Duo
 *  \brief La clase tipo  Duo .
 *  Esta clase genera una agrupación de 2 datos.
 *  Para usar incluir Pds/Duo.
 *  \ingroup DuoGroup
 *  \author Fernando Pujaico Rivera
 */
template <typename Datum>
class Duo
{
public:
    /*! Primer dato */
    Datum dat0;
    /*! Segundo dato. */
    Datum dat1;
    
public:

/** @name Varios tipos de constructores
 *  Crean una objeto Pds::Duo
 * @{
 */

    /** 
     *  \brief Crea un objeto de tipo Pds::Duo
     *  \return un objeto de tipo Pds::Duo.
     *  \ingroup DuoGroup
     */
    Duo(void);
    
    /** 
     *  \brief Crea un objeto de tipo Pds::Duo
     *  \param[in] D0 El valor del primer dato.
     *  \param[in] D1 El valor del segundo dato.
     *  \return un objeto de tipo Pds::Duo.
     *  \ingroup DuoGroup
     */
    Duo(Datum D0,Datum D1);

    ~Duo(); 
    
/**
 * @}
 */
    
public:

/** @name Imprimir datos.
 *  Muestra los datos
 * @{
 */
    /** 
     *  \brief Imprime en pantalla el contenido del duo.
     *  \param[in] str cadena de texto que se mostrara antes del elemento.
     *  \ingroup DuoGroup
     */
    void Print(std::string str) const;
    
    /** 
     *  \brief Imprime en pantalla el contenido del duo.
     *  \param[in] str cadena de texto que se mostrara antes del elemento.
     *  \ingroup DuoGroup
     */
    void Print(const char *str) const;
    
    /** 
     *  \brief Imprime en pantalla el contenido del duo.
     *  \ingroup DuoGroup
     */
    void Print(void) const; 
    
    
/**
 * @}
 */
    
public:

/** @name Operaciones notables.
 *  Operaciones con Duo
 * @{
 */
    
    /** 
     *  \brief Producto punto con sigo mismo.
     *  \return Un elemento Duo con el resultado de la operación.
     *  \ingroup DuoGroup
     */
    Datum Dot(void) const; 
    
    /** 
     *  \brief Producto punto con otra variable Duo.
     *  \param[in] B Elemento a multiplicar.
     *  \return Un elemento Duo con el resultado de la operación.
     *  \ingroup DuoGroup
     */
    Datum Dot(const Duo B) const; 
    
    
    /** 
     *  \brief Suma un valor.
     *  \param[in] beta Elemento a sumar.
     *  \return Un elemento Duo con el resultado de la operación.
     *  \ingroup DuoGroup
     */
    Duo Add(Datum beta) const;
    
    /** 
     *  \brief Suma un valor.
     *  \param[in] beta Elemento a sumar.
     *  \return Un elemento Duo con el resultado de la operación.
     *  \ingroup DuoGroup
     */
    Duo operator+(Datum beta) const; 
    
    /** 
     *  \brief Suma un valor.
     *  \param[in] B Elemento a sumar.
     *  \return Un elemento Duo con el resultado de la operación.
     *  \ingroup DuoGroup
     */
    Duo Add(Duo B) const; 
    
    /** 
     *  \brief Suma un valor.
     *  \param[in] B Elemento a sumar.
     *  \return Un elemento Duo con el resultado de la operación.
     *  \ingroup DuoGroup
     */
    Duo operator+(Duo B) const; 
    
    
    /** 
     *  \brief Multiplica por un valor.
     *  \param[in] beta Elemento a multiplicar.
     *  \return Un elemento Duo con el resultado de la operación.
     *  \ingroup DuoGroup
     */
    Duo Mul(Datum beta) const;
    
    /** 
     *  \brief Multiplica por un valor.
     *  \param[in] beta Elemento a multiplicar.
     *  \return Un elemento Duo con el resultado de la operación.
     *  \ingroup DuoGroup
     */
    Duo operator*(Datum beta) const; 
    
    /** 
     *  \brief Multiplica por un elemento. Multiplica
     *  como si fueran numeros complejos.
     *  \param[in] B Elemento a multiplicar.
     *  \return Un elemento Duo con el resultado de la operación.
     *  \ingroup DuoGroup
     */
    Duo operator*(Duo B) const; 
    
/**
 * @}
 */
}; // Class Duo


} // namespace Pds

    /** 
     *  \brief Retorna el contenido del elemento Duo por la salida estándar
     *
\code{.cpp}
    std::cout<<B;
\endcode
     * es equivalente a :
\code{.cpp}
    std::cout<<B.ToString();
\endcode
     *  \param[in] out La salida
     *  \param[in] B Elemento a multiplicar.
     *  \return Retorna la misma salida estándar out.
     *  \ingroup DuoGroup
     */
template <class Datum>
std::ostream& operator<<(std::ostream &out,const Pds::Duo<Datum> &B);

    /** 
     *  \brief Suma con B, un valor alpha y el resultado es
     * cargado en C. Este operador 
     *  es similar al método Add() 
     *
     *  \f[ C \leftarrow \alpha+B \f]
\code{.cpp}
    Pds::Duo B(4,4);
    Pds::Duo C;
    
    C=2.0+B;
    
    std::cout<<C;
\endcode
     *  \param[in] alpha El valor a sumar
     *  \param[in] B Elemento a sumar
     *  \return Retorna un nuevo objeto con el resultado.
     *  \see Add
     *  \ingroup DuoGroup
     */
template <class Datum>
Pds::Duo<Datum> operator+(Datum alpha,const Pds::Duo<Datum> &B);

template <class Datum,class T>
Pds::Duo<Datum> operator+(T alpha,const Pds::Duo<Datum> &B);

    /** 
     *  \brief Multiplica por B, un valor alpha y el resultado es
     * cargado en C. Este operador 
     *  es similar al método Mul() 
     *
     *  \f[ C \leftarrow \alpha*B \f]
\code{.cpp}
    Pds::Duo B(4,4);
    Pds::Duo C;
    
    C=2.0*B;
    
    std::cout<<C;
\endcode
     *  \param[in] alpha El valor a multiplicar
     *  \param[in] B Elemento a multiplicar
     *  \return Retorna un nuevo objeto con el resultado.
     *  \see Mul
     *  \ingroup DuoGroup
     */
template <class Datum>
Pds::Duo<Datum> operator*(Datum alpha,const Pds::Duo<Datum> &B);

template <class Datum,class T>
Pds::Duo<Datum> operator*(T alpha,const Pds::Duo<Datum> &B);

/*!
 * @}
 */

#endif

