#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Base convertor problma 3

void reverse(char *str, int len) {
    int start = 0, end = len - 1, temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

char* convert_to_base_b(long x, int b) {
    char *result = (char*) malloc(65 * sizeof(char));
    int index = 0;

    while (x > 0) {
        int remainder = x % b;
        result[index++] = remainder + '0';
        x = x / b;
    }

    result[index] = '\0';
    reverse(result, index);
    return result;
}

int main() {
    long x;
    int b;

    printf("Introduceti numarul x: ");
    scanf("%ld", &x);

    printf("Introduceti baza b: ");
    scanf("%d", &b);

    if (x < 0 || x >= 100000000000LL || b <= 1 || b >= 10) {
        printf("Valorile introduse nu sunt valide.\n");
        return 1;
    }

    char *result = convert_to_base_b(x, b);
    printf("Reprezentarea numarului %ld in baza %d este: %s\n", x, b, result);

    free(result);
    return 0;
}

