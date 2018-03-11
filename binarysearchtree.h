// Yusuf Pisan pisan@uw.edu
// 15 Jan 2018

// Edit 20 Jan 2018. Added <ItemType> for all cases
// since it was complaining under some compilers but not g++

// Additional Private methods added by:
//	Tabitha Roemish
//	27 Jan 2018

// BinarySearchTree class
// Creates a BST to store values
// Uses BinaryNode which holds the data
// Uses templates to store any type of data
// binarysearchtreee.cpp file is included at the bottom of the .h file
// binarysearchtreee.cpp is part of the template, cannot be compiled separately

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "movie.h" // required for rental store custom functions
#include "binarynode.h"
#include<algorithm>

using namespace std;

template<class ItemType>
class BinarySearchTree {
public:
    // constructor, empty tree
    BinarySearchTree<ItemType>();
    // constructor, tree with root
    explicit BinarySearchTree<ItemType>(const ItemType& rootItem);
    // copy constructor
    BinarySearchTree<ItemType>(const BinarySearchTree<ItemType>& bst);
    // destructor
    virtual ~BinarySearchTree<ItemType>();
    // true if no nodes
    bool isEmpty() const;
    // 0 if empty, 1 if only root, otherwise
    // max height of subtrees + 1
    int getHeight() const;
    // number of nodes and data in tree
    int getNumberOfNodes() const;
    // add a new item
    // return true if succesasfull
    // false if item already in tree or some other reason to fail
    bool add(const ItemType& item);
    // true if item is in tree
    bool contains(const ItemType& item) const;
    // dispaly a sideways ascii representation of tree
    void displaySideways() const;
    // inorder traversal: left-root-right
    // takes a function that takes a single parameter of ItemType
    // the function can modify the data in tree, but the
    // tree structure is not changed
 /*   void inorderTraverse(void visit(ItemType&)) const;*/
    // create dynamic array, copy all the items to the array
    // and then read the array to re-create this tree
    void rebalance();
    // delete all nodes in tree and set root to nullptr
    void clear();
    // given an array of length n
    // create this tree to have all items in that array
    // with the minimum height
    bool readTree(ItemType arr[], int n);
    // trees are equal if they have the same structure
    // AND the same item values at all the nodes
    bool operator==(const BinarySearchTree<ItemType> &) const;
    // not == to each other
    bool operator!=(const BinarySearchTree<ItemType> &) const;

	//custom methods for use in Rental Store

	//print tree inorder w/passing function as parameter
	void print();
	//find item given string value, 
	// requires ItemType to have method getKey() that returns string
	bool findWithString(std::string itemKey);

	// return item given string value, 
	//requres ItemType have getKey() method that returns string
	ItemType returnItemWithString(std::string itemKey);

private:
    // root of the tree
    BinaryNode<ItemType>* rootPtr {nullptr};
    // add a new node, helper function for add
    BinaryNode<ItemType>* placeNode(BinaryNode<ItemType>* subTreePtr, 
		BinaryNode<ItemType>* newNodePtr);
    // find the node with given vale, helper function for contains
    BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* subTreePtr, 
		const ItemType& target) const;
    // helper function for displaySideways to work recursively
    void sideways(BinaryNode<ItemType>* current, int level) const;

	// other functions....
	void printHelper(BinaryNode<ItemType>* current);
	ItemType returnItemWithStringHelper(BinaryNode<ItemType>* subTreePtr, 
		std::string itemKey);
	bool findWithStringHelper(BinaryNode<ItemType>* subTreePtr, std::string itemKey);
	void deleteTree(BinaryNode<ItemType>* current);
	int getHeightHelper(BinaryNode<ItemType> * current) const;
	int getNodeCountHelper(BinaryNode<ItemType> * current) const;
	void inorder(void visit(ItemType&), BinaryNode<ItemType> * current) const;
	BinaryNode<ItemType> * copyTree(const BinaryNode<ItemType> * current) const;
	BinaryNode<ItemType> * readTreeHelper(int start, int end, ItemType arr[]);
	bool compare(BinaryNode<ItemType> * t1, BinaryNode<ItemType> * t2) const;
	void saveToArray(BinaryNode<ItemType> * current, ItemType arr[], int i);
	static int insertCount;
};

template<class ItemType>
int BinarySearchTree<ItemType>::insertCount = 0;


/////////////////////////////////////////////////////

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() {
	//ctor
}

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree() {
	clear();
}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem) {
	rootPtr = new BinaryNode<ItemType>(rootItem);
}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& bst) {
	rootPtr = copyTree(bst.rootPtr);
}

template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const {
	return (rootPtr == nullptr) ? true : false;
}

template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const {
	return getHeightHelper(rootPtr);;
}


