#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define N 16


typedef struct {
    uint32_t P[N + 2];
    uint32_t S[4][256];
} BlowfishContext;


void blowfish_init(BlowfishContext *context, const uint8_t *key, size_t key_len);
void blowfish_encrypt(const BlowfishContext *context, uint32_t *left, uint32_t *right);
void blowfish_decrypt(const BlowfishContext *context, uint32_t *left, uint32_t *right);

int main() {
    BlowfishContext context;
    const char *message = "Hello, Blowfish!";
    uint32_t left, right;

    printf("Original Message: %s\n", message);

    
    uint8_t key[] = "BlowfishKey";
    blowfish_init(&context, key, strlen((const char *)key));

    
    printf("\nEncryption:\n");
    for (size_t i = 0; i < strlen(message); i += 8) {
        memcpy(&left, message + i, sizeof(uint32_t));
        memcpy(&right, message + i + sizeof(uint32_t), sizeof(uint32_t));

        blowfish_encrypt(&context, &left, &right);

        printf("Encrypted Block: %08X %08X\n", left, right);
    }

    
    printf("\nDecryption:\n");
    for (size_t i = 0; i < strlen(message); i += 8) {
        memcpy(&left, message + i, sizeof(uint32_t));
        memcpy(&right, message + i + sizeof(uint32_t), sizeof(uint32_t));

        blowfish_decrypt(&context, &left, &right);

        printf("Decrypted Block: %08X %08X\n", left, right);
    }

    return 0;
}

void blowfish_init(BlowfishContext *context, const uint8_t *key, size_t key_len) {
    
    
}

void blowfish_encrypt(const BlowfishContext *context, uint32_t *left, uint32_t *right) {
    
    
}

void blowfish_decrypt(const BlowfishContext *context, uint32_t *left, uint32_t *right) {
    
    
}
