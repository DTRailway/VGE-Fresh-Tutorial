#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

// Node structure for linked list
struct Node {
	int data;       // Data field
	Node* next;     // Pointer to next node
	Node(int val = 0);  // Constructor
};

/**
 * @brief Linked list class with interactive operations
 * @note Uses sentinel node (head node doesn't store actual data)
 */
class LinkedList {
private:
	Node* head;     // Sentinel node
	int size;       // Current list size

	// Helper methods
	void printConnections() const;
	void printMemoryDetails() const;

public:
	// Constructor & Destructor
	LinkedList();
	~LinkedList();

	// Core operations
	void insert(int pos, int val);
	void remove(int pos);
	Node* find(int val) const;
	void reverse();
	void clear();

	// Interactive operations
	void interactiveCreate();
	void interactiveInsert();
	void interactiveRemove();
	void interactiveFind();
	void traverse() const;

	// Accessors
	bool isEmpty() const;
	int getSize() const;
};