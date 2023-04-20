#include "BinaryTree.h"

BinTree::BinTree()
{
	this->root = nullptr;
	this->index = 0;
}

BinTree::~BinTree()
{
	destroy_tree();
}

void BinTree::clearTree()
{
	destroy_tree();
	this->root = nullptr;
	this->index = 0;
}

void BinTree::overWriteNode(Setting * key)
{
	overWriteNode(key, this->root);
}

//Chèn thêm đối tượng vào tree
void BinTree::insert(Setting * key)
{
	this->root = insert(key, this->root);
}

//Tìm kiếm đối tượng trong Tree
node * BinTree::search(string key, InputInfo choice)
{
	return search(key, choice, this->root);
}

//Xóa Tree
void BinTree::destroy_tree()
{
	destroy_tree(this->root);
}

void BinTree::inorder_print(string key, InputInfo choice, Classify choice_classify)
{
	switch (choice)
	{
	case CAR_NAME:
		inorder_print_carName(key, this->root, choice_classify);
		break;
	case PERSONAL_KEY:
		inorder_print_personalKey(key, this->root, choice_classify);
		break;
	}
}

//Trả về số lượng phần tử trong Tree
int BinTree::size()
{
	return index;
}

bool BinTree::isEmpty()
{
	if (this->root == nullptr) return true;
	return false;
}

//Duyệt trung thứ tự ghi file
void BinTree::inorder_writeFile(string FILE_PATH)
{
	this->inorder_writeFile(this->root, FILE_PATH);
}

void BinTree::destroy_tree(node * leaf)
{
	if (leaf != nullptr)
	{
		if (leaf->left != nullptr) destroy_tree(leaf->left);
		if (leaf->right != nullptr) destroy_tree(leaf->right);
		delete leaf;
	}
}

void BinTree::overWriteNode(Setting * key, node * leaf)
{
	if (leaf != nullptr)
	{
		if (key->getPersonalKey() < leaf->data->getPersonalKey())
		{
			overWriteNode(key, leaf->left);
		}
		else if (leaf->data->getPersonalKey() < key->getPersonalKey())
		{
			overWriteNode(key, leaf->right);

		}
		else
		{
			leaf->data->MyCar::operator=(key);
		}
	}
}

node *BinTree::insert(Setting * key, node * leaf)
{
	if (leaf == nullptr)
	{
		node *temp = new node;
		temp->data = key;
		temp->left = nullptr;
		temp->right = nullptr;
		index++;
		return temp;
	}
	else
	{
		if (leaf->data->getPersonalKey() > key->getPersonalKey())
		{
			leaf->left = insert(key, leaf->left);
		}
		else
		{
			leaf->right = insert(key, leaf->right);
		}
	}
	return leaf;
}

node * BinTree::search(string key, InputInfo choice, node * leaf)
{
	switch (choice)
	{
	case CAR_NAME:
		if (leaf == nullptr)
		{
			return nullptr;
		}
		else
		{
			if (leaf->data->getCarName() < key) //Tìm cây con bên phải
			{
				return search(key, choice, leaf->right);
			}
			else if (key < leaf->data->getCarName()) //Tìm cây con bên trái
			{
				return search(key, choice, leaf->left);
			}
			else
			{
				return leaf; //Tìm thấy
			}
		}
		break;
	case PERSONAL_KEY:
		if (leaf == nullptr)
		{
			return nullptr;
		}
		else
		{
			if (leaf->data->getPersonalKey() < key) //Tìm cây con bên phải
			{
				return search(key, choice, leaf->right);
			}
			else if (key < leaf->data->getPersonalKey()) //Tìm cây con bên trái
			{
				return search(key, choice, leaf->left);
			}
			else
			{
				return leaf; //Tìm thấy
			}
		}
		break;
	}
}

void BinTree::inorder_print_carName(string key, node * leaf, Classify choice)
{
	switch (choice)
	{
	case DISPLAY:
		if (leaf != nullptr)
		{
			inorder_print_carName(key, leaf->left, choice);
			if (leaf->data->getCarName() == key)
			{
				leaf->data->MyCar::xuatThongTin();
				leaf->data->getDisplayInfo()->xuatThongTin();
				cout << endl;
			}
			inorder_print_carName(key, leaf->right, choice);
		}
		break;
	case SOUND:
		if (leaf != nullptr)
		{
			inorder_print_carName(key, leaf->left, choice);
			if (leaf->data->getCarName() == key)
			{
				leaf->data->MyCar::xuatThongTin();
				leaf->data->getSoundInfo()->xuatThongTin();
				cout << endl;
			}
			inorder_print_carName(key, leaf->right, choice);
		}
		break;
	case GENERAL:
		if (leaf != nullptr)
		{
			inorder_print_carName(key, leaf->left, choice);
			if (leaf->data->getCarName() == key)
			{
				leaf->data->MyCar::xuatThongTin();
				leaf->data->getGeneralInfo()->xuatThongTin();
				cout << endl;
			}
			inorder_print_carName(key, leaf->right, choice);
		}
		break;
	case SETTING:
		if (leaf != nullptr)
		{
			inorder_print_carName(key, leaf->left, choice);
			if (leaf->data->getCarName() == key)
			{
				leaf->data->xuatThongTin();
				cout << endl;
			}
			inorder_print_carName(key, leaf->right, choice);
		}
		break;
	}
}

void BinTree::inorder_print_personalKey(string key, node * leaf, Classify choice)
{
	switch (choice)
	{
	case DISPLAY:
		if (leaf != nullptr)
		{
			inorder_print_personalKey(key, leaf->left, choice);
			if (leaf->data->getPersonalKey() == key)
			{
				leaf->data->MyCar::xuatThongTin();
				leaf->data->getDisplayInfo()->xuatThongTin();
				cout << endl;
			}
			inorder_print_personalKey(key, leaf->right, choice);
		}
		break;
	case SOUND:
		if (leaf != nullptr)
		{
			inorder_print_personalKey(key, leaf->left, choice);
			if (leaf->data->getPersonalKey() == key)
			{
				leaf->data->MyCar::xuatThongTin();
				leaf->data->getSoundInfo()->xuatThongTin();
				cout << endl;
			}
			inorder_print_personalKey(key, leaf->right, choice);
		}
		break;
	case GENERAL:
		if (leaf != nullptr)
		{
			inorder_print_personalKey(key, leaf->left, choice);
			if (leaf->data->getPersonalKey() == key)
			{
				leaf->data->MyCar::xuatThongTin();
				leaf->data->getGeneralInfo()->xuatThongTin();
				cout << endl;
			}
			inorder_print_personalKey(key, leaf->right, choice);
		}
		break;
	case SETTING:
		if (leaf != nullptr)
		{
			inorder_print_personalKey(key, leaf->left, choice);
			if (leaf->data->getPersonalKey() == key)
			{
				leaf->data->xuatThongTin();
				cout << endl;
			}
			inorder_print_personalKey(key, leaf->right, choice);
		}
		break;
	}
}

void BinTree::inorder_writeFile(node * leaf, string FILE_PATH)
{
	if (leaf != nullptr)
	{
		inorder_writeFile(leaf->left, FILE_PATH);
		leaf->data->writeFile(FILE_PATH);
		inorder_writeFile(leaf->right, FILE_PATH);
	}
}

node node::operator=(node node_)
{
	this->data = node_.data;
	this->left = node_.left;
	this->right = node_.right;
	return *this;
}
