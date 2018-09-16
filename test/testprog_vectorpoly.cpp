/** \example testprog_vectorpoly.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
    
#include <Pds/Ra>
    
int main(void)
{
    
    Pds::Vector X=5.0*Pds::RandU(1000,1);
    Pds::Vector Y=X+Pds::RandN(X.Size());
    X.Size().Print("X.Size(): ");
    Y.Size().Print("Y.Size(): ");
    
    Pds::Vector P=Pds::PolyFit(X,Y,1);
    P.Print("P:\n");
    
    Pds::Vector Xa=Pds::LinSpace(0,5,6);
    Xa.Print("Xa:\n");
    Pds::Vector Ya=Pds::PolyVal(P,Xa);
    Ya.Print("P(Xa):\n");
    
    
    Pds::Matrix M=Pds::PolyMat(X,1);
    
    Pds::Vector Q=M.PInv()*Y;
    Q.Print("Q:\n");

    Q.Fill(1.0);
    Q.Print("Q:\n");
    
    Pds::Vector R(3);
    R.Fill(1.0);
    R.Print("R:\n");
    Pds::PolyDer(R,4).Print("D R:\n");
    
    Pds::PolyMul(R,Q).Print("R(x)*Q(x):\n");
    Pds::PolyAdd(R,Q).Print("R(x)+Q(x):\n");
    
    return 0;
}
