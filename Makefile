main: cube.cpp
	g++ -std=c++11 cube.cpp -framework GLUT -framework OpenGL -o cube -Wno-deprecated
