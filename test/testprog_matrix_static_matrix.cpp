/** \example testprog_matrix_static_matrix.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <Pds/Ra>
        
int main(void)
{
    char filepath[]="filedat.txt";
    
    Pds::Matrix A=Pds::Ones(5); 
    
    bool state=A.Save(filepath);
    if(state==true) A.Print("A:\n");
    
    Pds::Matrix B;
    B.Load(filepath);
    B.Print("B:\n");
    
    
    Pds::Matrix D=Pds::Matrix::FromString("1 2 3\n 4 5 6\n\n");
    D.Print("D:\n");
    
    return 0;
}
