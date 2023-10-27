#include <iostream>
using namespace std;

// struct and class having declared everything public is same in C++

class Node
{
public:
  Node *left;
  Node *right;
  int data;
  bool rightThread;
  Node(int data)
  {
    this->data = data;
    rightThread = false;
    this->left = nullptr;
    this->right = nullptr;
  }
};

Node *leftMostNode(Node *node)
{
  if (node == nullptr)
  {
    return nullptr;
  }
  else
  {
    while (node->left != nullptr)
    {
      node = node->left;
    }
    return node;
  }
}

class BSTtoThreadedBST
{

public:
  BSTtoThreadedBST()
  {
  }

  void convert(Node *root)
  {
    inorder(root, nullptr);
  }

  void inorder(Node *root, Node *previous)
  {

    if (root == nullptr)
    {
      return;
    }
    else
    {
      inorder(root->right, previous);
      if (root->right == nullptr && previous != nullptr)
      {
        root->right = previous;
        root->rightThread = true;
      }
      inorder(root->left, root);
    }
  };

  void print(Node *root)
  {

    Node *current = leftMostNode(root);
    while (current != nullptr)
    {
      cout << " " << current->data;

      if (current->rightThread)
        current = current->right;
      else
        current = leftMostNode(current->right);
    }
    cout << endl;
  }
};

int main()
{
  Node *root = new Node(10);
  root->left = new Node(5);
  root->right = new Node(15);
  root->left->left = new Node(1);
  root->left->right = new Node(7);
  root->right->left = new Node(12);
  root->right->right = new Node(20);

  BSTtoThreadedBST *converter = new BSTtoThreadedBST();
  converter->convert(root);

  cout << "Inorder Traversal: " << endl;
  converter->print(root);

  return 0;
}