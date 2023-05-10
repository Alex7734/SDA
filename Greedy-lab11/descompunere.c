#include <stdlib.h>
#include <stdio.h>

int descompunere() {
    int x, count = 0;
    int a[] = {500, 200, 100, 50, 10, 5, 1};
    int num_notes = sizeof(a) / sizeof(a[0]);

    printf("Introduceti suma de bani x: ");
    scanf("%d", &x);

    for (int i = 0; i < num_notes && x > 0; i++) {
        while (x >= a[i]) {
            x -= a[i];
            count++;
            printf("Bancnota folosita: %d\n", a[i]);
        }
    }

    printf("Numarul minim de bancnote folosite: %d\n", count);

    return 0;
}
