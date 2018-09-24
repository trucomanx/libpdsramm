/** \example testprog_matrix_static_array.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
    
#include <iostream>
#include <Pds/Ra>
#include <cmath>
    
int main(void)
{
    std::string str;
    Pds::Matrix A=Pds::Eye(3);
    
    unsigned int Nlin=2;
    unsigned int Ncol=2;
    double **array=NULL;
    
    char filepath[]="filedat.txt";
    
    
    
    array=Pds::Matrix::ArrayAllocate(Nlin,Ncol);
    if(array==NULL)   return 0; 
    
    array[0][0]=0.0/0.0;    array[0][1]=0.0/1.0;
    array[1][0]=1.0/0.0;    array[1][1]=1.0/1.0;
    std::cout<<"\n";
    
    
    Pds::Matrix::ArraySave(filepath,array,Nlin,Ncol);
    
    std::cout   <<"ArrayAllocate(Nlin,Ncol):\n"
                <<Pds::Matrix::ArrayToString(array,Nlin,Ncol);
    
    Pds::Matrix::ArrayRelease(array,Nlin);
    if(array==NULL) std::cout<<"Array released.\n\n\n";
    
    
    
    array=Pds::Matrix::ArrayAllocate(A);
    if(array==NULL)   {std::cout<<"Error Alocate.\n";return 0;}
    else              std::cout<<"New array allocated.\n";
    
    std::cout   <<"ArrayAllocate(A):\n"
                <<Pds::Matrix::ArrayToString(array,A.Nlin(),A.Ncol());
    
    Pds::Matrix::ArrayRelease(array,A.Nlin());
    if(array==NULL) std::cout<<"Array released.\n\n\n";
    
    
    
    array=Pds::Matrix::ArrayAllocate(sin,A);
    if(array==NULL)   {std::cout<<"Error Alocate.\n";return 0;}
    else              std::cout<<"New array allocated.\n";
    
    std::cout   <<"ArrayAllocate(sin,A):\n"
                <<Pds::Matrix::ArrayToString(array,A.Nlin(),A.Ncol());
    
    Pds::Matrix::ArrayRelease(array,A.Nlin());
    if(array==NULL) std::cout<<"Array released.\n\n\n";
    
    
    
    array=Pds::Matrix::ArrayLoad(filepath,Nlin,Ncol);
    if(array==NULL)   {std::cout<<"Error Alocate.\n";return 0;}
    else              std::cout<<"New array allocated.\n";
    
    std::cout   <<"ArrayLoad(filepath,Nlin,Ncol):\n"
                <<Pds::Matrix::ArrayToString(array,Nlin,Ncol);
    
    Pds::Matrix::ArrayRelease(array,Nlin);
    if(array==NULL) std::cout<<"Array released.\n\n\n";
    
    
    
    array=Pds::Matrix::ArrayFromString("1 2 3\n4 5 6\n",Nlin,Ncol);
    if(array==NULL)   {std::cout<<"Error Alocate.\n";return 0;}
    else              std::cout<<"New array allocated.\n";
    
    std::cout   <<"ArrayFromString(\"1 2 3\\n4 5 6\\n\",Nlin,Ncol):\n"
                <<Pds::Matrix::ArrayToString(array,Nlin,Ncol);
    
    Pds::Matrix::ArrayRelease(array,Nlin);
    if(array==NULL) std::cout<<"Array released.\n\n\n";
    
    
    
    array=Pds::Matrix::ArrayColFromString("1 2 3\n4 5 6\n",Nlin,Ncol);
    if(array==NULL)   {std::cout<<"Error Alocate.\n";return 0;}
    else              std::cout<<"New array allocated.\n";
    
    std::cout   <<"ArrayColFromString(\"1 2 3\\n4 5 6\\n\",Nlin,Ncol):\n"
                <<Pds::Matrix::ArrayToString(array,Nlin,Ncol);

    bool ret=Pds::Matrix::ArrayWriteMatFile("filedat.mat",NULL,array,Nlin,Ncol);
    if(ret) std::cout<<"filedat.mat saved.\n";
    else    std::cout<<"filedat.mat NOT saved.\n";
    
    return 0;
}
