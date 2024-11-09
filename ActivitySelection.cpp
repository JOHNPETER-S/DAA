//Activity selection problem in greedy algorithm

#include <bits/stdc++.h>
using namespace std;
struct Arr{
    int id;
    int st;
    int end;
};
int main() {
    int n;
    cin>>n;
    Arr arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].id;
        cin>>arr[i].st;
        cin>>arr[i].end;
        if(arr[i].st>arr[i].end){
            cout<<"Invalid input";
            return 0;
        }
    }
    int temp=0;
  //sort the arr based on the ending time
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j].end>arr[j+1].end){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    cout<<arr[0].id<<" ";
    int count=1;
    int i=1;
  //if the next event time starts after the first event ending time then it will not overlap
    while(i<n){
        if(arr[0].end<=arr[i].st){
            cout<<arr[i].id<<" ";
            count++;
        }
        i++;
    }
    cout<<endl<<count;
    return 0;
}
