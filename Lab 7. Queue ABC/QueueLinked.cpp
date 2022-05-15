
#include "QueueLinked.h"

template <typename DataType>
QueueLinked<DataType>::QueueNode::QueueNode(const DataType& nodeData, QueueNode* nextPtr){
	this->dataItem = nodeData;
	this->next = nextPtr;
}

template <typename DataType>
QueueLinked<DataType>::QueueLinked(int maxNumber = Queue<DataType>::MAX_QUEUE_SIZE){
	this->front = NULL;
	this->back = NULL;
}

template <typename DataType>
QueueLinked<DataType>::QueueLinked(const QueueLinked& other){
	QueueNode *tempNode = other.front;
	while(tempNode != other.back) {
		this->enqueue(tempNode->dataItem);
		tempNode = tempNode->next;
	}
	this->enqueue(tempNode->dataItem);
}

template <typename DataType>
QueueLinked<DataType>& QueueLinked<DataType>::operator=(const QueueLinked& other){
	this->clear();
	QueueNode* tempNode = other.front;
	while (tempNode != other.back) {
		this->enqueue(tempNode->dataItem);
		tempNode = tempNode->next;
	}
	this->enqueue(tempNode->dataItem);
}

template <typename DataType>
QueueLinked<DataType>::~QueueLinked(){
	clear();
}

template <typename DataType>
void QueueLinked<DataType>::enqueue(const DataType& newDataItem) throw (logic_error){
	QueueNode *tempNode = new QueueNode(newDataItem, NULL);
	if(this->front == NULL) {
		this->front = tempNode;
		this->back = tempNode;
		return;
	}
	this->back->next = tempNode;
	this->back = this->back->next;
}

template <typename DataType>
DataType QueueLinked<DataType>::dequeue() throw (logic_error){
	if(this->front == NULL) {
		throw;
	}
	QueueNode *tempNode = this->front;
	DataType temp = this->front->dataItem;
	this->front = this->front->next;
	delete tempNode;
	return temp;
}

template <typename DataType>
void QueueLinked<DataType>::clear(){
	while(this->back != this->front) {
		dequeue();
	}
	dequeue();
}

template <typename DataType>
bool QueueLinked<DataType>::isEmpty() const{
	if(this->front == NULL) {
		return true;
	}
	return false;
}

template <typename DataType>
bool QueueLinked<DataType>::isFull() const{
	return false;
}

template <typename DataType>
void QueueLinked<DataType>::putFront(const DataType& newDataItem) throw (logic_error){
	if(this->front == NULL) {
		QueueNode* tempNode = new QueueNode(newDataItem, this->front);
		this->front = tempNode;
		this->back = this->front;
		return;
	}
	QueueNode* tempNode = new QueueNode(newDataItem, this->front);
	this->front = tempNode;
}

template <typename DataType>
DataType QueueLinked<DataType>::getRear() throw (logic_error){
	if(this->front == NULL) {
		throw;
	}
	if(this->front == this->back) {
		DataType tempData = this->front->dataItem;
		this->clear();
		return tempData;
	}
	DataType tempData = this->back->dataItem;
	QueueNode *tempNode = this->front;
	while(tempNode->next != this->back) {
		tempNode = tempNode->next;
	}
	delete this->back;
	this->back = tempNode;
	tempNode->next = NULL;
	return tempData;
}

template <typename DataType>
int QueueLinked<DataType>::getLength() const{
	int count = 1;
	if(this->front == NULL) {
		return 0;
	}
	QueueNode *tempNode = this->front;
	while(tempNode != this->back) {
		tempNode = tempNode->next;
		count++;
	}
	return count;
}

template <typename DataType>
void QueueLinked<DataType>::showStructure() const
{
    QueueNode *p;   // Iterates through the queue

    if ( isEmpty() )
	cout << "Empty queue" << endl;
    else
    {
	cout << "Front\t";
	for ( p = front ; p != 0 ; p = p->next )
	{
	    if( p == front ) 
	    {
		cout << '[' << p->dataItem << "] ";
	    }
	    else
	    {
		cout << p->dataItem << " ";
	    }
	}
	cout << "\trear" << endl;
    }
}