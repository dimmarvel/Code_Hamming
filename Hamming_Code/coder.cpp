#include"coder.h"
#define TEST
static PLUS_SIZE get_next_ps(PLUS_SIZE p_s) {
	return static_cast<PLUS_SIZE>(static_cast<int>(p_s) * 2);
}
static PLUS_SIZE calc_size(PLUS_SIZE p_s, int index) {
	if (p_s < index) {
		p_s = get_next_ps(p_s);
		p_s = calc_size(p_s, index);
	}
	return p_s;
}

vector<int> take_char_bit(char a)
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

vector<vector<int>> take_char_bit_array(string stroke) {
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
void coder(string str) {
	cout << str;
}