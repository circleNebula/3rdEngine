#include "math3d/math3d.h"
#include "GLee/GLee.h"
#include "GL/glu.h"
#include <GL/gl.h>
#include "level.h"
#include "SFML/Graphics.hpp"
#include "SFML/OpenGL.hpp"
#include "objloader.h"
#include "Maths/Maths.h"
#include "client2.h"
#include "AnimationController.h"
#include "xmlLoad.h"
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio.hpp>
#include <string.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <iostream>

	int part = 1;
	int world = 1;

int cube2;
float px, pz, py;
int table;
float speed = 0.1;
float pRotateSpeed = 3;
bool enKilled[20];
bool squKilled[20];
M3DMatrix44f shadow;
M3DVector4f equation;
GLUquadric* q;

bool squBounceFlipped;
int squBounceCounter = 0;
float moveSkew = 0;

string clientLine;
string cName;
bool online = false;
float onlineX[10];
float onlineY[10];
float onlineZ[10];
int pauseM, rewindM, forwardM;
float bossX, bossY, bossZ, bossAngle =0;
int bossLives = 3;
bool bossKilled = false;
int bossFindCounter = 0;
int onlineCounter = 0;
int onlineMCounter[10];
float onlineAngle[10];
float onlineRotation[10];
float onlineFrameCounter[10];
string onlineName[10];


float rewindSquX[20][500];
float rewindSquZ[20][500];
float rewindSquOldAngle[20];
float rewindSquAngle[20][500];

int rewindSquCounter[20];

bool onlineHi[10];
bool onlineSwitchAnimate[10];
bool onlineRunning[10];
bool onlineSucking[10];
bool onlineThrowAnimation[10];
bool onlineJumpingAnimation[10];
float onlineLastY[10];
bool onlineRunningDone[10];
bool onlineHiDone[10];
bool onlineJumpingDone[10];


string onlineCurrentAnimation[10];
string currentAnimation = "hiy";

GLfloat emerald_ambient[] =
{0.0215, 0.1745, 0.0215}, emerald_diffuse[] =
{0.07568, 0.61424, 0.07568}, emerald_specular[] =
{0.633, 0.727811, 0.633}, emerald_shininess = 76.8;

GLfloat yellow_light[] = {1.0,1.0,0,1.0};

GLfloat red_light[] =
{0.863, 0.078, 0.235, 1}, green_light[] =
{0.0, 1.0, 0.0, 1.0}, white_light[] =
{1.0, 1.0, 1.0, 1.0}, blue_light[] = { 	0.000, 0.749, 1.000,1}, pink_light[] = { 	0.294, 0.000, 0.510, 1};
GLfloat left_light_position[] =
{-1.0, 0.0, 1.0, 0.0}, right_light_position[] =
{1.0, 0.0, 1.0, 0.0};
GLfloat brass_ambient[] =
{0.33, 0.22, 0.03,1}, brass_diffuse[] =
{0.78, 0.57, 0.11, 0.6}, brass_specular[] =
{0.99, 0.91, 0.81, 1}, brass_shininess = 27.8;

GLfloat mint_light[] ={0.000, 1.000, 0.498, 1};

GLfloat orange_light[] ={1.000, 0.549, 0.000, 1};

GLfloat red_plastic_ambient[] =
{0.0, 0.0, 0.0}, red_plastic_diffuse[] =
{0.5, 0.0, 0.0}, red_plastic_specular[] =
{0.7, 0.6, 0.6}, red_plastic_shininess = 32.0;

int bombCount;

GLfloat slate_ambient[] =
{0.02, 0.02, 0.02}, slate_diffuse[] =
{0.02, 0.01, 0.01}, slate_specular[] =
{0.4, 0.4, 0.4}, slate_shininess = .78125;

static GLfloat floorPlane[4];
static GLfloat floorShadow[4][4];

int pauseTexture, rewindTexture, forwardTexture;

bool pauseTime = false;
bool forwardTime = false;
bool rewindTime = false;
int timeCounter = 0;
float coinSpinSpeed = 1;
float coinSpin =0;
int ballTexture, trapTexture, spikeTexture, magTexture;
float lightAngle = 0;
bool debugMode = false;
GLUquadric* sphere;
int skyT, skyB, skyF, skyBk, skyL, skyR;
bool foundCrystal = false;
float reflectSkew = 0;
bool trapTripped[20];
float trapRespawn[20];
float TrapWait[20];

bool runFromJump = false;
float magnetSpeed = 0.04;

float cameraRotateX, cameraRotateY = 0;

		float angle = -90;
	int ground = 0;
	float slopeAngle = 35;
	float angleX =0;

	float enemySpeed = 0.1;
	float reflectCounter =0;
	
	float onlineReflectCounter[10];
	
	
	bool start = false;
	int tailHead, tailBody, tailShoes;
	int tails;

GLuint shadowMapTexture;
int frameCounter;
bool switchAnimate = false;
int bombFrameCounter;
bool bombSwitchAnimate = false;
bool running = false;
bool hi = true;

float bombAngle = 0;
float bombZ[50];
float bombX[50];
float bombY[50];
int bombHeart[50];


float factoryX[20];
float factoryY[20];
float factoryZ[20];
bool factoryDead[20];
int factoryCounter;
int factoryTimer[20];
int factorySpeed;

float factoryMinionX[20];
float factoryMinionY[20];
float factoryMinionZ[20];
int fMinionSize;

int trapCount; 
float trapX[20];
float trapY[20];
float trapZ[20];

int sqCount = 0;
float squAngle[20];
float squZ[20];
float squX[20];
float squOldX[20];
float squOldZ[20];
bool squHit[20];
int squHitCounter[20];


float tMonsterX[20];
float tMonsterY[20];
float tMonsterZ[20];
float tMAngle[20];
int tMonsterType[20];
bool tmKilled[20];
int tmCooldown[20];
int tmCount;

float squY[20];
int squHeart[20];

int animeX[10];
int animeY[10];
int animeZ[10];
int animeCount;
float animeAngle[10];

float projectX[20];
float projectZ[20];
float projectY[20];
float projectAngle[20];
bool fireProject[20];
int projectCounter[20];
int projectCount;

float firePrX[20];
float firePrY[20];
float firePrZ[20];

int binCount;
float binX[50];
float binY[50];
float binZ[50];
bool binCollected[50];
bool binamation[50];
float binScale[50];
int hearts = 3;
int heartDeplete[8];
bool throwing = false;
bool throwAnimation = false;
bool sucking = false;
float throwX;
float throwY;
float throwZ;
float throwAngle;
float binVentory = 0;

float rewindSpawnX[100];
float rewindSpawnY[100];
float rewindSpawnZ[100];

int pauseCounter;
int rewindCounter;
int forwardCounter;

int pauseInven;
int rewindInven;
int forwardInven;

float pauseSpawnX[100];
float pauseSpawnY[100];
float pauseSpawnZ[100];

float forwardSpawnX[100];
float forwardSpawnY[100];
float forwardSpawnZ[100];

float rewindSkewX[100];
float rewindSkewY[100];
float rewindSkewZ[100];

float pauseSkewX[100];
float pauseSkewY[100];
float pauseSkewZ[100];

float forwardSkewX[100];
float forwardSkewY[100];
float forwardSkewZ[100];

bool forwardBounce[100];
bool pauseBounce[100];
bool rewindBounce[100];

bool shownPause[100];
bool shownRewind[100];
bool shownForward[100];

bool pauseCollectable[100];
bool rewindCollectable[100];
bool forwardCollectable[100];

bool completeFinished = 0;


bool lightDefined = false;
float lightX = 0;
float lightY = 0;
float lightZ = 0;
int count_semi(string s) {
  int count = 0;

  for (int i = 0; i < s.size(); i++)
    if (s[i] == ':') count++;

  return count;
}
void reflection(level &levelLoad, float playerR, float playerRZ, objloader &obj, int frameCounter, AnimationController &kingH, AnimationController &kingI, AnimationController &kingR){
	
		
			glMatrixMode(GL_MODELVIEW);
		//	glLoadIdentity(); // start a new matrix
			//glEnable(GL_TEXTURE_2D);


			//glRotatef(15,1,0, 0);
			//glTranslatef(0,-10,-50);
		   glEnable(GL_LIGHTING); //enable basic lighting on the objects
		   
			//glEnable(GL_LIGHT0);
			//glPopMatrix();
			//glEnable
		
			//glTranslated(lightpos3[0], lightpos3[1], lightpos3[2]);
			
		//	shadowMatrix(floorShadow, floorPlane, left_light_position);
			
			//glEnable(GL_LIGHT1);
		//	glRotatef(angle, 1,0,0);
		//	glRotatef(angleX, 0,1,0);
			
				GLfloat	lightpos3[4] = { 2.0f, 3.0f,2.0f, 1.0 }; 
		lightAngle += 0.1;
		//lightpos3[0] = cos(lightAngle);
		//lightpos3[1] = 5;
		//lightpos3[2] = sin(lightAngle);
			glLightfv(GL_LIGHT0, GL_POSITION, lightpos3);
			glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
			//glLightfv(GL_LIGHT1, GL_POSITION, lightpos3);
			//glLightfv(GL_LIGHT1, GL_SPECULAR, white_light);
			
			//glEnable(GL_LIGHT0);
			//glEnable(GL_LIGHT1);
			
			M3DVector3f points[3] = {{-9,-2,-8}, {-9, -2, 8}, {1, -2, 8}};
			m3dGetPlaneEquation(equation, points[0], points[1], points[2]);
			m3dMakePlanarShadowMatrix(shadow, equation, lightpos3);
		
		   // glColor3f(0.5, 0.5, 0.0);       
    // create a polygon ( define the vertexs) 
			//glPushMatrix();
			//glRotatef(angle * 30, 0.f, 1.f, 0.f);
			//glPushMatrix();
			//glLoadIdentity();
			//glTranslatef(levelLoad.pVert[levelLoad.pFaces[0]->faces[1]-1]->x + px, 0, levelLoad.pVert[levelLoad.pFaces[0]->faces[0]-1]->z + pz);
			//glRotatef(playerR,0,0,1);
			//glTranslatef(-levelLoad.pVert[levelLoad.pFaces[0]->faces[1]-1]->x + px, 0, -levelLoad.pVert[levelLoad.pFaces[0]->faces[0]-1]->z + pz);
			glPushMatrix();
			if(start){
					//glCallList(marble);
					//glTranslatef(px, py, pz);
					//glPopMatrix();
					glRotatef(playerRZ,1,0,0);
					glRotatef(playerR,0,0,1);
					//glTranslatef(-px, -py, -pz);
					gluQuadricDrawStyle(sphere, GLU_FILL);
					//glEnable(GL_TEXTURE_2D);
					//glBindTexture(GL_TEXTURE_2D, ballTexture);
					gluQuadricTexture(sphere, GL_TRUE);
					gluQuadricNormals(sphere, GLU_SMOOTH);
					gluSphere(sphere, 1.0, 64, 32);
					//glDisable(GL_TEXTURE_2D);
				}
			//glTranslatef(0,10,50);
			//glTranslatef(px, 0, pz);
			//glRotatef(playerRZ,1,0,0);
			//glRotatef(playerR,0,0,1);
			
			//glTranslatef(-levelLoad.pVert[levelLoad.pFaces[i]->faces[1]-1]->x + px, 0, -levelLoad.pVert[levelLoad.pFaces[i]->faces[1]-1]->z + pz);
			//glTranslatef(-px, 0, -pz);
			//glTranslatef(0,-10,-50);
			//glCallList(table);
			
			
			//glTranslatef(-px, -py, -pz);
			//glDisable(GL_TEXTURE_2D);
			
			glDisable(GL_DEPTH_TEST);
      glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);

      /* Draw 1 into the stencil buffer. */
      glEnable(GL_STENCIL_TEST);
      glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);
      glStencilFunc(GL_ALWAYS, 1, 0xffffffff);
			//cout << "painting reflection" << endl;
			//if(!start){
for(int i=0;i< levelLoad.pFaces.size();i++){	
						if((i+1) % 6 == 0){	
								if(levelLoad.pFaces[i]->four){	//if it's a quad draw a quad
									//if((i+1) % 6 != 0){
									//	std::cout << "here 1" << std::endl;
										glBegin(GL_QUADS);
											//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
											//I subtract 1 because the index start from 0 in C++
											
											glNormal3f(levelLoad.pNormals[levelLoad.pFaces[i]->facenum-1]->x,levelLoad.pNormals[levelLoad.pFaces[i]->facenum-1]->y,levelLoad.pNormals[levelLoad.pFaces[i]->facenum-1]->z);
											//draw the faces
											glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.pVert[levelLoad.pFaces[i]->faces[0]-1]->x,levelLoad.pVert[levelLoad.pFaces[i]->faces[0]-1]->y,levelLoad.pVert[levelLoad.pFaces[i]->faces[0]-1]->z);
											glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.pVert[levelLoad.pFaces[i]->faces[1]-1]->x,levelLoad.pVert[levelLoad.pFaces[i]->faces[1]-1]->y,levelLoad.pVert[levelLoad.pFaces[i]->faces[1]-1]->z);
											glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.pVert[levelLoad.pFaces[i]->faces[2]-1]->x,levelLoad.pVert[levelLoad.pFaces[i]->faces[2]-1]->y,levelLoad.pVert[levelLoad.pFaces[i]->faces[2]-1]->z);
											glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.pVert[levelLoad.pFaces[i]->faces[3]-1]->x,levelLoad.pVert[levelLoad.pFaces[i]->faces[3]-1]->y,levelLoad.pVert[levelLoad.pFaces[i]->faces[3]-1]->z);
										glEnd();
									}else{
										
										//char path[] = "Images/block3.png";
										//treeText1= loadTexture(path,3);
										//glBindTexture(GL_TEXTURE_2D, texture5);
										glBegin(GL_TRIANGLES);
											//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
											//I subtract 1 because the index start from 0 in C++
											
											glNormal3f(levelLoad.pNormals[levelLoad.pFaces[i]->facenum-1]->x,levelLoad.pNormals[levelLoad.pFaces[i]->facenum-1]->y,levelLoad.pNormals[levelLoad.pFaces[i]->facenum-1]->z);
											//draw the faces
											glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.pVert[levelLoad.pFaces[i]->faces[0]-1]->x,levelLoad.pVert[levelLoad.pFaces[i]->faces[0]-1]->y,levelLoad.pVert[levelLoad.pFaces[i]->faces[0]-1]->z);
											glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.pVert[levelLoad.pFaces[i]->faces[1]-1]->x,levelLoad.pVert[levelLoad.pFaces[i]->faces[1]-1]->y,levelLoad.pVert[levelLoad.pFaces[i]->faces[1]-1]->z);
											glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.pVert[levelLoad.pFaces[i]->faces[2]-1]->x,levelLoad.pVert[levelLoad.pFaces[i]->faces[2]-1]->y,levelLoad.pVert[levelLoad.pFaces[i]->faces[2]-1]->z);
											//glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.pVert[levelLoad.pFaces[i]->faces[3]-1]->x,levelLoad.pVert[levelLoad.pFaces[i]->faces[3]-1]->y,levelLoad.pVert[levelLoad.pFaces[i]->faces[3]-1]->z);
										glEnd();	
										//char path2[] = "Images/Plants/tree1.png";
										////treeText1 = loadTexture(path2, 3);
										//glBindTexture(GL_TEXTURE_2D, texture3);
									}
							}
				}
		for(int i=0;i< levelLoad.rSFaces.size();i++){	
						if((i+1) % 6 == 0){	
								if(levelLoad.rSFaces[i]->four){	//if it's a quad draw a quad
									//if((i+1) % 6 != 0){
									//	std::cout << "here 1" << std::endl;
										glBegin(GL_QUADS);
											//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
											//I subtract 1 because the index start from 0 in C++
											
											glNormal3f(levelLoad.rSNormals[levelLoad.rSFaces[i]->facenum-1]->x,levelLoad.rSNormals[levelLoad.rSFaces[i]->facenum-1]->y,levelLoad.rSNormals[levelLoad.rSFaces[i]->facenum-1]->z);
											//draw the faces
											glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.rSVert[levelLoad.rSFaces[i]->faces[0]-1]->x,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[0]-1]->y,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[0]-1]->z);
											glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.rSVert[levelLoad.rSFaces[i]->faces[1]-1]->x,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[1]-1]->y,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[1]-1]->z);
											glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.rSVert[levelLoad.rSFaces[i]->faces[2]-1]->x,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[2]-1]->y,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[2]-1]->z);
											glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.rSVert[levelLoad.rSFaces[i]->faces[3]-1]->x,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[3]-1]->y,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[3]-1]->z);
										glEnd();
									}else{
										
										//char path[] = "Images/block3.png";
										//treeText1= loadTexture(path,3);
										//glBindTexture(GL_TEXTURE_2D, texture5);
										glBegin(GL_TRIANGLES);
											//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
											//I subtract 1 because the index start from 0 in C++
											
											glNormal3f(levelLoad.rSNormals[levelLoad.rSFaces[i]->facenum-1]->x,levelLoad.rSNormals[levelLoad.rSFaces[i]->facenum-1]->y,levelLoad.rSNormals[levelLoad.rSFaces[i]->facenum-1]->z);
											//draw the faces
											glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.rSVert[levelLoad.rSFaces[i]->faces[0]-1]->x,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[0]-1]->y,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[0]-1]->z);
											glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.rSVert[levelLoad.rSFaces[i]->faces[1]-1]->x,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[1]-1]->y,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[1]-1]->z);
											glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.rSVert[levelLoad.rSFaces[i]->faces[2]-1]->x,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[2]-1]->y,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[2]-1]->z);
											//glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.rSVert[levelLoad.rSFaces[i]->faces[3]-1]->x,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[3]-1]->y,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[3]-1]->z);
										glEnd();	
										//char path2[] = "Images/Plants/tree1.png";
										////treeText1 = loadTexture(path2, 3);
										//glBindTexture(GL_TEXTURE_2D, texture3);
									}
							}
				}
					
				glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
      glEnable(GL_DEPTH_TEST);
      /* Now, only render where stencil is set to 1. */
      glStencilFunc(GL_EQUAL, 1, 0xffffffff);  /* draw if ==1 */
      glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
	  glPushMatrix();
	 // glRotatef(15,1,0, 0);
		//glTranslatef(0,10,50);
	 // glRotatef(playerRZ,1,0,0);
	 // glRotatef(playerR,0,0,1);
	  //glTranslatef(0,10,-50);
	  glScalef(1.0, -1.0, 1.0);
	 /* glLightfv(GL_LIGHT0, GL_POSITION, left_light_position);
			glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
			glLightfv(GL_LIGHT1, GL_POSITION, right_light_position);
			glLightfv(GL_LIGHT1, GL_SPECULAR, white_light);*/
	  glEnable(GL_NORMALIZE);
      glCullFace(GL_FRONT);
	  //if(angle < 270 && angle > 0){
		  
		//  glTranslatef(0, (2.3) + ((-py)+(reflectCounter*2)) + reflectSkew, pz);
		//  glRotatef(playerRZ,1,0,0);
		//  glTranslatef(0, -((2.3) + ((-py)+(reflectCounter*2)) + reflectSkew), -pz);
		//  glTranslatef(px, (2.3) + ((-py)+(reflectCounter*2)) + reflectSkew, 0);
		//  glRotatef(playerR,0,0,1);
		//  glTranslatef(-px, -((2.3) + ((-py)+(reflectCounter*2)) + reflectSkew), 0);
		//  glTranslatef(px, (2.3) + ((-py)+(reflectCounter*2)) + reflectSkew, pz);
	 
	   for(int i = 0; i < onlineCounter; i++){
			
			glTranslatef(onlineX[i], onlineY[i], onlineZ[i]);
			glTranslatef(0,-0.7,0);
			//glTranslatef(0, (2.35) +((-onlineY[i])+(reflectCounter*2)) + reflectSkew, 0);
			glRotatef((-onlineAngle[i])-90, 0,1,0);
			obj.drawTails(onlineFrameCounter[i]);
			
			
			
			glRotatef((onlineAngle[i])+90, 0,1,0);
			//glTranslatef(0, -((2.35) +((-onlineY[i])+(reflectCounter*2)) + reflectSkew),0);
			glTranslatef(0,0.7,0);
			glTranslatef(-onlineX[i], -onlineY[i], -onlineZ[i]);
			//glPopMatrix();
			//glPushMatrix();
		}
	 
	 glTranslatef(px, (2.35) +((-py)+(reflectCounter*2)) + reflectSkew, pz);
	glRotatef((-angle)-90, 0,1,0);
		glTranslatef(0,-0.7,0);
		obj.drawTails(frameCounter);
	  glPopMatrix();
	 
			//glCallList(marble);
		
				
		//glDisable(GL_TEXTURE_2D);
			glDisable(GL_NORMALIZE); //alex
      glCullFace(GL_BACK);
	  glPushMatrix();
	  
	  //glEnable(GL_NORMALIZE);
      //glCullFace(GL_FRONT);

	  if(!foundCrystal){
					glTranslatef(levelLoad.fVert[levelLoad.fFaces[0]->faces[0]-1]->x, 0,levelLoad.fVert[levelLoad.fFaces[0]->faces[0]-1]->z);
					glRotatef(coinSpin,0,1,0);
					glTranslatef(-levelLoad.fVert[levelLoad.fFaces[0]->faces[0]-1]->x, 0, -levelLoad.fVert[levelLoad.fFaces[0]->faces[0]-1]->z);
					glTranslatef(0,-4,0);
					for(int i=0;i< levelLoad.fFaces.size();i++){	
						
						if(levelLoad.fFaces[i]->four){	//if it's a quad draw a quad

							//	std::cout << "here 1" << std::endl;
							glBegin(GL_QUADS);
								//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
								//I subtract 1 because the index start from 0 in C++
								
								glNormal3f(levelLoad.fNormals[levelLoad.fFaces[i]->facenum-1]->x,levelLoad.fNormals[levelLoad.fFaces[i]->facenum-1]->y,levelLoad.fNormals[levelLoad.fFaces[i]->facenum-1]->z);
							//draw the faces
								glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.fVert[levelLoad.fFaces[i]->faces[0]-1]->x ,levelLoad.fVert[levelLoad.fFaces[i]->faces[0]-1]->y ,levelLoad.fVert[levelLoad.fFaces[i]->faces[0]-1]->z );
								glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.fVert[levelLoad.fFaces[i]->faces[1]-1]->x ,levelLoad.fVert[levelLoad.fFaces[i]->faces[1]-1]->y ,levelLoad.fVert[levelLoad.fFaces[i]->faces[1]-1]->z );
								glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.fVert[levelLoad.fFaces[i]->faces[2]-1]->x ,levelLoad.fVert[levelLoad.fFaces[i]->faces[2]-1]->y ,levelLoad.fVert[levelLoad.fFaces[i]->faces[2]-1]->z );
								glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.fVert[levelLoad.fFaces[i]->faces[3]-1]->x ,levelLoad.fVert[levelLoad.fFaces[i]->faces[3]-1]->y ,levelLoad.fVert[levelLoad.fFaces[i]->faces[3]-1]->z );
							glEnd();

						}else{
						//	std::cout << cVertex[levelLoad.fFaces[i]->faces[0]-1]->x << cVertex[levelLoad.fFaces[i]->faces[0]-1]->y << cVertex[levelLoad.fFaces[i]->faces[0]-1]->z << std::endl;
							//std::cout << vertex[levelLoad.fFaces[i]->faces[1]-1]->x << vertex[levelLoad.fFaces[i]->faces[1]-1]->y << vertex[levelLoad.fFaces[i]->faces[1]-1]->z << std::endl;
							//std::cout << vertex[levelLoad.fFaces[i]->faces[2]-1]->x << vertex[levelLoad.fFaces[i]->faces[2]-1]->y << vertex[levelLoad.fFaces[i]->faces[2]-1]->z << std::endl;
							glBegin(GL_TRIANGLES);
								//glBindTexture(GL_TEXTURE_2D, texture3);
								glNormal3f(levelLoad.fNormals[levelLoad.fFaces[i]->facenum-1]->x,levelLoad.fNormals[levelLoad.fFaces[i]->facenum-1]->y,levelLoad.fNormals[levelLoad.fFaces[i]->facenum-1]->z);
								glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.fVert[levelLoad.fFaces[i]->faces[0]-1]->x ,levelLoad.fVert[levelLoad.fFaces[i]->faces[0]-1]->y ,levelLoad.fVert[levelLoad.fFaces[i]->faces[0]-1]->z );
								glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.fVert[levelLoad.fFaces[i]->faces[1]-1]->x ,levelLoad.fVert[levelLoad.fFaces[i]->faces[1]-1]->y ,levelLoad.fVert[levelLoad.fFaces[i]->faces[1]-1]->z );
								glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.fVert[levelLoad.fFaces[i]->faces[2]-1]->x ,levelLoad.fVert[levelLoad.fFaces[i]->faces[2]-1]->y ,levelLoad.fVert[levelLoad.fFaces[i]->faces[2]-1]->z );
							glEnd();
						}
					}
				}

	 // }
			//glCullFace(GL_BACK);
			glPopMatrix();
			
			glDisable(GL_LIGHTING);
				glPushMatrix();
	  float length = 100;
	float height = 100;
	float width = 100;
				//glTranslatef(px -5, py -1, pz -5);
				glEnable(GL_TEXTURE_2D);
				glDisable(GL_LIGHTING);
				
					glPushMatrix();
					glRotatef(180,1,0,0);
					glRotatef(180,0,1,0);
					glRotatef(180,0,0,1);
					glBindTexture(GL_TEXTURE_2D, skyB);
					glTranslatef(0,-(height*2), 0);
					glBegin(GL_QUADS);
				
				
					//glNormal3f(0.0f, 1.0f, 0.0f);
					glTexCoord2d(1.0f, 0.0f); glVertex3f( width, height, -length); // Top Right Of The Quad (Top)
					glTexCoord2d(1.0f, 1.0f); glVertex3f(-width, height, -length); // Top Left Of The Quad (Top)
					glTexCoord2d(0.0, 1.0f); glVertex3f(-width, height, length); // Bottom Left Of The Quad (Top)
					glTexCoord2d(0.0, 0.0f); glVertex3f( width, height, length); // Bottom Right Of The Quad (Top)
					glEnd();
					
				glPopMatrix();
				
					glPushMatrix();
					//glRotatef(180,1,0,0);
					glTranslatef(0,-(height*2), 0);
					glRotatef(180,0,1,0);
					glRotatef(180,0,0,1);
					//glRotatef(180, 0,1, 0);
					glBindTexture(GL_TEXTURE_2D, skyT);
					glBegin(GL_QUADS);
					//glNormal3f(0.0f, 1.0f, 0.0f);
					glTexCoord2d(1.0f, 0.0f); glVertex3f( width, height, -length); // Top Right Of The Quad (Top)
					glTexCoord2d(1.0f, 1.0f); glVertex3f(-width, height, -length); // Top Left Of The Quad (Top)
					glTexCoord2d(0.0, 1.0f); glVertex3f(-width, height, length); // Bottom Left Of The Quad (Top)
					glTexCoord2d(0.0, 0.0f); glVertex3f( width, height, length); // Bottom Right Of The Quad (Top)
					glEnd();
					
					
					glPopMatrix();
					
					
					//glRotatef(180,1,0,0);
					glPushMatrix();
					glRotatef(180,0,0,1);
					glRotatef(180,0,1,0);
					glRotatef(180,0,0,1);
					glTranslatef((height*2),0, 0);
					glBindTexture(GL_TEXTURE_2D, skyL);
					glBegin(GL_QUADS);
					//glNormal3f(-1.0f, 0.0f, 0.0f);
					glTexCoord2d(1.0f, 0.0f); glVertex3f(-width, height, -length); // Top Right Of The Quad (Left)
					glTexCoord2d(1.0f, 1.0f); glVertex3f(-width, -height, -length); // Top Left Of The Quad (Left)
					glTexCoord2d(0.0f, 1.0f); glVertex3f(-width, -height, length); // Bottom Left Of The Quad (Left)
					glTexCoord2d(0.0f, 0.0f); glVertex3f(-width, height, length); // Bottom Right Of The Quad (Left)
					glEnd();
					glPopMatrix();
				
					
					glPushMatrix();
					glRotatef(180,0,0,1);
					glRotatef(180,0,1,0);
					glRotatef(180,0,0,1);
					glTranslatef(-(height*2),0, 0);
					glBindTexture(GL_TEXTURE_2D, skyR);
					glBegin(GL_QUADS);
					//glNormal3f(1.0f, 0.0f, 0.0f);
					glTexCoord2d(0.0f, 0.0f); glVertex3f( width, height, -length); // Top Right Of The Quad (Right)
					glTexCoord2d(1.0f, 0.0f); glVertex3f( width, height, length); // Top Left Of The Quad (Right)
					glTexCoord2d(1.0f, 1.0f); glVertex3f( width, -height, length); // Bottom Left Of The Quad (Right)
					glTexCoord2d(0.0f, 1.0f); glVertex3f( width, -height, -length); // Bottom Right Of The Quad (Right)
					glEnd();
					
					glPopMatrix();
					
					
				


					glPushMatrix();
					glBindTexture(GL_TEXTURE_2D, skyF);
					glRotatef(180,0,1,0);
					glRotatef(180,0,0,1);
					glTranslatef(0,0, (height*2));
					
					glBegin(GL_QUADS);
					//glNormal3f(0.0f, 0.0f, 1.0f);
					glTexCoord2d(0.0f, 1.0f); glVertex3f( width, -height, -length); // Bottom Left Of The Quad (Back)
					glTexCoord2d(1.0f, 1.0f); glVertex3f(-width, -height, -length); // Bottom Right Of The Quad (Back)
					glTexCoord2d(1.0f, 0.0f); glVertex3f(-width, height, -length); // Top Right Of The Quad (Back)
					glTexCoord2d(0.0f, 0.0f); glVertex3f( width, height, -length); // Top Left Of The Quad (Back)
					glEnd();
					glPopMatrix();
					
					glPushMatrix();
					//glRotatef(180,0,0,1);
					glRotatef(180,0,1,0);
					glRotatef(180,0,0,1);
					glTranslatef(0,0, -(height*2));
					glBindTexture(GL_TEXTURE_2D, skyBk);
					
					glBegin(GL_QUADS);
					//glNormal3f(0.0f, 0.0f, -1.0f);
					glTexCoord2d(0.0f, 0.0f); glVertex3f( width, height, length); // Top Right Of The Quad (Front)
					glTexCoord2d(1.0f, 0.0f); glVertex3f(-width, height, length); // Top Left Of The Quad (Front)
					glTexCoord2d(1.0f, 1.0f); glVertex3f(-width, -height, length); // Bottom Left Of The Quad (Front)
					glTexCoord2d(0.0f, 1.0f); glVertex3f( width, -height, length); // Bottom Right Of The Quad (Front)
					glEnd();
					
					glPopMatrix();
					
					
					glDisable(GL_TEXTURE_2D);
					glEnable(GL_LIGHTING);
				

					//glDisable(GL_TEXTURE_2D);
					glPushMatrix();
				
				
			for(int i = 0; i < bombCount; i++){
					glPushMatrix();
					glTranslatef(bombX[i], bombY[i], bombZ[i]);
					glRotatef(180,1,0,0);
					if(rewindTime){
						glRotatef((-bombAngle), 0,1,0);
					}else{
						glRotatef((bombAngle), 0,1,0);
					}
					//glRotatef(180, 1,0,0);
					glTranslatef(-bombX[i], 0, -bombZ[i]);
					
					glTranslatef(0,1/bombY[i],0);
					obj.drawBomb(bombFrameCounter, bombX[i],bombY[i],bombZ[i], bombAngle);
					glPopMatrix();
				}
			
			//glPopMatrix();
			//glPushMatrix();
			for(int i = 0; i < sqCount; i++){
					glPushMatrix();
					glTranslatef(squX[i], squY[i], squZ[i]);
					glRotatef(180,1,0,0);
					if(rewindTime){
						glRotatef((-squAngle[i]), 0,1,0);
					}else{
						glRotatef((squAngle[i]), 0,1,0);
					}
				
					//glRotatef(90, 0,0,1);
					//glRotatef(180, 1,0,0);
					glTranslatef(-squX[i], 0, -squZ[i]);
					glTranslatef(0,3/squY[i],0);
					glTranslatef(squX[i], 0, squZ[i]);
					if (squHit[i]){
					//	kingH.DrawGLScene(false);
					}else if(squOldX[i] != squX[i] || squOldZ[i] != squZ[i]){
					//	kingR.DrawGLScene(false);
					}else{
					//	kingI.DrawGLScene(false);
						
					}
					glPopMatrix();
				}
			//glPopMatrix();
	  
	  glDisable(GL_STENCIL_TEST);
	  
	  glEnable(GL_BLEND);
	  glDepthMask (GL_TRUE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   // glColor4f(0.7, 0.0, 0.0, 0.3);
	//glDisable(GL_LIGHTING);

	for(int i=0;i< levelLoad.pFaces.size();i++){	
						if((i+1) % 6 == 0){	
								if(levelLoad.pFaces[i]->four){	//if it's a quad draw a quad
									//if((i+1) % 6 != 0){
									//	std::cout << "here 1" << std::endl;
										glBegin(GL_QUADS);
											//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
											//I subtract 1 because the index start from 0 in C++
											
											glNormal3f(levelLoad.pNormals[levelLoad.pFaces[i]->facenum-1]->x,levelLoad.pNormals[levelLoad.pFaces[i]->facenum-1]->y,levelLoad.pNormals[levelLoad.pFaces[i]->facenum-1]->z);
											//draw the faces
											glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.pVert[levelLoad.pFaces[i]->faces[0]-1]->x,levelLoad.pVert[levelLoad.pFaces[i]->faces[0]-1]->y,levelLoad.pVert[levelLoad.pFaces[i]->faces[0]-1]->z);
											glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.pVert[levelLoad.pFaces[i]->faces[1]-1]->x,levelLoad.pVert[levelLoad.pFaces[i]->faces[1]-1]->y,levelLoad.pVert[levelLoad.pFaces[i]->faces[1]-1]->z);
											glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.pVert[levelLoad.pFaces[i]->faces[2]-1]->x,levelLoad.pVert[levelLoad.pFaces[i]->faces[2]-1]->y,levelLoad.pVert[levelLoad.pFaces[i]->faces[2]-1]->z);
											glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.pVert[levelLoad.pFaces[i]->faces[3]-1]->x,levelLoad.pVert[levelLoad.pFaces[i]->faces[3]-1]->y,levelLoad.pVert[levelLoad.pFaces[i]->faces[3]-1]->z);
										glEnd();
									}else{
										
										//char path[] = "Images/block3.png";
										//treeText1= loadTexture(path,3);
										//glBindTexture(GL_TEXTURE_2D, texture5);
										glBegin(GL_TRIANGLES);
											//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
											//I subtract 1 because the index start from 0 in C++
											
											glNormal3f(levelLoad.pNormals[levelLoad.pFaces[i]->facenum-1]->x,levelLoad.pNormals[levelLoad.pFaces[i]->facenum-1]->y,levelLoad.pNormals[levelLoad.pFaces[i]->facenum-1]->z);
											//draw the faces
											glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.pVert[levelLoad.pFaces[i]->faces[0]-1]->x,levelLoad.pVert[levelLoad.pFaces[i]->faces[0]-1]->y,levelLoad.pVert[levelLoad.pFaces[i]->faces[0]-1]->z);
											glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.pVert[levelLoad.pFaces[i]->faces[1]-1]->x,levelLoad.pVert[levelLoad.pFaces[i]->faces[1]-1]->y,levelLoad.pVert[levelLoad.pFaces[i]->faces[1]-1]->z);
											glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.pVert[levelLoad.pFaces[i]->faces[2]-1]->x,levelLoad.pVert[levelLoad.pFaces[i]->faces[2]-1]->y,levelLoad.pVert[levelLoad.pFaces[i]->faces[2]-1]->z);
											//glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.pVert[levelLoad.pFaces[i]->faces[3]-1]->x,levelLoad.pVert[levelLoad.pFaces[i]->faces[3]-1]->y,levelLoad.pVert[levelLoad.pFaces[i]->faces[3]-1]->z);
										glEnd();	
										//char path2[] = "Images/Plants/tree1.png";
										////treeText1 = loadTexture(path2, 3);
										//glBindTexture(GL_TEXTURE_2D, texture3);
									}
							}
				}	
				for(int i=0;i< levelLoad.rSFaces.size();i++){	
						if((i+1) % 6 == 0){	
								if(levelLoad.rSFaces[i]->four){	//if it's a quad draw a quad
									//if((i+1) % 6 != 0){
									//	std::cout << "here 1" << std::endl;
										glBegin(GL_QUADS);
											//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
											//I subtract 1 because the index start from 0 in C++
											
											glNormal3f(levelLoad.rSNormals[levelLoad.rSFaces[i]->facenum-1]->x,levelLoad.rSNormals[levelLoad.rSFaces[i]->facenum-1]->y,levelLoad.rSNormals[levelLoad.rSFaces[i]->facenum-1]->z);
											//draw the faces
											glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.rSVert[levelLoad.rSFaces[i]->faces[0]-1]->x,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[0]-1]->y,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[0]-1]->z);
											glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.rSVert[levelLoad.rSFaces[i]->faces[1]-1]->x,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[1]-1]->y,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[1]-1]->z);
											glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.rSVert[levelLoad.rSFaces[i]->faces[2]-1]->x,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[2]-1]->y,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[2]-1]->z);
											glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.rSVert[levelLoad.rSFaces[i]->faces[3]-1]->x,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[3]-1]->y,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[3]-1]->z);
										glEnd();
									}else{
										
										//char path[] = "Images/block3.png";
										//treeText1= loadTexture(path,3);
										//glBindTexture(GL_TEXTURE_2D, texture5);
										glBegin(GL_TRIANGLES);
											//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
											//I subtract 1 because the index start from 0 in C++
											
											glNormal3f(levelLoad.rSNormals[levelLoad.rSFaces[i]->facenum-1]->x,levelLoad.rSNormals[levelLoad.rSFaces[i]->facenum-1]->y,levelLoad.rSNormals[levelLoad.rSFaces[i]->facenum-1]->z);
											//draw the faces
											glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.rSVert[levelLoad.rSFaces[i]->faces[0]-1]->x,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[0]-1]->y,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[0]-1]->z);
											glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.rSVert[levelLoad.rSFaces[i]->faces[1]-1]->x,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[1]-1]->y,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[1]-1]->z);
											glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.rSVert[levelLoad.rSFaces[i]->faces[2]-1]->x,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[2]-1]->y,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[2]-1]->z);
											//glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.rSVert[levelLoad.rSFaces[i]->faces[3]-1]->x,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[3]-1]->y,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[3]-1]->z);
										glEnd();	
										//char path2[] = "Images/Plants/tree1.png";
										////treeText1 = loadTexture(path2, 3);
										//glBindTexture(GL_TEXTURE_2D, texture3);
									}
							}
				}
    glDisable(GL_BLEND);
	for(int i=0;i< levelLoad.rSFaces.size();i++){	
						//if((i+1) % 6 == 0){	
								if(levelLoad.rSFaces[i]->four){	//if it's a quad draw a quad
									//if((i+1) % 6 != 0){
									//	std::cout << "here 1" << std::endl;
										glBegin(GL_QUADS);
											//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
											//I subtract 1 because the index start from 0 in C++
											
											glNormal3f(levelLoad.rSNormals[levelLoad.rSFaces[i]->facenum-1]->x,levelLoad.rSNormals[levelLoad.rSFaces[i]->facenum-1]->y,levelLoad.rSNormals[levelLoad.rSFaces[i]->facenum-1]->z);
											//draw the faces
											glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.rSVert[levelLoad.rSFaces[i]->faces[0]-1]->x,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[0]-1]->y,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[0]-1]->z);
											glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.rSVert[levelLoad.rSFaces[i]->faces[1]-1]->x,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[1]-1]->y,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[1]-1]->z);
											glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.rSVert[levelLoad.rSFaces[i]->faces[2]-1]->x,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[2]-1]->y,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[2]-1]->z);
											glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.rSVert[levelLoad.rSFaces[i]->faces[3]-1]->x,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[3]-1]->y,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[3]-1]->z);
										glEnd();
									}else{
										
										//char path[] = "Images/block3.png";
										//treeText1= loadTexture(path,3);
										//glBindTexture(GL_TEXTURE_2D, texture5);
										glBegin(GL_TRIANGLES);
											//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
											//I subtract 1 because the index start from 0 in C++
											
											glNormal3f(levelLoad.rSNormals[levelLoad.rSFaces[i]->facenum-1]->x,levelLoad.rSNormals[levelLoad.rSFaces[i]->facenum-1]->y,levelLoad.rSNormals[levelLoad.rSFaces[i]->facenum-1]->z);
											//draw the faces
											glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.rSVert[levelLoad.rSFaces[i]->faces[0]-1]->x,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[0]-1]->y,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[0]-1]->z);
											glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.rSVert[levelLoad.rSFaces[i]->faces[1]-1]->x,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[1]-1]->y,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[1]-1]->z);
											glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.rSVert[levelLoad.rSFaces[i]->faces[2]-1]->x,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[2]-1]->y,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[2]-1]->z);
										//	glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.rSVert[levelLoad.rSFaces[i]->faces[3]-1]->x,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[3]-1]->y,levelLoad.rSVert[levelLoad.rSFaces[i]->faces[3]-1]->z);
										glEnd();	
										//char path2[] = "Images/Plants/tree1.png";
										////treeText1 = loadTexture(path2, 3);
										//glBindTexture(GL_TEXTURE_2D, texture3);
									}
							//}
				}
	for(int i=0;i< levelLoad.pFaces.size();i++){	
						//if((i+1) % 6 == 0){	
								if(levelLoad.pFaces[i]->four){	//if it's a quad draw a quad
									//if((i+1) % 6 != 0){
									//	std::cout << "here 1" << std::endl;
										glBegin(GL_QUADS);
											//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
											//I subtract 1 because the index start from 0 in C++
											
											glNormal3f(levelLoad.pNormals[levelLoad.pFaces[i]->facenum-1]->x,levelLoad.pNormals[levelLoad.pFaces[i]->facenum-1]->y,levelLoad.pNormals[levelLoad.pFaces[i]->facenum-1]->z);
											//draw the faces
											glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.pVert[levelLoad.pFaces[i]->faces[0]-1]->x,levelLoad.pVert[levelLoad.pFaces[i]->faces[0]-1]->y,levelLoad.pVert[levelLoad.pFaces[i]->faces[0]-1]->z);
											glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.pVert[levelLoad.pFaces[i]->faces[1]-1]->x,levelLoad.pVert[levelLoad.pFaces[i]->faces[1]-1]->y,levelLoad.pVert[levelLoad.pFaces[i]->faces[1]-1]->z);
											glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.pVert[levelLoad.pFaces[i]->faces[2]-1]->x,levelLoad.pVert[levelLoad.pFaces[i]->faces[2]-1]->y,levelLoad.pVert[levelLoad.pFaces[i]->faces[2]-1]->z);
											glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.pVert[levelLoad.pFaces[i]->faces[3]-1]->x,levelLoad.pVert[levelLoad.pFaces[i]->faces[3]-1]->y,levelLoad.pVert[levelLoad.pFaces[i]->faces[3]-1]->z);
										glEnd();
									}else{
										
										//char path[] = "Images/block3.png";
										//treeText1= loadTexture(path,3);
										//glBindTexture(GL_TEXTURE_2D, texture5);
										glBegin(GL_TRIANGLES);
											//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
											//I subtract 1 because the index start from 0 in C++
											
											glNormal3f(levelLoad.pNormals[levelLoad.pFaces[i]->facenum-1]->x,levelLoad.pNormals[levelLoad.pFaces[i]->facenum-1]->y,levelLoad.pNormals[levelLoad.pFaces[i]->facenum-1]->z);
											//draw the faces
											glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.pVert[levelLoad.pFaces[i]->faces[0]-1]->x,levelLoad.pVert[levelLoad.pFaces[i]->faces[0]-1]->y,levelLoad.pVert[levelLoad.pFaces[i]->faces[0]-1]->z);
											glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.pVert[levelLoad.pFaces[i]->faces[1]-1]->x,levelLoad.pVert[levelLoad.pFaces[i]->faces[1]-1]->y,levelLoad.pVert[levelLoad.pFaces[i]->faces[1]-1]->z);
											glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.pVert[levelLoad.pFaces[i]->faces[2]-1]->x,levelLoad.pVert[levelLoad.pFaces[i]->faces[2]-1]->y,levelLoad.pVert[levelLoad.pFaces[i]->faces[2]-1]->z);
											//glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.pVert[levelLoad.pFaces[i]->faces[3]-1]->x,levelLoad.pVert[levelLoad.pFaces[i]->faces[3]-1]->y,levelLoad.pVert[levelLoad.pFaces[i]->faces[3]-1]->z);
										glEnd();	
										//char path2[] = "Images/Plants/tree1.png";
										////treeText1 = loadTexture(path2, 3);
										//glBindTexture(GL_TEXTURE_2D, texture3);
									}
						//	}
				}
