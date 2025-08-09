#include "cpp-linked-list.h"


// Node constructor implementation
Node::Node(int val) : data(val), next(nullptr) {
	// Debug output can be added here if needed
}

// LinkedList constructor
LinkedList::LinkedList() : head(new Node()), size(0) {
	cout << "�����ʼ����� (List initialized)" << endl;
}

// LinkedList destructor
LinkedList::~LinkedList() {
	clear();
	delete head;
	cout << "���������� (List destroyed)" << endl;
}

// Insert node at specified position
void LinkedList::insert(int pos, int val) {
	if (pos < 1 || pos > size + 1) {
		throw out_of_range("λ�ó�����Χ (Position out of range)");
	}

	Node* p = head;
	for (int i = 1; i < pos; ++i) {
		p = p->next;
	}

	Node* newNode = new Node(val);
	newNode->next = p->next;
	p->next = newNode;
	size++;
}

// Remove node at specified position
void LinkedList::remove(int pos) {
	if (pos < 1 || pos > size) {
		throw out_of_range("ɾ��λ����Ч (Invalid delete position)");
	}

	Node* p = head;
	for (int i = 1; i < pos; ++i) {
		p = p->next;
	}

	Node* delNode = p->next;
	p->next = delNode->next;
	delete delNode;
	size--;
}

// Find node with given value
Node* LinkedList::find(int val) const {
	Node* p = head->next;
	while (p) {
		if (p->data == val) return p;
		p = p->next;
	}
	return nullptr;
}

// Reverse the linked list
void LinkedList::reverse() {
	if (size < 2) return;

	Node* prev = nullptr;
	Node* curr = head->next;

	while (curr) {
		Node* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	head->next = prev;
}

// Clear all nodes except sentinel
void LinkedList::clear() {
	while (!isEmpty()) {
		remove(1);
	}
}

// Interactive list creation
void LinkedList::interactiveCreate() {
	clear();
	cout << "\n=== ����ʽ�������� (Interactive Creation) ===" << endl;
	cout << "����Ҫ�����Ľڵ��� (Enter node count): ";
	int n;
	cin >> n;

	Node* tail = head;
	for (int i = 0; i < n; ++i) {
		cout << "�ڵ�" << i + 1 << "��ֵ (Node " << i + 1 << " value): ";
		int val;
		cin >> val;

		Node* newNode = new Node(val);
		tail->next = newNode;
		tail = newNode;
		size++;

		cout << "��ǰ���� (Current list): ";
		printConnections();
	}
	cout << "��������ɣ��� " << size << " ���ڵ� (List created with " << size << " nodes)" << endl;
	printMemoryDetails();
}

// Interactive node insertion
void LinkedList::interactiveInsert() {
	cout << "\n=== ����ڵ� (Insert Node) ===" << endl;
	cout << "��ǰ������ (Current length): " << size << endl;
	cout << "�������λ�� (Enter position) (1-" << size + 1 << "): ";
	int pos;
	cin >> pos;

	cout << "����Ҫ�����ֵ (Enter value): ";
	int val;
	cin >> val;

	try {
		insert(pos, val);
		cout << "����ɹ��� (Insert success!) ������ (New list): ";
		printConnections();
	}
	catch (const exception& e) {
		cerr << "���� (Error): " << e.what() << endl;
	}
}

// Interactive node deletion
void LinkedList::interactiveRemove() {
	cout << "\n=== ɾ���ڵ� (Delete Node) ===" << endl;
	if (isEmpty()) {
		cout << "����Ϊ�գ��޷�ɾ�� (List is empty)" << endl;
		return;
	}

	cout << "��ǰ���� (Current list): ";
	printConnections();
	cout << "����ɾ��λ�� (Enter position) (1-" << size << "): ";
	int pos;
	cin >> pos;

	try {
		remove(pos);
		cout << "ɾ���ɹ��� (Delete success!) ������ (New list): ";
		printConnections();
	}
	catch (const exception& e) {
		cerr << "���� (Error): " << e.what() << endl;
	}
}

// Interactive node search
void LinkedList::interactiveFind() {
	cout << "\n=== ���ҽڵ� (Find Node) ===" << endl;
	cout << "����Ҫ���ҵ�ֵ (Enter value to find): ";
	int val;
	cin >> val;

	Node* found = find(val);
	if (found) {
		cout << "�ҵ��ڵ� (Found node) @" << found << " ֵΪ (value) " << found->data << endl;
	}
	else {
		cout << "δ�ҵ�ֵΪ (No node with value) " << val << " �Ľڵ�" << endl;
	}
}

// Print list traversal
void LinkedList::traverse() const {
	cout << "\n=== ������� (List Traversal) ===" << endl;
	if (isEmpty()) {
		cout << "����Ϊ�� (List is empty)" << endl;
		return;
	}

	printConnections();
	printMemoryDetails();
}

// Print list connections
void LinkedList::printConnections() const {
	Node* p = head->next;
	cout << "[Head]";
	while (p) {
		cout << " -> [" << p->data << "]";
		p = p->next;
	}
	cout << " -> nullptr" << endl;
}

// Print detailed memory information
void LinkedList::printMemoryDetails() const {
	cout << "��������������������������������������������������������������������" << endl;
	cout << "�� ������ϸ��Ϣ (List Details)    ��" << endl;
	cout << "��������������������������������������������������������������������" << endl;
	cout << "�� �ڵ��� (Node count): " << size << endl;

	Node* p = head->next;
	int count = 1;
	while (p) {
		cout << "��������������������������������������������������������������������" << endl;
		cout << "�� �ڵ�" << count++ << " @" << p << " (Node" << count - 1 << ") \n";
		cout << "�� ���� (Data): " << p->data << endl;
		cout << "�� ��һ�� (Next): " << p->next << endl;
		p = p->next;
	}
	cout << "��������������������������������������������������������������������" << endl;
}

// Check if list is empty
bool LinkedList::isEmpty() const {
	return size == 0;
}

// Get current list size
int LinkedList::getSize() const {
	return size;
}