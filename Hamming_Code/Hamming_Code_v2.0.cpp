#include "coder.h"

int main() {
	setlocale(LC_ALL, "Rus");
	string answer("y");
	short work = 1;
	string text("ha");
	while (answer != "n") {
		
		cout
			<< "Выберите режим работы: \n"
			<< "1 - Обычный.\n"
			<< "2 - Вводить текст.\n"
			<< "3 - Вводить биты.\n"
			<< "4 - Проверка контольных бит.\n"
			<< "0 - Выход.\n";
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
		cout << "\nПродолжить?(y|n)\n";
		cin >> answer;
	}
	cout << endl;
	system("pause");
}