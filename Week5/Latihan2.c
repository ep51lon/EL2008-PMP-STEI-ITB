#include <stdio.h>

// Fungsi untuk mencari kemunculan kata dalam kalimat
int countOccurrences(char *sentence, char *word) {
    int i, j, count = 0;
    
    for (i = 0; sentence[i] != '\0'; i++) {
        int match = 1;
        for (j = 0; word[j] != '\0'; j++) {
            if (sentence[i + j] != word[j]) {
                match = 0;
                break;
            }
        }
        if (match) {
            count++;
        }
    }
    return count;
}

int main() {
    char sentence[200], word[50];

    printf("Masukkan kalimat: ");
    fgets(sentence, sizeof(sentence), stdin);
    
    printf("Masukkan kata kunci: ");
    // fgets(word, sizeof(word), stdin);
    scanf("%s", word);

    int occurrences = countOccurrences(sentence, word);
    printf("Kata \"%s\" ditemukan %d kali dalam kalimat.\n", word, occurrences);

    return 0;
}