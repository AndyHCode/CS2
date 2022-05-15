
#include "ListArray.h"

template < typename DataType >
List<DataType>::List ( int maxNumber){
	this->maxSize = maxNumber;
	this->size = 0;
	this->cursor = -1;
	this->dataItems = new DataType[maxSize];
}

template < typename DataType >
List<DataType>::List ( const List& source ){
	this->maxSize = source.maxSize;
	this->size = source.size;
	this->cursor = source.cursor;
	this->dataItems = new DataType[maxSize];
	for (int i = 0; i < maxSize; i++) {
		this->dataItems[i] = source.dataItems[i];
	}
}
    
template < typename DataType >
List<DataType>& List<DataType>::operator= ( const List& source ){
	if (source.size > this->maxSize) {
		delete this->dataItems;
		this->dataItems = new DataType[source.maxSize];
		this->maxSize = source.maxSize;
		this->cursor = source.cursor;
		this->size = 0;
		for (int i = 0; i < source.size; i++) {
			dataItems[i] = source.dataItems[i];
			this->size++;
		}
	}
	else {
		this->clear();
		for (int i = 0; i < source.size; i++) {
			this->dataItems[i] = source.dataItems[i];
		}
		this->size = source.size;
	}
	return *this;
}

template < typename DataType > 
List<DataType>::~List (){

}

template < typename DataType >
void List<DataType>::insert ( const DataType& newDataItem ) throw ( logic_error ){
	if (this->size == this->maxSize) {
		throw;
	}
	if (this->cursor == -1) {
		this->cursor++;
		this->dataItems[cursor] = newDataItem;
		this->size++;
	}
	else {
		for (int i = maxSize - 2; i > cursor - 1; i--) {
			this->dataItems[i + 1] = this->dataItems[i];
		}
		this->cursor++;
		this->dataItems[cursor] = newDataItem;
		this->size++;
	}

}

template < typename DataType >
void List<DataType>::remove () throw ( logic_error ){
	if (this->size == 0) {
		throw;
	}
	for (int i = cursor; i < this->size - 1; i++) {
		this->dataItems[i] = this->dataItems[i+1];
	}
	this->dataItems[size - 1] = NULL;
	this->size--;
	if (cursor != 0) {
		this->cursor--;
	}
	if (size == 0) {
		cursor == -1;
	}
}

template < typename DataType >
void List<DataType>::replace ( const DataType& newDataItem )
	throw ( logic_error )
{
	if (this->size == 0) {
		throw;
	}
	this->dataItems[cursor] = newDataItem;
}

template < typename DataType >
void List<DataType>::clear ()
{
	for (int i = 0; i < this->maxSize; i++) {
		this->dataItems[i] = NULL;
	}
	this->cursor = -1;
	this->size = 0;
}

template < typename DataType >
bool List<DataType>::isEmpty () const
{
	if (this->size == 0) {
		return true;
	}
	return false;
}

template < typename DataType >
bool List<DataType>::isFull () const
{
	if (this->size == this->maxSize) {
		return true;
	}
	return false;
}

template < typename DataType >
void List<DataType>::gotoBeginning () throw ( logic_error ){
	if (this->size == 0) {
		throw;
	}
	this->cursor = 0;
}

template < typename DataType >
void List<DataType>::gotoEnd () throw ( logic_error ){
	if (this->size == 0) {
		throw;
	}
	this->cursor = this->size - 1;


}

template < typename DataType >
bool List<DataType>::gotoNext () throw ( logic_error ){
	if (this->cursor == this->size - 1) {
		return false;
	}
	this->cursor++;
	return true;
}

template < typename DataType >
bool List<DataType>::gotoPrior () throw ( logic_error ){
	if (this->cursor < 1) {
		return false;
	}
	this->cursor--;
	return true;
}

template < typename DataType >
DataType List<DataType>::getCursor () const
        throw ( logic_error )
{
	DataType t;
	if (cursor == -1) {
		throw;
	}
	t = this->dataItems[cursor];
	return t;
}

#include "show3.cpp"

template < typename DataType >
void List<DataType>::moveToNth ( int n ) throw ( logic_error ){
	if (n < this->size && n > -1) {
		this->cursor = n;
	}
	else {
		throw;
	}




}

template < typename DataType >
bool List<DataType>::find ( const DataType& searchDataItem ) throw ( logic_error ){
	if (this->size == 0) {
		throw;
	}
	for (int i = 0; i < size; i++) {
		if (this->dataItems[i] == searchDataItem) {
			return true;
		}
	}
	return false;
}