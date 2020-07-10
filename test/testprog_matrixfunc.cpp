
/** \example testprog_matrixfunc.cpp
 *  \author Fernando Pujaico Rivera
 *  \date 18-04-2018
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <Pds/Ra>
    
int main(void)
{
    Pds::Matrix A = Pds::Eye(3);
    A.Print("\nA:\n");

    Pds::Matrix B = Pds::Ones(3);
    B.Print("\nB:\n");

    Pds::Matrix C = Pds::Zeros(3);
    C.Print("\nC:\n");

    Pds::Matrix D = Pds::RandU(3);
    D.Print("\nD:\n");

    Pds::Matrix E = Pds::RandN(3);
    E.Print("\nE:\n");

    Pds::Matrix F = Pds::MatrixId(2,3);
    F.Print("\nF:\n");

    Pds::Matrix G = Pds::Diag(F);
    G.Print("\nG:\n");

    Pds::Matrix H = Pds::MergeHor({A,B,C});
    H.Print("\nH=[A,B,C]:\n");

    Pds::Matrix I = Pds::MergeVer({A,B,C});
    I.Print("\nI=[A;B;C]:\n");
    
    I.MakeEmpty();
    std::list<Pds::Matrix> List={A,B,C};
    I.FusionVer(List);
    I.Print("\nI.FusionVer(List):\n");
    std::cout<<"List.size(): "<<List.size()<<"\n";
    for (auto pmat = List.begin(); pmat != List.end(); pmat++) 
    pmat->Print("\nList{0}:\n");

    
    std::cout<<"\n((3,3)): "<<Pds::NmultichooseK(3,3)<<std::endl;
    Pds::Matrix J = Pds::MultisetIndexSum(3,3);
    J.Print("J=MultisetIndexSum(3,3):\n");
    
    std::cout<<"\n((3,2)): "<<Pds::NmultichooseK(3,2)<<std::endl;
    Pds::Matrix K = Pds::MultisetIndexSum(3,2);
    K.Print("K=MultisetIndexSum(3,2):\n");
    
    std::cout<<"\n((3,1)): "<<Pds::NmultichooseK(3,1)<<std::endl;
    Pds::Matrix L = Pds::MultisetIndexSum(3,1);
    L.Print("L=MultisetIndexSum(3,1):\n");
        
    Pds::Matrix ID;
    F.Print("\nF:\n");
    Pds::Matrix M=Pds::Monomials(F,2,ID);
    M.Print("\nM=Pds::Monomials(F,2,ID):\n");
    ID.T().Print("\nID.T():\n");

    Pds::Matrix O=Pds::RegressorMatrix(F,2,ID);
    O.Print("\nO:\n");
    ID.T().Print("\nID.T():\n");

    std::cout<<Pds::MultisetIndexSumToString(ID)<<std::endl;
    
    A.Print("\nA:\n");
    std::cout<<"Pds::Find(A): "<<Pds::Ra::IndicesToString(Pds::Find(A),", ")<<std::endl;

    Pds::CountingTable(2,3).Print("\nPds::CountingTable(2,3):\n");

    Pds::CountingTable(3,-1,1,14).Print("\nPds::CountingTable(3,-1,1,14):\n");

    Pds::Matrix X;
    Pds::Matrix Y;
    Pds::Meshgrid(Pds::LinSpace(-3,3,7),Pds::LinSpace(-2,2,5),X,Y);
    X.Print("\nX:\n");
    Y.Print("\nY:\n");
    return 0;
}
