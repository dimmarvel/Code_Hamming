#include"coder.h"
#define TEST
int sum_bit = 0;
int how_ContrBitNeed = 0;
vector<int> contr_bit_arr;
vector<int> control_bit;
vector<vector<int>> X_arr;
vector<vector<int>> char_and_bit_array;

static PLUS_SIZE get_next_ps(PLUS_SIZE p_s, bool minusMood = false) {
	if (minusMood)
		return static_cast<PLUS_SIZE>(static_cast<int>(p_s) / 2);
	else
		return static_cast<PLUS_SIZE>(static_cast<int>(p_s) * 2);
}

static PLUS_SIZE calc_size(PLUS_SIZE p_s, int sum_bit, int *how_ContrBitNeed = NULL) {
	if (p_s < sum_bit) {
		p_s = get_next_ps(p_s);
		(*how_ContrBitNeed == 0) ? *how_ContrBitNeed += 2 : *how_ContrBitNeed += 1;
		p_s = calc_size(p_s, sum_bit, how_ContrBitNeed);
	}
	if (p_s > sum_bit)
		p_s = get_next_ps(p_s, true);
	return p_s;
}

static int calc_sum_bit(vector<vector<int>> char_bit_array) {
	return char_bit_array.size() * 8;
}

static vector<int> take_char_bit(char a)
{
	vector<int> bit_arr(8);
	int j = 7;
	for (int i = 0; i <= (8 * sizeof(a) - 1); i++)
	{
		bit_arr[j] = ((a >> i) & 1);
		j--;
	}
	return bit_arr;
}

static vector<vector<int>> take_char_bit_array(string stroke) {
	vector<vector<int>> arr(stroke.size(), vector <int>(8));
	for (int i = 0; i < stroke.size(); i++)
		arr[i] = take_char_bit(stroke[i]);
#ifdef TEST
	for (int i = 0; i < stroke.size(); i++)
	{
		cout << stroke[i] << " - ";
		for (int j = 0; j < 8; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << stroke << " - ";
	for (int i = 0; i < stroke.size(); i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << arr[i][j];
		}
	}
#endif
	return arr;
}

static vector<int> create_bit_array(vector<vector<int>>arr_bit, PLUS_SIZE p_s, int size_bit_pluse_contrBit) {
	PLUS_SIZE fnc_p_c = { ONE };
	vector<int> contr_bit_arr(size_bit_pluse_contrBit);
	int size_char_bit = arr_bit.size();
	int j = 0, //итерация по буквам [j][]
		k = 0 //биты буквы [][k]
		;
	for (int i = 1; i <= size_bit_pluse_contrBit; i++)
	{
		if (i == fnc_p_c) {
			contr_bit_arr[i - 1] = 0;
			fnc_p_c = get_next_ps(fnc_p_c);
		}
		else {
			contr_bit_arr[i - 1] = arr_bit[j][k++];
			if (i >= fnc_p_c)
				fnc_p_c = get_next_ps(fnc_p_c);
		}
		(k > 7) ? k = 0, j++ : NULL;
	}
	return contr_bit_arr;
}

static vector<vector<int>> X_counter(vector<int> arr_contrBit, PLUS_SIZE &p_s, int sum_bit, int size_contr_bit) {
	PLUS_SIZE pp_s = { ONE };
	vector<vector<int>> x_array(size_contr_bit, vector<int>(size_contr_bit + sum_bit));
	cout << "\n";
	EX ex = { X };
	int contr_bit_index = 0;
	for (int i = 0; i < size_contr_bit; i++)//итерация по массивам степеней двоек
	{
		for (int j = pp_s; j <= arr_contrBit.size(); j += (pp_s * 2)) { //идем по массиву и расставляем Х
			int counter = 0;
			contr_bit_index = j - 1;
			while (counter < pp_s && contr_bit_index < (sum_bit + size_contr_bit)) { //шагать пока не заполним степень двойки
				x_array[i][contr_bit_index++] = ex;
				counter++;
			}
		}
		pp_s = get_next_ps(pp_s);
	}
	return x_array;
}

static vector<int> get_control_bit(vector<vector<int>> x_array,vector<int> contrbit_arr) {
	vector<int> control_bit_arr(x_array.size());
	EX x = { X };
	for (int i = 0; i < x_array.size(); i++)
	{
		int x_even = 0;
		for (int j = 0; j < x_array[i].size(); j++)
		{
			if (x_array[i][j] == x && contrbit_arr[j] == 1)
				x_even++;
		}
		
		if (x_even % 2 == 0)
			control_bit_arr[i] = 0;
		else
			control_bit_arr[i] = 1;

		cout << control_bit_arr[i];
	}
	return control_bit_arr;
}
void coder(string str, short work) {

	how_ContrBitNeed = 0;
	sum_bit = 0;
	contr_bit_arr.clear();
	control_bit.clear();
	X_arr.clear();
	char_and_bit_array.clear();
	int size_bit_and_contrBit = 0;
	PLUS_SIZE plus_size = { ONE };

	char_and_bit_array.resize(str.size(), vector <int>(8));
	sum_bit = calc_sum_bit(char_and_bit_array);


	char_and_bit_array = take_char_bit_array(str);
	plus_size = calc_size(plus_size, sum_bit, &how_ContrBitNeed);
	size_bit_and_contrBit = plus_size + how_ContrBitNeed;
	
	contr_bit_arr = create_bit_array(char_and_bit_array, plus_size, size_bit_and_contrBit);
	X_arr = X_counter(contr_bit_arr, plus_size, sum_bit, how_ContrBitNeed);
	control_bit = get_control_bit(X_arr,contr_bit_arr);
	get_info();
	cout << endl;
}
void get_info() {
	cout << "Bit and contrbit - ";
	for (int i = 0; i <= contr_bit_arr.size() - 1; i++)
		cout << contr_bit_arr[i];

	//вывод всех битов
	cout << "\nSum bit(without contr bit) = " << sum_bit
		<< "\n+" << how_ContrBitNeed
		<< " with contr bit = " << contr_bit_arr.size();

	//вывод контр битов
	cout << endl;
	for (int i = 0; i < contr_bit_arr.size(); i++)
		cout << contr_bit_arr[i];
	cout << endl;

	//вывод Х над нужными контр битами
	for (int i = 0; i < how_ContrBitNeed; i++)
	{
		for (int j = 0; j < contr_bit_arr.size(); j++)
		{
			if (X_arr[i][j] != 7)
				cout << " ";
			else
				cout << "X";
		}
		cout << endl;
	}

	for (int i = 0; i < control_bit.size(); i++)
	{
		cout << control_bit[i];
	}
}