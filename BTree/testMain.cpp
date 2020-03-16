#include<fstream>
#include<string>
#include<iostream>
#include"BTree.h"
#include<random>
using namespace std;

int main() {
	/*BTree* tree = new BTree(3);
	for (size_t i = 0; i < 1000; i++)
	{
		tree->Insert(i);
		cout << "Insert:" << i << endl;
	}*/

	BTree* tree = new BTree(100);
	minstd_rand generator;
	uniform_int_distribution<int> r(0, 100000);
	int keyMap[100000] = { 0 };
	int n = 1000000;
	while (n){
		int key = r(generator);
		if (keyMap[key] == 0) {
			keyMap[key]++;
			tree->Insert(key);
			cout << "Insert: "<< 1000000 -n <<"th, "<< key << endl;
			n--;
		}
	}
	system("pause");
	return 0;
}