
#include "BSTree.h"

template <typename DataType, class KeyType>
BSTree<DataType, KeyType>::BSTreeNode::BSTreeNode ( const DataType &nodeDataItem, BSTreeNode *leftPtr, BSTreeNode *rightPtr ){
	this->dataItem = nodeDataItem;
	this->left = leftPtr;
	this->right = rightPtr;
}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>::BSTree (){
	root = nullptr;
}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>::BSTree ( const BSTree<DataType,KeyType>& other ){
	copyTreeHelper(this->root, other.root);
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::copyTreeHelper( BSTreeNode *t1, BSTreeNode *t2) {
	if(t2 == nullptr) {
		return;
	}
	BSTreeNode* tempNode = new BSTreeNode;
	tempNode->dataItem = t2->dataItem;
	t1 = tempNode;
	copyTreeHelper(t1->left, t2->left);
	copyTreeHelper(t2->right, t2->right);
}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>& BSTree<DataType, KeyType>:: operator= ( const BSTree<DataType,KeyType>& other ){
	copyTreeHelper(this->root, other.root);
}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>::~BSTree (){
	this->clear();
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::insert ( const DataType& newDataItem ){
	insertHelper(this->root, newDataItem);
}

template<typename DataType, class keyType>
 void BSTree<DataType, keyType>::insertHelper(BSTreeNode *&p,const DataType &newDataItem){
	 if(p == nullptr){
		 BSTreeNode *tempNode = new BSTreeNode(newDataItem, nullptr, nullptr);
		 p = tempNode;
	 }
	 else if(newDataItem.getKey() < p->dataItem.getKey()){
		 insertHelper(p->left, newDataItem);
	 }
	 else if(newDataItem.getKey() > p->dataItem.getKey()){
		 insertHelper(p->right, newDataItem);
	 }else{
		 p->dataItem =  newDataItem;
	 }
}

template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::retrieve ( const KeyType& searchKey, DataType& searchDataItem ) const{
	return retrieveHelper(root,searchKey,searchDataItem);		
}

template<typename DataType, class KeyType>
bool BSTree<DataType,KeyType>::retrieveHelper ( BSTreeNode *p, const KeyType& searchKey, DataType &searchDataItem ) const{
	if (p == nullptr) {
		return false;
	}
	if(searchKey < p->dataItem.getKey()){
		return retrieveHelper(p->left, searchKey, searchDataItem);
	}
	if(searchKey > p->dataItem.getKey()){
		return retrieveHelper(p->right, searchKey, searchDataItem);
	}
	searchDataItem = p->dataItem;
	return true;
}

template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::remove ( const KeyType& deleteKey ){
	return removeHelper(this->root, deleteKey);
}

template < typename DataType, typename KeyType >
bool BSTree<DataType,KeyType>:: removeHelper( BSTreeNode *&p, const KeyType& deleteKey ){
	BSTreeNode *delPtr;
	if(p == nullptr){
		return false;
	}
	if ( deleteKey < p->dataItem.getKey() ) {
		return removeHelper(p->left, deleteKey);
	}
	if ( deleteKey > p->dataItem.getKey() ) {
		return removeHelper(p->right, deleteKey);
	}
	if(p->left == nullptr && p->right == nullptr) {
		delPtr = p;
		delete delPtr;
		p = nullptr;
		return true;
	}
	if(p->left == nullptr){
		p->dataItem = p->right->dataItem;
		delPtr = p->right;
		p->right = p->right->right;
		delete delPtr;
	}
	else if(p->right == nullptr){
		p->dataItem = p->left->dataItem;
		delPtr = p->left;
		p->left = p->left->left;
		delete delPtr;
	}
	else{
		BSTreeNode *tempNode = p->left;
		while(tempNode->right){
			tempNode = tempNode->right;
		}
		p->dataItem = tempNode->dataItem;
		removeHelper(p->left, tempNode->dataItem.getKey());
	}
	return true;
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::writeKeys () const{
	writeKeysHelper(this->root);
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::writeKeysHelper (const BSTreeNode *tempNode) const{
	if(tempNode == nullptr){
		return;
	}
	writeKeysHelper(tempNode->left);
	cout << tempNode->dataItem.getKey() << " ";
	writeKeysHelper(tempNode->right);
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::clear (){
	clearHelper(this->root);
	this->root = nullptr;
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::clearHelper (BSTreeNode *node){
	if(node == nullptr){
		return;
	}
	clearHelper(node->left);
	clearHelper(node->right);
	delete node;
}

template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::isEmpty () const{
	if(this->root == nullptr){
		return true;
	}
	return false;
}

template < typename DataType, class KeyType >
int BSTree<DataType, KeyType>::getHeight () const{
	return getHightHelper(this->root);
}

template <typename DataType, class KeyType>
int BSTree<DataType, KeyType>::getHightHelper(BSTreeNode *p) const{
	if(p == nullptr){
		return 0;
	}
	return max(getHightHelper(p->left), getHightHelper(p->right)) + 1;
}

template < typename DataType, class KeyType >
int BSTree<DataType, KeyType>::getCount () const{
	return getCountHelper(this->root);
}

template<typename DataType, class KeyType>
int BSTree<DataType, KeyType>::getCountHelper(BSTreeNode *p) const{
	int total = 0;
	if(p == nullptr){
		return 0;
	}
	total += getCountHelper(p->left);
	total += getCountHelper(p->right);
	return total + 1;
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::writeLessThan ( const KeyType& searchKey ) const{
	writeLessThanHelper(this->root, searchKey);
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::writeLessThanHelper( BSTreeNode *tempNode, const KeyType& searchKey) const{
	if(tempNode == nullptr){
		return;
	}
	writeLessThanHelper(tempNode->left, searchKey);
	if (tempNode->dataItem.getKey() < searchKey) {
		cout << tempNode->dataItem.getKey() << " ";
	}
	writeLessThanHelper(tempNode->right, searchKey);

	
}



#include "show9.cpp"