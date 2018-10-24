#ifndef NODEOFTREE
#define NODEOFTREE
#include"NodeOfTree.h"
#endif

class WriteCompressedFile
{
	public:
		void writeHFile(char *filename,NodeOfTree *node);
		void writeCFile(char *filename,NodeOfTree *node);
};
