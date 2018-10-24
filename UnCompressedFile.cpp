#include"UnCompressedFile.h"
#include<fstream>
#include<bitset>
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

UnCompressedFile::UnCompressedFile()
{
	this->Fcount = 0;
	this->tree = new NodeOfTree();
}

void UnCompressedFile::readCFile(char *filename)
{
	this->in.open(filename,ios::in|ios::binary);
	if(!in.is_open())
	{
		cout << "can`t open compressed file" << endl;
		exit(1);
	}
	unsigned char c;
	char Null;
	this->in >> this->Ccount;
	NodeOfTree *p;
	this->in >> this->Fcount;
	int i = 0;
	int j = 0;
	int i_size;
	unsigned long n = 0;
	int size = 0;
	int char_count = 0;
	bitset<8> byte;
	string s;
	unsigned char *rbuffer[32];
	for(i = 0;i < this->Ccount;i++)
	{
		this->in >> size;
		this->in.get();
		c = this->in.get();
		arry[i].setOnebyte(c);
		this->in.get();
		if(size % 8 == 0)
		{
			char_count = size / 8;
			this->in.read((char *)rbuffer,size / 8);
		}
		else
		{
			char_count = size / 8 + 1;
			this->in.read((char *)rbuffer,size / 8 + 1);
		}
		for(j = 0;j < char_count;j++)
		{
			n = (unsigned long)rbuffer[j];
			byte = bitset<8>(n);
			s = s + byte.to_string();
		}
		memcpy(arry[i].getCode(),s.c_str(),size);
		p = this->tree;
		for(i_size = 0; i_size < size;i_size++)
		{
			if(s[i_size] == '0')
			{
				if(p->getLchild() == NULL)
					p->setLchild(new NodeOfTree());
				p = p->getLchild();
			}
			else
			{
				if(p->getRchild() == NULL)
					p->setRchild(new NodeOfTree());
				p = p->getRchild();
			}
		}
		p->setOnebyte(c);
		s = "";
		this->in.get();
	}
}

void UnCompressedFile::writeOFile(char *filename)
{
	unsigned char buffer[128];
	unsigned char wbuffer[1024];
	string s;
	NodeOfTree *p;
	p = this->tree;
	string file;
	int char_count;
	int i;
	int j;
	int size;
	long fcount = 0;
	unsigned long n;
	bitset<8> byte;
	file = ++filename;
	ofstream out(file.c_str(),ios::out|ios::binary);
	if(!out.is_open())
	{
		cout << "file can`t be opened or created!" << endl;
		exit(1);
	}
	while(!this->in.eof())
	{
		in.read((char *)buffer,128);
		char_count = in.gcount();
		for(i = 0;i < char_count;i++)
		{
			n = (unsigned long)buffer[i];
			byte = bitset<8>(n);
			s = s + byte.to_string();
		}
		size = s.length();
		for(i = 0,j = 0;i < size && j < 1024 && fcount < this->Fcount;i++)
		{
			if(s[i] == '0')
				if(p->getLchild()->getLchild() != NULL)
				{
					p = p->getLchild();
				}
				else
				{
					wbuffer[j] = p->getLchild()->getOnebyte();
					fcount++;
					j++;
					p = this->tree;
				}
			else
			{
				if(p->getRchild()->getRchild() != NULL)
				{
					p = p->getRchild();
				}
				else
				{
					wbuffer[j] = p->getRchild()->getOnebyte();
					fcount++;
					j++;
					p = this->tree;
				}
			}
		}
		out.write((char *)wbuffer,j);
		if(i == size)
			s = "";
		else
			s = s.assign(s,i,string::npos);
	}
	this->in.close();
	out.close();
}
		
void UnCompressedFile::destroyTree(NodeOfTree *trees)
{
	if(trees->getLchild() != NULL)
		destroyTree(trees->getLchild());
	if(trees->getRchild() != NULL)
		destroyTree(trees->getRchild());
	delete trees;
}

void UnCompressedFile::destroy()
{
	destroyTree(this->tree);
}

