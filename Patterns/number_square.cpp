#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter the Value For 'n' :-";
    cin >> n;

    for(int i = 0 ; i < n; i++){
        for(int j = 1; j <= n; j++){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0 ; i < n; i++){
        for(int j = 1; j <= n; j++){
            cout << (n - j + 1) << " ";
        }
        cout << endl;
    }
    cout << endl;
    int count = 1;
    for(int i = 0 ; i < n; i++){
        for(int j = 1; j <= n; j++){
            cout << count << " ";
            count++;
        }
        cout << endl;
    }

    return 0;
}