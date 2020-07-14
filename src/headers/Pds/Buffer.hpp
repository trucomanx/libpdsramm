/*
 * Buffer.hpp
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

/** \file Buffer.hpp
 *  \author Fernando Pujaico Rivera
 *  \date 01-09-2018
 *  \brief Funciones que trabajan con objetos tipo Buffer.
 *  
 */



#ifndef __PDS_BUFFER_HPP__
#define __PDS_BUFFER_HPP__

#include <string>

/** \defgroup BufferGroup Métodos Pds::Buffer
 *  \brief Metodos de la clase Pds::Buffer, el tamaño de una matriz 
 *  <div class="fragment"> \#include <Pds/Buffer> </div>
 *  
 *  
 * Informacion adicional puede ser encontrada en @cite tutorialmatvec
 * @{
 */

namespace Pds{

/*! \class Buffer
 *  \brief La clase tipo  Pds::Buffer .
 *  Esta clase genera un objeto con dos parametros Nlin y Ncol.
 *  Para usar incluir Pds/Buffer.
 *  \ingroup BufferGroup
 *  \author Fernando Pujaico Rivera
 */
template<typename Datum> 
class Buffer
{

private:
    /*! Número de elementos del buffer. */
    unsigned int nel;
    
    /*! Un arreglo de nel elementos. */
    Datum *data;
    
    /*! Indice del ID de la primera muestra. */
    unsigned int front;


public:

/** @name Varios tipos de constructores
 *  Crean una objeto Pds::Buffer
 *   
 * @{
 */  
    /** 
     *  \brief Crea un objeto vacio de tipo Pds::Buffer
     *  \return un objeto de tipo Pds::Buffer.
     *  \ingroup BufferGroup
     */
    Buffer(void);

    /** 
     *  \brief Crea un objeto de tipo Pds::Buffer
     *  \param[in] Nel El número de elementos del buffer.
     *  \return un objeto de tipo Pds::Buffer.
     *  \ingroup BufferGroup
     */
    Buffer(unsigned int Nel);

    /** 
     *  \brief Crea un objeto de tipo Pds::Buffer de otro.
     *  \param[in] B Desde donde se copiarán los datos.
     *  \return un objeto de tipo Pds::Buffer.
     *  \ingroup BufferGroup
     */
    Buffer(const Pds::Buffer<Datum> &B);
    
    ~Buffer(); 
/**
 * @}
 */
    
public:
/** @name Lectura y escritura de datos en Pds::Buffer
 *  Lectura y escritura de datos en el buffer
 *   
 * @{
 */  

    /** 
     *  \brief Lee y escribe datos en la memoria en el Pds::Buffer.
     *
     *  \warning No se hace una verificación si la posición de memoria existe.
     *  \param[in] id Elemento a acceder en la memoria del buffer.
     *  \ingroup BufferGroup
     */
    Datum &operator[](const unsigned int &id)
    {
        return this->data[(this->front+id)%this->nel];
    }


    /** 
     *  \brief Empuja un nuevo dato en la memoria del Pds::Buffer.
     *
     *  Si nuestro objeto se llama Buff, el dato Dat pasa a ocupar la posicion Buff[0],
     *  y el dato anterior la posición Buff[1].
     *  \param[in] Dat Dato a colocar al frente del buffer.
     *  \ingroup BufferGroup
     */
    bool Push(const Datum &Dat);
/**
 * @}
 */
    
public:
/** @name Mostrando datos
 *   
 * @{
 */
 
    /** 
     *  \brief Muestra en pantalla el contenido de Pds::Buffer, elementos separados por tabulador.
     *  \param[in] str Texto a mostrar antes de imprimir el contenido.
     *  \ingroup BufferGroup
     */
    void Print(const std::string &str="") const;
 
    /** 
     *  \brief Retorna true si el objeto esta vacio y false si no.
     *  \return Retorna true si el objeto esta vacio y false si no.
     *  \ingroup BufferGroup
     */
    bool IsEmpty(void) const;
/**
 * @}
 */
}; // Class Buffer

} // namespace Pds


/*!
 * @}
 */

#endif

