#include <stdlib.h>
#include "LinkedList.h"

void List::append(unsigned char* data) {
	if (size == 0) {
		size++;
		FirstNode = new Node;
		FirstNode->nextnode = 0;
		FirstNode->prevnode = 0;
		FirstNode->data = data;
		LastNode = FirstNode;
		return;
		}
	size++;
	LastNode->nextnode = new Node;
	LastNode->nextnode->nextnode = 0;
	LastNode->nextnode->prevnode = 0;
	LastNode->nextnode->data = data;
	LastNode->nextnode->prevnode = LastNode;
	LastNode = LastNode->nextnode;
}

void List::clear() {
	Node* to_remove;
	while(FirstNode!=NULL){
		to_remove = FirstNode;
		FirstNode = to_remove->nextnode;
		delete[] to_remove->data;
		delete to_remove;
	}
	size = 0;
	LastNode = NULL;
}

Node* List::get_node(unsigned long long int position) {
	Node* node;
	unsigned long long int counter;
	if (position >= size) {
		return 0;
	}
	if (position < size / 2) {
		counter = 0;
		node = FirstNode;
		while (counter != position) {
			node = node->nextnode;
			counter++;
		}
	}
	else {
		counter = size - 1;
		node = LastNode;
		while (counter != position) {
			node = node->prevnode;
			counter--;
		}
	}
	return node;
}


unsigned char* List::get(unsigned long long int position) {
	Node* node = get_node(position);
	if (node == 0) {
		return 0;
	}
	return node->data;
}

void List::set(unsigned char* data, unsigned long long int position) {
	Node* node = get_node(position);
	if (node == 0) {
		return;
	}
	free(node->data);
	node->data = data;
}

void List::insert(unsigned char* data, unsigned long long int position) {
	if (position == size) {
		append(data);
		return;
	}
	Node* newnode;
	if (position == 0) {
		newnode = new Node;
		newnode->prevnode = 0;
		newnode->data = data;
		FirstNode->prevnode = newnode;
		newnode->nextnode = FirstNode;
		FirstNode = newnode;
		size++;
		return;
	}

	Node* node = get_node(position);
	if (node == 0) {
		return;
	}
	size++;
	newnode = new Node;//(Node*)malloc(sizeof(Node));
	newnode->data = data;

	node->prevnode->nextnode = newnode;
	newnode->prevnode = node->prevnode;
	node->prevnode = newnode;
	newnode->nextnode = node;

}

void List::remove(unsigned long long int position) {
	Node* node = get_node(position);
	if (node == 0) {
		return;
	}

	if (position < size-1) {
		node->nextnode->prevnode = node->prevnode;
		if (position == 0) {
			FirstNode = node->nextnode;
		}
	}
	if (position > 0) {
		node->prevnode->nextnode = node->nextnode;
		if (position == size-1) {
			LastNode = node->prevnode;
		}
	}
	size--;
	delete[] node->data;
	delete node;
	return;
}


List::~List() {
	clear();
}






