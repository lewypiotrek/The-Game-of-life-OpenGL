#include "Cell.h"
using namespace std;


Cell::Cell()
{
	copySize(sizeY,sizeX);

	mainArr = new bool *[sizeY];
	tempArr = new bool *[sizeY];

	//generownie tablic 2d
	for (int i = 0; i <= sizeY; i++)
	{
		mainArr[i] = new bool[sizeX];
	}

	for (int i = 0; i <= sizeY; i++)
	{
		tempArr[i] = new bool[sizeX];
	}

	//resetowanie tablic
	for (int i = 0; i <= sizeY; i++)
	{
		for (int j = 0; j <= sizeX; j++)
		{
			mainArr[i][j] = 0;
			tempArr[i][j] = 0;
		}
	}

	copyArrays(mainArr);

}

Cell::~Cell()
{
	for (int i = 0; i < sizeX; i++)
		delete[] mainArr[i];
	delete[] mainArr;

	for (int i = 0; i < sizeX; i++)
		delete[] tempArr[i];
	delete[] tempArr;
}

void Cell::copyArr()
{
	for (int i = 1; i <=sizeY-1; i++)
	{
		for (int j =1 ; j <= sizeX-1; j++)
			mainArr[i][j] = tempArr[i][j];
	}
}
