#include<bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[])
{
	int nPlanes, i=0, a, b, c;
	cin>>nPlanes;
	int graph[nPlanes];

	while(i < nPlanes){
		cin>>graph[i];
		i++;
	}

	for (i = 0; i < nPlanes; ++i)
	{
		a = graph[i]-1;
		b = graph[a]-1;
		c = graph[b]-1;
		if(i == c){
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}