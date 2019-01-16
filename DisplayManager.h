/*
 * DisplayManager.h
 *
 *  Created on: Jan 10, 2019
 *      Author: Tommy
 */

#include "Globals.h"
#ifndef DISPLAYMANAGER_H_
#define DISPLAYMANAGER_H_

class DisplayManager {
public:
	DisplayManager();
	virtual ~DisplayManager();
	static void InitWindow();
	static void Draw(float rotAngle);
	static void DrawTriangle();
	static void DrawCube();
	static void DrawPlane(unsigned int tex);
	static void DrawQuadTex(float rotAngle, unsigned int tex);
	
};


#endif /* DISPLAYMANAGER_H_ */
