#include <stdio.h>
#include <malloc.h>

int countIf_(const int *const a, const size_t st, const size_t n, int cmp_val, int (*predicate )(int, int)) {
    int count = 0;
    for (size_t i = st; i <= n; i++) {
        count += predicate(a[i], cmp_val);

        if (count > 0) {
            break;
        }
    }

    return count;
}

int sum_val(int value, int smp_val) {
    return value == smp_val ? 1 : 0;
}

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
            int res = countIf_(z, 1, z[0], first[h], sum_val);
            counter += res;
        }

        if (counter == n) {
            printf("%d ", first[h]);
        }
    }

    return 0;
}
