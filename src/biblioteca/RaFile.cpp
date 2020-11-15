/*
 * RaFile.cpp
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
#include <Pds/RaString>
#include <Pds/RaFile>
#include <Pds/RaDefines>

#include <string>
#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>      // std::ifstream

////////////////////////////////////////////////////////////////////////////////

char *Pds::Ra::Fgets(FILE *fd)
{
    char *line=NULL;
    int i;
    fpos_t init;
    int count,N;
    char c;

    if(fd==NULL)    return NULL;

    // init tiene la posicion actual.
    fgetpos(fd,&init);

    // Cuento en count el numero de caracteres incluyendo el salto de linea
    count=0;    c=0;
    while( (c!=10)&&(c!=EOF) )  /* \n */
    {
        c=fgetc(fd);
        if(c!=EOF) count++;
    }

    // cuento 1 retorno de carro si este existe despues del salto de linea.
    if(c!=EOF)
    {
        c=fgetc(fd);
        /* \r */
        if(c==13) count++;
    }

    // reinicio el descriptor
    fsetpos(fd,&init);

    // Numero total de caracteres incluyendo el salto de linea y 1 retorno de 
    // carro posterior si existe.
    N=count;

    // copio N caracteres desde el archivo
    line=(char*)calloc(N+1,sizeof(char));
    if (line==NULL) return NULL;
    for(i=0;i<N;i++)
    {    
        line[i]=fgetc(fd);
    }

    // N entiendo porque funciona, mas funciona.
    if(c==EOF)  
    {
        fseek( fd, 0, SEEK_END );
        fgetc(fd);
    }

    return line;
}

////////////////////////////////////////////////////////////////////////////////

