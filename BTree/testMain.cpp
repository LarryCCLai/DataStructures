#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <vector>
#include"BTree.h"

#define MAX 10000000
using namespace std;

int main() {

	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	minstd_rand0 generator(seed);
	int i = 0;
	double p = 0.7; // probability that remove the key if the key is existing
	int key;
	int operation;
	unsigned long long insertNum = 0;
	unsigned long long removeNum = 0;
	unsigned long long searchNum = 0;
	vector<int> count(MAX, 0);
	fstream keyFile;
	fstream operationFile;

	keyFile.open("key0.txt", ios::in);
	if (!keyFile) {
		cout << "[error] keyFile  could not be opened" << endl;
		system("pause");
	}

	operationFile.open("operationFile.txt", ios::in);
	if (!operationFile) {
		cout << "[error] operationFile  could not be opened" << endl;
		system("pause");
	}

	BTree* tree = new BTree(3);

	while (keyFile >> key && i < MAX) {
		if (i % 1000 == 0) {
			cerr << "Now reaching I/O request " << i << endl;
		}
		operationFile >> operation;
		if (operation == 1) {
			//cout << i << "th: Insert" << endl;
			tree->Insert(key);
			insertNum++;
		}
		else if (operation == 2) {
			//cout << i << "th: Delete" << endl;
			tree->Delete(key);
			removeNum++;
		}
		else {
			/*int find = tree->Search(key);
			if (find != key) {
				cout << "[error] search";
				system("pause");
			}*/
			searchNum++;
		}
		i++;
	}
	cout << "#insert " << insertNum << endl;
	cout << "#remove " << removeNum << endl;
	cout << "#search " << searchNum << endl;
	tree->Inorder();
	system("pause");
	return 0;
}