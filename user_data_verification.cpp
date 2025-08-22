#include <iostream>
#include <string>

bool user_data_verification(const std::string& Card_number, int pin_code,
	const int Pin_codes[], const std::string Card_numbers[],
	int size)
{
	bool found = false;

	for (int i = 0; i < 4; i++)
		if (Card_number == Card_numbers[i] && pin_code == Pin_codes[i])
			found = true;
		

	return found;
}