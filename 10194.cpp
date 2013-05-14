// uva 10194
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<map>
#include<cctype>
using namespace std;
struct Team {
	int points,wins, ties, losses, goaldiff,goalscore,goalagainst,plays;
	string name;
	string name_lc;
	Team():points(0),wins(0),ties(0),losses(0),goaldiff(0),goalscore(0),goalagainst(0),plays(0){} //needs to define here
	bool operator()(Team a, Team b) {
		return (a.points>b.points || 
				a.points==b.points && a.wins>b.wins || 
				a.points==b.points && a.wins==b.wins && a.goaldiff>b.goaldiff || 
				a.points==b.points && a.wins==b.wins && a.goaldiff==b.goaldiff && a.goalscore>b.goalscore || 
				a.points==b.points && a.wins==b.wins && a.goaldiff==b.goaldiff && a.goalscore==b.goalscore && a.plays < b.plays || 
				a.points==b.points && a.wins==b.wins && a.goaldiff==b.goaldiff && a.goalscore==b.goalscore && b.plays == a.plays && a.name_lc<b.name_lc);
	}
};

int main() {	
	int N,T,G;	
	scanf("%d",&N);
	getchar();
	for(int i=0;i<N;i++) {
		map<string,Team*> tour;
		string tourname;
		
		getline(cin,tourname);
		scanf("%d",&T);
		getchar();
		vector<string> teams;
		for(int j=0;j<T;j++) {
			string teamname,teamname_lc;
			getline(cin,teamname);
			Team *teamp = new Team;
			teamp->name = teamname;//other value should be initialized by the default constructor to 0
			teamname_lc.resize(teamname.size());
			transform(teamname.begin(),teamname.end(),teamname_lc.begin(),::tolower);
			teamp->name_lc = teamname_lc;
			tour[teamname] = teamp;
		}
		scanf("%d",&G);
		getchar();
		string game;
		for(int j=0;j<G;j++) {

			getline(cin,game);
			int firsthashpos = game.find_first_of("#",0);
			int secondhashpos = game.find_first_of("#",firsthashpos+1);
			int atpos = game.find_first_of("@",0);
			string leftname = game.substr(0,firsthashpos);
			string leftgoal = game.substr(firsthashpos+1,atpos-firsthashpos-1);
			string rightgoal= game.substr(atpos+1,secondhashpos-atpos-1);
			string rightname = game.substr(secondhashpos+1,game.length()-secondhashpos-1);
			
			int leftgoal_int = atoi(leftgoal.c_str());
			int rightgoal_int = atoi(rightgoal.c_str());

			Team *teamp_left = tour[leftname];
			Team *teamp_right = tour[rightname];
			teamp_left->goalscore = teamp_left->goalscore + leftgoal_int;
			teamp_left->goalagainst = teamp_left->goalagainst + rightgoal_int;
			teamp_right->goalscore = teamp_right->goalscore + rightgoal_int;
			teamp_right->goalagainst = teamp_right->goalagainst + leftgoal_int;
			(teamp_left->plays)++;
			(teamp_right->plays)++;

			if(leftgoal_int>rightgoal_int) {
				(teamp_left->wins)++;
				(teamp_right->losses)++;
				teamp_left->points = teamp_left->points + 3;		
			} else if(leftgoal_int<rightgoal_int) {
				(teamp_right->wins)++;
				(teamp_left->losses)++;
				teamp_right->points = teamp_right->points + 3;
			} else {
				(teamp_right->ties)++;
				(teamp_left->ties)++;
				teamp_left->points = teamp_left->points + 1;
				teamp_right->points = teamp_right->points + 1;
			}
		}
		// start to update each teams goals diff
		vector<Team> vec;
		for(map<string,Team*>::iterator it=tour.begin();it!=tour.end();it++) {
			it->second->goaldiff = it->second->goalscore - it->second->goalagainst;
			vec.push_back(*(it->second));
		}
		sort(vec.begin(),vec.end(),Team());
		cout<<tourname<<endl;
		for(int j=0;j<T;j++) {
			cout<<j+1<<") "<<vec[j].name<<" "<<vec[j].points<<"p, "<<vec[j].plays<<"g ("<<vec[j].wins<<"-"<<vec[j].ties<<"-"<<vec[j].losses<<"), "<<vec[j].goaldiff<<"gd ("<<vec[j].goalscore<<"-"<<vec[j].goalagainst<<")"<<endl;
		}
		// unleash memory
		for(map<string,Team*>::iterator it=tour.begin();it!=tour.end();it++) {
			delete it->second;
		}
		if(i!=N-1)
			cout<<endl;
		
	}
}