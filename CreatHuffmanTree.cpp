#include"CreatHuffmanTree.h"

bool CreatHuffmanTree::myCompare(NodeOfTree *a,NodeOfTree *b)
{
	return a->getWeight() < b->getWeight();
}

void CreatHuffmanTree::setNode(NodeOfTree *arry)
{
	int i = 0;
	for(i = 0;i < 256;i++)
	{
		if(arry[i].getWeight() != 0)
		{
			this->node.push_back(&arry[i]);
		}
	}
			
}

void CreatHuffmanTree::creatTree()
{
	NodeOfTree *newnode;
	sort(this->node.begin(),this->node.end(),myCompare);
	while(this->node.size() != 1)
	{
		newnode = new NodeOfTree;
		newnode->setNWeight(this->node[0]->getWeight() + this->node[1]->getWeight());
		newnode->setLchild(node[0]);
		newnode->setRchild(node[1]);
		this->node.erase(node.begin());
		node[0] = newnode;
		sort(this->node.begin(),this->node.end(),myCompare);
	}
}

void CreatHuffmanTree::readCoding(NodeOfTree *tree,char *code,int deep)
{
	if(tree->getLchild() == NULL && tree->getRchild() == NULL)
	{
		memcpy(tree->getCode(),code,deep);
		return;
	}
	code[deep] = '0';
	if(tree->getLchild() != NULL)
	{
		readCoding(tree->getLchild(),code,deep + 1);
	}
	code[deep] = '1';
	if(tree->getRchild() != NULL)
	{
		readCoding(tree->getRchild(),code,deep + 1);
	}
}

void CreatHuffmanTree::readCode()
{
	char code[256];
	memset(code,'\0',256);
	int deep = 0;
	readCoding(this->node[0],code,deep);
}

void CreatHuffmanTree::destroyTree(NodeOfTree *tree)
{
	if(tree->getLchild() != NULL)
		destroyTree(tree->getLchild());
	if(tree->getRchild() != NULL)
		destroyTree(tree->getRchild());
	if(tree->getLchild() != NULL && tree->getRchild() != NULL)
		delete tree;
}

void CreatHuffmanTree::destroy()
{
	destroyTree(this->node[0]);
}
