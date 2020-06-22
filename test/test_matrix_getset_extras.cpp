/** \file test_matrix_getset_extras.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <cmath>
#include <Pds/Ra>
    
int main(void)
{
    Pds::Matrix A("0 3 6\n1 4 7\n2 5 8\n3 3 1");
    
    A.Print("\nA=\n");
    
    Pds::Vector  C=A.GetColVector(1);
    C.Print("\nC=A.GetColVector(1)=\n");
    
    C.Fill(-1.0);
    A.SetColVector(2,C);
    A.Print("\nA=\n");
    
    Pds::Vector  D=A.GetDiagonal();
    D.Print("\nD=A.GetDiagonal()=\n");

    A.Print("\nA=\n");
    Pds::Matrix B=A.GetRowsRand(2);
    B.Print("\nB=A.GetRowsRand(2)\n");    
    Pds::Matrix F=A.GetRows(2,6);
    F.Print("\nF=A.GetRows(2,6)\n");    

    A.GetRow(1).Print("\nA.GetRow(1)\n");
    A.GetCol(1).T().Print("\nA.GetCol(1).T()\n");
    return 0;
}
