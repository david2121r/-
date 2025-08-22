#include <iostream>
#include <string>

int found_id(std::string Card_number, int pin_code,
	int Pin_codes[], std::string Card_numbers[])
{
	int found_id;

	for (int i = 0; i < 6; i++)
		if (Card_number == Card_numbers[i] && pin_code == Pin_codes[i])
			found_id = i;

	return found_id;
}