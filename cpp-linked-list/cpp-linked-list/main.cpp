#include "cpp-linked-list.h"

/**
 * @brief Display main menu
 */
void showMenu() {
	cout << "\n=== �������ϵͳ (VGE��Summer��2025) ===" << endl;
	cout << "1. �������� (Create List)\n";
	cout << "2. ����ڵ� (Insert Node)\n";
	cout << "3. ɾ���ڵ� (Delete Node)\n";
	cout << "4. ���ҽڵ� (Find Node)\n";
	cout << "5. ��ת���� (Reverse List)\n";
	cout << "6. ��ʾ���� (Display List)\n";
	cout << "0. �˳� (Exit)\n";
	cout << "��ѡ����� (Your choice): ";
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
			cout << "�����ѷ�ת (List reversed)" << endl;
			list.traverse();
			break;
		case 6: list.traverse(); break;
		case 0: cout << "������� (Program ended)" << endl; break;
		default: cout << "��Чѡ�� (Invalid choice)" << endl;
		}
	} while (choice != 0);

	return 0;
}