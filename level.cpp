#include "GL/glu.h"
#include <GL/gl.h>
#include "level.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

//create object for coordinates
struct coordinate{
	float x,y,z;
	coordinate(float a,float b,float c) : x(a),y(b),z(c) {};
};
float furthestYl;
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

struct uv{
	bool four;
	int * faces = (int*) malloc(4 *sizeof(int));
	uv(int uva, int uvb, int uvc){
		faces[0] = uva;
		faces[1] = uvb;
		faces[2] = uvc;
		four = false;
	}
	uv(int uva, int uvb, int uvc, int uvd){
		faces[0] = uva;
		faces[1] = uvb;
		faces[2] = uvc;
		four = true;
	}
	
};



std::vector<coordinate*> pVert;
std::vector<face*> pFaces;
std::vector<coordinate*> pNormals;

std::vector<coordinate*> rSVert;
std::vector<face*> rSFaces;
std::vector<coordinate*> rSNormals;

std::vector<coordinate*> tVert;
std::vector<face*> tFaces;
std::vector<coordinate*> tNormals;

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

std::vector<coordinate*> trOVert;
std::vector<face*> trOFaces;
std::vector<coordinate*> trONormals;

std::vector<coordinate*> maVert;
std::vector<face*> maFaces;
std::vector<coordinate*> maNormals;

std::vector<coordinate*> spVert;
std::vector<face*> spFaces;
std::vector<coordinate*> spNormals;


std::vector<coordinate*> taVert;
std::vector<face*> taFaces;
std::vector<coordinate*> taNormals;
std::vector<uv*> taUvs;

std::vector<coordinate*>  bVert;
std::vector<face*> bFaces;

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

std::vector<coordinate*> throwVert;
std::vector<face*> throwFaces;
std::vector<coordinate*> throwNormals;

std::vector<face*> biSFaces;
std::vector<coordinate*> biSVert;

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

std::vector<coordinate*> famVert;
std::vector<face*> famFaces;
std::vector<coordinate*> famNormals;

int level::loadFactoryObject(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertex;
	std::vector<face*> faces;
	std::vector<coordinate*> normals;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Didn't load Spider" << std::endl;
		famVert = vertex;
		famNormals = normals;
		famFaces = faces;
		return -1;
		
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
//	std::cout << "here" << std::endl;
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			vertex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			normals.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				faces.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				faces.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	famVert = vertex;
	famFaces = faces;
	famNormals = normals;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];
}
	

int level::loadFactory(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertex;
	std::vector<face*> faces;
	std::vector<coordinate*> normals;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Didn't load Spider" << std::endl;
		faVert = vertex;
		faNormals = normals;
		faFaces = faces;
		return -1;
		
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
//	std::cout << "here" << std::endl;
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			vertex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			normals.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				faces.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				faces.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	faVert = vertex;
	faFaces = faces;
	faNormals = normals;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];
}

int level::loadSpider(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertex;
	std::vector<face*> faces;
	std::vector<coordinate*> normals;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Didn't load Spider" << std::endl;
		tmVert = vertex;
		tmNormals = normals;
		tmFaces = faces;
		return -1;
		
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
//	std::cout << "here" << std::endl;
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			vertex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			normals.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				faces.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				faces.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	tmVert = vertex;
	tmFaces = faces;
	tmNormals = normals;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];
}

int level::loadBossHit(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertex;
	std::vector<face*> faces;
	std::vector<coordinate*> normals;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "No Boss Hit" << std::endl;
		hVert = vertex;
		hNormals = normals;
		hFaces = faces;
		return -1;
		
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
//	std::cout << "here" << std::endl;
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			vertex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			normals.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				faces.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				faces.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	hVert = vertex;
	hFaces = faces;
	hNormals = normals;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];
}

int level::loadCamera(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertex;
	std::vector<face*> faces;
	std::vector<coordinate*> normals;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Not needed" << std::endl;
		paVert = vertex;
		paNormals = normals;
		paFaces = faces;
		return -1;
		
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
//	std::cout << "here" << std::endl;
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			vertex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			normals.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				faces.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				faces.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	caVert = vertex;
	caFaces = faces;
	caNormals = normals;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];
}

