#include<iostream>
#include<string>
using namespace std;

enum PLUS_SIZE
{
	ONE = 1, TWO = 2, THREE = 4,
	FOUR = 8, FIVE = 16, SIX = 32,
	SEVEN = 64, EIGHT = 128, NINE = 256,
};
enum ex { X = 777 }EX;

template<class T>
const char* foo(T a);

void coder(string);
PLUS_SIZE get_next_ps(PLUS_SIZE p_s);
PLUS_SIZE calc_size(PLUS_SIZE p_s, int index, int i = 0);