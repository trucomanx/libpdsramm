/** \example testprog_matrixmath.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <Pds/Ra>
    
int main(void)
{
    Pds::Matrix A(2);
    
    A.Fill(45.0*Pds::Ra::ToRadians);
    
    A.Print("\nA:\n");
    
    Pds::Sin(A).Print("sin(A):\n");
    Pds::Cos(A).Print("cos(A):\n");
    Pds::Tan(A).Print("tan(A):\n");
    
    A.Fill(1.0);
    A.Print("\nA:\n");
    
    Pds::Exp(A).Print("exp(A):\n");
    Pds::TwoExp(A).Print("TwoExp(A):\n");
    Pds::Ln(A).Print("ln(A):\n");
    Pds::Log2(A).Print("log2A):\n");
    Pds::Log10(A).Print("log10(A):\n");
    
    A.Fill(2.0);
    A.Print("\nA:\n");
    
    Pds::Sqrt(A).Print("sqrt(A):\n");

    A=Pds::LinSpace(-2,2,5).T();
    A.Print("\nA:\n");

    Pds::SQNL(A).Print("sqnl(A):\n");    
    Pds::Gaussian(A).Print("gaussian(A):\n");    
    Pds::Tanh(A).Print("tanh(A):\n");
    Pds::Sigmoid(A).Print("sigmoid(A):\n");

    Pds::Logit(Pds::Sigmoid(A)).Print("logit(sigmoid(A)):\n");
    Pds::Sinc(A).Print("sinc(A):\n");
    
    A.FillRandU();
    A.Print("\nA:\n");
    
    Pds::Hb(A).Print("Hb(A):\n");
    
    return 0;
}
