#include "head.hpp"


int main() {
	system("cls");
	init();
	if (!banker()) return 0;

	display();  // ��ʾ��ǰ��Դ
	while (isExit() == false) {
		bool ret = input();    // ����

		if (ret)
			banker();   // ִ�����м��㷨

		display();  // ��ʾ��ǰ��Դ
		cout << "����������� ~~~~~~~~~~~" << endl;
		fflush(stdout);
		getchar();
	}


	return 0;
}

