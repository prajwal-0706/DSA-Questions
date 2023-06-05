#include <iostream>
using namespace std;

class node
{
public:
  int data;
  node *left = NULL;
  node *right = NULL;
};

class bst
{
public:
  node *root;
  node *new_node;
  bst()
  {
    root = NULL;
  }
  void create();
  void insert(node *root, node *new_node);
  void display(node *root);
  int height(node *root);
  void min_max_value();
  void mirror_img(node *root);
  int search(node *root, int key);
};

void bst::create()
{
  new_node = new node;
  cout << "Enter data for new node : ";
  cin >> new_node->data;

  if (root == NULL)
  {
    root = new_node;
  }
  else
  {
    insert(root, new_node);
  }
}

void bst::insert(node *root, node *new_node)
{
  if (new_node->data < root->data)
  {
    if (root->left == NULL)
    {
      root->left = new_node;
    }
    else
    {
      insert(root->left, new_node);
    }
  }
  if (new_node->data > root->data)
  {
    if (root->right == NULL)
    {
      root->right = new_node;
    }
    else
    {
      insert(root->right, new_node);
    }
  }
}

void bst::display(node *root)
{
  if (root != NULL)
  {
    display(root->left);
    cout << root->data << " ";
    display(root->right);
  }
}

int bst::height(node *root)
{
  if (root == NULL)
    return 0;
  int max1 = height(root->right);
  int max2 = height(root->left);
  return max(max1, max2) + 1;
}

void bst::min_max_value()
{
  node *temp1 = root;
  while (temp1->left != NULL)
  {
    temp1 = temp1->left;
  }
  cout << "\nMinimum value is : " << temp1->data;

  node *temp2 = root;
  while (temp2->right != NULL)
  {
    temp2 = temp2->right;
  }
  cout << "\nMaximum value is : " << temp2->data << endl;
}

int bst::search(node *root, int key)
{
  if (root == NULL)
  {

    return 0;
  }
  else
  {
    if (key == root->data)
    {
      return 1;
    }
    else if (key < root->data)
    {
      search(root->left, key);
    }
    else
    {
      search(root->right, key);
    }
  }
}

void bst::mirror_img(node *root)
{
  if (root != NULL)
  {
    node *temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror_img(root->left);
    mirror_img(root->right);
  }
}

int main()
{
  bst b;
  char c = 'y';
  do
  {

    cout << "------------------------------MENU------------------------------------------" << endl;
    cout << "1.Create binary search tree " << endl;
    cout << "2.Insert new node " << endl;
    cout << "3.Display nodes " << endl;
    cout << "4.Height of tree " << endl;
    cout << "5.Minimum and Maximum value in tree " << endl;
    cout << "6.Search value in tree " << endl;
    cout << "7.Mirror image of trre" << endl;
    cout << "8.Exit " << endl;

    int ch;
    cout << "Enter your choice here : ";
    cin >> ch;

    switch (ch)
    {
    case 1:
      b.create();
      break;

    case 2:
      b.create();
      break;

    case 3:
      b.display(b.root);
      cout << endl;
      break;

    case 4:
      int h;
      h = b.height(b.root);
      cout << "Height of tree is : " << h - 1 << endl;
      break;

    case 5:
      b.min_max_value();
      break;

    case 6:
      int key;
      cout << "Enter key to be search : ";
      cin >> key;
      int k;
      k = b.search(b.root, key);
      if (k == 1)
      {
        cout << "Key is present" << endl;
      }
      else
      {
        cout << "Key is not present" << endl;
      }
      break;

    case 7:
      b.mirror_img(b.root);
      b.display(b.root);
      cout << endl;
      break;

    default:
      c = 'n';
      break;
    }

  } while (c == 'y');

  return 0;
}