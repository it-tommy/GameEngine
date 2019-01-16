#include "Globals.h"

float angle = 0;

DisplayManager dm;

unsigned int loadTexture(const char *filename){
	SDL_Surface *img = SDL_LoadBMP(filename);
	unsigned int id;
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->w, img->h, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, img->pixels);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	SDL_FreeSurface(img);
	return id;

}

struct coordinate{
	float x, y, z;
	coordinate(float a, float b, float c) : x(a), y(b), z(c) {};
};

struct face{
	int facenum;
	bool four;
	int faces[4];
	face(int facen, int f1, int f2, int f3) : facenum(facen){
		faces[0] = f1;
		faces[1] = f2;
		faces[2] = f3;
		four = false;
	}
	face(int facen, int f1, int f2, int f3, int f4) : facenum(facen){
		faces[0] = f1;
		faces[1] = f2;
		faces[2] = f3;
		faces[2] = f4;
		four = true;
	}
};

int loadObj(const char *filename){

	std::vector<std::string*> coord;
	std::vector<coordinate*> vertex;
	std::vector<face*> faces;
	std::vector<coordinate*> normals;

}

unsigned int tex;

int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface* screen;
	screen = SDL_SetVideoMode(WIDTH, HEIGHT, BITS_PER_PIXEL, SDL_SWSURFACE | SDL_OPENGL);
	SDL_WM_SetCaption(WINDOW_TITLE, NULL);

	tex = loadTexture("assets/images/andrew.bmp");
	bool isRunning = true;
	const int FPS = 30;
	Uint32 start;
	dm.InitWindow();
	while(isRunning)
	{
		start = SDL_GetTicks();
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
			case SDL_QUIT :
				isRunning = false;
				break;
			}
		}

		//SDL_Flip(screen);
		angle += 0.5;
		if(angle >= 360)
			angle -= 360;
		dm.DrawQuadTex(angle, tex);
		SDL_GL_SwapBuffers();
		if(1000/FPS > SDL_GetTicks() - start)
			SDL_Delay(1000/FPS -(SDL_GetTicks() - start));
	}



	SDL_Quit();



	return 0;
}
