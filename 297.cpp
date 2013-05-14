// uva 297
// http://www.cppblog.com/csu-yx/archive/2012/07/08/182186.html
#include <cstdio> 
#define BLACK (1)
#define WHITE (2)
#define MAX (32)
int nStateA[MAX][MAX];
int nStateB[MAX][MAX];

char szOne[10000];
char szTwo[10000];

void GetState(int nState[MAX][MAX], char* pszLine, int& nPos,
              int nSize, int nX, int nY)
{
    if (pszLine[nPos] == 'p')
    {
        ++nPos;
        GetState(nState, pszLine, nPos, nSize / 2, nX , nY + nSize / 2);
        GetState(nState, pszLine, nPos, nSize / 2, nX, nY);
        GetState(nState, pszLine, nPos, nSize / 2, nX + nSize / 2, nY );
        GetState(nState, pszLine, nPos, nSize / 2, nX + nSize / 2, nY + nSize / 2);
     }
     else
     {
         for (int i = nX; i < nX + nSize; ++i)
         {
             for (int j = nY; j < nY + nSize; ++j)
            {
                 if (pszLine[nPos] == 'e')
                 {
 
                     nState[i][j] = WHITE;
                 }
                 else
                 {
                     nState[i][j] = BLACK;
                 }
             }
         }
         ++nPos;
     }
 }
 
 int main()
 {
     int nCases;
 
     scanf("%d\n", &nCases);
     while (nCases--)
     {
         gets(szOne);
         gets(szTwo);
         int nPos = 0;
         GetState(nStateA, szOne, nPos, MAX, 0, 0);
         nPos = 0;
         GetState(nStateB, szTwo, nPos, MAX, 0, 0);
         int nAns = 0;
 
         for (int i = 0; i < MAX; ++i)
         {
             for (int j = 0; j < MAX; ++j)
             {
                 if (nStateA[i][j] == BLACK || nStateB[i][j] == BLACK)
                 {
                     nAns++;
                 }
             }
         }
         printf("There are %d black pixels.\n", nAns);
     }
 
     return 0;
}