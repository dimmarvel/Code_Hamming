#ifndef _CODER_H_
#define _CODER_H_
#include "decoder.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//enum x { X = 777 }x;
enum PLUS_SIZE
{
	ONE = 1, TWO = 2, THREE = 4,
	FOUR = 8, FIVE = 16, SIX = 32,
	SEVEN = 64, EIGHT = 128, NINE = 256,
};


vector<int> take_char_bit(char a); //определить биты символа
vector<vector<int>> take_char_bit_array(string stroke); //получить массив битов всех символов[номер_буквы][её_биты(8)]

void coder(string str);
static PLUS_SIZE get_next_ps(PLUS_SIZE p_s);
static PLUS_SIZE calc_size(PLUS_SIZE p_s, int index);



#endif