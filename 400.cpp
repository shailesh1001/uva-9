// uva 400 
// acutally this is a math problem. we first caculate how many words can be contain in a row
// count_per_row = (60 + 2) / (maxlen+2)    (maxlen is the longest word's length)
// then we need to calculate row_per_column minimum. this is a inequality problem in math.
// the last column contains words: n - (count_per_row-1) * row_per_column
// and this value has to satisfy the following condition
// 0 <= n - (count_per_row-1) * row_per_column <= n    (n is the number of words)
// solve this inequality, we get row_per_column is minimum when it is the ceil of n / count_per_row

#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
int main(){
	int n,k=0,maxlen=0;
	char dash[61];
	memset(dash,'-',sizeof(dash));
	dash[60]='\0';

	while((scanf("%d",&n))!=EOF) {
		k=0;
		maxlen=0;
		string *s = new string[n];
		for(int i=0;i<n;i++) {
			cin>>s[k];
			int len = s[k].length();
			if(len>maxlen)
				maxlen = len;
			k++;
		}
		vector<string> vec(s,s+k);
		sort(vec.begin(),vec.end());
		int count_per_row = 62/(maxlen+2);
		int row_per_column = ceil(n*1.0/count_per_row);
	
		cout<<dash<<endl;
		for(int i=0;i<row_per_column;i++) {
			for(int j=i,k=1;j<n;j+=row_per_column,k++) {
				if(k%count_per_row==0) {
					cout<<vec[j];
					for(int u=0;u<maxlen-vec[j].length();u++)
						cout<<" ";
				}
				else {
					cout<<vec[j];
					for(int u=0;u<maxlen-vec[j].length();u++)
						cout<<" ";
					cout<<"  ";
				}
			}
			cout<<endl;
		}
		delete [] s;
	}

}