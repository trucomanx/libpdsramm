/*
 * Array.hpp
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

/** \file Array.hpp
 *  \author Fernando Pujaico Rivera
 *  \date 01-09-2018
 *  \brief Funciones que trabajan con un grupo de 2 datos.
 *  
 */



#ifndef __PDS_ARRAY_HPP__
#define __PDS_ARRAY_HPP__


/** \defgroup ArrayGroup Métodos Pds::Array.
 *  \brief Metodos de la clase Pds::Array, una agrupación de 2 datos
 *  <div class="fragment"> \#include <Pds/Array> </div>
 *  
 *  
 * Informacion adicional puede ser encontrada en @cite tutorialmatvec
 * @{
 */


#include <string>
#include <Pds/Size>
#include <Pds/RegionRect>
#include <vector>



namespace Pds{

class Matrix;
class Vector;

/*! \class Array
 *  \brief La clase tipo  Array .
 *  Esta clase genera una agrupación de 2 datos.
 *  Para usar incluir Pds/Array.
 *  \ingroup ArrayGroup
 *  \author Fernando Pujaico Rivera
 */
template <typename Datum>
class Array
{
public:
    /*! Un arreglo de Nlin lineas y Ncol elementos por linea. */
    Datum **array;
    /*! Número de lineas. */
    unsigned int nlin;
    /*! Número de columnas. */
    unsigned int ncol;
    
public:

/** @name Varios tipos de constructores Pds::Array
 *  Crean una objeto Pds::Array
 * @{
 */

    /** 
     *  \brief Crea un objeto de tipo Pds::Array
     *  \return un objeto de tipo Pds::Array.
     *  \ingroup ArrayGroup
     */
    Array(void);
    
    /** 
     *  \brief Crea un objeto de tipo Pds::Array
     *  \param[in] Nlin El numero de lineas de la array.
     *  \param[in] Ncol El numero de columnas de la array.
     *  \return un objeto de tipo Pds::Array.
     *  \ingroup ArrayGroup
     */
    Array(unsigned int Nlin,unsigned int Ncol);
    
    /** 
     *  \brief Crea un objeto de tipo Pds::Array
     *  \param[in] Nlin El numero de lineas de la array.
     *  \param[in] Ncol El numero de columnas de la array.
     *  \param[in] val El valor a usar.
     *  \return un objeto de tipo Pds::Array.
     *  \ingroup ArrayGroup
     */
    Array(unsigned int Nlin,unsigned int Ncol,Datum val);
    
    /** 
     *  \brief Crea un objeto de tipo Pds::Array con elementos inicializados con cero.
     * 
   Para crear una array A de 4 filas y 3 columnas:
\code{.cpp}
    Pds::Array B(4,3);
    Pds::Array A(B.Size);
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] S El tamaño de la array.
     *  \ingroup ArrayGroup
     */
    Array(const Pds::Size &S);

    /** 
     *  \brief Crea un objeto de tipo Pds::Array copiando datos desde 
     *  otra array. Este es un Copy assignment constructor.
     * 
   Para crear una array A con copia de datos de una array B:
\code{.cpp}
    Pds::Array B(4,3,-1.0);
    Pds::Array A(B);
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] B Matriz a copiar.
     *  \ingroup ArrayGroup
     */
    Array(const Pds::Array<Datum> &B);

    /** 
     *  \brief Crea un objeto de tipo Pds::Array copiando datos desde 
     *  std::vector. 
     * 
   Para crear una array A con copia de datos de una array B:
\code{.cpp}
    std::vector<unsigned int> b={1,2,4,6};
    Pds::Array<unsigned int> A(b);
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] b Vetor a copiar.
     *  \ingroup ArrayGroup
     */
    Array(const std::vector<Datum> &b);

    /** 
     *  \brief Crea un objeto de tipo Pds::Array copiando datos desde 
     *  un Pds::Matrix.
     * 
   Para crear una array A con copia de datos de una array B:
\code{.cpp}
    Pds::Matrix B(4,3,1.0);
    Pds::Array A(B);
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] B Matriz a copiar, redondea con floor si necesario y convierte cuando necesario.
     *  \ingroup ArrayGroup
     */
    Array(const Pds::Matrix &B);

