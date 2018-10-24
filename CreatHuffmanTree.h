#include"ReadOringinatedFile.h"
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

class CreatHuffmanTree
{
	private:
		vector<NodeOfTree *> node;
	public:
		static bool myCompare(NodeOfTree *a,NodeOfTree *b);
		void setNode(NodeOfTree *arry);
		void creatTree();
		void readCode();
		void readCoding(NodeOfTree *tree,char *code,int deep);
		void destroy();
		void destroyTree(NodeOfTree *tree);
};
