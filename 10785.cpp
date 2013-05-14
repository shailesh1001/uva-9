//uva 10785

#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
const string sequence("AJAJAJAJAJASASASASASABABABABABAKAKAKAKAKATUTUTUTUTUCUCUCUCUCULULULULULUDUDUDUDUDUMUMEMEMEMEVEVEVEVEVENENENENENEWEWEWEWEWEFEFEFOFOFOXOXOXOXOXOGOGOGOGOGOPOPOPOPOPOYOYOYOYIYIHIHIHIHIHIQIQIQIQIQIZIZIZIZIZIRIRIRIRIR");

int main() {
	int N;
	scanf("%d",&N);
	getchar();
	for(int i=1;i<=N;i++) {
		int n;
		scanf("%d",&n);
		getchar();
		string ans = sequence.substr(0,n);
		string odd="",even="";
		for(int j=0;j<ans.size();j+=2) 
			even += ans[j];
		for(int j=1;j<ans.size();j+=2) 
			odd += ans[j];
		sort(odd.begin(),odd.end());
		sort(even.begin(),even.end());
		cout<<"Case "<<i<<": ";
		string output="";
		for(int j=0;j<ans.size();j++){
			if(j%2==0)
				output+=even[j/2];
			else
				output+=odd[(j-1)/2];
		}
		cout<<output<<endl;
	}
	return 0;
}