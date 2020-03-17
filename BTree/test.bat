@echo off
cd %~dp0 

g++ -std=c++11 -c BTree.cpp
g++ -std=c++11 -c BTree.h
g++ -std=c++11 -c BTreeNode.cpp
g++ -std=c++11 -c BTreeNode.h
g++ -std=c++11 -c testMain.cpp
g++ -o test.exe testMain.o BTree.o BTreeNode.o
test.exe 3 key.txt operationFile.txt