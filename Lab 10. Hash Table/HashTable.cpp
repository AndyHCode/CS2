
#include "HashTable.h"

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(int initTableSize){
	tableSize = initTableSize;
	dataTable = new BSTree<DataType, KeyType>[tableSize];
}

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(const HashTable& other){
	tableSize = other.tableSize;
	dataTable = new BSTree<dataTable, KeyType>[tableSize];
	copyTable(other);
}

template <typename DataType, typename KeyType>
HashTable<DataType,KeyType>& HashTable<DataType, KeyType>::operator=(const HashTable& other){
	this->clear();
	tableSize = other.tableSize;
	dataTable = new BSTree<dataTable, KeyType>[tableSize];
	copyTable(other);
}

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::~HashTable(){
	clear();
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::insert(const DataType& newDataItem){
	unsigned int loc = DataType::hash(newDataItem.getKey()) % tableSize;
	dataTable[loc].insert(newDataItem);
}

template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::remove(const KeyType& deleteKey){
	unsigned int loc = DataType::hash(deleteKey) % tableSize;
	if(dataTable[loc].remove(deleteKey)) {
		return true;
	}
	return false;
}

template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::retrieve(const KeyType& searchKey, DataType& returnItem) const{
	unsigned int loc = DataType::hash(searchKey) % tableSize;
	if (dataTable[loc].retrieve(searchKey, returnItem)) {
		return true;
	}
	return false;
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::clear(){
	for(int i = 0; i < this->tableSize; i++) {
		dataTable[i].clear();
	}
}

template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::isEmpty() const{
	bool isEmptyBool = true;
	for (int i = 0; i < this->tableSize; i++) {
		if (!dataTable[i].isEmpty()) {
			isEmptyBool = false;
		}
	}
	return isEmptyBool;
}

#include "show10.cpp"

template <typename DataType, typename KeyType>
double HashTable<DataType, KeyType>::standardDeviation() const{
	int holder;
	int totalDataPoint = 0;
	long totalAvg[tableSize];
	long total;
	for(int i = 0; i < this->tableSize; i++) {
		holder = this->dataTable[i].getCount();
		totalDataPoint += holder;
		totalAvg[i] = holder;
	}
	for (int i = 0; i < this->tableSize; i++) {
		totalAvg[i] = totalAvg[i] / totalDataPoint;
		totalAvg[i] = pow(totalDataPoint - totalAvg[i], 2);
		
	}
	for (int i = 0; i < this->tableSize; i++) {
		total += totalAvg[i];
	}
	total = sqrt(total/(tableSize - 1));
	return total;
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::copyTable(const HashTable& source){
	for (int i = 0; i < this->tableSize; i++) {
		this->dataTable[i] = source[i];
	}
}