int level::loadMoving(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertex;
	std::vector<face*> faces;
	std::vector<coordinate*> normals;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Not needed" << std::endl;
		moVert = vertex;
		moNormals = normals;
		moFaces = faces;
		return -1;
		
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
//	std::cout << "here" << std::endl;
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			vertex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			normals.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				faces.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				faces.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	moVert = vertex;
	moFaces = faces;
	moNormals = normals;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];
}


int level::loadMovingU(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertex;
	std::vector<face*> faces;
	std::vector<coordinate*> normals;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Not needed" << std::endl;
		moUVert = vertex;
		moUNormals = normals;
		moUFaces = faces;
		return -1;
		
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
//	std::cout << "here" << std::endl;
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			vertex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			normals.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				faces.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				faces.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	moUVert = vertex;
	moUFaces = faces;
	moUNormals = normals;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];
}
int level::loadPause(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertex;
	std::vector<face*> faces;
	std::vector<coordinate*> normals;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Not needed" << std::endl;
		paVert = vertex;
		paNormals = normals;
		paFaces = faces;
		return -1;
		
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
//	std::cout << "here" << std::endl;
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			vertex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			normals.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				faces.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				faces.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	paVert = vertex;
	paFaces = faces;
	paNormals = normals;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];

}
int level::loadBinSpawn(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertex;
	std::vector<face*> faces;
	std::vector<coordinate*> normals;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Not needed" << std::endl;
		biSVert = vertex;
		biSFaces = faces;
		return -1;
		
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
//	std::cout << "here" << std::endl;
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			vertex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			normals.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				faces.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				faces.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	biSVert = vertex;
	biSFaces = faces;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];
}
int level::loadBin(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertex;
	std::vector<face*> faces;
	std::vector<coordinate*> normals;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Not needed" << std::endl;
		biVert = vertex;
		biNormals = normals;
		biFaces = faces;
		return -1;
		
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
//	std::cout << "here" << std::endl;
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			vertex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			normals.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				faces.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				faces.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	biVert = vertex;
	biFaces = faces;
	biNormals = normals;
	
	throwVert = vertex;
	throwFaces = faces;
	throwNormals = normals;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];

}

int level::loadRewind(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertex;
	std::vector<face*> faces;
	std::vector<coordinate*> normals;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Not needed" << std::endl;
		reVert = vertex;
		reNormals = normals;
		reFaces = faces;
		return -1;
		
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
//	std::cout << "here" << std::endl;
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			vertex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			normals.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				faces.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				faces.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	reVert = vertex;
	reFaces = faces;
	reNormals = normals;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];

}

int level::loadForward(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertex;
	std::vector<face*> faces;
	std::vector<coordinate*> normals;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Not needed" << std::endl;
		frVert = vertex;
		frNormals = normals;
		frFaces = faces;
		return -1;
		
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
//	std::cout << "here" << std::endl;
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			vertex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			normals.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				faces.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				faces.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	frVert = vertex;
	frFaces = faces;
	frNormals = normals;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];

}

int level::loadBomb(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertex;
	std::vector<face*> faces;
	std::vector<coordinate*> normals;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Not needed" << std::endl;
		bVert = vertex;
		//spNormals = normals;
		bFaces = faces;
		return -1;
		
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
//	std::cout << "here" << std::endl;
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			vertex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			normals.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				faces.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				faces.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	bVert = vertex;
	bFaces = faces;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];

}

int level::loadSqu(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertex;
	std::vector<face*> faces;
	std::vector<coordinate*> normals;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Not needed Sqyu" << std::endl;
		sqVert = vertex;
		//spNormals = normals;
		sqFaces = faces;
		return -1;
		
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
//	std::cout << "here" << std::endl;
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			vertex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			normals.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				faces.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				faces.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	sqVert = vertex;
	sqFaces = faces;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];

}

