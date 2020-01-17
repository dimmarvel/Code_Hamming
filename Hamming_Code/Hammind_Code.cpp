#include<iostream>
#include<cstring>
#include<map>
void cout_arr(int *arr, int size) {
	for (int i = 1; i < size + 1; i++)
	{
		std::cout << " " << arr[i];
	}
}
enum PLUS_SIZE
{
	ONE = 1, TWO = 2, THREE = 4,
	FOUR = 8, FIVE = 16, SIX = 32,
	SEVEN = 64, EIGHT = 128, NINE = 256
};
PLUS_SIZE calc_size(PLUS_SIZE p_s, int index, int i = 0) {
	PLUS_SIZE pp_s = calc_size(p_s, index, i++);
	if (p_s < index) {
		pp_s = calc_size(p_s, index);
	}
	return pp_s;
}
int main() {
	setlocale(LC_ALL, "rus");
	char h[8] = { '0','1','0' ,'0' ,'0' ,'1','0', '0' };
	char a[8] = { '0','0','1' ,'1' ,'1' ,'1','0', '1' };
	int arr[9] =
	{
		1, 2, 4,
		8, 16, 32,
		64, 128, 256
	};
	PLUS_SIZE plus_size;
	int bit_sum = sizeof(h) + sizeof(a);
	std::cout << "Всего бит: " << bit_sum << std::endl;
	int index = bit_sum;
	int *arr = new int[index];
	std::map<std::string, double> some;
	some["suck"] = 2.1;
	std::cout << some["suck"];
	for (int i = 1; i < index + 1; i++) {
		arr[i] = i;
	}

	cout_arr(arr, index);

	plus_size = calc_size(plus_size, index);
	std::cout << plus_size;
	switch (plus_size) {
	case ONE:
		index++;
	case TWO:
		index += 2;
	case THREE:
		index += 3;
	case FOUR:
		index += 4;
	case FIVE:
		index += 5;
	case SIX:
		index += 6;
	case SEVEN:
		index += 7;
	case EIGHT:
		index += 8;
	case NINE:
		index += 9;
	}

	system("pause");
	return 0;
}