/*
Q.) Given an integer array representing the heights of N buildings; 
the task is to delete N-2 buildings such that the water that can be trapped between the remaining two building is maximum.
*/
/*
Input:
N = 6
height[] = {2,1,3,4,6,5}
Output: 8
Explanation: The heights are 2 1 3 4 6 5.
So we choose the following buildings
2 1 3 4 6 5  and remove others. So total
removed buildings is equal to 4, now the
height of smaller one is 2. So answer is
2 * removed buildings = 2*4 = 8. There is
no answer greater than this.*/
#include<bits/stdc++.h>
using namespace std;
int maxWater(int height[], int n) 
{         
    int sum=0;
	int l=0;
    int r=n-1;
    int i=2;
    int mx=0;
    while(l<r){
        int mini=min(height[l],height[r]);
        sum=mini*(n-i);
        if(height[l]<height[r]){
            l++;
        }
        else{
            r--;
        }
        mx=max(sum,mx);
        i++;
    }
    return mx;
} 
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<maxWater(arr,n);
	return 0;
}
