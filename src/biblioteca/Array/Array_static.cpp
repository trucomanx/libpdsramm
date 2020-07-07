#include <string>
#include <iostream>
#include <Pds/Array>
#include <Pds/RaBmp>
#include <iostream>
#include <cmath>

// Instantiate Pds::Array for the supported template type parameters
template class Pds::Array<double>;
template class Pds::Array<unsigned char>;
template class Pds::Array<unsigned int >;


template <class Datum>
std::vector<Pds::Array<Datum>>  Pds::Array<Datum>::ImportBmpFile( const char* filename)
{
    // Limpiando las matrices
    std::vector<Pds::Array<Datum>> Tmp(0);
    
    // Abriendo archivos
    FILE* f = fopen(filename, "rb");
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
        std::cout<<"BMP FILE WAS NOT READ!\nOnly can be read bmp files without with 1 plane!!\n";
        return Tmp;
    }
    if(!((Header.bits_per_pixel==8)||(Header.bits_per_pixel==16)||(Header.bits_per_pixel==24)||(Header.bits_per_pixel==32)))
    {
        std::cout<<"BMP FILE WAS NOT READ!\nOnly can be read bmp files without 8,16,24 or 32 bits per pixel!!\n";
        return Tmp;
    }

   
    // Cargando datos en data
    unsigned int bytes_by_pixel=Header.bits_per_pixel/8;
    unsigned int row_size_bytes= 4*ceil((Header.bits_per_pixel*Header.width_px)/32.0); // pading of row
    unsigned int size =  bytes_by_pixel*Header.width_px* abs(Header.height_px);

    unsigned char* data = new unsigned char[size]; // allocate 3 bytes per pixel
    unsigned char* rowdata = new unsigned char[row_size_bytes]; // allocate 3 bytes per pixel
    
    fseek(f, Header.offset, SEEK_SET);
    size_t numel=fread(data, sizeof(unsigned char), size, f); // read the rest of the data at once
    if(numel!=size) {delete[] data; return Tmp;}

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
    
    free(data);
    return Block;
}
