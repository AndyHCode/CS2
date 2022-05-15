//Andy Huang
#include "Text.h"

Text::Text ( const char *charSeq ){
	this->bufferSize = strlen(charSeq) + 1;
	this->buffer = new char[bufferSize];
	strcpy(this->buffer, charSeq);
}

Text::Text ( const Text &other ){
	this->bufferSize = other.bufferSize;
	buffer = new char[bufferSize];
	strcpy(this->buffer, other.buffer);
	
}

void Text::operator = ( const Text &other ){
	if (this->bufferSize < other.bufferSize) {
		this->bufferSize = other.bufferSize;
		delete[] buffer;
		this->buffer = new char[this->bufferSize];
	}
	strcpy(this->buffer, other.buffer);
}

Text::~Text (){
}

int Text::getLength () const{
	return strlen(this->buffer) + 1;
}

char Text::operator [] ( int n ) const{
	if (n <= (strlen(this->buffer)) && n >= 0) {
		return buffer[n];
	}
	return '\0';
}

void Text::clear (){
	strcpy(this->buffer, "");
}

void Text::showStructure () const{
	cout << buffer << endl;
}

Text Text::toUpper( ) const{
	Text temp(this->buffer);
	for (int i = 0; i < temp.getLength() - 1; i++) {
		temp.buffer[i] = toupper(temp.buffer[i]);
	}
	return temp;
}

Text Text::toLower( ) const{
	Text temp(this->buffer);
	for (int i = 0; i < temp.getLength(); i++) {
		temp.buffer[i] = tolower(temp.buffer[i]);
	}
	return temp;
}

bool Text::operator == ( const Text& other ) const{
	int holder = strcmp(this->buffer, other.buffer);
	if (holder == 0) {
		return true;
	}
	return false;
}

bool Text::operator <  ( const Text& other ) const{
	int holder = strcmp(this->buffer, other.buffer);
	if (holder < 0) {
		return true;
	}
	return false;
}

bool Text::operator >  ( const Text& other ) const{
	int holder = strcmp(this->buffer, other.buffer);
	if (holder > 0) {
		return true;
	}
	return false;
}
