//Possible Words From Phone Digits
/*Given a keypad of feature phone(Old phones in which 2 represents ABC and so on..), and an N digit number which is represented by array a[], the task is to list all words which are possible by pressing these numbers.*/
/*Example: Array:{2,3}
Output : ad ae af bd be bf cd ce cf.*/
//Possible Words From Phone Digits
/*Given a keypad of feature phone(Old phones in which 2 represents ABC and so on..), and an N digit number which is represented by array a[], the task is to list all words which are possible by pressing these numbers.*/
/*
Example: Array:{2,3}
Output : ad ae af bd be bf cd ce cf.
*/
#include<bits/stdc++.h>
#include<vector>
using namespace std;
void findCombinations(map<int,string> &m, int arr[], string res, int index,int n,vector<string> &v)
{
    // If processed every digit of key, push result
    if (index == n) {
        v.push_back(res);
        return;
    }

    // Stores current digit
    int digit = arr[index];

    // Size of the string corresponding to current digit
    int len = m[digit].size();

    // One by one replace the digit with each character in the
    // corresponding list and recur for next digit
    for (int i = 0; i < len; i++) {
    	auto it=m.find(digit);
		string temp=it->second;
        findCombinations(m, arr,  res+temp[i], index + 1,n,v);
    }
}
vector<string> possibleWords(int a[], int N)
{
        //Your code here
        vector<string> v;
        map<int,string> m;
        m.insert({2,"abc"});
        m.insert({3,"def"});
        m.insert({4,"ghi"});
        m.insert({5,"jkl"});
        m.insert({6,"mno"});
        m.insert({7,"pqrs"});
        m.insert({8,"tuv"});
        m.insert({9,"wxyz"});
        
        findCombinations(m,a,string(""),0,N,v);
        return v;
}
int main()
{
	int N;
	cin>>N;
	int arr[N];
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	vector<string> v=possibleWords(arr,N);
	for(string x:v){
		cout<<x<<" ";
	}
	return 0;
}