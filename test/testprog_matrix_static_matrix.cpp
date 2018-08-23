/** \example testprog_matrix_static_matrix.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <Pds/RealArrays>
        
int main(void)
{
    char filepath[]="filedat.txt";
    
    Pds::Matrix A=Pds::Ones(5); 
    
    bool state=Pds::Matrix::Save(filepath,A);
    if(state==true) A.Print("A:\n");
    
    Pds::Matrix B=Pds::Matrix::Load(filepath);
    B.Print("B:\n");
    
    Pds::Matrix C("filedat.txt");
    C.Print("C:\n");
    
    return 0;
}
