#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *_a, const void *_b) {
    char *a = (char*)_a;
    char *b = (char*)_b;

    return strcmp(a, b);
}

// 根据len长度的字符串，不足以空格补齐
void print(char st[], int len) {
    int tmp = len - strlen(st);
    printf("%s", st);
    while (tmp--)
        printf(" ");
}

int main() {
    int n;
    char s[105][65];

    while (scanf("%d", &n) != EOF) {
        int lMax, c, r;
        lMax = c = r = 0;
        for (int i=0; i<n; i++) {
            scanf("%s", s[i]);
            int tmp = strlen(s[i]);
            if (tmp > lMax)
                lMax = tmp;
        }
        c = 62 / (lMax+2);                      // 计算列数
        r = (n+c-1) / c;                        // 计算行数

        qsort(s, n, sizeof (s[0]), cmp);

        printf("------------------------------------------------------------\n");
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                int tmp = j*r + i;

                if (tmp >= n) continue;

                if (tmp >= ((int)((n-1)/r))*r)  // 如果为最后一列
                    print(s[tmp], lMax);
                else
                    print(s[tmp], lMax+2);
            }
            printf("\n");
        }

    }

    return 0;
}
