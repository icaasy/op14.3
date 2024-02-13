#include <stdio.h>
#include <stdlib.h>

int comp (const void * elem1, const void * elem2)
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];

    a[n-1] = 0;

    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &a[i]);
    }

    qsort(a, sizeof(a)/sizeof(*a)-1, sizeof(*a), comp);

    for (int i = 0; i < n; i++) {
        if (a[i] != i + 1) {
            printf("%d", i+1);
            break;
        }
    }

    return 0;
}