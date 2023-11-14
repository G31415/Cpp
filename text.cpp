#include <algorithm>
#include <stdio.h>
#include <string.h>
#define N 110
char a[N];
int S[N];
int p, q, r, s, t;
void fore()
{
    int k = 0, t1, t2;
    int l = strlen(a);
    for (int i = l - 1; i >= 0; i--)
    {
        if (a[i] == 'p')
            S[k++] = p;
        else if (a[i] == 'q')
            S[k++] = q;
        else if (a[i] == 'r')
            S[k++] = r;
        else if (a[i] == 's')
            S[k++] = s;
        else if (a[i] == 't')
            S[k++] = t;
        else if (a[i] == 'K')
        {
            t1 = S[--k];
            t2 = S[--k];
            S[k++] = (t1 && t2);
        }
        else if (a[i] == 'A')
        {
            t1 = S[--k];
            t2 = S[--k];
            S[k++] = (t1 || t2);
        }
        else if (a[i] == 'N')
        {
            t1 = S[--k];
            S[k++] = (!t1);
        }
        else if (a[i] == 'C')
        {
            t1 = S[--k];
            t2 = S[--k];
            if (t1 == 1 && t2 == 0)
                S[k++] = 0;
            else
                S[k++] = 1;
        }
        else if (a[i] == 'E')
        {
            t1 = S[--k];
            t2 = S[--k];
            if (t1 == t2)
                S[k++] = 1;
            else
                S[k++] = 0;
        }
    }
}
bool slove()
{
    for (p = 0; p <= 1; p++)
        for (q = 0; q <= 1; q++)
            for (r = 0; r <= 1; r++)
                for (s = 0; s <= 1; s++)
                    for (t = 0; t <= 1; t++)
                    {
                        fore();
                        if (!S[0])
                            return 0;
                    }
    return 1;
}
int main()
{
    while (gets(a) && a[0] != '0')
    {
        if (slove())
            printf("tautology\n");
        else
            printf("not\n");
    }
    return 0;
}
