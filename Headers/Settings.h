#include <iostream>
#include <string>
#include<fstream>

using namespace std;

class Settings
{
protected:
	fstream file;
	char **buffer = nullptr;
	int Bsize = 0;

public:

	Settings();
	~Settings();

	void loadSettings(string fileName);
	void checkSettings(string fileName);
	void copyArrays(bool **Arr);
	void copySize(int & sy, int & sx);
};