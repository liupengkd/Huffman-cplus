#ifndef NODEOFTREE
#define NODEOFTREE
#include"NodeOfTree.h"
#endif

class ReadOringinatedFile
{
	private:
		NodeOfTree arry[256];
	public:
//		ReadOringinatedFile();
		void readFile(char *filename);
		NodeOfTree *getArry();
};