    ~Array(); 

/**
 * @}
 */

public:

/** @name Métodos de asignacion Pds::Array
 *  Indican o establecen el estado de una array.
 * @{
 */

    /** 
     *  \brief Copia en si mismo (A), una array B. Este operador es 
     *  similar al método Copy().
     *  No importa  el tamaño de A, sus datos son liberados y un nuevo
     *  arreglo de datos es reservado.
     *
     *  \f[ A \leftarrow B \f]
     * Cuando acontece:
\code{.cpp}
    Pds::Array B(nlin,ncol);
    A=B;
\endcode
     * Cuando NO acontece:
\code{.cpp}
    Pds::Array A=Pds::Array(nlin,ncol);
\endcode
     *  \param[in] B la array a copiar
     *  \return Retorna el operador de la izquierda (acumulador) con el
     *  resultado, o una array vacía (this->IsEmpty() igual a true) en caso de error.
     *  \see Copy
     *  \ingroup ArrayGroup
     */
    Pds::Array<Datum>& operator = (const Pds::Array<Datum> &B);
    
    /** 
     *  \brief Copia en si mismo (A), el contenido de una array B. Este 
     *  método es similar a usar el operador = .
     *  No importa  el tamaño de A, sus datos son liberados y un nuevo
     *  arreglo de datos es reservado.
     *
     *  \f[ A \leftarrow B \f]
     *  \param[in] B la array a copiar
     *  \return Retorna true si todo fue bien o false si no. Si se retorna false
     *  el receptor no altera su contenido.
     *  \see Copy
     *  \ingroup ArrayGroup
     */
    bool Copy(const Pds::Array<Datum> &B);
    
/**
 * @}
 */

public:

/** @name Métodos de estado Pds::Array
 *  Indican o establecen el estado de una array.
 * @{
 */

    /** 
     *  \brief Verifica si la array es nula es decir con lineas o columnas cero o arreglo NULL.
     *  
     *  Una array\f$\mathbf{A}\f$ está vacía si  \f$ \mathbf{A}=[]\f$.
     *  \return Retorna true si es nula e false si no.
     *  \ingroup ArrayGroup
     */
    bool IsEmpty(void) const;

    /** 
     *  \brief Verifica si las matrices son similares en tamaño.
     * 
     *  Una array\f$A_{M,N}\f$ es similar a \f$B_{P,Q}\f$ 
     *  si  \f$M=P\f$ y \f$N=Q\f$.
     *  \param[in] B Matriz en consulta.
     *  \return Retorna false si son similares y true si no.
     *  \ingroup ArrayGroup
     */
    bool IsNotSimilarTo(const Pds::Array<Datum> &B) const;


/**
 * @}
 */

public:

/** @name Métodos de fill  Pds::Array
 *  Herramientas genéricas para lectura y escritura de datos.
 * @{
 */
    /** 
     *  \brief Inicializa la array con números con unos y ceros con una probabilidad de 1 igual a p1.
     *
     *  \warning La función usa internamente la función rand(), 
     *  si se desea esta puede ser aleatoriamente inicializada usando la funcíón Pds::Ra::Randomize(),
     *  de lo contrario los números pseudo aleatórios siempre seguirán la misma secuencia.
     * 
     *  \param[in] p1 Probabilidad de encontrar un 1.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup ArrayGroup
     */
    bool FillRandC(double p1);

    /** 
     *  \brief Inicializa la array con números enteros desde min a max.
     *
     *  \warning La función usa internamente la función rand(), 
     *  si se desea esta puede ser aleatoriamente inicializada usando la funcíón Pds::Ra::Randomize(),
     *  de lo contrario los números pseudo aleatórios siempre seguirán la misma secuencia.
     * 
     *  \param[in] min Valor mínimo.
     *  \param[in] max Valor máximo.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup ArrayGroup
     */
    bool FillRandI(unsigned int min,unsigned int max);

/**
 * @}
 */

public:

/** @name Métodos estatisticos básicos de Pds::Array
 *  Herramientas genéricas para lectura y escritura de datos.
 * @{
 */

