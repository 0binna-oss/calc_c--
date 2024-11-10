#include <iostream>
#include <limits>
#include <string>

void showMenu() {
    std::cout << "Simple Calculator\n";
    std::cout << "=================\n";
    std::cout << "1. Addition (+)\n";
    std::cout << "2. Subtraction (-)\n";
    std::cout << "3. Multiplication (*)\n";
    std::cout << "4. Division (/)\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose an option: "; 
}

double getNumber(const std::string & prompt) {
    double number;
    while (true) {
        std::cout << prompt;
        std::cin >> number;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            return number;
        }
    }
}

int getchoice() {
    std::string input;
    int choice;

    while (true) {
        std::getline(std::cin, input);
        
        try {
            choice = std::stoi(input);
            return choice;
        } catch (...) {
            std::cout << "invalid input. Please enter a number between 1 and 5: ";
        }
    }
}

int main() {
    int choice;
    double num1, num2, result;

    while (true) {
        showMenu();
        std::cin >> choice;

        if (choice == 5) {
            std::cout << "Exiting the calculator. Goodbye!\n";
            break;
        }

        if (choice <1 || choice >4) {
            std::cout << "Invalid choice. PLease try again.\n";
            continue;
        }

        // Get two numbers from the user 
        num1 = getNumber("Enter the first number: ");
        num2 = getNumber("Enter the second number: ");

        // Perform the selected operation
        switch (choice) {
            case 1:
               result = num1 + num2;
               std::cout << "Result: " << num1 << "+" << num2 << "=" << result << "\n";
               break;
            case 2:
               result = num1 - num2;
               std::cout << "Result: " << num1 << "-" << num2 << "=" << result << "\n";
               break;
            case 3:
               result = num1 * num2;
               std::cout << "Result: " << num1 << "*" << num2 << "=" << result << "\n";
               break;
            case 4:
               if (num2 == 0) {
                std::cout << "Error: Division by zero is not allowed.\n";
               } else {
                result = num1 / num2;
                std::cout << "Result: " << num1 << "/" << num2 << "=" << result << "\n";
               }
               break;
            default:
                std::cout << "Invalid choice.\n";
                break;            
        }
        std::cout << "\n";
    }
    return 0; 
}