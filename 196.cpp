// uva 196
// thought from http://blog.csdn.net/moyan_min/article/details/8134658
// self-coded

#include<string>
#include<cstdio>
#include<iostream>
#include<cctype>
#include<cstdlib>
using namespace std;

struct Cell {
	bool isstr; // whether this cell is an expression string or integer value
	string strval;
	int intval;
};
Cell sheet[1010][1010];

int calculate(int i,int j) {
	if(sheet[i][j].isstr==false)
		return sheet[i][j].intval;
	// evaluate expression recursively
	else {
		Cell cell = sheet[i][j];
		int col=0,row=0;
		for(int k=1;k<cell.strval.size();k++) {
			if(isalpha(cell.strval[k]))
				col = col*26 + cell.strval[k] - 'A' + 1;
			else if(isdigit(cell.strval[k]))
				row = row*10 + cell.strval[k] - '0'; 
			else {
				cell.intval += calculate(row-1,col-1);// we start from 0 but the data is from 1, so need to substract 1
				col = row = 0;
			}
		}
		sheet[i][j] = cell;
		sheet[i][j].isstr = false; // we update every cell when we calculated them, this save future recursion time
		return cell.intval;
	}
}

int main() {
	int row,col,T;
	string str;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&col,&row);
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++) {
				cin>>str;
				if(str[0]=='=') {
					Cell cell;
					cell.isstr = true;
					cell.strval = str + "+"; // add an extra plus sign for recrusion convenience later
					cell.intval = 0;
					sheet[i][j] = cell;
				} else {
					Cell cell;
					cell.isstr = false;
					cell.intval = atoi(str.c_str());
					sheet[i][j] = cell;
				}
			}
		// start to evaluate
		for(int i=0;i<row;i++) {
			printf("%d",calculate(i,0));
			for(int j=1;j<col;j++) 
				printf(" %d",calculat e(i,j));
			putchar('\n');
		}
	}
	return 0;
}