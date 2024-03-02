#include <stdio.h>
#include <string.h>

void encryptRailFence(char *message, int rails, char *encryptedMessage) {
    int len = strlen(message);
    int i, j, k = 0, cycle = 2 * (rails - 1);
    for (i = 0; i < rails; i++) {
        for (j = i; j < len; j += cycle) {
            encryptedMessage[k++] = message[j];
            if (i != 0 && i != rails - 1 && j + cycle - 2 * i < len)
                encryptedMessage[k++] = message[j + cycle - 2 * i];
        }
    }
    encryptedMessage[len] = '\0';
}

void decryptRailFence(char *encryptedMessage, int rails, char *decryptedMessage) {
    int len = strlen(encryptedMessage);
    int cycle = 2 * (rails - 1), i, j, k = 0;
    for (i = 0; i < len; i += cycle) {
        decryptedMessage[i] = encryptedMessage[k++];
    }
    for (i = 1; i < rails - 1; i++) {
        for (j = i; j < len; j += cycle) {
            decryptedMessage[j] = encryptedMessage[k++];
            if (j + cycle - 2 * i < len)
                decryptedMessage[j + cycle - 2 * i] = encryptedMessage[k++];
        }
    }
    for (i = rails - 1; i < len; i += cycle) {
        decryptedMessage[i] = encryptedMessage[k++];
    }
    decryptedMessage[len] = '\0';
}

int main() {
    char message[100], encryptedMessage[100], decryptedMessage[100];
    int rails;

    printf("Enter the message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter the number of rails: ");
    scanf("%d", &rails);

    int len = strlen(message);
    if (message[len - 1] == '\n')
        message[len - 1] = '\0';

    encryptRailFence(message, rails, encryptedMessage);
    printf("Encrypted message: %s\n", encryptedMessage);

    decryptRailFence(encryptedMessage, rails, decryptedMessage);
    printf("Decrypted message: %s\n", decryptedMessage);

    return 0;
}