    /** 
     *  \brief Retorna la suma de todos los elementos del array.
     *  \return Retorna la suma de todos los elementos del array.
     *  \ingroup ArrayGroup
     */
    Datum Sum(void) const;

/**
 * @}
 */

public:

/** @name Métodos de tamaño Pds::Array
 *  Herramientas genéricas para lectura y escritura de datos.
 * @{
 */
    
    /** 
     *  \brief Retorna el numero de lineas de la array.
     *  \return Retorna el numero de lineas de la array.
     *  \ingroup ArrayGroup
     */
    unsigned int Nlin(void) const;
    
    /** 
     *  \brief Retorna el numero de columnas de la array.
     *  \return Retorna el numero de columnas de la array.
     *  \ingroup ArrayGroup
     */
    unsigned int Ncol(void) const;
    
    /** 
     *  \brief Retorna el numero de elementos de la array (Nlin x Ncol).
     *  \return Retorna el numero de elementos de la array.
     *  \ingroup ArrayGroup
     */
    unsigned int Nel(void) const;
    
    /** 
     *  \brief Retorna un objeto de tipo Pds::Size con el numero de lineas y columans.
     *  \return Retorna el tamano de la array.
     *  \ingroup ArrayGroup
     */
    Pds::Size Size(void) const;


/**
 * @}
 */

public:

/** @name Métodos get y set de elementos Pds::Array.
 *  Herramientas genéricas para lectura y escritura de datos.
 * @{
 */
    /** 
     *  \brief Retorna una variable Datum en la posición (lin,col) de la array. 
     *  Hace una verificación para evitar leer fuera de la memoria, 
     *  si no está retorna zero 
     *  \param[in] lin La linea en consulta.
     *  \param[in] col La columna en consulta.
     *  \return Retorna una variable Datum en la posición (lin,col). 
     *  \ingroup ArrayGroup
     */
    Datum Get(unsigned int lin,unsigned int col) const;

    /** 
     *  \brief Establece una variable Datum en la posición (lin,col) de la array. 
     *  Hace una verificación para evitar escribir fuera de la memoria, 
     *  si no está retorna false y no escribe nada. 
     *  \param[in] lin La linea en consulta.
     *  \param[in] col La columna en consulta.
     *  \param[in] val valor a escribir.
     *  \return Retorna true si todo fue bien o false si no. 
     *  \ingroup ArrayGroup
     */
    bool Set(unsigned int lin,unsigned int col,Datum val);

    /** 
     *  \brief Retorna una variable Datum en la posición (id) de la array. 
     *  Hace una verificación para evitar leer fuera de la memoria, 
     *  si no está retorna zero 
     *  \param[in] id La posicion en consulta.
     *  \return Retorna una variable Datum en la posición (lin,col). 
     *  \ingroup ArrayGroup
     */
    Datum Get(unsigned int id) const;

    /** 
     *  \brief Retorna una variable Datum en la posición (lin,col) de la array. 
     *  \warning NO hace una verificación para evitar leer fuera de la memoria, 
     *  por lo que dará errores de acceso si pedimos una posición inexistente. 
     *  \param[in] lin La linea en consulta.
     *  \param[in] col La columna en consulta.
     *  \return Retorna una variable Datum en la posición (lin,col). 
     *  \ingroup ArrayGroup
     */
    const Datum &GetRaw(unsigned int lin,unsigned int col) const
    {
        return this->array[lin][col];
    }


    /** 
     *  \brief Establece una variable Datum en la posición (lin,col) de la array. 
     *  \warning NO hace una verificación para evitar leer fuera de la memoria, 
     *  por lo que dará errores de acceso si pedimos una posición inexistente. 
     *  \param[in] lin La linea en consulta.
     *  \param[in] col La columna en consulta.
     *  \param[in] val valor a escribir.
     *  \return Retorna true si todo fue bien o false si no. 
     *  \ingroup ArrayGroup
     */
    void SetRaw(unsigned int lin,unsigned int col,const Datum &val)
    {
        this->array[lin][col]=val;
    }

