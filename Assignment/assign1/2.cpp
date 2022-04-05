#include <iostream>
using namespace std;

void printAB(int n, int bit, char arr[]){
    if(bit==n){
        for(int i=0; i<n; i++)
            cout<<arr[i];
        cout<<endl;
        return;
    }
    for(int i=0; i<2; i++){
        arr[bit]=(i==0?'a':'b');
        printAB(n, bit+1, arr);
    }
}

int main(){
    int n;
    cin>>n;
    char arr[n];
    printAB(n, 0, arr);    
}