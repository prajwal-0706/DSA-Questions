#include <bits/stdc++.h>
using namespace std;

// Binary Search without Recursion
int binartSearchByNormal(vector<int> arr, int key)
{

  int start = 0;
  int end = arr.size() - 1;
  while (start <= end)
  {
    int mid = start + (end - start) / 2;

    if (arr[mid] == key)
    {
      return mid;
    }

    else if (arr[mid] > key)
    {
      end = mid - 1;
    }

    else if (arr[mid] < key)
    {
      start = mid + 1;
    }
  }

  return -1;
}

// Binary Search with Recursion
int binarySearchByRecursion(vector<int> arr, int start, int end, int key)
{
  if (start <= end)
  {
    int mid = start + (end - start) / 2;

    if (arr[mid] == key)
    {
      return mid;
    }

    else if (arr[mid] > key)
    {
      return binarySearchByRecursion(arr, start, mid - 1, key);
    }

    else
    {
      return binarySearchByRecursion(arr, mid + 1, end, key);
    }
  }

  return -1;
}

int main()
{

  int n;
  cout << "Enter the Size of the Array: " << endl;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int key;
  cout << "Enter the Key to be Searched: " << endl;
  cin >> key;

  // int index = binarySearchByRecursion(arr, 0, n - 1, key);
  // index == -1 ? cout << "Element not found" : cout << "Element found at index " << index << endl;
  int index = binartSearchByNormal(arr, key);
  index == -1 ? cout << "Element not found" : cout << "Element found at index " << index << endl;
  return 0;
}