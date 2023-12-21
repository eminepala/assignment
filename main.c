#include <stdio.h>
#include <stdlib.h>
#include <string.h>

   int main() {
    char word[50] = "", wordHyp[100] = "";
    printf("Enter a word for hyphenation:\n");
    scanf("%s", word);
    hyphenate(word, wordHyp);
    printf("%s\n", wordHyp);
    return 0;
}
int isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void hyphenate(char word[], char wordHyp[]) {
    int length = strlen(word);
    int hypIndex = 0;

    for (int i = 0; i < length; i++) {
        if (isVowel(word[i])) {
            if (i + 1 < length && isVowel(word[i + 1])) {
                // Rule 4: Two vowels together, each forms a separate syllable
                wordHyp[hypIndex++] = word[i];
                wordHyp[hypIndex++] = '-';
                wordHyp[hypIndex++] = word[i + 1];
            } else if (i + 2 < length && !isVowel(word[i + 2])) {
                // Rule 3: Three consecutive consonants, the first two form a syllable
                wordHyp[hypIndex++] = word[i];
                wordHyp[hypIndex++] = word[i + 1];
                wordHyp[hypIndex++] = '-';
                i++;  // Skip the next consonant
            } else {
                // Rule 1: Consonant between two vowels forms a syllable with the following vowel
                wordHyp[hypIndex++] = '-';
                if (i + 1 < length && isVowel(word[i + 1])) {
                    wordHyp[hypIndex++] = word[i];
                    wordHyp[hypIndex++] = '-';
                } else {
                    wordHyp[hypIndex++] = word[i];
                }
            }
        } else {
            // Rule 2: Consonant forms a syllable with the following vowel
            wordHyp[hypIndex++] = word[i];
        }
    }

    // Ensure the hyphenated word is null-terminated
    wordHyp[hypIndex] = '\0';
}

