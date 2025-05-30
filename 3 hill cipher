#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 2

// Encrypt using key matrix
void hillEncrypt(char msg[], int key[SIZE][SIZE], char result[]) {
    for (int i = 0; i < SIZE; i++) {
        result[i] = ((key[i][0] * (msg[0] - 'A') + key[i][1] * (msg[1] - 'A')) % 26) + 'A';
    }
    result[SIZE] = '\0';
}

// Decrypt using inverse key matrix
void hillDecrypt(char cipher[], int invKey[SIZE][SIZE], char result[]) {
    for (int i = 0; i < SIZE; i++) {
        result[i] = ((invKey[i][0] * (cipher[0] - 'A') + invKey[i][1] * (cipher[1] - 'A')) % 26) + 'A';
    }
    result[SIZE] = '\0';
}

// Find modular inverse of determinant mod 26
int modInverse(int det) {
    det = det % 26;
    for (int i = 1; i < 26; i++) {
        if ((det * i) % 26 == 1) return i;
    }
    return -1;
}

// Compute inverse of 2x2 matrix mod 26
int getInverseKey(int key[SIZE][SIZE], int invKey[SIZE][SIZE]) {
    int det = (key[0][0]*key[1][1] - key[0][1]*key[1][0]) % 26;
    if (det < 0) det += 26;

    int invDet = modInverse(det);
    if (invDet == -1) return 0;

    invKey[0][0] = ( key[1][1] * invDet) % 26;
    invKey[0][1] = (-key[0][1] * invDet) % 26;
    invKey[1][0] = (-key[1][0] * invDet) % 26;
    invKey[1][1] = ( key[0][0] * invDet) % 26;

    // Make all elements positive
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (invKey[i][j] < 0) invKey[i][j] += 26;

    return 1;
}

int main() {
    char message[3];
    printf("Enter 2-letter uppercase message: ");
    scanf("%2s", message);

    // Key matrix (must be invertible mod 26)
    int key[SIZE][SIZE] = { {3, 3}, {2, 5} };
    int invKey[SIZE][SIZE];

    if (!getInverseKey(key, invKey)) {
        printf("Key matrix is not invertible modulo 26.\n");
        return 1;
    }

    char encrypted[3], decrypted[3];
    hillEncrypt(message, key, encrypted);
    hillDecrypt(encrypted, invKey, decrypted);

    printf("Encrypted Text: %s\n", encrypted);
    printf("Decrypted Text: %s\n", decrypted);

    return 0;
}
