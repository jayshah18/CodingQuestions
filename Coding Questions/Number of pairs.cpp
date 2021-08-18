/*
Q.) Given two arrays X and Y of positive integers, 
find the number of pairs such that xy > yx (raised to power of) where x is an element from X and y is an element from Y.
Input: 
M = 3, X[] = [2 1 6] 
N = 2, Y[] = [1 5]
Output: 3
Explanation: 
The pairs which follow x^y > y^x are 
as such: 2^1 > 1^2,  2^5 > 5^2 and 6^1 > 1^6 

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll Count(int x,int Y[],int n,int arr[]){
	//if x is zero then there is no pair
	if(x==0){
        return 0;
	}
	//if x is 1 then the pairs are , no. of zeros in Y..	  
    if(x==1){
       return arr[0];
    }
    
    auto it=upper_bound(Y,Y+n,x);
    ll ans=(Y+n)-it;
    ans+=arr[0]+arr[1];
	//if x is 2 then decrement the count of 3's and 4's in y from the ans..
	if(x==2){
	    ans-=(arr[3]+arr[4]);
    }
    //if x is 3 then decrement the count of count of 2's from the ans..
    if(x==3){
        ans+=arr[2];
    }
    return ans;
}
ll countPairs(int X[], int Y[], int M, int N)
{
	//The trick to this question is if y > x, then then x^y > y^x with some exceptions.
   int arr[5]={0};
   for(int i=0;i<N;i++){
       if(Y[i]<5){
           arr[Y[i]]++;
       }
   }
   sort(Y,Y+N);
   long long cnt=0;
   for(int i=0;i<M;i++)
   {
       cnt+=Count(X[i],Y,N,arr);
   }
   return cnt;
}
int main()
{
	ll N,M;
	cin>>N>>M;
	ll X[N];
	ll Y[M];
	for(ll i=0;i<N;i++){
		cin>>X[i];
	}
	for(ll i=0;i<M;i++){
		cin>>Y[i];
	}
	cout<<countPairs(X,Y,N,M)<<endl;
	return 0;
}
