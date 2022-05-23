#include <iostream>
using namespace std;

void Hanoi(int n, char from, char by, char to){
    if(n>2){
        Hanoi(n-1, from, to, by);
        Hanoi(1, from, by, to);
        Hanoi(n-1, by, from, to);
    }
    else if(n==2){
        Hanoi(1, from, to, by);
        Hanoi(1, from, by, to);
        Hanoi(1, by, from, to);
    }
    else if(n==1)
        cout<<from<<"=>"<<to<<endl;
}

int main(){
    Hanoi(3, 'A', 'B', 'C');
}