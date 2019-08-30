#include<iostream>
#include "Engine\Cell.h"
#include "Engine\Engine.h"
#include "Engine\GraphicEngine.h"

/*-------------------------------------
Gra w Życie
Grafika oparta na OpenGL

© copyright by Piotr Lewandowski
------------------------------------*/


using namespace std;

int main() {
	
	GraphicEngine * newGame = new GraphicEngine;
	newGame->renderLoop();
}