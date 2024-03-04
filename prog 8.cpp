#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#define PRIME_SIZE 16
#define PUBLIC_EXPONENT 65537


uint64_t mod_pow(uint64_t base, uint64_t exponent, uint64_t modulus);
uint64_t gcd(uint64_t a, uint64_t b);
uint64_t generate_prime();
uint64_t generate_key(uint64_t *public_key, uint64_t *private_key);

int main() {
    uint64_t public_key, private_key, modulus;

    
    modulus = generate_key(&public_key, &private_key);

    printf("Public Key: %llu\n", public_key);
    printf("Private Key: %llu\n", private_key);
    printf("Modulus: %llu\n", modulus);

    
    uint64_t plaintext = 42;
    printf("Original Message: %llu\n", plaintext);

    
    uint64_t ciphertext = mod_pow(plaintext, public_key, modulus);
    printf("Encrypted Message: %llu\n", ciphertext);

    
    uint64_t decrypted_message = mod_pow(ciphertext, private_key, modulus);
    printf("Decrypted Message: %llu\n", decrypted_message);

    return 0;
}


uint64_t mod_pow(uint64_t base, uint64_t exponent, uint64_t modulus) {
    uint64_t result = 1;
    base = base % modulus;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }

    return result;
}


uint64_t gcd(uint64_t a, uint64_t b) {
    while (b != 0) {
        uint64_t temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


uint64_t generate_prime() {
    
    
    return rand() % ((uint64_t)pow(2, PRIME_SIZE) - 2) + 2;
}


uint64_t generate_key(uint64_t *public_key, uint64_t *private_key) {
    uint64_t p, q, n, phi, e;

    
    do {
        p = generate_prime();
        q = generate_prime();
    } while (p == q);

    n = p * q;      
    phi = (p - 1) * (q - 1);    

    
    do {
        e = rand() % (phi - 2) + 2;
    } while (gcd(e, phi) != 1);

    *public_key = e;

    
    *private_key = mod_pow(e, phi - 1, phi);

    return n;
}
