/** \file test_funcarraylabeling.cpp
 *  \brief Programa para el testeo de las funciones.
    
Para compilar o código test_funcarraylabeling.cpp:
\code{.sh}
g++ -static -o test_funcarraylabeling test_funcarraylabeling.cpp -lpdsramm 
\endcode
Para executar o programa:
\code{.sh}
    ./test_funcarraylabeling
\endcode  
Retornando por consola:
\verbatim
    
\endverbatim
 *
 * Código test_funcarraylabeling.cpp:
 */
    
#include <Pds/Ra>
    

int main(void)
{
    Pds::Ra::Randomize();
    
    unsigned int L=512;
    Pds::Array<unsigned char> A(L,L);
    
    Pds::Image::DataSet::LoadDataCircles(A,3,1);
    //A.FillRandC(0.6); A.Print("A:\n");

    Pds::Matrix(A).Scale(0,255).ExportBmpFile(Pds::Colormap::Gray,"A-binary.bmp");


    Pds::Array<unsigned int> ID;
    
    Pds::Ra::Tic();
    ID=Pds::Image::IdMapUsingCC4(A);
    Pds::Ra::Toc();
    //ID.Print("ID:\n");

    Pds::Matrix(ID).Scale(0,255).ExportBmpFile(Pds::Colormap::Steps,"A-ID.bmp");
   
    std::vector<std::vector<Pds::Position>> Data;
    Pds::Ra::Tic();
    Data=Pds::Image::VectorGroupFromIdMap(ID);
    Pds::Ra::Toc();

    for(unsigned int i=0;i<Data.size();i++)
    {
        double  Per=Pds::Image::PerimeterOfConvexGroup(Data[i]);
        unsigned int Area=Data[i].size();
        
        std::cout<<"Perimeter["<<i<<"]:\t"<<Per<<"\t";
        std::cout<<"     Area["<<i<<"]:\t"<<Area<<"\t";
        std::cout<<"    Gamma["<<i<<"]:\t"<<(Per/2.0)/sqrt(Area*Pds::Ra::Pi)<<"\n";
    }
    return 0;
}

/*

*/
