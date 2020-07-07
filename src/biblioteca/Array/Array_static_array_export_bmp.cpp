#include <string>
#include <iostream>
#include <Pds/Array>
#include <Pds/RaBmp>

// Instantiate Pds::Array for the supported template type parameters
template class Pds::Array<double>;
template class Pds::Array<unsigned char>;
template class Pds::Array<unsigned int >;


/** 
 *  \brief Escribe los datos de una matriz en un archivo de en formato BMP.
 *  \param[in] R Matriz donde se leerán los datos de color rojo. 0<= r<= 255
 *  \param[in] G Matriz donde se leerán los datos de color verde. 0<= g<= 255
 *  \param[in] B Matriz donde se leerán los datos de color azul. 0<= b<= 255
 *  \param[in] bmpfilename Nombre del archivo donde se escribirán los datos 
 *  de la matriz.
 *  \return true si todo fue bien o false si no. (ej. R,G,B,bmpfilename==NULL)
 *  \ingroup ArrayGroup
 */
template <class Datum>
bool Pds::Array<Datum>::ArrayWriteBmp(  Datum **arrayr,
                                        Datum **arrayg,
                                        Datum **arrayb,
                                        unsigned int Nlin,
                                        unsigned int Ncol,
                                        const std::string &bmpfilename)
{
    FILE *bmpfd=NULL;

    unsigned char *img = NULL;
    double r,g,b;

    if(arrayr==NULL)        return false;
    if(arrayg==NULL)        return false;
    if(arrayb==NULL)        return false;
    if(bmpfilename.size()==0)   return false;

    int x,y,i,j;
    int WIDTH  = Ncol;
    int HEIGHT = Nlin;
    int FILESIZE = 54 + 3*WIDTH*HEIGHT; 



    img = (unsigned char *)calloc(3*WIDTH*HEIGHT,sizeof(unsigned char));
    if(img==NULL)   return false;

    for(j=0; j<HEIGHT; j++)
    for(i=0; i<WIDTH ; i++)
    {
        x=i; 
        y=j;

        r = (double)arrayr[j][i];    if (r > 255) r=255;   if (r < 0) r=0;
        g = (double)arrayg[j][i];    if (g > 255) g=255;   if (g < 0) g=0;
        b = (double)arrayb[j][i];    if (b > 255) b=255;   if (b < 0) b=0;
        
        img[(x+(HEIGHT-1-y)*WIDTH)*3+2] = (unsigned char)(r);
        img[(x+(HEIGHT-1-y)*WIDTH)*3+1] = (unsigned char)(g);
        img[(x+(HEIGHT-1-y)*WIDTH)*3+0] = (unsigned char)(b);
    }

    ///////////////////////////////// Cabecera //////////////////////////////////
    // [ 2, 6> tamaño total del archivo (calculalo luego)
    // [ 6,10> puros cero
    // [10,14> Tamanho total de la cabecera
    unsigned char bmpfileheader[14] = {'B','M',   0,0,0,0,  0,0,0,0,  54,0,0,0};

    bmpfileheader[ 2] = (unsigned char)(FILESIZE    );
    bmpfileheader[ 3] = (unsigned char)(FILESIZE>> 8);
    bmpfileheader[ 4] = (unsigned char)(FILESIZE>>16);
    bmpfileheader[ 5] = (unsigned char)(FILESIZE>>24);

    /////////////////////////// Cabecera informativa ////////////////////////////
    // [ 0, 4> Tamanho total de informacion de la cabecera
    // [ 4, 8> Ancho en pixels de la imagen
    // [ 8,12> Alto en pixels de la imagen
    unsigned char bmpinfoheader[40] = {40,0,0,0,  0,0,0,0,  0,0,0,0,  1,0, 24,0};

    bmpinfoheader[ 4] = (unsigned char)(WIDTH    );
    bmpinfoheader[ 5] = (unsigned char)(WIDTH>> 8);
    bmpinfoheader[ 6] = (unsigned char)(WIDTH>>16);
    bmpinfoheader[ 7] = (unsigned char)(WIDTH>>24);

    bmpinfoheader[ 8] = (unsigned char)(HEIGHT    );
    bmpinfoheader[ 9] = (unsigned char)(HEIGHT>> 8);
    bmpinfoheader[10] = (unsigned char)(HEIGHT>>16);
    bmpinfoheader[11] = (unsigned char)(HEIGHT>>24);

    unsigned char bmppad[3] = {0,0,0};

    bmpfd = fopen(bmpfilename.c_str(),"wb");
    if(bmpfd==NULL)
    {
        free(img);
        return false;
    }
    fwrite(bmpfileheader,1,14,bmpfd);
    fwrite(bmpinfoheader,1,40,bmpfd);
    for(i=0; i<HEIGHT; i++)
    {
        fwrite(img+(WIDTH*i*3),3,WIDTH            ,bmpfd);
        fwrite(bmppad         ,1,(4-(WIDTH*3)%4)%4,bmpfd);
    }
    fclose(bmpfd);
    return true;
}


