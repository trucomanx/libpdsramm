#include <Pds/Matrix>
//#include <Pds/RaTools>

Pds::Matrix Pds::Matrix::Apply(double (*func)(double),const Pds::Matrix &B)
{
    return Pds::Matrix(func,B);
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
