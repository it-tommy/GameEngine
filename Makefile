# Makefile

INCLUDES=-IC:/usr/SDL-1.2.15/include -IC:/usr/glew-2.1.0/include -IC:/usr/include
LIBS=-LC:/usr/SDL-1.2.15/lib -LC:/usr/glew-2.1.0/lib -LC:/usr/lib
LINKLIBS= -lmingw32 -lSDLmain -lSDL -lopengl32 -lgdi32 -lglu32 -lglew32


all:
	g++ -g DisplayManager.cpp Main.cpp -o Game ${INCLUDES} ${LIBS} ${LINKLIBS}






clean:
	rm -rf *.o *.exe