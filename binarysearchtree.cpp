//File Name: binarysearchtree.cpp
// Programmer: Tabitha Roemish
// Date: 1/27/2018
//#include "binarysearchtree.h"


//template<class ItemType>
//BinarySearchTree<ItemType>::BinarySearchTree() {
//	//ctor
//}
//
//template<class ItemType>
//BinarySearchTree<ItemType>::~BinarySearchTree() {
//	clear();
//}
//
//template<class ItemType>
//BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem) {
//	rootPtr = new BinaryNode<ItemType>(rootItem);
//}
//
//template<class ItemType>
//BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& bst) {
//	rootPtr = copyTree(bst.rootPtr);
//}
//
//template<class ItemType>
//bool BinarySearchTree<ItemType>::isEmpty() const {
//	return (rootPtr == nullptr) ? true : false;
//}
//
//template<class ItemType>
//int BinarySearchTree<ItemType>::getHeight() const {
//	return getHeightHelper(rootPtr);;
//}
//
//
//template<class ItemType>
//int BinarySearchTree<ItemType>::getNumberOfNodes() const {
//	return getNodeCountHelper(rootPtr);
//}
//
//template<class ItemType>
//bool BinarySearchTree<ItemType>::add(const ItemType& item) {
//
//	if (insertCount == 3)
//	{
//		rebalance();
//		insertCount = 0;
//	}
//
//	if (rootPtr == nullptr)
//		rootPtr = new BinaryNode<ItemType>(item);
//	else
//	{
//		if (contains(item))
//			return false;
//		else
//		{
//			BinaryNode<ItemType> * tempNewNode = new BinaryNode<ItemType>(item);
//			placeNode(rootPtr, tempNewNode);
//			insertCount++;
//		}
//	}
//	return true;
//}
//
//template<class ItemType>
//void BinarySearchTree<ItemType>::clear() {
//	deleteTree(rootPtr);
//	rootPtr = nullptr;
//}
//
//template<class ItemType>
//bool BinarySearchTree<ItemType>::contains(const ItemType& item) const {
//	if (findNode(rootPtr, item) == nullptr)
//		return false;
//	return true;
//}
//
//template<class ItemType>
//BinaryNode<ItemType>* BinarySearchTree<ItemType>::
//placeNode(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr) {
//	if (newNodePtr->getItem()> subTreePtr->getItem())
//	{
//		if (subTreePtr->getRightChildPtr() == nullptr)
//			subTreePtr->setRightChildPtr(newNodePtr);
//		else
//			placeNode(subTreePtr->getRightChildPtr(), newNodePtr);
//	}
//	//check left
//	if (newNodePtr->getItem() < subTreePtr->getItem())
//	{
//		if (subTreePtr->getLeftChildPtr() == nullptr)
//			subTreePtr->setLeftChildPtr(newNodePtr);
//		else
//			placeNode(subTreePtr->getLeftChildPtr(), newNodePtr);
//	}
//	if (newNodePtr->getItem() == subTreePtr->getItem())
//		return nullptr;
//
//	return subTreePtr;
//}  // end placeNode
//
//template<class ItemType>
//BinaryNode<ItemType>* BinarySearchTree<ItemType>::
//findNode(BinaryNode<ItemType>* subTreePtr, const ItemType& target) const {
//
//	if (subTreePtr->getItem() == target)
//		return subTreePtr;
//	//check left
//	else if (target < subTreePtr->getItem())
//		if (subTreePtr->getLeftChildPtr() == nullptr)
//			return nullptr;
//		else
//			return findNode(subTreePtr->getLeftChildPtr(), target);
//	//check right
//	else if (target > subTreePtr->getItem())
//		if (subTreePtr->getRightChildPtr() == nullptr)
//			return nullptr;
//		else
//			return findNode(subTreePtr->getRightChildPtr(), target);
//	else
//		return nullptr;
//
//}  // end findNode
//
//   //template<class ItemType>
//   //void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const {
//   //	inorder(visit, rootPtr);
//   //}  // end inorder
//
//template<class ItemType>
//void BinarySearchTree<ItemType>::print()
//{
//	if (current != nullptr)
//	{
//		print(current->getLeftChildPtr());
//		std::cout << "      " << *current << std::endl;
//		print(current->getRightChildPtr());
//	}
//}
//
//template<class ItemType>
//void BinarySearchTree<ItemType>::rebalance() {
//	//save to array
//	int size = getNumberOfNodes();
//	ItemType * arrPtr = new string[size];
//	saveToArray(rootPtr, arrPtr, 0);
//	// build tree from array
//	readTree(arrPtr, size);
//	delete[] arrPtr;
//}
//
//template<class ItemType>
//bool BinarySearchTree<ItemType>::readTree(ItemType arr[], int n) {
//	clear(); //clear existing tree
//
//			 //adding this since readTree is public and 
//			 // readtreehelper requires a sorted array to build a binary search tree
//	if (!(is_sorted(arr, arr + n)))
//		sort(arr, arr + n);
//
//	rootPtr = readTreeHelper(0, n - 1, arr);	// fill tree
//
//	if (rootPtr == nullptr) //set boolean return
//		return false;
//	else
//		return true;
//}
//
//template<class ItemType>
//void BinarySearchTree<ItemType>::displaySideways() const {
//	sideways(rootPtr, 0);
//}
//
//template<class ItemType>
//void BinarySearchTree<ItemType>::sideways(BinaryNode<ItemType>* current, int level) const {
//	if (current != NULL) {
//		level++;
//		sideways(current->getRightChildPtr(), level);
//
//		// indent for readability, 4 spaces per depth level
//		for (int i = level; i >= 0; i--) {
//			cout << "    ";
//		}
//
//		cout << current->getItem() << endl;        // display information of object
//		sideways(current->getLeftChildPtr(), level);
//	}
//}
//
//template<class ItemType>
//bool BinarySearchTree<ItemType>::operator==(const BinarySearchTree<ItemType>& other) const {
//	return compare(rootPtr, other.rootPtr);
//}
//
//template<class ItemType>
//bool BinarySearchTree<ItemType>::operator!=(const BinarySearchTree<ItemType>& other) const {
//	if (other == *this)
//		return false;
//	else
//		return true;
//}
//
//// Helper Functions:
//
//template<class ItemType>
//BinaryNode<ItemType> * BinarySearchTree<ItemType>::
//copyTree(const BinaryNode<ItemType> * current) const
//{
//	BinaryNode<ItemType> * otherTreePtr = nullptr;
//	if (current != nullptr)
//	{
//		otherTreePtr = new BinaryNode<ItemType>(current->getItem());
//		otherTreePtr->setLeftChildPtr(copyTree(current->getLeftChildPtr()));
//		otherTreePtr->setRightChildPtr(copyTree(current->getRightChildPtr()));
//	}
//	return otherTreePtr;
//}
//
//template<class ItemType>
//int BinarySearchTree<ItemType>::getHeightHelper(BinaryNode<ItemType> * current) const
//{
//	if (current == nullptr)
//		return 0;
//	else
//		return 1 + max(getHeightHelper(current->getLeftChildPtr()),
//			getHeightHelper(current->getRightChildPtr()));
//}
//
//template<class ItemType>
//int BinarySearchTree<ItemType>::getNodeCountHelper(BinaryNode<ItemType> * current) const
//{
//	if (current == nullptr)
//		return 0;
//	else
//		return 1 + getNodeCountHelper(current->getLeftChildPtr()) +
//		getNodeCountHelper(current->getRightChildPtr());
//
//}
//
//template<class ItemType>
//void BinarySearchTree<ItemType>::deleteTree(BinaryNode<ItemType>* current)
//{
//	if (current != nullptr)
//	{
//		deleteTree(current->getLeftChildPtr());
//		deleteTree(current->getRightChildPtr());
//		delete current;
//	}
//}
//
//template<class ItemType>
//void BinarySearchTree<ItemType>::
//inorder(void visit(ItemType&), BinaryNode<ItemType> * current) const
//{
//	if (current != nullptr)
//	{
//		inorder(visit, current->getLeftChildPtr());
//		ItemType theItem = current->getItem();
//		visit(theItem); // main uses displayItem()
//		inorder(visit, current->getRightChildPtr());
//	}
//}
//
//template<class ItemType>
//void BinarySearchTree<ItemType>::
//saveToArray(BinaryNode<ItemType> * current, ItemType arr[], int i)
//{
//	if (current != nullptr)
//	{
//		saveToArray(current->getLeftChildPtr(), arr, i);
//		arr[i] = current->getItem();
//		i++;
//		saveToArray(current->getRightChildPtr(), arr, i);
//	}
//}
//
//
//template<class ItemType>
//BinaryNode<ItemType> * BinarySearchTree<ItemType>::
//readTreeHelper(int start, int end, ItemType arr[])
//{
//	if (start > end)
//		return nullptr;
//	else
//	{
//		int mid = (start + end) / 2;
//		BinaryNode<ItemType> * current = new BinaryNode<ItemType>(arr[mid]);
//		current->setLeftChildPtr(readTreeHelper(start, (mid - 1), arr));
//		current->setRightChildPtr(readTreeHelper((mid + 1), end, arr));
//		return current;
//	}
//}
//
//template<class ItemType>
//bool BinarySearchTree<ItemType>::
//compare(BinaryNode<ItemType> * t1, BinaryNode<ItemType> * t2) const
//{
//	if (t1 == nullptr && t2 == nullptr)
//		return true;
//	else if (t1 == nullptr || t2 == nullptr)
//		return false;
//	else
//		return ((t1->getItem() == t2->getItem())
//			&& compare(t1->getLeftChildPtr(), t2->getLeftChildPtr())
//			&& compare(t1->getRightChildPtr(), t2->getRightChildPtr()));
//}





