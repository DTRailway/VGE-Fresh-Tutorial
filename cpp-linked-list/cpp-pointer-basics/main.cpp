#include "cpp-pointer-basis.h"

int main() {
	int choice = 0;
	int sub_choice = 0;

	while (true) {
		cout << "\n=== VGEС��C++������ʾ ===" << endl;
		cout << "1. ����ָ����ʾ\n"
			<< "2. �������ݷ�ʽ\n"
			<< "3. �෵��ֵʵ��\n"
			<< "4. ָ�������\n"
			<< "0. �˳�\n"
			<< "��������ѡ��: ";

		cin >> choice;

		if (choice == 0) break;

		switch (choice) {
		case 1: // ������ʾ
			PointerDemo();
			break;

		case 2: { // ��������ϸ��
			cout << "\n=== �������ݷ�ʽ ===\n"
				<< "2-1. ֵ����\n"
				<< "2-2. ָ�봫��\n"
				<< "2-3. ���ô���\n"
				<< "2-4. �ۺ϶Ա�\n"
				<< "0. ����\n"
				<< "��ѡ����ѡ��: ";

			cin >> sub_choice;
			int val = 10; // ͳһ����ֵ

			switch (sub_choice) {
			case 1:
				cout << "\n[ֵ������ʾ]\nԭֵ: " << val << endl;
				ModifyValueByValue(val);
				cout << "���ú�ԭֵ: " << val << endl;
				break;
			case 2:
				cout << "\n[ָ�봫����ʾ]\nԭֵ: " << val << endl;
				ModifyValueByPointer(&val);
				cout << "���ú�ԭֵ: " << val << endl;
				break;
			case 3:
				cout << "\n[���ô�����ʾ]\nԭֵ: " << val << endl;
				ModifyValueByReference(val);
				cout << "���ú�ԭֵ: " << val << endl;
				break;
			case 4:
				CrossModifyDemo();
				break;
			}
			break;
		}

		case 3: { // �෵��ֵ
			cout << "\n=== �෵��ֵʵ�� ===\n";
			int a, b;
			if (ReturnByPointer(&a, &b)) {
				cout << "��ȡ���: " << a << ", " << b << endl;
			}
			break;
		}

		case 4: { // ������ϸ��
			cout << "\n=== ָ������� ===\n"
				<< "4-1. Ұָ��\n"
				<< "4-2. ����ָ��\n"
				<< "4-3. �ڴ�й©\n"
				<< "0. ����\n"
				<< "��ѡ����ѡ��: ";

			cin >> sub_choice;

			switch (sub_choice) {
			case 1:
				WildPointerDemo();
				break;
			case 2:
				DanglingPointerDemo();
				break;
			case 3:
				MemoryLeakDemo();
				break;
			}
			break;
		}
		}
	}

	cout << "��ʾ����" << endl;
	return 0;
}