#include"CreatHuffmanTree.h"
#include"WriteCompressedFile.h"
#include"UnCompressedFile.h"
#include<iostream>

using namespace std;

void compressedFile(char *filename)
{
	ReadOringinatedFile read_o_file;
	read_o_file.readFile(filename);
	NodeOfTree *node = read_o_file.getArry();
	CreatHuffmanTree huffman;
	huffman.setNode(node);
	huffman.creatTree();
	huffman.readCode();
	huffman.destroy();
	WriteCompressedFile write_c_file;
	write_c_file.writeHFile(filename,node);
	write_c_file.writeCFile(filename,node);
}

void uncompressedFile(char *filename)
{
	UnCompressedFile uncompressed_file;
	uncompressed_file.readCFile(filename);
	uncompressed_file.writeOFile(filename);
	uncompressed_file.destroy();
}

int main(int argc,char *argv[])
{
	if(argc != 3)
	{
		cout << "参数个数出错" << endl;
		return 0;
	}
	else
	{
		if(argv[1][0] == '-' && argv[1][1] == 'c')
			compressedFile(argv[2]);
		else if(argv[1][0] == '-' && argv[1][1] == 'u')
			uncompressedFile(argv[2]);
		else
			cout << "错误参数" << endl;
	}
	return 0;
}