//cout << "finsihed" << endl;
}
string name = "";
void deciferP(){
	vector<string> coords;
	//cout << clientLine << endl;
	
		
	
	char delimiter = '/';
	string acc = "";
	
	if(clientLine.find("ROTATE") == std::string::npos && clientLine.find("Q") == std::string::npos){
		
		for(int i = 0; i < clientLine.size(); i++)
		{
			if(clientLine[i] == delimiter)
			{
				coords.push_back(acc);
				acc = "";
			}
			else
			{
				acc += clientLine[i];
			}
		}
		for(int v = 0; v < coords.size(); v++){
			if(count_semi(coords[v]) == 6){
			char delimiter = ':';
			acc = "";
			vector<string> str;
			//cout << coords[v] << endl;
			for(int i = 0; i < coords[v].size(); i++)
			{
				if(coords[v][i] == delimiter)
				{
					str.push_back(acc);
					acc = "";
				}
				else
				{
					acc += coords[v][i];
				}
			}
			//if(!name.compare(str[0]) || !cName.compare(str[0])){
			//cout << input << endl;
			//cout << str[0] << " " << str[1] << " "<< str[2] << endl;// " " <<str[3] << endl;
			//for(int i = 0; i < coords.size(); i++){
				if(str[0].find("COOP") != std::string::npos || str[0].find("PLAYER") != std::string::npos){
					if(str[0].find("HELLO") == std::string::npos){
						if(str[0].compare(cName) != 0){
							if(str[0].compare(name) != 0 && str[0].find("FINISHED") == std::string::npos){
								
								//cout << "the name" << name << endl;
							bool foundPlayer = false;
							int playerI;
						//if(str[0].compare(name) !=0 && str[0].compare(cName) != 0){
							for(int c = 0; c < onlineCounter; c++){
								if(str[0].compare(onlineName[c]) ==0){
									foundPlayer = true;
									playerI = c;
								}
							}
							if(foundPlayer ==1){
								onlineX[playerI] = strtof((str[1]).c_str(),0);
								onlineY[playerI] = strtof((str[2]).c_str(),0);
								onlineZ[playerI] = strtof((str[3]).c_str(),0);
								onlineAngle[playerI] = strtof((str[4]).c_str(),0);
								onlineCurrentAnimation[playerI] = str[5];
								//cout << onlineCurrentAnimation[playerI] << endl;
								//cout << "updating" << endl;
								//cout << onlineName[playerI] << " ";
								//cout << str[0] << str[1] << str[2] << "updating" << endl;
										//cout << "coords sent" << endl;
										//onlineRotation[i] = std::stof(str[3]);
							}else{
								onlineName[onlineCounter] = str[0];
								onlineX[onlineCounter] = strtof((str[1]).c_str(),0);
								onlineY[onlineCounter] = strtof((str[2]).c_str(),0);
								onlineZ[onlineCounter] = strtof((str[3]).c_str(),0);
								onlineAngle[onlineCounter] = strtof((str[4]).c_str(),0);
								onlineCurrentAnimation[onlineCounter] = str[5];
										//onlineRotation[onlineCounter] = std::stof(str[3]);
								if(onlineCounter < 10){
									onlineCounter++;
								}
								cout << "adding new player " << str[0]<<  endl;
							}
						}
					}
				}
				}
			//}
			}
			//}
			//}
		}
	}else if(clientLine.find("Q") != std::string::npos){
		completeFinished = 1;
	}
    //boost::split(coord, clientLine, boost::is_any_of("-"));
	//for(int v = 0; v < sizeof(coord); v++){
	//cout << input << endl;
	//cout << coord[v] << endl;
	//boost::split(result, coord[v], boost::is_any_of(":"));
	/*
	if(!name.compare(result[0]) || !cName.compare(result[0])){
		//cout << input << endl;
		for(int i = 0; i < onlineCounter; i++){
			if(result[0].compare(onlineName[i])){
				onlineX[i] = std::stof(result[1]);
				onlineY[i] = std::stof(result[2]);
				onlineRotation[i] = std::stof(result[3]);
			}else{
				onlineName[onlineCounter] = result[0];
				onlineX[onlineCounter] = std::stof(result[1]);
				onlineY[onlineCounter] = std::stof(result[2]);
				onlineRotation[onlineCounter] = std::stof(result[3]);
				onlineCounter++;
				i = 10;
			}
		}
	}*/
}

GLfloat v[8][3];  /* Will be filled in with X,Y,Z vertexes. */