    /** 
     *  \brief Retorna una variable Datum en la posición (lin,col) de la array. 
     *  Hace una verificación para evitar leer o escribir fuera de la memoria, 
     *  con este fin hace lin=lin%Nlin y col=col%Ncol. 
     *  \param[in] lin La linea en consulta.
     *  \param[in] col La columna en consulta.
     *  \return Retorna una variable Datum en la posición (lin,col). 
     *  \ingroup ArrayGroup
     */
    Datum &At(unsigned int lin,unsigned int col);

    /** 
     *  \brief Retorna una variable Datum en la posición (id) de la array. 
     *  Hace una verificación para evitar leer o escribir fuera de la memoria, 
     *  con este fin hace id=id%(Nlin*Ncol). 
     *  \param[in] id La posicion en consulta.
     *  \return Retorna una variable Datum en la posición (id). 
     *  \ingroup ArrayGroup
     */
    Datum &At(unsigned int id);
/**
 * @}
 */

public:

/** @name Métodos con regiones con Pds::Array.
 *  Herramientas genéricas
 * @{
 */

    /** 
     *  \brief Retorna un vector con el histograma. 
     *  \param[in] R Region de busca.
     *  \param[in] min Valor mínimo del histograma.
     *  \param[in] max Valor máximo del histograma.
     *  \return Retorna una vector con un histograma. 
     *  \ingroup ArrayGroup
     */
    Pds::Vector HistogramNorm(const Pds::RegionRect &R,unsigned int min,unsigned int max) const;


    /** 
     *  \brief Retorna una variable Pds::RegionRect desde la posicion (0,0), con ancho y alto (Mat.Nlin(),Mat.Ncol()).
     *  \return La region si todo fue bien, sino se retorna una region donde IsEmpty() == true.
     *  \ingroup MatrixGroup
     */
    Pds::RegionRect GetRegion(void) const;

/**
 * @}
 */


public:

/** @name Métodos Static con Array
 *  Herramientas genéricas que pueden ser usadas desde Pds::Matrix
 * @{
 */

   /** 
     *  \brief Lee matrices de un archivo binario en formato BMP.
     * 
     *  \warning Solo lee matrices con :
<table>
<caption id="multi_row_inport_array">Suported bmp files</caption>
    <tr><td>Without compression
    <tr><td>Number of planes equal to 1
    <tr><td>8,16,24 o 32 bits by pixel.
</table> 
     *  \param[in] bmpfilepath Nombre del archivo donde se leeran los datos.
     *  \return Retorna un vector de matrices, una matriz por cada byte en un pixel.
     *  \ingroup ArrayGroup
     */
    static std::vector<Pds::Array<Datum>>  ImportBmpFile(const std::string &bmpfilepath);

/**
 * @}
 */


public:

/** @name Métodos Static con standard c arrays
 *  Herramientas genéricas que pueden ser usadas desde Pds::Array
 * @{
 */
    /** 
     *  \brief crea dinámicamente un arreglo de A.Nlin() lineas y A.Ncol() columnas,
     *  con los datos copiados de una matriz A.
     *  \param[in] A Matriz de donde se copiaran datos.
     *  \return Retorna un puntero al arreglo, o NULL si no consiguió reservar
     * la memoria. Esta memoria debe ser liberada siempre com ArrayRelease
     *  \ingroup ArrayGroup
     */
    static Datum** ArrayAllocate(const Pds::Matrix &A);

    /** 
     *  \brief crea dinámicamente un arreglo de A.Nlin() lineas y A.Ncol() columnas,
     *  con los datos copiados de una matriz A.
     *  \param[in] A Array de donde se copiaran datos.
     *  \return Retorna un puntero al arreglo, o NULL si no consiguió reservar
     * la memoria. Esta memoria debe ser liberada siempre com ArrayRelease
     *  \ingroup ArrayGroup
     */
    static Datum** ArrayAllocate(const Pds::Array<Datum> &A);

    
    /** 
     *  \brief crea dinámicamente un arreglo de Nlin lineas y Ncol columnas,
     *  con elementos inicializado con un valor.
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \param[in] Ncol El numero de columnas en el arreglo.
     *  \param[in] val El valor a usar.
     *  \return Retorna un puntero al arreglo, o NULL si no consiguió reservar
     * la memoria. Esta memoria debe ser liberada siempre com ArrayRelease
     *  \ingroup ArrayGroup
     */
    static Datum** ArrayAllocate(unsigned int Nlin,unsigned int Ncol,Datum val);
    
