#include "cpp-linked-list.h"

/**
 * @brief Display main menu
 */
void showMenu() {
	cout << "\n=== 链表操作系统 (VGE·Summer·2025) ===" << endl;
	cout << "1. 创建链表 (Create List)\n";
	cout << "2. 插入节点 (Insert Node)\n";
	cout << "3. 删除节点 (Delete Node)\n";
	cout << "4. 查找节点 (Find Node)\n";
	cout << "5. 反转链表 (Reverse List)\n";
	cout << "6. 显示链表 (Display List)\n";
	cout << "0. 退出 (Exit)\n";
	cout << "请选择操作 (Your choice): ";
}

int main() {
	LinkedList list;
	int choice = 0;

	do {
		showMenu();
		cin >> choice;

		switch (choice) {
		case 1: list.interactiveCreate(); break;
		case 2: list.interactiveInsert(); break;
		case 3: list.interactiveRemove(); break;
		case 4: list.interactiveFind(); break;
		case 5:
			list.reverse();
			cout << "链表已反转 (List reversed)" << endl;
			list.traverse();
			break;
		case 6: list.traverse(); break;
		case 0: cout << "程序结束 (Program ended)" << endl; break;
		default: cout << "无效选择 (Invalid choice)" << endl;
		}
	} while (choice != 0);

	return 0;
}