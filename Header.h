#ifndef header
#define header

#include <string>

bool user_data_verification(const std::string& Card_number, int pin_code,
    const int Pin_codes[], const std::string Card_numbers[],
    int size);

int checking_entered_commands(const std::string& cmd_user, const std::string cmd_server[], int id);

void money_transfer(int(&user_account)[6], int id_for_user,
	std::string user_enter, int amount_of_translation,
	std::string(&arr)[6]);


#endif // !header

