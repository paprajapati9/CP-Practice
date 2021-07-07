#include<bits/stdc++.h>

using namespace std;

bool isPrime(int x){
	for (int i = 2; i < x; ++i)
	{
		if(x%i == 0) return false;
	}
	return true;
}


int main(int argc, char const *argv[])
{
	int n, i;
	cin>>n;

	for (i = 1; i < 1000; ++i)
	{
		if(!isPrime(n*i + 1)) {
			cout<<i;
			return 0;
		}
	}
	return 0;
}