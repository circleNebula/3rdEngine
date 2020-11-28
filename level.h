#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;
class level{
	public:
		int loadPlayer(const char* filename);
		int loadReflectSlope(const char* filename);
		int loadTable(const char* filename);
		int loadSlope(const char* filename);
		int loadFSlope(const char* filename);
		int loadFinish(const char* filename);
		int loadExit(const char* filename);
		int loadTrapDoor(const char* filename);
		int loadOriginalTrap(const char* filename);
		int loadMagnets(const char* filename);
		int loadSpikes(const char* filename);
		int loadMoving(const char* filename);
		int loadMovingU(const char* filename);
		int loadTails(const char* filename);
		int loadBomb(const char* filename);
		int loadSqu(const char* filename);
		int loadProject(const char* filename);
		int loadBossHit(const char* filename);
		
		int loadPause(const char* filename);
		int loadRewind(const char* filename);
		int loadForward(const char* filename);
		
		int loadSpider(const char* filename);
		
		int loadBin(const char* filename);
		int loadBinSpawn(const char* filname);
		int loadFactory(const char* filename);
		int loadCamera(const char* filename);


		int loadFactoryObject(const char* filename);
		
		struct coordinate{
			float x,y,z;
			coordinate(float a,float b,float c) : x(a),y(b),z(c) {};
		};
		struct face{
			int facenum;
			bool four;
			int* faces = (int *) malloc(4 * sizeof(int));
			face(int facen,int f1,int f2,int f3) : facenum(facen){	//constructor for triangle
				faces[0]=f1;
				faces[1]=f2;
				faces[2]=f3;
				four=false;
			}
			face(int facen,int f1,int f2,int f3,int f4) : facenum(facen){ //overloaded constructor for quad
				faces[0]=f1;
				faces[1]=f2;
				faces[2]=f3;
				faces[3]=f4;
				four=true;
			}
		};
		std::vector<coordinate*> tVert;
		std::vector<face*> tFaces;
		std::vector<coordinate*> tNormals;
		
		std::vector<coordinate*> pVert;
		std::vector<face*> pFaces;
		std::vector<coordinate*> pNormals;
		
		std::vector<coordinate*> trOVert;
		std::vector<face*> trOFaces;
		std::vector<coordinate*> trONormals;
		
		std::vector<coordinate*> rSVert;
		std::vector<face*> rSFaces;
		std::vector<coordinate*> rSNormals;
		
		std::vector<coordinate*> famVert;
		std::vector<face*> famFaces;
		std::vector<coordinate*> famNormals;
		
		std::vector<coordinate*> sVert;
		std::vector<face*> sFaces;
		std::vector<coordinate*> sNormals;
		
		std::vector<coordinate*> sfVert;
		std::vector<face*> sfFaces;
		std::vector<coordinate*> sfNormals;

		std::vector<coordinate*> eVert;
		std::vector<face*> eFaces;
		std::vector<coordinate*> eNormals;

		std::vector<coordinate*> fVert;
		std::vector<face*> fFaces;
		std::vector<coordinate*> fNormals;
		
		std::vector<coordinate*> trVert;
		std::vector<face*> trFaces;
		std::vector<coordinate*> trNormals;
		
		std::vector<coordinate*> maVert;
		std::vector<face*> maFaces;
		std::vector<coordinate*> maNormals;
		
		std::vector<coordinate*> spVert;
		std::vector<face*> spFaces;
		std::vector<coordinate*> spNormals;


		
		std::vector<coordinate*> taVert;
		std::vector<face*> taFaces;
		std::vector<coordinate*> taNormals;
		
		std::vector<coordinate*> bVert;
		std::vector<face*> bFaces;
		
		std::vector<coordinate*> sqVert;
		std::vector<face*> sqFaces;
		
		std::vector<coordinate*> frVert;
		std::vector<face*> frFaces;
		std::vector<coordinate*> frNormals;
		
		std::vector<coordinate*> paVert;
		std::vector<face*> paFaces;
		std::vector<coordinate*> paNormals;
		
		std::vector<coordinate*> reVert;
		std::vector<face*> reFaces;
		std::vector<coordinate*> reNormals;
		
		std::vector<coordinate*> biNormals;
		std::vector<face*> biFaces;
		std::vector<coordinate*> biVert;
		
		std::vector<face*> biSFaces;
		std::vector<coordinate*> biSVert;
		
		std::vector<coordinate*> throwVert;
		std::vector<face*> throwFaces;
		std::vector<coordinate*> throwNormals;
		
		std::vector<coordinate*> caVert;
		std::vector<face*> caFaces;
		std::vector<coordinate*> caNormals;
		
		std::vector<coordinate*> moVert;
		std::vector<face*> moFaces;
		std::vector<coordinate*> moNormals;
		
		std::vector<coordinate*> moUVert;
		std::vector<face*> moUFaces;
		std::vector<coordinate*> moUNormals;
		
		std::vector<coordinate*> prVert;
		std::vector<face*> prFaces;
		std::vector<coordinate*> prNormals;
		
		std::vector<coordinate*> hVert;
		std::vector<face*> hFaces;
		std::vector<coordinate*> hNormals;
		
		std::vector<coordinate*> tmVert;
		std::vector<face*> tmFaces;
		std::vector<coordinate*> tmNormals;
		
		std::vector<coordinate*> faVert;
		std::vector<face*> faFaces;
		std::vector<coordinate*> faNormals;


	
		
	private:
		float furthestYl;
	protected:
};
#endif