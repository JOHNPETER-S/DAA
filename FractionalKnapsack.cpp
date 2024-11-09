//Fractional knapsack method in greedy algorithm

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int weight[n];
    for(int i=0;i<n;i++)cin>>weight[i];
    int profit[n];
    for(int i=0;i<n;i++)cin>>profit[i];
    int money;
    cin>>money;
    int temp=0;
    for(int i=0;i<n-1;i++){
        if(money<weight[i]){
            cout<<"Invalid input";
            return 0;
        }
        
        if(profit[i]/weight[i] < profit[i+1]/weight[i+1]){
            temp=profit[i];
            profit[i]=profit[i+1];
            profit[i+1]=temp;
            temp=weight[i];
            weight[i]=weight[i+1];
            weight[i+1]=temp;
        }
    }
    int total=0;
    int price=0;
    for(int i=0;i<n;i++){
        if(money>=weight[i]){
            total+=profit[i];
            money=money-weight[i];
        }else{
            price=profit[i]/weight[i];
            total+=money*price;
        }
    }
    cout<<total;
}
