#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue<int> q;
    int input;

    //masukkan data ke queue
    while(cin>>input){
        q.push(input);
    }

    //engeluarkan dan menampilkan semua data 
    while (!q.empty()){
        cout<< q.front()<<" ";
        q.pop();
    }

    //mengeluarkan dan menamoilkan semua data
    while (!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

cout<< endl;

}