#include "cpp-linked-list.h"


// Node constructor implementation
Node::Node(int val) : data(val), next(nullptr) {
	// Debug output can be added here if needed
}

// LinkedList constructor
LinkedList::LinkedList() : head(new Node()), size(0) {
	cout << "链表初始化完成 (List initialized)" << endl;
}

// LinkedList destructor
LinkedList::~LinkedList() {
	clear();
	delete head;
	cout << "链表已销毁 (List destroyed)" << endl;
}

// Insert node at specified position
void LinkedList::insert(int pos, int val) {
	if (pos < 1 || pos > size + 1) {
		throw out_of_range("位置超出范围 (Position out of range)");
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
		throw out_of_range("删除位置无效 (Invalid delete position)");
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
	cout << "\n=== 交互式创建链表 (Interactive Creation) ===" << endl;
	cout << "输入要创建的节点数 (Enter node count): ";
	int n;
	cin >> n;

	Node* tail = head;
	for (int i = 0; i < n; ++i) {
		cout << "节点" << i + 1 << "的值 (Node " << i + 1 << " value): ";
		int val;
		cin >> val;

		Node* newNode = new Node(val);
		tail->next = newNode;
		tail = newNode;
		size++;

		cout << "当前链表 (Current list): ";
		printConnections();
	}
	cout << "链表创建完成，共 " << size << " 个节点 (List created with " << size << " nodes)" << endl;
	printMemoryDetails();
}

// Interactive node insertion
void LinkedList::interactiveInsert() {
	cout << "\n=== 插入节点 (Insert Node) ===" << endl;
	cout << "当前链表长度 (Current length): " << size << endl;
	cout << "输入插入位置 (Enter position) (1-" << size + 1 << "): ";
	int pos;
	cin >> pos;

	cout << "输入要插入的值 (Enter value): ";
	int val;
	cin >> val;

	try {
		insert(pos, val);
		cout << "插入成功！ (Insert success!) 新链表 (New list): ";
		printConnections();
	}
	catch (const exception& e) {
		cerr << "错误 (Error): " << e.what() << endl;
	}
}

// Interactive node deletion
void LinkedList::interactiveRemove() {
	cout << "\n=== 删除节点 (Delete Node) ===" << endl;
	if (isEmpty()) {
		cout << "链表为空，无法删除 (List is empty)" << endl;
		return;
	}

	cout << "当前链表 (Current list): ";
	printConnections();
	cout << "输入删除位置 (Enter position) (1-" << size << "): ";
	int pos;
	cin >> pos;

	try {
		remove(pos);
		cout << "删除成功！ (Delete success!) 新链表 (New list): ";
		printConnections();
	}
	catch (const exception& e) {
		cerr << "错误 (Error): " << e.what() << endl;
	}
}

// Interactive node search
void LinkedList::interactiveFind() {
	cout << "\n=== 查找节点 (Find Node) ===" << endl;
	cout << "输入要查找的值 (Enter value to find): ";
	int val;
	cin >> val;

	Node* found = find(val);
	if (found) {
		cout << "找到节点 (Found node) @" << found << " 值为 (value) " << found->data << endl;
	}
	else {
		cout << "未找到值为 (No node with value) " << val << " 的节点" << endl;
	}
}

// Print list traversal
void LinkedList::traverse() const {
	cout << "\n=== 链表遍历 (List Traversal) ===" << endl;
	if (isEmpty()) {
		cout << "链表为空 (List is empty)" << endl;
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
	cout << "┌────────────────────────────────┐" << endl;
	cout << "│ 链表详细信息 (List Details)    │" << endl;
	cout << "├────────────────────────────────┤" << endl;
	cout << "│ 节点数 (Node count): " << size << endl;

	Node* p = head->next;
	int count = 1;
	while (p) {
		cout << "├────────────────────────────────┤" << endl;
		cout << "│ 节点" << count++ << " @" << p << " (Node" << count - 1 << ") \n";
		cout << "│ 数据 (Data): " << p->data << endl;
		cout << "│ 下一个 (Next): " << p->next << endl;
		p = p->next;
	}
	cout << "└────────────────────────────────┘" << endl;
}

// Check if list is empty
bool LinkedList::isEmpty() const {
	return size == 0;
}

// Get current list size
int LinkedList::getSize() const {
	return size;
}