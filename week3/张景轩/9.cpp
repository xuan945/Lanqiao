#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200010;

int n, m;
int a[maxn];

int main()
{
    scanf("%d%d", &n, &m);
    int k = n + m + 1;
    LL sum = 0;
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];	//求这些数的和 
    }
    sort(a, a + k);

    if (a[0] >= 0)	//第一个数大于0，说明没有负数，因为之前加过一次a[0]，然后我们本来就需要减掉a[0]，所以减掉2*a[0] 
    {
        if (m) sum -= 2 * a[0];
    }
    else		//如果是负数的那么我们需要加上，因为之前是负数，加上去也就相当于减掉,所以-=2*a[i](a[i]<0) 
    {
        for (int i = 0; i < k && a[i] < 0 && m > 0; i++ )
        {
            sum -= a[i] * 2;
            m-- ;
        }
    }

    cout << sum << endl;
    return 0;
}
