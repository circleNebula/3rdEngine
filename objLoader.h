//This example program is created by thecplusplusuy for demonstration purposes. It's a simple 3D model loader (wavefront (.obj)), which is capable to load materials and UV textures:
//http://www.youtube.com/user/thecplusplusguy
//Free source, modify if you want, LGPL licence (I guess), I would be happy, if you would not delete the link
//so other people can see the tutorial
//this file is the objloader.h
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <iostream>
#ifndef OBJLOADER_H
#define OBJLOADER_H

//This struct contain 3 floats and a constructor, it's used for vertexes and normal vectors
struct coordinate{
	float x,y,z;
	coordinate(float a,float b,float c);
};
//This structure is store every property of a face
struct face{
	int facenum;	//the number of the face (it's start from 1 not 0, so if you use it as an index, subtract 1 from it), it's used for the normal vectors
	bool four;		//if true, than it's a quad else it's a triangle
	int faces[4];	//indexes for every vertex, which makes the face (it's start from 1 not 0, so if you use it as an index, subtract 1 from it)
	int texcoord[4];	//indexes for every texture coorinate that is in the face (it's start from 1 not 0, so if you use it as an index, subtract 1 from it)
	int mat;					//the index for the material, which is used by the face
	face(int facen,int f1,int f2,int f3,int t1,int t2,int t3,int m);	//constuctor for triangle
	face(int facen,int f1,int f2,int f3,int f4,int t1,int t2,int t3,int t4,int m);	//-"- for quad
};

//this is a structure, which contain one material
struct material{
	std::string name;	//the name of the material
	float alpha,ns,ni;	//some property, alpha, shininess, and some other, which we not used
	float dif[3],amb[3],spec[3];	//the color property (diffuse, ambient, specular)
	int illum;	//illum - we not use it
	int texture;	//the id for the texture, if there is no texture than -1
	material(const char* na,float al,float n,float ni2,float* d,float* a,float* s,int i,int t);
};

//texture coorinate (UV coordinate), nothing to explain here
struct texcoord{
	float u,v;
	texcoord(float a,float b);
};

struct frame{
	std::vector<coordinate*> vertex;	//all vertexes
	std::vector<face*> faces;					//all faces
	std::vector<coordinate*> normals;	//all normal vectors
	std::vector<material*> materials;	//all materials
	std::vector<texcoord*> texturecoordinate;	//all texture coorinate (UV coordinate)
	frame(std::vector<coordinate*> vertexs, std::vector<face*> facez, std::vector<coordinate*> normalz, std::vector<material*> materialz, std::vector<texcoord*> texturecoordinates);
	
};

//the main class for the object loader
class objloader{
	
	int texture1;
	int texture2;
	int texture3;
	

	bool ismaterial,isnormals,istexture;	//obvious
	unsigned int* textures1;
	void clean();	//free all of the used memory
	
	public:
	std::vector<frame*> tailFrames;
	std::vector<frame*> bombFrames;
	std::vector<frame*> squFrames;
	void drawTails(int frameCounter);
	void drawBomb(int frameCounter, float spawnX, float spawnY, float spawnZ, float angle);
	void drawSqu(int frameCounter, float spawnX, float spawnY, float spawnZ, float angle);
	void drawSquT(int frameCounter, float spawnX, float spawnY, float spawnZ, float angle);
	objloader();	
	~objloader();	//free the textures and lists
	int loadTails(const char* filename, const char* path);	//the main model load function
	int loadBomb(const char* filename , const char* path);
	int loadSqu(const char* filname, const char* path);
	void preLoadTexture();
	int loadTexture(char filename[], int number);
};

#endif