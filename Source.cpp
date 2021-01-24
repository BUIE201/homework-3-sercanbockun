#include <iostream>
#include <list>
using namespace std;


// Constructing Tree

struct Node
{
	int i;
	Node* pLeft;
	Node* pRight;

	Node(int iIn) : i(iIn), pLeft(nullptr), pRight(nullptr) {}
};


std::list<Node*> branch;


int maxsum(Node* pRoot)
{
	if (!pRoot) {
		return 0;
	}
	
	int left = maxsum(pRoot->pLeft); // Recursively we calculate the sum of branches on the left
	int right = maxsum(pRoot->pRight); // And samely on the right branches


	 // After recursive iterations we get the higher sum either from right or left
	if (left >= right) {
		if ((pRoot->pLeft)) {
			branch.push_back(pRoot->pLeft);
		}
		return left + pRoot->i;
	}
	else {
		
		return right + pRoot->i;
	}

};

void successpath(Node* pRoot) {




}

int main(){
	//I'm manually constructing the tree because this is not an ordered tree!!!
	Node* pRoot = nullptr;
	pRoot = new Node(5);
	pRoot->pLeft = new Node(4);
	pRoot->pLeft->pLeft = new Node(11);
	pRoot->pLeft->pLeft->pLeft = new Node(7);
	pRoot->pLeft->pLeft->pRight = new Node(2);

	pRoot->pRight = new Node(8);
	pRoot->pRight->pLeft = new Node(13);
	pRoot->pRight->pRight = new Node(4);
	pRoot->pRight->pRight->pRight = new Node(1);
	int totalsum = maxsum(pRoot);
	cout << totalsum << endl;
	for (auto i : branch)
		std::cout << i->i << "\n";
	
}