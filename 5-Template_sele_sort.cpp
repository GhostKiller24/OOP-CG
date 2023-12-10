#include<iostream>
using namespace std;
template <typename t>
void selection(t array[],int n){
    int minm;
    for(int i=0;i<n-1;i++){
        minm=i;
        for(int j=i+1;j<n;j++){
            if(array[j]<array[minm])
                minm=j;
        }
        t temp=array[i];
        array[i]=array[minm];
        array[minm]=temp;
    }
    cout<<"Array after sorting: "<<endl;
    for(int i=0;i<n;i++){
        cout<<array[i]<<",";
    }
    cout<<endl;
}
int main(){
    int n;
    cout<<"Enter array length: "<<endl;
    cin>>n;
    int array[n];
    float arr[n];
    cout<<"Enter int array"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Enter the element at index : "<<i<<":"<<endl;
        cin>>array[i];
    }
    cout<<"Enter float array"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Enter the element at index : "<<i<<":"<<endl;
        cin>>arr[i];
    }
    selection(array,n);
    selection(arr,n);
    return 0;
}