#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void encrypt(char *message, int key) {
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (islower(message[i])) {
                message[i] = 'a' + (message[i] - 'a' + key) % 26;
            } else if (isupper(message[i])) {
                message[i] = 'A' + (message[i] - 'A' + key) % 26;
            }
        }
    }
}
void decrypt(char *message, int key) {
    encrypt(message, 26 - key); 
}
int main() {
    char message[100];
    int key;
    printf("Enter the message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0'; 
    printf("Enter the key (0-25): ");
    scanf("%d", &key);
    key = key % 26; 
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);\
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
    return 0;
}