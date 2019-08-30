#include "GraphicEngine.h"
GraphicEngine::GraphicEngine()
{
	/* Initialize the library */
	if (!glfwInit()) {
		std::cout << "Blad inicjalizacji petli gry\n";
	}

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(800, 600, "Piotr Lewandowski - Gra w Zycie", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
	}
}

GraphicEngine::~GraphicEngine()
{
	glfwTerminate();		// usuwanie wszystkich pozosta³oœci po oknie
}


/* Rysowanie siatki */
void GraphicEngine::layoutDraw()
{
	

	double x1 = -0.9, y1 = -0.9, x2 = -0.9, y2 = 0.9;		// linie pionowe
	double xx1 = -0.9, yy1 = -0.9, xx2 = 0.9, yy2 = -0.9;	// linie pionowe

	double m = x/sizeX;

	glBegin(GL_LINES);

	// RYSOWANIE RAMKI
	glColor3d(0.25, 0.99, 2.18);
	glVertex2d(x1, y1);
	glVertex2d(x2, y2);
	glVertex2d(xx1, yy1);
	glVertex2d(xx2, yy2);

	// RYSOWANIE SIATKI
	for (int i = 0; i < sizeX; i++)
	{
			
			x1 = x1 + m;
			x2 = x2 + m;
			yy1 = yy1 + m;
			yy2 = yy2 + m;

			glVertex2d(x1,y1);
			glVertex2d(x2,y2);

			glVertex2d(xx1,yy1);
			glVertex2d(xx2, yy2);
			
			
	}

	glEnd();
}

/* Rysowanie pojedynczej komórki */
void GraphicEngine::cellDraw(short i, short j)
{

	// Zmienne przesuniecie, zmienne pomocnicze do poruszania
	double m = (x / sizeX);

	/* Ustawienie komórki w lewym górnym rogu */
	double t[8] = { 
		-0.898,0.896,
		-0.898,0.896 - m +0.009,
		-0.898 + m-0.006,0.896 - m + 0.009,
		-0.898 + m-0.006,0.895 };

	double X = 0.0 + (i*m), Y = 0.0 - (j*m);

	/* Rysowanie komórki w odpowiedniej kratce */
	glBegin(GL_POLYGON);

	glColor3d(0.07, 0.65, 0.09);
	glVertex2d(t[0] + X, t[1] + Y);
	glVertex2d(t[2] + X, t[3] + Y);
	glVertex2d(t[4] + X, t[5] + Y);
	glVertex2d(t[6] + X, t[7] + Y);

	glEnd();
}

/* Pêtla gry */
void GraphicEngine::renderLoop()
{
	double previousTime = glfwGetTime();
	int frameCount = 0;

	glfwWindowHint(GLFW_DOUBLEBUFFER, GL_FALSE);

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		
		/***************************** Render here *****************************/
		glClear(GL_COLOR_BUFFER_BIT);
	
		view();
		stepChecker();
		fps(0.65);
		
		/************************************************************************/

		/* Swap front and back buffers */
		glfwSwapBuffers(window);
		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	
}

/* Rysowanie ¿ywych komórek */
void GraphicEngine::view()
{
	layoutDraw();

	for (short i = 1; i <= sizeY; i++)
	{
		for (short j = 1; j <= sizeX; j++)
		{
			if (mainArr[i][j] == 1)
			{
				cellDraw(j - 1, i - 1);
			}
		}
	}
}

/* Spowalnianie pêtli */
void GraphicEngine::fps(double sec)
{
	clock_t end;
	end = clock() + sec * CLOCKS_PER_SEC;
	while (clock() < end) {}
}

