#include <iostream>
#include <fstream>
#include "polynomial.h"

void Polynomial::LoadPolynomial(std::string &filename){
    std::ifstream fin;
    fin.open("./"+filename);
    fin>>n;
    arr=new int *[n];
    for(int i=0; i<n; i++)
        arr[i]=new int[2];
    if(!fin.eof()){
        for(int i=0; !fin.eof(); i++)
            fin>>arr[i][0]>>arr[i][1];
    }
    else
        std::cout<<"file doesn't exist\n";
    while(1){
        int count=0;
        for(int i=0; i<n-1; i++){
            if(arr[i][1]<arr[i+1][1]){
                int temp=arr[i+1][0];
                arr[i+1][0]=arr[i][0];
                arr[i][0]=temp;
                temp=arr[i+1][1];
                arr[i+1][1]=arr[i][1];
                arr[i][1]=temp;
                count++;
            }
        }
        if(count==0)
            break;
    }
}
void Polynomial::PrintPolynomial(){
    for(int i=0; i<n; i++){
        if(arr[i][0]!=0)
            std::cout<<arr[i][0]<<" "<<arr[i][1]<<"\n";
    }
}
void Polynomial::add(Polynomial a, Polynomial b){
    int k=a.arr[0][1], m=b.arr[0][1], l=(k>m?k:m), tempa[l+1][2], tempb[l+1][2], tempc[l+1];
    for(int i=0; i<=l; i++){
        tempa[l-i][0]=tempb[l-i][0]=0;
        tempa[l-i][1]=tempb[l-i][1]=i;
        for(int j=0; j<a.n; j++){
            if(i==a.arr[j][1]){
                tempa[l-i][0]=a.arr[j][0];
                break;
            }
        }
        for(int j=0; j<b.n; j++){
            if(i==b.arr[j][1]){
                tempb[l-i][0]=b.arr[j][0];
                break;
            }
        }
    }
    arr=new int *[l+1];
    for(int i=0; i<=l; i++)
        arr[i]=new int[2];
    for(int i=0; i<=l; i++){
        arr[i][0]=tempa[i][0]+tempb[i][0];
        arr[i][1]=l-i;
    }
    n=l+1;
}