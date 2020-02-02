#include"coder.h"
#define TEST


static PLUS_SIZE get_next_ps(PLUS_SIZE p_s) {
	return static_cast<PLUS_SIZE>(static_cast<int>(p_s) * 2);
}
static PLUS_SIZE calc_size(PLUS_SIZE p_s, int sum_bit,int &how_ContrBitNeed) {
	if (p_s < sum_bit) {
		p_s = get_next_ps(p_s);
		(how_ContrBitNeed == 0) ? how_ContrBitNeed += 2 : how_ContrBitNeed++;
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
static vector<int> create_bit_array(vector<vector<int>>arr_bit, vector<int>arr_numbers, PLUS_SIZE p_s) {
	PLUS_SIZE fnc_p_c = { ONE };
	cout << "ha:\n" << "h - ";
	vector<int> contr_bit_arr;
	int size_char_bit = arr_bit.size();
	for (int i = 0; i < arr_bit.size(); i++)
	{

	}
	return contr_bit_arr;
}
void coder(string str) {
	
	vector<vector<int>> char_and_bit_array(str.size(), vector <int>(8));
	int sum_bit = calc_sum_bit(char_and_bit_array);
	int how_ContrBitNeed = 0;
	PLUS_SIZE plus_size = { ONE };


	char_and_bit_array = take_char_bit_array(str);
	plus_size = calc_size(plus_size, sum_bit, how_ContrBitNeed);

	cout << endl;
}