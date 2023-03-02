#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the value of 'n' :-";
    cin >> n;
    cout << endl;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j <= i ; j++){
            cout <<  "*" << " ";
        }
        cout << endl;
    }

    cout << endl;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= i ; j++){
            cout <<  i << " ";
        }
        cout << endl;
    }

    cout << endl;
    int count = 1;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= i ; j++){
            cout <<  count++ << " ";
        }
        cout << endl;
    }

    cout << endl;
    
    for(int i = 1 ; i <= n ; i++){
        int value = i;
        for(int j = 1 ; j <= i ; j++){
            cout <<  value-- << " ";
        }
        cout << endl;
    }

    return 0;
}