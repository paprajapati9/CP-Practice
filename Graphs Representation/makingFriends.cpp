#include<bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[])
{
	int testCases, nStudents, mFriends;
	cin>>testCases;
	while(testCases--){
		cin>>nStudents>>mFriends;
		if(nStudents%2 == 0 && nStudents/2 >= mFriends) cout<<"Yes\n";
		else if(mFriends == 0) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}