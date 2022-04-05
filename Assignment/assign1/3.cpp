#include <iostream>
using namespace std;

void binarySearch(int first, int last, int find, int arr[], int count){
    if(first<=last){
        int mid=(first+last)/2;
        count++;
        if(find<arr[mid])
            return binarySearch(first, mid-1, find, arr, count);
        else if(find>arr[mid])
            return binarySearch(mid+1, last, find, arr, count);
        else if(find==arr[mid]){
            cout<<mid<<endl<<count<<endl;
            return;
        }
    }
    cout<<-1<<endl<<count<<endl;
}

int main(){
    int n, find;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)    
        cin>>arr[i];
    cin>>find;
    binarySearch(0, n-1, find, arr, 0);
}