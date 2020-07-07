#include <Pds/RaBmp>
#include <iostream>

Pds::Ra::BmpHeader Pds::Ra::ReadBmpHeader(FILE *fd)
{
    Pds::Ra::BmpHeader Header;
    unsigned char info[54];
    if (fd==NULL)   return Header;
    
    //Envio el archivo al inicio
    fseek(fd, 0, SEEK_SET);
    
    size_t numel=fread(info, sizeof(unsigned char), 54, fd); // read the 54-byte header
    if(numel!=54)    return Header;

  Header.type[0]=*(unsigned char*)&info[0];    // Magic identifier: 0x4d42 (1 byte)
  Header.type[1]=*(unsigned char*)&info[1];    // Magic identifier: 0x4d42 (1 byte)
  Header.size       =*(uint32_t*)&info[2];     // File size in bytes (4 bytes)
  Header.reserved1  =*(uint16_t*)&info[6];     // Not used (2 bytes)
  Header.reserved2  =*(uint16_t*)&info[8];     // Not used (2 bytes)
  Header.offset     =*(uint32_t*)&info[10];    // Offset to image data in bytes from beginning of file 54 bytes (4 bytes)
    // Encabezado DIB 
  Header.dib_header_size  =*(uint32_t*)&info[14];   // DIB Header size in bytes 40 bytes (4 bytes)
  Header.width_px         =*(int32_t *)&info[18];   // Width of the image (4 bytes)
  Header.height_px        =*(int32_t *)&info[22];   // Height of image (4 bytes)
  Header.num_planes       =*(uint16_t*)&info[26];   // Number of color planes (2 bytes)
  Header.bits_per_pixel   =*(uint16_t*)&info[28];   // Bits per pixel (2 bytes)
  Header.compression      =*(uint32_t*)&info[30];   // Compression type (4 bytes)
  Header.image_size_bytes =*(uint32_t*)&info[34];   // Image size in bytes (4 bytes)
  Header.x_resolution_ppm =*(int32_t *)&info[38];   // Pixels per meter (4 bytes)
  Header.y_resolution_ppm =*(int32_t *)&info[42];   // Pixels per meter (4 bytes)
  Header.num_colors       =*(uint32_t*)&info[46];   // Number of colors (4 bytes) 
  Header.important_colors =*(uint32_t*)&info[50];   // Important colors (4 bytes)

    return Header;
}

Pds::Ra::BmpHeader Pds::Ra::ReadBmpHeader(const std::string &filename)
{
    Pds::Ra::BmpHeader Header;
    FILE* fd = fopen(filename.c_str(), "rb");
    if(fd==NULL) 
    {return Header;}
    
    // extract image height and width from header
    Header=Pds::Ra::ReadBmpHeader(fd);
    fclose(fd);
    
    return Header;
}

void Pds::Ra::PrintBmpHeader(Pds::Ra::BmpHeader Header)
{
    std::cout<<"             BMP header"<<std::endl;
    std::cout<<"            type: "<<Header.type[0]<<Header.type[1]<<std::endl; // Magic identifier: 0x4d42 (1 byte)
    std::cout<<"            size: "<<Header.size<<std::endl;                    // File size in bytes (4 bytes)
    std::cout<<"       reserved1: "<<Header.reserved1<<std::endl;               // Not used (2 bytes)
    std::cout<<"       reserved2: "<<Header.reserved2<<std::endl;               // Not used (2 bytes)
    std::cout<<"          offset: "<<Header.offset<<std::endl;                  // Offset to image data in bytes from beginning of file 54 bytes (4 bytes)
    
    std::cout<<"             DIB header"<<std::endl;
    std::cout<<" dib_header_size: "<<Header.dib_header_size<<std::endl;     // DIB Header size in bytes 40 bytes (4 bytes)
    std::cout<<"        width_px: "<<Header.width_px<<std::endl;            // Width of the image (4 bytes)
    std::cout<<"       height_px: "<<Header.height_px<<std::endl;           // Height of image (4 bytes)
    std::cout<<"      num_planes: "<<Header.num_planes<<std::endl;          // Number of color planes (2 bytes)
    std::cout<<"  bits_per_pixel: "<<Header.bits_per_pixel<<std::endl;      // Bits per pixel (2 bytes)
    std::cout<<"     compression: "<<Header.compression<<std::endl;         // Compression type, 0=no comprimido (4 bytes)
    std::cout<<"image_size_bytes: "<<Header.image_size_bytes<<std::endl;    // Image size in bytes (4 bytes)
    std::cout<<"x_resolution_ppm: "<<Header.x_resolution_ppm<<std::endl;    // Pixels per meter (4 bytes)
    std::cout<<"y_resolution_ppm: "<<Header.y_resolution_ppm<<std::endl;    // Pixels per meter (4 bytes)
    std::cout<<"      num_colors: "<<Header.num_colors<<std::endl;          // Number of colors (4 bytes) 
    std::cout<<"important_colors: "<<Header.important_colors<<std::endl;    // Important colors (4 bytes)
}

