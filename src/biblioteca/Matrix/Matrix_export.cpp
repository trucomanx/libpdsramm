#include <Pds/Matrix>
#include <Pds/Array>
#include <Pds/RaDefines>
#include <Pds/RaTools>

////////////////////////////////////////////////////////////////////////



bool Pds::Matrix::Save(const char* filepath) const
{
    return Pds::Array<double>::ArraySave(filepath,this->array,this->nlin,this->ncol);
}

bool Pds::Matrix::Load(const char* filepath)
{
    double **array=NULL;
    unsigned int Nlin,Ncol;
    this->MakeEmpty();

    array=Pds::Array<double>::ArrayLoad(filepath,Nlin,Ncol);
    if(array==NULL) return false;
    this->array=array;
    this->nlin=Nlin;
    this->ncol=Ncol;
    return true;
}
////////////////////////////////////////////////////////////////////////////////

bool Pds::Matrix::ExportCsvFile(const char* filepath,char delimitador) const
{
    return Pds::Array<double>::ArrayWriteCsvFile(filepath,this->array,this->nlin,this->ncol,delimitador);
}

////////////////////////////////////////////////////////////////////////////////
bool Pds::Matrix::ExportMatFile(const char* pname,const char* filepath) const
{
    if(this->IsEmpty()) return false;
    if(filepath==NULL)  return false;
    if(pname==NULL)     return false;
    
    FILE *fd=fopen(filepath,"wb");
    if(fd==NULL)    return false;
    
    bool ret=Pds::Array<double>::ArrayWriteMatFile(fd,pname,this->array,this->nlin,this->ncol);
    fclose(fd);
    
    return ret;
}

////////////////////////////////////////////////////////////////////////////////

bool Pds::Matrix::ExportBmpFile(const unsigned char colormap[256][3],const std::string &filepath) const
{
    if(filepath.size()==0)  return false;

    if(this->IsEmpty()) return false;
    if(colormap==NULL)  return false;
    
    bool ret=Pds::Array<double>::ArrayWriteBmpWithColormap(this->array,this->nlin,this->ncol,colormap,filepath.c_str());
    return ret;
}

