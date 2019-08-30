#pragma once
#include"Cell.h"
#include <iostream>

class Engine
	:public Cell
{
public:
	enum { ver = 200 };

	Engine();	// bezparametrowy konstruktor wywyo�a bezparametrowe konstruktory klas dziedziczonych
	~Engine();	// pusty destruktor, wywo�a konstruktory klas dziedziczonych

	/* Sprawdzanie ca�ego jednego kroku */
	void stepChecker();	

	/* Sprawdzanie s�siad�w pojedynczej kom�rki */
	short neighborCheck(short y, short x);

	/* Wirtualna funkcja do przys�oni�cia inn� metod� */
	virtual void renderLoop() { std::cout << "ERROR: Blad wirtualizacji metody"; };

};

