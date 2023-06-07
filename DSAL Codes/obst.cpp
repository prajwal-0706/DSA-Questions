#include <iostream>
using namespace std;
int sum(int freq[], int i, int j)
{
  int s = 0;
  for (int k = i; k <= j; k++)
  {
    s += freq[k];
  }
  return s;
}



int OBST(int freq[], int i, int j)
{
  if (j < i)
  {
    return 0;
  }
  if (j == i)
  {
    return freq[i];
  }

  int min = 1000;
  int fsum = sum(freq, i, j);
  for (int k = i; k <= j; k++)
  {
    int cost = OBST(freq, i, k - 1) + OBST(freq, k + 1, j);
    if (cost < min)
    {
      min = cost;
    }
  }
  return min + fsum;
}


int obst(int keys[], int freq[], int n)
{
  return OBST(freq, 0, n - 1);
}

int main()
{
  int a, b;
  cout << "Enter the no of keys in the tree : ";
  cin >> a;
  int keys[a];
  int freq[a];

  for (int i = 0; i < a; i++)
  {
    cout << "Enter the key value :";
    cin >> keys[i];
  }
  for (int i = 0; i < a; i++)
  {
    cout << "Enter the corresponding frequency value : ";
    cin >> freq[i];
  }

  int n = sizeof(keys) / sizeof(keys[0]);
  cout << n << endl;
  cout << "Optimal cost for the full tree is : " << obst(keys, freq, n);
}