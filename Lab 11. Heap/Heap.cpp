
#include "Heap.h"

template < typename DataType, typename KeyType, typename Comparator >
Heap<DataType,KeyType,Comparator>::Heap ( int maxNumber = DEFAULT_MAX_HEAP_SIZE ){
	this->maxSize = maxNumber;
	this->size = 0;
	this->dataItems = new DataType[this->maxSize];
}

template < typename DataType, typename KeyType, typename Comparator >
Heap<DataType,KeyType,Comparator>::Heap ( const Heap& other ){
	this->maxSize = other.maxSize;
	this->size = other.size;
	this->dataItems = new DataType[this->maxSize];

	for (int i = 0; i < size; i++) {
		this->dataItems[i] = other.dataItems[i];
	}
}

template < typename DataType, typename KeyType, typename Comparator >
Heap<DataType,KeyType,Comparator>& Heap<DataType,KeyType,Comparator>::operator= ( const Heap& other ){
	delete this->dataItems;
	this->maxSize = other.maxSize;
	this->size = other.size;
	this->dataItems = new DataType[this->maxSize];

	for (int i = 0; i < size; i++) {
		this->dataItems[i] = other.dataItems[i];
	}
}

template < typename DataType, typename KeyType, typename Comparator >
Heap<DataType,KeyType,Comparator>::~Heap (){
	delete this->dataItems;
}

template < typename DataType, typename KeyType, typename Comparator >
void Heap<DataType,KeyType,Comparator>::insert ( const DataType &newDataItem ) throw ( logic_error ){
	if(this->isFull()) {
		throw;
	}
	this->dataItems[this->size] = newDataItem;
	int tempIndex = this->size;
	DataType tempDataItemHolder;
	this->size++;
	while (tempIndex != 0) {
		if(comparator(this->dataItems[tempIndex / 2].getPriority(), this->dataItems[tempIndex].getPriority())) {
			return;
		}
		tempDataItemHolder = this->dataItems[tempIndex];
		this->dataItems[tempIndex] = this->dataItems[tempIndex / 2];
		this->dataItems[tempIndex / 2] = tempDataItemHolder;
		tempIndex = tempIndex / 2;
	}
}

template < typename DataType, typename KeyType, typename Comparator >
DataType Heap<DataType,KeyType,Comparator>::remove () throw ( logic_error ){
	if (this->isEmpty()) {
		throw;
	}
	if(this->size == 1) {
		size--;
		return this->dataItems[0];
	}
	DataType temp = this->dataItems[0];
	this->dataItems[0] = this->dataItems[size - 1];
	size--;
	int tempIndex = 1;
	DataType tempDataItemHolder;
	while(true) {
		if (tempIndex * 2 <= this->size && comparator(this->dataItems[(tempIndex * 2) - 1].getPriority(), this->dataItems[tempIndex - 1].getPriority())) {
			tempDataItemHolder = this->dataItems[tempIndex - 1];
			this->dataItems[tempIndex - 1] = this->dataItems[(tempIndex * 2) - 1];
			this->dataItems[(tempIndex * 2) - 1] = tempDataItemHolder;
			tempIndex = tempIndex * 2;
		}else if (tempIndex * 2 + 1 <= this->size && comparator(this->dataItems[tempIndex * 2].getPriority(), this->dataItems[tempIndex - 1].getPriority())) {
			tempDataItemHolder = this->dataItems[tempIndex - 1];
			this->dataItems[tempIndex - 1] = this->dataItems[tempIndex * 2];
			this->dataItems[tempIndex * 2] = tempDataItemHolder;
			tempIndex = tempIndex * 2 + 1;
		}else {
			break;
		}
	}
	return temp;
}

template < typename DataType, typename KeyType, typename Comparator >
void Heap<DataType,KeyType,Comparator>::clear (){
	this->size = 0;
}

template < typename DataType, typename KeyType, typename Comparator >
bool Heap<DataType,KeyType,Comparator>::isEmpty () const{
	if(this->size == 0) {
		return true;
	}
	return false;
}

template < typename DataType, typename KeyType, typename Comparator >
bool Heap<DataType,KeyType,Comparator>::isFull () const{
	if(this->size == this->maxSize) {
		return true;
	}
	return false;
}

template<typename DataType, typename KeyType, typename Comparator>
void Heap<DataType, KeyType, Comparator>::writeLevels() const {
	int nextParentNode = 1;
	int currentNode = 1;
	while(currentNode <= this->size) {
		cout << this->dataItems[currentNode - 1].getPriority() << " ";
		if(nextParentNode == currentNode) {
			cout << endl;
			nextParentNode = nextParentNode * 2 + 1;
		}
		currentNode++;
	}
}
#include "show11.cpp"