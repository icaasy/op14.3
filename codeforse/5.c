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

    bool res = false;
    int counter = 1;

    if (n >= k) {
        for (int i = 1; i < n; i++) {
            if (counter <= k) {
                if (word[i] == word[i - 1]) {
                    counter++;
                } else {
                    res = true;
                    counter = 1;
                }
            } else {

                res = false;
                break;
            }
        }
    } else {
        res = true;
    }

    if (counter == k) {
        res = true;
    }
    else if (counter > k) {
        res = false;
    }

    if (res) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}