void loadCrystals(level &levelLoad){
	
	for(int z = 0; z < 100; z++){
		glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, pauseTexture);
		if(pauseSpawnX[z] != -1000){
			if(shownPause[z]){
				for(int i=0;i< levelLoad.paFaces.size();i++){
						//if((i+1) % 6 == 0){	xcq	
						//if(levelLoad.paVert[levelLoad.paFaces[i]->faces[0]-1]->y < py){

								if(levelLoad.paFaces[i]->four){	//if it's a quad draw a quad
									//if((i+1) % 6 != 0){
									//	std::cout << "here 1" << std::endl;
										glBegin(GL_QUADS);
											//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
											//I subtract 1 because the index start from 0 in C++
											
											glNormal3f(levelLoad.paNormals[levelLoad.paFaces[i]->facenum-1]->x + pauseSkewX[z],levelLoad.paNormals[levelLoad.paFaces[i]->facenum-1]->y,levelLoad.paNormals[levelLoad.paFaces[i]->facenum-1]->z + pauseSkewZ[z]);
											//draw the faces
											glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.paVert[levelLoad.paFaces[i]->faces[0]-1]->x + pauseSkewX[z],levelLoad.paVert[levelLoad.paFaces[i]->faces[0]-1]->y + pauseSkewY[z],levelLoad.paVert[levelLoad.paFaces[i]->faces[0]-1]->z + pauseSkewZ[z]);
											glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.paVert[levelLoad.paFaces[i]->faces[1]-1]->x + pauseSkewX[z],levelLoad.paVert[levelLoad.paFaces[i]->faces[1]-1]->y + pauseSkewY[z],levelLoad.paVert[levelLoad.paFaces[i]->faces[1]-1]->z + pauseSkewZ[z]);
											glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.paVert[levelLoad.paFaces[i]->faces[2]-1]->x + pauseSkewX[z],levelLoad.paVert[levelLoad.paFaces[i]->faces[2]-1]->y + pauseSkewY[z],levelLoad.paVert[levelLoad.paFaces[i]->faces[2]-1]->z + pauseSkewZ[z]);
											glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.paVert[levelLoad.paFaces[i]->faces[3]-1]->x + pauseSkewX[z],levelLoad.paVert[levelLoad.paFaces[i]->faces[3]-1]->y + pauseSkewY[z],levelLoad.paVert[levelLoad.paFaces[i]->faces[3]-1]->z + pauseSkewZ[z]);
										glEnd();
									}else{
										
										//char path[] = "Images/block3.png";
										//treeText1= loadTexture(path,3);
										//glBindTexture(GL_TEXTURE_2D, texture5);
										glBegin(GL_QUADS);
											//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
											//I subtract 1 because the index start from 0 in C++
											
											glNormal3f(levelLoad.paNormals[levelLoad.paFaces[i]->facenum-1]->x + pauseSkewX[z],levelLoad.paNormals[levelLoad.paFaces[i]->facenum-1]->y,levelLoad.paNormals[levelLoad.paFaces[i]->facenum-1]->z + pauseSkewZ[z]);
											//draw the faces
											glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.paVert[levelLoad.paFaces[i]->faces[0]-1]->x + pauseSkewX[z],levelLoad.paVert[levelLoad.paFaces[i]->faces[0]-1]->y + pauseSkewY[z],levelLoad.paVert[levelLoad.paFaces[i]->faces[0]-1]->z + pauseSkewZ[z]);
											glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.paVert[levelLoad.paFaces[i]->faces[1]-1]->x + pauseSkewX[z],levelLoad.paVert[levelLoad.paFaces[i]->faces[1]-1]->y + pauseSkewY[z],levelLoad.paVert[levelLoad.paFaces[i]->faces[1]-1]->z + pauseSkewZ[z]);
											glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.paVert[levelLoad.paFaces[i]->faces[2]-1]->x + pauseSkewX[z],levelLoad.paVert[levelLoad.paFaces[i]->faces[2]-1]->y + pauseSkewY[z],levelLoad.paVert[levelLoad.paFaces[i]->faces[2]-1]->z + pauseSkewZ[z]);
											glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.paVert[levelLoad.paFaces[i]->faces[3]-1]->x + pauseSkewX[z],levelLoad.paVert[levelLoad.paFaces[i]->faces[3]-1]->y + pauseSkewY[z],levelLoad.paVert[levelLoad.paFaces[i]->faces[3]-1]->z + pauseSkewZ[z]);
										glEnd();	
										//char path2[] = "Images/Plants/tree1.png";
										////treeText1 = loadTexture(path2, 3);
										//glBindTexture(GL_TEXTURE_2D, texture3);
									}
							}
					}
				}
		}
		glPopMatrix();
		glBindTexture(GL_TEXTURE_2D, forwardTexture);	
			
			for(int z = 0; z < 100; z++){
				if(forwardSpawnX[z] != -1000){
					if(shownForward[z]){
						for(int i=0;i< levelLoad.frFaces.size();i++){
						//if((i+1) % 6 == 0){	
						//if(levelLoad.frVert[levelLoad.frFaces[i]->faces[0]-1]->y < py){

								if(levelLoad.frFaces[i]->four){	//if it's a quad draw a quad
									//if((i+1) % 6 != 0){
									//	std::cout << "here 1" << std::endl;
										glBegin(GL_QUADS);
											//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
											//I subtract 1 because the index start from 0 in C++
											
											glNormal3f(levelLoad.frNormals[levelLoad.frFaces[i]->facenum-1]->x + forwardSkewX[z],levelLoad.frNormals[levelLoad.frFaces[i]->facenum-1]->y,levelLoad.frNormals[levelLoad.frFaces[i]->facenum-1]->z + forwardSkewZ[z]);
											//draw the faces
											glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.frVert[levelLoad.frFaces[i]->faces[0]-1]->x + forwardSkewX[z],levelLoad.frVert[levelLoad.frFaces[i]->faces[0]-1]->y + forwardSkewY[z],levelLoad.frVert[levelLoad.frFaces[i]->faces[0]-1]->z + forwardSkewZ[z]);
											glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.frVert[levelLoad.frFaces[i]->faces[1]-1]->x + forwardSkewX[z],levelLoad.frVert[levelLoad.frFaces[i]->faces[1]-1]->y + forwardSkewY[z],levelLoad.frVert[levelLoad.frFaces[i]->faces[1]-1]->z + forwardSkewZ[z]);
											glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.frVert[levelLoad.frFaces[i]->faces[2]-1]->x + forwardSkewX[z],levelLoad.frVert[levelLoad.frFaces[i]->faces[2]-1]->y + forwardSkewY[z],levelLoad.frVert[levelLoad.frFaces[i]->faces[2]-1]->z + forwardSkewZ[z]);
											glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.frVert[levelLoad.frFaces[i]->faces[3]-1]->x + forwardSkewX[z],levelLoad.frVert[levelLoad.frFaces[i]->faces[3]-1]->y + forwardSkewY[z],levelLoad.frVert[levelLoad.frFaces[i]->faces[3]-1]->z + forwardSkewZ[z]);
										glEnd();
									}else{
										
										//char path[] = "Images/block3.png";
										//treeText1= loadTexture(path,3);
										//glBindTexture(GL_TEXTURE_2D, texture5);
										glBegin(GL_QUADS);
											//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
											//I subtract 1 because the index start from 0 in C++
											
											glNormal3f(levelLoad.frNormals[levelLoad.frFaces[i]->facenum-1]->x + forwardSkewX[z],levelLoad.frNormals[levelLoad.frFaces[i]->facenum-1]->y,levelLoad.frNormals[levelLoad.frFaces[i]->facenum-1]->z + forwardSkewZ[z]);
											//draw the faces
											glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.frVert[levelLoad.frFaces[i]->faces[0]-1]->x + forwardSkewX[z],levelLoad.frVert[levelLoad.frFaces[i]->faces[0]-1]->y + forwardSkewY[z],levelLoad.frVert[levelLoad.frFaces[i]->faces[0]-1]->z + forwardSkewZ[z]);
											glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.frVert[levelLoad.frFaces[i]->faces[1]-1]->x + forwardSkewX[z],levelLoad.frVert[levelLoad.frFaces[i]->faces[1]-1]->y + forwardSkewY[z],levelLoad.frVert[levelLoad.frFaces[i]->faces[1]-1]->z + forwardSkewZ[z]);
											glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.frVert[levelLoad.frFaces[i]->faces[2]-1]->x + forwardSkewX[z],levelLoad.frVert[levelLoad.frFaces[i]->faces[2]-1]->y + forwardSkewY[z],levelLoad.frVert[levelLoad.frFaces[i]->faces[2]-1]->z + forwardSkewZ[z]);
											glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.frVert[levelLoad.frFaces[i]->faces[3]-1]->x + forwardSkewX[z],levelLoad.frVert[levelLoad.frFaces[i]->faces[3]-1]->y + forwardSkewY[z],levelLoad.frVert[levelLoad.frFaces[i]->faces[3]-1]->z + forwardSkewZ[z]);
										glEnd();	
										//char path2[] = "Images/Plants/tree1.png";
										////treeText1 = loadTexture(path2, 3);
										//glBindTexture(GL_TEXTURE_2D, texture3);
									}
							}
					}
				}
		}
		glBindTexture(GL_TEXTURE_2D, rewindTexture);
			for(int z = 0; z < 100; z++){
				if(rewindSpawnX[z] != -1000){
					if(shownRewind[z]){
						for(int i=0;i< levelLoad.reFaces.size();i++){
						//if((i+1) % 6 == 0){	
						//if(levelLoad.reVert[levelLoad.reFaces[i]->faces[0]-1]->y < py){

								if(levelLoad.reFaces[i]->four){	//if it's a quad draw a quad
									//if((i+1) % 6 != 0){
									//	std::cout << "here 1" << std::endl;
										glBegin(GL_QUADS);
											//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
											//I subtract 1 because the index start from 0 in C++
											
											glNormal3f(levelLoad.reNormals[levelLoad.reFaces[i]->facenum-1]->x + rewindSkewX[z],levelLoad.reNormals[levelLoad.reFaces[i]->facenum-1]->y,levelLoad.reNormals[levelLoad.reFaces[i]->facenum-1]->z + rewindSkewZ[z]);
											//draw the faces
											glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.reVert[levelLoad.reFaces[i]->faces[0]-1]->x + rewindSkewX[z],levelLoad.reVert[levelLoad.reFaces[i]->faces[0]-1]->y + rewindSkewY[z],levelLoad.reVert[levelLoad.reFaces[i]->faces[0]-1]->z + rewindSkewZ[z]);
											glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.reVert[levelLoad.reFaces[i]->faces[1]-1]->x + rewindSkewX[z],levelLoad.reVert[levelLoad.reFaces[i]->faces[1]-1]->y + rewindSkewY[z],levelLoad.reVert[levelLoad.reFaces[i]->faces[1]-1]->z + rewindSkewZ[z]);
											glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.reVert[levelLoad.reFaces[i]->faces[2]-1]->x + rewindSkewX[z],levelLoad.reVert[levelLoad.reFaces[i]->faces[2]-1]->y + rewindSkewY[z],levelLoad.reVert[levelLoad.reFaces[i]->faces[2]-1]->z + rewindSkewZ[z]);
											glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.reVert[levelLoad.reFaces[i]->faces[3]-1]->x + rewindSkewX[z],levelLoad.reVert[levelLoad.reFaces[i]->faces[3]-1]->y + rewindSkewY[z],levelLoad.reVert[levelLoad.reFaces[i]->faces[3]-1]->z + rewindSkewZ[z]);
										glEnd();
									}else{
										
										//char path[] = "Images/block3.png";
										//treeText1= loadTexture(path,3);
										//glBindTexture(GL_TEXTURE_2D, texture5);
										glBegin(GL_QUADS);
											//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
											//I subtract 1 because the index start from 0 in C++
											
											glNormal3f(levelLoad.reNormals[levelLoad.reFaces[i]->facenum-1]->x + rewindSkewX[z],levelLoad.reNormals[levelLoad.reFaces[i]->facenum-1]->y,levelLoad.reNormals[levelLoad.reFaces[i]->facenum-1]->z + rewindSkewZ[z]);
											//draw the faces
											glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.reVert[levelLoad.reFaces[i]->faces[0]-1]->x + rewindSkewX[z],levelLoad.reVert[levelLoad.reFaces[i]->faces[0]-1]->y + rewindSkewY[z],levelLoad.reVert[levelLoad.reFaces[i]->faces[0]-1]->z + rewindSkewZ[z]);
											glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.reVert[levelLoad.reFaces[i]->faces[1]-1]->x + rewindSkewX[z],levelLoad.reVert[levelLoad.reFaces[i]->faces[1]-1]->y + rewindSkewY[z],levelLoad.reVert[levelLoad.reFaces[i]->faces[1]-1]->z + rewindSkewZ[z]);
											glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.reVert[levelLoad.reFaces[i]->faces[2]-1]->x + rewindSkewX[z],levelLoad.reVert[levelLoad.reFaces[i]->faces[2]-1]->y + rewindSkewY[z],levelLoad.reVert[levelLoad.reFaces[i]->faces[2]-1]->z + rewindSkewZ[z]);
											glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.reVert[levelLoad.reFaces[i]->faces[3]-1]->x + rewindSkewX[z],levelLoad.reVert[levelLoad.reFaces[i]->faces[3]-1]->y + rewindSkewY[z],levelLoad.reVert[levelLoad.reFaces[i]->faces[3]-1]->z + rewindSkewZ[z]);
										glEnd();	
										//char path2[] = "Images/Plants/tree1.png";
										////treeText1 = loadTexture(path2, 3);
										//glBindTexture(GL_TEXTURE_2D, texture3);
									}
							}
					}
				}
		}
				
	
}
void drawScene(level &levelLoad, int marble, float playerR, float playerRZ, objloader &objLoader, bool left, bool right, bool backward, AnimationController &kingI, AnimationController &kingR, AnimationController &kingH, AnimationController &anime, AnimationController &boss, AnimationController &spider){
			bool isnormals = true;
			bool istexture = true;
			glCallList(marble);
					if(forwardTime){
						glCallList(forwardM);
					}else if(pauseTime){
						glCallList(pauseM);
					}else if(rewindTime){
						glCallList(rewindM);
					}else{
						glCallList(marble);
					}
			
			//cout << "IT'S THE FUCKING draw FUNCTION" << endl;
			
				for(int i = 0; i < fMinionSize; i++){
					glPushMatrix();
					objLoader.drawBomb(bombFrameCounter, factoryMinionX[i] ,factoryMinionY[i],factoryMinionZ[i], bombAngle);
					glPopMatrix();
				}
				for(int i =0;i < factoryCounter; i++){
					if(!factoryDead[i]){
						glPushMatrix();
						glTranslatef(factoryX[i], factoryY[i], factoryZ[i]);
							for(int i=0;i< levelLoad.famFaces.size();i++){	
							//if((i+1) % 6 == 0){	
							//if(levelLoad.throwVert[levelLoad.throwFaces[i]->faces[0]-1]->y < py){

									if(levelLoad.famFaces[i]->four){	//if it's a quad draw a quad
										//if((i+1) % 6 != 0){
										//	std::cout << "here 1" << std::endl;
											glBegin(GL_QUADS);
												//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
												//I subtract 1 because the index start from 0 in C++
												
												glNormal3f(levelLoad.famNormals[levelLoad.famFaces[i]->facenum-1]->x,levelLoad.famNormals[levelLoad.famFaces[i]->facenum-1]->y,levelLoad.famNormals[levelLoad.famFaces[i]->facenum-1]->z);
												//draw the faces
												glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.famVert[levelLoad.famFaces[i]->faces[0]-1]->x,levelLoad.famVert[levelLoad.famFaces[i]->faces[0]-1]->y,levelLoad.famVert[levelLoad.famFaces[i]->faces[0]-1]->z);
												glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.famVert[levelLoad.famFaces[i]->faces[1]-1]->x,levelLoad.famVert[levelLoad.famFaces[i]->faces[1]-1]->y,levelLoad.famVert[levelLoad.famFaces[i]->faces[1]-1]->z);
												glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.famVert[levelLoad.famFaces[i]->faces[2]-1]->x,levelLoad.famVert[levelLoad.famFaces[i]->faces[2]-1]->y,levelLoad.famVert[levelLoad.famFaces[i]->faces[2]-1]->z);
												glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.famVert[levelLoad.famFaces[i]->faces[3]-1]->x,levelLoad.famVert[levelLoad.famFaces[i]->faces[3]-1]->y,levelLoad.famVert[levelLoad.famFaces[i]->faces[3]-1]->z);
											glEnd();
										}else{
											
											//char path[] = "Images/block3.png";
											//treeText1= loadTexture(path,3);
											//glBindTexture(GL_TEXTURE_2D, texture5);
											glBegin(GL_TRIANGLES);
										//glBindTexture(GL_TEXTURE_2D, texture3);
												glNormal3f(levelLoad.famNormals[levelLoad.famFaces[i]->facenum-1]->x,levelLoad.famNormals[levelLoad.famFaces[i]->facenum-1]->y,levelLoad.famNormals[levelLoad.famFaces[i]->facenum-1]->z);
												glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.famVert[levelLoad.famFaces[i]->faces[0]-1]->x ,levelLoad.famVert[levelLoad.famFaces[i]->faces[0]-1]->y ,levelLoad.famVert[levelLoad.famFaces[i]->faces[0]-1]->z );
												glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.famVert[levelLoad.famFaces[i]->faces[1]-1]->x ,levelLoad.famVert[levelLoad.famFaces[i]->faces[1]-1]->y ,levelLoad.famVert[levelLoad.famFaces[i]->faces[1]-1]->z );
												glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.famVert[levelLoad.famFaces[i]->faces[2]-1]->x ,levelLoad.famVert[levelLoad.famFaces[i]->faces[2]-1]->y ,levelLoad.famVert[levelLoad.famFaces[i]->faces[2]-1]->z );
											glEnd();	
											//char path2[] = "Images/Plants/tree1.png";
											////treeText1 = loadTexture(path2, 3);
											//glBindTexture(GL_TEXTURE_2D, texture3);
										}
							//	}
						//}
							}
							glPopMatrix();
						}
					}
				
			for(int v = 0; v < onlineCounter; v++){
					glPushMatrix();
					glTranslatef(onlineX[v], onlineY[v], onlineZ[v]);
					glTranslatef(0,-0.7,0);
					glRotatef((-onlineAngle[v])-90, 0,1,0);
				for(int i=0;i< objLoader.tailFrames[onlineFrameCounter[v]]->faces.size();i++) //go throught all faces
				{
					if(objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->four)      //if quad
					{
							glBegin(GL_QUADS);
									if(isnormals)   //if there are normals
											glNormal3f(objLoader.tailFrames[onlineFrameCounter[v]]->normals[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->facenum-1]->x,objLoader.tailFrames[onlineFrameCounter[v]]->normals[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->facenum-1]->y,objLoader.tailFrames[onlineFrameCounter[v]]->normals[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->facenum-1]->z);    //use them
										   
									if(istexture &&objLoader.tailFrames[onlineFrameCounter[v]]-> materials[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->mat]->texture!=-1)  //if there are textures
											glTexCoord2f(objLoader.tailFrames[onlineFrameCounter[v]]->texturecoordinate[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->texcoord[0]-1]->u,objLoader.tailFrames[onlineFrameCounter[v]]->texturecoordinate[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->texcoord[0]-1]->v);      //set the texture coorinate
								   
									glVertex3f(objLoader.tailFrames[onlineFrameCounter[v]]->vertex[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->faces[0]-1]->x,objLoader.tailFrames[onlineFrameCounter[v]]->vertex[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->faces[0]-1]->y,objLoader.tailFrames[onlineFrameCounter[v]]->vertex[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->faces[0]-1]->z);
								   
									if(istexture && objLoader.tailFrames[onlineFrameCounter[v]]->materials[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->mat]->texture!=-1)
											glTexCoord2f(objLoader.tailFrames[onlineFrameCounter[v]]->texturecoordinate[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->texcoord[1]-1]->u,objLoader.tailFrames[onlineFrameCounter[v]]->texturecoordinate[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->texcoord[1]-1]->v);
								   
									glVertex3f(objLoader.tailFrames[onlineFrameCounter[v]]->vertex[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->faces[1]-1]->x,objLoader.tailFrames[onlineFrameCounter[v]]->vertex[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->faces[1]-1]->y,objLoader.tailFrames[onlineFrameCounter[v]]->vertex[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->faces[1]-1]->z);
								   
									if(istexture && objLoader.tailFrames[onlineFrameCounter[v]]->materials[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->mat]->texture!=-1)
											glTexCoord2f(objLoader.tailFrames[onlineFrameCounter[v]]->texturecoordinate[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->texcoord[2]-1]->u,objLoader.tailFrames[onlineFrameCounter[v]]->texturecoordinate[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->texcoord[2]-1]->v);
								   
									glVertex3f(objLoader.tailFrames[onlineFrameCounter[v]]->vertex[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->faces[2]-1]->x,objLoader.tailFrames[onlineFrameCounter[v]]->vertex[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->faces[2]-1]->y,objLoader.tailFrames[onlineFrameCounter[v]]->vertex[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->faces[2]-1]->z);
								   
									if(istexture && objLoader.tailFrames[onlineFrameCounter[v]]->materials[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->mat]->texture!=-1)
											glTexCoord2f(objLoader.tailFrames[onlineFrameCounter[v]]->texturecoordinate[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->texcoord[3]-1]->u,objLoader.tailFrames[onlineFrameCounter[v]]->texturecoordinate[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->texcoord[3]-1]->v);
								   
									glVertex3f(objLoader.tailFrames[onlineFrameCounter[v]]->vertex[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->faces[3]-1]->x,objLoader.tailFrames[onlineFrameCounter[v]]->vertex[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->faces[3]-1]->y,objLoader.tailFrames[onlineFrameCounter[v]]->vertex[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->faces[3]-1]->z);
							glEnd();
					}else{
							glBegin(GL_TRIANGLES);
									if(isnormals)   //if there are normals
											glNormal3f(objLoader.tailFrames[onlineFrameCounter[v]]->normals[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->facenum-1]->x,objLoader.tailFrames[onlineFrameCounter[v]]->normals[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->facenum-1]->y,objLoader.tailFrames[onlineFrameCounter[v]]->normals[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->facenum-1]->z);
	 
									if(istexture && objLoader.tailFrames[onlineFrameCounter[v]]->materials[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->mat]->texture!=-1)
											glTexCoord2f(objLoader.tailFrames[onlineFrameCounter[v]]->texturecoordinate[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->texcoord[0]-1]->u,objLoader.tailFrames[onlineFrameCounter[v]]->texturecoordinate[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->texcoord[0]-1]->v);
	 
	 
									glVertex3f(objLoader.tailFrames[onlineFrameCounter[v]]->vertex[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->faces[0]-1]->x,objLoader.tailFrames[onlineFrameCounter[v]]->vertex[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->faces[0]-1]->y,objLoader.tailFrames[onlineFrameCounter[v]]->vertex[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->faces[0]-1]->z);
								   
									if(istexture && objLoader.tailFrames[onlineFrameCounter[v]]->materials[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->mat]->texture!=-1)
											glTexCoord2f(objLoader.tailFrames[onlineFrameCounter[v]]->texturecoordinate[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->texcoord[1]-1]->u,objLoader.tailFrames[onlineFrameCounter[v]]->texturecoordinate[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->texcoord[1]-1]->v);
								   
									glVertex3f(objLoader.tailFrames[onlineFrameCounter[v]]->vertex[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->faces[1]-1]->x,objLoader.tailFrames[onlineFrameCounter[v]]->vertex[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->faces[1]-1]->y,objLoader.tailFrames[onlineFrameCounter[v]]->vertex[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->faces[1]-1]->z);
								   
								   
									if(istexture &&objLoader.tailFrames[onlineFrameCounter[v]]-> materials[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->mat]->texture!=-1)
											glTexCoord2f(objLoader.tailFrames[onlineFrameCounter[v]]->texturecoordinate[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->texcoord[2]-1]->u,objLoader.tailFrames[onlineFrameCounter[v]]->texturecoordinate[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->texcoord[2]-1]->v);
								   
									glVertex3f(objLoader.tailFrames[onlineFrameCounter[v]]->vertex[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->faces[2]-1]->x,objLoader.tailFrames[onlineFrameCounter[v]]->vertex[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->faces[2]-1]->y,objLoader.tailFrames[onlineFrameCounter[v]]->vertex[objLoader.tailFrames[onlineFrameCounter[v]]->faces[i]->faces[2]-1]->z);
							glEnd();
					}
				}
				glPopMatrix();
			}
				glPushMatrix();
					glTranslatef(px, py, pz);
					glTranslatef(0,-0.7,0);
					glRotatef((-angle)-90, 0,1,0);
				//glRotatef(playerRZ,1,0,0);
				//glRotatef(playerR,0,0,1);
				//glTranslatef(-px, -py, -pz);
				
				for(int i=0;i< objLoader.tailFrames[frameCounter]->faces.size();i++) //go throught all faces
				{
					if(objLoader.tailFrames[frameCounter]->faces[i]->four)      //if quad
					{
							glBegin(GL_QUADS);
									if(isnormals)   //if there are normals
											glNormal3f(objLoader.tailFrames[frameCounter]->normals[objLoader.tailFrames[frameCounter]->faces[i]->facenum-1]->x,objLoader.tailFrames[frameCounter]->normals[objLoader.tailFrames[frameCounter]->faces[i]->facenum-1]->y,objLoader.tailFrames[frameCounter]->normals[objLoader.tailFrames[frameCounter]->faces[i]->facenum-1]->z);    //use them
										   
									if(istexture &&objLoader.tailFrames[frameCounter]-> materials[objLoader.tailFrames[frameCounter]->faces[i]->mat]->texture!=-1)  //if there are textures
											glTexCoord2f(objLoader.tailFrames[frameCounter]->texturecoordinate[objLoader.tailFrames[frameCounter]->faces[i]->texcoord[0]-1]->u,objLoader.tailFrames[frameCounter]->texturecoordinate[objLoader.tailFrames[frameCounter]->faces[i]->texcoord[0]-1]->v);      //set the texture coorinate
								   
									glVertex3f(objLoader.tailFrames[frameCounter]->vertex[objLoader.tailFrames[frameCounter]->faces[i]->faces[0]-1]->x,objLoader.tailFrames[frameCounter]->vertex[objLoader.tailFrames[frameCounter]->faces[i]->faces[0]-1]->y,objLoader.tailFrames[frameCounter]->vertex[objLoader.tailFrames[frameCounter]->faces[i]->faces[0]-1]->z);
								   
									if(istexture && objLoader.tailFrames[frameCounter]->materials[objLoader.tailFrames[frameCounter]->faces[i]->mat]->texture!=-1)
											glTexCoord2f(objLoader.tailFrames[frameCounter]->texturecoordinate[objLoader.tailFrames[frameCounter]->faces[i]->texcoord[1]-1]->u,objLoader.tailFrames[frameCounter]->texturecoordinate[objLoader.tailFrames[frameCounter]->faces[i]->texcoord[1]-1]->v);
								   
									glVertex3f(objLoader.tailFrames[frameCounter]->vertex[objLoader.tailFrames[frameCounter]->faces[i]->faces[1]-1]->x,objLoader.tailFrames[frameCounter]->vertex[objLoader.tailFrames[frameCounter]->faces[i]->faces[1]-1]->y,objLoader.tailFrames[frameCounter]->vertex[objLoader.tailFrames[frameCounter]->faces[i]->faces[1]-1]->z);
								   
									if(istexture && objLoader.tailFrames[frameCounter]->materials[objLoader.tailFrames[frameCounter]->faces[i]->mat]->texture!=-1)
											glTexCoord2f(objLoader.tailFrames[frameCounter]->texturecoordinate[objLoader.tailFrames[frameCounter]->faces[i]->texcoord[2]-1]->u,objLoader.tailFrames[frameCounter]->texturecoordinate[objLoader.tailFrames[frameCounter]->faces[i]->texcoord[2]-1]->v);
								   
									glVertex3f(objLoader.tailFrames[frameCounter]->vertex[objLoader.tailFrames[frameCounter]->faces[i]->faces[2]-1]->x,objLoader.tailFrames[frameCounter]->vertex[objLoader.tailFrames[frameCounter]->faces[i]->faces[2]-1]->y,objLoader.tailFrames[frameCounter]->vertex[objLoader.tailFrames[frameCounter]->faces[i]->faces[2]-1]->z);
								   
									if(istexture && objLoader.tailFrames[frameCounter]->materials[objLoader.tailFrames[frameCounter]->faces[i]->mat]->texture!=-1)
											glTexCoord2f(objLoader.tailFrames[frameCounter]->texturecoordinate[objLoader.tailFrames[frameCounter]->faces[i]->texcoord[3]-1]->u,objLoader.tailFrames[frameCounter]->texturecoordinate[objLoader.tailFrames[frameCounter]->faces[i]->texcoord[3]-1]->v);
								   
									glVertex3f(objLoader.tailFrames[frameCounter]->vertex[objLoader.tailFrames[frameCounter]->faces[i]->faces[3]-1]->x,objLoader.tailFrames[frameCounter]->vertex[objLoader.tailFrames[frameCounter]->faces[i]->faces[3]-1]->y,objLoader.tailFrames[frameCounter]->vertex[objLoader.tailFrames[frameCounter]->faces[i]->faces[3]-1]->z);
							glEnd();
					}else{
							glBegin(GL_TRIANGLES);
									if(isnormals)   //if there are normals
											glNormal3f(objLoader.tailFrames[frameCounter]->normals[objLoader.tailFrames[frameCounter]->faces[i]->facenum-1]->x,objLoader.tailFrames[frameCounter]->normals[objLoader.tailFrames[frameCounter]->faces[i]->facenum-1]->y,objLoader.tailFrames[frameCounter]->normals[objLoader.tailFrames[frameCounter]->faces[i]->facenum-1]->z);
	 
									if(istexture && objLoader.tailFrames[frameCounter]->materials[objLoader.tailFrames[frameCounter]->faces[i]->mat]->texture!=-1)
											glTexCoord2f(objLoader.tailFrames[frameCounter]->texturecoordinate[objLoader.tailFrames[frameCounter]->faces[i]->texcoord[0]-1]->u,objLoader.tailFrames[frameCounter]->texturecoordinate[objLoader.tailFrames[frameCounter]->faces[i]->texcoord[0]-1]->v);
	 
	 
									glVertex3f(objLoader.tailFrames[frameCounter]->vertex[objLoader.tailFrames[frameCounter]->faces[i]->faces[0]-1]->x,objLoader.tailFrames[frameCounter]->vertex[objLoader.tailFrames[frameCounter]->faces[i]->faces[0]-1]->y,objLoader.tailFrames[frameCounter]->vertex[objLoader.tailFrames[frameCounter]->faces[i]->faces[0]-1]->z);
								   
									if(istexture && objLoader.tailFrames[frameCounter]->materials[objLoader.tailFrames[frameCounter]->faces[i]->mat]->texture!=-1)
											glTexCoord2f(objLoader.tailFrames[frameCounter]->texturecoordinate[objLoader.tailFrames[frameCounter]->faces[i]->texcoord[1]-1]->u,objLoader.tailFrames[frameCounter]->texturecoordinate[objLoader.tailFrames[frameCounter]->faces[i]->texcoord[1]-1]->v);
								   
									glVertex3f(objLoader.tailFrames[frameCounter]->vertex[objLoader.tailFrames[frameCounter]->faces[i]->faces[1]-1]->x,objLoader.tailFrames[frameCounter]->vertex[objLoader.tailFrames[frameCounter]->faces[i]->faces[1]-1]->y,objLoader.tailFrames[frameCounter]->vertex[objLoader.tailFrames[frameCounter]->faces[i]->faces[1]-1]->z);
								   
								   
									if(istexture &&objLoader.tailFrames[frameCounter]-> materials[objLoader.tailFrames[frameCounter]->faces[i]->mat]->texture!=-1)
											glTexCoord2f(objLoader.tailFrames[frameCounter]->texturecoordinate[objLoader.tailFrames[frameCounter]->faces[i]->texcoord[2]-1]->u,objLoader.tailFrames[frameCounter]->texturecoordinate[objLoader.tailFrames[frameCounter]->faces[i]->texcoord[2]-1]->v);
								   
									glVertex3f(objLoader.tailFrames[frameCounter]->vertex[objLoader.tailFrames[frameCounter]->faces[i]->faces[2]-1]->x,objLoader.tailFrames[frameCounter]->vertex[objLoader.tailFrames[frameCounter]->faces[i]->faces[2]-1]->y,objLoader.tailFrames[frameCounter]->vertex[objLoader.tailFrames[frameCounter]->faces[i]->faces[2]-1]->z);
							glEnd();
					}
				}
				//glDisable(GL_TEXTURE_2D);
				
				glPopMatrix();
				if(world ==0 && !bossKilled){
					glPushMatrix();
					glTranslatef(bossX, 0, bossZ);
					glRotatef(((-bossAngle)-270), 0,1,0);
					glTranslatef(-bossX, 0, -bossZ);
					glTranslatef(bossX, bossY, bossZ);
					glCallList(pauseM);
					boss.DrawGLScene(true);
					for(int i=0;i< levelLoad.hFaces.size();i++){	
						
						if(levelLoad.hFaces[i]->four){	//if it's a quad draw a quad

							//	std::cout << "here 1" << std::endl;
							glBegin(GL_QUADS);
								//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
								//I subhact 1 because the index start from 0 in C++
								
								glNormal3f(levelLoad.hNormals[levelLoad.hFaces[i]->facenum-1]->x,levelLoad.hNormals[levelLoad.hFaces[i]->facenum-1]->y,levelLoad.hNormals[levelLoad.hFaces[i]->facenum-1]->z);
							//draw the faces
								glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.hVert[levelLoad.hFaces[i]->faces[0]-1]->x ,levelLoad.hVert[levelLoad.hFaces[i]->faces[0]-1]->y ,levelLoad.hVert[levelLoad.hFaces[i]->faces[0]-1]->z );
								glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.hVert[levelLoad.hFaces[i]->faces[1]-1]->x ,levelLoad.hVert[levelLoad.hFaces[i]->faces[1]-1]->y ,levelLoad.hVert[levelLoad.hFaces[i]->faces[1]-1]->z );
								glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.hVert[levelLoad.hFaces[i]->faces[2]-1]->x ,levelLoad.hVert[levelLoad.hFaces[i]->faces[2]-1]->y ,levelLoad.hVert[levelLoad.hFaces[i]->faces[2]-1]->z );
								glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.hVert[levelLoad.hFaces[i]->faces[3]-1]->x ,levelLoad.hVert[levelLoad.hFaces[i]->faces[3]-1]->y ,levelLoad.hVert[levelLoad.hFaces[i]->faces[3]-1]->z );
							glEnd();

						}else{
						//	std::cout << cVertex[levelLoad.hFaces[i]->faces[0]-1]->x << cVertex[levelLoad.hFaces[i]->faces[0]-1]->y << cVertex[levelLoad.hFaces[i]->faces[0]-1]->z << std::endl;
							//std::cout << vertex[levelLoad.hFaces[i]->faces[1]-1]->x << vertex[levelLoad.hFaces[i]->faces[1]-1]->y << vertex[levelLoad.hFaces[i]->faces[1]-1]->z << std::endl;
							//std::cout << vertex[levelLoad.hFaces[i]->faces[2]-1]->x << vertex[levelLoad.hFaces[i]->faces[2]-1]->y << vertex[levelLoad.hFaces[i]->faces[2]-1]->z << std::endl;
							glBegin(GL_TRIANGLES);
								//glBindTexture(GL_TEXTURE_2D, texture3);
								glNormal3f(levelLoad.hNormals[levelLoad.hFaces[i]->facenum-1]->x,levelLoad.hNormals[levelLoad.hFaces[i]->facenum-1]->y,levelLoad.hNormals[levelLoad.hFaces[i]->facenum-1]->z);
								glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.hVert[levelLoad.hFaces[i]->faces[0]-1]->x ,levelLoad.hVert[levelLoad.hFaces[i]->faces[0]-1]->y ,levelLoad.hVert[levelLoad.hFaces[i]->faces[0]-1]->z );
								glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.hVert[levelLoad.hFaces[i]->faces[1]-1]->x ,levelLoad.hVert[levelLoad.hFaces[i]->faces[1]-1]->y ,levelLoad.hVert[levelLoad.hFaces[i]->faces[1]-1]->z );
								glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.hVert[levelLoad.hFaces[i]->faces[2]-1]->x ,levelLoad.hVert[levelLoad.hFaces[i]->faces[2]-1]->y ,levelLoad.hVert[levelLoad.hFaces[i]->faces[2]-1]->z );
							glEnd();
						}
					}
					
					glPopMatrix();
				}
					//glDisable(GL_TEXTURE_2D);
				
				for(int i = 0; i < bombCount; i++){
					glPushMatrix();
					glTranslatef(bombX[i], 0, bombZ[i]);
					if(!rewindTime){
						glRotatef((-bombAngle), 0,1,0);
					}else{
						glRotatef((bombAngle), 0,1,0);
					}
					glTranslatef(-bombX[i], 0, -bombZ[i]);
					objLoader.drawBomb(bombFrameCounter, bombX[i],bombY[i],bombZ[i], bombAngle);
					glPopMatrix();
				}
				for(int i = 0; i < projectCount; i++){
					glPushMatrix();
					glTranslatef(projectX[i], 0, projectZ[i]);
					glRotatef((projectAngle[i]), 0,1,0);
					glTranslatef(-projectX[i], 0, -projectZ[i]);
					objLoader.drawSqu(0, projectX[i], projectY[i], projectZ[i], projectAngle[i]);
					glPopMatrix();
					if(fireProject[i]){
						glPushMatrix();
						glTranslatef(firePrX[i], firePrY[i], firePrZ[i]);
						gluQuadricDrawStyle(sphere, GLU_FILL);
						//glEnable(GL_TEXTURE_2D);
						//glBindTexture(GL_TEXTURE_2D, ballTexture);
						gluQuadricTexture(sphere, GL_TRUE);
						gluQuadricNormals(sphere, GLU_SMOOTH);
						gluSphere(sphere, 1.0, 64, 32);
						glPopMatrix();
					}
				}
				for(int i = 0; i < tmCount; i++){
					if(!tmKilled[i]){
						glPushMatrix();
						glTranslatef(tMonsterX[i], 0, tMonsterZ[i]);
						glRotatef(tMAngle[i], 0, 1, 0);
						glTranslatef(-tMonsterX[i], 0, -tMonsterZ[i]);
						glTranslatef(tMonsterX[i], tMonsterY[i], tMonsterZ[i]);
						if(tMonsterType[i] == 0){
							glCallList(pauseM);
						}else if(tMonsterType[i] ==1){
							glCallList(forwardM);
						}else if(tMonsterType[i] ==10){
							glCallList(marble);
						}
						spider.DrawGLScene(true);
						glPopMatrix();
					}
				}
			
						if(forwardTime){
							glCallList(forwardM);
						}else if(pauseTime){
							glCallList(pauseM);
						}else if(rewindTime){
							glCallList(rewindM);
						}else{
							glCallList(marble);
						}
				for(int i = 0; i < sqCount; i++){
					glPushMatrix();
					glTranslatef(squX[i], 0, squZ[i]);
					//if(!rewindTime){
						glRotatef((-squAngle[i]+90), 0,1,0);
					//}else{
					//	glRotatef((squAngle[i]), 0,1,0);
					//}
					//glRotatef(90, 0,0,1);
					glTranslatef(-squX[i], 0, -squZ[i]);
					glTranslatef(squX[i], squY[i], squZ[i]);
					//kingI.Update();
					if (squHit[i]){
						kingH.DrawGLScene(true);
					}else if(squOldX[i] != squX[i] || squOldZ[i] != squZ[i]){
						kingR.DrawGLScene(true);
					}else{
						kingI.DrawGLScene(true);
						
					}
					glPopMatrix();
				}
				if(part == 1 || part == 2){
					for(int i =0; i < animeCount; i++){
						//if(i ==2){
							glPushMatrix();
							glTranslatef(animeX[i], 0, animeZ[i]);
							//if(!rewindTime){
								glRotatef((-animeAngle[i]+90), 0,1,0);
							//}else{
							//	glRotatef((squAngle[i]), 0,1,0);
							//}
							//glRotatef(90, 0,0,1);
							glTranslatef(-animeX[i], 0, -animeZ[i]);
							glTranslatef(animeX[i], animeY[i], animeZ[i]);
							//kingI.Update();

							anime.DrawGLScene(true);
							glPopMatrix();
						//}else{
						//	objLoader.drawSqu(i, animeX[i], animeY[i], animeZ[i], 0);
						//}
					}
				}
				for(int z = 0; z < binCount; z++){
					if(!binCollected[z] && !binamation[z]){
						glPushMatrix();
						glTranslatef(binX[z], binY[z], binZ[z]);
						for(int i=0;i< levelLoad.biFaces.size();i++){	
						//if((i+1) % 6 == 0){	
						//if(levelLoad.biVert[levelLoad.biFaces[i]->faces[0]-1]->y < py){

								if(levelLoad.biFaces[i]->four){	//if it's a quad draw a quad
									//if((i+1) % 6 != 0){
									//	std::cout << "here 1" << std::endl;
										glBegin(GL_QUADS);
											//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
											//I subtract 1 because the index start from 0 in C++
											
											glNormal3f(levelLoad.biNormals[levelLoad.biFaces[i]->facenum-1]->x,levelLoad.biNormals[levelLoad.biFaces[i]->facenum-1]->y,levelLoad.biNormals[levelLoad.biFaces[i]->facenum-1]->z);
											//draw the faces
											glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.biVert[levelLoad.biFaces[i]->faces[0]-1]->x,levelLoad.biVert[levelLoad.biFaces[i]->faces[0]-1]->y,levelLoad.biVert[levelLoad.biFaces[i]->faces[0]-1]->z);
											glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.biVert[levelLoad.biFaces[i]->faces[1]-1]->x,levelLoad.biVert[levelLoad.biFaces[i]->faces[1]-1]->y,levelLoad.biVert[levelLoad.biFaces[i]->faces[1]-1]->z);
											glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.biVert[levelLoad.biFaces[i]->faces[2]-1]->x,levelLoad.biVert[levelLoad.biFaces[i]->faces[2]-1]->y,levelLoad.biVert[levelLoad.biFaces[i]->faces[2]-1]->z);
											glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.biVert[levelLoad.biFaces[i]->faces[3]-1]->x,levelLoad.biVert[levelLoad.biFaces[i]->faces[3]-1]->y,levelLoad.biVert[levelLoad.biFaces[i]->faces[3]-1]->z);
										glEnd();
									}else{
										
										//char path[] = "Images/block3.png";
										//treeText1= loadTexture(path,3);
										//glBindTexture(GL_TEXTURE_2D, texture5);
										glBegin(GL_TRIANGLES);
									//glBindTexture(GL_TEXTURE_2D, texture3);
											glNormal3f(levelLoad.biNormals[levelLoad.biFaces[i]->facenum-1]->x,levelLoad.biNormals[levelLoad.biFaces[i]->facenum-1]->y,levelLoad.biNormals[levelLoad.biFaces[i]->facenum-1]->z);
											glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.biVert[levelLoad.biFaces[i]->faces[0]-1]->x ,levelLoad.biVert[levelLoad.biFaces[i]->faces[0]-1]->y ,levelLoad.biVert[levelLoad.biFaces[i]->faces[0]-1]->z );
											glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.biVert[levelLoad.biFaces[i]->faces[1]-1]->x ,levelLoad.biVert[levelLoad.biFaces[i]->faces[1]-1]->y ,levelLoad.biVert[levelLoad.biFaces[i]->faces[1]-1]->z );
											glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.biVert[levelLoad.biFaces[i]->faces[2]-1]->x ,levelLoad.biVert[levelLoad.biFaces[i]->faces[2]-1]->y ,levelLoad.biVert[levelLoad.biFaces[i]->faces[2]-1]->z );
										glEnd();	
										//char path2[] = "Images/Plants/tree1.png";
										////treeText1 = loadTexture(path2, 3);
										//glBindTexture(GL_TEXTURE_2D, texture3);
									}
						//	}
					//}
						}
						glPopMatrix();
					}else if(binamation[z]){
						glPushMatrix();
						glTranslatef(binX[z], binY[z], binZ[z]);
						glScalef(binScale[z],binScale[z], 1);
						
						for(int i=0;i< levelLoad.biFaces.size();i++){	
						//if((i+1) % 6 == 0){	
						//if(levelLoad.biVert[levelLoad.biFaces[i]->faces[0]-1]->y < py){

								if(levelLoad.biFaces[i]->four){	//if it's a quad draw a quad
									//if((i+1) % 6 != 0){
									//	std::cout << "here 1" << std::endl;
										glBegin(GL_QUADS);
											//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
											//I subtract 1 because the index start from 0 in C++
											
											glNormal3f(levelLoad.biNormals[levelLoad.biFaces[i]->facenum-1]->x,levelLoad.biNormals[levelLoad.biFaces[i]->facenum-1]->y,levelLoad.biNormals[levelLoad.biFaces[i]->facenum-1]->z);
											//draw the faces
											glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.biVert[levelLoad.biFaces[i]->faces[0]-1]->x,levelLoad.biVert[levelLoad.biFaces[i]->faces[0]-1]->y,levelLoad.biVert[levelLoad.biFaces[i]->faces[0]-1]->z);
											glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.biVert[levelLoad.biFaces[i]->faces[1]-1]->x,levelLoad.biVert[levelLoad.biFaces[i]->faces[1]-1]->y,levelLoad.biVert[levelLoad.biFaces[i]->faces[1]-1]->z);
											glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.biVert[levelLoad.biFaces[i]->faces[2]-1]->x,levelLoad.biVert[levelLoad.biFaces[i]->faces[2]-1]->y,levelLoad.biVert[levelLoad.biFaces[i]->faces[2]-1]->z);
											glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.biVert[levelLoad.biFaces[i]->faces[3]-1]->x,levelLoad.biVert[levelLoad.biFaces[i]->faces[3]-1]->y,levelLoad.biVert[levelLoad.biFaces[i]->faces[3]-1]->z);
										glEnd();
									}else{
										
										//char path[] = "Images/block3.png";
										//treeText1= loadTexture(path,3);
										//glBindTexture(GL_TEXTURE_2D, texture5);
										glBegin(GL_TRIANGLES);
									//glBindTexture(GL_TEXTURE_2D, texture3);
											glNormal3f(levelLoad.biNormals[levelLoad.biFaces[i]->facenum-1]->x,levelLoad.biNormals[levelLoad.biFaces[i]->facenum-1]->y,levelLoad.biNormals[levelLoad.biFaces[i]->facenum-1]->z);
											glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.biVert[levelLoad.biFaces[i]->faces[0]-1]->x ,levelLoad.biVert[levelLoad.biFaces[i]->faces[0]-1]->y ,levelLoad.biVert[levelLoad.biFaces[i]->faces[0]-1]->z );
											glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.biVert[levelLoad.biFaces[i]->faces[1]-1]->x ,levelLoad.biVert[levelLoad.biFaces[i]->faces[1]-1]->y ,levelLoad.biVert[levelLoad.biFaces[i]->faces[1]-1]->z );
											glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.biVert[levelLoad.biFaces[i]->faces[2]-1]->x ,levelLoad.biVert[levelLoad.biFaces[i]->faces[2]-1]->y ,levelLoad.biVert[levelLoad.biFaces[i]->faces[2]-1]->z );
										glEnd();	
										//char path2[] = "Images/Plants/tree1.png";
										////treeText1 = loadTexture(path2, 3);
										//glBindTexture(GL_TEXTURE_2D, texture3);
									}
						//	}
					//}
						}
						glPopMatrix();
						
						
						
					}
					
				}
				glPushMatrix();
				if(throwing){
					glTranslatef(throwX, throwY, throwZ);
					for(int i=0;i< levelLoad.throwFaces.size();i++){	
					//if((i+1) % 6 == 0){	
					//if(levelLoad.throwVert[levelLoad.throwFaces[i]->faces[0]-1]->y < py){

							if(levelLoad.throwFaces[i]->four){	//if it's a quad draw a quad
								//if((i+1) % 6 != 0){
								//	std::cout << "here 1" << std::endl;
									glBegin(GL_QUADS);
										//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
										//I subtract 1 because the index start from 0 in C++
										
										glNormal3f(levelLoad.throwNormals[levelLoad.throwFaces[i]->facenum-1]->x,levelLoad.throwNormals[levelLoad.throwFaces[i]->facenum-1]->y,levelLoad.throwNormals[levelLoad.throwFaces[i]->facenum-1]->z);
										//draw the faces
										glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.throwVert[levelLoad.throwFaces[i]->faces[0]-1]->x,levelLoad.throwVert[levelLoad.throwFaces[i]->faces[0]-1]->y,levelLoad.throwVert[levelLoad.throwFaces[i]->faces[0]-1]->z);
										glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.throwVert[levelLoad.throwFaces[i]->faces[1]-1]->x,levelLoad.throwVert[levelLoad.throwFaces[i]->faces[1]-1]->y,levelLoad.throwVert[levelLoad.throwFaces[i]->faces[1]-1]->z);
										glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.throwVert[levelLoad.throwFaces[i]->faces[2]-1]->x,levelLoad.throwVert[levelLoad.throwFaces[i]->faces[2]-1]->y,levelLoad.throwVert[levelLoad.throwFaces[i]->faces[2]-1]->z);
										glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.throwVert[levelLoad.throwFaces[i]->faces[3]-1]->x,levelLoad.throwVert[levelLoad.throwFaces[i]->faces[3]-1]->y,levelLoad.throwVert[levelLoad.throwFaces[i]->faces[3]-1]->z);
									glEnd();
								}else{
									
									//char path[] = "Images/block3.png";
									//treeText1= loadTexture(path,3);
									//glBindTexture(GL_TEXTURE_2D, texture5);
									glBegin(GL_TRIANGLES);
								//glBindTexture(GL_TEXTURE_2D, texture3);
										glNormal3f(levelLoad.throwNormals[levelLoad.throwFaces[i]->facenum-1]->x,levelLoad.throwNormals[levelLoad.throwFaces[i]->facenum-1]->y,levelLoad.throwNormals[levelLoad.throwFaces[i]->facenum-1]->z);
										glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.throwVert[levelLoad.throwFaces[i]->faces[0]-1]->x ,levelLoad.throwVert[levelLoad.throwFaces[i]->faces[0]-1]->y ,levelLoad.throwVert[levelLoad.throwFaces[i]->faces[0]-1]->z );
										glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.throwVert[levelLoad.throwFaces[i]->faces[1]-1]->x ,levelLoad.throwVert[levelLoad.throwFaces[i]->faces[1]-1]->y ,levelLoad.throwVert[levelLoad.throwFaces[i]->faces[1]-1]->z );
										glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.throwVert[levelLoad.throwFaces[i]->faces[2]-1]->x ,levelLoad.throwVert[levelLoad.throwFaces[i]->faces[2]-1]->y ,levelLoad.throwVert[levelLoad.throwFaces[i]->faces[2]-1]->z );
									glEnd();	
									//char path2[] = "Images/Plants/tree1.png";
									////treeText1 = loadTexture(path2, 3);
									//glBindTexture(GL_TEXTURE_2D, texture3);
								}
					//	}
				//}
					}
				}
				glPopMatrix();
				for(int i=0;i< levelLoad.eFaces.size();i++){	
		
					if(levelLoad.eFaces[i]->four){	//if it's a quad draw a quad
						if((i+1) % 6 != 0){
						//	std::cout << "here 1" << std::endl;
							glBegin(GL_QUADS);
								//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
								//I subtract 1 because the index start from 0 in C++
								
								glNormal3f(levelLoad.eNormals[levelLoad.eFaces[i]->facenum-1]->x,levelLoad.eNormals[levelLoad.eFaces[i]->facenum-1]->y,levelLoad.eNormals[levelLoad.eFaces[i]->facenum-1]->z);
								//draw the faces
								glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.eVert[levelLoad.eFaces[i]->faces[0]-1]->x,levelLoad.eVert[levelLoad.eFaces[i]->faces[0]-1]->y,levelLoad.eVert[levelLoad.eFaces[i]->faces[0]-1]->z);
								glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.eVert[levelLoad.eFaces[i]->faces[1]-1]->x,levelLoad.eVert[levelLoad.eFaces[i]->faces[1]-1]->y,levelLoad.eVert[levelLoad.eFaces[i]->faces[1]-1]->z);
								glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.eVert[levelLoad.eFaces[i]->faces[2]-1]->x,levelLoad.eVert[levelLoad.eFaces[i]->faces[2]-1]->y,levelLoad.eVert[levelLoad.eFaces[i]->faces[2]-1]->z);
								glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.eVert[levelLoad.eFaces[i]->faces[3]-1]->x,levelLoad.eVert[levelLoad.eFaces[i]->faces[3]-1]->y,levelLoad.eVert[levelLoad.eFaces[i]->faces[3]-1]->z);
							glEnd();
						}else{
							
							//char path[] = "Images/block3.png";
							//treeText1= loadTexture(path,3);
							//glBindTexture(GL_TEXTURE_2D, texture5);
							glBegin(GL_QUADS);
								//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
								//I subtract 1 because the index start from 0 in C++
								
								glNormal3f(levelLoad.eNormals[levelLoad.eFaces[i]->facenum-1]->x,levelLoad.eNormals[levelLoad.eFaces[i]->facenum-1]->y,levelLoad.eNormals[levelLoad.eFaces[i]->facenum-1]->z);
								//draw the faces
								glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.eVert[levelLoad.eFaces[i]->faces[0]-1]->x,levelLoad.eVert[levelLoad.eFaces[i]->faces[0]-1]->y,levelLoad.eVert[levelLoad.eFaces[i]->faces[0]-1]->z);
								glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.eVert[levelLoad.eFaces[i]->faces[1]-1]->x,levelLoad.eVert[levelLoad.eFaces[i]->faces[1]-1]->y,levelLoad.eVert[levelLoad.eFaces[i]->faces[1]-1]->z);
								glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.eVert[levelLoad.eFaces[i]->faces[2]-1]->x,levelLoad.eVert[levelLoad.eFaces[i]->faces[2]-1]->y,levelLoad.eVert[levelLoad.eFaces[i]->faces[2]-1]->z);
								glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.eVert[levelLoad.eFaces[i]->faces[3]-1]->x,levelLoad.eVert[levelLoad.eFaces[i]->faces[3]-1]->y,levelLoad.eVert[levelLoad.eFaces[i]->faces[3]-1]->z);
							glEnd();	
							//char path2[] = "Images/Plants/tree1.png";
							////treeText1 = loadTexture(path2, 3);
							//glBindTexture(GL_TEXTURE_2D, texture3);
						}
					}else{
					//	std::cout << cVertex[levelLoad.eFaces[i]->faces[0]-1]->x << cVertex[levelLoad.eFaces[i]->faces[0]-1]->y << cVertex[levelLoad.eFaces[i]->faces[0]-1]->z << std::endl;
						//std::cout << vertex[levelLoad.eFaces[i]->faces[1]-1]->x << vertex[levelLoad.eFaces[i]->faces[1]-1]->y << vertex[levelLoad.eFaces[i]->faces[1]-1]->z << std::endl;
						//std::cout << vertex[levelLoad.eFaces[i]->faces[2]-1]->x << vertex[levelLoad.eFaces[i]->faces[2]-1]->y << vertex[levelLoad.eFaces[i]->faces[2]-1]->z << std::endl;
						glBegin(GL_TRIANGLES);
							//glBindTexture(GL_TEXTURE_2D, texture3);
							glNormal3f(levelLoad.eNormals[levelLoad.eFaces[i]->facenum-1]->x,levelLoad.eNormals[levelLoad.eFaces[i]->facenum-1]->y,levelLoad.eNormals[levelLoad.eFaces[i]->facenum-1]->z);
							glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.eVert[levelLoad.eFaces[i]->faces[0]-1]->x,levelLoad.eVert[levelLoad.eFaces[i]->faces[0]-1]->y,levelLoad.eVert[levelLoad.eFaces[i]->faces[0]-1]->z);
							glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.eVert[levelLoad.eFaces[i]->faces[1]-1]->x,levelLoad.eVert[levelLoad.eFaces[i]->faces[1]-1]->y,levelLoad.eVert[levelLoad.eFaces[i]->faces[1]-1]->z);
							glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.eVert[levelLoad.eFaces[i]->faces[2]-1]->x,levelLoad.eVert[levelLoad.eFaces[i]->faces[2]-1]->y,levelLoad.eVert[levelLoad.eFaces[i]->faces[2]-1]->z);
						glEnd();
					}
				}
				for(int i=0;i< levelLoad.sfFaces.size();i++){	
				//if(levelLoad.sfVert[levelLoad.sfFaces[i]->faces[0]-1]->y < py){
					if(levelLoad.sfFaces[i]->four){	//if it's a quad draw a quad
						if((i+1) % 6 != 0){
						//	std::cout << "here 1" << std::endl;
							glBegin(GL_QUADS);
								//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
								//I subtract 1 because the index start from 0 in C++
								
								glNormal3f(levelLoad.sfNormals[levelLoad.sfFaces[i]->facenum-1]->x,levelLoad.sfNormals[levelLoad.sfFaces[i]->facenum-1]->y,levelLoad.sfNormals[levelLoad.sfFaces[i]->facenum-1]->z);
								//draw the faces
								glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.sfVert[levelLoad.sfFaces[i]->faces[0]-1]->x,levelLoad.sfVert[levelLoad.sfFaces[i]->faces[0]-1]->y,levelLoad.sfVert[levelLoad.sfFaces[i]->faces[0]-1]->z);
								glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.sfVert[levelLoad.sfFaces[i]->faces[1]-1]->x,levelLoad.sfVert[levelLoad.sfFaces[i]->faces[1]-1]->y,levelLoad.sfVert[levelLoad.sfFaces[i]->faces[1]-1]->z);
								glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.sfVert[levelLoad.sfFaces[i]->faces[2]-1]->x,levelLoad.sfVert[levelLoad.sfFaces[i]->faces[2]-1]->y,levelLoad.sfVert[levelLoad.sfFaces[i]->faces[2]-1]->z);
								glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.sfVert[levelLoad.sfFaces[i]->faces[3]-1]->x,levelLoad.sfVert[levelLoad.sfFaces[i]->faces[3]-1]->y,levelLoad.sfVert[levelLoad.sfFaces[i]->faces[3]-1]->z);
							glEnd();
						}else{
							
							//char path[] = "Images/block3.png";
							//treeText1= loadTexture(path,3);
							//glBindTexture(GL_TEXTURE_2D, texture5);
							glBegin(GL_QUADS);
								//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
								//I subtract 1 because the index start from 0 in C++
								
								glNormal3f(levelLoad.sfNormals[levelLoad.sfFaces[i]->facenum-1]->x,levelLoad.sfNormals[levelLoad.sfFaces[i]->facenum-1]->y,levelLoad.sfNormals[levelLoad.sfFaces[i]->facenum-1]->z);
								//draw the faces
								glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.sfVert[levelLoad.sfFaces[i]->faces[0]-1]->x,levelLoad.sfVert[levelLoad.sfFaces[i]->faces[0]-1]->y,levelLoad.sfVert[levelLoad.sfFaces[i]->faces[0]-1]->z);
								glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.sfVert[levelLoad.sfFaces[i]->faces[1]-1]->x,levelLoad.sfVert[levelLoad.sfFaces[i]->faces[1]-1]->y,levelLoad.sfVert[levelLoad.sfFaces[i]->faces[1]-1]->z);
								glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.sfVert[levelLoad.sfFaces[i]->faces[2]-1]->x,levelLoad.sfVert[levelLoad.sfFaces[i]->faces[2]-1]->y,levelLoad.sfVert[levelLoad.sfFaces[i]->faces[2]-1]->z);
								glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.sfVert[levelLoad.sfFaces[i]->faces[3]-1]->x,levelLoad.sfVert[levelLoad.sfFaces[i]->faces[3]-1]->y,levelLoad.sfVert[levelLoad.sfFaces[i]->faces[3]-1]->z);
							glEnd();	
							//char path2[] = "Images/Plants/tree1.png";
							////treeText1 = loadTexture(path2, 3);
							//glBindTexture(GL_TEXTURE_2D, texture3);
						}
					}else{
					//	std::cout << cVertex[levelLoad.sfFaces[i]->faces[0]-1]->x << cVertex[levelLoad.sfFaces[i]->faces[0]-1]->y << cVertex[levelLoad.sfFaces[i]->faces[0]-1]->z << std::endl;
						//std::cout << vertex[levelLoad.sfFaces[i]->faces[1]-1]->x << vertex[levelLoad.sfFaces[i]->faces[1]-1]->y << vertex[levelLoad.sfFaces[i]->faces[1]-1]->z << std::endl;
						//std::cout << vertex[levelLoad.sfFaces[i]->faces[2]-1]->x << vertex[levelLoad.sfFaces[i]->faces[2]-1]->y << vertex[levelLoad.sfFaces[i]->faces[2]-1]->z << std::endl;
						glBegin(GL_TRIANGLES);
							//glBindTexture(GL_TEXTURE_2D, texture3);
							glNormal3f(levelLoad.sfNormals[levelLoad.sfFaces[i]->facenum-1]->x,levelLoad.sfNormals[levelLoad.sfFaces[i]->facenum-1]->y,levelLoad.sfNormals[levelLoad.sfFaces[i]->facenum-1]->z);
							glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.sfVert[levelLoad.sfFaces[i]->faces[0]-1]->x,levelLoad.sfVert[levelLoad.sfFaces[i]->faces[0]-1]->y,levelLoad.sfVert[levelLoad.sfFaces[i]->faces[0]-1]->z);
							glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.sfVert[levelLoad.sfFaces[i]->faces[1]-1]->x,levelLoad.sfVert[levelLoad.sfFaces[i]->faces[1]-1]->y,levelLoad.sfVert[levelLoad.sfFaces[i]->faces[1]-1]->z);
							glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.sfVert[levelLoad.sfFaces[i]->faces[2]-1]->x,levelLoad.sfVert[levelLoad.sfFaces[i]->faces[2]-1]->y,levelLoad.sfVert[levelLoad.sfFaces[i]->faces[2]-1]->z);
						glEnd();
					}
				//}
			}
	for(int i=0;i< levelLoad.moFaces.size();i++){	
					//if((i+1) % 6 == 0){	
					//if(levelLoad.moVert[levelLoad.moFaces[i]->faces[0]-1]->y < py){

							if(levelLoad.moFaces[i]->four){	//if it's a quad draw a quad
								//if((i+1) % 6 != 0){
								//	std::cout << "here 1" << std::endl;
									glBegin(GL_QUADS);
										//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
										//I subtract 1 because the index start from 0 in C++
										
										glNormal3f(levelLoad.moNormals[levelLoad.moFaces[i]->facenum-1]->x,levelLoad.moNormals[levelLoad.moFaces[i]->facenum-1]->y,levelLoad.moNormals[levelLoad.moFaces[i]->facenum-1]->z);
										//draw the faces
										glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.moVert[levelLoad.moFaces[i]->faces[0]-1]->x,levelLoad.moVert[levelLoad.moFaces[i]->faces[0]-1]->y,levelLoad.moVert[levelLoad.moFaces[i]->faces[0]-1]->z);
										glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.moVert[levelLoad.moFaces[i]->faces[1]-1]->x,levelLoad.moVert[levelLoad.moFaces[i]->faces[1]-1]->y,levelLoad.moVert[levelLoad.moFaces[i]->faces[1]-1]->z);
										glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.moVert[levelLoad.moFaces[i]->faces[2]-1]->x,levelLoad.moVert[levelLoad.moFaces[i]->faces[2]-1]->y,levelLoad.moVert[levelLoad.moFaces[i]->faces[2]-1]->z);
										glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.moVert[levelLoad.moFaces[i]->faces[3]-1]->x,levelLoad.moVert[levelLoad.moFaces[i]->faces[3]-1]->y,levelLoad.moVert[levelLoad.moFaces[i]->faces[3]-1]->z);
									glEnd();
								}else{
									
									//char path[] = "Images/block3.png";
									//treeText1= loadTexture(path,3);
									//glBindTexture(GL_TEXTURE_2D, texture5);
									glBegin(GL_QUADS);
										//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
										//I subtract 1 because the index start from 0 in C++
										
										glNormal3f(levelLoad.moNormals[levelLoad.moFaces[i]->facenum-1]->x,levelLoad.moNormals[levelLoad.moFaces[i]->facenum-1]->y,levelLoad.moNormals[levelLoad.moFaces[i]->facenum-1]->z);
										//draw the faces
										glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.moVert[levelLoad.moFaces[i]->faces[0]-1]->x,levelLoad.moVert[levelLoad.moFaces[i]->faces[0]-1]->y,levelLoad.moVert[levelLoad.moFaces[i]->faces[0]-1]->z);
										glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.moVert[levelLoad.moFaces[i]->faces[1]-1]->x,levelLoad.moVert[levelLoad.moFaces[i]->faces[1]-1]->y,levelLoad.moVert[levelLoad.moFaces[i]->faces[1]-1]->z);
										glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.moVert[levelLoad.moFaces[i]->faces[2]-1]->x,levelLoad.moVert[levelLoad.moFaces[i]->faces[2]-1]->y,levelLoad.moVert[levelLoad.moFaces[i]->faces[2]-1]->z);
										glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.moVert[levelLoad.moFaces[i]->faces[3]-1]->x,levelLoad.moVert[levelLoad.moFaces[i]->faces[3]-1]->y,levelLoad.moVert[levelLoad.moFaces[i]->faces[3]-1]->z);
									glEnd();	
									//char path2[] = "Images/Plants/tree1.png";
									////treeText1 = loadTexture(path2, 3);
									//glBindTexture(GL_TEXTURE_2D, texture3);
								}
					//	}
				//}
			}
			for(int i=0;i< levelLoad.moUFaces.size();i++){	
					//if((i+1) % 6 == 0){	
					//if(levelLoad.moUVert[levelLoad.moUFaces[i]->faces[0]-1]->y < py){

							if(levelLoad.moUFaces[i]->four){	//if it's a quad draw a quad
								//if((i+1) % 6 != 0){
								//	std::cout << "here 1" << std::endl;
									glBegin(GL_QUADS);
										//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
										//I subtract 1 because the index start from 0 in C++
										
										glNormal3f(levelLoad.moUNormals[levelLoad.moUFaces[i]->facenum-1]->x,levelLoad.moUNormals[levelLoad.moUFaces[i]->facenum-1]->y,levelLoad.moUNormals[levelLoad.moUFaces[i]->facenum-1]->z);
										//draw the faces
										glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.moUVert[levelLoad.moUFaces[i]->faces[0]-1]->x,levelLoad.moUVert[levelLoad.moUFaces[i]->faces[0]-1]->y,levelLoad.moUVert[levelLoad.moUFaces[i]->faces[0]-1]->z);
										glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.moUVert[levelLoad.moUFaces[i]->faces[1]-1]->x,levelLoad.moUVert[levelLoad.moUFaces[i]->faces[1]-1]->y,levelLoad.moUVert[levelLoad.moUFaces[i]->faces[1]-1]->z);
										glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.moUVert[levelLoad.moUFaces[i]->faces[2]-1]->x,levelLoad.moUVert[levelLoad.moUFaces[i]->faces[2]-1]->y,levelLoad.moUVert[levelLoad.moUFaces[i]->faces[2]-1]->z);
										glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.moUVert[levelLoad.moUFaces[i]->faces[3]-1]->x,levelLoad.moUVert[levelLoad.moUFaces[i]->faces[3]-1]->y,levelLoad.moUVert[levelLoad.moUFaces[i]->faces[3]-1]->z);
									glEnd();
								}else{
									
									//char path[] = "Images/block3.png";
									//treeText1= loadTexture(path,3);
									//glBindTexture(GL_TEXTURE_2D, texture5);
									glBegin(GL_QUADS);
										//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
										//I subtract 1 because the index start from 0 in C++
										
										glNormal3f(levelLoad.moUNormals[levelLoad.moUFaces[i]->facenum-1]->x,levelLoad.moUNormals[levelLoad.moUFaces[i]->facenum-1]->y,levelLoad.moUNormals[levelLoad.moUFaces[i]->facenum-1]->z);
										//draw the faces
										glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.moUVert[levelLoad.moUFaces[i]->faces[0]-1]->x,levelLoad.moUVert[levelLoad.moUFaces[i]->faces[0]-1]->y,levelLoad.moUVert[levelLoad.moUFaces[i]->faces[0]-1]->z);
										glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.moUVert[levelLoad.moUFaces[i]->faces[1]-1]->x,levelLoad.moUVert[levelLoad.moUFaces[i]->faces[1]-1]->y,levelLoad.moUVert[levelLoad.moUFaces[i]->faces[1]-1]->z);
										glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.moUVert[levelLoad.moUFaces[i]->faces[2]-1]->x,levelLoad.moUVert[levelLoad.moUFaces[i]->faces[2]-1]->y,levelLoad.moUVert[levelLoad.moUFaces[i]->faces[2]-1]->z);
										glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.moUVert[levelLoad.moUFaces[i]->faces[3]-1]->x,levelLoad.moUVert[levelLoad.moUFaces[i]->faces[3]-1]->y,levelLoad.moUVert[levelLoad.moUFaces[i]->faces[3]-1]->z);
									glEnd();	
									//char path2[] = "Images/Plants/tree1.png";
									////treeText1 = loadTexture(path2, 3);
									//glBindTexture(GL_TEXTURE_2D, texture3);
								}
					//	}
				//}
			}
		for(int i=0;i< levelLoad.tFaces.size();i++){	
					//if((i+1) % 6 == 0){	
					//if(levelLoad.tVert[levelLoad.tFaces[i]->faces[0]-1]->y < py){

							if(levelLoad.tFaces[i]->four){	//if it's a quad draw a quad
								//if((i+1) % 6 != 0){
								//	std::cout << "here 1" << std::endl;
									glBegin(GL_QUADS);
										//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
										//I subtract 1 because the index start from 0 in C++
										
										glNormal3f(levelLoad.tNormals[levelLoad.tFaces[i]->facenum-1]->x,levelLoad.tNormals[levelLoad.tFaces[i]->facenum-1]->y,levelLoad.tNormals[levelLoad.tFaces[i]->facenum-1]->z);
										//draw the faces
										glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.tVert[levelLoad.tFaces[i]->faces[0]-1]->x,levelLoad.tVert[levelLoad.tFaces[i]->faces[0]-1]->y,levelLoad.tVert[levelLoad.tFaces[i]->faces[0]-1]->z);
										glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.tVert[levelLoad.tFaces[i]->faces[1]-1]->x,levelLoad.tVert[levelLoad.tFaces[i]->faces[1]-1]->y,levelLoad.tVert[levelLoad.tFaces[i]->faces[1]-1]->z);
										glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.tVert[levelLoad.tFaces[i]->faces[2]-1]->x,levelLoad.tVert[levelLoad.tFaces[i]->faces[2]-1]->y,levelLoad.tVert[levelLoad.tFaces[i]->faces[2]-1]->z);
										glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.tVert[levelLoad.tFaces[i]->faces[3]-1]->x,levelLoad.tVert[levelLoad.tFaces[i]->faces[3]-1]->y,levelLoad.tVert[levelLoad.tFaces[i]->faces[3]-1]->z);
									glEnd();
								}else{
									
									//char path[] = "Images/block3.png";
									//treeText1= loadTexture(path,3);
									//glBindTexture(GL_TEXTURE_2D, texture5);
									glBegin(GL_QUADS);
										//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
										//I subtract 1 because the index start from 0 in C++
										
										glNormal3f(levelLoad.tNormals[levelLoad.tFaces[i]->facenum-1]->x,levelLoad.tNormals[levelLoad.tFaces[i]->facenum-1]->y,levelLoad.tNormals[levelLoad.tFaces[i]->facenum-1]->z);
										//draw the faces
										glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.tVert[levelLoad.tFaces[i]->faces[0]-1]->x,levelLoad.tVert[levelLoad.tFaces[i]->faces[0]-1]->y,levelLoad.tVert[levelLoad.tFaces[i]->faces[0]-1]->z);
										glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.tVert[levelLoad.tFaces[i]->faces[1]-1]->x,levelLoad.tVert[levelLoad.tFaces[i]->faces[1]-1]->y,levelLoad.tVert[levelLoad.tFaces[i]->faces[1]-1]->z);
										glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.tVert[levelLoad.tFaces[i]->faces[2]-1]->x,levelLoad.tVert[levelLoad.tFaces[i]->faces[2]-1]->y,levelLoad.tVert[levelLoad.tFaces[i]->faces[2]-1]->z);
										glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.tVert[levelLoad.tFaces[i]->faces[3]-1]->x,levelLoad.tVert[levelLoad.tFaces[i]->faces[3]-1]->y,levelLoad.tVert[levelLoad.tFaces[i]->faces[3]-1]->z);
									glEnd();	
									//char path2[] = "Images/Plants/tree1.png";
									////treeText1 = loadTexture(path2, 3);
									//glBindTexture(GL_TEXTURE_2D, texture3);
								}
					//	}
				//}
			}
			
			//glBindTexture(GL_TEXTURE_2D, magTexture);
				for(int i=0;i< levelLoad.maFaces.size();i++){	
						
						if(levelLoad.maFaces[i]->four){	//if it's a quad draw a quad

							//	std::cout << "here 1" << std::endl;
							glBegin(GL_QUADS);
								//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
								//I submaact 1 because the index start from 0 in C++
								
								glNormal3f(levelLoad.maNormals[levelLoad.maFaces[i]->facenum-1]->x,levelLoad.maNormals[levelLoad.maFaces[i]->facenum-1]->y,levelLoad.maNormals[levelLoad.maFaces[i]->facenum-1]->z);
							//draw the faces
								glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.maVert[levelLoad.maFaces[i]->faces[0]-1]->x ,levelLoad.maVert[levelLoad.maFaces[i]->faces[0]-1]->y ,levelLoad.maVert[levelLoad.maFaces[i]->faces[0]-1]->z );
								glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.maVert[levelLoad.maFaces[i]->faces[1]-1]->x ,levelLoad.maVert[levelLoad.maFaces[i]->faces[1]-1]->y ,levelLoad.maVert[levelLoad.maFaces[i]->faces[1]-1]->z );
								glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.maVert[levelLoad.maFaces[i]->faces[2]-1]->x ,levelLoad.maVert[levelLoad.maFaces[i]->faces[2]-1]->y ,levelLoad.maVert[levelLoad.maFaces[i]->faces[2]-1]->z );
								glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.maVert[levelLoad.maFaces[i]->faces[3]-1]->x ,levelLoad.maVert[levelLoad.maFaces[i]->faces[3]-1]->y ,levelLoad.maVert[levelLoad.maFaces[i]->faces[3]-1]->z );
							glEnd();

						}else{
						//	std::cout << cVertex[levelLoad.maFaces[i]->faces[0]-1]->x << cVertex[levelLoad.maFaces[i]->faces[0]-1]->y << cVertex[levelLoad.maFaces[i]->faces[0]-1]->z << std::endl;
							//std::cout << vertex[levelLoad.maFaces[i]->faces[1]-1]->x << vertex[levelLoad.maFaces[i]->faces[1]-1]->y << vertex[levelLoad.maFaces[i]->faces[1]-1]->z << std::endl;
							//std::cout << vertex[levelLoad.maFaces[i]->faces[2]-1]->x << vertex[levelLoad.maFaces[i]->faces[2]-1]->y << vertex[levelLoad.maFaces[i]->faces[2]-1]->z << std::endl;
							glBegin(GL_TRIANGLES);
								//glBindTexture(GL_TEXTURE_2D, texture3);
								glNormal3f(levelLoad.maNormals[levelLoad.maFaces[i]->facenum-1]->x,levelLoad.maNormals[levelLoad.maFaces[i]->facenum-1]->y,levelLoad.maNormals[levelLoad.maFaces[i]->facenum-1]->z);
								glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.maVert[levelLoad.maFaces[i]->faces[0]-1]->x ,levelLoad.maVert[levelLoad.maFaces[i]->faces[0]-1]->y ,levelLoad.maVert[levelLoad.maFaces[i]->faces[0]-1]->z );
								glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.maVert[levelLoad.maFaces[i]->faces[1]-1]->x ,levelLoad.maVert[levelLoad.maFaces[i]->faces[1]-1]->y ,levelLoad.maVert[levelLoad.maFaces[i]->faces[1]-1]->z );
								glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.maVert[levelLoad.maFaces[i]->faces[2]-1]->x ,levelLoad.maVert[levelLoad.maFaces[i]->faces[2]-1]->y ,levelLoad.maVert[levelLoad.maFaces[i]->faces[2]-1]->z );
							glEnd();
						}
					}
				//glBindTexture(GL_TEXTURE_2D, spikeTexture);
				for(int i=0;i< levelLoad.spFaces.size();i++){	
						
						if(levelLoad.spFaces[i]->four){	//if it's a quad draw a quad

							//	std::cout << "here 1" << std::endl;
							glBegin(GL_QUADS);
								//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
								//I subspact 1 because the index start from 0 in C++
								
								glNormal3f(levelLoad.spNormals[levelLoad.spFaces[i]->facenum-1]->x,levelLoad.spNormals[levelLoad.spFaces[i]->facenum-1]->y,levelLoad.spNormals[levelLoad.spFaces[i]->facenum-1]->z);
							//draw the faces
								glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.spVert[levelLoad.spFaces[i]->faces[0]-1]->x ,levelLoad.spVert[levelLoad.spFaces[i]->faces[0]-1]->y ,levelLoad.spVert[levelLoad.spFaces[i]->faces[0]-1]->z );
								glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.spVert[levelLoad.spFaces[i]->faces[1]-1]->x ,levelLoad.spVert[levelLoad.spFaces[i]->faces[1]-1]->y ,levelLoad.spVert[levelLoad.spFaces[i]->faces[1]-1]->z );
								glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.spVert[levelLoad.spFaces[i]->faces[2]-1]->x ,levelLoad.spVert[levelLoad.spFaces[i]->faces[2]-1]->y ,levelLoad.spVert[levelLoad.spFaces[i]->faces[2]-1]->z );
								glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.spVert[levelLoad.spFaces[i]->faces[3]-1]->x ,levelLoad.spVert[levelLoad.spFaces[i]->faces[3]-1]->y ,levelLoad.spVert[levelLoad.spFaces[i]->faces[3]-1]->z );
							glEnd();

						}else{
						//	std::cout << cVertex[levelLoad.spFaces[i]->faces[0]-1]->x << cVertex[levelLoad.spFaces[i]->faces[0]-1]->y << cVertex[levelLoad.spFaces[i]->faces[0]-1]->z << std::endl;
							//std::cout << vertex[levelLoad.spFaces[i]->faces[1]-1]->x << vertex[levelLoad.spFaces[i]->faces[1]-1]->y << vertex[levelLoad.spFaces[i]->faces[1]-1]->z << std::endl;
							//std::cout << vertex[levelLoad.spFaces[i]->faces[2]-1]->x << vertex[levelLoad.spFaces[i]->faces[2]-1]->y << vertex[levelLoad.spFaces[i]->faces[2]-1]->z << std::endl;
							glBegin(GL_TRIANGLES);
								//glBindTexture(GL_TEXTURE_2D, texture3);
								glNormal3f(levelLoad.spNormals[levelLoad.spFaces[i]->facenum-1]->x,levelLoad.spNormals[levelLoad.spFaces[i]->facenum-1]->y,levelLoad.spNormals[levelLoad.spFaces[i]->facenum-1]->z);
								glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.spVert[levelLoad.spFaces[i]->faces[0]-1]->x ,levelLoad.spVert[levelLoad.spFaces[i]->faces[0]-1]->y ,levelLoad.spVert[levelLoad.spFaces[i]->faces[0]-1]->z );
								glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.spVert[levelLoad.spFaces[i]->faces[1]-1]->x ,levelLoad.spVert[levelLoad.spFaces[i]->faces[1]-1]->y ,levelLoad.spVert[levelLoad.spFaces[i]->faces[1]-1]->z );
								glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.spVert[levelLoad.spFaces[i]->faces[2]-1]->x ,levelLoad.spVert[levelLoad.spFaces[i]->faces[2]-1]->y ,levelLoad.spVert[levelLoad.spFaces[i]->faces[2]-1]->z );
							glEnd();
						}
					}
					
				//glDisable(GL_TEXTURE_2D);
			glPushMatrix();
			//glDisable(GL_TEXTURE_2D);
				if(!foundCrystal){
					glTranslatef(levelLoad.fVert[levelLoad.fFaces[0]->faces[0]-1]->x, 0,levelLoad.fVert[levelLoad.fFaces[0]->faces[0]-1]->z);
					glRotatef(coinSpin,0,1,0);
					glTranslatef(-levelLoad.fVert[levelLoad.fFaces[0]->faces[0]-1]->x, 0, -levelLoad.fVert[levelLoad.fFaces[0]->faces[0]-1]->z);
					for(int i=0;i< levelLoad.fFaces.size();i++){	
						
						if(levelLoad.fFaces[i]->four){	//if it's a quad draw a quad

							//	std::cout << "here 1" << std::endl;
							glBegin(GL_QUADS);
								//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
								//I subtract 1 because the index start from 0 in C++
								
								glNormal3f(levelLoad.fNormals[levelLoad.fFaces[i]->facenum-1]->x,levelLoad.fNormals[levelLoad.fFaces[i]->facenum-1]->y,levelLoad.fNormals[levelLoad.fFaces[i]->facenum-1]->z);
							//draw the faces
								glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.fVert[levelLoad.fFaces[i]->faces[0]-1]->x ,levelLoad.fVert[levelLoad.fFaces[i]->faces[0]-1]->y ,levelLoad.fVert[levelLoad.fFaces[i]->faces[0]-1]->z );
								glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.fVert[levelLoad.fFaces[i]->faces[1]-1]->x ,levelLoad.fVert[levelLoad.fFaces[i]->faces[1]-1]->y ,levelLoad.fVert[levelLoad.fFaces[i]->faces[1]-1]->z );
								glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.fVert[levelLoad.fFaces[i]->faces[2]-1]->x ,levelLoad.fVert[levelLoad.fFaces[i]->faces[2]-1]->y ,levelLoad.fVert[levelLoad.fFaces[i]->faces[2]-1]->z );
								glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.fVert[levelLoad.fFaces[i]->faces[3]-1]->x ,levelLoad.fVert[levelLoad.fFaces[i]->faces[3]-1]->y ,levelLoad.fVert[levelLoad.fFaces[i]->faces[3]-1]->z );
							glEnd();

						}else{
						//	std::cout << cVertex[levelLoad.fFaces[i]->faces[0]-1]->x << cVertex[levelLoad.fFaces[i]->faces[0]-1]->y << cVertex[levelLoad.fFaces[i]->faces[0]-1]->z << std::endl;
							//std::cout << vertex[levelLoad.fFaces[i]->faces[1]-1]->x << vertex[levelLoad.fFaces[i]->faces[1]-1]->y << vertex[levelLoad.fFaces[i]->faces[1]-1]->z << std::endl;
							//std::cout << vertex[levelLoad.fFaces[i]->faces[2]-1]->x << vertex[levelLoad.fFaces[i]->faces[2]-1]->y << vertex[levelLoad.fFaces[i]->faces[2]-1]->z << std::endl;
							glBegin(GL_TRIANGLES);
								//glBindTexture(GL_TEXTURE_2D, texture3);
								glNormal3f(levelLoad.fNormals[levelLoad.fFaces[i]->facenum-1]->x,levelLoad.fNormals[levelLoad.fFaces[i]->facenum-1]->y,levelLoad.fNormals[levelLoad.fFaces[i]->facenum-1]->z);
								glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.fVert[levelLoad.fFaces[i]->faces[0]-1]->x ,levelLoad.fVert[levelLoad.fFaces[i]->faces[0]-1]->y ,levelLoad.fVert[levelLoad.fFaces[i]->faces[0]-1]->z );
								glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.fVert[levelLoad.fFaces[i]->faces[1]-1]->x ,levelLoad.fVert[levelLoad.fFaces[i]->faces[1]-1]->y ,levelLoad.fVert[levelLoad.fFaces[i]->faces[1]-1]->z );
								glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.fVert[levelLoad.fFaces[i]->faces[2]-1]->x ,levelLoad.fVert[levelLoad.fFaces[i]->faces[2]-1]->y ,levelLoad.fVert[levelLoad.fFaces[i]->faces[2]-1]->z );
							glEnd();
						}
					}
				}
				//glCallList(marble);
				glPopMatrix();
				
				
}



