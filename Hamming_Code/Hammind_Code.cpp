#include<iostream>
#include<cstring>
enum PLUS_SIZE;
PLUS_SIZE get_next_ps(PLUS_SIZE p_s);
void cout_arr(int *bit_array, int size, int zero_one = true) {
	//true - zero
	//false - one
	if (zero_one)
		for (int i = 1; i < size + 1; i++)
			std::cout << bit_array[i] << "  ";
	else
		for (int i = 0; i < size + 1; i++)
			if (i == 0)
				std::cout << bit_array[i] << " : ";
			else
				std::cout << bit_array[i] << " ";
	std::cout << std::endl;
}
void init_arr(int *bit_array, int size) {
	for (int i = 1; i < size + 1; i++) {
		bit_array[i] = i;
	}
}
enum PLUS_SIZE
{
	ONE = 1, TWO = 2, THREE = 4,
	FOUR = 8, FIVE = 16, SIX = 32,
	SEVEN = 64, EIGHT = 128, NINE = 256,
};
enum ex { X = 777 }EX;
int* create_bit_array(int **arr_bit, int size_h, int size_a, int size_numbers, int *arr_numbers, PLUS_SIZE p_s) {
	PLUS_SIZE fnc_p_c = { ONE };
	int size_char_bit_arr = size_h + size_a;
	int *char_bit_arr = new int[size_numbers + 1];
	int *bit_and_contrbit_arr = new int[size_numbers + 1];
	std::cout << "ha:\n" << "h - ";
	for (int i = 0; i < size_h; i++)
	{
		char_bit_arr[i] = arr_bit[0][i];
		std::cout << char_bit_arr[i];
	}
	std::cout << std::endl;
	std::cout << "a - ";
	for (int i = 0; i < size_a; i++)
	{
		char_bit_arr[size_h + i] = arr_bit[1][i];
		std::cout << char_bit_arr[size_h + i];
	}
	std::cout << std::endl;
	std::cout << "ha - ";
	for (int i = 0; i < size_char_bit_arr; i++)
	{
		std::cout << char_bit_arr[i];
	}
	int j = 0;
	std::cout << std::endl;

	for (int i = 1; i <= size_numbers; i++)
	{
		if (i == fnc_p_c) {
			bit_and_contrbit_arr[i] = 0;
			fnc_p_c = get_next_ps(fnc_p_c);
		}
		else {
			bit_and_contrbit_arr[i] = char_bit_arr[j++];
			if (i >= fnc_p_c)
				fnc_p_c = get_next_ps(fnc_p_c);
		}
	}

	std::cout << "\nbit_and_contrbit_arr - ";
	for (int i = 1; i <= size_numbers; i++)
	{
		std::cout << bit_and_contrbit_arr[i];
	}

	delete[]char_bit_arr;
	return bit_and_contrbit_arr;
}
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
void X_counter(int* arr_bit, int *x_array, PLUS_SIZE &p_s, int size_bit_arr) {
	//true - чет
	//false - не чет
	PLUS_SIZE pp_s = p_s;
	p_s = get_next_ps(p_s);
	EX = X;
	init_arr(x_array, size_bit_arr);
	int x_counter = 0;
		for (int i = pp_s; i <= size_bit_arr; i += (pp_s * 2)) {
			int counter = 0;
			int index = i;
			while (counter < pp_s && index <= size_bit_arr) {
				if (arr_bit[index] == 1) {
					x_counter++;
				}
				x_array[index] = EX;
				index++;
				counter++;
			}
		}
	if ((x_counter % 2) == 0) {
		x_array[0] = 0;
	}
	else {
		x_array[0] = 1;
	}
	cout_arr(x_array, size_bit_arr, false);

}
int main() {
	setlocale(LC_ALL, "rus");
	int h[8] = { 1,1,1,0,0,0,1,0 };
	int a[8] = { 1,0,0,1,1,0,0,1 };
	int size_bit_sum = (sizeof(h) / sizeof(int)) + (sizeof(a) / sizeof(int));
	int size_bit_h = sizeof(h) / sizeof(int);
	int size_bit_a = sizeof(a) / sizeof(int);
	int **word = new int*[2];
	word[0] = h;
	word[1] = a;
	int two_pow_bit_array[9] =
	{
		1, 2, 4,
		8, 16, 32,
		64, 128, 256
	};
	PLUS_SIZE plus_size = { ONE };

	std::cout << "Всего бит: " << size_bit_sum << std::endl;
	int index = size_bit_sum;
	int *bit_arr = new int[index];
	init_arr(bit_arr, index);
	cout_arr(bit_arr, index);

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

	int *BitContr_arr = new int[index];
	init_arr(BitContr_arr, index);
	cout_arr(BitContr_arr, index);

	int *bit_and_contr_bit = new int[index];
	bit_and_contr_bit = create_bit_array(word, size_bit_h, size_bit_a, index, BitContr_arr, plus_size);

	PLUS_SIZE X_p_s = { ONE };
	int chet_size = index + 1;
	std::cout << std::endl;
	int *chetnost1 = new int[chet_size];
	X_counter(bit_and_contr_bit, chetnost1, X_p_s, index);

	int *chetnost2 = new int[chet_size];
	X_counter(bit_and_contr_bit, chetnost2, X_p_s, index);

	int *chetnost4 = new int[chet_size];
	X_counter(bit_and_contr_bit, chetnost4, X_p_s, index);

	int *chetnost8 = new int[chet_size];
	X_counter(bit_and_contr_bit, chetnost8, X_p_s, index);

	int *chetnost16 = new int[chet_size];
	X_counter(bit_and_contr_bit, chetnost16, X_p_s, index);

	int user_even[5];
	for (int i = 0; i < 5; i++)
	{
		std::cin >> user_even[i];
	}

	if (user_even[0] == chetnost1[0])
		std::cout << user_even[0] << " - true;" << std::endl;
	else
		std::cout << user_even[0] << " - false, need(" <<chetnost1[0] << ')' << std::endl;
	
	if (user_even[1] == chetnost2[0])
		std::cout << user_even[1] << " - true;" << std::endl;
	else
		std::cout << user_even[1] << " - false, need(" <<chetnost2[0] << ')' << std::endl;
		
	if (user_even[2] == chetnost4[0])
		std::cout << user_even[2] << " - true;" << std::endl;
	else
		std::cout << user_even[2] << " - false, need(" <<chetnost4[0] << ')' << std::endl;
		
	if (user_even[3] == chetnost8[0])
		std::cout << user_even[3] << " - true;" << std::endl;
	else
		std::cout << user_even[3] << " - false, need(" <<chetnost8[0] << ')' << std::endl;
			
	if (user_even[4] == chetnost16[0])
		std::cout << user_even[4] << " - true;" << std::endl;
	else
		std::cout << user_even[4] << " - false, need(" <<chetnost16[0] << ')' << std::endl;


	delete[]chetnost1;
	delete[]chetnost2;
	delete[]chetnost4;
	delete[]chetnost8;
	delete[]chetnost16;

	system("pause");
	return 0;
}
