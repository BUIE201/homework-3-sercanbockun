#include <iostream>
#include <vector>
using namespace std;


// Constructing Tree

struct Node
{
	int i;
	Node* pLeft;
	Node* pRight;

	Node(int iIn) : i(iIn), pLeft(nullptr), pRight(nullptr) {}
};





int maxsum(Node* pRoot )
{
	if (!pRoot) {
		return 0;
	}
	
	int left = maxsum(pRoot->pLeft); // Recursively we calculate the sum of branches on the left
	int right = maxsum(pRoot->pRight); // And samely on the right branches


	 // After recursive iterations we get the higher sum either from right or left
	if (left >= right) {
		
		return left + pRoot->i;}
	else {
		
		return right + pRoot->i;}
}

bool sumsuccessorpath(Node* pRoot, int sum)
{

	if (sum == 0) { // this if statement checks if we found the leaf or not. Sum == 0 means we found the LEAF!!!!!
		return true;
	}

	if (pRoot == nullptr) {
		return false;
	}
	bool left = sumsuccessorpath(pRoot->pLeft, sum - pRoot->i);
	bool right = sumsuccessorpath(pRoot->pRight, sum - pRoot->i);

	if (left || right) {
		cout << pRoot->i << " ";
	}

	return left || right;
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
	
	cout << "Branch with the largest sum is (in reverse):" << " ";
	sumsuccessorpath(pRoot, 27);
	cout << "-> SUM = " << " ";
	cout << totalsum << endl;

	
}
