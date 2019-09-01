#include <igl/embree/line_mesh_intersection.h>
#include <igl/readSTL.h>

int main(int argc, char *argv[])
{


  
  std::vector<std::vector > V;
  std::vector<std::vector > F;
  std::vector<std::vector > N;
  bool success = igl::readSTL("File_path.stl",V,F,N);
  Eigen::MatrixXd V_1(V.size(),3);
  Eigen::MatrixXi F_1(F.size(),3);
  Eigen::MatrixXd N_1(N.size(),3);
  Eigen::MatrixXd V_1_f(1,3);
  Eigen::MatrixXd N_1_f(1,3);
  V_1_f(0,0)=rNode.X(); V_1_f(0,1)=rNode.Y(); V_1_f(0,2)=rNode.Z();
  N_1_f(0,0)=rRayVector[0]; N_1_f(0,1)=rRayVector[1]; N_1_f(0,2)=rRayVector[2];

for (int i=0; i<V.size(); ++i){

  V_1(i,0)=V[i][0]; V_1(i,1)=V[i][1]; V_1(i,2)=V[i][2];
  //std::cout<<V_1(i,0)<<V_1(i,1)<<V_1(i,2)<<std::endl;

}
for (int i=0; i<F.size(); ++i){

  F_1(i,0)=F[i][0]; F_1(i,1)=F[i][1]; F_1(i,2)=F[i][2];
  //std::cout<<F_1(i,0)<<F_1(i,1)<<F_1(i,2)<<std::endl;

}
for (int i=0; i<N.size(); ++i){

  N_1(i,0)=N[i][0]; N_1(i,1)=N[i][1]; N_1(i,2)=N[i][2];
  //std::cout<<N_1(i,0)<<N_1(i,1)<<N_1(i,2)<<std::endl;

}

Eigen::MatrixXd R = igl::embree::line_mesh_intersection<Eigen::MatrixXd, Eigen::MatrixXi >(V_1_f, N_1_f, V_1, F_1);
std::cout<<"Ray Hit !!!!!!!!!!!!!!!!!!"<<R<<std::endl;}
