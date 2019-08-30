//#include<GLFW\glfw3.h>
#include "GLFW/glfw3.h"
#include<string>
#include "Engine.h"
#include<time.h>



class GraphicEngine :public Engine
{
protected:
	enum verGraph {verG = 200};
	GLFWwindow* window = nullptr;
	const double x = 1.8;	//zmienna szerokosci i wysokosci planszy

public:
	GraphicEngine();
	~GraphicEngine();

	void layoutDraw();
	void cellDraw(short i, short j);
	virtual void renderLoop();
	void view();
	void fps(double sec);


};

