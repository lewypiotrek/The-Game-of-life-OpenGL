#pragma once
#include"Cell.h"
#include <iostream>

class Engine
	:public Cell
{
public:
	enum { ver = 200 };

	Engine();	// bezparametrowy konstruktor wywyo³a bezparametrowe konstruktory klas dziedziczonych
	~Engine();	// pusty destruktor, wywo³a konstruktory klas dziedziczonych

	/* Sprawdzanie ca³ego jednego kroku */
	void stepChecker();	

	/* Sprawdzanie s¹siadów pojedynczej komórki */
	short neighborCheck(short y, short x);

	/* Wirtualna funkcja do przys³oniêcia inn¹ metod¹ */
	virtual void renderLoop() { std::cout << "ERROR: Blad wirtualizacji metody"; };

};

