#include"WriteCompressedFile.h"
#include<fstream>
#include<string>
#include<bitset>
#include<iostream>

using namespace std;

void WriteCompressedFile::writeHFile(char *filename,NodeOfTree *node)
{
	string file;
	file = filename;
	file = "C" + file;
	fstream compressed_file(file.c_str(),ios::out|ios::binary);
	if(!compressed_file.is_open())
	{
		cout << "can`t creat compressed file" << endl;
		exit(1);
	}
	int i;
	long j;
	int k = 0;
	int size = 0;
	int pos = 0;
	long Ccount = 0;
	long Fcount = 0;
	unsigned char wbuffer[32];
	string s;
	bitset<8> byte;
	for(i = 0;i < 256;i++)
	{
		j = node[i].getWeight();
		if(j != 0)
		{
			Ccount++;
			Fcount = Fcount + j;
		}

	}
	compressed_file << Ccount << endl;
	compressed_file << Fcount << endl;
	for(i = 0;i < 256;i++)
	{
		j = node[i].getWeight();
		if(j != 0)
		{
			s = node[i].getCode();
			k = s.length();
			compressed_file << k << endl;
			compressed_file << node[i].getOnebyte() << endl;
			if(k % 8 != 0)
			{
				k = 8 - k % 8;
				for(k;k > 0;k--)
				{
					s = s + "0";
				}
			}
			size = s.length();
			for(pos = 0,k = 0;(pos + 8) <= size;pos,k)
			{
				byte = bitset<8>(s,pos,8);
				j = (int)byte.to_ulong();
				wbuffer[k] = (unsigned char)j;
				pos = pos + 8;
				k++;
			}
			compressed_file.write((char *)wbuffer,k);
			compressed_file << endl;
		}
	}
	compressed_file.close();
}

void WriteCompressedFile::writeCFile(char *filename,NodeOfTree *node)
{
	string file;
	file = filename;
	file = "C" + file;
	ifstream oringinated_file(filename,ios::in|ios::binary);
	ofstream compressed_file(file.c_str(),ios::out|ios::binary|ios::app);
	if(!oringinated_file.is_open() || !compressed_file.is_open())
	{
		cout << "file can`t be opened or created!" << endl;
		exit(1);
	}
	unsigned char buffer[128];
	string s;
	int char_count = 0;
	unsigned char wbuffer[1024];
	int i = 0;
	int j = 0;
	int k = 0;
	unsigned int size = 0;
	unsigned int pos = 0;
	bitset<8> byte;
	while(!oringinated_file.eof() || s.length() != 0)
	{
		oringinated_file.read((char *)buffer,128);
		char_count = oringinated_file.gcount();
		for(i = 0;i < char_count;i++)
		{
			s = s + node[buffer[i]].getCode();
		}
		size = s.length();
		for(pos = 0,k = 0;(pos + 8) <= size && k < 1024;pos,k)
		{
			byte = bitset<8>(s,pos,8);
			j = (int)byte.to_ulong();
			wbuffer[k] = (char)j;
			pos = pos + 8;
			k++;
		}
		s = s.assign(s,pos,string::npos);
		compressed_file.write((char *)wbuffer,k);
		if(oringinated_file.eof())
		{
			for(i = s.length();i < 8;i++)
			{
				s = s + "0";
			}
			byte = bitset<8>(s);
			j = (int)byte.to_ulong();
			wbuffer[0] = (char)j;
			compressed_file.write((char *)wbuffer,1);
			s = "";
		}
	}
	oringinated_file.close();
	compressed_file.close();
}
