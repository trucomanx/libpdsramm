#include <Pds/Matrix>
//#include <Pds/RealArraysTools>

Pds::Matrix Pds::Matrix::Load(const char* filepath)
{
    Pds::Matrix A;
    Pds::Matrix::LoadArray(filepath,A.array,A.nlin,A.ncol);
    return A;
}


bool Pds::Matrix::Save(const char* filepath,const Pds::Matrix &A)
{
    return Pds::Matrix::SaveArray(filepath,A.array,A.nlin,A.ncol);
}
