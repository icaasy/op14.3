#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int p[n+1];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    for (int i = 1; i <= n; i++) {
        int map[1001] = {0};
        int temp = i;

        while(1) {
            map[temp]++;
            if (map[temp] == 2) {
                break;
            }
            temp = p[temp];
        }
        printf("%d ", temp);
    }

    return 0;
}