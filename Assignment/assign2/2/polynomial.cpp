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
        std::cout<<"file doesn't exist or filename is wrong\n";
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
    for(int i=0; i<n; i++)
        std::cout<<arr[i][0]<<" "<<arr[i][1]<<"\n";
}