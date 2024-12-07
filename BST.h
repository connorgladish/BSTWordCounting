#ifndef BST_H
#define BST_H

#include "Node.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BST
{
private:
    Node *root;

    void insert_helper(Node *&node, const string &key, int value);
    int find_helper(Node *node, const string &key) const;
    void print_helper(Node *node) const;
    void save_helper(Node *node, ofstream &file) const;
    Node *delete_helper(Node *node, const string &key);
    Node *find_min(Node *node) const;
    void destroy(Node *node);

public:
    BST() : root(nullptr) {}
    ~BST() { destroy(root); }

    void set(const string &key, int value);
    int find(const string &key) const;
    void print() const;
    string min() const;
    string max() const;
    void save_file(const string &filename) const;
    void delete_node(const string &key);
};

#endif
