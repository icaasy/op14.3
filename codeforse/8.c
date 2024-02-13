#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define new_max(x,y) (((x) >= (y)) ? (x) : (y))

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

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    qsort(a, sizeof(a)/sizeof(*a), sizeof(*a), comp);

    int counter = 0;
    int height = 1;
    int sum = n;
    for (int i = 1; i < n; i++) {
        if (a[i-1] == a[i]) {
            counter++;
            sum--;
        } else {
            counter = 0;
        }

        if (counter > 0) {
            height = new_max(height, counter+1);
        }
    }

    printf("%d %d", height, sum);

    return 0;
}