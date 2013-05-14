#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main() {
	int n=0;
	string a[2];
	string s[5];
	string output="";
	int arrowpos[4]; // four arrow positions
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++) {
		getline(cin,a[0]);
		getline(cin,a[1]);
		int k=0;

		//process for the first sentence
		output = "";
		for(int j=0;j<a[0].size();j++) {
			if(a[0].at(j)!='<' && a[0].at(j)!='>') {
				output += a[0].at(j);
			} else {
				arrowpos[k++] = j;
			}
		}
		s[0] = arrowpos[0] == 0 ? "" : a[0].substr(0,arrowpos[0]-0);
		s[1] = a[0].substr(arrowpos[0]+1,arrowpos[1]-arrowpos[0]-1);
		s[2] = a[0].substr(arrowpos[1]+1,arrowpos[2]-arrowpos[1]-1);
		s[3] = a[0].substr(arrowpos[2]+1,arrowpos[3]-arrowpos[2]-1);
		s[4] = arrowpos[3] == a[0].size()-1 ? "" : a[0].substr(arrowpos[3]+1,a[0].size()-arrowpos[3]-1);
		cout<<output<<endl;

		//process for the second sentence
		a[1] = a[1].substr(0,a[1].size()-3);
		output = a[1] + s[3] + s[2] + s[1] + s[4];
		cout<<output<<endl;
	}
	return 0;
}