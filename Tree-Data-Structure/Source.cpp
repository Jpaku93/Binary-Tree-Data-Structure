// Binary-Tree-Data-Structure.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
// create a subject struct
struct Subject {
	std::string name;
	int grade;
};

// create node class for a binary tree
class BT {

	Subject data;
	BT* left;
	BT* right;
public:
	BT(Subject data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
	// insert function
	void insert(Subject data) {
		if (data.grade <= this->data.grade) {
			if (this->left == NULL) {
				this->left = new BT(data);
			}
			else {
				this->left->insert(data);
			}
		}
		else {
			if (this->right == NULL) {
				this->right = new BT(data);
			}
			else {
				this->right->insert(data);
			}
		}
	}
	// contains boolean
	bool contains(Subject data) {
		if (data.grade == this->data.grade) {
			return true;
		}
		else if (data.grade <= this->data.grade) {
			if (this->left == NULL) {
				return false;
			}
			else {
				return this->left->contains(data);
			}
		}
		else {
			if (this->right == NULL) {
				return false;
			}
			else {
				return this->right->contains(data);
			}
		}
	}
	// print in order function (left root right)
	void printInOrder() {
		if (this->left != NULL) {
			this->left->printInOrder();
		}
		std::cout << "Grade:" << this->data.grade << std::endl;
		std::cout << "Name:" << this->data.name << std::endl;
		if (this->right != NULL) {
			this->right->printInOrder();
		}
	}
	//print pre order function (root left right)
	void printPreOrder() {
		std::cout << "Grade:" << this->data.grade << std::endl;
		std::cout << "Name:" << this->data.name << std::endl;
		if (this->left != NULL) {
			this->left->printPreOrder();
		}
		if (this->right != NULL) {
			this->right->printPreOrder();
		}
	}
	//print post order function (left right root)
	void printPostOrder() {
		if (this->left != NULL) {
			this->left->printPostOrder();
		}
		if (this->right != NULL) {
			this->right->printPostOrder();
		}
		std::cout << "Grade:" << this->data.grade << std::endl;
		std::cout << "Name:" << this->data.name << std::endl;

	}
};




int main()
{
	// create a subject struct
	Subject data({ "root", 0 });

	// create a node class for a binary tree
	BT* root = new BT(data);
	// insert data into the tree
	root->insert({ "John", 90 });
	root->insert({ "Jane", 80 });
	root->insert({ "Joe", 70 });
	root->insert({ "Jack", 60 });
	root->insert({ "Jill", 50 });
	root->insert({ "Jak", 40 });

	std::cout << "In Order: ";
	root->printInOrder();
	std::cout << "\nPre Order: ";
	root->printPreOrder();
	std::cout << "\nPost Order: ";
	root->printPostOrder();
	std::cout << "\n";
	// check if the tree contains a subject
	std::cout << "Does the tree contain a subject with grade of 70? " << root->contains({ "", 60 }) << std::endl;
	std::cout << "Does the tree contain a subject with grade of 80? " << root->contains({ "", 80 }) << std::endl;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

