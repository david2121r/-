#include <iostream>
#include <string>

int checking_entered_commands(const std::string& cmd_user, const std::string cmd_server[], int id)
{
	int id_for_cmd = -1;

	for (int i = 0; i < 6; i++)
		if (cmd_user == cmd_server[i])
			id_for_cmd = i;

	return id_for_cmd;
}