int level::loadSpikes(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertex;
	std::vector<face*> faces;
	std::vector<coordinate*> normals;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Not needed" << std::endl;
		spVert = vertex;
		spNormals = normals;
		spFaces = faces;
		return -1;
		
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
//	std::cout << "here" << std::endl;
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			vertex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			normals.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				faces.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				faces.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	spVert = vertex;
	spNormals = normals;
	spFaces = faces;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];

}


int level::loadReflectSlope(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertex;
	std::vector<face*> faces;
	std::vector<coordinate*> normals;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Not needed" << std::endl;
		rSVert = vertex;
		rSNormals = normals;
		rSFaces = faces;
		return -1;
		
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
//	std::cout << "here" << std::endl;
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			vertex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			normals.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				faces.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				faces.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	rSVert = vertex;
	rSNormals = normals;
	rSFaces = faces;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];

}

int level::loadTails(const char* filename){
		std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertex;
	std::vector<face*> faces;
	std::vector<coordinate*> normals;
	std::vector<uv*> uvs;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Not needed" << std::endl;
		spVert = vertex;
		spNormals = normals;
		spFaces = faces;
		return -1;
		
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
//	std::cout << "here" << std::endl;
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			vertex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			normals.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			
			int uva, uvb, uvc, uvd;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
				sscanf(coord[i]->c_str(),"f %d/%d/%d %d/%d/%d %d/%d/%d",&a,&uva,&b,&c, &uvb,&b,&d, &uvc,&b);
				faces.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
				uvs.push_back(new uv(uva, uvb, uvc));
			}else{
				sscanf(coord[i]->c_str(),"f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d",&a, &uva, &b,&c, &uvb, &b, &d, &uvc, &b,&e, &uvd, &b);
				faces.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
				uvs.push_back(new uv(uva, uvb, uvc, uvd));
			}
			/*if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				faces.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				faces.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}*/
		}
	}
	taVert = vertex;
	taNormals = normals;
	taFaces = faces;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];
}



int level::loadFinish(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertex;
	std::vector<face*> faces;
	std::vector<coordinate*> normals;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Not needed" << std::endl;
		fVert = vertex;
		fNormals = normals;
		fFaces = faces;
		return -1;
		
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
//	std::cout << "here" << std::endl;
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			vertex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			normals.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				faces.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				faces.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	fVert = vertex;
	fNormals = normals;
	fFaces = faces;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];
}

int level::loadTrapDoor(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertex;
	std::vector<face*> faces;
	std::vector<coordinate*> normals;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Not needed" << std::endl;
		trVert = vertex;
		trNormals = normals;
		trFaces = faces;
		return -1;
		
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
//	std::cout << "here" << std::endl;
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			vertex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			normals.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				faces.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				faces.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	trVert = vertex;
	trNormals = normals;
	trFaces = faces;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];
}