/* Create a matrix that will project the desired shadow. */

const int shadowMapSize= 2048;

//Textures

MATRIX4X4 lightProjectionMatrix, lightViewMatrix;
MATRIX4X4 cameraProjectionMatrix, cameraViewMatrix;
VECTOR3D cameraPosition(-2.5f, 10.f,-15.f);
VECTOR3D lightPosition(2.0f, 10.0f,2.0f);


int finishCollision(level &level){
	float py2 = py - 0.7;/// = ((py) *-1) + 2.5;
	float width = 0.595634;
	float height = 0.595634;
	for(int i = 0; i < level.fFaces.size(); i++){
		if(level.fVert[level.fFaces[i]->faces[1]-1]->x +width > (px - width/2) && level.fVert[level.fFaces[i]->faces[1]-1]->x  < (px + width) ){
			if(level.fVert[level.fFaces[i]->faces[1]-1]->z +width > (pz -width/2) && level.fVert[level.fFaces[i]->faces[1]-1]->z  < (pz + width)){
				if(level.fVert[level.fFaces[i]->faces[1]-1]->y + height > py2 && level.fVert[level.fFaces[i]->faces[1]-1]->y  < py2 - height + 0.25){
					if(world != 0){
						foundCrystal = true;
					}
				}
			}
		}
	}
	for(int i = 0; i < level.eFaces.size(); i++){
		if(level.eVert[level.eFaces[i]->faces[1]-1]->x +width > (px - width/2) && level.eVert[level.eFaces[i]->faces[1]-1]->x  < (px + width) ){
			if(level.eVert[level.eFaces[i]->faces[1]-1]->z +width > (pz -width/2) && level.eVert[level.eFaces[i]->faces[1]-1]->z  < (pz + width)){
				if(level.eVert[level.eFaces[i]->faces[1]-1]->y + height > py2 && level.eVert[level.eFaces[i]->faces[1]-1]->y  < py2 - height + 0.25){
					if(foundCrystal){
						return 1;
						
					}
				}
			}
		}
	}
	return 0;
}
	sf::Sound collect;
	sf::SoundBuffer Cbuffer;
void crystalCollision(level &level){
	float py2 = py - 0.7;/// = ((py) *-1) + 2.5;
	float width = 1;
	float height = 2;
	for(int z = 0; z < binCount; z++){
		for(int i=0;i< level.biFaces.size(); i++){
			if(level.biVert[level.biFaces[i]->faces[1]-1]->x +width +binX[z] > (px - width/2) && level.biVert[level.biFaces[i]->faces[1]-1]->x +binX[z] < (px + width) ){
				if(level.biVert[level.biFaces[i]->faces[1]-1]->z +width +binZ[z]> (pz -width/2) && level.biVert[level.biFaces[i]->faces[1]-1]->z + binZ[z] < (pz + width)){
					if(binY[z] + height > py2 && binY[z]  < py2 + height){
						if(!binCollected[z] && sucking){
								//binVentory++;
								binamation[z] = true;
								//sucking = false;
								//binCollected[z] = true;
							
						}
					}
				}
			}
		}
		if(throwX > (px - width/2) && throwX < (px + width) ){
			if(throwZ > (pz -width/2) && throwZ < (pz + width)){
				if(throwY +  height > py2 && throwY < py2 + height){
					if(binCollected[z] && sucking){
								//binVentory++;
						binScale[z] = 1;
						binamation[z] = true;
						throwing = false;
								//sucking = false;
						binCollected[z] = true;
							
					}
				}
			}
		}
	}
	
	for(int z = 0; z < 100; z++){
		if(shownPause[z] && !pauseBounce[z]){
			for(int i=0;i< level.paFaces.size(); i++){
				if(level.paVert[level.paFaces[i]->faces[1]-1]->x +width +pauseSkewX[z] > (px - width/2) && level.paVert[level.paFaces[i]->faces[1]-1]->x +pauseSkewX[z] < (px + width) ){
					if(level.paVert[level.paFaces[i]->faces[1]-1]->z +width +pauseSkewZ[z]> (pz -width/2) && level.paVert[level.paFaces[i]->faces[1]-1]->z +pauseSkewZ[z] < (pz + width)){
						if(pauseSkewY[z] + height > py2 && pauseSkewY[z]  < py2 + height){
							if(pauseCollectable[z]){
								pauseSpawnX[z] = -1000;
								shownPause[z] = false;
								pauseCollectable[z] = false;
								pauseInven++;
								
								if(pauseInven % 40 ==0){
									pauseInven-= 40;
									pauseCounter++;
									collect.play();
								}
							}
						}
					}
				}
			}
		}
		if(shownRewind[z] && !rewindBounce[z]){
			for(int i= 0; i < level.reFaces.size(); i++){
				if(level.reVert[level.reFaces[i]->faces[1]-1]->x + rewindSkewX[z] +width > (px - width/2) && level.reVert[level.reFaces[i]->faces[1]-1]->x + rewindSkewX[z] < (px + width) ){
					if(level.reVert[level.reFaces[i]->faces[1]-1]->z+ rewindSkewZ[z] +width > (pz -width/2) && level.reVert[level.reFaces[i]->faces[1]-1]->z  + rewindSkewZ[z] < (pz + width)){
						if(rewindSkewY[z] + height > py2 && rewindSkewY[z]  < py2 + height){
							if(rewindCollectable[z]){
								rewindSpawnX[z] = -1000;
								shownRewind[z] = false;
								rewindCollectable[z] = false;
								rewindInven++;
								
								if(rewindInven % 40 ==0){
									rewindInven-= 40;
									rewindCounter++;
									collect.play();
								}
							}
						}
					}
				}
			}
		}
		if(shownForward[z] && !forwardBounce[z]){
			for(int i = 0;i < level.frFaces.size(); i++){
				if(level.frVert[level.frFaces[i]->faces[1]-1]->x +width +forwardSkewX[z]> (px - width/2) && level.frVert[level.frFaces[i]->faces[1]-1]->x +forwardSkewX[z] < (px + width) ){
					if(level.frVert[level.frFaces[i]->faces[1]-1]->z +width +forwardSkewZ[z] > (pz -width/2) && level.frVert[level.frFaces[i]->faces[1]-1]->z  + forwardSkewZ[z] < (pz + width)){
						if(forwardSkewY[z] + height > py2 && forwardSkewY[z]  < py2 + height){
							if(forwardCollectable[z]){
								forwardSpawnX[z] = -1000;
								shownForward[z] = false;
								forwardCollectable[z] = false;
								forwardInven++;
								
								if(forwardInven % 40 ==0){
									forwardInven-= 40;
									forwardCounter++;
									collect.play();
								}
							}
						}
					}
				}
			}
		}
	}
}



