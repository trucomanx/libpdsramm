/** \example testprog_matrix_operators.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  s
 */
    
#include <iostream>
#include <Pds/RealArrays>
    
int main(void)
{
    Pds::Matrix A(2,2);
    Pds::Matrix B(2,2);
    Pds::Matrix C;
    
    A.Fill(1.0);    std::cout<<"A:\n"<<A;
    B.Fill(2.0);    std::cout<<"B:\n"<<B;
    
    // = operator
    std::cout<<std::endl;
    
    C= Pds::Matrix(2,2);    // A Matrix object was created, the data were copied
                            // and later the Matrix object was destroyed.
    
    if((C=A).IsNotVoid())   C.Print("C=A\n");
    if(C.Copy(B))           C.Print("C=B\n");
    
    // += operator
    std::cout<<std::endl;
    
    if((C+=A).IsNotVoid())  C.Print("C+=A\n");
    if(C.AddAssig(B))       C.Print("C+=B\n");
    
    
    // Inv operator
    std::cout<<std::endl;
    
    C.FillRandU();
    C.Print("C\n");
    double rcond;
    Pds::Matrix D=C.Inv(&rcond);

    (C*D).Print("\nC*D=\n");
    
    return 0;
}
