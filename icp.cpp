#include <opencv2/surface_matching.hpp>
#include <iostream>
#include <opencv2/surface_matching/ppf_helpers.hpp>
#include <opencv2/core/utility.hpp>

using namespace std;
using namespace cv;
using namespace ppf_match_3d;

int main(int argc, char** argv){
	Mat model=loadPLYSimple("model-low.ply",0);
	Mat scene=loadPLYSimple("scene-high.ply",0);
   ICP icp(100, 0.2f, 2.0f, 8);
cerr<<"icp...";
	Matx44d pose(
		1,0,0,0,
		0,1,0,13,
		0,0,1,0,
		0,0,0,1
	);
	double residu=0;
	Mat modela=transformPCPose(model,pose);
   icp.registerModelToScene(modela, scene, residu, pose);
cerr<<"done\n";
cerr<<"pose=\n"<<pose<<"\n";
cerr<<"residue="<<residu<<"\n";
	modela=transformPCPose(modela, pose);
	writePLY(modela,"result.ply");
	return 0;
}