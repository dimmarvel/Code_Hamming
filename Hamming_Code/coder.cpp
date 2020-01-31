#include"coder.h"

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
template<class T>
const char* foo(T a)
{
	for (int i = 8 * sizeof(a) - 1; i >= 0; --i)
	{
		cout << ((a >> i) & 1);
	}
	return "";
}