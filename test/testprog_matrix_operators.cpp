/** \example testprog_matrix_operators.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  s
 */
    
#include <iostream>
#include <Pds/Ra>
    
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
    
    if((C=A).IsNotEmpty())  C.Print("C=A\n");
    if(C.Copy(B))           C.Print("C=B\n");
    
    // += operator
    std::cout<<std::endl;
    
    if((C+=A).IsNotEmpty()) C.Print("C+=A\n");
    if(C.AddAssig(B))       C.Print("C+=B\n");
    
    if((C+=0.2).IsNotEmpty()) C.Print("C+=0.2\n");
    if(C.AddAssig(0.8))       C.Print("C+=0.8\n");
    
    // -= operator
    std::cout<<std::endl;
    
    if((C-=A).IsNotEmpty()) C.Print("C-=A\n");
    if(C.SubAssig(B))       C.Print("C-=B\n");
    
    if((C-=0.3).IsNotEmpty()) C.Print("C-=0.3\n");
    if(C.SubAssig(0.7))       C.Print("C-=0.7\n");
    
    // *= operator
    std::cout<<std::endl;
    
    if((C*=0.2).IsNotEmpty()) C.Print("C*=0.2\n");
    if(C.MulAssig(5.0))       C.Print("C*=5.0\n");
    
    if((C*=A).IsNotEmpty()) C.Print("C*=A\n");
    if(C.MulAssig(A))       C.Print("C*=A\n");
    
    // Inv operator
    std::cout<<std::endl;
    
    C=Pds::Matrix::FromString("117 822.2940998481383\n 822.2940998481383 5783.818979511911");
    C.Print("C\n");
    double rcond;
    Pds::Matrix D=C.Inv(&rcond);
    D.Print("D=C.Inv(&rcond)\n");

    (C*D).Print("\nC*D=\n");

    D.Fill(1.0);
    D.Print("\nD.Fill(1.0)\n");
    
    Pds::Matrix F=D.PInv(&rcond);
    F.Print("\nF:\n");   
    std::cout<<"rcond: "<<rcond<<std::endl;
    
    return 0;
}
