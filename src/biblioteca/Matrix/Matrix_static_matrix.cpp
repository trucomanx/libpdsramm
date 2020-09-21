#include <Pds/Matrix>
#include <Pds/RaBmp>

Pds::Matrix Pds::Matrix::GetSamples(const std::vector<Pds::Matrix> &Block)
{
    if(Block.size()==0)     return Pds::Matrix(); 
    if(Block[0].IsEmpty())  return Pds::Matrix();
    for(unsigned int i=1;i<Block.size();i++)
    if(Block[0].IsNotSimilarTo(Block[i]))
    return Pds::Matrix();

    unsigned int L=Block[0].Nel();
    unsigned int l=0;
    unsigned int Nlin=Block[0].nlin;
    unsigned int Ncol=Block[0].ncol;
    unsigned int N=Block.size();
    Pds::Matrix A(L,N);
    

    for(unsigned int col=0;col<Ncol;col++)
    for(unsigned int lin=0;lin<Nlin;lin++)
    {
        for(unsigned int n=0;n<N;n++)
        A.array[l][n]=Block[n].array[lin][col];
     
        l++;
    }

    return A;
}

Pds::Matrix Pds::Matrix::GetSamples(const std::vector<Pds::Matrix> &Block,const std::vector<unsigned int> Id)
{
    if(Block.size()==0)     return Pds::Matrix(); 
    if(Block[0].IsEmpty())  return Pds::Matrix();
    for(unsigned int i=1;i<Block.size();i++)
    if(Block[0].IsNotSimilarTo(Block[i]))
    return Pds::Matrix();

    unsigned int L=Id.size();
    unsigned int N=Block.size();
    Pds::Matrix A(L,N);
    for(unsigned int l=0;l<L;l++)
    for(unsigned int n=0;n<N;n++)
    A.array[l][n]=Block[n].Get(Id[l]);

    return A;
}
////////////////////////////////////////////////////////////////////////////////
Pds::Matrix Pds::Matrix::FromString(const std::string &str)
{
    Pds::Matrix A;
    unsigned int Nlin;
    unsigned int Ncol;
    static double **array=Pds::Array<double>::ArrayFromString(str,Nlin,Ncol);
    if(array==NULL) return A;
    
    A.array=array;
    A.ncol=Ncol;
    A.nlin=Nlin;
    
    return A;
}

////////////////////////////////////////////////////////////////////////////////

bool Pds::Matrix::ExportBmpFile(const Pds::Matrix &R,const Pds::Matrix &G,const Pds::Matrix &B,const std::string &bmpfilename)
{
    if(R.IsEmpty())         return false;
    if(R.IsNotSimilarTo(G)) return false;
    if(R.IsNotSimilarTo(B)) return false;
    if(bmpfilename.size()==0)   return false;

    
    bool ret=Pds::Array<double>::ArrayWriteBmp(R.array,G.array,B.array,R.nlin,R.ncol,bmpfilename);
    
    return ret;
}

////////////////////////////////////////////////////////////////////////////////

std::vector<Pds::Matrix>  Pds::Matrix::ImportBmpFile( const std::string &filename)
{
    std::vector<Pds::Array<unsigned char>> Block;
    std::vector<Pds::Matrix> Tmp(0);

    
    Block=Pds::Array<unsigned char>::ImportBmpFile(filename.c_str());
    if(Block.size()==0) return Tmp;

    std::vector<Pds::Matrix> Out(Block.size());
    
    for(unsigned int i=0;i<Block.size();i++)
    Out[i].Copy(Block[i]);

    return Out;
}
/*
std::vector<Pds::Matrix>  Pds::Matrix::ImportBmpFile( const char* filename)
{
    // Limpiando las matrices
    std::vector<Pds::Matrix> Tmp;
    
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
    unsigned int N=Header.width_px * Header.height_px;
    unsigned int size = bytes_by_pixel * N;
    unsigned char* data = new unsigned char[size]; // allocate 3 bytes per pixel
    
    fseek(f, Header.offset, SEEK_SET);
    size_t numel=fread(data, sizeof(unsigned char), size, f); // read the rest of the data at once
    if(numel!=size) {free(data); return Tmp;}
    fclose(f);
    
    // Copiando los datos dentro de las matrices de colores
    std::vector<Pds::Matrix> Block(bytes_by_pixel);

    for(unsigned int j=0; j < bytes_by_pixel; j++)
    Block[j]=Pds::Matrix(Header.height_px,Header.width_px);

    for(unsigned int lin=0; lin < (unsigned int)Header.height_px; lin++)
    for(unsigned int col=0; col < (unsigned int)Header.width_px; col++)
    for(unsigned int j=0; j < bytes_by_pixel; j++)
    Block[j].At(lin,col)=(double)data[(col+(Header.height_px-1-lin)*Header.width_px)*bytes_by_pixel+j];
    
    free(data);
    return Block;
}
*/


////////////////////////////////////////////////////////////////////////////////

Pds::Matrix  Pds::Matrix::MeanBlock( const std::vector<Pds::Matrix> &Block)
{
    unsigned int N=Block.size();
    
    if(N==0) return Pds::Matrix();
    
    for(unsigned int n=1;n<N;n++)   
    if(Block[0].IsNotSimilarTo(Block[n]))   return Pds::Matrix();
        
    unsigned int Nlin=Block[0].Nlin();
    unsigned int Ncol=Block[0].Ncol();
    unsigned int lin,col,n;
    double S;
    
    Pds::Matrix Gray(Nlin,Ncol);

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

