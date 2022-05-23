#include <iostream>
using namespace std;

int Fibo(int n){
    if(n==1||n==2)
        return 1;
    else if(n==0)
        return 0;
    else
        return Fibo(n-1)+Fibo(n-2);
}

int main(){
    cout<<Fibo(3)<<endl;
}