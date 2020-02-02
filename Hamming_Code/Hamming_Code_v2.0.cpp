#include "coder.h"

int main() {
	string text_array("qwe");
	cin >> text_array;
	char a[4] = "abc";
	vector<vector<int>> arr2(text_array.size(), vector <int>(8));
	arr2 = take_char_bit_array(text_array);
	system("pause");
}