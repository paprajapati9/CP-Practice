#include<bits/stdc++.h>

using namespace std;

/**
 * Author : Pankaj Prajapati
 * Question Link : https://codeforces.com/problemset/problem/115/A
 */


/**
 * We essentially need to find out length of the longest path in the graph
 * Or we can describe it as the height of the connected tree in the graph
 * that would indicate the minimum number of groups.
 */
int main(int argc, char const *argv[])
{
	int nEmp, i=0, empNo, level = 1, maxLevel=1, k;
	cin>>nEmp;
	int graph[nEmp];

	while(i < nEmp){
		cin>>empNo;
		graph[i] = empNo == -1 ? empNo : empNo-1;
		i++;
	}

	for (i = 0; i < nEmp; ++i)
	{
		k = i;
		while(graph[k] != -1){
			level++;
			k = graph[k];
		}
		if(maxLevel < level) maxLevel = level;
		level = 1;
	}
	cout<<maxLevel;
	return 0;
}