template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const {
	return getNodeCountHelper(rootPtr);
}

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& item) {

	//if (insertCount == 5)
	//{
	//	rebalance();
	//	insertCount = 0;
	//}

	if (rootPtr == nullptr)
		rootPtr = new BinaryNode<ItemType>(item);
	else
	{
		if (contains(item))
			return false;
		else
		{
			BinaryNode<ItemType> * tempNewNode = new BinaryNode<ItemType>(item);
			placeNode(rootPtr, tempNewNode);
			insertCount++;
		}
	}
	return true;
}

template<class ItemType>
void BinarySearchTree<ItemType>::clear() {
	deleteTree(rootPtr);
	rootPtr = nullptr;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& item) const {
	if (findNode(rootPtr, item) == nullptr)
		return false;
	return true;
}

//customized for Rental Store
//add dereferencing to look at Movie objects
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::
placeNode(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr) {
	if (*newNodePtr->getItem() > *subTreePtr->getItem())
	{
		if (subTreePtr->getRightChildPtr() == nullptr)
			subTreePtr->setRightChildPtr(newNodePtr);
		else
			placeNode(subTreePtr->getRightChildPtr(), newNodePtr);
	}
	//check left
	if (*newNodePtr->getItem() < *subTreePtr->getItem())
	{
		if (subTreePtr->getLeftChildPtr() == nullptr)
			subTreePtr->setLeftChildPtr(newNodePtr);
		else
			placeNode(subTreePtr->getLeftChildPtr(), newNodePtr);
	}
	if (*newNodePtr->getItem() == *subTreePtr->getItem())
		return nullptr;

	return subTreePtr;
}  // end placeNode

//customized for Rental Store
//add dereferencing to look at Movie objects
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::
findNode(BinaryNode<ItemType>* subTreePtr, const ItemType& target) const {

	if (*subTreePtr->getItem() == *target)
		return subTreePtr;
	//check left
	else if (*target < *subTreePtr->getItem())
		if (subTreePtr->getLeftChildPtr() == nullptr)
			return nullptr;
		else
			return findNode(subTreePtr->getLeftChildPtr(), target);
	//check right
	else if (*target > *subTreePtr->getItem())
		if (subTreePtr->getRightChildPtr() == nullptr)
			return nullptr;
		else
			return findNode(subTreePtr->getRightChildPtr(), target);
	else
		return nullptr;

}  // end findNode

   //template<class ItemType>
   //void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const {
   //	inorder(visit, rootPtr);
   //}  // end inorder

template<class ItemType>
void BinarySearchTree<ItemType>::print()
{
	printHelper(rootPtr);
}

template<class ItemType>
void BinarySearchTree<ItemType>::printHelper(BinaryNode<ItemType>* current)
{
	if (current != nullptr)
	{
		printHelper(current->getLeftChildPtr());
		std::cout << "      ";
		current->getItem()->print();
		printHelper(current->getRightChildPtr());
	}
}

template<class ItemType>
ItemType BinarySearchTree<ItemType>
::returnItemWithString(std::string itemKey)
{
	ItemType mv = returnItemWithStringHelper(rootPtr, itemKey);
	return mv;
}

