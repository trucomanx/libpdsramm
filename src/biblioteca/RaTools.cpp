/*
 * RaTools.cpp
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


#include <Pds/RaTools>
#include <Pds/RaDefines>

#include <string>
#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>      // std::ifstream


long Pds::Ra::SignificativeLinesInFile(const char*filepath)
{
    long count;
    std::string line;

    if (filepath==NULL)         return -1;
    if (strlen(filepath)==0)    return -1;

    std::ifstream ifs(filepath, std::ifstream::in);	
    if (ifs.is_open()==false)   return -1;

    count=0;
    while(!ifs.eof())
    {
        line.clear();

        if (std::getline(ifs, line))
        if(Pds::Ra::IsSpacesString(line.c_str())==false) count++;
    }

    ifs.close();

	return count;
}


bool Pds::Ra::ElementsInFile(const char* filepath,unsigned int &Nel)
{
    unsigned int count;
    int N;

    std::string line;

    if (filepath==NULL)         return false;
    if (strlen(filepath)==0)    return false;

    std::ifstream ifs(filepath, std::ifstream::in);	
    if (ifs.is_open()==false)   return false;

    count=0;
    while(!ifs.eof())
    {
        line.clear();

        if (std::getline(ifs, line))
        if(Pds::Ra::IsSpacesString(line.c_str())==false)
        {
            N=Pds::Ra::ElementsInString(line);
            count=count+(unsigned int )N;
        }
    }

    ifs.close();

    Nel=count;
    
    return true;
}

bool Pds::Ra::ArraySizeInFile(const char*filepath,unsigned int &Nlin,unsigned int &Ncol)
{
    unsigned int count;
    int N;
    unsigned int last_ncol=0;

    std::string line;

    if (filepath==NULL)         return false;
    if (strlen(filepath)==0)    return false;

    std::ifstream ifs(filepath, std::ifstream::in);	
    if (ifs.is_open()==false)   return false;

    count=0;
    while(!ifs.eof())
    {
        line.clear();

        if (std::getline(ifs, line))
        if(Pds::Ra::IsSpacesString(line.c_str())==false)
        {
            N=Pds::Ra::ElementsInString(line);
            if(count==0)    last_ncol=(unsigned int)N;
            else if(last_ncol!=(unsigned int)N)
            {
                ifs.close();
                return false;
            }            
            count++;
        }
    }

    ifs.close();

    Nlin=count;
    Ncol=last_ncol;

	return true;
}

bool Pds::Ra::IsSpacesString(const char *str)
{
    int i;
    int N=strlen(str);

    for(i=0;i<N;i++)
    {
        if(isspace(str[i])==0)  return  false;
    }

    return true;
}

bool Pds::Ra::IsSpacesString(std::string str)
{
    return Pds::Ra::IsSpacesString(str.c_str());
}

int Pds::Ra::ElementsInString(const char *str)
{

    int N=0;
    int i=0;

    if(str==NULL)   return -1;

    while(str[i]!=0)
    {
        while((isspace(str[i])!=0)&&(str[i]!=0))   i++;

        if((isspace(str[i])==0)&&(str[i]!=0))
        {
            N++;
            while((isspace(str[i])==0)&&(str[i]!=0))   i++;
        }
    }
    return N;
}

int Pds::Ra::ElementsInString(std::string str)
{
    return Pds::Ra::ElementsInString(str.c_str());
}


////////////////////////////////////////////////////////////////////////////////

#include <sstream>
#include <iomanip>      // std::setprecision
#include <Pds/RaDefines>
#include <Pds/Matrix>
#include <Pds/Vector>

template std::string Pds::Ra::ToString<int>(int val);
template std::string Pds::Ra::ToString<unsigned int>(unsigned int val);
template std::string Pds::Ra::ToString<long>(long val);
template std::string Pds::Ra::ToString<unsigned long>(unsigned long val);
template std::string Pds::Ra::ToString<double>(double val);
template std::string Pds::Ra::ToString<float>(float val);
template std::string Pds::Ra::ToString<Pds::Matrix>(Pds::Matrix val);
template std::string Pds::Ra::ToString<Pds::Vector>(Pds::Vector val);
template std::string Pds::Ra::ToString<char>(char val);
template std::string Pds::Ra::ToString<const char*>(const char *val);
template std::string Pds::Ra::ToString<char*>(char *val);

template <typename T>
std::string Pds::Ra::ToString(T val)
{
    std::stringstream stream;
    stream <<std::setprecision(Pds::Ra::StringPrecision)<< val;
    return stream.str();
}

////////////////////////////////////////////////////////////////////////////////
