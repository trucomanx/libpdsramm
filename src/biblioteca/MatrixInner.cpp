/*
 * MatrixInner.cpp
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


#include <Pds/MatrixInner.hpp>

Pds::MatrixInner::MatrixInner(void)
{
    return;
}

Pds::MatrixInner::MatrixInner(  Pds::Matrix A, 
                                unsigned int lin_begin  ,unsigned int col_begin, 
                                unsigned int lin_end    ,unsigned int col_end)
{
    return;
}

Pds::MatrixInner::~MatrixInner(void)
{
    this->array=NULL;

    this->nlin=0;
    this->ncol=0;
}

