/*
 * RealArraysTools.cpp
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


#include <Pds/RealArraysTools>
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
        bool state=std::getline(ifs, line);

        if (state==true)
        if(Pds::Ra::IsSpace(line.c_str())==false) count++;
    }

    ifs.close();

	return count;
}


bool Pds::Ra::ElementsInFile(const char* filepath,unsigned int &Nel)
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
        bool state=std::getline(ifs, line);

        if (state==true)
        if(Pds::Ra::IsSpace(line.c_str())==false)
        {
            N=Pds::Ra::NumberOfElements(line);
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
        bool state=std::getline(ifs, line);

        if (state==true)
        if(Pds::Ra::IsSpace(line.c_str())==false)
        {
            N=Pds::Ra::NumberOfElements(line);
            if(count==0)    last_ncol=(unsigned int)N;
            else if(last_ncol!=N)
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

bool Pds::Ra::IsSpace(const char *str)
{
    int i;
    int N=strlen(str);

    for(i=0;i<N;i++)
    {
        if(isspace(str[i])==0)  return  false;
    }

    return true;
}

bool Pds::Ra::IsSpace(std::string str)
{
    return Pds::Ra::IsSpace(str.c_str());
}

int Pds::Ra::NumberOfElements(const char *str)
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

int Pds::Ra::NumberOfElements(std::string str)
{
    return Pds::Ra::NumberOfElements(str.c_str());
}

