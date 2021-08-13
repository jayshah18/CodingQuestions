/*Q.We have an array of size n. we have to return the maximum subarray sum in normal array or it might be in circular fashion.
Approach:1)find the maximum sum of subarray in array with normal kadane's algorithm.
         2)Then find the maximum sum of subarray in circular fashion.
         3)return the maximum sum.
*/
#include<bits/stdc++.h>
using namespace std;
int kadane(int arr[],int n){
    int mx=arr[0];
    int prev=arr[0];
    for(int i=1;i<n;i++){
        prev=max(arr[i],arr[i]+prev);
        mx=max(mx,prev);
    }
    return mx;
}
int circularSubarraySum(int arr[], int num){
	
    int mx_val=kadane(arr,num);
    if(mx_val<0){    
        return mx_val;  //we have to check this for Negative array
    }
    int arr_sum=0;
    for(int i=0;i<num;i++){
	        arr_sum+=arr[i];
        arr[i]=-arr[i];
    }
  //The total sum minus some elements gives the sum of remaining elements(subarray in circular fashion).
    int circular_sum = arr_sum + kadane(arr,num);
    return max(circular_sum , mx_val);
}
int main()
{
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<circularSubarraySum(arr,n)<<endl;
}
