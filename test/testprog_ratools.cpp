/** \example testprog_ratools.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <iostream>
#include <Pds/Ra>

    
int main(void)
{
    char filepath[]="filedat.txt";
    char str1[]=" \t \t \n";
    char str2[]=" Hola como\testas \n";
    long N;
    
    std::list<std::string> Token=Pds::Ra::Split(str2," \t\n");
    
    std::list<std::string>::iterator iter;
    for( iter = Token.begin(); iter != Token.end(); ++iter)
    std::cout<<"["<<*iter<<"]\n";
    
    Pds::Matrix A=Pds::Ones(4,3);
    A.Save(filepath);
    
    if(Pds::Ra::IsSpacesString(str1))   std::cout<<"str1 is a space line\n";
    else                                std::cout<<"str1 is not a space line\n";
    
    if(Pds::Ra::IsSpacesString(str2))   std::cout<<"str2 is a space line\n";
    else                                std::cout<<"str2 is not a space line\n";
    
    N=Pds::Ra::ElementsInString(str1);
    std::cout<<"str1 has "<<N<<" elements\n";
    
    N=Pds::Ra::ElementsInString(str2);
    std::cout<<"str2 has "<<N<<" elements\n";
    
    
    N=Pds::Ra::SignificativeLinesInFile(filepath);
    std::cout<<"Number of significative lines in "<<filepath<<" is "<<N<<std::endl;
    
    unsigned int Nlin=0,Ncol=0,Nel=0;
    bool status;
    
    status=Pds::Ra::ArraySizeInFile(filepath,Nlin,Ncol);
    if(status==true)
    std::cout<<"Nlin:"<<Nlin<<"\nNcol"<<Ncol<<std::endl;
    
    status=Pds::Ra::ElementsInFile(filepath,Nel);
    if(status==true)
    std::cout<<"Nel:"<<Nel<<std::endl;
    
    std::cout   <<"Pds::Ra::ToString(0.1234567890123456789):"
                <<Pds::Ra::ToString(0.1234567890123456789)<<std::endl;
    std::cout   <<"Pds::Ra::ToString(\"hola\"):"
                <<Pds::Ra::ToString("hola")<<std::endl;
    
    std::cout   <<"STATE: "<<Pds::Ra::ArraySizeInString("1 2 3\n4 5 6",Nlin,Ncol)<<std::endl
                <<" Nlin: "<<Nlin<<std::endl
                <<" Ncol: "<<Ncol<<std::endl;
    
    return 0;
}
