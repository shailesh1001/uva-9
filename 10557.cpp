// uva 10557 digraph
// thought from http://blog.csdn.net/shuangde800/article/details/7726777
// I made some slight changes to his code

// We assume that when it enters the finish room with positive energy we win. Original problem description is vague in this concept.

#include<cstdio>
#include<cstring>
struct Room {
	int val,nNext; // number of adjacent rooms
	int reach[105]; // assume that it can have 150 neighbours
};
Room room[105];
int nRoom; //the number of rooms
int energy[105]; // store the energy value when the person enters room #i also it will act as the flag as whether this room has been visited
int queue[100000]; 
bool v[105],flag;

// search whether this room can lead to finish room can use dfs too but bfs is easier to code in this problem
void bfs(int pos) {
	memset(v,0,sizeof(v));
	v[pos]=true;
	int front=0,rear=0;
	queue[rear++] = pos;
	while(front<rear) {
		int q = queue[front++];
		if(q == nRoom-1) {flag = true;return;}
		for(int i=0;i<room[q].nNext;i++) {
			int m = room[q].reach[i];
			if(!v[m]) {
				v[m] = true;
				queue[rear++] = m;
			}
		}
	}
}

// enter room #pos with energy value of val
// precondition: val is greater than zero
void dfs(int pos, int val) {
	if(flag || pos<0 || pos>=nRoom) return;
	
	if(pos==nRoom-1) {flag = true; return;}
	for(int i=0;i<room[pos].nNext;i++) {
		int m = room[pos].reach[i];
		// if m is visited before and there is positive loop back to this room, then 
		// we can simply check if this room can ever lead to the finish room, because 
		// positive loop means we can go throught this loop to get infinite energy and
		// then find the way to finish room
		
		if(flag) return; //if some branch find the way out, we do trimming, no need to dfs anymore

		if(energy[m] && energy[m] < room[m].val + val) {
			bfs(pos);
			if(flag) return;
		}
		if(!energy[m] && val+room[m].val>0) {  // only when it is a positive value do we enter into next dfs
			energy[m] = val + room[m].val;
			dfs(m,energy[m]);  // if some branch return here with success flag set, we don't need to do rest of the for loop. So, we do trmming, see above
		}
	}
}

int main() {
	while(~scanf("%d",&nRoom) && nRoom != -1) {
		for(int i=0;i<nRoom;i++) {
			scanf("%d %d",&room[i].val,&room[i].nNext);
			for(int j=0;j<room[i].nNext;j++) {
				int temp;
				scanf("%d",&temp);
				room[i].reach[j] = temp-1; //we numbered room from 0
			}
		}
		memset(v,0,sizeof(v));
		memset(energy,0,sizeof(energy));
		energy[0] = 100;
		flag = false;
		dfs(0,100);
		if(flag) printf("winnable\n");
		else printf("hopeless\n");
	}
	return 0;
}