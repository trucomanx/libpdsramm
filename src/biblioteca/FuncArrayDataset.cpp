/*
 * FuncArrayDataset.cpp
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



#include <Pds/FuncArrayDataset>
#include <Pds/Ra>
#include <vector>
#include <set>
#include <list>
#include <iostream>




bool Pds::Image::DataSet::LoadDataSquares(Pds::Array<unsigned char> &A,unsigned int L,double des)
{
    if(A.IsEmpty()) return false;
    if(L==0)        return false;
    unsigned int Nlin=A.Nlin();
    unsigned int step_lin=Nlin/L;
    unsigned int Ncol=A.Ncol();
    unsigned int step_col=Ncol/L;

    des=fabs(des);

    unsigned int rl,rc;

    for(unsigned int cl=step_lin/2;cl<Nlin;cl=cl+step_lin)
    for(unsigned int cc=step_col/2;cc<Ncol;cc=cc+step_col)
    {
        if(des==0.0)
        {
            rl=0;
            rc=0;
        }
        else
        {
            rl=rand()%((unsigned int)(step_lin*des));
            rc=rand()%((unsigned int)(step_col*des));
        }
    
        unsigned int offset=step_lin/4;
        for(unsigned int lin=0;lin<step_lin/2;lin++)
        for(unsigned int col=0;col<step_col/2;col++)
        A.At(cl-offset+rl+lin,cc-offset+rc+col)=1;
    }
    return true;
}


bool Pds::Image::DataSet::LoadDataCircles(Pds::Array<unsigned char> &A,unsigned int L,double des)
{
    if(A.IsEmpty()) return false;
    if(L==0)        return false;
    unsigned int Nlin=A.Nlin();
    unsigned int step_lin=Nlin/L;
    unsigned int Ncol=A.Ncol();
    unsigned int step_col=Ncol/L;

    des=fabs(des);

    unsigned int rl,rc;
    double x,y;

    for(unsigned int cl=step_lin/2;cl<Nlin;cl=cl+step_lin)
    for(unsigned int cc=step_col/2;cc<Ncol;cc=cc+step_col)
    {
        if(des==0.0)
        {
            rl=0;
            rc=0;
        }
        else
        {
            rl=rand()%((unsigned int)(step_lin*des));
            rc=rand()%((unsigned int)(step_col*des));
        }
    
        unsigned int offset=step_lin/4;
        for(unsigned int lin=0;lin<step_lin/2;lin++)
        for(unsigned int col=0;col<step_col/2;col++)
        {
            x=lin+0.0-offset;
            y=col+0.0-offset;
            if( sqrt(x*x+y*y)<offset )
            A.At(cl+rl+(unsigned int)x,cc+rc+(unsigned int)y)=1;
        }
    }
    return true;
}


bool Pds::Image::DataSet::LoadDataEllipses(Pds::Array<unsigned char> &A,unsigned int L,double des)
{
    if(A.IsEmpty()) return false;
    if(L==0)        return false;
    unsigned int Nlin=A.Nlin();
    unsigned int step_lin=Nlin/L;
    unsigned int Ncol=A.Ncol();
    unsigned int step_col=Ncol/L;

    des=fabs(des);

    unsigned int rl,rc;
    double x,y;

    for(unsigned int cl=step_lin/2;cl<Nlin;cl=cl+step_lin)
    for(unsigned int cc=step_col/2;cc<Ncol;cc=cc+step_col)
    {
        if(des==0.0)
        {
            rl=0;
            rc=0;
        }
        else
        {
            rl=rand()%((unsigned int)(step_lin*des));
            rc=rand()%((unsigned int)(step_col*des));
        }
    
        unsigned int offset=step_lin/4;
        for(unsigned int lin=0;lin<step_lin/2;lin++)
        for(unsigned int col=0;col<step_col/2;col++)
        {
            x=lin+0.0-offset;
            y=col+0.0-offset;
            if( sqrt(x*x*2+y*y)<offset )
            A.At(cl+rl+(unsigned int)x,cc+rc+(unsigned int)y)=1;
        }
    }
    return true;
}
