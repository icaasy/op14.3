#include <stdio.h>
#include <malloc.h>


int main() {
    int n;
    scanf("%d", &n);
    int *p[n];

    int r;
    for (int i = 0; i < n; i++) {
        scanf("%d", &r);
        int *z = malloc(sizeof(int) * (r+1));
        z[0] = r;
        p[i] = z;

        for (int j = 1; j <= r; j++) {
            scanf("%d", &z[j]);
        }
    }

    int *first = p[0];
    for (int h = 1; h <= first[0]; h++) {

        int counter = 1;
        for (int i = 1; i < n; i++) {

            int *z = p[i];
            for (int j = 1; j <= z[0]; j++) {
                if (first[h] == z[j]) {
                    counter++;
                    break;
                }
            }
        }

        if (counter == n) {
            printf("%d ", first[h]);
        }
    }

    return 0;
}
