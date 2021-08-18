/*
Q.) Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order.
Merge them in sorted order without using any extra space.
Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

Input: 
n = 4, arr1[] = [1 3 5 7] 
m = 5, arr2[] = [0 2 6 8 9]
Output: 
arr1[] = [0 1 2 3]
arr2[] = [5 6 7 8 9]
Explanation:
After merging the two 
non-decreasing arrays, we get, 
0 1 2 3 5 6 7 8 9.

*/
#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int b[],int n1,int n2)
{
	int i=0,j=0,k=n1-1;
	while(i<=k and j<n2){
		if(a[i]<b[j]){
			i++;
		}
		else{
			swap(a[k--],b[j++]);
		}
	}
	sort(a,a+n1);
	sort(b,b+n2);
}
int main()
{
	int n1,n2;
	cin>>n1>>n2;
	int a[n1];
	int b[n2];
	for(int i=0;i<n1;i++){
		cin>>a[i];
	}
	for(int i=0;i<n2;i++){
		cin>>b[i];
	}
	merge(a,b,n1,n2);
	for(int x:a){
	    cout<<x<<" ";
	}
	//cout<<endl;
	for(int x:b){
	    cout<<x<<" ";
	}
	
	return 0;
}
