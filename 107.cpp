// uva 107 一道数学题 网上抄来的：http://www.cppblog.com/csu-yx/archive/2012/05/07/173913.html
// http://hi.baidu.com/tomtongjiantao/item/6a3f30f76a31acd66225d25b   更简单一些

#include <stdio.h>
#include <math.h>

int main()
{
    int nInitH, nOnes;
    int nN, n;

    while (scanf("%d%d", &nInitH, &nOnes), nInitH + nOnes)
    {
        int nBeg = 1;
        int nEnd = nOnes;
        int nMid;
    
        while (nBeg <= nEnd)
        {
            nMid = (nBeg + nEnd) / 2;
            
            double fRes = log10(nInitH) * log10(nMid);
            double fTemp = log10(nMid + 1) * log10(nOnes);
            if (fabs(fRes - fTemp) < 1e-10)
            {
                //printf("Find nN:%d\n", nMid);
                nN = nMid;
                break;
            }
            else if (fTemp > fRes)
            {
                nBeg = nMid + 1;
            }
            else
            {
                nEnd = nMid - 1;
            }
        }
        
        n = floor(log10(nInitH) / log10(nN + 1) + 1e-9);
        //printf("nN:%d, n:%d\n", nN, n);

        int nSum = 0;
        int nLazy = 0;
        int nNum = 1;
        for (int i = 0; i <= n; ++i)
        {
            nSum += nNum * nInitH;
            nLazy += nNum;
            nNum *= nN;
            nInitH /= (nN + 1);
        }
        
        printf("%d %d\n", nLazy - nOnes, nSum);
    }

    return 0;
}