template <class Datum>
bool Pds::Array<Datum>::ArrayWriteBmpWithColormap(Datum **array,
                                            unsigned int Nlin,
                                            unsigned int Ncol,
                                            const unsigned char colormap[256][3],
                                            const std::string &bmpfilename)
{
    FILE * bmpfd=NULL;

    unsigned char *img = NULL;
    unsigned char UCHAR;

    int i;
    unsigned int lin,col;

    if(array==NULL)         return false;
    if(bmpfilename.size()==0)   return false;
    
    int WIDTH  = Ncol;
    int HEIGHT = Nlin;

    int FILESIZE=54+(int)WIDTH*HEIGHT+1024;
    
    img = (unsigned char *)calloc(WIDTH*HEIGHT,sizeof(unsigned char));
    if(img==NULL)   return false;

    for(lin=0; lin<(unsigned int)HEIGHT; lin++)
    for(col=0; col<(unsigned int)WIDTH ; col++)
    {

        if      ((unsigned char)array[lin][col] > 255)  UCHAR = 255;
        else if ((unsigned char)array[lin][col] <   0)  UCHAR = 0;
        else                                            UCHAR = (unsigned char)array[lin][col];
        
        //img[col+lin*WIDTH] = UCHAR;
        img[col+(HEIGHT-1-lin)*WIDTH] = UCHAR;
    }

    ///////////////////////////////// Paleta ///////////////////////////////////
    unsigned char paleta[1024];
    for(i=0;i<256;i++)
    {
        paleta[i*4+0]=colormap[i][2];
        paleta[i*4+1]=colormap[i][1];
        paleta[i*4+2]=colormap[i][0];
        paleta[i*4+3]=0;
    }
    ////////////////////////////////////////////////////////////////////////////


    ///////////////////////////////// Cabecera //////////////////////////////////
    // [ 2, 6> tamaño total del archivo (calculalo luego)
    // [ 6,10> puros cero
    // [10,14> Tamanho total de la cabecera (1024+54)
    unsigned char bmpfileheader[14] = {'B','M',  0,0,0,0,  0,0,0,0,  54,4,0,0};
   
    bmpfileheader[ 2] = (unsigned char)(FILESIZE    );
    bmpfileheader[ 3] = (unsigned char)(FILESIZE>> 8);
    bmpfileheader[ 4] = (unsigned char)(FILESIZE>>16);
    bmpfileheader[ 5] = (unsigned char)(FILESIZE>>24);
    ////////////////////////////////////////////////////////////////////////////


    /////////////////////////// Cabecera informativa ////////////////////////////
    // [ 0, 4> Tamanho total de informacion de la cabecera
    // [ 4, 8> Ancho en pixels de la imagen
    // [ 8,12> Alto en pixels de la imagen
    // [12,14> Numero de Planos ¿?
    // [14,16> Numero de bits por pixel (1, 4, 8, 16, 24 o 32.)
    // [16,20> Sin compresion
    unsigned char bmpinfoheader[40] = {40,0,0,0,    0,0,0,0,    0,0,0,0,    1,0,    8,0,    0,0,0,0};
    // [32,36> 0100h=256 numero de colores
    // [36,40> 0100h=256 numero de colores
    
    bmpinfoheader[ 4] = (unsigned char)(WIDTH    );
    bmpinfoheader[ 5] = (unsigned char)(WIDTH>> 8);
    bmpinfoheader[ 6] = (unsigned char)(WIDTH>>16);
    bmpinfoheader[ 7] = (unsigned char)(WIDTH>>24);

    bmpinfoheader[ 8] = (unsigned char)(HEIGHT    );
    bmpinfoheader[ 9] = (unsigned char)(HEIGHT>> 8);
    bmpinfoheader[10] = (unsigned char)(HEIGHT>>16);
    bmpinfoheader[11] = (unsigned char)(HEIGHT>>24);

    bmpinfoheader[32] = (unsigned char)(0);
    bmpinfoheader[33] = (unsigned char)(1);

    bmpinfoheader[36] = (unsigned char)(0);
    bmpinfoheader[37] = (unsigned char)(1);
    ////////////////////////////////////////////////////////////////////////////

    unsigned char bmppad[3] = {0,0,0};

    bmpfd = fopen(bmpfilename.c_str(), "wb");
    if (bmpfd == NULL) 
    {
        free(img);
        return false;
    }
    
    fwrite(bmpfileheader, 1,  14, bmpfd);
    fwrite(bmpinfoheader, 1,  40, bmpfd);
    fwrite(paleta       , 1,1024, bmpfd);


    for(i=0;i<HEIGHT;i++)
    {
        fwrite(img+(WIDTH*i),1,WIDTH          ,bmpfd);
        fwrite(bmppad       ,1,(4-(WIDTH%4))%4,bmpfd);
    }

    fclose(bmpfd);

    return true;
}

