#include <stdio.h>

int main()
{
    int n, t, count[21] = {0};
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &t);
        count[t + 10] += 1;
    }
    long long result = (long long)(count[10]) * (long long)(count[10] - 1) /2;
    for (int i = 0; i < 10; ++i)
    {
        result += (long long)(count[i]) * (long long)(count[20 - i]);
    }
    printf("%lld", result);
    return 0;
}
