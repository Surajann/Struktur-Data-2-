#include<iostream>
#include<stack>

using namespace std;

int main(){
    stack<int> s;
    int input;

    //input bereni ketika input bukan angka
    while(cin>>input){
        s.push(input);

    }



    // mengeluarkan semua data dari stack
    while(!s.empty()){
        cout<<s.top() << " ";
        s.pop();
    
    }

    cout << endl;
    return 0;


}