#pragma once

struct Node {
	unsigned char* data;
	Node* prevnode = 0;
	Node* nextnode = 0;
};


class List {
private:
	unsigned long long int size = 0;
	Node* FirstNode = 0;
	Node* LastNode = 0;
	Node* get_node(unsigned long long int position);
public:
	unsigned long long int length() { return size; };
	void append(unsigned char* data);
	unsigned char* get(unsigned long long int position);//returns 0 if position >= length
	void set(unsigned char* data, unsigned long long int position);
	void clear();
	void insert(unsigned char* data, unsigned long long int position);
	void remove(unsigned long long int position);
	~List();
	
};