int level::loadOriginalTrap(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertex;
	std::vector<face*> faces;
	std::vector<coordinate*> normals;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Not needed" << std::endl;
		trOVert = vertex;
		trONormals = normals;
		trOFaces = faces;
		return -1;
		
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
//	std::cout << "here" << std::endl;
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			vertex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			normals.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				faces.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				faces.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	trOVert = vertex;
	trONormals = normals;
	trOFaces = faces;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];
}
int level::loadMagnets(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertex;
	std::vector<face*> faces;
	std::vector<coordinate*> normals;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Not needed" << std::endl;
		maVert = vertex;
		maNormals = normals;
		maFaces = faces;
		return -1;
		
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
//	std::cout << "here" << std::endl;
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			vertex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			normals.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				faces.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				faces.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	maVert = vertex;
	maNormals = normals;
	maFaces = faces;
	for(int i=0;i<coord.size();i++)
		delete coord[i];
}
int level::loadExit(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertex;
	std::vector<face*> faces;
	std::vector<coordinate*> normals;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Not needed" << std::endl;
		eVert = vertex;
		eNormals = normals;
		eFaces = faces;
		return -1;
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
//	std::cout << "here" << std::endl;
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			vertex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			normals.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				faces.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				faces.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	eVert = vertex;
	eNormals = normals;
	eFaces = faces;
	for(int i=0;i<coord.size();i++)
		delete coord[i];
}
int level::loadProject(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertex;
	std::vector<face*> faces;
	std::vector<coordinate*> normals;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Not needed" << std::endl;
		prVert = vertex;
		prNormals = normals;
		prFaces = faces;
		return -1;
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
//	std::cout << "here" << std::endl;
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			vertex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			normals.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				faces.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				faces.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	prVert = vertex;
	prNormals = normals;
	prFaces = faces;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];
}
int level::loadPlayer(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertex;
	std::vector<face*> faces;
	std::vector<coordinate*> normals;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Not needed" << std::endl;
		pVert = vertex;
		pNormals = normals;
		pFaces = faces;
		return -1;
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
//	std::cout << "here" << std::endl;
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			vertex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			normals.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				faces.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				faces.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	pVert = vertex;
	pNormals = normals;
	pFaces = faces;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];
}
int level::loadSlope(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertex;
	std::vector<face*> faces;
	std::vector<coordinate*> normals;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Not needed" << std::endl;
		sVert = vertex;
		sNormals = normals;
		sFaces = faces;
		return -1;
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
//	std::cout << "here" << std::endl;
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			vertex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			normals.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				faces.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				faces.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	sVert = vertex;
	sNormals = normals;
	sFaces = faces;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];
}
int level::loadFSlope(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertex;
	std::vector<face*> faces;
	std::vector<coordinate*> normals;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Not needed" << std::endl;
		sfVert = vertex;
		sfNormals = normals;
		sfFaces = faces;
		return -1;
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
//	std::cout << "here" << std::endl;
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			vertex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			normals.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				faces.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				faces.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	sfVert = vertex;
	sfNormals = normals;
	sfFaces = faces;
	
	for(int i=0;i<coord.size();i++)
		delete coord[i];
}
int level::loadTable(const char* filename){
	std::vector<std::string*> coord;	//read every single line of the obj file as a string
	std::vector<coordinate*> vertex;
	std::vector<face*> faces;
	std::vector<coordinate*> normals;	//normal vectors for every face
	std::ifstream in(filename);	//open the .obj file
	
	if(!in.is_open()){	//if not opened, exit with -1
		std::cout << "Not needed" << std::endl;
		tVert = vertex;
		tNormals = normals;
		tFaces = faces;
		return -1;
	}
	char* buf = (char *)malloc(256 * sizeof(char));
	//read in every line to coord
	while(!in.eof()){
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}
//	std::cout << "here" << std::endl;
	//go through all of the elements of coord, and decide what kind of element is that
	for(int i=0;i<coord.size();i++){
		if(coord[i]->c_str()[0]=='#'){	//if it is a comment (the first character is #)
			continue;	//we don't care about that
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' '){	//if vector
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);	//read in the 3 float coordinate to tmpx,tmpy,tmpz
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			vertex.push_back(new coordinate(tmpx,tmpy,tmpz));	//and then add it to the end of our vertex list
		}else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n'){	//if normal vector
			float tmpx,tmpy,tmpz;	//do the same thing
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			if(tmpy < furthestYl){
				furthestYl = tmpy;	
			}
			normals.push_back(new coordinate(tmpx,tmpy,tmpz));	
		}else if(coord[i]->c_str()[0]=='f'){	//if face
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	//if it is a triangle (it has 3 space in it)
			{
		  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				faces.push_back(new face(b,a,c,d));	//read in, and add to the end of the face list
			}else{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				faces.push_back(new face(b,a,c,d,e));	//do the same, except we call another constructor, and we use different pattern
			}
		}
	}
	tVert = vertex;
	tNormals = normals;
	tFaces = faces;
	int num;	//the id for the list
	num=glGenLists(3);	//generate a uniqe
	return num;
}