long Pds::Ra::SignificativeLinesInFile(const std::string &filepath)
{
    long count;
    std::string line;

    if (filepath.size()==0)     return -1;
    //if (strlen(filepath)==0)    return -1;

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


bool Pds::Ra::ElementsInFile(const std::string &filepath,unsigned int &Nel)
{
    unsigned int count;
    int N;

    std::string line;

    if (filepath.size()==0)         return false;
    //if (strlen(filepath)==0)    return false;

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

bool Pds::Ra::ArraySizeInFile(const std::string &filepath,unsigned int &Nlin,unsigned int &Ncol)
{
    unsigned int count;
    int N;
    unsigned int last_ncol=0;

    std::string line;

    if (filepath.size()==0)         return false;
    //if (strlen(filepath)==0)    return false;

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

////////////////////////////////////////////////////////////////////////////////

std::string Pds::Ra::FullFile( std::initializer_list<std::string> str_text_list )
{   
    std::string out_str="";
    
    int i=0;
    for( auto elem : str_text_list )
    {
        if(i==0) out_str=elem;
        else     out_str=out_str+Pds::Ra::FileSep+elem;
        i++;
    }
    
    return out_str;
}
    
////////////////////////////////////////////////////////////////////////////////


std::string Pds::Ra::HomeDir(void)
{
    std::string homedir;

    #if defined(_WINDOWS_) || defined(_WIN32) || defined(WIN32)
    homedir=getenv("HOMEDRIVE")+Pds::Ra::FileSep+getenv("HOMEPATH");
    #elif defined(__linux__)
    homedir=getenv("HOME");
    #endif
    
    return homedir;
}
////////////////////////////////////////////////////////////////////////////////
#define __BUFFER_SIZE__ 4096
#if defined(_WINDOWS_) || defined(_WIN32) || defined(WIN32)
    #include <windows.h>
    #include <tchar.h>
#endif

#include <unistd.h>

std::string Pds::Ra::Programpath(void)
{
    char exepath[__BUFFER_SIZE__];
    memset(exepath, 0,__BUFFER_SIZE__);

    #if defined(_WINDOWS_) || defined(_WIN32) || defined(WIN32)
        int i;
        TCHAR buffer[__BUFFER_SIZE__];
        GetModuleFileName(NULL,buffer, __BUFFER_SIZE__) ;
        for(i = 0; buffer[i]; ++i) 
        {
          wchar_t wc = buffer[i];
          char c = (char)wc;
          exepath[i] = c;
        }
    #elif defined(__linux__)
        int ID=readlink("/proc/self/exe", exepath,__BUFFER_SIZE__-1);
        ID++;
    #else
        printf("The function pds_get_absolute_programpath() is not suported in this operating system.")
        exepath[0]='.'
    #endif

    char *CMD=(char *)calloc(strlen(exepath)+1,sizeof(char));
    sprintf(CMD,"%s",exepath);

    return CMD;
}

std::string Pds::Ra::Pwd(void)
{
    char cwd[__BUFFER_SIZE__];
    char *str=getcwd(cwd,__BUFFER_SIZE__-1);
    if(str==NULL) std::string("");
    
    return std::string(cwd);
}
////////////////////////////////////////////////////////////////////////////////


std::string Pds::Ra::Dirname(std::string filepath)
{
    char *ptr=NULL;
    int dir_path_size;
    int i;
    
    if(filepath.size()==0)  return "";
    
    const char *file_path=filepath.c_str();

    ptr=strrchr((char*)file_path,Pds::Ra::CharFileSep);

    if(ptr==NULL)
    {
        return "";
    }

    dir_path_size=(int)(ptr-file_path);
    std::string dir_path(dir_path_size,' ');
    
    for(i=0;i<dir_path_size;i++) dir_path[i]=file_path[i];

    return dir_path; 
}


std::string Pds::Ra::Basename(std::string filepath)
{
    char *ptr = NULL;
    
    if(filepath.size()==0)  return "";
        
    const char *file_path=filepath.c_str();

    ptr=strrchr((char*)file_path,Pds::Ra::CharFileSep);

    if(ptr==NULL)   return std::string((char*)file_path);
    else            return std::string(ptr + 1);
}


std::string Pds::Ra::Extension(std::string filepath)
{
    char *ptr = NULL;

    if(filepath.size()==0)  return "";
    
    std::string basename=Pds::Ra::Basename(filepath);
    if(basename.empty())  return "";
    if(basename[0]=='.')  return "";

    const char *base_name=basename.c_str();
    
    ptr=strrchr((char*)base_name,'.');

    if(ptr==NULL)
    {
        return std::string("");
    }
    else
    {
        return std::string(ptr + 1);
    }
}

std::string Pds::Ra::Filename(std::string filepath)
{
    char *ptr=NULL;
    int   file_name_size;
    int i;
    
    if(filepath.size()==0)  return "";

    std::string basename=Pds::Ra::Basename(filepath);
    if(basename.empty())  return "";
    
    
    const char *base_name=basename.c_str();

    ptr=strrchr((char*)base_name,'.');
    if(ptr==base_name)  return std::string(base_name);

    if(ptr==NULL)
    {
        return basename;
    }

    file_name_size=(int)(ptr-base_name);
    std::string file_name(file_name_size,' ');
    
    for(i=0;i<file_name_size;i++) file_name[i]=base_name[i];

    return file_name;
}


std::string Pds::Ra::ReplaceExtension(std::string filepath,std::string new_ext)
{
    char *ptr=NULL;
    char *ptr2=NULL;
    int   file_name_size;
    int i;

    if(filepath.size()==0)  return "";
    
    const char *file_path=filepath.c_str();
    ptr2=strrchr((char*)file_path,Pds::Ra::CharFileSep);
    if(ptr2==NULL)   ptr2=(char*)file_path;
    if(ptr2[0]==Pds::Ra::CharFileSep) ptr2++;
    if(ptr2[0]=='.') ptr2++;

    ptr=strrchr((char*)ptr2,'.');
    if(ptr==NULL)   ptr=ptr2+strlen(ptr2);

    file_name_size=(int)(ptr-file_path);
    std::string file_name(file_name_size,' ');
    
    for(i=0;i<file_name_size;i++) file_name[i]=file_path[i];

    return file_name+"."+new_ext;
}

////////////////////////////////////////////////////////////////////////////////
#include <sys/stat.h>
bool Pds::Ra::IsFile(std::string path)
{
    struct stat stat_result;
    stat(path.c_str(), &stat_result);

    if( access( path.c_str(), F_OK ) == -1 ) return false;

    if(S_ISREG(stat_result.st_mode)==0) return false;
    else                                return true;
}

bool Pds::Ra::IsDir(std::string path)
{
    struct stat stat_result;
    stat(path.c_str(), &stat_result);

    if( access( path.c_str(), F_OK ) == -1 ) return false;

    if(S_ISDIR(stat_result.st_mode))    return true;
    else                                return false;
}

////////////////////////////////////////////////////////////////////////////////
std::string Pds::Ra::GetParamString(int argc,
                                    char* const argv[],
                                    std::string param,
                                    std::string default_data)
{
	int i;
	if(argv==NULL)	return default_data;
	if(argc<=2)	    return default_data;
	
	for(i=1;i<(argc-1);i++)
	{
		if(strcmp(argv[i],param.c_str())==0)
		{
			return argv[i+1];
		}
	}
	return default_data;
}


/** \brief Retorna true si existe el parámetro param.
 *  \param[in] argc Cantidad de elementos de argv.
 *  \param[in] argv Cadenas de caracteres con  parámetros de entrada.
 *  \param[in] param Dato a buscar en las cadenas argv.
 *  \return Retorna true si todo fue bien o false si no.
 *  \ingroup PdsArgsFuncGroup
 */
bool Pds::Ra::ExistParam(int argc,char* const argv[],std::string param)
{
	int i;
	if((argv==NULL)||(param.c_str()==0))    return false;
	for(i=1;i<argc;i++)
	{
		if(strcmp(argv[i],param.c_str())==0)	return true;
	}
	return false;
}

