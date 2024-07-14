#include <stdio.h>
#include <string.h>

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

unsigned long long countAnagrams(char *word) {
    int length = strlen(word);
    int charCount[256] = {0};

    for (int i = 0; i < length; i++) {
        charCount[(int)word[i]]++;
    }

    unsigned long long totalAnagrams = factorial(length);

    for (int i = 0; i < 256; i++) {
        if (charCount[i] > 1) {
            totalAnagrams /= factorial(charCount[i]);
        }
    }

    return totalAnagrams;
}

int main() {
    char word[15];

    printf("Введіть слово: ");
    scanf("%14s", word);

    unsigned long long result = countAnagrams(word);

    printf("Кількість можливих анаграм: %llu\n", result);

    return 0;
}
