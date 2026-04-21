#include "../GenericStack/Stack.h"

#define BINARY 2
#define OCTAL 8

string numberConverter(int number, int base)
{

    if (number < base && number >= 0)
        return to_string(number);

    Stack<string> stack;
    int remainder;
    while (number >= base)
    {
        remainder = number % base;
        if (remainder == 10)
            stack.push("A");
        else if (remainder == 11)
            stack.push("B");
        else if (remainder == 12)
            stack.push("C");
        else if (remainder == 13)
            stack.push("D");
        else if (remainder == 14)
            stack.push("E");
        else if (remainder == 15)
            stack.push("F");
        else
            stack.push(to_string(remainder));

        number = number / base;
        if (number < base)
        {
            stack.push(to_string(number));
            break;
        }
    }

    string returnNumber;
    while (!stack.isEmpty())
    {
        returnNumber += stack.pop();
    }

    return returnNumber;
}

int main()
{
    system("cls");

    int choice, num;

    cout << "\n***************Welcome to Number Converter***************" << endl
         << endl;

    while (true)
    {
        cout << "\n1. Binary Conversion" << endl;
        cout << "2. Octal Conversion" << endl;
        cout << "3. Hexadecimal Conversion" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter: ";
        cin >> choice;

        if (choice == 4)
            exit(0);

        cout << "Enter a number: ";
        cin >> num;

        switch (choice)
        {
        case 1:
            cout << "Number " << num << " in binary is " << numberConverter(num, BINARY);
            break;

        case 2:
            cout << "Number " << num << " in octal is " << numberConverter(num, OCTAL);
            break;

        case 3:
            cout << "Number " << num << " in hexadecimal is " << numberConverter(num, 16);
            break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
//teste modification
    return 0;
}