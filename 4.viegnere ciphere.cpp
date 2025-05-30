#include <stdio.h>
#include <string.h>
#include <ctype.h>
void vigenereEncrypt(char *plaintext, char *key, char *ciphertext) {
    int i, j;
    int textLen = strlen(plaintext);
    int keyLen = strlen(key);

    for (i = 0, j = 0; i < textLen; i++) {
        if (isalpha(plaintext[i])) {
            char p = toupper(plaintext[i]) - 'A';
            char k = toupper(key[j % keyLen]) - 'A';
            ciphertext[i] = ((p + k) % 26) + 'A';
            j++;
        } else {
            ciphertext[i] = plaintext[i]; 
        }
    }
    ciphertext[i] = '\0';
}
void vigenereDecrypt(char *ciphertext, char *key, char *plaintext) {
    int i, j;
    int textLen = strlen(ciphertext);
    int keyLen = strlen(key);

    for (i = 0, j = 0; i < textLen; i++) {
        if (isalpha(ciphertext[i])) {
            char c = toupper(ciphertext[i]) - 'A';
            char k = toupper(key[j % keyLen]) - 'A';
            plaintext[i] = ((c - k + 26) % 26) + 'A';
            j++;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[i] = '\0';
}
int main() {
    char plaintext[100], key[100], encrypted[100], decrypted[100];
    printf("Enter plaintext (uppercase letters): ");
    scanf("%s", plaintext);
    printf("Enter key (uppercase letters): ");
    scanf("%s", key);
    vigenereEncrypt(plaintext, key, encrypted);
    printf("Encrypted Text: %s\n", encrypted);
    vigenereDecrypt(encrypted, key, decrypted);
    printf("Decrypted Text: %s\n", decrypted);
    return 0;
}
