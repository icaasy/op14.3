#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int comp (const void * elem1, const void * elem2)
{
    char f = *((char*)elem1);
    char s = *((char*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    char word[n];
    scanf("%s", word);
    qsort(word, strlen(word) * sizeof(char), sizeof(char), comp);

    bool flag = false;
    if (n > 1) {
        for (int i = 0; i < n; i++) {
            if (word[i] == word[i - 1]) {
                flag = true;
                break;
            }
        }
    } else {
        flag = true;
    }
    if (!flag) {
        printf("NO");
    } else {
        printf("YES");
    }

    return 0;
}