bool randomBool() {
    if (rand() % 2 == 0)
        return true;
    else return false;
}
float RandomFloat() {
	float a = -2;
	float b = 2;
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

int enemyCollision(level &level){
	float py2 = py - 0.7;/// = ((py) *-1) + 2.5;
	float width = 0.595634;
	float height = 0.595634;
	float objectWidth = 2;
	float objectHeight = 2;
	for(int z = 0; z < factoryCounter; z++){
		if(!factoryDead[z]){
			if(factoryX[z] +objectWidth  > throwX && factoryX[z] < (throwX + objectWidth) ){
				if(factoryZ[z] +objectWidth > throwZ && factoryZ[z] < (throwZ + objectWidth)){
					if(factoryY[z] + objectWidth > (throwY - 0.7) && factoryY[z]  < (throwY -0.7) + objectHeight){
						factoryDead[z] = true;
					}
				}
			}
		}
	}
	for(int z =0;z < fMinionSize; z++){
		
			if(factoryMinionY[z] != -1000){
				if(factoryMinionX[z] +objectWidth  > px && factoryMinionX[z] < (px + objectWidth) ){
					if(factoryMinionZ[z] +objectWidth > pz && factoryMinionZ[z] < (pz + objectWidth)){
						if(factoryMinionY[z] + objectWidth > (py - 0.7) && factoryMinionY[z]  < (py -0.7) + objectHeight){
							return 1;
						}
					}
				}
			}
			
			if(factoryMinionX[z] +objectWidth  > throwX && factoryMinionX[z] < (throwX + objectWidth) ){
				if(factoryMinionZ[z] +objectWidth > throwZ && factoryMinionZ[z] < (throwZ + objectWidth)){
					if(factoryMinionY[z] + objectWidth > (throwY - 0.7) && factoryMinionY[z]  < (throwY -0.7) + objectHeight){
						factoryMinionX[z] = -1000;
						factoryMinionY[z] = -1000;
						factoryMinionZ[z] = -1000;
					}
				}
			}
	}
	for(int z =0; z < tmCount; z++){
		if(!tmKilled[z]){
			if(tMonsterX[z] +objectWidth  > px && tMonsterX[z] < (px + objectWidth) ){
				if(tMonsterZ[z] +objectWidth > pz && tMonsterZ[z] < (pz + objectWidth)){
					if(tMonsterY[z] + objectWidth > (py - 0.7) && tMonsterY[z]  < (py -0.7) + objectHeight){
						return 1;
					}
				}
			}
			if(tMonsterX[z] +objectWidth  > throwX && tMonsterX[z] < (throwX + objectWidth) ){
				if(tMonsterZ[z] +objectWidth > throwZ && tMonsterZ[z] < (throwZ + objectWidth)){
					if(tMonsterY[z] + objectWidth > (throwY - 0.7) && tMonsterY[z]  < (throwY -0.7) + objectHeight){
						if(tMonsterType[z] == 0 && pauseTime){
							throwing = false;
							tmKilled[z] = true;
						}else if(tMonsterType[z] ==1 && forwardTime){
							throwing = false;
							tmKilled[z] = true;
						}else if(tMonsterType[z] == 10){
							tmKilled[z] = true;
							foundCrystal = true;
						}
					}
				}
			}
		}
	}
	for(int z = 0; z < bombCount; z++){
		//for(int i = 0; i < level.bFaces.size(); i++){
		if(bombX[z] +objectWidth  > throwX && bombX[z] < (throwX + objectWidth) ){
			if(bombZ[z] +objectWidth > throwZ && bombZ[z] < (throwZ + objectWidth)){
				if(bombY[z] + objectWidth > (throwY - 0.7) && bombY[z]  < (throwY -0.7) + objectHeight){
					throwing = false;
						
					
					enKilled[z] = true;
				}
			}
		}
		//}
		if(!enKilled[z]){
			float enDimensions = 1;
			if(bombX[z] +enDimensions  > px && bombX[z] < (px + enDimensions) ){
				if(bombZ[z] +enDimensions > pz && bombZ[z] < (pz + enDimensions)){
					if(bombY[z] + enDimensions > (py - 0.7) && bombY[z]  < (py -0.7) +enDimensions){
							return 1;
					}
				}
			}
		}
	}
	for(int z = 0; z < sqCount; z++){
		if(squX[z] +objectHeight > throwX && squX[z] < (throwX + objectWidth) ){
			if(squZ[z] +objectHeight > throwZ && squZ[z] < (throwZ + objectWidth)){
				if(squY[z] + objectHeight > (throwY - 0.7) && squY[z]  < (throwY -0.7) + objectHeight){
					throwing = false;
					squKilled[z] = true;
				}
			}
		}
	}
	if(world ==0){
		if(bossX +objectWidth  > px && bossX < (px + objectWidth) ){
			if(bossZ +objectWidth > pz && bossZ < (pz + objectWidth)){
				if(bossY + objectWidth > (py - 0.7) && bossY  < (py -0.7) + objectHeight){
					return 1;
				}
			}
		}
		if(throwing){
			if(bossX +objectWidth  > throwX && bossX < (throwX + objectWidth) ){
				if(bossZ +objectWidth > throwZ && bossZ < (throwZ + objectWidth)){
					if(bossY + objectWidth > (throwY - 0.7) && bossY  < (throwY -0.7) + objectHeight){
						throwing = false;
						if(part == 10){
							if(pauseTime){
								//pauseTime = false;
								//rewindTime = false;
								//forwardTime = false;
								bossLives -= 1;
								if(bossLives < 1){
									bossKilled = true;
									foundCrystal = true;
								}
							}
						}
					}
				}
			}
		}
	}
	for(int z = 0; z < projectCount; z++){
		if(projectX[z] +objectWidth  > px && projectX[z] < (px + objectWidth) ){
			if(projectZ[z] +objectWidth > pz && projectZ[z] < (pz + objectWidth)){
				if(projectY[z] + objectWidth > (py - 0.7) && projectY[z]  < (py -0.7) + objectHeight){
					return 1;
				}
			}
		}
		
		if(firePrX[z] +objectWidth  > px && firePrX[z] < (px + objectWidth) ){
			if(firePrZ[z] +objectWidth> pz && firePrZ[z] < (pz + objectWidth)){
				if(firePrY[z] + objectWidth > (py - 0.7) && firePrY[z]  < (py -0.7) + objectHeight){
					return 1;
				}
			}
		}
	}
	for(int i = 0; i < level.spFaces.size(); i++){
		if(level.spVert[level.spFaces[i]->faces[1]-1]->x +width > (px - width/2) && level.spVert[level.spFaces[i]->faces[1]-1]->x  < (px + width) ){
			if(level.spVert[level.spFaces[i]->faces[1]-1]->z +width > (pz -width/2) && level.spVert[level.spFaces[i]->faces[1]-1]->z  < (pz + width)){
				if(level.spVert[level.spFaces[i]->faces[1]-1]->y + height > py && level.spVert[level.spFaces[i]->faces[1]-1]->y  < height){	
					return 1;
				}
			}
		}
	}
	width = 2;
	height = 2;
	for(int z = 0; z < sqCount; z++){
		if(!squKilled[z]){
			if(squX[z] +width  > px && squX[z] < (px + width) ){
				if(squZ[z] +width > pz && squZ[z] < (pz + width)){
					if(squY[z] + height > (py - 0.7) && squY[z]  < (py -0.7) +height){
							squHit[z] = true;
							squHitCounter[z] = 0;
							return 1;
					}
				}
			}
		}
	}
	
	return 0;
}
int factoryCollision(level &level, int counter){
	float fy = factoryMinionY[counter];
	float fx = factoryMinionX[counter];
	float fz = factoryMinionZ[counter];
	float width = 0.595634;
	float height = 0.595634;
	bool foundLand = false;
	for(int i = 0; i < level.tFaces.size(); i++){
		float differenceX = level.tVert[level.tFaces[i]->faces[1]-1]->x - fx;
		float differenceZ = level.tVert[level.tFaces[i]->faces[1]-1]->z - fz;
		if(differenceX * differenceX < 1 && differenceZ * differenceZ < 1){
			if(level.tVert[level.tFaces[i]->faces[1]-1]->x +width > (fx) && level.tVert[level.tFaces[i]->faces[1]-1]->x  < (fx + width) ){
				//cout << "gotx"<< endl;
				if(level.tVert[level.tFaces[i]->faces[1]-1]->z +width > (fz) && level.tVert[level.tFaces[i]->faces[1]-1]->z  < (fz + width)){
					//cout << "gozx" << endl;
					if(level.tVert[level.tFaces[i]->faces[1]-1]->y + height > fy && level.tVert[level.tFaces[i]->faces[1]-1]->y  < fy +height){
			
						foundLand = true;
					}
				}
			}
		}
	}
	if(!foundLand){
		return 0;
	}else{
		return 1;
	}
}
int mapCollision(level &level){
	float py2 = py - 0.7;/// = ((py) *-1) + 2.5;
	float width = 0.595634;
	float height = 0.595634;
	bool foundLand = false;
	for(int i = 0; i < level.pFaces.size(); i++){
		float differenceX = level.pVert[level.pFaces[i]->faces[1]-1]->x - px;
		float differenceZ = level.pVert[level.pFaces[i]->faces[1]-1]->z - pz;
		if(differenceX * differenceX < 1 && differenceZ * differenceZ < 1){
			if(level.pVert[level.pFaces[i]->faces[1]-1]->x +width > (px - width/2) && level.pVert[level.pFaces[i]->faces[1]-1]->x  < (px + width) ){
				if(level.pVert[level.pFaces[i]->faces[1]-1]->z +width > (pz -width/2) && level.pVert[level.pFaces[i]->faces[1]-1]->z  < (pz + width)){
					if(level.pVert[level.pFaces[i]->faces[1]-1]->y + height > py2 && level.pVert[level.pFaces[i]->faces[1]-1]->y  < py2 - height + 0.25){
					
							
							foundLand = true;
					}
				}
			}
		}
	}
	
	for(int i = 0; i < level.spFaces.size(); i++){
		if(level.spVert[level.spFaces[i]->faces[1]-1]->x +width > (px - width/2) && level.spVert[level.spFaces[i]->faces[1]-1]->x  < (px + width) ){
			if(level.spVert[level.spFaces[i]->faces[1]-1]->z +width > (pz -width/2) && level.spVert[level.spFaces[i]->faces[1]-1]->z  < (pz + width)){
				if(level.spVert[level.spFaces[i]->faces[1]-1]->y + height > py2 && level.spVert[level.spFaces[i]->faces[1]-1]->y  < py2 + height){	
					py = 5;
					pz =0;
					px = 0;
					std::string moMap = "Objects/world";
					moMap += std::to_string(world);
					moMap += "/moving";
					moMap += std::to_string(part);
					moMap += ".obj";
					char* moArray = (char*) moMap.c_str();
					level.loadMoving(moArray);
				}
			}
		}
	}
	bool onMoving = false;
	bool onMovingU = false;
	for(int i =0; i < level.moFaces.size();i++){
		if(level.moVert[level.moFaces[i]->faces[1]-1]->x +width > (px - width/2) && level.moVert[level.moFaces[i]->faces[1]-1]->x  < (px + width) ){
			if(level.moVert[level.moFaces[i]->faces[1]-1]->z +width > (pz -width/2) && level.moVert[level.moFaces[i]->faces[1]-1]->z  < (pz + width)){
				if(level.moVert[level.moFaces[i]->faces[1]-1]->y + height > py2 && level.moVert[level.moFaces[i]->faces[1]-1]->y  < py2 - height + 0.25){
					foundLand = true;
					onMoving = true;
				}
			}
		}
	}
	for(int i =0; i < level.moUFaces.size();i++){
		if(level.moUVert[level.moUFaces[i]->faces[1]-1]->x +width > (px - width/2) && level.moUVert[level.moUFaces[i]->faces[1]-1]->x  < (px + width) ){
			if(level.moUVert[level.moUFaces[i]->faces[1]-1]->z +width > (pz -width/2) && level.moUVert[level.moUFaces[i]->faces[1]-1]->z  < (pz + width)){
				if(level.moUVert[level.moUFaces[i]->faces[1]-1]->y + height > py2 && level.moUVert[level.moUFaces[i]->faces[1]-1]->y  < py2 - height + 0.25){
					foundLand = true;
					onMovingU = true;
				}
			}
		}
	}
	if(onMoving){
		for(int i = 0; i < level.moFaces.size(); i++){
			level.moVert[level.moFaces[i]->faces[0]-1]->z -= 0.1;
			level.moVert[level.moFaces[i]->faces[1]-1]->z -= 0.1;
			level.moVert[level.moFaces[i]->faces[2]-1]->z -= 0.1;
			level.moVert[level.moFaces[i]->faces[3]-1]->z -= 0.1;
			//moveSkew -= 0.1;
		}
		pz -= 0.3;
	}
	
	if(onMovingU){
		for(int i = 0; i < level.moUFaces.size(); i++){
			level.moUVert[level.moUFaces[i]->faces[0]-1]->y += 0.1;
			level.moUVert[level.moUFaces[i]->faces[1]-1]->y += 0.1;
			level.moUVert[level.moUFaces[i]->faces[2]-1]->y += 0.1;
			level.moUVert[level.moUFaces[i]->faces[3]-1]->y += 0.1;
			
			//moveSkew -= 0.1;
		}
		py += 0.3;
	}
	for(int i = 0; i < level.pFaces.size(); i++){
		float differenceX = level.pVert[level.pFaces[i]->faces[1]-1]->x - px;
		float differenceZ = level.pVert[level.pFaces[i]->faces[1]-1]->z - pz;
		if(differenceX * differenceX < 1 && differenceZ * differenceZ < 1){
			if(level.pVert[level.pFaces[i]->faces[1]-1]->x +width > (px - width/2) && level.pVert[level.pFaces[i]->faces[1]-1]->x  < (px + width) ){
				if(level.pVert[level.pFaces[i]->faces[1]-1]->z +width > (pz -width/2) && level.pVert[level.pFaces[i]->faces[1]-1]->z  < (pz + width)){
					if(level.pVert[level.pFaces[i]->faces[1]-1]->y + height > py2 && level.pVert[level.pFaces[i]->faces[1]-1]->y  < py2 - height + 0.25){
							reflectSkew =0;
						
							foundLand = true;
						
					}else{
						float px2 = px;
						float pz2 = pz;
						if(level.pVert[level.pFaces[i]->faces[1]-1]->y +height > py  && level.pVert[level.pFaces[i]->faces[1]-1]->y < py + (height *2)){
							
							px2 = px + width/2;
							if(px2 < level.pVert[level.pFaces[i]->faces[1]-1]->x + width && px2 + width/2 > level.pVert[level.pFaces[i]->faces[1]-1]->x +width){
								px +=0.4;
								speed = 0.1;
								pRotateSpeed = 3;			
							}else{
								px2 = px - width/2;
								if(px2 + width > -level.pVert[level.pFaces[i]->faces[1]-1]->x && px2 + width < level.pVert[level.pFaces[i]->faces[1]-1]->x +(width/3 *2)){
									px -=0.4;	
									speed = 0.1;
									pRotateSpeed = 3;
								}
							}
							pz2 = pz - width/2;
							if(pz2 < level.pVert[level.pFaces[i]->faces[1]-1]->z + width && pz2 + width/2 > level.pVert[level.pFaces[i]->faces[1]-1]->z +width){
								pz +=0.4;
								speed = 0.1;
								pRotateSpeed = 3;			
							}else{
								pz2 = pz + width/2;
								if(pz2 + width > level.pVert[level.pFaces[i]->faces[1]-1]->z && pz2 + width < level.pVert[level.pFaces[i]->faces[1]-1]->z +(width/3 *2)){
									pz -=0.4;	
									speed = 0.1;
									pRotateSpeed = 3;
								}
							}
						}
					}		
				}
			}
		}
	}
	for(int i = 0; i < level.tFaces.size(); i++){
		float differenceX = level.tVert[level.tFaces[i]->faces[1]-1]->x - px;
		float differenceZ = level.tVert[level.tFaces[i]->faces[1]-1]->z - pz;
		if(differenceX * differenceX < 1 && differenceZ * differenceZ < 1){
			if(level.tVert[level.tFaces[i]->faces[1]-1]->x +width > (px - width/2) && level.tVert[level.tFaces[i]->faces[1]-1]->x  < (px + width) ){
				if(level.tVert[level.tFaces[i]->faces[1]-1]->z +width > (pz -width/2) && level.tVert[level.tFaces[i]->faces[1]-1]->z  < (pz + width)){
					if(level.tVert[level.tFaces[i]->faces[1]-1]->y + height > py2 && level.tVert[level.tFaces[i]->faces[1]-1]->y  < py2 - height + 0.25){
							reflectSkew =0;
						
							foundLand = true;
						
					}else{
						float px2 = px;
						float pz2 = pz;
						if(level.tVert[level.tFaces[i]->faces[1]-1]->y +height > py  && level.tVert[level.tFaces[i]->faces[1]-1]->y < py + (height *2)){
							
							px2 = px + width/2;
							if(px2 < level.tVert[level.tFaces[i]->faces[1]-1]->x + width && px2 + width/2 > level.tVert[level.tFaces[i]->faces[1]-1]->x +width){
								px +=0.4;
								speed = 0.1;
								pRotateSpeed = 3;			
							}else{
								px2 = px - width/2;
								if(px2 + width > -level.tVert[level.tFaces[i]->faces[1]-1]->x && px2 + width < level.tVert[level.tFaces[i]->faces[1]-1]->x +(width/3 *2)){
									px -=0.4;	
									speed = 0.1;
									pRotateSpeed = 3;
								}
							}
							pz2 = pz - width/2;
							if(pz2 < level.tVert[level.tFaces[i]->faces[1]-1]->z + width && pz2 + width/2 > level.tVert[level.tFaces[i]->faces[1]-1]->z +width){
								pz +=0.4;
								speed = 0.1;
								pRotateSpeed = 3;			
							}else{
								pz2 = pz + width/2;
								if(pz2 + width > level.tVert[level.tFaces[i]->faces[1]-1]->z && pz2 + width < level.tVert[level.tFaces[i]->faces[1]-1]->z +(width/3 *2)){
									pz -=0.4;	
									speed = 0.1;
									pRotateSpeed = 3;
								}
							}
						}
					}		
				}
			}
		}
	}
	bool slope = true;
	for(int i = 0; i < level.sFaces.size(); i++){
		if(level.sVert[level.sFaces[i]->faces[1]-1]->x +width > (px - width/2) && level.sVert[level.sFaces[i]->faces[1]-1]->x  < (px + width) ){
			if(level.sVert[level.sFaces[i]->faces[1]-1]->z +width > (pz -width/2) && level.sVert[level.sFaces[i]->faces[1]-1]->z  < (pz + width)){
				if(level.sVert[level.sFaces[i]->faces[1]-1]->y + height > py2 && level.sVert[level.sFaces[i]->faces[1]-1]->y  < py2 + 0.25){
					if(slope){
						reflectSkew = 1;
						if(py -0.6 > level.sVert[level.sFaces[i]->faces[1]-1]->y){
							py +=0.02 + (speed /10);
						}
					}
					foundLand = true;		
				}
			}
		}
	}
	slope = false;
	width = 5;
	for(int i = 0; i < trapCount; i++){
		if(trapX[i] +width > (px ) && trapX[i] < (px + width) ){
			if(trapZ[i] +width > (pz) && trapZ[i] < (pz + width)){
				if(trapY[i] + trapRespawn[i] + height > py2 && trapY[i] + trapRespawn[i]  < py2 - height + 0.25){
				
						trapTripped[i] = true;
						foundLand = true;
				}
			}
		}
	}
	//width = 4;
	float width2 = 8;
	width = 4;
	height = 4;
	for(int i = 0; i < level.maFaces.size(); i++){
		if(level.maVert[level.maFaces[i]->faces[1]-1]->x +width2 > (px ) && level.maVert[level.maFaces[i]->faces[1]-1]->x  < (px + width2) ){
			if(level.maVert[level.maFaces[i]->faces[1]-1]->z +width > (pz) && level.maVert[level.maFaces[i]->faces[1]-1]->z  < (pz + width)){
				if(level.maVert[level.maFaces[i]->faces[1]-1]->y +  height > py2 && level.maVert[level.maFaces[i]->faces[1]-1]->y  < py2 + height){
						if(level.maVert[level.maFaces[i]->faces[1]-1]->x > px){
							px += magnetSpeed;
						}else if(level.maVert[level.maFaces[i]->faces[1]-1]->x < px){
							px -= magnetSpeed;
						}
						if(level.maVert[level.maFaces[i]->faces[1]-1]->z > pz){
							pz += magnetSpeed/2;
						}else if(level.maVert[level.maFaces[i]->faces[1]-1]->z < pz){
							pz -= magnetSpeed/2;
						}
				}
			}
		}
	}
	if(!foundLand){
		return 0;
	}else{
		return 1;
	}
}
void material(int dlist, GLfloat * ambient, GLfloat * diffuse,
  GLfloat * specular, GLfloat shininess)
{
  glNewList(dlist, GL_COMPILE);
  glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
  glMaterialf(GL_FRONT, GL_SHININESS, shininess);
  glEndList();
}

int windowHeight, windowWidth;
bool startedRunning = false;
bool bombEnemy = false;
float flowTimer = 0;



bool healthCoolDown = false;
int healthCounter = 0;

int barrelT, heartT;

float aimAngleX = 0;
float aimAngleZ =0;
float aimAngle = 0;
bool aiming = false;
int bombAim = 0;
int squAim = 0;



int main(){
	bool orbit = true;
	int orbitCounter = 0;
	srand(time(NULL));
	int randnumber = rand() % 250;
	name = "PLAYER";
	name += std::to_string(randnumber);
	client2 * client = new client2();
	xmlLoad * xLoad = new xmlLoad();
	int success = client->init();
	float angleX = -45;
	float angleY = 30;
	if(success ==1){
		online = true;
	}else{
		online = false;
	}
	

	part = xLoad->loadXml();
	world = (int)(part /10)+1;
	cout << "world: " << world << endl;
	
	if(part == 10){
		if(online){
			part++;
		}else{
			world = 0;
		}
	}
	px =0;
	py = 5;
	pz = 0;
	hi = true;
	running = false;
	switchAnimate = false;
	frameCounter = 8;
	//shadowMapTexture = loadShadowMap(15);
	float cameraSpeed = 1.5;
	float playerR;
	float playerRZ;
	float jumpSpeed = 0.1;
	bool left, right, forward, backward;
	bool jump =false;
	float jumpingCounter =0;
	int jumpCounter =0;
	bool jump_allowed = true;
	float gravityCounter =0;
	left = false;
	right = false;
	forward = false;
	backward = false;
	bool increaseSpeedL = false;
	bool increaseSpeedR = false;
	int marbleCounter = 1;
	sf::Music music;
	
	sf::Sound hoover;
	sf::Sound hit;
	sf::Sound throwS;
	sf::Sound jumpS;
	sf::Sound bossS;
	sf::SoundBuffer hitBuffer;
	sf::SoundBuffer Hbuffer;
	sf::SoundBuffer thBuffer;
	sf::SoundBuffer jumpBuffer;
	sf::SoundBuffer bossBuffer;
	bool playingHoover = false;
	bool playingThrow = false;
	if(!Cbuffer.loadFromFile("Music/collection.ogg")){
		std::cout << "Could not load sound" << std::endl;
	}
	collect.setBuffer(Cbuffer);
	if(!hitBuffer.loadFromFile("Music/hit.ogg")){
		std::cout << "Could not load sound" << std::endl;
	}
	hit.setBuffer(hitBuffer);
	if(!Hbuffer.loadFromFile("Music/hoover.ogg")){
		std::cout << "Could not load sound" << std::endl;
	}
	hoover.setBuffer(Hbuffer);
	if(!thBuffer.loadFromFile("Music/throw.ogg")){
		std::cout << "Could not load sound" << std::endl;
	}
	throwS.setBuffer(thBuffer);
	if(!jumpBuffer.loadFromFile("Music/jump.ogg")){
		std::cout << "Could not load sound" << std::endl;
	}
	jumpS.setBuffer(jumpBuffer);
	if (!music.openFromFile("Music/music.ogg")){
		std::cout <<"Could not load music"<< std::endl;
	}
	bossS.setBuffer(bossBuffer);
	if(!bossBuffer.loadFromFile("Music/boss25.ogg")){
		std::cout << "Could not load music" << std::endl;
	}


	//controller.Add3DAnimFromFile("Objects/king/king_hitting.fbx");
	//controller.Add3DAnimFromFile("Objects/king/king_idle.fbx");
	AnimationController kingR("Objects/king/king_running.fbx");
	kingR.Add3DAnimFromFile("Objects/king/king_running.fbx");
	kingR.Import3DFromFile("Objects/king/king_running.fbx");
	
	
	AnimationController kingI("Objects/king/king_idle.fbx");
	kingI.Add3DAnimFromFile("Objects/king/king_idle.fbx");
	kingI.Import3DFromFile("Objects/king/king_idle.fbx");
	
	AnimationController anime("Object/anime/animeGirl.fbx");
	anime.Add3DAnimFromFile("Objects/anime/animeGirl.fbx");
	anime.Import3DFromFile("Objects/anime/animeGirl.fbx");
	
	AnimationController kingH("Objects/king/king_hitting.fbx");
	kingH.Add3DAnimFromFile("Objects/king/king_hitting.fbx");
	kingH.Import3DFromFile("Objects/king/king_hitting.fbx");
	
	AnimationController boss("Objects/boss/frog25.fbx");
	boss.Add3DAnimFromFile("Objects/boss/frog25.fbx");
	boss.Import3DFromFile("Objects/boss/frog25.fbx");
	
	AnimationController spider("Objects/timeM/timeSpider.fbx");
	spider.Add3DAnimFromFile("Objects/timeM/timeSpider.fbx");
	spider.Import3DFromFile("Objects/timeM/timeSpider.fbx");
	
	
	music.setLoop(true);         // make it loop
	music.play();
	sf::ContextSettings window_settings;
	window_settings.depthBits         = 24; // Request a 24-bit depth buffer
	window_settings.stencilBits       = 8;  // Request a 8 bits stencil buffer
	window_settings.antialiasingLevel = 2;  // Request 2 levels of antialiasing
 // Create the main window
	 sf::VideoMode desktop = sf::VideoMode().getDesktopMode();
	//sf::RenderWindow window(desktop, "SFML works!", sf::Style::None);
    sf::RenderWindow App(desktop, "Marb 0.1 - Alexander Elvis Johnson", sf::Style::Resize | sf::Style::Close, window_settings);

	glEnable(GL_DEPTH_TEST);
    // Create a clock for measuring time elapsed
	 
    sf::Clock Clock;
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Shading states
	//glShadeModel(GL_SMOOTH);
	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	//glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	//Depth states
	glClearDepth(1.0f);
	glDepthFunc(GL_LEQUAL);
	//glEnable(GL_DEPTH_TEST);

	glEnable(GL_CULL_FACE);

	//We use glScale when drawing the scene
	glEnable(GL_NORMALIZE);

	//Create the shadow map texture
	glGenTextures(1, &shadowMapTexture);
	glBindTexture(GL_TEXTURE_2D, shadowMapTexture);
	glTexImage2D(	GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, shadowMapSize, shadowMapSize, 0,
					GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	
	

	//Use the color as the ambient and diffuse material
	//glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	//glEnable(GL_COLOR_MATERIAL);
	int marble = 2;
	table = 1;
	
	
	pauseM = 4;
	rewindM = 5;
	forwardM = 6;
	int enemy = 3;
	bool bossFinished = false;
	int target = 4;
	//if(part < 10){
		
		material(table, white_light, white_light, white_light, brass_shininess);
		
		material(target, red_plastic_ambient, red_light, red_plastic_specular, red_plastic_shininess);

		
		material(enemy, brass_ambient, brass_diffuse, brass_specular, brass_shininess);
	//}else if(part < 20){
	//material(table, emerald_ambient, white_light, emerald_specular, brass_shininess);
	//}
	//material(marble, white_light, white_light, white_light, brass_shininess);
	
	
	if(world ==1 ){
		material(marble, emerald_ambient, yellow_light, emerald_specular, emerald_shininess);
	}else if(world ==2){
		material(marble, emerald_ambient, green_light, emerald_specular, emerald_shininess);
	}else if(world ==3){
		material(marble, red_plastic_ambient, red_light, red_plastic_specular, red_plastic_shininess);
	}else if(world == 4){
		material(marble, emerald_ambient, mint_light, emerald_specular, emerald_shininess);
	}else if(world == 5){
		material(marble, emerald_ambient, orange_light, emerald_specular, emerald_shininess);
	}else if(world ==0){
		int worldN = (part /10) +1;
		bossFinished = false;
		if(part == 10){
			bossLives = 5;
			bossKilled = false;
		}
		if(worldN ==1 ){
			material(marble, emerald_ambient, yellow_light, emerald_specular, emerald_shininess);
		}else if(worldN ==2){
			material(marble, emerald_ambient, green_light, emerald_specular, emerald_shininess);
		}else if(worldN ==3){
			material(marble, red_plastic_ambient, red_light, red_plastic_specular, red_plastic_shininess);
		}
		
	}
	
	material(pauseM, emerald_ambient, blue_light, emerald_specular, emerald_shininess);
	
	material(rewindM, emerald_ambient, pink_light, emerald_specular, emerald_shininess);
	
	material(forwardM, emerald_ambient, red_light, emerald_specular, emerald_shininess);
	//glCallList(table);
    //prepare OpenGL sufaces for HSR
	//glClearDepth(1.f);
    glClearColor(0.f, 0.3f, 0.6f, 0.f);

	
	glPushMatrix();
	

	glLoadIdentity();
	windowWidth = sf::VideoMode::getDesktopMode().width;
	windowHeight = sf::VideoMode::getDesktopMode().height;
	gluPerspective(100.0f, (float)windowWidth/windowHeight, 1.0f, 100.0f);
	glGetFloatv(GL_MODELVIEW_MATRIX, cameraProjectionMatrix);
	
	glLoadIdentity();
	gluLookAt(cameraPosition.x, cameraPosition.y, cameraPosition.z,
				0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f);
	glGetFloatv(GL_MODELVIEW_MATRIX, cameraViewMatrix);
	
	glLoadIdentity();
	gluPerspective(100.0f, 1024.f / 768.f, 1.0f, 100.0f);
	glGetFloatv(GL_MODELVIEW_MATRIX, lightProjectionMatrix);
	
	glLoadIdentity();
	gluLookAt(	lightPosition.x, lightPosition.y, lightPosition.z,
				0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f);
	glGetFloatv(GL_MODELVIEW_MATRIX, lightViewMatrix);
	
	glPopMatrix();
	
    //// Setup a perspective projection & Camera position
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	 gluPerspective(30.f, 1024.f / 768.f, 1.0f, 300);//fov, aspect, zNear, zFar
	App.setFramerateLimit(30);
	
	
	
	
	
	
	level levelLoad;
	
	//objLoader objL;
	
	objloader obj;
	obj.loadTails("Objects/Tails/tailsRun/tailsRun1.obj", "Objects/Tails/tailsRun/");
	obj.loadTails("Objects/Tails/tailsRun/tailsRun2.obj", "Objects/Tails/tailsRun/");
	obj.loadTails("Objects/Tails/tailsRun/tailsRun3.obj", "Objects/Tails/tailsRun/");
	obj.loadTails("Objects/Tails/tailsRun/tailsRun4.obj", "Objects/Tails/tailsRun/");
	obj.loadTails("Objects/Tails/tailsRun/tailsRun5.obj", "Objects/Tails/tailsRun/");
	obj.loadTails("Objects/Tails/tailsRun/tailsRun6.obj", "Objects/Tails/tailsRun/");
	obj.loadTails("Objects/Tails/tailsRun/tailsRun7.obj", "Objects/Tails/tailsRun/");
	obj.loadTails("Objects/Tails/tailsRun/tailsRun8.obj", "Objects/Tails/tailsRun/");
	
	obj.loadTails("Objects/Tails/tailsWave/tail1.obj", "Objects/Tails/tailsWave/");
	obj.loadTails("Objects/Tails/tailsWave/tail2.obj", "Objects/Tails/tailsWave/");
	obj.loadTails("Objects/Tails/tailsWave/tail3.obj", "Objects/Tails/tailsWave/");
	obj.loadTails("Objects/Tails/tailsWave/tail4.obj", "Objects/Tails/tailsWave/");
	obj.loadTails("Objects/Tails/tailsWave/tail5.obj", "Objects/Tails/tailsWave/");
	obj.loadTails("Objects/Tails/tailsWave/tail6.obj", "Objects/Tails/tailsWave/");
	obj.loadTails("Objects/Tails/tailsWave/tail7.obj", "Objects/Tails/tailsWave/");
	obj.loadTails("Objects/Tails/tailsWave/tail8.obj", "Objects/Tails/tailsWave/");
	obj.loadTails("Objects/Tails/tailsWave/tail9.obj", "Objects/Tails/tailsWave/");
	obj.loadTails("Objects/Tails/tailsWave/tail10.obj", "Objects/Tails/tailsWave/");
	
	obj.loadTails("Objects/Tails/tailsBreathing/tailsBreath1.obj", "Objects/Tails/tailsBreathing/");
	obj.loadTails("Objects/Tails/tailsBreathing/tailsBreath2.obj", "Objects/Tails/tailsBreathing/");
	obj.loadTails("Objects/Tails/tailsBreathing/tailsBreath3.obj", "Objects/Tails/tailsBreathing/");
	
	obj.loadTails("Objects/Tails/tailsJump/tailsJump1.obj", "Objects/Tails/tailsJump/");
	obj.loadTails("Objects/Tails/tailsJump/tailsJump2.obj", "Objects/Tails/tailsJump/");
	
	obj.loadTails("Objects/Tails/tailsCamera/tailsCamera.obj", "Objects/Tails/tailsCamera/");
	
	obj.loadBomb("Objects/Enemies/Bomb/bomb1.obj", "Objects/Enemies/Bomb/");
	obj.loadBomb("Objects/Enemies/Bomb/bomb2.obj", "Objects/Enemies/Bomb/");
	obj.loadBomb("Objects/Enemies/Bomb/bomb3.obj", "Objects/Enemies/Bomb/");
	
	obj.loadSqu("Objects/Enemies/Squeeze/squ.obj", "Objects/Enemies/Squeeze/");
	
	
	levelLoad.loadPause("Objects/Crystal/pause.obj");
	levelLoad.loadForward("Objects/Crystal/forward.obj");
	levelLoad.loadRewind("Objects/Crystal/rewind.obj");
	
	levelLoad.loadBin("Objects/Trash/bin/Barrel.obj");
	
	levelLoad.loadCamera("Objects/Camera/camera.obj");
	
	levelLoad.loadFactoryObject("Objects/factory.obj");
	
	kingR.LoadGLTextures();
	kingI.LoadGLTextures();
	kingH.LoadGLTextures();
	spider.LoadGLTextures();
	anime.LoadGLTextures();
	
	int bossOldLives = 3;
	
	std::string lMap = "Objects/world";
		lMap += std::to_string(world);
		lMap +="/table";
		lMap += std::to_string(part);
		lMap += ".obj";
		char * lArray = (char*)lMap.c_str();
		levelLoad.loadTable(lArray);
		
		
		std::string sMap = "Objects/world";
		sMap += std::to_string(world); 
		sMap += "/slope";
		sMap += std::to_string(part);
		sMap += ".obj";
		char * sArray = (char*)sMap.c_str();
		levelLoad.loadSlope(sArray);


		std::string fMap = "Objects/world";
		fMap += std::to_string(world);
		fMap += "/fSlope";
		fMap += std::to_string(part);
		fMap += ".obj";
		char * fArray = (char*) fMap.c_str();
		levelLoad.loadFSlope(fArray);

		std::string rMap = "Objects/world";
		rMap += std::to_string(world);
		rMap += "/reflect";
		rMap += std::to_string(part);
		rMap += ".obj";
		char * rArray = (char*) rMap.c_str();
		levelLoad.loadPlayer(rArray);
		
		std::string rsMap = "Objects/world";
		rsMap += std::to_string(world);
		rsMap += "/fRSlope";
		rsMap += std::to_string(part);
		rsMap += ".obj";
		char * rsArray = (char*) rsMap.c_str();
		levelLoad.loadReflectSlope(rsArray);
		
		std::string eMap = "Objects/world";
		eMap += std::to_string(world);
		eMap += "/exit";
		eMap += std::to_string(part);
		eMap += ".obj";
		char * eArray = (char*) eMap.c_str();
		levelLoad.loadExit(eArray);
		
		std::string maMap = "Objects/world";
		maMap += std::to_string(world);
		maMap += "/magnet";
		maMap += std::to_string(part);
		maMap += ".obj";
		char * maArray = (char*) maMap.c_str();
		levelLoad.loadMagnets(maArray);
		
		std::string spMap = "Objects/world";
		spMap += std::to_string(world);
		spMap += "/spikes";
		spMap += std::to_string(part);
		spMap += ".obj";
		char * spArray = (char*) spMap.c_str();
		levelLoad.loadSpikes(spArray);
		
		std::string finMap = "Objects/world";
		finMap += std::to_string(world);
		finMap +="/finish";
		finMap += std::to_string(part);
		finMap += ".obj";
		char * finArray = (char*) finMap.c_str();
		levelLoad.loadFinish(finArray);
		
		std::string trMap = "Objects/world";
		trMap += std::to_string(world);
		trMap += "/trap";
		trMap += std::to_string(part);
		trMap += ".obj";
		char * trArray = (char*) trMap.c_str();
		levelLoad.loadTrapDoor(trArray);
		
		std::string tMap = "Objects/trap.obj";
		char * tArray = (char*) tMap.c_str();
		levelLoad.loadOriginalTrap(tArray);
		
		std::string bMap = "Objects/world";
		bMap += std::to_string(world);
		bMap += "/bomb";
		bMap += std::to_string(part);
		bMap += ".obj";
		char * bArray = (char*) bMap.c_str();
		levelLoad.loadBomb(bArray);
		
		std::string tmMap = "Objects/world";
		tmMap += std::to_string(world);
		tmMap += "/tm";
		tmMap += std::to_string(part);
		tmMap += ".obj";
		char * tmArray = (char*) tmMap.c_str();
		levelLoad.loadSpider(tmArray);
		
		std::string faMap = "Objects/world";
		faMap += std::to_string(world);
		faMap += "/factory";
		faMap += std::to_string(part);
		faMap += ".obj";
		char * faArray = (char*) faMap.c_str();
		levelLoad.loadFactory(faArray);
		
		std::string sqMap = "Objects/world";
		sqMap += std::to_string(world);
		sqMap += "/squ";
		sqMap += std::to_string(part);
		sqMap += ".obj";
		char * sqArray = (char*) sqMap.c_str();
		levelLoad.loadSqu(sqArray);
		
		std::string biMap = "Objects/world";
		biMap += std::to_string(world);
		biMap += "/bin";
		biMap += std::to_string(part);
		biMap += ".obj";
		char * biArray = (char*) biMap.c_str();
		levelLoad.loadBinSpawn(biArray);
		
		std::string moMap = "Objects/world";
		moMap += std::to_string(world);
		moMap += "/moving";
		moMap += std::to_string(part);
		moMap += ".obj";
		char* moArray = (char*) moMap.c_str();
		levelLoad.loadMoving(moArray);
		
		moMap = "Objects/world";
		moMap += std::to_string(world);
		moMap += "/movingU";
		moMap += std::to_string(part);
		moMap += ".obj";
		moArray = (char*) moMap.c_str();
		levelLoad.loadMovingU(moArray);
		
		std::string bhMap = "Objects/world";
		bhMap += std::to_string(world);
		bhMap += "/frogH";
		bhMap += std::to_string(part);
		bhMap += ".obj";
		char* bhArray = (char*) bhMap.c_str();
		levelLoad.loadBossHit(bhArray);
		
		
		
		if(levelLoad.bFaces.size() > 0){
			bombEnemy = true;
		}else{
			bombEnemy = false;
		}
		for(int i = 0; i < 10; i++){
			binCollected[i] = true;
			binamation[i] = false;
			binScale[i] = 1;
		}
		
		std::string prMap = "Objects/world";
		prMap += std::to_string(world);
		prMap += "/project";
		prMap += std::to_string(part);
		prMap += ".obj";
		char* prArray = (char*) prMap.c_str();
		levelLoad.loadProject(prArray);
		if(levelLoad.prFaces.size() % 6 == 0){
			projectCount = levelLoad.prFaces.size()/6;
			for(int i = 0; i < projectCount; i++){
				projectX[i] = levelLoad.prVert[levelLoad.prFaces[i*6 + 1]->faces[1]-1]->x;
				projectZ[i] = levelLoad.prVert[levelLoad.prFaces[i*6 + 1]->faces[1]-1]->z;
				projectY[i] = levelLoad.prVert[levelLoad.prFaces[i*6 + 1]->faces[1]-1]->y;
				projectAngle[i] = 0;
				fireProject[i] = false;
				projectCounter[i] =0;
			}
		}
		if(levelLoad.faFaces.size() % 6 ==0){
			factoryCounter = levelLoad.faFaces.size()/6;
			for(int i = 0; i < factoryCounter; i++){
				factoryX[i] = levelLoad.faVert[levelLoad.faFaces[i*6+1]->faces[1]-1]->x;
				factoryY[i] = levelLoad.faVert[levelLoad.faFaces[i*6+1]->faces[1]-1]->y;
				factoryZ[i] = levelLoad.faVert[levelLoad.faFaces[i*6+1]->faces[1]-1]->z;
				factoryDead[i]= false;
				//factoryType[i] = 0;
			}
		}
		if(levelLoad.biSFaces.size() %6 ==0){
			binCount = levelLoad.biSFaces.size()/6;
			for(int i = 0; i < binCount; i++){
				binX[i] =  levelLoad.biSVert[levelLoad.biSFaces[i*6 + 1]->faces[1]-1]->x;
				binZ[i] =  levelLoad.biSVert[levelLoad.biSFaces[i*6 + 1]->faces[1]-1]->z;
				binY[i] =  levelLoad.biSVert[levelLoad.biSFaces[i*6 + 1]->faces[1]-1]->y;
				binCollected[i] = false;
			}
		}
		if(levelLoad.tmFaces.size() % 6 ==0){
			tmCount = levelLoad.tmFaces.size()/6;
			for(int i = 0; i < tmCount; i++){
				tMonsterX[i] = levelLoad.tmVert[levelLoad.tmFaces[i*6+1]->faces[1]-1]->x;
				tMonsterY[i] = levelLoad.tmVert[levelLoad.tmFaces[i*6+1]->faces[1]-1]->y;
				tMonsterZ[i] = levelLoad.tmVert[levelLoad.tmFaces[i*6+1]->faces[1]-1]->z;
				tMonsterType[i] = rand() %2;
				
			}
			if(part > 40){
				tMonsterType[0] = 10;
			}
		}

		if(levelLoad.bFaces.size() % 6 ==0){
			bombCount = levelLoad.bFaces.size()/6;
			for(int i = 0; i < bombCount; i++){
				bombX[i] = levelLoad.bVert[levelLoad.bFaces[i*6 + 1]->faces[1]-1]->x;
				bombZ[i] = levelLoad.bVert[levelLoad.bFaces[i*6 + 1]->faces[1]-1]->z;
				bombY[i] = levelLoad.bVert[levelLoad.bFaces[i*6 + 1]->faces[1]-1]->y;
				
				enKilled[i] = false;
			}
		}
		if(levelLoad.sqFaces.size() % 6 ==0){
			if(part != 1){
				sqCount = levelLoad.sqFaces.size()/6;
			}else{
				animeCount = levelLoad.sqFaces.size()/6;
			}
			//sqCount -= 1;
			for(int i = 0; i < sqCount; i++){
				//if(part != 1){
				squX[i] = levelLoad.sqVert[levelLoad.sqFaces[i*6 + 1]->faces[1]-1]->x;
				squZ[i] = levelLoad.sqVert[levelLoad.sqFaces[i*6 + 1]->faces[1]-1]->z;
				squY[i] = levelLoad.sqVert[levelLoad.sqFaces[i*6 + 1]->faces[1]-1]->y;
				squKilled[i] = false;
			
			}
			for(int i = 0; i < animeCount; i++){
				animeX[i] = levelLoad.sqVert[levelLoad.sqFaces[i*6 + 1]->faces[1]-1]->x;
				animeZ[i] = levelLoad.sqVert[levelLoad.sqFaces[i*6 + 1]->faces[1]-1]->z;
				animeY[i] = levelLoad.sqVert[levelLoad.sqFaces[i*6 + 1]->faces[1]-1]->y;
			}
		}
		
		if(levelLoad.trFaces.size() % 6 ==0){
			trapCount = levelLoad.trFaces.size()/6;
			for(int i =0; i < trapCount; i++){
				trapX[i] = levelLoad.trVert[levelLoad.trFaces[i*6 + 1]->faces[1]-1]->x;
				trapZ[i] = levelLoad.trVert[levelLoad.trFaces[i*6 + 1]->faces[1]-1]->z;
				trapY[i] = levelLoad.trVert[levelLoad.trFaces[i*6 + 1]->faces[1]-1]->y;
				trapTripped[i] = false;
				trapRespawn[i] = 0;
				TrapWait[i] = 0;
			}
			
		}
		char pauseI[] = "Images/Crystal/pause.png";
		pauseTexture = obj.loadTexture(pauseI, 10);
		char forwardI[] = "Images/Crystal/forward.png";
		forwardTexture = obj.loadTexture(forwardI,11);
		char rewindI[] = "Images/Crystal/rewind.png";
		rewindTexture = obj.loadTexture(rewindI, 12);
		
		char heartI[] = "Images/hud/heart.png";
		heartT = obj.loadTexture(heartI, 13);
		
		char barrelI[] = "Images/hud/barrel.png";
		barrelT = obj.loadTexture(barrelI, 14);
		heartDeplete[0] = heartT;
		for(int i = 1; i < 8; i++){
			std::string heartL = "Images/hud/deplete/heart";
			heartL += std::to_string(i);
			heartL += "-min.png";
			char * heartArray = (char*) heartL.c_str();
			heartDeplete[i] = obj.loadTexture(heartArray, 14 +i);
		}
		
		char trapC[] = "Images/Textures/copper.png";
		trapTexture = obj.loadTexture(trapC,22);
		
		char magnetC[] = "Images/Textures/magnet.png";
		magTexture = obj.loadTexture(magnetC, 23);
		
		char spikeC[] = "Images/Textures/metal.png";
		spikeTexture = obj.loadTexture(spikeC, 24);
		
	if(world ==2){
		char skyTop[] = "Images/hw_crater/craterlake_up.tga";
		skyT = obj.loadTexture(skyTop, 25);
		
		char skyBot[] = "Images/hw_crater/craterlake_dn.tga";
		skyB = obj.loadTexture(skyBot, 26);
		
		char skyFront[] = "Images/hw_crater/craterlake_ft.tga";
		skyF = obj.loadTexture(skyFront, 27);
		
		char skyBack[] = "Images/hw_crater/craterlake_bk.tga";
		skyBk = obj.loadTexture(skyBack, 28);
		
		char skyLeft[] = "Images/hw_crater/craterlake_lf.tga";
		skyL = obj.loadTexture(skyLeft, 29);
		
		char skyRight[] = "Images/hw_crater/craterlake_rt.tga";
		skyR = obj.loadTexture(skyRight, 30);
		
	}else if(world ==1){
		char skyTop[] = "Images/mp_5dim/5dim_up.tga";
		skyT = obj.loadTexture(skyTop, 25);
		
		char skyBot[] = "Images/mp_5dim/5dim_dn.tga";
		skyB = obj.loadTexture(skyBot, 26);
		
		char skyFront[] = "Images/mp_5dim/5dim_ft.tga";
		skyF = obj.loadTexture(skyFront, 27);
		
		char skyBack[] = "Images/mp_5dim/5dim_bk.tga";
		skyBk = obj.loadTexture(skyBack, 28);
		
		char skyLeft[] = "Images/mp_5dim/5dim_lf.tga";
		skyL = obj.loadTexture(skyLeft, 29);
		
		char skyRight[] = "Images/mp_5dim/5dim_rt.tga";
		skyR = obj.loadTexture(skyRight, 30);
		
	}else if(world == 3){
			char skyTop[] = "Images/sky/violentdays_up.tga";
			skyT = obj.loadTexture(skyTop, 25);
			
			char skyBot[] = "Images/sky/violentdays_dn.tga";
			skyB = obj.loadTexture(skyBot, 26);
			
			char skyFront[] = "Images/sky/violentdays_ft.tga";
			skyF = obj.loadTexture(skyFront, 27);
			
			char skyBack[] = "Images/sky/violentdays_bk.tga";
			skyBk = obj.loadTexture(skyBack, 28);
			
			char skyLeft[] = "Images/sky/violentdays_lf.tga";
			skyL = obj.loadTexture(skyLeft, 29);
			
			char skyRight[] = "Images/sky/violentdays_rt.tga";
			skyR = obj.loadTexture(skyRight, 30);
			
	}else if(world == 4){
			char skyTop[] = "Images/ame_emerald/emeraldfog_dn.tga";
			skyT = obj.loadTexture(skyTop, 25);
			
			char skyBot[] = "Images/ame_emerald/emeraldfog_up.tga";
			skyB = obj.loadTexture(skyBot, 26);
			
			char skyFront[] = "Images/ame_emerald/emeraldfog_ft.tga";
			skyF = obj.loadTexture(skyFront, 27);
			
			char skyBack[] = "Images/ame_emerald/emeraldfog_bk.tga";
			skyBk = obj.loadTexture(skyBack, 28);
			
			char skyLeft[] = "Images/ame_emerald/emeraldfog_lf.tga";
			skyL = obj.loadTexture(skyLeft, 29);
			
			char skyRight[] = "Images/ame_emerald/emeraldfog_rt.tga";
			skyR = obj.loadTexture(skyRight, 30);
			
		}else if(world ==5){
			char skyTop[] = "Images/hw_sandstorm/sandstorm_dn.tga";
			skyT = obj.loadTexture(skyTop, 25);
			
			char skyBot[] = "Images/hw_sandstorm/sandstorm_up.tga";
			skyB = obj.loadTexture(skyBot, 26);
			
			char skyFront[] = "Images/hw_sandstorm/sandstorm_ft.tga";
			skyF = obj.loadTexture(skyFront, 27);
			
			char skyBack[] = "Images/hw_sandstorm/sandstorm_bk.tga";
			skyBk = obj.loadTexture(skyBack, 28);
			
			char skyLeft[] = "Images/hw_sandstorm/sandstorm_lf.tga";
			skyL = obj.loadTexture(skyLeft, 29);
			
			char skyRight[] = "Images/hw_sandstorm/sandstorm_rt.tga";
			skyR = obj.loadTexture(skyRight, 30);
			
		}
		
		for(int i = 0; i < 100; i++){
			
			rewindCollectable[i] = false;
			pauseCollectable[i] = false;
			forwardCollectable[i] = false;
			
			rewindSpawnX[i] = -1000;
			rewindSpawnZ[i] = -1000;
			rewindSpawnY[i] = -1000;
			
			pauseSpawnX[i] = -1000;
			pauseSpawnZ[i] = -1000;
			pauseSpawnY[i] = -1000;
			
			forwardSpawnX[i] = -1000;
			forwardSpawnZ[i] = -1000;
			forwardSpawnY[i] = -1000;
			
			
			forwardBounce[i] = true;
			pauseBounce[i] = true;
			rewindBounce[i] = true;
			
			shownPause[i] = false;
			shownRewind[i] = false;
			shownForward[i] = false;
			
		}

		px = px + (speed*2) * cos(angle * (3.14159/180));
			pz = pz + (speed*2) * sin(angle * (3.14159/180));
			//playerRZ -= pRotateSpeed;
			//running = true;
			
						
	//levelLoad.loadSpikes("Objects/magnet8.obj");

	int finished = 0;
	sphere = gluNewQuadric();
	
	float lz, lx;

	//App.setActive(true);
	//material(table, emerald_ambient, emerald_diffuse, emerald_specular, emerald_shininess);
	if(part < 10){
		//material(table, brass_ambient, brass_diffuse, brass_specular, brass_shininess);
	}else if(part < 20){
		//material(table, emerald_ambient, emerald_diffuse, emerald_specular, emerald_shininess);
	}
	//material(marble, white_light, white_light, white_light, brass_shininess);
	string mText;
	bool sayingHi = false;
	float fraction = 0.1;
	bool leftL, rightL;
	int enemyHit = 0;
	float newAngleX = 0;
	float newAngleZ = 0;
	float newAngleY = 0;
	bool xMovingL = false;
	bool xMovingR = false;
	bool yMovingL = false;
	bool yMovingR = false;
	int animationCounter = 0;
	while (App.isOpen())
    {
		while(finished ==0 && completeFinished == 0){
		
		coinSpin += coinSpinSpeed;
		sf::Event Event;
		while (App.pollEvent(Event)) //game loop!
		{
			if (Event.type == sf::Event::Closed)
				App.close();
			
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
					App.close();
				
			//increaseSpeedL = false;
			
			
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
				if(!start){
					if(!aiming){
						leftL = true;
					}else{
						
						if(bombCount > 0){
							bombAim++;
							if(bombAim > bombCount){
								if(sqCount > 0){
									squAim++;
									if(squAim > sqCount){
										bombAim =0;
										squAim = 0;
									}
								}else{
									bombAim = 0;
								}
							}
						}else if(sqCount > 0){
							bombAim = bombCount;
							squAim++;
							if(squAim > sqCount){
								bombAim =0;
								squAim = 0;
							}
						}
						
					}
				}else{

				}
			}else{
				leftL = false;
				hi = false;
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::O)){
				orbitCounter++;
				if(orbitCounter == 50){
					orbitCounter =0;
					if(orbit){
						orbit = false;
					}else{
						orbit = true;
					}
				}
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
				if(!start){
					if(!aiming){
						rightL = true;
					}else{
						
						if(bombCount > 0){
							bombAim--;
							if(bombAim < 0){
								if(sqCount > 0){
									squAim--;
									if(squAim < 0){
										bombAim =0;
										squAim = 0;
									}
								}else{
									bombAim = 0;
								}
							}
						}else if(sqCount > 0){
							bombAim = bombCount;
							squAim--;
							if(squAim < 0){
								squAim = 0;
							}
						}
						
					}
				}else{
					hi = false;
				}
			}else{
				rightL = false;
				hi = false;
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
				aiming = true;
			}else{
				aiming = false;
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
				yMovingR = true;
				
			}else{
				yMovingR = false;
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
				yMovingL = true;
				
			}else{
				yMovingL = false;
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
				//angleX += cameraSpeed *2;
				xMovingL = true;
			}else{
				xMovingL = false;
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
				xMovingR = true;
			}else{
				xMovingR = false;
			}

			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
				if(binVentory > 0){
					binVentory--;
					throwing = true;
					if(!playingThrow){
						playingThrow = true;
						throwS.play();
					}
					throwAnimation = true;
					throwX = px;
					throwY = py;
					throwZ = pz;
					throwAngle = angle;
				}
			}else{
				playingThrow = false;
				throwAnimation = false;
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
				sucking = true;
				if(!playingHoover){
					playingHoover = true;
					hoover.play();
				}
			}else{
				sucking = false;
				playingHoover = false;
				hoover.stop();
			}
			if(!start){
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
						forward = true;
						if(speed < 0.3){
							//speed += 0.005;
							pRotateSpeed += 1;
						}
						
				

						
						//playerR -= speed;
				}else{
					forward = false;
					running = false;
					if(!backward){
						running = false;
						frameCounter = 18;
						startedRunning = false;
					}
				}

				
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
						backward = true;
						if(speed < 0.3){
							//speed += 0.005;
							pRotateSpeed += 1;
						}
				}else{
					backward = false;
					running = false;
					if(!forward){
						running = false;
						frameCounter = 18;
						startedRunning = false;
					}
				}

			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
					hi = true;
					if(!sayingHi){
						sayingHi = true;
						frameCounter = 7;
						switchAnimate = false;
						running = false;
					}
				}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
				if(!start){
					if(jump_allowed){
						jump = true;
						jumpS.play();
						frameCounter = 20;
						ground = 0;
						jump_allowed = false;
					}
				}else{
					start = false;
				}
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
				if(pauseCounter > 0){
					pauseTime = true;
					timeCounter = 1;
				}
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){
				if(rewindCounter > 0){
					rewindTime = true;
				//rewindSquCounter[z] --;
					timeCounter = 1;
					bombAngle =0;
				}
			//	bombX = levelLoad.bVert[levelLoad.bFaces[1]->faces[1]-1]->x;
			//	bombZ = levelLoad.bVert[levelLoad.bFaces[1]->faces[1]-1]->z;
			//	bombY = levelLoad.bVert[levelLoad.bFaces[1]->faces[1]-1]->y;
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)){
				if(forwardCounter > 0){
					forwardTime = true;
					timeCounter = 1;
				}
			}
		}
		if(leftL){
			angle -=10;
			if(angle >360){
				angle =0;
			}
		}
		if(rightL){
			angle +=10;
			if(angle >360){
				angle =0;
			}
		}
		if(aiming){
			float checkX = 0;
			float checkZ = 0;
			float width = 0.6;
			float pxF = px;
			float pzF = pz;
			float newAngle = 0;
			for(int x = 0; x < 36; x++){
				newAngle +=10;
				pxF = px;
				pzF = pz;
				if(bombAim < bombCount){
					checkX = bombX[bombAim];
					checkZ = bombZ[bombAim];
					for(int i = 0;i < 200; i++){
						pxF = pxF + (speed*2) * cos(newAngle * (3.14159/180));
						pzF = pzF + (speed*2) * sin(newAngle * (3.14159/180));
						if(checkX +width  > pxF && checkX< (pxF + width) ){
							if(checkZ  +width > pzF && checkZ  < (pzF + width)){
								angle = newAngle;
							}
						}
					}
				}else if(squAim < sqCount){
					width = 1.4;
					checkX = squX[squAim];
					checkZ = squZ[squAim];
					for(int i = 0;i < 200; i++){
						pxF = pxF + (speed*2) * cos(newAngle * (3.14159/180));
						pzF = pzF + (speed*2) * sin(newAngle * (3.14159/180));
						if(checkX +width  > pxF && checkX< (pxF + width) ){
							if(checkZ  +width > pzF && checkZ  < (pzF + width)){
								angle = newAngle;
							}
						}
					}
				}
			}
		}
		if(xMovingL){
			angleX += cameraSpeed *2;
		}else if(xMovingR){
			angleX -= cameraSpeed *2;
		}
		if(yMovingL){
			angleY -= cameraSpeed; 
		}else if(yMovingR){
			angleY += cameraSpeed; 
		}
		for(int i = 0;i < factoryCounter; i++){
			if(!factoryDead[i]){
				factoryTimer[i]++;
				if(factoryTimer[i] > 50 && fMinionSize < 12){
					factoryTimer[i] = 0;
					factoryMinionX[fMinionSize] = factoryX[i];
					factoryMinionY[fMinionSize] = factoryY[i];
					factoryMinionZ[fMinionSize] = factoryZ[i];
					
					
					fMinionSize++;
					
				}
			}
			
		}
		for(int i =0;i < fMinionSize; i++){
			if(factoryMinionY[i] != -1000){
				factoryMinionX[i] -= 0.1;
				int ground = factoryCollision(levelLoad, i);
				//cout << ground << endl;
				if(ground != 1){
					factoryMinionY[i] -= 0.1;	
				}
				if(factoryMinionY[i] < -10){
					factoryMinionY[i] = -1000;
					factoryMinionX[i] = -1000;
					factoryMinionZ[i] = -1000;
					if(i == fMinionSize-1){
						fMinionSize = 0;
					}
				}
			}
		}
		if(timeCounter > 0){
			if(timeCounter < 75){
				timeCounter++;
			
			}else{
				timeCounter = 0;
				if(pauseTime){
					pauseCounter--;
				}
				if(rewindTime){
					rewindCounter--;
				}
				if(forwardTime){
					forwardCounter--;
					for(int i = 0; i < binCount; i++){
						binCollected[i] = false;
					}
				}
				pauseTime = false;
				rewindTime = false;
				for(int i = 0; i < sqCount; i++){
					for(int z = rewindSquCounter[i]; z < 500; z++){
						rewindSquX[i][z] = 0;
						rewindSquZ[i][z] = 0;
						rewindSquOldAngle[z] = 0;
						rewindSquAngle[i][z] = 0;
					}
					if(rewindSquCounter[i] == 0){
						//rewindSquAngle[i][0] = 0;
						squAngle[i] =0;
					}
				}
				forwardTime = false;
				enemySpeed = 0.1;
				coinSpinSpeed = 1;
			}
		}
		if(pauseTime){
			enemySpeed = 0;
			coinSpinSpeed = 0;
		}
		if(rewindTime){
			enemySpeed = -0.1;
			coinSpinSpeed = -1;
			
		}
		if(forwardTime){
			enemySpeed = 0.2;
			coinSpinSpeed = 2;
		}
		for(int i = 0;i < 10; i++){
			if(binamation[i]){
				if(binScale[i] > 0){
					binScale[i] -= 0.1;
				}else{
					sucking = false;
					binamation[i] = false;
					binScale[i] = 1;
					binVentory++;
					binCollected[i] = true;
				}
			}
		}
		
		if(forward){
			//pz -= speed;
			px = px + (speed*2) * cos(angle * (3.14159/180));
			pz = pz + (speed*2) * sin(angle * (3.14159/180));
			playerRZ -= pRotateSpeed;
			running = true;
			if(!startedRunning){
				hi = false;
				startedRunning = true;
				running = true;
				frameCounter = 0;
			}
		}else if(backward){
			px = px - speed * cos(angle * (3.14159/180));
			pz = pz - speed * sin(angle * (3.14159/180));
			playerRZ += pRotateSpeed;
			running = true;
			if(!startedRunning){
				startedRunning = true;
				hi = false;
				running = true;
				frameCounter = 0;
			}
		}
		if(throwing){
			if(!rewindTime){
				throwX = throwX + (speed*2) * cos(throwAngle * (3.14159/180));
				throwZ = throwZ + (speed*2) * sin(throwAngle * (3.14159/180));
			}else{
				throwX = throwX - (speed*2) * cos(throwAngle * (3.14159/180));
				throwZ = throwZ - (speed*2) * sin(throwAngle * (3.14159/180));
			}
		}
		if(playerRZ > 180){
			playerRZ = 0;
		}
		if(playerR > 180){
			playerR =0;
		}
		if(py < -40){
			py = 5;
			pz =0;
			px = 0;
			moMap = "Objects/world";
			moMap += std::to_string(world);
			moMap += "/moving";
			moMap += std::to_string(part);
			moMap += ".obj";
			char* moArray = (char*) moMap.c_str();
			levelLoad.loadMoving(moArray);
			
			
			moMap = "Objects/world";
			moMap += std::to_string(world);
			moMap += "/movingU";
			moMap += std::to_string(part);
			moMap += ".obj";
			moArray = (char*) moMap.c_str();
			levelLoad.loadMovingU(moArray);
		}
		if(!increaseSpeedL && !increaseSpeedR){
			speed = 0.1;
			pRotateSpeed = 3;
		}
		if(jump){
			py += (jumpSpeed*3) - jumpingCounter;
			reflectCounter += (jumpSpeed*3) - jumpingCounter;
			if(jumpCounter >= jumpSpeed*150){
						//jump_allowed = false;	
				jump = false;
				jump_allowed = false;
				runFromJump = false;
			}
			hi = false;
			jumpCounter++; //the jump counters will increase while the player is in the air
			jumpingCounter += 0.02;
			
		}
		ground = mapCollision(levelLoad);
		finished = finishCollision(levelLoad);
		enemyHit = enemyCollision(levelLoad);
		if(enemyHit){
			if(!healthCoolDown){
				hit.play();
				healthCoolDown = true;
				jump = true;
				frameCounter = 20;
				ground = 0;
				jump_allowed = false;
				hearts--;
			}
			
		}
		
		if(healthCoolDown){
			if(healthCounter < 30){
				healthCounter++;
			}else{
				healthCoolDown = false;
				healthCounter = 0;
				
			}
		}
		if(hearts ==0){
			hearts = 3;
			py = 5;
			pz = 0;
			px = 0;
			moMap = "Objects/world";
			moMap += std::to_string(world);
			moMap += "/moving";
			moMap += std::to_string(part);
			moMap += ".obj";
			char* moArray = (char*) moMap.c_str();
			levelLoad.loadMoving(moArray);
			
			moMap = "Objects/world";
			moMap += std::to_string(world);
			moMap += "/movingU";
			moMap += std::to_string(part);
			moMap += ".obj";
			moArray = (char*) moMap.c_str();
			levelLoad.loadMovingU(moArray);
		}
		if(flowTimer > 25){
			crystalCollision(levelLoad);
		}else{
			flowTimer++;
		}
		for(int i =0;i < trapCount; i++){
			if(trapTripped[i]){
				if(TrapWait[i] > 20){
					trapRespawn[i]--;
					if(trapRespawn[i] < -150){
						trapTripped[i] = false;
						trapRespawn[i] = 0;
						TrapWait[i] =0;
					}
				}else{
					TrapWait[i]++;
				}
			}
		}
		if(finished ==1){
			cout << "Finished level"<< endl;
			if(online){
				char fin[] = "Finished"; //let server know your client has "finished"
				client->sendMessage(fin);
				finished = 0;
			}
		}
		if(ground ==0){
			
			if(!jump){
				py -= jumpSpeed + gravityCounter;
				reflectCounter -= jumpSpeed + gravityCounter;
				if(gravityCounter < 0.35){
					gravityCounter += 0.01;
				}
			}
		}else if(ground ==1){
			hi = false;
			jump = false;
			if(!runFromJump){
				runFromJump = true;
				frameCounter = 0;
			}
			reflectCounter =0;
			jump_allowed = true;
			gravityCounter = 0;
			
			jumpCounter =0;
			jumpingCounter = 0;
		}
		//evidence of the f
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT| GL_STENCIL_BUFFER_BIT );        //clear the buffer cache 
			//Prepare for drawing
			//glCallList(marble);
			if(orbit){
				cameraPosition.Set(px -5, py -1, pz -5);
			}
		//	cameraPosition.Set(-px, -py, -pz);
			glLoadIdentity();
	windowWidth = sf::VideoMode::getDesktopMode().width;
	windowHeight = sf::VideoMode::getDesktopMode().height;
	gluPerspective(100.0f, (float)windowWidth/windowHeight, 1.0f, 200.0f);
	glGetFloatv(GL_MODELVIEW_MATRIX, cameraProjectionMatrix);
	
	glLoadIdentity();
	newAngleZ = (cameraPosition.z) + (cameraSpeed*10) * sin(angleX * (3.14159/180));
	newAngleX = (cameraPosition.x) +(cameraSpeed*10) * cos(angleX * (3.14159/180));
	newAngleY = (cameraPosition.y) +(cameraSpeed*10) * tan(angleY * (3.14159/180));
	if(!lightDefined){
		lightX = newAngleX;
		lightZ = newAngleZ;
		//lightY = 15;
		lightDefined = true;
		//lightPosition.Set(lightX, lightY, lightZ);
	}
	lightY = 6 + py;
	float newLightX = px + 1;
	float newLightZ = pz + 9;
	lightPosition.Set(newLightX, lightY, newLightZ);
	if(!orbit){
		glRotatef((angle)+90, 0,1,0);
			//glTranslatef(0,-0.7,0);
		glRotatef(angleY, 0, 0, 1);
		glTranslatef(-px, (-py)-3, -pz);
		
	//orbit
	
	}else{
	 gluLookAt(newAngleX, newAngleY, newAngleZ,
				px, py, pz,
				0.0f, 1.0f, 0.0f);
				
	}
	glGetFloatv(GL_MODELVIEW_MATRIX, cameraViewMatrix);
	
	glLoadIdentity();
	gluPerspective(150.0f, 1, 1.0f, 100.0f);
	glGetFloatv(GL_MODELVIEW_MATRIX, lightProjectionMatrix);
	
	glLoadIdentity();
	gluLookAt(	lightPosition.x, lightPosition.y, lightPosition.z,
				0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f);
	glGetFloatv(GL_MODELVIEW_MATRIX, lightViewMatrix);
	
	glPopMatrix();
	
    //// Setup a perspective projection & Camera position
    glMatrixMode(GL_PROJECTION);
	//glTranslatef(-10,0,0);
	if(!pauseTime){
		kingI.Update();
		kingR.Update();
		kingH.Update();
		anime.Update();
		spider.Update();
		boss.Update();
	}

			//glDepthFunc(GL_LEQUAL);
			//glCallList(marble);
			//glCallList(table);
			//glDepthFunc(GL_LESS);
			//drawScene(levelLoad, marble, playerR, playerRZ);
			
		//	glDepthFunc(GL_LEQUAL);
			if(forwardTime){
				glCallList(forwardM);
			}else if(pauseTime){
				glCallList(pauseM);
			}else if(rewindTime){
				glCallList(rewindM);
			}else{
				glCallList(marble);
			}

		///	glCallList(marble);
			

	
	
	
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(lightProjectionMatrix);

	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(lightViewMatrix);

	//Use viewport the same size as the shadow map
	glViewport(0, 0, shadowMapSize, shadowMapSize);

	//Draw back faces into the shadow map
	glCullFace(GL_FRONT);

	//Disable color writes, and use flat shading for speed
	glShadeModel(GL_FLAT);
	glColorMask(0, 0, 0, 0);
	
	//Draw the scene
	//glCallList(table);
	drawScene(levelLoad, marble, playerR, playerRZ, obj, left, right, backward, kingI, kingR, kingH, anime, boss, spider);
	//glCallList(marble);

	//Read the depth buffer into the shadow map texture
	glBindTexture(GL_TEXTURE_2D, shadowMapTexture);
	glCopyTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 0, 0, shadowMapSize, shadowMapSize);

	//restore states
	glCullFace(GL_BACK);
	glShadeModel(GL_SMOOTH);
	glColorMask(1, 1, 1, 1);
	

	

	//2nd pass - Draw from camera's point of view
	glClear(GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(cameraProjectionMatrix);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(cameraViewMatrix);

	glViewport(0, 0, windowWidth, windowHeight);

	//Use dim light to represent shadowed areas
	glLightfv(GL_LIGHT1, GL_POSITION, VECTOR4D(lightPosition));
	glLightfv(GL_LIGHT1, GL_AMBIENT, white*0.2f);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, white*0.2f);
	// glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 20);
  //  glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 60);
	glLightfv(GL_LIGHT1, GL_SPECULAR, black);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHTING);
	
	//glRotatef(angleY, 0,1,0);
	//glRotatef(-angleX, 0,1,0);

	//glCallList(table);
	drawScene(levelLoad, marble, playerR, playerRZ, obj, left, right, backward, kingI, kingR, kingH, anime, boss, spider);
	
	
	//glCallList(marble);
	


	//3rd pass
	//Draw with bright light
	glLightfv(GL_LIGHT1, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT1, GL_SPECULAR, white);
	//glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 20);
   // glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 60);

	//Calculate texture matrix for projection
	//This matrix takes us from eye space to the light's clip space
	//It is postmultiplied by the inverse of the current view matrix when specifying texgen
	static MATRIX4X4 biasMatrix(0.5f, 0.0f, 0.0f, 0.0f,
								0.0f, 0.5f, 0.0f, 0.0f,
								0.0f, 0.0f, 0.5f, 0.0f,
								0.5f, 0.5f, 0.5f, 1.0f);	//bias from [-1, 1] to [0, 1]
	MATRIX4X4 textureMatrix=biasMatrix*lightProjectionMatrix*lightViewMatrix;

	//Set up texture coordinate generation.
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glTexGenfv(GL_S, GL_EYE_PLANE, textureMatrix.GetRow(0));
	glEnable(GL_TEXTURE_GEN_S);

	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glTexGenfv(GL_T, GL_EYE_PLANE, textureMatrix.GetRow(1));
	glEnable(GL_TEXTURE_GEN_T);

	glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glTexGenfv(GL_R, GL_EYE_PLANE, textureMatrix.GetRow(2));
	glEnable(GL_TEXTURE_GEN_R);

	glTexGeni(GL_Q, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glTexGenfv(GL_Q, GL_EYE_PLANE, textureMatrix.GetRow(3));
	glEnable(GL_TEXTURE_GEN_Q);

	//Bind & enable shadow map texture
	glBindTexture(GL_TEXTURE_2D, shadowMapTexture);
	glEnable(GL_TEXTURE_2D);

	//Enable shadow comparison
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE_ARB, GL_COMPARE_R_TO_TEXTURE);

	//Shadow comparison should be true (ie not in shadow) if r<=texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC_ARB, GL_LEQUAL);

	//Shadow comparison should generate an INTENSITY result
	glTexParameteri(GL_TEXTURE_2D, GL_DEPTH_TEXTURE_MODE_ARB, GL_INTENSITY);

	//Set alpha test to discard false comparisons
	glAlphaFunc(GL_GEQUAL, 0.99f);
	glEnable(GL_ALPHA_TEST);

	//glCallList(table);
	drawScene(levelLoad, marble, playerR, playerRZ, obj, left, right, backward, kingI, kingR, kingH, anime, boss, spider);
	//glCallList(marble);
	
	//Disable textures and texgen
	glDisable(GL_TEXTURE_2D);

	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glDisable(GL_TEXTURE_GEN_R);
	glDisable(GL_TEXTURE_GEN_Q);

	//Restore other states
	glDisable(GL_LIGHTING);
	glDisable(GL_ALPHA_TEST);
	
	//drawReflection();
	
	
			
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(-1.0f, 1.0f, -1.0f, 1.0f);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	//Print text
	glRasterPos2f(-1.0f, 0.9f);


	//reset matrices
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	
	glCallList(enemy);
			glDepthFunc(GL_LESS);
			//drawScene(levelLoad, marble, playerR, playerRZ);
			reflection(levelLoad, playerR, playerRZ, obj, frameCounter, kingH, kingI, kingR);
			glDepthFunc(GL_LEQUAL);
			glCallList(marble);
	glPushMatrix();
	GLfloat	lightpos3[4] = {px -5, py -1, pz -5, 1}; 
	glPopMatrix();
		for(int i = 0; i < sqCount; i++){
			if(squHit[i]){
				if(squHitCounter[i] > 50){
					squHit[i] = false;
				}else{
					squHitCounter[i]++;
				}
			}
			
			
			glTranslatef(squX[i], 0, squZ[i]);
	
			glRotatef((-squAngle[i] + 90), 0,1,0);
			
					//glRotatef(90, 0,0,1);
			
			glTranslatef(-squX[i], 0, -squZ[i]);
			//if(squAim == i  && bombAim > bombCount && aiming){
				glCallList(table);
			//}
			glTranslatef(squX[i], squY[i], squZ[i]);
			//cout << squX[i] << "hi" << squY[i] << "hi" << squZ[i];
			//obj.drawSqu(0, squX[i],squY[i],squZ[i], squAngle[i]);
			glEnable(GL_TEXTURE_2D);
			if (squHit[i]){
				kingH.DrawGLScene(false);
			}else if(squOldX[i] != squX[i] || squOldZ[i] != squZ[i]){
				kingR.DrawGLScene(false);
			}else{
				kingI.DrawGLScene(false);
				
			}
			glPopMatrix();
			glPushMatrix();
			//*/
			squOldX[i] = squX[i];
			squOldZ[i] = squZ[i];
			if(squAim == i  && bombAim > bombCount && aiming){
				glCallList(enemy);
			}
			
			
		}
		if(part == 1){
			for(int i =0;i < animeCount; i++){
				//if(i ==2){
				//glPushMatrix();
						glTranslatef(animeX[i], 0, animeZ[i]);
						//if(!rewindTime){
							glRotatef((-animeAngle[i]+90), 0,1,0);
						//}else{
						//	glRotatef((squAngle[i]), 0,1,0);
						//}
						//glRotatef(90, 0,0,1);
						glTranslatef(-animeX[i], 0, -animeZ[i]);
						glTranslatef(animeX[i], animeY[i], animeZ[i]);
						glEnable(GL_TEXTURE_2D);
						//kingI.Update();
						anime.DrawGLScene(false);
						glPopMatrix();
					glPushMatrix();
				//}else{
				//	obj.drawSquT(i, animeX[i], animeY[i], animeZ[i], 0);
				//}
			}
		}
		glCallList(table);
		glLightfv(GL_LIGHT0, GL_POSITION, lightpos3);
		//glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHTING);
		for(int i = 0; i < onlineCounter; i++){
			glPushMatrix();
			glTranslatef(onlineX[i], onlineY[i], onlineZ[i]);
			glTranslatef(0,-0.7,0);
			glRotatef((-onlineAngle[i])-90, 0,1,0);
			obj.drawTails(onlineFrameCounter[i]);
			glPopMatrix();
		}
		glTranslatef(px, py, pz);
		glRotatef((-angle)-90, 0,1,0);
		glTranslatef(0,-0.7,0);
		obj.drawTails(frameCounter);
		
		if(sucking || throwAnimation){
			glCallList(enemy);
			for(int i=0;i< levelLoad.caFaces.size();i++){	
					//if((i+1) % 6 == 0){	
					//if(levelLoad.caVert[levelLoad.caFaces[i]->faces[0]-1]->y < py){

							if(levelLoad.caFaces[i]->four){	//if it's a quad draw a quad
								//if((i+1) % 6 != 0){
								//	std::cout << "here 1" << std::endl;
									glBegin(GL_QUADS);
										//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
										//I subtract 1 because the index start from 0 in C++
										
										glNormal3f(levelLoad.caNormals[levelLoad.caFaces[i]->facenum-1]->x,levelLoad.caNormals[levelLoad.caFaces[i]->facenum-1]->y,levelLoad.caNormals[levelLoad.caFaces[i]->facenum-1]->z);
										//draw the faces
										glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.caVert[levelLoad.caFaces[i]->faces[0]-1]->x,levelLoad.caVert[levelLoad.caFaces[i]->faces[0]-1]->y,levelLoad.caVert[levelLoad.caFaces[i]->faces[0]-1]->z);
										glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.caVert[levelLoad.caFaces[i]->faces[1]-1]->x,levelLoad.caVert[levelLoad.caFaces[i]->faces[1]-1]->y,levelLoad.caVert[levelLoad.caFaces[i]->faces[1]-1]->z);
										glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.caVert[levelLoad.caFaces[i]->faces[2]-1]->x,levelLoad.caVert[levelLoad.caFaces[i]->faces[2]-1]->y,levelLoad.caVert[levelLoad.caFaces[i]->faces[2]-1]->z);
										glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.caVert[levelLoad.caFaces[i]->faces[3]-1]->x,levelLoad.caVert[levelLoad.caFaces[i]->faces[3]-1]->y,levelLoad.caVert[levelLoad.caFaces[i]->faces[3]-1]->z);
									glEnd();
								}else{
									
									//char path[] = "Images/block3.png";
									//treeText1= loadTexture(path,3);
									//glBindTexture(GL_TEXTURE_2D, texture5);
									glBegin(GL_QUADS);
										//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
										//I subtract 1 because the index start from 0 in C++
										
										glNormal3f(levelLoad.caNormals[levelLoad.caFaces[i]->facenum-1]->x,levelLoad.caNormals[levelLoad.caFaces[i]->facenum-1]->y,levelLoad.caNormals[levelLoad.caFaces[i]->facenum-1]->z);
										//draw the faces
										glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.caVert[levelLoad.caFaces[i]->faces[0]-1]->x,levelLoad.caVert[levelLoad.caFaces[i]->faces[0]-1]->y,levelLoad.caVert[levelLoad.caFaces[i]->faces[0]-1]->z);
										glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.caVert[levelLoad.caFaces[i]->faces[1]-1]->x,levelLoad.caVert[levelLoad.caFaces[i]->faces[1]-1]->y,levelLoad.caVert[levelLoad.caFaces[i]->faces[1]-1]->z);
										glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.caVert[levelLoad.caFaces[i]->faces[2]-1]->x,levelLoad.caVert[levelLoad.caFaces[i]->faces[2]-1]->y,levelLoad.caVert[levelLoad.caFaces[i]->faces[2]-1]->z);
										//glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.caVert[levelLoad.caFaces[i]->faces[3]-1]->x,levelLoad.caVert[levelLoad.caFaces[i]->faces[3]-1]->y,levelLoad.caVert[levelLoad.caFaces[i]->faces[3]-1]->z);
									glEnd();	
									//char path2[] = "Images/Plants/tree1.png";
									////treeText1 = loadTexture(path2, 3);
									//glBindTexture(GL_TEXTURE_2D, texture3);
								}
					//	}
				//}
			}
		}
		glCallList(marble);
		glPopMatrix();
		glEnable(GL_NORMALIZE);
		glCallList(enemy);
		glEnable(GL_LIGHTING);
		for(int i = 0; i < bombCount; i++){
			glPushMatrix();
			glTranslatef(bombX[i], 0, bombZ[i]);
			if(!rewindTime){
				glRotatef((-bombAngle), 0,1,0);
			}else{
				glRotatef((bombAngle), 0,1,0);
			}
			glTranslatef(-bombX[i], 0, -bombZ[i]);
			if(bombAim == i && aiming){
				glCallList(target);
			}
			obj.drawBomb(bombFrameCounter, bombX[i],bombY[i],bombZ[i], bombAngle);
			if(bombAim == i && aiming){
				glCallList(enemy);
			}
			glPopMatrix();
		}
		
		
		
		
		glCallList(marble);
		glPushMatrix();
		if(!pauseTime){
			if(forwardTime){
				bombAngle += 20;
			}else if(rewindTime){
				bombAngle += 10;
			}else {
				bombAngle += 10;
			}
		}
		for(int z = 0; z < projectCount; z++){
			//if(!squKilled[z]){
					float checkX = projectX[z];
					float checkZ = projectZ[z];
					bool foundL = false;
					bool foundR = false;
					bool foundU = false;
					bool foundB = false;
					float width = 0.6;
					float newAngle = 0;
					if(!pauseTime){
						for(int x = 0; x < 36; x++){
							newAngle +=10;
							checkX = projectX[z];
							checkZ = projectZ[z];
							
							for(int i = 0;i < 100; i++){
								checkX = checkX + (speed*2) * cos(newAngle * (3.14159/180));
								checkZ = checkZ + (speed*2) * sin(newAngle * (3.14159/180));
								if(checkX +width  > px && checkX< (px + width) ){
									if(checkZ  +width > pz && checkZ  < (pz + width)){
										foundU = true;
									
										projectAngle[z] = -(newAngle);
										//cout << squAngle[z] << endl;
										i = 100;
										x = 36;
									}
								}
							}
						}
					}
			//	}
			if(foundU){
				if(projectCounter[z] < 10){
					projectCounter[z]++;
				}else{
					fireProject[z] = true;
					if(projectCounter[z] < 15){
						firePrY[z] = projectY[z];
						firePrX[z] = projectX[z];
						firePrZ[z] = projectZ[z];
					}
				}
			}
			if(fireProject[z]){
				projectCounter[z]++;
				if(projectCounter[z] > 100){
					fireProject[z] = false;
					projectCounter[z] = 0;
				}
				if(!pauseTime){
					firePrX[z] = firePrX[z] + (speed*2) * cos(-projectAngle[z] * (3.14159/180));
					firePrZ[z] = firePrZ[z] + (speed*2) * sin(-projectAngle[z] * (3.14159/180));
				}
			}
		}
		for(int z = 0; z < tmCount; z++){
			float newAngle = 0;
			float width = 0.6;
			tmCooldown[z]++;
			for(int x = 0; x < 36; x++){
						newAngle +=10;
						float checkX = tMonsterX[z];
						float checkZ = tMonsterZ[z];
						
						for(int i = 0;i < 60; i++){
							
			
//float rewindSquX[20][100];
//float rewindSquZ[20][100];
//float rewindSquOldAngle[20];
//float rewindSquAngle[20][100];

//int rewindSquCounter[20];
							checkX = checkX + (speed*2) * cos(newAngle * (3.14159/180));
							checkZ = checkZ + (speed*2) * sin(newAngle * (3.14159/180));
							if(checkX +width  > px && checkX< (px + width) ){
								if(checkZ  +width > pz && checkZ  < (pz + width)){
									
									if(tmCooldown[z] > 200){
										tmCooldown[z] =0;
									}else if(tmCooldown[z] < 20){
										tMAngle[z] = newAngle;
										tMonsterX[z] = tMonsterX[z] + (speed) * cos(tMAngle[z] * (3.14159/180));
										tMonsterZ[z] = tMonsterZ[z] + (speed) * sin(tMAngle[z] * (3.14159/180));
									}
								}
								
							}
						}
			}
		}
		for(int z = 0; z < sqCount; z++){
			if(!pauseTime && !rewindTime){
				if(!squKilled[z]){
					float checkX = squX[z];
					float checkZ = squZ[z];
					bool foundL = false;
					bool foundR = false;
					bool foundU = false;
					bool foundB = false;
					float width = 0.6;
					float newAngle = 0;
					for(int x = 0; x < 36; x++){
						newAngle +=10;
						checkX = squX[z];
						checkZ = squZ[z];
						
						for(int i = 0;i < 40; i++){
							
			
//float rewindSquX[20][100];
//float rewindSquZ[20][100];
//float rewindSquOldAngle[20];
//float rewindSquAngle[20][100];

//int rewindSquCounter[20];
							checkX = checkX + (speed*2) * cos(newAngle * (3.14159/180));
							checkZ = checkZ + (speed*2) * sin(newAngle * (3.14159/180));
							if(checkX +width  > px && checkX< (px + width) ){
								if(checkZ  +width > pz && checkZ  < (pz + width)){
									foundU = true;
									squAngle[z] = (newAngle);
									if(squAngle[z] != rewindSquOldAngle[z]){
										rewindSquOldAngle[z] = squAngle[z];
										rewindSquAngle[z][rewindSquCounter[z]] = squAngle[z];
										rewindSquZ[z][rewindSquCounter[z]] = squZ[z];
										rewindSquX[z][rewindSquCounter[z]] = squX[z];
										if(rewindSquCounter[z] < 499){
											rewindSquCounter[z]++;
											//cout << rewindSquCounter[z] << ":"<< rewindSquX[z][rewindSquCounter[z]-1] << ":" << rewindSquZ[z][rewindSquCounter[z]-1] << ":" << rewindSquAngle[z][rewindSquCounter[z]-1]<< endl;
										}
									}
									//cout << squAngle[z] << endl;
									i = 40;
									x = 36;
								}
							}
						}
					}
					/*
					if(squBounceFlipped){
						squY[z] -= 0.1;
						if(squBounceCounter < 12){
							squBounceCounter++;
						}else{
							squBounceCounter = 0;
							squBounceFlipped = false;
						}
					}else{
						squY[z] += 0.1;
						if(squBounceCounter < 12){
							squBounceCounter++;
						}else{
							squBounceCounter = 0;
							squBounceFlipped = true;
						}	
					}*/
					if(foundU){
						if(!forwardTime){
							squX[z] = squX[z] + (speed) * cos(squAngle[z] * (3.14159/180));
							squZ[z] = squZ[z] + (speed) * sin(squAngle[z] * (3.14159/180));
						}else{
							squX[z] = squX[z] + (speed*2) * cos(squAngle[z] * (3.14159/180));
							squZ[z] = squZ[z] + (speed*2) * sin(squAngle[z] * (3.14159/180));
						}
					}
				}
			}else if(rewindTime){
				if(!squKilled[z]){
					int i = rewindSquCounter[z];
					squAngle[z] = rewindSquAngle[z][i];
					if(rewindSquCounter[z] > 0){
						if(rewindSquX[z][i] != 0 && rewindSquZ[z][i] != 0){
							bool foundCos = false;
							bool foundSin = false;
							
						//for(int i = rewindSquCounter[z]; i > -1; i--){
							if(squX[z] + 0.1 > rewindSquX[z][i] && squX[z] < rewindSquX[z][i] + 0.1){
								foundSin = true;
							}else{
								squX[z] = squX[z] - (speed) * cos(rewindSquAngle[z][i] * (3.14159/180));
							}
							if(squZ[z] + 0.1 > rewindSquZ[z][i] && squZ[z] < rewindSquZ[z][i] + 0.1){
								foundCos = true;
							}else{
								squZ[z] = squZ[z] - (speed) * sin(rewindSquAngle[z][i] * (3.14159/180));
							}
							if(foundCos &&foundSin){
								rewindSquCounter[z] --;
							}
						}else{
							rewindSquCounter[z] --;
						}
					}
					
				}
			}
		
		if(squKilled[z] && squX[z] != -1000){
				//bombHeart[i] =0;
				for(int v = 0; v < 100; v++){
							if(!shownForward[v]){
								shownForward[v] = randomBool();
								if(shownForward[v]){
									forwardSkewX[v] = squX[z];
									forwardSkewZ[v] = squZ[z];
									forwardSkewY[v] = squY[z];
									
									forwardSpawnX[v] = (float)RandomFloat();
									forwardSpawnX[v] += squX[z];
									//cout << rewindSpawnX[v]<< endl;
									forwardSpawnZ[v] = (float)RandomFloat();
									forwardSpawnZ[v] += squZ[z];
									forwardSpawnY[v] = squY[z];
									forwardSkewY[v] = forwardSpawnY[v];
								}
							}
							if(!shownPause[v]){
								shownPause[v]= randomBool();
								if(shownPause[v]){
									pauseSkewX[v] = squX[z];
									pauseSkewZ[v] = squZ[z];
									pauseSkewY[v] = squY[z];
									
									pauseSpawnX[v] = (float)RandomFloat();
									pauseSpawnX[v] += squX[z];
									//cout << rewindSpawnX[v]<< endl;
									pauseSpawnZ[v] = (float)RandomFloat();
									pauseSpawnZ[v] += squZ[z];
									pauseSpawnY[v] = squY[z];
									pauseSkewY[v] =  pauseSpawnY[v];
								}
							}
							if(!shownRewind[v]){
								shownRewind[v] = randomBool();
								if(shownRewind[v]){
									rewindSkewX[v] = squX[z];
									rewindSkewZ[v] = squZ[z];
									rewindSkewY[v] = squY[z];
									
									rewindSpawnX[v] = (float)RandomFloat();
									rewindSpawnX[v] += squX[z];
									//cout << rewindSpawnX[v]<< endl;
									rewindSpawnZ[v] = (float)RandomFloat();
									rewindSpawnZ[v] += squZ[z];
									rewindSpawnY[v] = squY[z];
									rewindSkewY[v] = rewindSpawnY[v];
						}
					}
					//cout << shownRewind[v] << shownPause[v] << shownForward[v] << endl;		
				}
				squX[z] = -1000;
			}
		}
		for(int i = 0; i < bombCount; i++){
		if(bombEnemy && !enKilled[i]){
			if(!pauseTime){
				
				if(bombAngle > 360){
					
					
						bombX[i] = levelLoad.bVert[levelLoad.bFaces[i*6 + 1]->faces[1]-1]->x;
						bombZ[i] = levelLoad.bVert[levelLoad.bFaces[i*6 + 1]->faces[1]-1]->z;
						bombY[i] = levelLoad.bVert[levelLoad.bFaces[i*6 + 1]->faces[1]-1]->y;
				}else if(bombAngle < -360){
					//bombAngle =0;
					bombX[i] = levelLoad.bVert[levelLoad.bFaces[i*6 + 1]->faces[1]-1]->x;
					bombZ[i] = levelLoad.bVert[levelLoad.bFaces[i*6 + 1]->faces[1]-1]->z;
					bombY[i] = levelLoad.bVert[levelLoad.bFaces[i*6 + 1]->faces[1]-1]->y;
					
				}

					if(!rewindTime){
						bombX[i] = bombX[i] + (enemySpeed*2) * cos(bombAngle * (3.14159/180));
						bombZ[i] = bombZ[i] + (enemySpeed*2) * sin(bombAngle * (3.14159/180));
					}else{
						bombX[i] = bombX[i] + (enemySpeed*2) * cos(bombAngle * (3.14159/180));
						bombZ[i] = bombZ[i] - (enemySpeed*2) * sin(bombAngle * (3.14159/180));
					}
				
			}
		}else if(bombEnemy && enKilled[i] && bombX[i] != -1000){
			if(bombHeart[i] < 7){
				bombHeart[i]++;
			}else{				
				
				//bombHeart[i] =0;
				for(int v = 0; v < 100; v++){
							if(!shownForward[v]){
								shownForward[v] = randomBool();
								if(shownForward[v]){
									forwardSkewX[v] = bombX[i];
									forwardSkewZ[v] = bombZ[i];
									forwardSkewY[v] = bombY[i];
									
									forwardSpawnX[v] = (float)RandomFloat();
									forwardSpawnX[v] += bombX[i];
									//cout << rewindSpawnX[v]<< endl;
									forwardSpawnZ[v] = (float)RandomFloat();
									forwardSpawnZ[v] += bombZ[i];
									forwardSpawnY[v] = bombY[i];
									forwardSkewY[v] = forwardSpawnY[v];
								}
							}
							if(!shownPause[v]){
								shownPause[v]= randomBool();
								if(shownPause[v]){
									pauseSkewX[v] = bombX[i];
									pauseSkewZ[v] = bombZ[i];
									pauseSkewY[v] = bombY[i];
									
									pauseSpawnX[v] = (float)RandomFloat();
									pauseSpawnX[v] += bombX[i];
									//cout << rewindSpawnX[v]<< endl;
									pauseSpawnZ[v] = (float)RandomFloat();
									pauseSpawnZ[v] += bombZ[i];
									pauseSpawnY[v] = bombY[i];
									pauseSkewY[v] =  pauseSpawnY[v];
								}
							}
							if(!shownRewind[v]){
								shownRewind[v] = randomBool();
								if(shownRewind[v]){
									rewindSkewX[v] = bombX[i];
									rewindSkewZ[v] = bombZ[i];
									rewindSkewY[v] = bombY[i];
									
									rewindSpawnX[v] = (float)RandomFloat();
									rewindSpawnX[v] += bombX[i];
									//cout << rewindSpawnX[v]<< endl;
									rewindSpawnZ[v] = (float)RandomFloat();
									rewindSpawnZ[v] += bombZ[i];
									rewindSpawnY[v] = bombY[i];
									rewindSkewY[v] = rewindSpawnY[v];
						}
					}
					//cout << shownRewind[v] << shownPause[v] << shownForward[v] << endl;		
				}
				bombX[i] = -1000;
			}
		}			
			//obj.drawBomb(bombFrameCounter, bombX,bombY,bombZ, bombAngle);
		}
		if(bombAngle > 360){
			bombAngle = 0;
		}
		glPopMatrix();
		
		//glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);
		loadCrystals(levelLoad);
		
		
		glCallList(table);
		
		glDisable(GL_LIGHTING);
				glPushMatrix();
	  float length = 100;
	float height = 100;
	float width = 100;
				//glTranslatef(px -5, py -1, pz -5);
				glEnable(GL_TEXTURE_2D);
				glDisable(GL_LIGHTING);
				
					glPushMatrix();
					glRotatef(180,1,0,0);
					glBindTexture(GL_TEXTURE_2D, skyB);
					glTranslatef(0,-(height*2), 0);
					glBegin(GL_QUADS);
				
				
					//glNormal3f(0.0f, 1.0f, 0.0f);
					glTexCoord2d(1.0f, 0.0f); glVertex3f( width, height, -length); // Top Right Of The Quad (Top)
					glTexCoord2d(1.0f, 1.0f); glVertex3f(-width, height, -length); // Top Left Of The Quad (Top)
					glTexCoord2d(0.0, 1.0f); glVertex3f(-width, height, length); // Bottom Left Of The Quad (Top)
					glTexCoord2d(0.0, 0.0f); glVertex3f( width, height, length); // Bottom Right Of The Quad (Top)
					glEnd();
					
				glPopMatrix();
				
					glPushMatrix();
					//glRotatef(180,1,0,0);
					glTranslatef(0,-(height*2), 0);
					
					//glRotatef(180, 0,1, 0);
					glBindTexture(GL_TEXTURE_2D, skyT);
					glBegin(GL_QUADS);
					//glNormal3f(0.0f, 1.0f, 0.0f);
					glTexCoord2d(1.0f, 0.0f); glVertex3f( width, height, -length); // Top Right Of The Quad (Top)
					glTexCoord2d(1.0f, 1.0f); glVertex3f(-width, height, -length); // Top Left Of The Quad (Top)
					glTexCoord2d(0.0, 1.0f); glVertex3f(-width, height, length); // Bottom Left Of The Quad (Top)
					glTexCoord2d(0.0, 0.0f); glVertex3f( width, height, length); // Bottom Right Of The Quad (Top)
					glEnd();
					
					
					glPopMatrix();
					
					
					//glRotatef(180,1,0,0);
					glPushMatrix();
					glRotatef(180,0,0,1);
					glTranslatef((height*2),0, 0);
					glBindTexture(GL_TEXTURE_2D, skyL);
					glBegin(GL_QUADS);
					//glNormal3f(-1.0f, 0.0f, 0.0f);
					glTexCoord2d(1.0f, 0.0f); glVertex3f(-width, height, -length); // Top Right Of The Quad (Left)
					glTexCoord2d(1.0f, 1.0f); glVertex3f(-width, -height, -length); // Top Left Of The Quad (Left)
					glTexCoord2d(0.0f, 1.0f); glVertex3f(-width, -height, length); // Bottom Left Of The Quad (Left)
					glTexCoord2d(0.0f, 0.0f); glVertex3f(-width, height, length); // Bottom Right Of The Quad (Left)
					glEnd();
					glPopMatrix();
				
					
					glPushMatrix();
					glRotatef(180,0,0,1);
					glTranslatef(-(height*2),0, 0);
					glBindTexture(GL_TEXTURE_2D, skyR);
					glBegin(GL_QUADS);
					//glNormal3f(1.0f, 0.0f, 0.0f);
					glTexCoord2d(0.0f, 0.0f); glVertex3f( width, height, -length); // Top Right Of The Quad (Right)
					glTexCoord2d(1.0f, 0.0f); glVertex3f( width, height, length); // Top Left Of The Quad (Right)
					glTexCoord2d(1.0f, 1.0f); glVertex3f( width, -height, length); // Bottom Left Of The Quad (Right)
					glTexCoord2d(0.0f, 1.0f); glVertex3f( width, -height, -length); // Bottom Right Of The Quad (Right)
					glEnd();
					
					glPopMatrix();
					
					
				


					glPushMatrix();
					glBindTexture(GL_TEXTURE_2D, skyF);
					glTranslatef(0,0, (height*2));
					glBegin(GL_QUADS);
					//glNormal3f(0.0f, 0.0f, 1.0f);
					glTexCoord2d(0.0f, 1.0f); glVertex3f( width, -height, -length); // Bottom Left Of The Quad (Back)
					glTexCoord2d(1.0f, 1.0f); glVertex3f(-width, -height, -length); // Bottom Right Of The Quad (Back)
					glTexCoord2d(1.0f, 0.0f); glVertex3f(-width, height, -length); // Top Right Of The Quad (Back)
					glTexCoord2d(0.0f, 0.0f); glVertex3f( width, height, -length); // Top Left Of The Quad (Back)
					glEnd();
					glPopMatrix();
					
					glPushMatrix();
					//glRotatef(180,0,0,1);
					glTranslatef(0,0, -(height*2));
					glBindTexture(GL_TEXTURE_2D, skyBk);
					glBegin(GL_QUADS);
					//glNormal3f(0.0f, 0.0f, -1.0f);
					glTexCoord2d(0.0f, 0.0f); glVertex3f( width, height, length); // Top Right Of The Quad (Front)
					glTexCoord2d(1.0f, 0.0f); glVertex3f(-width, height, length); // Top Left Of The Quad (Front)
					glTexCoord2d(1.0f, 1.0f); glVertex3f(-width, -height, length); // Bottom Left Of The Quad (Front)
					glTexCoord2d(0.0f, 1.0f); glVertex3f( width, -height, length); // Bottom Right Of The Quad (Front)
					glEnd();
					
					glPopMatrix();
					
					glEnable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);
		loadCrystals(levelLoad);
		
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glEnable(GL_BLEND);
			
		for(int i = 0; i < bombCount; i++){
			glPushMatrix();
			glTranslatef(bombX[i], bombY[i]+2, bombZ[i]);
			glRotatef(-(angleX + 45), 0,1,0);
			//glRotatef(newAngleZ, 0,0,1);
			glBindTexture(GL_TEXTURE_2D, heartDeplete[bombHeart[i]]);
			glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0);glVertex3f(-0.5f, -0.5, -0.5f);
				glTexCoord2f(0.0, 1.0); glVertex3f(-0.5f,  0.5f, -0.5f);
				glTexCoord2f(1.0, 1.0); glVertex3f( 0.5f,  0.5f, -0.5f);
				glTexCoord2f(1.0, 0.0);   glVertex3f( 0.5f, -0.5f, -0.5f);
			glEnd();
			glPopMatrix();
		}
		for(int i = 0; i < rewindCounter; i++){
			glPushMatrix();
			glTranslatef(cameraPosition.x, cameraPosition.y, cameraPosition.z);
			glTranslatef(4, 5, 2);
			glRotatef(35, 1,0,0);
			glRotatef(-35, 0, 0, 1);
			glTranslatef(0,2,0);
			glTranslatef(i, 0, 0);
			glBindTexture(GL_TEXTURE_2D, rewindTexture);
			glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0);glVertex3f(-0.5f, -0.5, -0.5f);
				glTexCoord2f(0.0, 1.0); glVertex3f(-0.5f,  0.5f, -0.5f);
				glTexCoord2f(1.0, 1.0); glVertex3f( 0.5f,  0.5f, -0.5f);
				glTexCoord2f(1.0, 0.0);   glVertex3f( 0.5f, -0.5f, -0.5f);
			glEnd();
			glPopMatrix();
		}
		for(int i = 0; i < forwardCounter; i++){
			glPushMatrix();
			glTranslatef(cameraPosition.x, cameraPosition.y, cameraPosition.z);
			glTranslatef(4, 5, 2);
			glRotatef(35, 1,0,0);
			glRotatef(-35, 0, 0, 1);
			glTranslatef(0,2,0);
			glTranslatef(i + rewindCounter, 0, 0);
			glBindTexture(GL_TEXTURE_2D, forwardTexture);
			glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0);glVertex3f(-0.5f, -0.5, -0.5f);
				glTexCoord2f(0.0, 1.0); glVertex3f(-0.5f,  0.5f, -0.5f);
				glTexCoord2f(1.0, 1.0); glVertex3f( 0.5f,  0.5f, -0.5f);
				glTexCoord2f(1.0, 0.0);   glVertex3f( 0.5f, -0.5f, -0.5f);
			glEnd();
			glPopMatrix();
		}
		for(int i = 0; i < pauseCounter; i++){
			glPushMatrix();
			glTranslatef(cameraPosition.x, cameraPosition.y, cameraPosition.z);
			glTranslatef(4, 5, 2);
			glRotatef(35, 1,0,0);
			glRotatef(-35, 0, 0, 1);
			glTranslatef(0,2,0);
			glTranslatef(i + (forwardCounter + rewindCounter), 0, 0);
			glBindTexture(GL_TEXTURE_2D, pauseTexture);
			glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0);glVertex3f(-0.5f, -0.5, -0.5f);
				glTexCoord2f(0.0, 1.0); glVertex3f(-0.5f,  0.5f, -0.5f);
				glTexCoord2f(1.0, 1.0); glVertex3f( 0.5f,  0.5f, -0.5f);
				glTexCoord2f(1.0, 0.0);   glVertex3f( 0.5f, -0.5f, -0.5f);
			glEnd();
			glPopMatrix();
		}
		for(int i = 0; i < hearts; i++){
			glPushMatrix();
			glTranslatef(cameraPosition.x, cameraPosition.y, cameraPosition.z);
			glTranslatef(4, 5, 2);
			glRotatef(35, 1,0,0);
			glRotatef(-35, 0, 0, 1);
			glTranslatef(0,1,0);
			glTranslatef(i, 0, 0);
			glBindTexture(GL_TEXTURE_2D, heartT);
			glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0);glVertex3f(-0.5f, -0.5, -0.5f);
				glTexCoord2f(0.0, 1.0); glVertex3f(-0.5f,  0.5f, -0.5f);
				glTexCoord2f(1.0, 1.0); glVertex3f( 0.5f,  0.5f, -0.5f);
				glTexCoord2f(1.0, 0.0);   glVertex3f( 0.5f, -0.5f, -0.5f);
			glEnd();
			glPopMatrix();
		}
		
		
		for(int i = 0; i < binVentory; i++){
			glPushMatrix();
			glTranslatef(cameraPosition.x, cameraPosition.y, cameraPosition.z);
			glTranslatef(4, 5, 2);
			glRotatef(35, 1,0,0);
			glRotatef(-35, 0, 0, 1);
			glTranslatef(i, 0, 0);
			glBindTexture(GL_TEXTURE_2D, barrelT);
			glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0);glVertex3f(-0.5f, -0.5, -0.5f);
				glTexCoord2f(0.0, 1.0); glVertex3f(-0.5f,  0.5f, -0.5f);
				glTexCoord2f(1.0, 1.0); glVertex3f( 0.5f,  0.5f, -0.5f);
				glTexCoord2f(1.0, 0.0);   glVertex3f( 0.5f, -0.5f, -0.5f);
			glEnd();
			glPopMatrix();
		}
					//glDisable(GL_TEXTURE_2D);
					glEnable(GL_LIGHTING);
		
		glBindTexture(GL_TEXTURE_2D, trapTexture);
		for(int v = 0; v < trapCount; v++){
				glPushMatrix();
				glTranslatef(trapX[v], trapY[v] + trapRespawn[v], trapZ[v]);
				for(int i=0;i< levelLoad.trOFaces.size();i++){	
						
						if(levelLoad.trOFaces[i]->four){	//if it's a quad draw a quad

							//	std::cout << "here 1" << std::endl;
							glBegin(GL_QUADS);
								//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
								//I subtract 1 because the index start from 0 in C++
								
								glNormal3f(levelLoad.trONormals[levelLoad.trOFaces[i]->facenum-1]->x,levelLoad.trONormals[levelLoad.trOFaces[i]->facenum-1]->y,levelLoad.trONormals[levelLoad.trOFaces[i]->facenum-1]->z);
							//draw the faces
								glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.trOVert[levelLoad.trOFaces[i]->faces[0]-1]->x ,levelLoad.trOVert [levelLoad.trOFaces[i]->faces[0]-1]->y,levelLoad.trOVert [levelLoad.trOFaces[i]->faces[0]-1]->z );
								glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.trOVert[levelLoad.trOFaces[i]->faces[1]-1]->x ,levelLoad.trOVert [levelLoad.trOFaces[i]->faces[1]-1]->y,levelLoad.trOVert [levelLoad.trOFaces[i]->faces[1]-1]->z );
								glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.trOVert [levelLoad.trOFaces[i]->faces[2]-1]->x ,levelLoad.trOVert [levelLoad.trOFaces[i]->faces[2]-1]->y,levelLoad.trOVert [levelLoad.trOFaces[i]->faces[2]-1]->z );
								glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.trOVert [levelLoad.trOFaces[i]->faces[3]-1]->x ,levelLoad.trOVert [levelLoad.trOFaces[i]->faces[3]-1]->y,levelLoad.trOVert [levelLoad.trOFaces[i]->faces[3]-1]->z );
							glEnd();

						}else{
						//	std::cout << cVertex[levelLoad.trOFaces[i]->faces[0]-1]->x << cVertex[levelLoad.trOFaces[i]->faces[0]-1]->y << cVertex[levelLoad.trOFaces[i]->faces[0]-1]->z << std::endl;
							//std::cout << vertex[levelLoad.trOFaces[i]->faces[1]-1]->x << vertex[levelLoad.trOFaces[i]->faces[1]-1]->y << vertex[levelLoad.trOFaces[i]->faces[1]-1]->z << std::endl;
							//std::cout << vertex[levelLoad.trOFaces[i]->faces[2]-1]->x << vertex[levelLoad.trOFaces[i]->faces[2]-1]->y << vertex[levelLoad.trOFaces[i]->faces[2]-1]->z << std::endl;
							glBegin(GL_TRIANGLES);
								//glBindTexture(GL_TEXTURE_2D, texture3);
								glNormal3f(levelLoad.trONormals[levelLoad.trOFaces[i]->facenum-1]->x,levelLoad.trONormals[levelLoad.trOFaces[i]->facenum-1]->y,levelLoad.trONormals[levelLoad.trOFaces[i]->facenum-1]->z);
								glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.trOVert [levelLoad.trOFaces[i]->faces[0]-1]->x ,levelLoad.trOVert [levelLoad.trOFaces[i]->faces[0]-1]->y,levelLoad.trOVert [levelLoad.trOFaces[i]->faces[0]-1]->z );
								glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.trOVert [levelLoad.trOFaces[i]->faces[1]-1]->x ,levelLoad.trOVert [levelLoad.trOFaces[i]->faces[1]-1]->y,levelLoad.trOVert [levelLoad.trOFaces[i]->faces[1]-1]->z );
								glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.trOVert [levelLoad.trOFaces[i]->faces[2]-1]->x ,levelLoad.trOVert [levelLoad.trOFaces[i]->faces[2]-1]->y,levelLoad.trOVert [levelLoad.trOFaces[i]->faces[2]-1]->z );
							glEnd();
						}
					}
				glPopMatrix();
			}
			glBindTexture(GL_TEXTURE_2D, magTexture);
				for(int i=0;i< levelLoad.maFaces.size();i++){	
						
						if(levelLoad.maFaces[i]->four){	//if it's a quad draw a quad

							//	std::cout << "here 1" << std::endl;
							glBegin(GL_QUADS);
								//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
								//I submaact 1 because the index start from 0 in C++
								
								glNormal3f(levelLoad.maNormals[levelLoad.maFaces[i]->facenum-1]->x,levelLoad.maNormals[levelLoad.maFaces[i]->facenum-1]->y,levelLoad.maNormals[levelLoad.maFaces[i]->facenum-1]->z);
							//draw the faces
								glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.maVert[levelLoad.maFaces[i]->faces[0]-1]->x ,levelLoad.maVert[levelLoad.maFaces[i]->faces[0]-1]->y ,levelLoad.maVert[levelLoad.maFaces[i]->faces[0]-1]->z );
								glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.maVert[levelLoad.maFaces[i]->faces[1]-1]->x ,levelLoad.maVert[levelLoad.maFaces[i]->faces[1]-1]->y ,levelLoad.maVert[levelLoad.maFaces[i]->faces[1]-1]->z );
								glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.maVert[levelLoad.maFaces[i]->faces[2]-1]->x ,levelLoad.maVert[levelLoad.maFaces[i]->faces[2]-1]->y ,levelLoad.maVert[levelLoad.maFaces[i]->faces[2]-1]->z );
								glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.maVert[levelLoad.maFaces[i]->faces[3]-1]->x ,levelLoad.maVert[levelLoad.maFaces[i]->faces[3]-1]->y ,levelLoad.maVert[levelLoad.maFaces[i]->faces[3]-1]->z );
							glEnd();

						}else{
						//	std::cout << cVertex[levelLoad.maFaces[i]->faces[0]-1]->x << cVertex[levelLoad.maFaces[i]->faces[0]-1]->y << cVertex[levelLoad.maFaces[i]->faces[0]-1]->z << std::endl;
							//std::cout << vertex[levelLoad.maFaces[i]->faces[1]-1]->x << vertex[levelLoad.maFaces[i]->faces[1]-1]->y << vertex[levelLoad.maFaces[i]->faces[1]-1]->z << std::endl;
							//std::cout << vertex[levelLoad.maFaces[i]->faces[2]-1]->x << vertex[levelLoad.maFaces[i]->faces[2]-1]->y << vertex[levelLoad.maFaces[i]->faces[2]-1]->z << std::endl;
							glBegin(GL_TRIANGLES);
								//glBindTexture(GL_TEXTURE_2D, texture3);
								glNormal3f(levelLoad.maNormals[levelLoad.maFaces[i]->facenum-1]->x,levelLoad.maNormals[levelLoad.maFaces[i]->facenum-1]->y,levelLoad.maNormals[levelLoad.maFaces[i]->facenum-1]->z);
								glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.maVert[levelLoad.maFaces[i]->faces[0]-1]->x ,levelLoad.maVert[levelLoad.maFaces[i]->faces[0]-1]->y ,levelLoad.maVert[levelLoad.maFaces[i]->faces[0]-1]->z );
								glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.maVert[levelLoad.maFaces[i]->faces[1]-1]->x ,levelLoad.maVert[levelLoad.maFaces[i]->faces[1]-1]->y ,levelLoad.maVert[levelLoad.maFaces[i]->faces[1]-1]->z );
								glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.maVert[levelLoad.maFaces[i]->faces[2]-1]->x ,levelLoad.maVert[levelLoad.maFaces[i]->faces[2]-1]->y ,levelLoad.maVert[levelLoad.maFaces[i]->faces[2]-1]->z );
							glEnd();
						}
					}
				glBindTexture(GL_TEXTURE_2D, spikeTexture);
				for(int i=0;i< levelLoad.spFaces.size();i++){	
						
						if(levelLoad.spFaces[i]->four){	//if it's a quad draw a quad

							//	std::cout << "here 1" << std::endl;
							glBegin(GL_QUADS);
								//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
								//I subspact 1 because the index start from 0 in C++
								
								glNormal3f(levelLoad.spNormals[levelLoad.spFaces[i]->facenum-1]->x,levelLoad.spNormals[levelLoad.spFaces[i]->facenum-1]->y,levelLoad.spNormals[levelLoad.spFaces[i]->facenum-1]->z);
							//draw the faces
								glTexCoord2f(1.0, 1.0);glVertex3f(levelLoad.spVert[levelLoad.spFaces[i]->faces[0]-1]->x ,levelLoad.spVert[levelLoad.spFaces[i]->faces[0]-1]->y ,levelLoad.spVert[levelLoad.spFaces[i]->faces[0]-1]->z );
								glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.spVert[levelLoad.spFaces[i]->faces[1]-1]->x ,levelLoad.spVert[levelLoad.spFaces[i]->faces[1]-1]->y ,levelLoad.spVert[levelLoad.spFaces[i]->faces[1]-1]->z );
								glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.spVert[levelLoad.spFaces[i]->faces[2]-1]->x ,levelLoad.spVert[levelLoad.spFaces[i]->faces[2]-1]->y ,levelLoad.spVert[levelLoad.spFaces[i]->faces[2]-1]->z );
								glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.spVert[levelLoad.spFaces[i]->faces[3]-1]->x ,levelLoad.spVert[levelLoad.spFaces[i]->faces[3]-1]->y ,levelLoad.spVert[levelLoad.spFaces[i]->faces[3]-1]->z );
							glEnd();

						}else{
						//	std::cout << cVertex[levelLoad.spFaces[i]->faces[0]-1]->x << cVertex[levelLoad.spFaces[i]->faces[0]-1]->y << cVertex[levelLoad.spFaces[i]->faces[0]-1]->z << std::endl;
							//std::cout << vertex[levelLoad.spFaces[i]->faces[1]-1]->x << vertex[levelLoad.spFaces[i]->faces[1]-1]->y << vertex[levelLoad.spFaces[i]->faces[1]-1]->z << std::endl;
							//std::cout << vertex[levelLoad.spFaces[i]->faces[2]-1]->x << vertex[levelLoad.spFaces[i]->faces[2]-1]->y << vertex[levelLoad.spFaces[i]->faces[2]-1]->z << std::endl;
							glBegin(GL_TRIANGLES);
								//glBindTexture(GL_TEXTURE_2D, texture3);
								glNormal3f(levelLoad.spNormals[levelLoad.spFaces[i]->facenum-1]->x,levelLoad.spNormals[levelLoad.spFaces[i]->facenum-1]->y,levelLoad.spNormals[levelLoad.spFaces[i]->facenum-1]->z);
								glTexCoord2f(0.0, 0.0);glVertex3f(levelLoad.spVert[levelLoad.spFaces[i]->faces[0]-1]->x ,levelLoad.spVert[levelLoad.spFaces[i]->faces[0]-1]->y ,levelLoad.spVert[levelLoad.spFaces[i]->faces[0]-1]->z );
								glTexCoord2f(1.0, 0.0);glVertex3f(levelLoad.spVert[levelLoad.spFaces[i]->faces[1]-1]->x ,levelLoad.spVert[levelLoad.spFaces[i]->faces[1]-1]->y ,levelLoad.spVert[levelLoad.spFaces[i]->faces[1]-1]->z );
								glTexCoord2f(0.0, 1.0);glVertex3f(levelLoad.spVert[levelLoad.spFaces[i]->faces[2]-1]->x ,levelLoad.spVert[levelLoad.spFaces[i]->faces[2]-1]->y ,levelLoad.spVert[levelLoad.spFaces[i]->faces[2]-1]->z );
							glEnd();
						}
					}
					glCallList(marble);
		//glEnable(GL_L);
				//glDisable(GL_TEXTURE_2D);
		glDisable(GL_TEXTURE_2D);
		//glEnable(GL_LIGHTING);
		//hud
		glDisable(GL_BLEND);
		
		
		//glPopMatrix();
		for(int i = 0; i < 100; i++){
				if(!rewindTime){
					if(shownPause[i]){
						if(!pauseBounce[i]){
							int collect =0;
							if(pauseSkewX[i] < pauseSpawnX[i]){
								pauseSkewX[i] += enemySpeed;
							}else if(pauseSkewX[i] > pauseSpawnX[i] + enemySpeed){
								pauseSkewX[i] -= enemySpeed;
							}else{
								collect++;
							}
							if(pauseSkewZ[i] < pauseSpawnZ[i]){
								pauseSkewZ[i] += enemySpeed;
							}else if(pauseSkewZ[i] > pauseSpawnZ[i] + enemySpeed){
								pauseSkewZ[i] -= enemySpeed;
							}else{
								collect++;
							}
							if(pauseSkewY[i] < pauseSpawnY[i]){
								pauseSkewY[i] += enemySpeed;
							}else if(pauseSkewY[i] > pauseSpawnY[i] + enemySpeed){
								pauseSkewY[i] -= enemySpeed;
							}else{
								collect++;
							}
							if(collect ==3){
								pauseCollectable[i] = true;
							}
						}else{
							pauseSkewY[i] += enemySpeed;
							if(pauseSkewY[i] > pauseSpawnY[i] + 1.5){
								pauseBounce[i] = false;
							}
						}
					}
					if(shownRewind[i]){
						if(!rewindBounce[i]){
							int collect = 0;
							if(rewindSkewX[i] < rewindSpawnX[i]){
								rewindSkewX[i] += enemySpeed;
							}else if(rewindSkewX[i] > rewindSpawnX[i] + enemySpeed){
								rewindSkewX[i] -= enemySpeed;
							}else{
								collect++;
							}
							if(rewindSkewZ[i] < rewindSpawnZ[i]){
								rewindSkewZ[i] += enemySpeed;
							}else if(rewindSkewZ[i] > rewindSpawnZ[i] + enemySpeed){
								rewindSkewZ[i] -= enemySpeed;
							}else{
								collect++;
							}
							if(rewindSkewY[i] < rewindSpawnY[i]){
								rewindSkewY[i] += enemySpeed;
							}else if(rewindSkewY[i] > rewindSpawnY[i] + enemySpeed){
								rewindSkewY[i] -= enemySpeed;
							}else{
								collect++;
							}
							if(collect ==3){
								rewindCollectable[i] = true;
							}
						}else{
							rewindSkewY[i] += enemySpeed;
							if(rewindSkewY[i] > rewindSpawnY[i] + 1.5){
								rewindBounce[i] = false;
							}
						}
					}
					if(shownForward[i]){
						if(!forwardBounce[i]){
							int collect = 0;
							if(forwardSkewX[i] < forwardSpawnX[i]){
								forwardSkewX[i] += enemySpeed;
							}else if(forwardSkewX[i] > forwardSpawnX[i] + enemySpeed){
								forwardSkewX[i] -= enemySpeed;
							}else{
								collect++;
							}
							if(forwardSkewZ[i] < forwardSpawnZ[i]){
								forwardSkewZ[i] += enemySpeed;
							}else if(forwardSkewZ[i] > forwardSpawnZ[i] + enemySpeed){
								forwardSkewZ[i] -= enemySpeed;
							}else{
								collect++;
							}
							if(forwardSkewY[i] < forwardSpawnY[i]){
								forwardSkewY[i] += enemySpeed;
							}else if(forwardSkewY[i] > forwardSpawnY[i] + enemySpeed){
								forwardSkewY[i] -= enemySpeed;
							}else{
								collect++;
							}
							if(collect ==3){
								forwardCollectable[i] = true;
							}
						}else{
							forwardSkewY[i] += enemySpeed;
							if(forwardSkewY[i] > forwardSpawnY[i]+ 1.5){
								forwardBounce[i] = false;
							}
						}
					}
				}else{
					for(int i = 0; i < bombCount; i++){
						if(pauseBounce[i]){
							if(pauseSkewX[i] > bombX[i]){
								pauseSkewX[i] += enemySpeed;
							}else if(pauseSkewX[i] < bombX[i]){
								pauseSkewX[i] -= enemySpeed;
							}
							if(pauseSkewZ[i] > bombZ[i]){
								pauseSkewZ[i] += enemySpeed;
							}else if(pauseSkewZ[i] < bombZ[i]){
								pauseSkewZ[i] -= enemySpeed;
							}
						}else{
							pauseSkewY[i] += enemySpeed;
							if(pauseSkewY[i] > pauseSpawnY[i] + 2){
								pauseBounce[i] = false;
							}
						}
						if(rewindBounce[i]){
							if(rewindSkewX[i]> bombX[i]){
								rewindSkewX[i] += enemySpeed;
							}else if(rewindSkewX[i] < bombX[i]){
								rewindSkewX[i] -= enemySpeed;
							}
							if(rewindSkewZ[i] > bombZ[i]){
								rewindSkewZ[i] += enemySpeed;
							}else if(rewindSkewZ[i] < bombZ[i]){
								rewindSkewZ[i] -= enemySpeed;
							}
						}else{
							rewindSkewY[i] += enemySpeed;
							if(rewindSkewY[i] > pauseSpawnY[i] + 2){
								rewindBounce[i] = false;
							}
						}
						if(forwardBounce[i]){
						if(forwardSkewX[i] > bombX[i]){
							forwardSkewX[i] += enemySpeed;
						}else if(forwardSkewX[i] < bombX[i]){
							forwardSkewX[i] -= enemySpeed;
						}
						if(forwardSkewZ[i] > bombZ[i]){
							forwardSkewZ[i] += enemySpeed;
						}else if(forwardSkewZ[i] < bombZ[i]){
							forwardSkewZ[i] -= enemySpeed;
						}
						}else{
							forwardSkewY[i] -= enemySpeed;
							if(forwardSkewY[i] < forwardSpawnY[i] +2){
								forwardBounce[i] = false;
							}
						}
					}
				}
			}
			
		//}
		
		for(int i = 0; i < onlineCounter; i++){
			if(onlineCurrentAnimation[i].find("RUN") != std::string::npos){
				onlineRunning[i] = true;
				if(!onlineRunningDone[i]){
					onlineRunningDone[i] = true;
					onlineFrameCounter[i] = 0;
				}
			}else if(onlineCurrentAnimation[i].find("JMP") != std::string::npos){
				onlineJumpingAnimation[i] = true;
				if(!onlineJumpingDone[i]){
					onlineJumpingDone[i] = true;
					onlineFrameCounter[i] = 20;
				}
				//cout << "jump" << endl;
			}
			if(onlineCurrentAnimation[i].find("SUC") != std::string::npos){
				onlineSucking[i] = true;
			}
			if(onlineCurrentAnimation[i].find("HIY") != std::string::npos){
				onlineHi[i] = true;
				if(!onlineHiDone[i]){
					onlineHiDone[i] = true;
					onlineFrameCounter[i] = 7;
				}
			}
			if(onlineCurrentAnimation[i].find("THW") != std::string::npos){
				onlineThrowAnimation[i] = true;
			}
			
			if(onlineCurrentAnimation[i].find("NON") != std::string::npos){
				onlineThrowAnimation[i] = false;
				onlineSucking[i] = false;
				onlineRunning[i] = false;
				onlineJumpingAnimation[i] = false;
				onlineJumpingDone[i] = false;
				onlineHi[i] = false;
				onlineHiDone[i] = false;
				onlineRunningDone[i] = false;
				onlineFrameCounter[i] = 18;
			}
		}
		for(int i = 0;i < onlineCounter; i++){
			
			if(onlineSucking[i] || onlineThrowAnimation[i]){
				onlineFrameCounter[i] = 23;
			}else{
				if(onlineJumpingAnimation[i]){
					if(onlineFrameCounter[i] < 22){
						onlineFrameCounter[i]++;
					}
				}else if(onlineRunning[i]){
					if(onlineSwitchAnimate[i] == false){
						if(onlineFrameCounter[i] < 7){
							onlineFrameCounter[i]++;
						}else{
							onlineSwitchAnimate[i] = true;
						}
					}else{
						if(onlineFrameCounter[i] > 0){
							onlineFrameCounter[i]--;
						}else{
							onlineSwitchAnimate[i] = false;
						}
					}
				}else if(onlineHi[i]){
					if(onlineSwitchAnimate[i] == false){
						if(onlineFrameCounter[i] < 17){
							onlineFrameCounter[i]++;
						}else{
							onlineSwitchAnimate[i] = true;
						}
					}else{
						if(onlineFrameCounter[i] > 8){
							onlineFrameCounter[i]--;
						}else{
							onlineHi[i] = false;
							onlineSwitchAnimate[i] = false;
							//sayingHi = false;
						}
					}
					
				}else{
					if(onlineSwitchAnimate[i] == false){
						if(onlineFrameCounter[i] < 20){
							onlineFrameCounter[i]++;
						}else{
							onlineSwitchAnimate[i] = true;
						}
					}else{
						if(onlineFrameCounter[i] > 18){
							onlineFrameCounter[i]--;
						}else{
							onlineHi[i] = false;
							onlineSwitchAnimate[i] = false;
							//sayingHi = false;
						}
					}
				}
			}
			onlineLastY[i] = onlineY[i];
		}
		if(world == 0 && part ==10){
			if(bossOldLives > bossLives){
				bossS.play();
			}
			bossOldLives = bossLives;
			if(bossKilled && !bossFinished){
				std::string bfMap = "Objects/world/bossFinish.obj";
				char * bfArray = (char*) bfMap.c_str();
				levelLoad.loadFinish(bfArray);
				bossFinished = true;
			}else{
				if(bossFindCounter > 50){
					bossX = bossX + (enemySpeed*2) * cos(bossAngle * (3.14159/180));
					bossZ = bossZ + (enemySpeed*2) * sin(bossAngle * (3.14159/180));
					bossAngle+=5;
					if(bossAngle > 360){
						bossAngle = 0;
						bossFindCounter =0;
					}
					for(int v = 0; v <100; v++){
						if(!shownPause[v]){
							shownPause[v]= randomBool();
							if(shownPause[v]){
								pauseSkewX[v] = bossX;
								pauseSkewZ[v] = bossZ;
								pauseSkewY[v] = bossY;
									
								pauseSpawnX[v] = (float)RandomFloat();
								pauseSpawnX[v] += bossX;
									//cout << rewindSpawnX[v]<< endl;
								pauseSpawnZ[v] = (float)RandomFloat();
								pauseSpawnZ[v] += bossZ;
								pauseSpawnY[v] = bossY;
								pauseSkewY[v] =  pauseSpawnY[v];
							}
							if(!shownForward[v]){
								shownForward[v] = randomBool();
								if(shownForward[v]){
									forwardSkewX[v] = bossX;
									forwardSkewZ[v] = bossZ;
									forwardSkewY[v] = bossY;
									
									forwardSpawnX[v] = (float)RandomFloat();
									forwardSpawnX[v] += bossX;
									//cout << rewindSpawnX[v]<< endl;
									forwardSpawnZ[v] = (float)RandomFloat();
									forwardSpawnZ[v] += bossZ;
									forwardSpawnY[v] = bossY;
									forwardSkewY[v] = forwardSpawnY[v];
								}
							}
						}
					}
				}else{
					bossFindCounter++;
					float checkX = bossX;
						float checkZ = bossZ;
						bool foundL = false;
						bool foundR = false;
						bool foundU = false;
						bool foundB = false;
						float width = 2;
						float newAngle = 0;
						for(int x = 0; x < 36; x++){
							newAngle +=10;
							checkX = bossX;
							checkZ = bossZ;
							
							for(int i = 0;i < 200; i++){
								
				
	//float rewindSquX[20][100];
	//float rewindSquZ[20][100];
	//float rewindSquOldAngle[20];
	//float rewindSquAngle[20][100];

	//int rewindSquCounter[20];
								checkX = checkX + (speed*2) * cos(newAngle * (3.14159/180));
								checkZ = checkZ + (speed*2) * sin(newAngle * (3.14159/180));
								if(checkX +width  > px && checkX< (px + width) ){
									if(checkZ  +width > pz && checkZ  < (pz + width)){
										foundU = true;
										bossAngle = (newAngle);
										//cout << squAngle[z] << endl;
										i = 200;
										x = 36;
									}
								}
							}
						}
						/*
						if(squBounceFlipped){
							squY[z] -= 0.1;
							if(squBounceCounter < 12){
								squBounceCounter++;
							}else{
								squBounceCounter = 0;
								squBounceFlipped = false;
							}
						}else{
							squY[z] += 0.1;
							if(squBounceCounter < 12){
								squBounceCounter++;
							}else{
								squBounceCounter = 0;
								squBounceFlipped = true;
							}	
						}*/
						if(foundU){
							if(!forwardTime){
								bossX = bossX + (speed) * cos(bossAngle * (3.14159/180));
								bossZ = bossZ + (speed) * sin(bossAngle * (3.14159/180));
							}
						}
				}
			}
		}
		if(sucking || throwAnimation){
			frameCounter = 23;
		}else{
			if(!jump_allowed){
				if(frameCounter < 22){
					frameCounter++;
				}
			}else if(running){
				if(switchAnimate == false){
					if(frameCounter < 7){
						frameCounter++;
					}else{
						switchAnimate = true;
					}
				}else{
					if(frameCounter > 0){
						frameCounter--;
					}else{
						switchAnimate = false;
					}
				}
			}else if(hi){
				if(switchAnimate == false){
					if(frameCounter < 17){
						frameCounter++;
					}else{
						switchAnimate = true;
					}
				}else{
					if(frameCounter > 8){
						frameCounter--;
					}else{
						hi = false;
						switchAnimate = false;
						sayingHi = false;
					}
				}
				
			}else{
				if(switchAnimate == false){
					if(frameCounter < 20){
						frameCounter++;
					}else{
						switchAnimate = true;
					}
				}else{
					if(frameCounter > 18){
						frameCounter--;
					}else{
						hi = false;
						switchAnimate = false;
						sayingHi = false;
					}
				}
			}
			if(bombEnemy){
				if(!pauseTime){
					if(bombSwitchAnimate == false){
						if(bombFrameCounter < 2){
							bombFrameCounter++;
						}else{
							bombSwitchAnimate = true;
						}
					}else{
						if(bombFrameCounter > 0){
							bombFrameCounter--;
						}else{
							bombSwitchAnimate = false;
						}
					}
				}
			}
		}
		lightAngle += 0.1;
		//lightpos3[0] = cos(lightAngle);
		//lightpos3[1] = 5;
		//lightpos3[2] = sin(lightAngle);

		//glDisable(GL_LIGHTING);
		//glDisable(GL_LIGHT0);
		//glBindTexture(GL_TEXTURE_2D, shadowMapTexture);
	//glEnable(GL_TEXTURE_2D);
