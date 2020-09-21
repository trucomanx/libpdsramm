/*
 * RegionRect_static_regionrect.cpp
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


#include <Pds/RegionRect>
#include <vector>

////////////////////////////////////////////////////////////////////////////////
Pds::RegionRect Pds::RegionRect::Intersection(const std::vector<Pds::RegionRect> &B)
{
    Pds::RegionRect R;
    unsigned int N=B.size();
    if(N==0)    return R;    
    
    R=B[0];
    for(unsigned int n=1;n<N;n++)
    R=R.Intersection(B[n]);
    
    return R;
}

////////////////////////////////////////////////////////////////////////////////
Pds::RegionRect Pds::RegionRect::Superior(const std::vector<Pds::RegionRect> &B)
{
    Pds::RegionRect R;
    unsigned int N=B.size();
    if(N==0)    return R;    
    
    R=B[0];
    for(unsigned int n=1;n<N;n++)
    R=R.Superior(B[n]);
    
    return R;
}

////////////////////////////////////////////////////////////////////////////////
Pds::RegionRect Pds::RegionRect::Mean(const std::vector<Pds::RegionRect> &B)
{
    Pds::RegionRect R;
    unsigned int N=B.size();
    if(N==0)    return R;
    
    unsigned int L0=0;
    unsigned int C0=0;
    unsigned int Nlin=0;
    unsigned int Ncol=0;
    unsigned int L=0;
    
    for(unsigned int n=1;n<N;n++)
    {
        if((B[n].Nlin!=0)&&(B[n].Ncol!=0))
        {
            L0+=B[n].L0;
            C0+=B[n].C0;
            Nlin+=B[n].Nlin;
            Ncol+=B[n].Ncol;
            L++;
        }
    }
    
    L0=L0/L;
    C0=C0/L;
    Nlin=Nlin/L;
    Ncol=Ncol/L;
    
    return Pds::RegionRect(L0,C0,Nlin,Ncol);
}
