#include<stdio.h>

void forEach_(int *source, const size_t n, int (*
predicate )(int *, int *)) {
    for (size_t i = 0; i < n; i++)
        predicate(source, &source[i]);
}

int input_value(int *arr, int *value) {
    static char s[32];
    scanf("%s", s);
    arr[s[0] - 'a']++;
}

int countIf_(const int *const a, const size_t n, int (*predicate )(int)) {
    int count = 0;
    for (size_t i = 0; i < n; i++)
        count += predicate(a[i]);
    return count;
}

int counter(int value) {
    int k = value / 2;
    return k * (k - 1) / 2 + (value - k) * (value - k - 1) / 2;
}

int main()
{
    static int kk[26];
    int n, ans;
    scanf("%d", &n);

    forEach_(kk, n, input_value);

    ans = countIf_(kk, 26, counter);

    printf("%d\n", ans);
    return 0;
}