    /** 
     *  \brief crea dinámicamente un arreglo de Nlin lineas y Ncol columnas
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \param[in] Ncol El numero de columnas en el arreglo.
     *  \return Retorna un puntero al arreglo, o NULL si no consiguió reservar
     * la memoria. Esta memoria debe ser liberada siempre com ArrayRelease
     *  \ingroup ArrayGroup
     */
    static Datum** ArrayAllocate(unsigned int Nlin,unsigned int Ncol);

   /** 
     *  \brief Libera un arreglo de Nlin lineas y Ncol columnas (arreglo de arreglos)
     * Adicionalmente carga con NULL al arreglo a liberar.
     *  \param[in] array El arreglo de arreglos de de Nlin lineas y Ncol columnas
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \ingroup ArrayGroup
     */
    static void ArrayRelease(Datum** &array,unsigned int Nlin);

    /** 
     *  \brief crea dinámicamente un arreglo de Nlin lineas y Ncol columnas,
     *  con los datos copiados de una matriz A copiando en orden hasta donde sea posible.
     *  \param[in] A Array de donde se copiaran datos.
     *  \param[in] Nlin Número de lineas.
     *  \param[in] Ncol Número de columnas.
     *  \return Retorna un puntero al arreglo, o NULL si no consiguió reservar
     * la memoria. Esta memoria debe ser liberada siempre com ArrayRelease
     *  \ingroup ArrayGroup
     */
    static Datum** ArrayReshape(const Pds::Array<Datum> &A,unsigned int Nlin,unsigned int Ncol);

   /** 
     *  \brief Convierte a un arreglo unidimensional un arreglo de Nlin
     *  lineas y Ncol columnas (arreglo de arreglos). Lee primero una columna entera.
     *  \param[in] array El arreglo de arreglos de de Nlin lineas y Ncol columnas
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \param[in] Ncol El numero de columnas en el arreglo.
     *  \return Retorna un Datum*. Si la matriz es nula retorna NULL.
     *  \ingroup ArrayGroup
     */
    static Datum *ArrayToLineArray(Datum **array,unsigned int Nlin,unsigned int Ncol);

   /** 
     *  \brief Convierte a un sdt::string un arreglo de Nlin lineas y Ncol columnas (arreglo de arreglos).
     *  \param[in] array El arreglo de arreglos de de Nlin lineas y Ncol columnas
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \param[in] Ncol El numero de columnas en el arreglo.
     *  \return Retorna un std::string. Si la matriz es nula retorna un string sin caracteres.
     *  \ingroup ArrayGroup
     */
    static std::string ArrayToString(Datum **array,unsigned int Nlin,unsigned int Ncol);

   /** 
     *  \brief Convierte un sdt::string con arreglo de Nlin lineas y Ncol columnas a un arreglo.
     *  \param[in] str Cadena a leer.
     *  \param[out] Nlin El numero de lineas en el arreglo.
     *  \param[out] Ncol El numero de columnas en el arreglo.
     *  \return Retorna un arreglo. en caso de error se retorna NULL.
     *  \ingroup ArrayGroup
     */
    static Datum **ArrayFromString(const std::string &str,unsigned int &Nlin,unsigned int &Ncol);

   /** 
     *  \brief Convierte un sdt::string con arreglo de Nlin lineas y 1 columna a un arreglo.
     *  \param[in] str Cadena a leer.
     *  \param[out] Nlin El numero de lineas en el arreglo.
     *  \param[out]  Ncol El numero de columnas en el arreglo. En caso de exito 
     *  este valor sera 1 en otro caso el valor original no es alterado.
     *  \return Retorna un arreglo. en caso de error se retorna NULL.
     *  \ingroup ArrayGroup
     */
    static Datum **ArrayColFromString(const std::string &str,unsigned int &Nlin,unsigned int &Ncol);

/**
 * @}
 */


public:

/** @name Métodos para export Pds::Array
 *  Herramientas genéricas que pueden ser usadas desde Pds::Array
 * @{
 */
   

