#pragma once
#include <iostream>
#include "Settings.h"
class Cell
	:public Settings

{
public:
	/* warto�� size b�dzie zawsze warto�ci� zwi�kszon� do sprawdzania */
	int sizeY=2;	//domy�lnie pusta tarcza
	int sizeX=2;
	bool **mainArr;
	bool **tempArr;

	Cell();
	~Cell();
	void copyArr();
};

