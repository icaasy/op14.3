#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void *elem1, const void *elem2) {
    char f = *((char *) elem1);
    char s = *((char *) elem2);
    if (f > s) return 1;
    if (f < s) return -1;
    return 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    char word[n];
    scanf("%s", word);
    qsort(word, strlen(word) * sizeof(char), sizeof(char), comp);

    int prev = word[0] - 'a' + 1;
    int sum = prev;
    int counter = 1;

    if (k > 1) {
        for (int j = 1; (j < n) && (counter < k); j++) {
            if ((word[j] - 'a' + 1 - prev) > 1) {
                sum += word[j] - 'a' + 1;
                counter++;
            }
        }
    }

    if (counter != k) {
        sum = -1;
    }


    printf("%d", sum);


    return 0;
}