#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

class Node
{
private:
    Node *left;
    Node *right;
    string key;
    int data;

public:
    Node(const string &key, int data = 0)
        : left(nullptr), right(nullptr), key(key), data(data) {}

    friend class BST; // BST class can access private members
};

#endif
