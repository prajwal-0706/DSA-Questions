#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> arr)
{
  for (int i = 0; i < arr.size(); i++)
    cout << arr[i] << " ";
  cout << endl;
}

// Bubble Sort
void bubbleSort(vector<int> arr)
{
  int n = arr.size();

  for (int round = 1; round < n; round++)
  {
    bool swapped = false;
    for (int j = 0; j < n - round; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }
    if (!swapped)
      break;
  }
  printArray(arr);
}

// Selection Sort
void selectionSort(vector<int> arr)
{
  int n = arr.size();

  for (int round = 0; round < n - 1; round++)
  {
    int minIndex = round;

    for (int j = round + 1; j < n; j++)
    {
      if (arr[j] < arr[minIndex])
      {
        minIndex = j;
      }
    }

    swap(arr[round], arr[minIndex]);
  }
  printArray(arr);
}

void insertionSort(vector<int> arr)
{
  int n = arr.size();

  for (int i = 1; i < n; i++)
  {
    // Step 1: Fetch
    int current = arr[i];

    // Step 2 & 3: Compare and Shift
    int j = i - 1;
    while (j >= 0 && arr[j] > current) // compare
    {
      arr[j + 1] = arr[j]; // shift
      j--;
    }

    // Step 4: copy
    arr[j + 1] = current;
  }
  printArray(arr);
}

int main()
{
  int n;
  cout << "Enter the size of the array: " << endl;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; i++)
    cin >> arr[i];
  // bubbleSort(arr);
  // selectionSort(arr);
  insertionSort(arr);
  return 0;
}