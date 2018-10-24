main:main.o ReadOringinatedFile.o NodeOfTree.o CreatHuffmanTree.o WriteCompressedFile.o UnCompressedFile.o
	g++ -g -o main main.o ReadOringinatedFile.o NodeOfTree.o CreatHuffmanTree.o WriteCompressedFile.o UnCompressedFile.o
NodeOfTree.o:NodeOfTree.cpp NodeOfTree.h
	g++ -g -c NodeOfTree.cpp
ReadOringinatedFile.o:ReadOringinatedFile.cpp ReadOringinatedFile.h NodeOfTree.h
	g++ -g -c ReadOringinatedFile.cpp
CreatHuffmanTree.o:CreatHuffmanTree.cpp CreatHuffmanTree.h ReadOringinatedFile.h
	g++ -g -c CreatHuffmanTree.cpp
WriteCompressedFile.o:WriteCompressedFile.cpp WriteCompressedFile.h NodeOfTree.h
	g++ -g -c WriteCompressedFile.cpp
UnCompressedFile.o:UnCompressedFile.cpp UnCompressedFile.h NodeOfTree.h
	g++ -g -c UnCompressedFile.cpp
main.o:main.cpp CreatHuffmanTree.h
	g++ -g -c main.cpp
clean:
	@rm -r main main.o ReadOringinatedFile.o NodeOfTree.o CreatHuffmanTree.o WriteCompressedFile.o UnCompressedFile.o
