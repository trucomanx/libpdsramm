/** \example testprog_matrix_static_array.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
    
#include <iostream>
#include <Pds/RealArrays>
#include <cmath>
    
int main(void)
{
    std::string str;
    Pds::Matrix A=Pds::Eye(3);
    
    unsigned int Nlin=2;
    unsigned int Ncol=2;
    double **array=NULL;
    
    char filepath[]="filedat.txt";
    
    array=Pds::Matrix::AllocateArray(Nlin,Ncol);
    if(array==NULL)   return 0; 
    
    array[0][0]=0.0/0.0;
    array[0][1]=0.0/1.0;
    array[1][0]=1.0/0.0;
    array[1][1]=1.0/1.0;
    
    str=Pds::Matrix::ArrayToString(array,Nlin,Ncol);
    std::cout<<str;
    
    Pds::Matrix::SaveArray(filepath,array,Nlin,Ncol);
    
    Pds::Matrix::ReleaseArray(array,Nlin);
    std::cout<<std::endl<<"array="<<array<<std::endl<<std::endl;
    
    
    array=Pds::Matrix::AllocateArray(A);
    if(array==NULL)   return 0;
    
    str=Pds::Matrix::ArrayToString(array,A.Nlin(),A.Ncol());
    std::cout<<str;
    
    Pds::Matrix::ReleaseArray(array,A.Nlin());
    std::cout<<std::endl<<"array="<<array<<std::endl<<std::endl;
    
    
    array=Pds::Matrix::AllocateArray(A,sin);
    if(array==NULL)   return 0;
    
    str=Pds::Matrix::ArrayToString(array,A.Nlin(),A.Ncol());
    std::cout<<str;
    
    Pds::Matrix::ReleaseArray(array,A.Nlin());
    std::cout<<std::endl<<"array="<<array<<std::endl<<std::endl;
    
    
    Pds::Matrix::LoadArray(filepath,array,Nlin,Ncol);
    str=Pds::Matrix::ArrayToString(array,Nlin,Ncol);
    std::cout<<str;
    
    return 0;
}