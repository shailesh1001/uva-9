#include<iostream>
#include<string>
#include<cctype>
#include<set>
#include<vector>
#include<cstdio>
using namespace std;

int count_match(set<string> &keyword_set, string );
int main() {
	int a,b,n=1;
	string *keywords;
	string *excuses;
	string *excuses_lc;
	int *excuses_key_hit_count;
	int worst_count = 0;
	while(EOF!=(scanf("%d %d",&a,&b))) {
		getchar();
		worst_count = 0;
		keywords = new string[a];
		excuses = new string[b];
		excuses_lc = new string[b];
		excuses_key_hit_count = new int[b];
		set<string> keyword_set;

		for(int i=0;i<a;i++) {
			getline(cin,keywords[i]);
			keyword_set.insert(keywords[i]);
		}
		for(int i=0;i<b;i++) {
			getline(cin,excuses[i]);
			excuses_lc[i] = "";
			for(int j=0;j<excuses[i].size();j++) {
				excuses_lc[i] += tolower(excuses[i][j]);      //cannot written as excuses_lc[i][j] = tolower(excuses[i][j])
															 // the reason maybe that excuses_lc[i][j] is an invalid address access
			}
			//printf("excuses:\n%s\nexcuses_ls:\n%s\n",excuses[i].c_str(),excuses_lc[i].c_str());

			int count = count_match(keyword_set,excuses_lc[i]);
			excuses_key_hit_count[i] = count;
			if(count > worst_count) {
				worst_count = count;
			}
		}
		printf("Excuse Set #%d\n",n);
		for(int i=0;i<b;i++) {
			if(excuses_key_hit_count[i]==worst_count) {
				cout<<excuses[i]<<endl;
			}
		}
		cout<<endl;
		delete [] keywords;
		delete [] excuses;
		delete [] excuses_lc;
		delete [] excuses_key_hit_count;
		n++;
	}
	return 0;
}


int count_match(set<string> &keyword_set, string s) {
	//split the string
	int start=0;
	vector<string> words;
	int count=0;
	for(int i=0;i<s.size();){
		if(!isalnum(s[i])) {
			while(!isalnum(s[i]) && i<s.size()) 
				i++;
			start = i;
		} else {
			while(isalnum(s[i]) && i<s.size()) 
				i++;
			words.push_back(s.substr(start,i-start));
			start = i;
		}
	}

	for(vector<string>::iterator iter=words.begin();iter!=words.end();iter++) {
		if(keyword_set.count(*iter)) 
			count++;
	}
	
	return count;
}