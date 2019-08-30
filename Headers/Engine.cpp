#include "Engine.h"


Engine::Engine() :Cell()
{
}

Engine::~Engine()
{
}

void Engine::stepChecker()
{
	for (int i = 1; i <= sizeY-1; i++)
	{
		for (int j = 1; j <= sizeX-1; j++)
		{

			if (neighborCheck(i, j) == 3)
			{
				tempArr[i][j] = 1;
			}
			else if ((neighborCheck(i, j) > 3) || (neighborCheck(i, j) < 2))
			{
				tempArr[i][j] = 0;
			}
			else if ((neighborCheck(i, j) == 2))
			{
				tempArr[i][j] = mainArr[i][j];
			}
		}
	}

	// kopiowanie z tablicy pomocniczej do g��wnej
	copyArr();
} 

short Engine::neighborCheck(short y, short x)
{
	short counter = 0;

	// SPRAWDZANIE �RODKA
	if (mainArr[y][x - 1] == 1)
		counter++;

	if (mainArr[y][x + 1] == 1)
		counter++;
	
	// SPRAWDZANIE G�Ry oraz DO�U
	for (int i = 0; i < 3; i++)
	{
		// G�RA
		if (mainArr[y - 1][x - 1 + i] == 1)
			counter++;

		// D�
		if (mainArr[y + 1][x - 1 + i] == 1)
			counter++;
		
	}
	
	return counter;
}
