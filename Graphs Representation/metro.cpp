#include<bits/stdc++.h>

using namespace std;

/**
 * Author : Pankaj Prajapati
 * Question Link : https://codeforces.com/problemset/problem/1055/A
 */

int main(int argc, char const *argv[])
{
	int nStations, des, i, isTrackConnectedMidway;
	cin>>nStations>>des;
	int track1[nStations], track2[nStations];
	des--;

	for (i = 0; i < nStations; ++i)
	{
		cin>>track1[i];
	}
	for (i = 0; i < nStations; ++i)
	{
		cin>>track2[i];
	}

	if(!track1[0]){
		cout<<"NO";
		return 0;
	}else if(track1[des]) {
		cout<<"YES";
		return 0;
	}

	isTrackConnectedMidway = 0;
	for (int i = des; i < nStations; ++i)
	{
		if(track1[i] && track2[i]) {
			isTrackConnectedMidway = 1;
			break;
		}
	}

	if(track2[des] && isTrackConnectedMidway) {
		cout<<"YES";
	}else{
		cout<<"NO";
	}

	return 0;
}