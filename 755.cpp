// uva 755
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

const char *mm[] = { "0", "1", "2ABC", "3DEF", "4GHI", "5JKL", "6MNO", "7PRS", "8TUV", "9WXY" };

char map[128],line[1048576];
vector<string> phones;

int main() {
	int N;

	memset(map,0,sizeof(map));
	for(int i=0;i<10;i++)
		for(int j=0;mm[i][j];j++)
			map[mm[i][j]] = i+'0';
	scanf("%d",&N);
	getchar();
	getchar();
	for(int nn=0;nn<N;nn++) {
		int n=0;
		phones.clear();
		scanf("%d",&n);
		getchar();
		for(int i=0;i<n;i++) {
			cin.getline(line,100048);
			int len = strlen(line);
			string phone="";
			for(int j=0;j<len;j++) {
				if(line[j]!='-') {
					phone += map[line[j]];
				}
			}
			phones.push_back(phone);
		}
		sort(phones.begin(),phones.end());
		bool found=false;
		int count;
		int i,j;
		for(i=0;i<phones.size();) {
			count =1;
			for(j=i+1;j<phones.size()&&phones[i]==phones[j];j++) 
				count++;
			if(count>1) {
				found = true;
				for(int k=0;k<phones[i].length();k++) {
					if(k==2)
						cout<<phones[i].at(k)<<"-";
					else
						cout<<phones[i].at(k);
				}
				cout<<" "<<count<<endl;
			}
			i=j;
		}
		if(!found)
			cout<<"No duplicates."<<endl;
		if(nn!=N-1)
			cout<<endl;
	}

}