#include "BST.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

void menu()
{
    cout << "1. Insert key-value\n";
    cout << "2. Find value by key\n";
    cout << "3. Print tree in order\n";
    cout << "4. Find minimum key\n";
    cout << "5. Find maximum key\n";
    cout << "6. Save tree to file\n";
    cout << "7. Delete a key\n";
    cout << "8. Load words from file\n";
    cout << "9. Exit\n";
}

string clean_word(const string &word)
{
    string cleaned;
    for (char ch : word)
    {
        if (isalnum(ch))
            cleaned += tolower(ch);
    }
    return cleaned;
}

void load_file(BST &tree, const string &filename)
{
    ifstream file(filename);
    string word;

    if (!file.is_open())
    {
        cout << "Failed to open file.\n";
        return;
    }

    while (file >> word)
    {
        word = clean_word(word);
        if (!word.empty())
        {
            int count = tree.find(word);
            if (count == -1)
                count = 0;
            tree.set(word, count + 1);
        }
    }
    file.close();
}

int main()
{
    BST tree;
    int choice;
    string key, filename;
    int value;

    while (true)
    {
        menu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter key: ";
            cin >> key;
            cout << "Enter value: ";
            cin >> value;
            tree.set(key, value);
            break;
        case 2:
            cout << "Enter key: ";
            cin >> key;
            value = tree.find(key);
            if (value == -1)
                cout << "Key not found.\n";
            else
                cout << "Value: " << value << "\n";
            break;
        case 3:
            tree.print();
            break;
        case 4:
            cout << "Minimum key: " << tree.min() << "\n";
            break;
        case 5:
            cout << "Maximum key: " << tree.max() << "\n";
            break;
        case 6:
            cout << "Enter filename: ";
            cin >> filename;
            tree.save_file(filename);
            break;
        case 7:
            cout << "Enter key: ";
            cin >> key;
            tree.delete_node(key);
            break;
        case 8:
            cout << "Enter file to load: ";
            cin >> filename;
            load_file(tree, filename);
            break;
        case 9:
            return 0;
        default:
            cout << "Invalid choice\n";
        }
    }
}
