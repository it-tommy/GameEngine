/*
 * DisplayManager.cpp
 *
 *  Created on: Jan 10, 2019
 *      Author: Tommy
 */

#include "DisplayManager.h"


DisplayManager::DisplayManager() {
	// TODO Auto-generated constructor stub

}

DisplayManager::~DisplayManager() {
	std::cout << "DisplayManager Destroyed...." << std::endl;
}

void DisplayManager::InitWindow() {

	glClearColor(0.0, 0.0, 0.7, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, WIDTH / HEIGHT, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);

	//glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//glEnable(GL_COLOR_MATERIAL);
	float dif[] = {1.0, 1.0, 1.0, 1.0};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);
	float amb[] = {0.2, 0.2, 0.2, 1.0};
	glLightfv(GL_LIGHT0, GL_AMBIENT, amb);

}

void DisplayManager::Draw(float rotAngle){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	float pos[] = {-2.0, 2.0, 3.0, 1.0};
	glLightfv(GL_LIGHT0, GL_POSITION, pos);

	glTranslatef(0.0, 0.0, -5.0);
	glRotatef(rotAngle, 1.0, 1.0, 1.0);
	//DrawTriangle(rotAngle);
	DrawCube();
}

void DisplayManager::DrawQuadTex(float rotAngle, unsigned int tex){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	float pos[] = {-2.0, 2.0, 3.0, 1.0};
	glLightfv(GL_LIGHT0, GL_POSITION, pos);

	glTranslatef(0.0, 0.0, -5.0);
	glRotatef(rotAngle, 1.0, 1.0, 1.0);
	DrawPlane(tex);
}

void DisplayManager::DrawPlane(unsigned int tex){
	glBindTexture(GL_TEXTURE_2D, tex);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0,1.0);
		glVertex3f(-2.0, 2.0, 0.0);
		glTexCoord2f(0.0,0.0);
		glVertex3f(-2.0, -2.0, 0.0);
		glTexCoord2f(1.0,0.0);
		glVertex3f(2.0, -2.0, 0.0);
		glTexCoord2f(1.0,1.0);
		glVertex3f(2.0, 2.0, 0.0);
	glEnd();
}

void DisplayManager::DrawTriangle() {	
	glBegin(GL_TRIANGLES);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.0, 2.0, 0.0);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(-2.0, -2.0, 0.0);
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(2.0, -2.0, 0.0);
	glEnd();
}

void DisplayManager::DrawCube(){
			float size = 1.0;
			float difamb[] = {1.0, 0.35, 0.35,1.0};
	        glBegin(GL_QUADS);
                // front face
				glNormal3f(0.0, 0.0, 1.0);
				glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, difamb);
				//glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 128.0);
                //glColor3f(1.0,0.0,0.0);
                glVertex3f(size/2,size/2,size/2);
                glVertex3f(-size/2,size/2,size/2);
                glVertex3f(-size/2,-size/2,size/2);
                glVertex3f(size/2,-size/2,size/2);
                // left face
				glNormal3f(-1.0, 0.0, 0.0);
                //glColor3f(0.0,1.0,0.0);
                glVertex3f(-size/2,size/2,size/2);
                glVertex3f(-size/2,-size/2,size/2);
                glVertex3f(-size/2,-size/2,-size/2);
                glVertex3f(-size/2,size/2,-size/2);
                // back face
				glNormal3f(0.0, 0.0, -1.0);
                //glColor3f(0.0,0.0,1.0);
                glVertex3f(size/2,size/2,-size/2);
                glVertex3f(-size/2,size/2,-size/2);
                glVertex3f(-size/2,-size/2,-size/2);
                glVertex3f(size/2,-size/2,-size/2);
                // right face
				glNormal3f(1.0, 0.0, 0.0);
                //glColor3f(1.0,1.0,0.0);
                glVertex3f(size/2,size/2,size/2);
                glVertex3f(size/2,-size/2,size/2);
                glVertex3f(size/2,-size/2,-size/2);
                glVertex3f(size/2,size/2,-size/2);
                // top face
				glNormal3f(0.0, 1.0, 0.0);
                //glColor3f(1.0,0.0,1.0);
                glVertex3f(size/2,size/2,size/2);
                glVertex3f(-size/2,size/2,size/2);
                glVertex3f(-size/2,size/2,-size/2);
                glVertex3f(size/2,size/2,-size/2);
                // bottom face
				glNormal3f(0.0, -1.0, 0.0);
                //glColor3f(0.0,1.0,1.0);
                glVertex3f(size/2,-size/2,size/2);
                glVertex3f(-size/2,-size/2,size/2);
                glVertex3f(-size/2,-size/2,-size/2);
                glVertex3f(size/2,-size/2,-size/2);
        glEnd();
}
