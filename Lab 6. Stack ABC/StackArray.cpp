
#include "StackArray.h"

template <typename DataType>
StackArray<DataType>::StackArray(int maxNumber){
	this->top = -1;
	this->maxSize = maxNumber;
	this->dataItems = new DataType[maxNumber];
}

template <typename DataType>
StackArray<DataType>::StackArray(const StackArray& other){
	this->maxSize = other.maxSize;
	this->dataItems = new DataType[maxSize];
	for(int i = 0; i < other.top + 1; i++) {
		this->dataItems[i] = other.dataItems[i];
	}
	this->top = other.top;
}

template <typename DataType>
StackArray<DataType>& StackArray<DataType>::operator=(const StackArray& other){
	if(this == &other) {
		return *this;
	}
	if(this->maxSize < other.top + 1) {
		delete this->dataItems;
		this->dataItems = new DataType[other.top + 1];
		this->top = -1;
		this->maxSize = other.top + 1;
		for (int i = 0; i < other.top + 1; i++) {
			this->dataItems[i] = other.dataItems[i];
			this->top = this->top + 1;
		}
		return *this;
	}
	for (int i = 0; i < other.top + 1; i++)
		this->dataItems[i] = other.dataItems[i];
	this->top = other.top;
	return *this;
}

template <typename DataType>
StackArray<DataType>::~StackArray(){
	delete this->dataItems;
}

template <typename DataType>
void StackArray<DataType>::push(const DataType& newDataItem) throw (logic_error){
	if(this->top + 1 == this->maxSize) {
		throw;
	}
	this->top = this->top + 1;
	this->dataItems[this->top] = newDataItem;
}

template <typename DataType>
DataType StackArray<DataType>::pop() throw (logic_error){
	if(this->top == -1) {
		throw;
	}
	this->top = this->top - 1;
	return this->dataItems[this->top + 1];
}

template <typename DataType>
void StackArray<DataType>::clear(){
	this->top = -1;
}

template <typename DataType>
bool StackArray<DataType>::isEmpty() const{
	if(this->top == -1) {
		return true;
	}
	return false;
}

template <typename DataType>
bool StackArray<DataType>::isFull() const{
	if(this->maxSize == this->top + 1) {
		return true;
	}
	return false;
}

template <typename DataType>
void StackArray<DataType>::showStructure() const 

// Array implementation. Outputs the data items in a stack. If the
// stack is empty, outputs "Empty stack". This operation is intended
// for testing and debugging purposes only.

{
    if( isEmpty() ) {
	cout << "Empty stack." << endl;
    }
    else {
	int j;
	cout << "Top = " << top << endl;
	for ( j = 0 ; j < maxSize ; j++ )
	    cout << j << "\t";
	cout << endl;
	for ( j = 0 ; j <= top  ; j++ )
	{
	    if( j == top )
	    {
	        cout << '[' << dataItems[j] << ']'<< "\t"; // Identify top
	    }
	    else
	    {
		cout << dataItems[j] << "\t";
	    }
	}
	cout << endl;
    }
    cout << endl;
}