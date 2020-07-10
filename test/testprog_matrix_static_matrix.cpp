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
    
    Pds::Matrix A=Pds::Ones(3); 
    Pds::Matrix B=2*Pds::Ones(3); 
    Pds::Matrix C(3,3); 
    C.FillId();
    C.Print("C:\n");
    
    bool state=A.Save(filepath);
    if(state==true) A.Print("A:\n");
    
    Pds::Matrix D;
    D.Load(filepath);
    D.Print("D:\n");
    
    std::vector<Pds::Matrix> Block(3);
    Block[0]=A; Block[1]=B; Block[2]=C;
    Pds::Matrix::GetSamples(Block).Print("Pds::Matrix::GetSamples(Block)\n");
    Pds::Matrix::GetSamples(Block,{1,5,3}).Print("Pds::Matrix::GetSamples(Block,{1,5,3})\n");
    
    Pds::Matrix E=Pds::Matrix::FromString("1 2 3\n 4 5 6\n\n");
    E.Print("E:\n");
    
    return 0;
}
