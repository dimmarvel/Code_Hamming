#include "coder.h"

int main() {
	setlocale(LC_ALL, "Rus");
	string answer("y");
	short work = 1;
	string text("ha");
	while (answer != "n") {
		
		cout
			<< "�������� ����� ������: \n"
			<< "1 - �������.\n"
			<< "2 - ������� �����.\n"
			<< "3 - ������� ����.\n"
			<< "4 - �������� ���������� ���.\n"
			<< "0 - �����.\n";
		//cin >> work;
		switch (work) {
		case 1:
			coder(text);
			break;
		case 2: 
			coder(text, work);
			break;
		case 3:
			coder(text, work); 
			break;
		case 4:
			coder(text, work);
			break;
		case 0:
			answer = "n";
			break;
		}
		decoder();
		cout << "\n����������?(y|n)\n";
		cin >> answer;
	}
	cout << endl;
	system("pause");
}