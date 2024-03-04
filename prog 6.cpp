#include <stdio.h>
#include <stdint.h>


static const int initial_permutation[64] = { /* ... */ };
static const int final_permutation[64] = { /* ... */ };


static const int expansion_table[48] = { /* ... */ };
static const int substitution_boxes[8][4][16] = { /* ... */ };
static const int straight_permutation[32] = { /* ... */ };


static const int key_permutation[56] = { /* ... */ };
static const int key_shifts[16] = { /* ... */ };
static const int key_compression[48] = { /* ... */ };


void des_encrypt(const uint64_t plaintext, const uint64_t key, uint64_t *ciphertext);
void generate_subkeys(const uint64_t key, uint64_t *subkeys);

int main() {
    uint64_t plaintext = 0x0123456789ABCDEF;  
    uint64_t key = 0x133457799BBCDFF1;         
    uint64_t ciphertext;

    des_encrypt(plaintext, key, &ciphertext);

    printf("Plaintext: 0x%016llX\n", plaintext);
    printf("Key: 0x%016llX\n", key);
    printf("Ciphertext: 0x%016llX\n", ciphertext);

    return 0;
}

void des_encrypt(const uint64_t plaintext, const uint64_t key, uint64_t *ciphertext) {
    
    
}

void generate_subkeys(const uint64_t key, uint64_t *subkeys) {
    
}
