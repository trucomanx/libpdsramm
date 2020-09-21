#include <string>
#include <iostream>
#include <Pds/Array>
#include <Pds/RaBmp>
#include <iostream>
#include <cmath>
#include <cstring>

// Instantiate Pds::Array for the supported template type parameters
template class Pds::Array<double>;
template class Pds::Array<unsigned char>;
template class Pds::Array<unsigned int >;


template <class Datum>
std::vector<Pds::Array<Datum>>  Pds::Array<Datum>::ImportBmpFile( const std::string &filename)
{
    // Limpiando las matrices
    std::vector<Pds::Array<Datum>> Tmp(0);
    
    // Abriendo archivos
    FILE* f = fopen(filename.c_str(), "rb");
    if(f==NULL) 
    {return Tmp;}
    
    // extract image height and width from header
    Pds::Ra::BmpHeader Header=Pds::Ra::ReadBmpHeader(f);

    // Verificando tipo de bmp soportado
    if((Header.type[0]!='B')||(Header.type[1]!='M'))
    {
        std::cout<<"THIS IS NOT A BMP FILE!\n";
        return Tmp;
    }
    if(Header.compression!=0)
    {
        std::cout<<"BMP FILE WAS NOT READ!\nOnly can be read bmp files without compression!!\n";
        return Tmp;
    }
    if(Header.num_planes!=1)
    {
        std::cout<<"BMP FILE WAS NOT READ!\nOnly can be read bmp files with 1 plane!!\n";
        return Tmp;
    }
    if(!((Header.bits_per_pixel==8)||(Header.bits_per_pixel==16)||(Header.bits_per_pixel==24)||(Header.bits_per_pixel==32)))
    {
        std::cout<<"BMP FILE WAS NOT READ!\nOnly can be read bmp files without 8,16,24 or 32 bits per pixel!!\n";
        return Tmp;
    }

   
    // Cargando datos en data
    unsigned int bytes_by_pixel=Header.bits_per_pixel/8;

    unsigned int row_size  = 4*ceil((Header.bits_per_pixel*Header.width_px)/32.0); // padding of row
    unsigned int line_size = bytes_by_pixel*Header.width_px; 
    unsigned int size =  bytes_by_pixel*Header.width_px* abs(Header.height_px);

    unsigned char* data = new unsigned char[size]; // allocate 3 bytes per pixel
    unsigned char* rowdata = new unsigned char[row_size]; // allocate 3 bytes per pixel
    
    fseek(f, Header.offset, SEEK_SET);
    for(unsigned int j=0; j < abs(Header.height_px); j++)
    {
        // read row
        size_t numel=fread(rowdata, sizeof(unsigned char), row_size, f); 
        if(numel!=row_size) {delete[] data;delete[] rowdata; return Tmp;}

        memcpy(&data[j*line_size],rowdata, line_size);
    }

    delete[] rowdata;
    fclose(f);
    
    // Copiando los datos dentro de las matrices de colores
    std::vector<Pds::Array<Datum>> Block(bytes_by_pixel);

    for(unsigned int j=0; j < bytes_by_pixel; j++)
    Block[j]=Pds::Array<Datum>(Header.height_px,Header.width_px);

    for(unsigned int lin=0; lin < (unsigned int)Header.height_px; lin++)
    for(unsigned int col=0; col < (unsigned int)Header.width_px; col++)
    for(unsigned int j=0; j < bytes_by_pixel; j++)
    Block[bytes_by_pixel-1-j].At(lin,col)=(Datum)data[(col+(Header.height_px-1-lin)*Header.width_px)*bytes_by_pixel+j];
    
    delete[] data;
    return Block;
}

////////////////////////////////////////////////////////////////////////////////
template <class Datum>
Pds::Array<Datum>  Pds::Array<Datum>::MeanBlock( const std::vector<Pds::Array<Datum>> &Block)
{
    unsigned int N=Block.size();
    
    if(N==0) return Pds::Array<Datum>();
    
    for(unsigned int n=1;n<N;n++)   
    if(Block[0].IsNotSimilarTo(Block[n]))   return Pds::Array<Datum>();
        
    unsigned int Nlin=Block[0].Nlin();
    unsigned int Ncol=Block[0].Ncol();
    unsigned int lin,col,n;
    double S;
    
    Pds::Array<Datum> Gray(Nlin,Ncol);

    for(lin=0;lin<Nlin;lin++)
    for(col=0;col<Ncol;col++)
    {
        S=0;
        for(n=0;n<N;n++)    
        S+=Block[n].array[lin][col];
        
        Gray.array[lin][col]=(S/N);
    }
    return Gray;
}

