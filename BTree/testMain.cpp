#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <vector>
#include"BTree.h"

#define MAX 10000000
using namespace std;


int main(int argc, char* argv[]) {
	int i = 0;
	int key;
	int operation;
	unsigned long long insertNum = 0;
	unsigned long long removeNum = 0;
	unsigned long long searchNum = 0;
	fstream keyFile;
	fstream operationFile;
	fstream inorderKeysFile;
	keyFile.open(argv[1], ios::in);
	if (!keyFile) {
		cout << "[error] keyFile  could not be opened" << endl;
		system("pause");
	}

	operationFile.open(argv[2], ios::in);
	if (!operationFile) {
		cout << "[error] operationFile  could not be opened" << endl;
		system("pause");
	}

	BTree* tree = new BTree(atoi(argv[0]));

	while (keyFile >> key && i < MAX) {
		if (i % 1000 == 0) {
			cerr << "Now reaching I/O request " << i << endl;
		}
		operationFile >> operation;
		if (operation == 1) {
			tree->Insert(key);
			insertNum++;
		}
		else if (operation == 2) {
			tree->Delete(key);
			removeNum++;
		}
		else {
			int find = tree->Search(key);
			if (find != key) {
				cout << "[error] search";
				system("pause");
			}
			searchNum++;
		}
		i++;
	}
	cout << "#insert " << insertNum << endl;
	cout << "#remove " << removeNum << endl;
	cout << "#search " << searchNum << endl;
	inorderKeysFile.open("res1.txt", ios::out);
	if (!inorderKeysFile) {
		cout << "[error] inorderKeysFile could not be opened" << endl;
		system("pause");
	}
	tree->Inorder(inorderKeysFile);
	system("pause");
	return 0;
}