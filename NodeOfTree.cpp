#include"NodeOfTree.h"

NodeOfTree::NodeOfTree ()
{
	this->onebyte = '\0';
	memset(this->code,'\0',256);
	this->weight = 0;
	this->lchild = NULL;
	this->rchild = NULL;
}

char *NodeOfTree::getCode()
{
	return this->code;
}

unsigned char NodeOfTree::getOnebyte()
{
	return this->onebyte;
}

NodeOfTree *NodeOfTree::getLchild()
{
	return this->lchild;
}

NodeOfTree *NodeOfTree::getRchild()
{
	return this->rchild;
}

long NodeOfTree::getWeight()
{
	return this->weight;
}

void NodeOfTree::setWeight()
{
	this->weight++;
}

void NodeOfTree::setNWeight(long n)
{
	this->weight = n;
}

void NodeOfTree::setOnebyte(unsigned char byte)
{
	this->onebyte = byte;
}

void NodeOfTree::setLchild(NodeOfTree *childl)
{
	this->lchild = childl;
}

void NodeOfTree::setRchild(NodeOfTree *childr)
{
	this->rchild = childr;
}
