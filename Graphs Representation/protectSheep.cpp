#include<bits/stdc++.h>

using namespace std;

/**
 * Author : Pankaj Prajapati
 * Question Link : https://codeforces.com/problemset/problem/948/A
 */


bool isInRange(int pos, int totalSize){
	if(pos >= 0 && pos < totalSize) return true;
	return false;
}


/**
 * We just see it's possible to surround all four edges of sheep with a dog or sheep
 * such that there is no edge in graph of sheep to wolf.
 */
int main(int argc, char const *argv[])
{
	int rows, columns;
	bool valid = true;
	cin>>rows>>columns;
	char graph[rows][columns];
	string str;

	for (int i = 0; i < rows; ++i)
	{
		cin>>str;
		for (int j = 0; j < columns; ++j)
		{
			graph[i][j] = str[j];
		}
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			if(graph[i][j] == 'S'){
				
				if(j+1 < columns) { //valid right
					if(graph[i][j+1] == 'W') {
						valid = false;
						break;
					}
					if(graph[i][j+1] == '.') {
						graph[i][j+1] = 'D';
					}
				}
				if(j-1 >= 0) { //valid right
					if(graph[i][j-1] == 'W') {
						valid = false;
						break;
					}
					if(graph[i][j-1] == '.') {
						graph[i][j-1] = 'D';
					}
				}
				if(i+1 < rows) { //valid right
					if(graph[i+1][j] == 'W') {
						valid = false;
						break;
					}
					if(graph[i+1][j] == '.') {
						graph[i+1][j] = 'D';
					}
				}
				if(i-1 >= 0) { //valid right
					if(graph[i-1][j] == 'W') {
						valid = false;
						break;
					}
					if(graph[i-1][j] == '.') {
						graph[i-1][j] = 'D';
					}
				}
			}
			if(!valid) break;
		}
		if(!valid) break;
	}
	if(valid) {
		cout<<"YES"<<endl;
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				cout<<graph[i][j];
			}
			cout<<"\n";
		}
	}
	else cout<<"NO";
	return 0;
}