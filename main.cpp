#include <iostream>
#include <string>
#include <conio.h>
#include <thread>

int main()
{
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
    int Balance_on_the_card[6]{
        100,564,942,975,10,532
    };
    int Cash_balance[6]{
        100,231,62,36,1110,109
    };

    std::string Card_number;

    std::cout << "enter card number: ";
    std::getline(std::cin, Card_number);

    system("cls");

    int pin = 0;

    std::cout << "enter pin code: ";
    std::cin >> pin;

    std::cin.ignore();

    bool found = false;

    for (int i = 0; i < 4; i++)
        if (Card_number == Card_numbers[i] && pin == Pin_codes[i])
            found = true;

    int id = -1;

    for (int i = 0; i < 6; i++)
        if (Card_number == Card_numbers[i] && pin == Pin_codes[i])
            id = i;

    int amount = 0;
    std::string enter_card_numbers;
    bool found_1 = false;
    int id_1 = -1;

    while (true)
    {

        if (found == true)
        {
            int choice = 1;

            char key;

            do {
                system("cls");

                std::cout << "select option: \n";

                std::cout << (choice == 1 ? "->" : "   ") << "enter money \n";
                std::cout << (choice == 2 ? "->" : "   ") << "withdraw money \n";
                std::cout << (choice == 3 ? "->" : "   ") << "transfer money \n";
                std::cout << (choice == 4 ? "->" : "   ") << "exit \n";

                key = _getch();

                if (key == 72 && choice > 1) choice--;
                if (key == 80 && choice < 4) choice++;

            }

            while (key != 13);

            switch (choice)
            {
            case(1):
                system("cls");

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

                std::this_thread::sleep_for(std::chrono::seconds(3));

                break;

            case(2):
                system("cls");

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

                std::this_thread::sleep_for(std::chrono::seconds(3));

                break;

            case(3):
                std::cin.ignore();

                std::cout << "enter card numbers: ";
                std::getline(std::cin, enter_card_numbers);

                std::cout << "enter the amount: ";
                std::cin >> amount;

                if (enter_card_numbers != Card_numbers[id] && amount < Balance_on_the_card[id])
                {
                    for (int i = 0; i < 6; i++)
                        if (Card_numbers[i] == enter_card_numbers)
                        {
                            found_1 = true;
                            id_1 = i;
                        }

                    if (found_1 == true)
                    {
                        Balance_on_the_card[id] -= amount;
                        Balance_on_the_card[id_1] += amount;

                        std::cout << "now you have " << Balance_on_the_card[id] << " dollars and he/she has " << Balance_on_the_card[id_1] << std::endl;
                    }

                    else
                        std::cout << "such card number does not exist\n";
                }

                else
                    std::cout << "You have entered your card number or you do not have sufficient funds\n";

                std::this_thread::sleep_for(std::chrono::seconds(3));

                break;

            case(4):
                return 0;
            }
        }
        else
            std::cout << "Invalid code or card number\n";

    }
}