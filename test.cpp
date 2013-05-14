// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;




int compare_ch(const void* _a, const void* _b) 
{
	char *a = (char*)_a;
	char *b = (char*)_b;
	return *a-*b;
}

int main () {
  char s[100] = "lone";
  string ss[4] = {"hello","sdfdsf","aour","thrie"};
  int ii[4] = {3,4,1,6};
  qsort(s,4,sizeof(char),compare_ch);
  puts(s);
  for(int i=0;i<4;i++)
  	cout<<ss[i]<<endl;
  sort(ss,ss+4);

  for(int i=0;i<4;i++)
  	cout<<ss[i]<<endl;

  for(int i=0;i<4;i++)
  	cout<<ii[i]<<endl;
  sort(ii,ii+4);

  for(int i=0;i<4;i++)
  	cout<<ii[i]<<endl;


  vector<string> vec(ss,ss+4);

  sort(vec.begin(),vec.end());
   for(int i=0;i<4;i++)
  	cout<<vec[i]<<endl;

  int chch[10]={1,2,3,4,5,5,6,6,7,0};
  int *p = chch;


  cout<<sizeof(chch)<<endl;
  cout<<sizeof(p)<<endl;
  cout<<sizeof(int)<<endl;
  cout<<sizeof(char)<<endl;
  cout<<sizeof(double)<<endl;
  cout<<sizeof(int*)<<endl;
  cout<<sizeof(char*)<<endl;
  cout<<sizeof(double*)<<endl;


  string bb = "hello";
  int a = 12;
  bb = bb + a;
  cout<<bb+12<<endl;

  int bbb[a];
  for(int i=0;i<a;i++) {
      bbb[i]=i+1;
      printf("bbb %d\n",bbb[i]);
  }

  return 0;
}