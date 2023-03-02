#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the Value of 'n' :-";
    cin >> n;

    for(int i = 1 ; i <= n ; i++){

        //spaces
        for(int j = n - i ; j >= 1 ; j--){
            cout << " ";
        }

        //stars
        for(int j = 1 ; j <= i ; j++){
            cout << "*" << " ";
        }
        
        cout << endl;

    }

    return 0;
}