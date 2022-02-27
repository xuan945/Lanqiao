#include <cstring>
#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

typedef long long LL;
const int N = 300010;

int n;
LL sum[N], a[N], s0, sn;
bool st[N];

int main()
{
    int T;
    scanf("%d", &T);
    while (T -- )
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ )
        {
            scanf("%lld", &sum[i]);
            sum[i] += sum[i - 1];
        }

        s0 = sum[0], sn = sum[n];
        if (s0 > sn) swap(s0, sn);

        sort(sum, sum + n + 1);

        for (int i = 0; i <= n; i ++ )
            if (s0 == sum[i])
            {
                s0 = i;
                break;
            }
        for (int i = n; i >= 0; i -- )
            if (sn == sum[i])
            {
                sn = i;
                break;
            }

        memset(st, 0, sizeof st);
        int l = 0, r = n;
        for (int i = s0; i >= 0; i -= 2)
        {
            a[l ++ ] = sum[i];
            st[i] = true;
        }
        for (int i = sn; i <= n; i += 2)
        {
            a[r -- ] = sum[i];
            st[i] = true;
        }
        for (int i = 0; i <= n; i ++ )
            if (!st[i])
            {
                a[l ++ ] = sum[i];
            }

        LL res = 0;
        for (int i = 1; i <= n; i ++ ) res = max(res, abs(a[i] - a[i - 1]));
        cout << res << endl;
    }
    return 0;
}
