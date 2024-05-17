#ifndef DSA_BINARY_HEAP_H
#define DSA_BINARY_HEAP_H

template <typename T>
class BinaryHeap
{
private:
    class Node
    {
        Node *root;
        Node *left;
        Node *right;
        T value;

        Node(Node *root, Node *left, Node *right, Node *value) : root(root), left(left), right(right), value(value) {}
        Node(Node *root, T value) : root(root), value(value) {}
        Node(T value) : left(nullptr), right(nullptr), value(value) {}
    };

    Node *root;

    void *swap(Node parent)
    {
    }

    void print(Node *start)
    {

    }

public:
    BinaryHeap() {}

    void insert(T value)
    {
        if (root == nullptr)
        {
            root = new Node(value);
            return;
        }
        Node *temp = root;
        while (temp->left != nullptr && temp->right != nullptr)
        {
            if (temp->left == nullptr)
            {
                temp->left = new Node(value);
                swap(temp->left);
                return;
            }
            if (temp->right == nullptr)
            {
                temp->right = new Node(value);
                swap(temp->right);
                return;
            }
            if (temp->left->value > temp->right->value)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
    }
};

#endif