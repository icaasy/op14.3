#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

    for (int i = 0; i < n; i++) {
        word[i] = 'a';
    }
    scanf("%s", word);
    qsort(word, sizeof(word) * sizeof(char), sizeof(char), comp);

    bool flag = true;
    long counter = 1;
    long max = 0;
    for (int i = 1; i < n; i++) {
        if ((word[i] == word[i - 1]) && (counter < 26)) {
            counter++;
            max++;
            continue;
        }
        if (counter < 26) {
            counter++;
            continue;
        }
        printf("-1\n");
        flag = false;
        break;
    }

    if (flag) {
        printf("%ld", max);
    }

    return 0;
}