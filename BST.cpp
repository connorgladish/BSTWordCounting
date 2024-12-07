#include "BST.h"
using namespace std;

void BST::destroy(Node *node)
{
    if (node)
    {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

void BST::insert_helper(Node *&node, const string &key, int value)
{
    if (!node)
    {
        node = new Node(key, value);
    }
    else if (key < node->key)
    {
        insert_helper(node->left, key, value);
    }
    else if (key > node->key)
    {
        insert_helper(node->right, key, value);
    }
    else
    {
        node->data = value; // Overwrite if key exists
    }
}

int BST::find_helper(Node *node, const string &key) const
{
    if (!node)
    {
        return -1; // Not found
    }
    if (key < node->key)
    {
        return find_helper(node->left, key);
    }
    else if (key > node->key)
    {
        return find_helper(node->right, key);
    }
    else
    {
        return node->data;
    }
}

void BST::print_helper(Node *node) const
{
    if (node)
    {
        print_helper(node->left);
        cout << "(" << node->key << ", " << node->data << ") ";
        print_helper(node->right);
    }
}

void BST::save_helper(Node *node, ofstream &file) const
{
    if (node)
    {
        save_helper(node->left, file);
        file << node->key << " " << node->data << "\n";
        save_helper(node->right, file);
    }
}

Node *BST::find_min(Node *node) const
{
    while (node && node->left)
    {
        node = node->left;
    }
    return node;
}

Node *BST::delete_helper(Node *node, const string &key)
{
    if (!node)
        return nullptr;

    if (key < node->key)
    {
        node->left = delete_helper(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = delete_helper(node->right, key);
    }
    else
    {
        if (!node->left)
        {
            Node *temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right)
        {
            Node *temp = node->left;
            delete node;
            return temp;
        }
        Node *temp = find_min(node->right);
        node->key = temp->key;
        node->data = temp->data;
        node->right = delete_helper(node->right, temp->key);
    }
    return node;
}

void BST::set(const string &key, int value)
{
    insert_helper(root, key, value);
}

int BST::find(const string &key) const
{
    return find_helper(root, key);
}

void BST::print() const
{
    print_helper(root);
    cout << "\n";
}

string BST::min() const
{
    Node *minNode = find_min(root);
    return minNode ? minNode->key : "Tree is empty";
}

string BST::max() const
{
    Node *current = root;
    while (current && current->right)
    {
        current = current->right;
    }
    return current ? current->key : "Tree is empty";
}

void BST::save_file(const string &filename) const
{
    ofstream file(filename);
    if (file.is_open())
    {
        save_helper(root, file);
        file.close();
    }
}

void BST::delete_node(const string &key)
{
    root = delete_helper(root, key);
}
