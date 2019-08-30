#include "Settings.h"


Settings::Settings()
{
	loadSettings("settings.txt");
}

Settings::~Settings()
{
	for (int i = 0; i < Bsize; i++)
		delete[] buffer[i];
	delete[] buffer;
}

void Settings::loadSettings(string fileName)
{

	file.open(fileName, ios::in);

	// sprawdzenie poprawnoœci wczytania
	if (!file.good()) std::cout << "ERROR: Blad wczytania pliku! ... \n";
	else
	{
		std::cout << "Wczytywanie ustawien gry ... \n ------------------------------ \n";
		file >> Bsize;

		// Generowanie tablicy 2D
		buffer = new char *[Bsize+1];
		for (int i = 0; i < Bsize+1; i++)
			buffer[i] = new char[Bsize+1];


		//	'zerowanie' talbicy
		for(int i = 0; i < Bsize+1; i++)
			for (int j = 0; j < Bsize+1; j++)
			{
				buffer[i][j] = 'x';
			}

		//	wczytywanie danych
		for (int i = 1; i <= Bsize; i++)
			for (int j = 1; j <= Bsize; j++)
			{
				file >> buffer[i][j];
			}

		checkSettings(fileName);
	}

	file.close();

}

void Settings::checkSettings(string fileName)
{

	file.open(fileName, ios::in);
	for (int i = 1; i <= Bsize; i++)
		for (int j = 1; j <= Bsize; j++)
		{
			if (buffer[i][j] == 'x')
			{
				std::cout << "\n ERROR: Blad w pliku settings, popraw ustawienia i sprobuj ponownie ... \n";
				break;
			}
		}
	file.close();
}

void Settings::copyArrays(bool **Arr)
{
	for (int i = 0; i <= Bsize; i++)
		for (int j = 0; j <= Bsize; j++)
		{
			if ((buffer[i][j] == '0') ||(buffer[i][j] == 'x'))
			{
				Arr[i][j] = false;
			}
			else if (buffer[i][j] == '1')
			{
				Arr[i][j] = true;
			}
		}
}

void Settings::copySize(int & sy, int & sx)
{
	sy = Bsize;
	sx = Bsize;
}