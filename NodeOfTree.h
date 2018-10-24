#include<cstdlib>
#include<cstring>

using namespace std;

#ifndef NULL
#define NULL 0
#endif

class NodeOfTree
{
	private:
		unsigned char onebyte;
		char code[256];
		long weight;
		NodeOfTree *lchild;
		NodeOfTree *rchild;
	public:
		NodeOfTree ();
		char *getCode();
		unsigned char getOnebyte();
		NodeOfTree *getLchild();
		NodeOfTree *getRchild();
		long getWeight();
		void setWeight();
		void setNWeight(long n);
		void setOnebyte(unsigned char byte);
		void setLchild(NodeOfTree *childl);
		void setRchild(NodeOfTree *childr);
};
