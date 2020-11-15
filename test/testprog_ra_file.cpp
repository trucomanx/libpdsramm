/** \example testprog_ra_file.cpp
 *  \brief Programa para el testeo de las funciones.
 *  
 */
    
#include <Pds/Ra>


int main(int argc, char * argv[])
{
     std::cout<<Pds::Ra::HomeDir()<<std::endl;
     std::cout<<Pds::Ra::Programpath()<<std::endl;
     std::cout<<Pds::Ra::Pwd()<<std::endl;
     
     std::cout<<std::endl;
     
     std::string filepath=Pds::Ra::FullFile({"/usr","share","program_name","icons","image.png"});
     std::cout<<" filepath: "<<filepath<<std::endl;
     std::cout<<"  dirname: "<<Pds::Ra::Dirname(filepath)<<std::endl;
     std::cout<<" basename: "<<Pds::Ra::Basename(filepath)<<std::endl;
     std::cout<<"extension: "<<Pds::Ra::Extension(filepath)<<std::endl;
     std::cout<<" filename: "<<Pds::Ra::Filename(filepath)<<std::endl;

     std::cout<<"replaceex: "<<Pds::Ra::ReplaceExtension(filepath,"bmp")<<std::endl;
         
     std::string data;
     data=Pds::Ra::GetParamString(argc,argv,"--dat","default_data");
     std::cout<<"data: "<<data<<std::endl;
     
    if(Pds::Ra::ExistParam(argc,argv,"--dat"))  std::cout<<"Exist the param: ---dat"<<std::endl;
    else                                        std::cout<<"NO exist the param: ---dat"<<std::endl;
     
    if(Pds::Ra::IsFile(filepath))   std::cout<<"Exist the file: "<<filepath<<std::endl;
    else                            std::cout<<"NO exist the file: "<<filepath<<std::endl;
    
    if(Pds::Ra::IsDir(Pds::Ra::HomeDir()))    std::cout<<"Exist the directory: "<<Pds::Ra::HomeDir()<<std::endl;
    else                            std::cout<<"NO exist the directory: "<<Pds::Ra::HomeDir()<<std::endl;
}
