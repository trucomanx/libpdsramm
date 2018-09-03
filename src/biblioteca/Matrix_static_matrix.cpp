#include <Pds/Matrix>
//#include <Pds/RATools>

Pds::Matrix Pds::Matrix::RandU(unsigned int Nlin,unsigned int Ncol)
{
    Pds::Matrix A(Nlin,Ncol);
    A.FillRandU();
    return A;
}

Pds::Matrix Pds::Matrix::Load(const char* filepath)
{
    Pds::Matrix A;
    Pds::Matrix::ArrayLoad(filepath,A.array,A.nlin,A.ncol);
    return A;
}


bool Pds::Matrix::Save(const char* filepath,const Pds::Matrix &A)
{
    return Pds::Matrix::ArraySave(filepath,A.array,A.nlin,A.ncol);
}