   /** 
     *  \brief Escribe en una matriz en un archivo binario en formato BMP.
     *  Losdatos deben ir de 0 a 255, valores superiores o inferiores serán truncados.
     * 
     *  \param[in] colormap Mapa de colores. Ejemplo: Pds::Colormap::Jet, Pds::Colormap::Bone,
     *  \param[in] filepath Nombre del archivo donde se escribirán los datos 
     *  Pds::Colormap::Hot,Pds::Colormap::Jolly.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup ArrayGroup
     */
    bool ExportBmpFile(const unsigned char colormap[256][3],const std::string &filepath) const;

   /** 
     *  \brief Escribe en una matriz en un archivo binario en formato BMP.
     *  Losdatos deben ir de 0 a 255, valores superiores o inferiores serán truncados.
     * 
     *  \param[in] Colormap Mapa de colores debe tener 3 columnas obligatoriamente y 1 linea como mínimo.
     *  \param[in] filepath Nombre del archivo donde se escribirán los datos.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup ArrayGroup
     */
    bool ExportBmpFile(const Pds::Array<unsigned char> &Colormap,const std::string &filepath) const;
/**
 * @}
 */


public:

/** @name Métodos Static con standard c arrays para export
 *  Herramientas genéricas que pueden ser usadas desde Pds::Array
 * @{
 */
   
    /** 
     *  \brief Escribe los datos de una matriz en un archivo de en formato BMP.
     *
     *  <center>
     *  \image html pds_matrix_save_bmp_with_colormap_jet.bmp "grafico usando el colormap Pds::Colormap::Jet."
     *  </center>
     *  \param[in] array Arreglo donde se leerán los datos de escala de gris. \f$0\leq a_{ij} \leq 255\f$
     *  \param[in] Nlin Número de lineas del arreglo, equivalente a la altura de la imagen.
     *  \param[in] Ncol Número de columnas del arreglo, equivalente al ancho de la imagen.
     *  \param[in] colormap Mapa de colores. Ejemplo: Pds::Colormap::Jet, Pds::Colormap::Bone,
     *  \param[in] bmpfilepath Nombre del archivo donde se escribirán los datos 
     *  Pds::Colormap::Hot,Pds::Colormap::Jolly.
     *  \return true si todo fue bien o false si no. (ej. array,bmpfilepath==NULL)
     *  \ingroup ArrayGroup
     */
    static bool ArrayWriteBmpWithColormap(  Datum **array,
                                            unsigned int Nlin,
                                            unsigned int Ncol,
                                            const unsigned char colormap[256][3],
                                            const std::string &bmpfilepath);

   
    /** 
     *  \brief Escribe los datos de una matriz en un archivo de en formato BMP.
     *
     *  <center>
     *  \image html pds_matrix_save_bmp_with_colormap_jet.bmp "grafico usando el colormap Pds::Colormap::Jet."
     *  </center>
     *  \param[in] array Arreglo donde se leerán los datos de escala de gris. \f$0\leq a_{ij} \leq 255\f$
     *  \param[in] Nlin Número de lineas del arreglo, equivalente a la altura de la imagen.
     *  \param[in] Ncol Número de columnas del arreglo, equivalente al ancho de la imagen.
     *  \param[in] Colormap Mapa de colores debe tener 3 columnas obligatoriamente y 1 linea como mínimo.
     *  \param[in] bmpfilepath Nombre del archivo donde se escribirán los datos 
     *  \return true si todo fue bien o false si no. (ej. array,bmpfilepath==NULL)
     *  \ingroup ArrayGroup
     */
    static bool ArrayWriteBmpWithColormap(  Datum **array,
                                            unsigned int Nlin,
                                            unsigned int Ncol,
                                            const Pds::Array<unsigned char> &Colormap,
                                            const std::string &bmpfilepath);

