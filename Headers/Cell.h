#pragma once
#include <iostream>
#include "Settings.h"
class Cell
	:public Settings

{
public:
	/* wartoœæ size bêdzie zawsze wartoœci¹ zwiêkszon¹ do sprawdzania */
	int sizeY=2;	//domyœlnie pusta tarcza
	int sizeX=2;
	bool **mainArr;
	bool **tempArr;

	Cell();
	~Cell();
	void copyArr();
};

