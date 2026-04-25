#include "../GenericStack/Stack.h"

int main()
{
    system("cls");

    int choice;
    Stack<string> stack, undo;
    string word;

    cout << "\n***************Welcome to Text Editor***************" << endl
         << endl;

    while (true)
    {
        cout << "\n1. Type a word: " << endl;
        cout << "2. Undo: " << endl;
        cout << "3. Redo: " << endl;
        cout << "4. Show: " << endl;
        cout << "5. Exit: " << endl;
        cout << "Enter: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter a work: ";
            getline(cin, word);
            stack.push(word);
            break;

        case 2:
            if (stack.isEmpty())
            {
                cout << "The stack is empty. Can't do undo" << endl;
            }
            else
            {
                undo.push(stack.pop());
                cout << "Undo successfully done" << endl;
            }
            break;

        case 3:
            if (undo.isEmpty())
            {
                cout << "Can't do more redo" << endl;
            }
            else
            {
                stack.push(undo.pop());
                cout << "Redo successfully done" << endl;
            }
            break;

        case 4:
            stack.showAll();
            break;

        case 5:
            exit(0);
            break;

        default:
            break;
        }
    }
    return 0;
}


//this comment is written on khizee laptop