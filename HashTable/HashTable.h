#ifndef HASHTABLE_H
#define HASHTABLE_H
class HashTable {
private:
	int* keys;
	int m;
public:
	HashTable(int space);
	~HashTable();
	int Hash(int key, int i);
	int OpenAddressing();
	void Insert(int key);
	void Delete(int key);
	int Search(int key);

};
#endif // !HASHTABLE_H