    /** 
     *  \brief Escribe los datos de una matriz en un archivo de en formato BMP.
     *
     *  \param[in] arrayr Arreglo donde se leerán los datos de escala de gris. \f$0\leq r_{ij} \leq 255\f$
     *  \param[in] arrayg Arreglo donde se leerán los datos de escala de gris. \f$0\leq g_{ij} \leq 255\f$
     *  \param[in] arrayb Arreglo donde se leerán los datos de escala de gris. \f$0\leq b_{ij} \leq 255\f$
     *  \param[in] Nlin Número de lineas del arreglo, equivalente a la altura de la imagen.
     *  \param[in] Ncol Número de columnas del arreglo, equivalente al ancho de la imagen.
     *  \param[in] bmpfilepath Nombre del archivo donde se escribirán los datos.
     *  \return true si todo fue bien o false si no. (ej. array,bmpfilepath==NULL)
     *  \ingroup ArrayGroup
     */
    static bool ArrayWriteBmp(  Datum **arrayr,
                                Datum **arrayg,
                                Datum **arrayb,
                                unsigned int Nlin,
                                unsigned int Ncol,
                                const std::string &bmpfilepath);

    
   /** 
     *  \brief Salva en un archivo de texto un arreglo de Nlin lineas y Ncol columnas, 
     *  usando el formato Csv (Comma Separated Values).
     *  \param[in] filepath El archivo donde se guardaran los datos.
     *  \param[in] array El arreglo de arreglos de de Nlin lineas y Ncol columnas
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \param[in] Ncol El numero de columnas en el arreglo.
     *  \param[in] delimitador delimitador de elementos por defecto es ','.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup ArrayGroup
     */
    static bool ArrayWriteCsvFile(const std::string &filepath,Datum **array,unsigned int Nlin,unsigned int Ncol,char delimitador=',');

   /** 
     *  \brief Escribe en un archivo binario en formato de octave un
     *  arreglo de Nlin lineas y Ncol columnas (arreglo de arreglos).
     *  Es usado el nombre MAT0 como identificador de matriz.
     * 
Para cargar los datos en OCTAVE se puede usar el siguiente código
\verbatim
% Load all the variables in "matfile.mat" in the workspace.
load("-v4","matfile.mat");

% Load the B variable in a STRUCTURE
STRUCTURE=load("-v4","matfile.mat","B");
\endverbatim
     *  Version 4 MAT-File Format:[Documento externo](https://www.eiscat.se/wp-content/uploads/2016/03/Version-4-MAT-File-Format.pdf)
     *  [Documento oficial](https://www.mathworks.com/help/pdf_doc/matlab/matfile_format.pdf)
     *  \param[in] fp El descriptor de fichero que apunta a donde se guardaran los datos.
     *  \param[in] array El arreglo de arreglos de de Nlin lineas y Ncol columnas
     *  \param[in] pname El nombre de la matriz.
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \param[in] Ncol El numero de columnas en el arreglo.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup ArrayGroup
     */
    static bool ArrayWriteMatFile(FILE *fp,const char *pname,Datum **array,unsigned int Nlin,unsigned int Ncol);

   /** 
     *  \brief Escribe en un archivo binario en formato de octave un
     *  arreglo de Nlin lineas y Ncol columnas (arreglo de arreglos).
     *  Es usado el nombre MAT0 como identificador de matriz.
     * 
Para cargar los datos en OCTAVE se puede usar el siguiente código
\verbatim
% Load all the variables in "matfile.mat" in the workspace.
load("-v4","matfile.mat");

% Load the B variable in a STRUCTURE
STRUCTURE=load("-v4","matfile.mat","B");
\endverbatim
     *  Version 4 MAT-File Format:[Documento externo](https://www.eiscat.se/wp-content/uploads/2016/03/Version-4-MAT-File-Format.pdf)
     *  [Documento oficial](https://www.mathworks.com/help/pdf_doc/matlab/matfile_format.pdf)
     *  \param[in] fp El descriptor de fichero que apunta a donde se guardaran los datos.
     *  \param[in] arrayr El arreglo real de arreglos de de Nlin lineas y Ncol columnas.
     *  \param[in] arrayi El arreglo imag de arreglos de de Nlin lineas y Ncol columnas.
     *  \param[in] pname El nombre de la matriz.
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \param[in] Ncol El numero de columnas en el arreglo.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup ArrayGroup
     */
    static bool ArrayWriteMatFile(FILE *fp,const char *pname,Datum **arrayr,Datum **arrayi,unsigned int Nlin,unsigned int Ncol);

    
   /** 
     *  \brief Salva en un archivo un arreglo de Nlin lineas y Ncol columnas (arreglo de arreglos).
     *  \param[in] filepath El archivo donde se guardaran los datos.
     *  \param[in] array El arreglo de arreglos de de Nlin lineas y Ncol columnas
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \param[in] Ncol El numero de columnas en el arreglo.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup ArrayGroup
     */
    static bool ArraySave(const std::string &filepath,Datum **array,unsigned int Nlin,unsigned int Ncol);

