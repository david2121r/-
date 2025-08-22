#include <iostream>
#include <string>
#include "Header.h"

int main()
{
    int pin = 0;
    std::string Card_number;
    bool found = false;
    int id = -1;
    std::string option;
    int id_for_cmd = -1;
    int amount = 0;
    std::string enter_card_numbers;

    std::string cmd_for_user[4]{
        "enter","withdraw","transfer","exit"
    };

    std::string Client_names[6]{
            "jonny","zolot","infinty",
            "slippers","reef","chupa"
    };
    std::string Card_numbers[6]{
        "4923 8340 9753 1664","6384 0536 0365 8254",
        "9375 0184 5396 4285","8663 7653 0635 0183",
        "9365 9175 0946 7432","8472 6519 9785 0013"
    };
    int Pin_codes[6]{
        5236,9534,5482,9042,3718,5085
    };
    int Balance_on_the_card[6] {
        100,564,942,975,10,532
    };
    int Cash_balance[6]{
        100,231,62,36,11102,109
    };

    while (true)
    {
        std::cout << "enter Card number: ";
        std::getline(std::cin, Card_number);

        std::cout << "enter pin code: ";
        std::cin >> pin;

        std::cin.ignore();

        for (int i = 0; i < 6; i++)
            if (Card_number == Card_numbers[i] && pin == Pin_codes[i])
                id = i;

        found = user_data_verification(Card_number, pin, Pin_codes, Card_numbers, id);

        if (found == true)
        {
            std::cout << "hello " << Client_names[id]
                << " you have " << Balance_on_the_card[id] << " dollars in your account\n";

            std::cout << "and you have " << Cash_balance[id] << " cash\n";

            while (true)
            {
                std::cout << "You have the option enter, withdraw, exit or transfer: ";
                std::cin >> option;

                id_for_cmd = checking_entered_commands(option, cmd_for_user, 6);

                std::cin.ignore();

                switch (id_for_cmd)
                {
                    case(0):
                        std::cout << "enter the amount: ";
                        std::cin >> amount;

                        std::cin.ignore();

                        if (Cash_balance[id] >= amount)
                        {
                            Cash_balance[id] -= amount;
                            Balance_on_the_card[id] += amount;

                            std::cout << "now you have " << Balance_on_the_card[id] << std::endl;
                        }

                        else
                            std::cout << "insufficient funds\n";

                        break;

                    case(1):
                        std::cout << "enter the amount: ";
                        std::cin >> amount;

                        std::cin.ignore();

                        if (Balance_on_the_card[id] >= 0 && Balance_on_the_card[id] >= amount)
                        {
                            Cash_balance[id] += amount;
                            Balance_on_the_card[id] -= amount;

                            std::cout << "now you have " << Cash_balance[id] << " on cash\n";
                        }

                        else
                            std::cout << "there are not enough funds on the card\n";

                        break;

                    case(2):
                        std::cout << "enter card numbers: ";
                        std::getline(std::cin, enter_card_numbers);

                        std::cout << "enter the amount: ";
                        std::cin >> amount;

                        std::cin.ignore();

                        if (enter_card_numbers != Card_numbers[id] && amount < Balance_on_the_card[id])
                            money_transfer(Balance_on_the_card, id, enter_card_numbers,amount,Card_numbers);

                        else
                            std::cout << "You have entered your card number or you do not have sufficient funds\n";

                        break;

                    case(3):
                        return 0;

                    default:

                        std::cin.ignore();

                        std::cout << "Incorrectly entered command\n";
                }
            }

        }

        else
            std::cout << "Invalid code or card number\n";

    }

    return 0;
}