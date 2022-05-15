
#include "QueueArray.h"

template <typename DataType>
QueueArray<DataType>::QueueArray(int maxNumber){
    this->maxSize = maxNumber;
    this->front = -1;
    this->back = -1;
    this->dataItems = new DataType[maxSize];
}

template <typename DataType>
QueueArray<DataType>::QueueArray(const QueueArray& other){
    this->maxSize = other.maxSize;
    this->front = other.front;
    this->back = other.back;
    this->dataItems = new DataType[maxSize];
    for (int i = 0; i < this->maxSize; i++) {
        this->dataItems[i] = other.dataItems[i];
    }
}

template <typename DataType>
QueueArray<DataType>& QueueArray<DataType>::operator=(const QueueArray& other){
    if(this->maxSize < other.maxSize) {
        delete [] this->dataItems;
        this(other);
        return *this;
    }
    int temp = other.front;
    for(int i = 0; i < other.maxSize; i++ ) {
        this->dataItems[i] = other.dataItems[temp];
        temp = ((temp + 1) % other.maxSize);
    }
    this->front = 0;
    this->back = other.maxSize - 1;
}

template <typename DataType>
QueueArray<DataType>::~QueueArray(){
    delete[] this->dataItems;
}

template <typename DataType>
void QueueArray<DataType>::enqueue(const DataType& newDataItem) throw (logic_error){
    if ((this->back + 1) % maxSize == this->front) {
        throw;
    }
    this->back = ((this->back + 1) % maxSize);
    this->dataItems[this->back] = newDataItem;
    if (this->front == -1) {
        this->front = this->back;
    }


}

template <typename DataType>
DataType QueueArray<DataType>::dequeue() throw (logic_error){
    if(this->front == -1) {
        throw;
    }
    DataType tempData = this->dataItems[this->front];
    this->front = ((this->front + 1) % maxSize);
    if(((this->back + 1) % maxSize) == this->front) {
        this->front = -1;
    }
    return tempData;
}

template <typename DataType>
void QueueArray<DataType>::clear(){
    this->front = -1;
    this->back = -1;
}

template <typename DataType>
bool QueueArray<DataType>::isEmpty() const{
	if(this->front == this->back) {
        return true;
	}
    return false;
}

template <typename DataType>
bool QueueArray<DataType>::isFull() const{
	if (this->front == (this->back + 1) % this->maxSize) {
		return true;
	}
	return false;
}

template <typename DataType>
void QueueArray<DataType>::putFront(const DataType& newDataItem) throw (logic_error){
    if(this->getLength() == this->maxSize) {
        throw;
    }
    if(this->front == -1) {
        this->enqueue(newDataItem);
    }else if(this->front == 0) {
        this->front = maxSize - 1;
        this->dataItems[this->front] = newDataItem;
    }else {
        this->front = this->front - 1;
        this->dataItems[this->front] = newDataItem;
    }
}

template <typename DataType>
DataType QueueArray<DataType>::getRear() throw (logic_error){
    if(this->front == -1) {
        throw;
    }
    if(this->back == 0 && this->front != this->back) {
        this->back = this->maxSize - 1;
        return this->dataItems[0];
    }
    if(this->back == this->front) {
        return this->dequeue();
    }
    DataType temp;
    temp = this->dataItems[this->back];
    this->back = this->back - 1;
    return temp;
}

template <typename DataType>
int QueueArray<DataType>::getLength() const{
	if(this->front == -1) {
        return 0;
	}
    if(this->front == this->back) {
	    return 1;
    }
    if(this->front < this->back) {
        return (this->back - this->front) + 1;
    }
    int temp = this->maxSize - this->front;
    temp = temp + this->back + 1;
    return temp;
}

//--------------------------------------------------------------------

template <typename DataType>
void QueueArray<DataType>::showStructure() const 
// Array implementation. Outputs the data items in a queue. If the
// queue is empty, outputs "Empty queue". This operation is intended
// for testing and debugging purposes only.

{
    int j;   // Loop counter

    if ( front == -1)
       cout << "Empty queue" << endl;
    else
    {
       cout << "Front = " << front << "  Back = " << back << endl;
       for ( j = 0 ; j < maxSize ; j++ )
           cout << j << "\t";
       cout << endl;
       if ( back >= front )
          for ( j = 0 ; j < maxSize ; j++ )
              if ( ( j >= front ) && ( j <= back ) )
                 cout << dataItems[j] << "\t";
              else
                 cout << " \t";
       else
          for ( j = 0 ; j < maxSize ; j++ )
              if ( ( j >= front ) || ( j <= back ) )
                 cout << dataItems[j] << "\t";
              else
                 cout << " \t";
       cout << endl;
    }
}