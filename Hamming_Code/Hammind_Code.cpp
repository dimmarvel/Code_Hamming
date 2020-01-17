#include<iostream>
#include<cstring>
#include<map>
void cout_arr(int *arr, int size) {
	for (int i = 1; i < size + 1; i++)
	{
		std::cout << " " << arr[i];
	}
	std::cout << std::endl;
}
void init_arr(int *arr, int size) {
	for (int i = 1; i < size + 1; i++) {
		arr[i] = i;
	}
}
enum PLUS_SIZE
{
	ONE = 1, TWO = 2, THREE = 4,
	FOUR = 8, FIVE = 16, SIX = 32,
	SEVEN = 64, EIGHT = 128, NINE = 256,
};
PLUS_SIZE get_next_ps(PLUS_SIZE p_s) {
	return static_cast<PLUS_SIZE>(static_cast<int>(p_s) * 2);
}
PLUS_SIZE calc_size(PLUS_SIZE p_s, int index, int i = 0) {
	if (p_s < index) {
		p_s = get_next_ps(p_s);
		p_s = calc_size(p_s, index);
	}
	return p_s;
}
int main() {
	setlocale(LC_ALL, "rus");
	char h[8] = { '0','1','0' ,'0' ,'0' ,'1','0', '0' };
	char a[8] = { '0','0','1' ,'1' ,'1' ,'1','0', '1' };
	int two_pow_arr[9] =
	{
		1, 2, 4,
		8, 16, 32,
		64, 128, 256
	};
	PLUS_SIZE plus_size = {ONE};
	int bit_sum = sizeof(h) + sizeof(a);
	std::cout << "Всего бит: " << bit_sum << std::endl;
	int index = bit_sum;
	int *arr = new int[index];
	init_arr(arr, index);
	cout_arr(arr, index);

	plus_size = calc_size(plus_size, index);
	switch (plus_size) {
	case ONE:
		std::cout << "Всего битов: " << index << " + 1 контр. бит = ";
		index++;
		std::cout << index << std::endl;
		break;
	case TWO:
		std::cout << "Всего битов: " << index << " + 2 контр. бит = ";
		index += 2;
		std::cout << index << std::endl;
		break;
	case THREE:
		std::cout << "Всего битов: " << index << " + 3 контр. бит = ";
		index += 3;
		std::cout << index << std::endl;
		break;
	case FOUR:
		std::cout << "Всего битов: " << index << " + 4 контр. бит = ";
		index += 4;
		std::cout << index << std::endl;
		break;
	case FIVE:
		std::cout << "Всего битов: " << index << " + 5 контр. бит = ";
		index += 5;
		std::cout << index << std::endl;
		break;
	case SIX:
		std::cout << "Всего битов: " << index << " + 6 контр. бит = ";
		index += 6;
		std::cout << index << std::endl;
		break;
	case SEVEN:
		std::cout << "Всего битов: " << index << " + 7 контр. бит = ";
		index += 7;
		std::cout << index << std::endl;
		break;
	case EIGHT:
		std::cout << "Всего битов: " << index << " + 8 контр. бит = ";
		index += 8;
		std::cout << index << std::endl;
		break;
	case NINE:
		std::cout << "Всего битов: " << index << " + 9 контр. бит = ";
		index += 9;
		std::cout << index << std::endl;
		break;
	}
	int *arr2 = new int[index];
	init_arr(arr2, index);
	cout_arr(arr2, index);
	system("pause");
	return 0;
}