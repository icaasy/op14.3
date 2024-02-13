#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void inputArray_(char *const a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        scanf("%s", &a[i]);
}

int comp(const void *elem1, const void *elem2) {
    char f = *((char *) elem1);
    char s = *((char *) elem2);
    if (f > s) return 1;
    if (f < s) return -1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    char word[n];

    inputArray_(word, n);

    qsort(word, sizeof(word) * sizeof(char), sizeof(char), comp);

    long max = 0;

    bool found = true;

    int l = n > 27 ? 27 : n;
    for (int i = 1; i < l; i++) {
        if (i < 26) {
            if (word[i] == word[i - 1]) {
                max++;
            }
        } else {
            found = false;
        }
    }

    if (found) {
        printf("%ld", max);
    } else {
        printf("-1\n");
    }

    return 0;
}