   /** 
     *  \brief Lee de un archivo un arreglo de Nlin lineas y Ncol columnas (arreglo de arreglos).
     *  \param[in] filepath El archivo donde se leerán los datos.
     *  \param[out] Nlin Donde se escribirá el numero de lineas en el arreglo.
     *  \param[out] Ncol Donde se escribirá el numero de columnas en el arreglo.
     *  \return El arreglo de arreglos de de Nlin lineas y Ncol columnas. Si el numero de columnas 
     *  no es constante se retorna NULL. Si la función retorna NULL entonces los valores
     *  de entrada Nlin e Ncol no son alterados.
     *  \ingroup ArrayGroup
     */
    static Datum** ArrayLoad(const std::string &filepath,unsigned int& Nlin,unsigned int& Ncol);

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
     *  \ingroup ArrayGroup
     */
    static Datum** ArrayColLoad(const std::string &filepath,unsigned int& Nlin,unsigned int& Ncol);



/**
 * @}
 */
    
public:

/** @name Metodos variados datos Pds::Array.
 *  Muestra los datos
 * @{
 */


    /** 
     *  \brief libera los datos internos de la array y la convierte en una array nula.
     *  es decir con lineas y columnas cero.
     * 
     *  Una array\f$\mathbf{A}\f$ está vacía si  \f$ \mathbf{A}=[]_{0,0}\f$.
     *  \ingroup ArrayGroup
     */
    void MakeEmpty(void);

    /** 
     *  \brief Imprime en pantalla el contenido del array.
     *  \param[in] str cadena de texto que se mostrara antes del elemento.
     *  \ingroup ArrayGroup
     */
    void Print(std::string str) const;
    
    /** 
     *  \brief Imprime en pantalla el contenido del array.
     *  \ingroup ArrayGroup
     */
    void Print(void) const;


    /** 
     *  \brief Remodela los datos internos de la array y la convierte en una array de tamaño diferente,
     *  los datos que faltan se rellenan con cero.
     * 
     *  \param[in] Nlin Número de lineas.
     *  \param[in] Ncol Número de columnas.
     *  \ingroup ArrayGroup
     */
    bool Reshape(unsigned int Nlin,unsigned int Ncol);


    /** 
     *  \brief calcula los centroides de las muestras en el bloque Block.
     *  EL bloque Block tiene L muestras de N elementos.
     *  La matriz A tambien deve tener L elementos.
     * 
     *  \param[in] Block Vector de N matrices.
     *  \return Los centroides.
     *  \ingroup ArrayGroup
     */
    Pds::Matrix Centroids(const std::vector<Pds::Matrix> &Block) const;

    /** 
     *  \brief calcula los centroides de las muestras en X.
     *  La matriz tiene L muestras (lineas) de N elementos (columnas).
     * 
     *  \param[in] X Matriz de L muestras (lineas) y Ncolumans.
     *  \return Los centroides.
     *  \ingroup ArrayGroup
     */
    Pds::Matrix Centroids(const Pds::Matrix &X) const;
/**
 * @}
 */
   

}; // Class Array


} // namespace Pds



/*!
 * @}
 */

#endif

