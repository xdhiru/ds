#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter length:";
    cin>>n;
    int arr1[n];
    for (int i=0;i<n;i++){
        cout<<"$";
        cin>>arr1[i];
    }

    for (int i=1;i<n;i++){
        int element=arr1[i];
        int j=i-1;
        while (arr1[j]>element & j>=0){
            arr1[j+1]=arr1[j];
            j--;
        }
        arr1[j+1]=element;
    }

    for (int i=0;i<n;i++){
        cout<<arr1[i]<<", ";
        
    }

    return 0;
}