#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp (const void * elem1, const void * elem2)
{
    char f = *((char*)elem1);
    char s = *((char*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

int main() {
    int t;
    scanf("%d", &t);

    for (int j = 0; j < t; j++) {
        char word[1000];
        scanf("%s", word);

        qsort(word, strlen(word) * sizeof(char), sizeof(char), comp);

        int temp = strlen(word);
        if (word[temp-1] != word[0]) {
            printf("%s\n", word);
        } else {
            printf("-1\n");
        }
    }

    return 0;
}