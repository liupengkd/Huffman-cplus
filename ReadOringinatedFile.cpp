#include<fstream>
#include"ReadOringinatedFile.h"
#include<iostream>

using namespace std;

void ReadOringinatedFile::readFile(char *filename)
{
	unsigned char buffer[1024];
	int i = 0;
	int j = 0;
	int charCount = 0;
	ifstream oringinatedFile(filename,ios::in|ios::binary);
	if(!oringinatedFile.is_open())
	{
		cout << "error opening file" << endl;
		exit(1);
	}
	while(!oringinatedFile.eof())
	{
		oringinatedFile.read((char *)buffer,1024);
		charCount = oringinatedFile.gcount();
		for(i = 0;i < charCount;i++)
		{
			arry[(int)buffer[i]].setOnebyte(buffer[i]);
			arry[(int)buffer[i]].setWeight();
		}
	}
	oringinatedFile.close();
}

NodeOfTree *ReadOringinatedFile::getArry()
{
	return this->arry;
}