template<class ItemType>
ItemType BinarySearchTree<ItemType>::
	returnItemWithStringHelper(BinaryNode<ItemType>* subTreePtr,
		std::string itemKey)
{
	std::cout << "find with string test: " << std::endl;
	std::cout << "Current Key: " << subTreePtr->getItem()->getKey() << std::endl;
	std::cout << " Search Key: " << itemKey << endl;
	if (subTreePtr->getItem()->getKey() == itemKey)
		return subTreePtr->getItem();
	//check left
	else if (itemKey < subTreePtr->getItem()->getKey())
	{
		std::cout << "Check Left" << std::endl;
		if (subTreePtr->getLeftChildPtr() == nullptr)
			return nullptr;
		else
			return returnItemWithStringHelper(subTreePtr->getLeftChildPtr(), itemKey);
	}
	//check right
	else if (itemKey > subTreePtr->getItem()->getKey())
	{
		std::cout << "Check Right" << std::endl;
		if (subTreePtr->getRightChildPtr() == nullptr)
			return nullptr;
		else
			return returnItemWithStringHelper(subTreePtr->getRightChildPtr(), itemKey);
	}
	else
		return nullptr;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::findWithString(std::string itemKey)
{
	ItemType temp = returnItemWithStringHelper(rootPtr, itemKey);
	if (temp == nullptr)
		return false;
	else
		return true;
}


//customized for Rental Store
//add dereferencing to look at Movie objects
template<class ItemType>
void BinarySearchTree<ItemType>::rebalance() {
	//save to array
	int size = getNumberOfNodes();
	ItemType * arrPtr = new ItemType[size];
	saveToArray(rootPtr, arrPtr, 0);
	// build tree from array
	readTree(arrPtr, size);
	delete[] arrPtr;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::readTree(ItemType arr[], int n) {
	clear(); //clear existing tree

			 //adding this since readTree is public and 
			 // readtreehelper requires a sorted array to build a binary search tree
	if (!(is_sorted(arr, arr + n)))
		sort(arr, arr + n);

	rootPtr = readTreeHelper(0, n - 1, arr);	// fill tree

	if (rootPtr == nullptr) //set boolean return
		return false;
	else
		return true;
}

template<class ItemType>
void BinarySearchTree<ItemType>::displaySideways() const {
	sideways(rootPtr, 0);
}

template<class ItemType>
void BinarySearchTree<ItemType>::sideways(BinaryNode<ItemType>* current, int level) const {
	if (current != NULL) {
		level++;
		sideways(current->getRightChildPtr(), level);

		// indent for readability, 4 spaces per depth level
		for (int i = level; i >= 0; i--) {
			cout << "    ";
		}

		cout << current->getItem() << endl;        // display information of object
		sideways(current->getLeftChildPtr(), level);
	}
}

template<class ItemType>
bool BinarySearchTree<ItemType>::operator==(const BinarySearchTree<ItemType>& other) const {
	return compare(rootPtr, other.rootPtr);
}

template<class ItemType>
bool BinarySearchTree<ItemType>::operator!=(const BinarySearchTree<ItemType>& other) const {
	if (other == *this)
		return false;
	else
		return true;
}

// Helper Functions:

template<class ItemType>
BinaryNode<ItemType> * BinarySearchTree<ItemType>::
copyTree(const BinaryNode<ItemType> * current) const
{
	BinaryNode<ItemType> * otherTreePtr = nullptr;
	if (current != nullptr)
	{
		otherTreePtr = new BinaryNode<ItemType>(current->getItem());
		otherTreePtr->setLeftChildPtr(copyTree(current->getLeftChildPtr()));
		otherTreePtr->setRightChildPtr(copyTree(current->getRightChildPtr()));
	}
	return otherTreePtr;
}

template<class ItemType>
int BinarySearchTree<ItemType>::getHeightHelper(BinaryNode<ItemType> * current) const
{
	if (current == nullptr)
		return 0;
	else
		return 1 + max(getHeightHelper(current->getLeftChildPtr()),
			getHeightHelper(current->getRightChildPtr()));
}

template<class ItemType>
int BinarySearchTree<ItemType>::getNodeCountHelper(BinaryNode<ItemType> * current) const
{
	if (current == nullptr)
		return 0;
	else
		return 1 + getNodeCountHelper(current->getLeftChildPtr()) +
		getNodeCountHelper(current->getRightChildPtr());

}

//customized for Rental Store
//delete space for movie pointers
template<class ItemType>
void BinarySearchTree<ItemType>::deleteTree(BinaryNode<ItemType>* current)
{
	if (current != nullptr)
	{
		deleteTree(current->getLeftChildPtr());
		deleteTree(current->getRightChildPtr());
		delete current->getItem();
		delete current;
	}
}

template<class ItemType>
void BinarySearchTree<ItemType>::
inorder(void visit(ItemType&), BinaryNode<ItemType> * current) const
{
	if (current != nullptr)
	{
		inorder(visit, current->getLeftChildPtr());
		ItemType theItem = current->getItem();
		visit(theItem); // main uses displayItem()
		inorder(visit, current->getRightChildPtr());
	}
}

//customized for Rental Store
//add dereferencing to add Movie objects to array
template<class ItemType>
void BinarySearchTree<ItemType>::
saveToArray(BinaryNode<ItemType> * current, ItemType arr[], int i)
{
	if (current != nullptr)
	{
		saveToArray(current->getLeftChildPtr(), arr, i);
		arr[i] = *current->getItem();
		i++;
		saveToArray(current->getRightChildPtr(), arr, i);
	}
}


template<class ItemType>
BinaryNode<ItemType> * BinarySearchTree<ItemType>::
readTreeHelper(int start, int end, ItemType arr[])
{
	if (start > end)
		return nullptr;
	else
	{
		int mid = (start + end) / 2;
		BinaryNode<ItemType> * current = new BinaryNode<ItemType>(arr[mid]);
		current->setLeftChildPtr(readTreeHelper(start, (mid - 1), arr));
		current->setRightChildPtr(readTreeHelper((mid + 1), end, arr));
		return current;
	}
}

template<class ItemType>
bool BinarySearchTree<ItemType>::
compare(BinaryNode<ItemType> * t1, BinaryNode<ItemType> * t2) const
{
	if (t1 == nullptr && t2 == nullptr)
		return true;
	else if (t1 == nullptr || t2 == nullptr)
		return false;
	else
		return ((t1->getItem() == t2->getItem())
			&& compare(t1->getLeftChildPtr(), t2->getLeftChildPtr())
			&& compare(t1->getRightChildPtr(), t2->getRightChildPtr()));
}

//#include "binarysearchtree.cpp"  // need to revert to separate files, before submit
#endif // BINARYSEARCHTREE_H
