/** \file test_array_region.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <cmath>
#include <Pds/Ra>
    
int main(void)
{
    Pds::Ra::Randomize();

    Pds::Array<unsigned int> A(10,10);
    Pds::RegionRect R(7,7,3,3);
    Pds::Vector H;

    A.FillRandI(0,9);
    A.Print("\nA:\n");
    R.Print("\nR:\n");
    
    H=A.HistogramNorm(R,0,9);
    H.Print("\nH:\n");
    std::cout<<"\nH.Sum():\n"<<H.Sum()<<std::endl;

    return 0;
}
