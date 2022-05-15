#include "ListLinked.h"

// ListNode member functions

template <typename DataType>
List<DataType>::ListNode::ListNode(const DataType& nodeData, ListNode* nextPtr){
	this->dataItem = nodeData;
	this->next = nextPtr;
}
// List member functions

template <typename DataType>
List<DataType>::List(int ignored = 0){
	this->head = NULL;
	this->cursor = NULL;
}

template <typename DataType>
List<DataType>::List(const List& other){
	this->head = NULL;
	this->cursor = NULL;
	if(other.head == other.cursor) {
		this->head->dataItem = other.head->dataItem;
		this->head->next = NULL;
		this->cursor = this->head;
	}else{
		ListNode* tempNode = other.head->next;
		ListNode* tempHolderNode;
		this->head->dataItem = other.head->dataItem;
		this->cursor = this->head;
		while (tempNode != NULL){
			tempHolderNode = tempNode->dataItem;
			cursor->next = tempHolderNode;
			tempNode = tempNode->next;
		}
		cursor->next = NULL;
	}

}

template <typename DataType>
List<DataType>& List<DataType>::operator=(const List& other){
	this.clear();
	this->head = NULL;
	this->cursor = NULL;
	if (other.head == other.cursor) {
		this->head->dataItem = other.head->dataItem;
		this->head->next = NULL;
		this->cursor = this->head;
	} else {
		ListNode* tempNode = other.head->next;
		ListNode* tempHolderNode;
		this->head->dataItem = other.head->dataItem;
		this->cursor = this->head;
		while (tempNode != NULL) {
			tempHolderNode = tempNode->dataItem;
			cursor->next = tempHolderNode;
			tempNode = tempNode->next;
		}
		cursor->next = NULL;
	}
}

template <typename DataType>
List<DataType>::~List(){
	clear();
}

template <typename DataType>
void List<DataType>::insert(const DataType& newDataItem) throw (logic_error){
	if (this->head == NULL) {
		this->head = new ListNode(newDataItem, NULL);
		this->cursor = this->head;
	}
	else {
		ListNode* newNode;
		if (this->cursor->next != NULL) {
			newNode = new ListNode(newDataItem, this->cursor->next);
			this->cursor->next = newNode;
			this->cursor = newNode;
		}
		else {
			newNode = new ListNode(newDataItem, NULL);
			this->cursor->next = newNode;
			this->cursor = newNode;
		}
	}

}

template <typename DataType>
void List<DataType>::remove() throw (logic_error){
	if (this->head == this->cursor){
		this->head = this->cursor->next;
		delete this->cursor;
		this->cursor = this->head;
	}
	else {
		ListNode* tempNode = this->head;
		while (tempNode->next != this->cursor) {
			tempNode = tempNode->next;
		}
		tempNode->next = this->cursor->next;
		delete this->cursor;
		this->cursor = tempNode;
	}
}

template <typename DataType>
void List<DataType>::replace(const DataType& newDataItem) throw (logic_error){
	this->cursor->dataItem = newDataItem;
}

template <typename DataType>
void List<DataType>::clear(){
	ListNode* tempNode;
	while(this->head->next != NULL){
		tempNode = this->head->next;
		delete this->head;
		this->head = tempNode;
	}
	delete this->head;
	this->head = NULL;
	this->cursor = this->head;
}

template <typename DataType>
bool List<DataType>::isEmpty() const{
	if(this->head == NULL)
	{
		return true;
	}
	return false;
}

template <typename DataType>
bool List<DataType>::isFull() const{
	return false;
}

template <typename DataType>
void List<DataType>::gotoBeginning() throw (logic_error){
	this->cursor = this->head;
}

template <typename DataType>
void List<DataType>::gotoEnd() throw (logic_error){
	if(this->cursor->next == NULL) {
		return;
	}
	if (this->head == NULL) {
		this->cursor = this->head;
	}else {
		while(true) {
			if (this->cursor->next != NULL) {
				this->cursor = this->cursor->next;
			}else {
				break;
			}
		}
	}
}

template <typename DataType>
bool List<DataType>::gotoNext() throw (logic_error)
{
	if (this->cursor->next == NULL) {
		return false;
	}
	else {
		this->cursor = this->cursor->next;
		return true;
	}
}

template <typename DataType>
bool List<DataType>::gotoPrior() throw (logic_error){
	if(this->cursor == this->head)
	{
		return false;
	}else{
		ListNode* tempNode = this->head;
		while(true)
		{
			if (tempNode->next != this->cursor) {
				tempNode = tempNode->next;
			}else
			{
				break;
			}
		}
		this->cursor = tempNode;
		return true;
	}
}

template <typename DataType>
DataType List<DataType>::getCursor() const throw (logic_error){
	return this->cursor->dataItem;
}





template <typename DataType>
void List<DataType>::moveToBeginning () throw (logic_error){
	if (this->cursor != this->head) {
		ListNode* tempNode = new ListNode(NULL, NULL);
		tempNode->dataItem = this->cursor->dataItem;
		this->remove();
		this->cursor = this->head;
		tempNode->next = this->cursor;
		this->head = tempNode;
		this->cursor = this->head;
	}else if(this->cursor == this->head && this->head != NULL) {
		return;
	}
	else {
		throw;
	}
}

template <typename DataType>
void List<DataType>::insertBefore(const DataType& newDataItem) throw (logic_error){
	if(this->cursor == NULL) {
		this->insert(newDataItem);
	}else if(this->cursor == this->head) {
		ListNode* tempNode = new ListNode(newDataItem, this->cursor);
		this->head = tempNode;

	}else {
		ListNode* tempNode = new ListNode(newDataItem, this->cursor);
		ListNode* counterNode = head;
		while(counterNode->next != this->cursor) {
			counterNode = counterNode->next;
		}
		counterNode->next = tempNode;
	}
}

#include "show5.cpp"

