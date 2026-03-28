#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

const int MINUS_PRECEDENCE = 1;
const int PLUS_PRECEDENCE = 1;
const int MULTIPLY_PRECEDENCE = 2;
const int DIVIDE_PRECEDENCE = 2;

bool validateString(string text)
{
    Stack<char> stack;

    for (int i = 0; i < text.length(); i++)
    {
        char ch = text[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            stack.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (stack.isEmpty())
                return false;

            char top = stack.pop();

            if ((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '['))
            {
                return false;
            }
        }
    }

    return stack.isEmpty();
}

int getPrecedence(char op)
{
    switch (op)
    {
    case '-':
        return MINUS_PRECEDENCE;
    case '+':
        return PLUS_PRECEDENCE;
    case '*':
        return MULTIPLY_PRECEDENCE;
    case '/':
        return DIVIDE_PRECEDENCE;
    default:
        return 0;
    }
}

string convertToPostfix(string infix)
{
    Stack<char> stack;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            stack.push(ch);
        }
        else if (ch == '-' || ch == '+' || ch == '*' || ch == '/')
        {
            while (!stack.isEmpty() &&
                   getPrecedence(stack.top()) >= getPrecedence(ch))
            {
                postfix += stack.pop();
            }
            stack.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            while (!stack.isEmpty())
            {
                if (stack.top() == '(' || stack.top() == '{' || stack.top() == '[')
                {
                    stack.pop();
                    break;
                }
                postfix += stack.pop();
            }
        }
        else
        {
            postfix += ch;
        }
    }

    while (!stack.isEmpty())
    {
        postfix += stack.pop();
    }

    return postfix;
}

int evaluatePostfix(string postfix)
{
    if (postfix.length() < 1)
    {
        cout << "Invalid expression";
        return -1;
    }

    Stack<char> stack;
    int op1, op2, value = 0;

    for (int i = 0; i < postfix.length(); i++)
    {

        char ch = postfix[i];

        if (ch == '-' || ch == '+' || ch == '*' || ch == '/')
        {
            op2 = stack.pop();
            op1 = stack.pop();
            switch (ch)
            {
            case '-':
                value = op1 - op2;
                break;
            case '+':
                value = op1 + op2;
                break;
            case '*':
                value = op1 * op2;
                break;
            case '/':
                value = op1 / op2;
                break;
            }

            stack.push(value);
        }
        else
        {
            stack.push(ch - '0');
        }
    }

    return stack.pop();
}

int main()
{
    string expression = "(3+5)*(2-4)";

    string postfix = convertToPostfix(expression);

    cout << "Simple expression: " << expression << endl
         << endl;
    cout << "Postfix expression: " << postfix << endl
         << endl;

    cout << "The answer of this answer is " << evaluatePostfix(postfix);
    return 0;
}