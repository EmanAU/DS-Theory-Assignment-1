#include "../GenericStack/Stack.h"

#define BINARY 2
#define OCTAL 8

string BinaryConverter(int decimalNumber)
{

    if (decimalNumber == 1)
        return "1";
    else if (decimalNumber == 0)
        return "0";

    Stack<int> stack;
    int remainder;
    while (decimalNumber >= 2)
    {
        remainder = decimalNumber % 2;
        decimalNumber = decimalNumber / 2;
        stack.push(remainder);
        if (decimalNumber < 2)
        {
            stack.push(decimalNumber);
        }
    }

    string binaryNumber;
    while (!stack.isEmpty())
    {
        binaryNumber += to_string(stack.pop());
    }

    return binaryNumber;
}

string numberConverter(int number, int base)
{
    if (number < base && number >= 0)
        return to_string(number);

    Stack<int> stack;
    int remainder;
    while (number >= base)
    {
        remainder = number % base;
        number = number / base;
        stack.push(remainder);
        if (number < base)
        {
            stack.push(number);
            break;
        }
    }

    string returnNumber;
    while (!stack.isEmpty())
    {
        returnNumber += to_string(stack.pop());
    }

    return returnNumber;
}

string hexConverter(int number)
{
    int base = 16;

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
    int choice, num;

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
            cout << "Number " << num << " in hexadecimal is " << hexConverter(num);
            break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }

    return 0;
}