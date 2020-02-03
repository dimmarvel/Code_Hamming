#include"coder.h"
#define TEST


static PLUS_SIZE get_next_ps(PLUS_SIZE p_s) {
	return static_cast<PLUS_SIZE>(static_cast<int>(p_s) * 2);
}

static PLUS_SIZE calc_size(PLUS_SIZE p_s, int sum_bit, int *how_ContrBitNeed =  NULL) {
	if (p_s < sum_bit) {
		p_s = get_next_ps(p_s);
		(*how_ContrBitNeed == 0) ? *how_ContrBitNeed += 2 : *how_ContrBitNeed += 1;
		p_s = calc_size(p_s, sum_bit, how_ContrBitNeed);
	}
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

static vector<int> create_bit_array(vector<vector<int>>arr_bit, PLUS_SIZE p_s,int size_bit_pluse_contrBit) {
	PLUS_SIZE fnc_p_c = { ONE };
	vector<int> contr_bit_arr(size_bit_pluse_contrBit);
	int size_char_bit = arr_bit.size();
	int j = 0, //итерация по буквам [j][]
		k = 0 //биты буквы [][k]
		;
	for (int i = 1; i <= size_bit_pluse_contrBit; i++)
	{
		if (i == fnc_p_c) {
			contr_bit_arr[i-1] = 0;
			fnc_p_c = get_next_ps(fnc_p_c);
		}
		else {
			contr_bit_arr[i-1] = arr_bit[j][k++];
			if (i >= fnc_p_c)
				fnc_p_c = get_next_ps(fnc_p_c);
		}
		(k > 7) ? k = 0, j++ : NULL;
	}
	return contr_bit_arr;
} 

static vector<vector<int>> X_counter(vector<int> arr_contrBit, PLUS_SIZE &p_s,int sum_bit, int size_contr_bit) {
	PLUS_SIZE pp_s = {ONE};
	vector<vector<int>> x_array(sum_bit,vector<int> (arr_contrBit.size()));
	cout << "\n";
	EX ex = { X };
	int contr_bit_index = 0;
	for (int i = 0; i < size_contr_bit; i++)//итерация по массивам степеней двоек
	{
		for (int j = pp_s; j <= arr_contrBit.size(); j += (pp_s * 2)) { //идем по массиву и расставляем Х
			int counter = 0;
			contr_bit_index = j-1;
			while (counter < pp_s && contr_bit_index < (sum_bit + size_contr_bit)) { //шагать пока не заполним степень двойки
				x_array[i][contr_bit_index++] = ex;
				counter++;
			}
		}
		pp_s = get_next_ps(pp_s);
	}
	return x_array;
}
void coder(string str) {

	vector<vector<int>> char_and_bit_array(str.size(), vector <int>(8));
	int sum_bit = calc_sum_bit(char_and_bit_array);
	int how_ContrBitNeed = 0;
	int size_bit_and_contrBit = 0;
	PLUS_SIZE plus_size = { ONE };


	char_and_bit_array = take_char_bit_array(str);

	plus_size = calc_size(plus_size, sum_bit, &how_ContrBitNeed);
	size_bit_and_contrBit = plus_size + how_ContrBitNeed;
	vector<int> contr_bit_arr = create_bit_array(char_and_bit_array, plus_size, size_bit_and_contrBit);
	vector<vector<int>> X_arr = X_counter(contr_bit_arr, plus_size, sum_bit, how_ContrBitNeed);


	cout << "bit_and_contrbit_arr - ";
	for (int i = 0; i <= size_bit_and_contrBit - 1; i++)
	{
		cout << contr_bit_arr[i];
	}
	cout << "\nAll bit = " << sum_bit
		 << "\n+" << how_ContrBitNeed 
		 << " contr bit = " << size_bit_and_contrBit;

	cout << endl;
	for (int i = 0; i < contr_bit_arr.size(); i++)
		cout << contr_bit_arr[i];
	cout << endl;

	for (int i = 0; i < how_ContrBitNeed; i++)
	{
		for (int j = 0; j < size_bit_and_contrBit; j++)
		{
			if (X_arr[i][j] != 7)
				cout << " ";
			else
				cout << "X";
		}
		cout << endl;
	}
	cout << endl;
}