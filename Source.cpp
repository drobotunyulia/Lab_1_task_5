#include <iostream>
#include <vector>
#include <stdarg.h>

using namespace std;

int other_to_dec(char symbol, int base);
string sum(int base, size_t count_value, ...);
string add_value(int base, string value_1, string value_2);
char dec_to_other(int num, int base);

int main()
{
	cout << "Laba 1 Task 5\nDrobotun Yulia M8o-210B-20\n" << endl << endl;
	cout << "Sum = ";
	cout << sum(16, 3, string("95873"), string("FFA"), string("FF55FF66")) << endl;
	return 0;
}

int other_to_dec(char symbol, int base)
{
	int dec_number;
	if (symbol <= '9')
		symbol = symbol - '0';
	else
		symbol = symbol - 'A' + 10;
	dec_number = (int)symbol;
	return dec_number;
}

char dec_to_other(int num, int base)
{
	if (num <= 9)
		num = num + '0';
	else
		num = num - 10 + 'A';
	return (char)num;
}

string sum(int base, size_t count_value, ...)
{
	vector<string> value_array;
	string sum_value(1, '0');
	va_list factor;
	va_start(factor, count_value);
	for (size_t i = 0; i < count_value; i++)
	{
		value_array.push_back(va_arg(factor, string));
	}
	va_end(factor);
	for (size_t i = 0; i < count_value; i++)
	{
		sum_value = add_value(base, sum_value, value_array[i]);
	}
	return sum_value;
}

string add_value(int base, string value_1, string value_2)
{
	size_t result_length = 0;
	string result;
	int digit_dec_1 = 0, digit_dec_2 = 0, digit_dec_result = 0, shift = 0;
	if (value_1.length() >= value_2.length())
	{
		result_length = value_1.length() + 1;
	}
	if (value_2.length() > value_1.length())
	{
		result_length = value_2.length() + 1;
	}
	size_t count_zero_1 = result_length - value_1.length();
	size_t count_zero_2 = result_length - value_2.length();
	result.resize(result_length, '0');
	for (size_t i = 0; i < count_zero_1; i++)
	{
		value_1.insert(value_1.begin(), '0');
	}
	for (size_t i = 0; i < count_zero_2; i++)
	{
		value_2.insert(value_2.begin(), '0');
	}
	for (int i = result_length - 1; i >= 0; i--)
	{
		digit_dec_1 = other_to_dec(value_1[i], base);
		digit_dec_2 = other_to_dec(value_2[i], base);
		digit_dec_result = digit_dec_1 + digit_dec_2 + shift;
		shift = digit_dec_result / base;
		digit_dec_result = digit_dec_result % base;
		result[i] = dec_to_other(digit_dec_result, base);
	}
	if (result[0] == '0')
	{
		result.erase(0, 1);
	}
	return result;
}
