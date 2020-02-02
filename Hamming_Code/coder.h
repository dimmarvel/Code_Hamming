#ifndef _CODER_H_
#define _CODER_H_
#include "decoder.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;

enum EX { X = 777 };
enum PLUS_SIZE
{
	ONE = 1, TWO = 2, THREE = 4,
	FOUR = 8, FIVE = 16, SIX = 32,
	SEVEN = 64, EIGHT = 128, NINE = 256,
};

void coder(string str);
static vector<int> take_char_bit(char a); //определить биты символа
static vector<vector<int>> take_char_bit_array(string stroke); //получить массив битов всех символов[номер_буквы][её_биты(8)]
static int calc_sum_bit(vector<vector<int>> char_bit_array); //сумма битов со всех букв
static PLUS_SIZE get_next_ps(PLUS_SIZE p_s); //следующий токен
static PLUS_SIZE calc_size(PLUS_SIZE p_s, int sum_bit, int &how_ContrBitNeed); //посчитать количество степеней двоек и сколько нужно добавить контбит
static vector<int> create_bit_array(vector<vector<int>>arr_bit, vector<int>arr_numbers, PLUS_SIZE p_s); //создать массив битов и контр битов


#endif