#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include <iostream>
#include "Setting.h"

using namespace std;

struct node
{
	Setting *data;
	node *left;
	node *right;

	node operator=(node node_);
};

enum Classify
{
	DISPLAY, SOUND, GENERAL, SETTING
};

enum InputInfo
{
	CAR_NAME, PERSONAL_KEY
};

class BinTree
{
public:
	BinTree();
	~BinTree();

	int size();
	bool isEmpty();

	void clearTree();
	void overWriteNode(Setting * key);
	void insert(Setting * key);
	node* search(string key, InputInfo choice);
	void destroy_tree();
	void inorder_print(string key, InputInfo choice, Classify choice_classify);
	void inorder_writeFile(string FILE_PATH);
private:
	void overWriteNode(Setting * key, node * leaf);
	node* insert(Setting * key, node *leaf);
	node* search(string key, InputInfo choice, node *leaf);
	void destroy_tree(node *leaf);
	void inorder_print_carName(string key, node *leaf, Classify choice_classify);
	void inorder_print_personalKey(string key, node *leaf, Classify choice_classify);
	void inorder_writeFile(node *leaf, string FILE_PATH);

	node* root;
	int index;
};

#endif // !_BINARYTREE_H


