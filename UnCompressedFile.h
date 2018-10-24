#ifndef NODEOFTREE
#define NODEOFTREE
#include"NodeOfTree.h"
#endif
#include<fstream>

using namespace std;

class UnCompressedFile
{
	private:
		NodeOfTree arry[256];
		long Fcount;
		long Ccount;
		ifstream in;
		NodeOfTree *tree;
	public:
		UnCompressedFile();
		void readCFile(char *filename);
		void writeOFile(char *filename);
		void destroy();
		void destroyTree(NodeOfTree *trees);
};	