//	glPopMatrix();
	//glTranslatef(0,-50,0);
	//glScalef(-2,-2,-2);
			//glTranslatef(0,-500,0);
			//glPushMatrix();
		//	glRotatef(90,0,0,1);
		//glCallList(table);
			//kingR.DrawGLScene();
			
			//glColor4f(1,1,1,1);
			//glColor3f(1,1,1);
			//glPopMatrix();
			//glLoadIdentity
	glFinish();
			int resetCounter = 0;
			currentAnimation = "NON";
			if(hi){
				currentAnimation = "HIY";
			}else{
				resetCounter++;
			}
			if(jump){
				currentAnimation = "JMP";
			}else{
				resetCounter++;
			}
			if(running){
				currentAnimation = "RUN";
			}else{
				resetCounter++;
			}
			
			if(throwing){
				currentAnimation = "THW";
			}else{
				resetCounter++;
			}
			
			if(sucking){
				currentAnimation = "SUC";
			}else{
				resetCounter++;
			}

				
			//}
			
			
			//}
		
	std::string coords = name;
			coords += ":";
			coords += std::to_string(px);
			coords += ":";
			coords += std::to_string(py);
			coords += ":";
			coords += std::to_string(pz);
			coords += ":";
			coords += std::to_string(angle);
			coords += ":";
			coords += currentAnimation;
			coords += ":";
			//coords += std::to_string(angle);
			coords += "/";
			char * coordsArray = (char*)coords.c_str();
			client->sendMessage(coordsArray);
			
			

		client->recieve();
			clientLine = client->line;
			
			deciferP();
			
		
		App.display();
		}
		finished = 0;
		completeFinished = 0;
		foundCrystal = false;
		part++;
		world = (int)(part /10)+1;
		if(part == 10){
			if(online){
				part++;
			}else{
				world = 0;
			}
		}
		if(!online){
			xLoad->writeXml(part);
		}
		px = 0;
		py = 5;
		pz = 0;

		std::string lMap = "Objects/world";
		lMap += std::to_string(world);
		lMap +="/table";
		lMap += std::to_string(part);
		lMap += ".obj";
		char * lArray = (char*)lMap.c_str();
		levelLoad.loadTable(lArray);
		
		
		std::string sMap = "Objects/world";
		sMap += std::to_string(world); 
		sMap += "/slope";
		sMap += std::to_string(part);
		sMap += ".obj";
		char * sArray = (char*)sMap.c_str();
		levelLoad.loadSlope(sArray);


		std::string fMap = "Objects/world";
		fMap += std::to_string(world);
		fMap += "/fSlope";
		fMap += std::to_string(part);
		fMap += ".obj";
		char * fArray = (char*) fMap.c_str();
		levelLoad.loadFSlope(fArray);


		std::string eMap = "Objects/world";
		eMap += std::to_string(world);
		eMap += "/exit";
		eMap += std::to_string(part);
		eMap += ".obj";
		char * eArray = (char*) eMap.c_str();
		levelLoad.loadExit(eArray);
		
		std::string maMap = "Objects/world";
		maMap += std::to_string(world);
		maMap += "/magnet";
		maMap += std::to_string(part);
		maMap += ".obj";
		char * maArray = (char*) maMap.c_str();
		levelLoad.loadMagnets(maArray);
		
		std::string spMap = "Objects/world";
		spMap += std::to_string(world);
		spMap += "/spikes";
		spMap += std::to_string(part);
		spMap += ".obj";
		char * spArray = (char*) spMap.c_str();
		levelLoad.loadSpikes(spArray);
		
		std::string finMap = "Objects/world";
		finMap += std::to_string(world);
		finMap +="/finish";
		finMap += std::to_string(part);
		finMap += ".obj";
		char * finArray = (char*) finMap.c_str();
		levelLoad.loadFinish(finArray);
		
		std::string trMap = "Objects/world";
		trMap += std::to_string(world);
		trMap += "/trap";
		trMap += std::to_string(part);
		trMap += ".obj";
		char * trArray = (char*) trMap.c_str();
		levelLoad.loadTrapDoor(trArray);
		
		std::string bMap = "Objects/world";
		bMap += std::to_string(world);
		bMap += "/bomb";
		bMap += std::to_string(part);
		bMap += ".obj";
		char * bArray = (char*) bMap.c_str();
		levelLoad.loadBomb(bArray);
		
		std::string biMap = "Objects/world";
		biMap += std::to_string(world);
		biMap += "/bin";
		biMap += std::to_string(part);
		biMap += ".obj";
		char * biArray = (char*) biMap.c_str();
		levelLoad.loadBinSpawn(biArray);
		
		std::string rMap = "objects/world";
		rMap += std::to_string(world);
		rMap += "/reflect";
		rMap += std::to_string(part);
		rMap += ".obj";
		char * rArray = (char*) rMap.c_str();
		levelLoad.loadPlayer(rArray);
		
		std::string tmMap = "Objects/world";
		tmMap += std::to_string(world);
		tmMap += "/tm";
		tmMap += std::to_string(part);
		tmMap += ".obj";
		char * tmArray = (char*) tmMap.c_str();
		levelLoad.loadSpider(tmArray);
		
		std::string rsMap = "Objects/world";
		rsMap += std::to_string(world);
		rsMap += "/fRSlope";
		rsMap += std::to_string(part);
		rsMap += ".obj";
		char * rsArray = (char*) rsMap.c_str();
		levelLoad.loadReflectSlope(rsArray);
		
		std::string sqMap = "Objects/world";
		sqMap += std::to_string(world);
		sqMap += "/squ";
		sqMap += std::to_string(part);
		sqMap += ".obj";
		char * sqArray = (char*) sqMap.c_str();
		levelLoad.loadSqu(sqArray);
		
		std::string moMap = "Objects/world";
		moMap += std::to_string(world);
		moMap += "/moving";
		moMap += std::to_string(part);
		moMap += ".obj";
		char* moArray = (char*) moMap.c_str();
		levelLoad.loadMoving(moArray);
		
		
		moMap = "Objects/world";
		moMap += std::to_string(world);
		moMap += "/movingU";
		moMap += std::to_string(part);
		moMap += ".obj";
		moArray = (char*) moMap.c_str();
		levelLoad.loadMovingU(moArray);
		
		std::string bhMap = "Objects/world";
		bhMap += std::to_string(world);
		bhMap += "/frogH";
		bhMap += std::to_string(part);
		bhMap += ".obj";
		char* bhArray = (char*) bhMap.c_str();
		levelLoad.loadBossHit(bhArray);
		
		std::string faMap = "Objects/world";
		faMap += std::to_string(world);
		faMap += "/factory";
		faMap += std::to_string(part);
		faMap += ".obj";
		char * faArray = (char*) faMap.c_str();
		levelLoad.loadFactory(faArray);
		
		moveSkew = 0;
		
		std::string prMap = "Objects/world";
		prMap += std::to_string(world);
		prMap += "/project";
		prMap += std::to_string(part);
		prMap += ".obj";
		char* prArray = (char*) prMap.c_str();
		levelLoad.loadProject(prArray);
		if(levelLoad.prFaces.size() % 6 == 0){
			projectCount = levelLoad.prFaces.size()/6;
			for(int i = 0; i < projectCount; i++){
				projectX[i] = levelLoad.prVert[levelLoad.prFaces[i*6 + 1]->faces[1]-1]->x;
				projectZ[i] = levelLoad.prVert[levelLoad.prFaces[i*6 + 1]->faces[1]-1]->z;
				projectY[i] = levelLoad.prVert[levelLoad.prFaces[i*6 + 1]->faces[1]-1]->y;
				projectAngle[i] = 0;
				fireProject[i] = false;
				projectCounter[i] =0;
			}
		}
		
		if(world ==1 ){
			material(marble, emerald_ambient, yellow_light, emerald_specular, emerald_shininess);
		}else if(world ==2){
			material(marble, emerald_ambient, green_light, emerald_specular, emerald_shininess);
		}else if(world ==3){
			material(marble, red_plastic_ambient, red_light, red_plastic_specular, red_plastic_shininess);
		}else if(world == 4){
			material(marble, emerald_ambient, mint_light, emerald_specular, emerald_shininess);
		}else if(world == 5){
			material(marble, emerald_ambient, orange_light, emerald_specular, emerald_shininess);
		}else if(world ==0){
			bossFinished = false;
			if(part == 10){
				bossLives = 5;
				bossKilled = false;
			}
			int worldN = (part /10) +1;
			if(worldN ==1 ){
				material(marble, emerald_ambient, yellow_light, emerald_specular, emerald_shininess);
			}else if(worldN ==2){
				material(marble, emerald_ambient, green_light, emerald_specular, emerald_shininess);
			}else if(worldN ==3){
				material(marble, red_plastic_ambient, red_light, red_plastic_specular, red_plastic_shininess);
			}else if(worldN ==4){
				material(marble, emerald_ambient, mint_light, emerald_specular, emerald_shininess);
			}
			if(online){
				part++;
			}
		}

		if(world ==2){
			char skyTop[] = "Images/hw_crater/craterlake_up.tga";
			skyT = obj.loadTexture(skyTop, 25);
			
			char skyBot[] = "Images/hw_crater/craterlake_dn.tga";
			skyB = obj.loadTexture(skyBot, 26);
			
			char skyFront[] = "Images/hw_crater/craterlake_ft.tga";
			skyF = obj.loadTexture(skyFront, 27);
			
			char skyBack[] = "Images/hw_crater/craterlake_bk.tga";
			skyBk = obj.loadTexture(skyBack, 28);
			
			char skyLeft[] = "Images/hw_crater/craterlake_lf.tga";
			skyL = obj.loadTexture(skyLeft, 29);
			
			char skyRight[] = "Images/hw_crater/craterlake_rt.tga";
			skyR = obj.loadTexture(skyRight, 30);
			
		}else if(world ==1){
			char skyTop[] = "Images/mp_5dim/5dim_up.tga";
			skyT = obj.loadTexture(skyTop, 25);
			
			char skyBot[] = "Images/mp_5dim/5dim_dn.tga";
			skyB = obj.loadTexture(skyBot, 26);
			
			char skyFront[] = "Images/mp_5dim/5dim_ft.tga";
			skyF = obj.loadTexture(skyFront, 27);
			
			char skyBack[] = "Images/mp_5dim/5dim_bk.tga";
			skyBk = obj.loadTexture(skyBack, 28);
			
			char skyLeft[] = "Images/mp_5dim/5dim_lf.tga";
			skyL = obj.loadTexture(skyLeft, 29);
			
			char skyRight[] = "Images/mp_5dim/5dim_rt.tga";
			skyR = obj.loadTexture(skyRight, 30);
			
		}else if(world == 3){
			char skyTop[] = "Images/sky/violentdays_up.tga";
			skyT = obj.loadTexture(skyTop, 25);
			
			char skyBot[] = "Images/sky/violentdays_dn.tga";
			skyB = obj.loadTexture(skyBot, 26);
			
			char skyFront[] = "Images/sky/violentdays_ft.tga";
			skyF = obj.loadTexture(skyFront, 27);
			
			char skyBack[] = "Images/sky/violentdays_bk.tga";
			skyBk = obj.loadTexture(skyBack, 28);
			
			char skyLeft[] = "Images/sky/violentdays_lf.tga";
			skyL = obj.loadTexture(skyLeft, 29);
			
			char skyRight[] = "Images/sky/violentdays_rt.tga";
			skyR = obj.loadTexture(skyRight, 30);
			
		}else if(world == 4){
			char skyTop[] = "Images/ame_emerald/emeraldfog_dn.tga";
			skyT = obj.loadTexture(skyTop, 25);
			
			char skyBot[] = "Images/ame_emerald/emeraldfog_up.tga";
			skyB = obj.loadTexture(skyBot, 26);
			
			char skyFront[] = "Images/ame_emerald/emeraldfog_ft.tga";
			skyF = obj.loadTexture(skyFront, 27);
			
			char skyBack[] = "Images/ame_emerald/emeraldfog_bk.tga";
			skyBk = obj.loadTexture(skyBack, 28);
			
			char skyLeft[] = "Images/ame_emerald/emeraldfog_lf.tga";
			skyL = obj.loadTexture(skyLeft, 29);
			
			char skyRight[] = "Images/ame_emerald/emeraldfog_rt.tga";
			skyR = obj.loadTexture(skyRight, 30);
			
		}else if(world ==5){
			char skyTop[] = "Images/hw_sandstorm/sandstorm_dn.tga";
			skyT = obj.loadTexture(skyTop, 25);
			
			char skyBot[] = "Images/hw_sandstorm/sandstorm_up.tga";
			skyB = obj.loadTexture(skyBot, 26);
			
			char skyFront[] = "Images/hw_sandstorm/sandstorm_ft.tga";
			skyF = obj.loadTexture(skyFront, 27);
			
			char skyBack[] = "Images/hw_sandstorm/sandstorm_bk.tga";
			skyBk = obj.loadTexture(skyBack, 28);
			
			char skyLeft[] = "Images/hw_sandstorm/sandstorm_lf.tga";
			skyL = obj.loadTexture(skyLeft, 29);
			
			char skyRight[] = "Images/hw_sandstorm/sandstorm_rt.tga";
			skyR = obj.loadTexture(skyRight, 30);
			
		}
		
		if(levelLoad.bFaces.size() > 0){
			bombEnemy = true;
		}else{
			bombEnemy = false;
		}
		for(int i = 0; i < 10; i++){
			binCollected[i] = true;
			binamation[i] = false;
			binScale[i] = 1;
		}
		if(levelLoad.biSFaces.size() %6 ==0){
			binCount = levelLoad.biSFaces.size()/6;
			for(int i = 0; i < binCount; i++){
				binX[i] =  levelLoad.biSVert[levelLoad.biSFaces[i*6 + 1]->faces[1]-1]->x;
				binZ[i] =  levelLoad.biSVert[levelLoad.biSFaces[i*6 + 1]->faces[1]-1]->z;
				binY[i] =  levelLoad.biSVert[levelLoad.biSFaces[i*6 + 1]->faces[1]-1]->y;
				binCollected[i] = false;
			}
		}
		if(levelLoad.bFaces.size() % 6 ==0){
			bombCount = levelLoad.bFaces.size()/6;
			for(int i = 0; i < bombCount; i++){
				bombX[i] = levelLoad.bVert[levelLoad.bFaces[i*6 + 1]->faces[1]-1]->x;
				bombZ[i] = levelLoad.bVert[levelLoad.bFaces[i*6 + 1]->faces[1]-1]->z;
				bombY[i] = levelLoad.bVert[levelLoad.bFaces[i*6 + 1]->faces[1]-1]->y;
				bombHeart[i] = 0;
				enKilled[i] = false;
			}
		}
		
		if(levelLoad.sqFaces.size() % 6 ==0){
			sqCount = levelLoad.sqFaces.size()/6;
			for(int i = 0; i < sqCount; i++){
				squX[i] = levelLoad.sqVert[levelLoad.sqFaces[i*6 + 1]->faces[1]-1]->x;
				squZ[i] = levelLoad.sqVert[levelLoad.sqFaces[i*6 + 1]->faces[1]-1]->z;
				squY[i] = levelLoad.sqVert[levelLoad.sqFaces[i*6 + 1]->faces[1]-1]->y;
				squKilled[i] = false;
			}
		}
		if(levelLoad.trFaces.size() % 6 ==0){
			trapCount = levelLoad.trFaces.size()/6;
			for(int i =0; i < trapCount; i++){
				trapX[i] = levelLoad.trVert[levelLoad.trFaces[i*6 + 1]->faces[1]-1]->x;
				trapZ[i] = levelLoad.trVert[levelLoad.trFaces[i*6 + 1]->faces[1]-1]->z;
				trapY[i] = levelLoad.trVert[levelLoad.trFaces[i*6 + 1]->faces[1]-1]->y;
				trapTripped[i] = false;
				trapRespawn[i] = 0;
				TrapWait[i] = 0;
			}
			
		}
		fMinionSize = 0;
		if(levelLoad.faFaces.size() % 6 ==0){
			factoryCounter = levelLoad.faFaces.size()/6;
			for(int i = 0; i < factoryCounter; i++){
				factoryX[i] = levelLoad.faVert[levelLoad.faFaces[i*6+1]->faces[1]-1]->x;
				factoryY[i] = levelLoad.faVert[levelLoad.faFaces[i*6+1]->faces[1]-1]->y;
				factoryZ[i] = levelLoad.faVert[levelLoad.faFaces[i*6+1]->faces[1]-1]->z;
				factoryDead[i] = false;
				//factoryType[i] = 0;
			}
		}
		if(levelLoad.tmFaces.size() % 6 ==0){
			tmCount = levelLoad.tmFaces.size()/6;
			for(int i = 0; i < tmCount; i++){
				tMonsterX[i] = levelLoad.tmVert[levelLoad.tmFaces[i*6+1]->faces[1]-1]->x;
				tMonsterY[i] = levelLoad.tmVert[levelLoad.tmFaces[i*6+1]->faces[1]-1]->y;
				tMonsterZ[i] = levelLoad.tmVert[levelLoad.tmFaces[i*6+1]->faces[1]-1]->z;
				tMonsterType[i] = rand() %2;
			}
		}
		
		for(int i = 0; i < 100; i++){
			
			rewindCollectable[i] = false;
			pauseCollectable[i] = false;
			forwardCollectable[i] = false;
			
			rewindSpawnX[i] = -1000;
			rewindSpawnZ[i] = -1000;
			rewindSpawnY[i] = -1000;
			
			pauseSpawnX[i] = -1000;
			pauseSpawnZ[i] = -1000;
			pauseSpawnY[i] = -1000;
			
			forwardSpawnX[i] = -1000;
			forwardSpawnZ[i] = -1000;
			forwardSpawnY[i] = -1000;
			
			
			forwardBounce[i] = true;
			pauseBounce[i] = true;
			rewindBounce[i] = true;
			
			shownPause[i] = false;
			shownRewind[i] = false;
			shownForward[i] = false;
			
		}
		
		
		if(levelLoad.bFaces.size() > 0){
			bombEnemy = true;
		}else{
			bombEnemy = false;
		}
	
		lightDefined = false;
		if(part < 10){
		//	material(table, brass_ambient, brass_diffuse, brass_specular, brass_shininess);
		}else if(part < 20){
		//	material(table, emerald_ambient, emerald_diffuse, emerald_specular, emerald_shininess);
		}
	}
	
	xLoad->writeXml(part);
	delete xLoad;
	delete client;
	
	return 0;
}