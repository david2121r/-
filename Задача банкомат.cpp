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

    std::string cmd_for_user[]{
        "enter","withdraw","transfer"
    };

    std::string Client_names[]{
            "jonny","zolot","infinty",
            "slippers","reef","chupa"
    };
    std::string Card_numbers[]{
        "4923 8340 9753 1664","6384 0536 0365 8254",
        "9375 0184 5396 4285","8663 7653 0635 0183",
        "9365 9175 0946 7432","8472 6519 9785 0013"
    };
    int Pin_codes[]{
        5236,9534,5482,9042,3718,5085
    };
    int Balance_on_the_card[]{
        100,564,942,975,0,532
    };
    int Cash_balance[]{
        100,231,62,36,0,109
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
                std::cout << "You have the option to enter, withdraw or transfer: ";
                std::cin >> option;

                
            }

        }

        else
            std::cout << "Invalid code or card number\n";

    }

    return 0;
}