/** \example testprog_matrix_rows.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <Pds/Ra>
    
int main(void)
{
    Pds::Matrix A(3,4);
    Pds::Matrix B;
    A.Set(1.0,0,0);A.Set(1.0,0,1); A.Set(1.0,0,2);     A.Set(24.0,0,3);
    A.Set(4.0,1,0);A.Set(6.0,1,1); A.Set(10.0,1,2);    A.Set(148.0,1,3);
    A.Set(0.5,2,0);A.Set(0.25,2,1);A.Set(1.0/3.0,2,2); A.Set(9.0,2,3);
    
    B=A;
    B.RowReduction();
    
    A.Print("\nA:\n");
    B.Print("\nB:\n");
    
    
    return 0;
}
