#include <iostream>
#include <string>

void money_transfer(int(&user_account)[6], int id_for_user,
	std::string user_enter, int amount_of_translation,
	std::string(&arr)[6]
)
{
	int id = 1;
	bool found = false;

	for (int i = 0; i < 6; i++)
		if (arr[i] == user_enter)
		{
			found = true;
			id = i; 
		}

	if (found == true)
	{
		user_account[id_for_user] -= amount_of_translation;
		user_account[id] += amount_of_translation;

		std::cout << "now you have " << user_account[id_for_user] << " dollars and he has " << user_account[id] << std::endl;
	}

	else
		std::cout << "such card number does not exist\n";

}