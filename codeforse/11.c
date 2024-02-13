#include <stdio.h>
#include <stdlib.h>

#define MAX_COUNT 1001

int comp(const void *p1, const void *p2) {
    return *((char *) p1) - *((char *) p2);
}

int main() {
    int number_digits_in_cards;
    scanf("%d\n", &number_digits_in_cards);

    char sherlock_card[MAX_COUNT];
    char moriarty_card[MAX_COUNT];

    scanf("%s\n %s", sherlock_card, moriarty_card);

    qsort(sherlock_card, number_digits_in_cards, sizeof(char), comp);
    qsort(moriarty_card, number_digits_in_cards, sizeof(char), comp);

    int number_clicks = 0;
    int j = 0;

    for (int i = 0; i < number_digits_in_cards; i++) {
        while (j < number_digits_in_cards && sherlock_card[i] > moriarty_card[j]) {
            j++;
        }

        if (j >= number_digits_in_cards) {
            number_clicks++;
        }

        j++;
    }

    printf("%d\n", number_clicks);

    number_clicks = 0;

    for (int i = 0, j = 0; i < number_digits_in_cards; i++) {
        while (j < number_digits_in_cards && sherlock_card[i] >= moriarty_card[j]) {
            j++;
        }

        if (j < number_digits_in_cards) {
            number_clicks++;
        }

        j++;
    }

    printf("%d\n", number_clicks);

    return 0;
}