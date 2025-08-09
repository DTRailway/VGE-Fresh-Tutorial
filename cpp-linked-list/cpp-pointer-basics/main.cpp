#include "cpp-pointer-basis.h"

int main() {
	int choice = 0;
	int sub_choice = 0;

	while (true) {
		cout << "\n=== VGE小组C++基础演示 ===" << endl;
		cout << "1. 基础指针演示\n"
			<< "2. 参数传递方式\n"
			<< "3. 多返回值实现\n"
			<< "4. 指针错误案例\n"
			<< "0. 退出\n"
			<< "请输入主选项: ";

		cin >> choice;

		if (choice == 0) break;

		switch (choice) {
		case 1: // 基础演示
			PointerDemo();
			break;

		case 2: { // 参数传递细分
			cout << "\n=== 参数传递方式 ===\n"
				<< "2-1. 值传递\n"
				<< "2-2. 指针传递\n"
				<< "2-3. 引用传递\n"
				<< "2-4. 综合对比\n"
				<< "0. 返回\n"
				<< "请选择子选项: ";

			cin >> sub_choice;
			int val = 10; // 统一测试值

			switch (sub_choice) {
			case 1:
				cout << "\n[值传递演示]\n原值: " << val << endl;
				ModifyValueByValue(val);
				cout << "调用后原值: " << val << endl;
				break;
			case 2:
				cout << "\n[指针传递演示]\n原值: " << val << endl;
				ModifyValueByPointer(&val);
				cout << "调用后原值: " << val << endl;
				break;
			case 3:
				cout << "\n[引用传递演示]\n原值: " << val << endl;
				ModifyValueByReference(val);
				cout << "调用后原值: " << val << endl;
				break;
			case 4:
				CrossModifyDemo();
				break;
			}
			break;
		}

		case 3: { // 多返回值
			cout << "\n=== 多返回值实现 ===\n";
			int a, b;
			if (ReturnByPointer(&a, &b)) {
				cout << "获取结果: " << a << ", " << b << endl;
			}
			break;
		}

		case 4: { // 错误案例细分
			cout << "\n=== 指针错误案例 ===\n"
				<< "4-1. 野指针\n"
				<< "4-2. 悬垂指针\n"
				<< "4-3. 内存泄漏\n"
				<< "0. 返回\n"
				<< "请选择子选项: ";

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

	cout << "演示结束" << endl;
	return 0;
}