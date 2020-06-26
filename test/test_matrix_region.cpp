/** \file test_matrix_region.cpp 
 *  \brief Programa para el testeo de las funciones.
 *
    
Para compilar o código test_matrix_region.cpp:
\code{.sh}
g++ -static -o example_matrix_create test_matrix_region.cpp -lpdsramm 
\endcode
Para executar o programa:
\code{.sh}
    ./example_matrix_create
\endcode  
Retornando por consola:
\verbatim
    
\endverbatim
 *
 * Código test_matrix_region.cpp:
 */
    
#include <Pds/Ra>
#include <cstdio>
    
int main(void)
{
    unsigned int L,N=7;
    Pds::Matrix Mat1=Pds::Round(9*Pds::RandU(N,N));
    Pds::Matrix Mat2(N,N);

    Pds::RegionRect R;    
    Pds::RegionRect R1(3,3,2,2);
    Pds::RegionRect R2(5,5,2,2);
    R1.Print("R1:\n");
    R2.Print("R2:\n");

    Mat1.Print("Mat1:\n");
    
    Mat1.CopyRegion(R1,R2,Mat2);
    Mat2.Print("Mat1.CopyRegion(R1,R2,Mat2):\n");
    
    Mat2.InitRegion(R1,-1);
    Mat2.Print("Mat2.InitRegion(R1,-1);:\n");

    R=Mat1.GetRegion();
    if(R.IsEmpty()) std::cout<<"R is empty\n";
    else            R.Print("R=Mat1.GetRegion():\n");
    
    double mean,std;
    
    Mat1.Print("Mat1:\n");
    Mat1.MeanOfRegion(R1,&mean);

    R1.Print("R1:\n");
    std::cout<<"Mat1.MeanOfRegion(R1,&mean):\t"<<mean<<std::endl;
    std::cout<<"Mat1.MeanOfRegion(R1):\t"<<Mat1.MeanOfRegion(R1)<<std::endl;
    
    Mat1.StdAndMeanOfRegion(R1,&std,&mean);
    std::cout<<"Mat1.StdAndMeanOfRegion(R1,&std,&mean):\t"<<std<<"\t"<<mean<<std::endl;
    
    /*
    Pds::RegionRect Rout;
    N=1000;
    L=64;
    Mat1=Pds::Round(9*Pds::RandU(N,N));
    Mat2=Pds::Round(9*Pds::RandU(N,N));
    R1=Pds::RegionRect(2,2,L,L);
    R2=Pds::RegionRect(N/2,N/2,L,L);
    Mat1.CopyRegion(R1,R2,Mat2);
    Pds::Ra::Tic();
    Rout=Mat1.FindRegion(Mat2,R1,0.6,1);
    Pds::Ra::Toc();
    Rout.Print("Rout:\n");
    */    
    return 0;
}
