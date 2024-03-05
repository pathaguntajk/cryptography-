#include <stdio.h>
#include <stdint.h>
#include <string.h>


uint64_t K[80] = {
    0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc,
    0x3956c25bf348b538, 0x59f111f1b605d019, 0x923f82a4af194f9b, 0xab1c5ed5da6d8118,
    0xd807aa98a3030242, 0x12835b0145706fbe, 0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
    0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235, 0xc19bf174cf692694,
    0xe49b69c19ef14ad2, 0xefbe4786384f25e3, 0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
    
};


#define ROTR(x, n) (((x) >> (n)) | ((x) << (64 - (n))))


uint64_t H[8] = {
    0x6a09e667f3bcc908, 0xbb67ae8584caa73b, 0x3c6ef372fe94f82b, 0xa54ff53a5f1d36f1,
    0x510e527fade682d1, 0x9b05688c2b3e6c1f, 0x1f83d9abfb41bd6b, 0x5be0cd19137e2179,
};


uint64_t W[80];


#define Ch(x, y, z) (((x) & (y)) ^ ((~x) & (z)))
#define Maj(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define Sigma0(x) (ROTR(x, 28) ^ ROTR(x, 34) ^ ROTR(x, 39))
#define Sigma1(x) (ROTR(x, 14) ^ ROTR(x, 18) ^ ROTR(x, 41))
#define sigma0(x) (ROTR(x, 1) ^ ROTR(x, 8) ^ ((x) >> 7))
#define sigma1(x) (ROTR(x, 19) ^ ROTR(x, 61) ^ ((x) >> 6))


void sha512_transform(uint64_t *M) {
    uint64_t a, b, c, d, e, f, g, h, t1, t2;
    int i;

    for (i = 0; i < 16; i++)
        W[i] = M[i];

    for (; i < 80; i++)
        W[i] = sigma1(W[i - 2]) + W[i - 7] + sigma0(W[i - 15]) + W[i - 16];

    a = H[0];
    b = H[1];
    c = H[2];
    d = H[3];
    e = H[4];
    f = H[5];
    g = H[6];
    h = H[7];

    for (i = 0; i < 80; i++) {
        t1 = h + Sigma1(e) + Ch(e, f, g) + K[i] + W[i];
        t2 = Sigma0(a) + Maj(a, b, c);

        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }

    H[0] += a;
    H[1] += b;
    H[2] += c;
    H[3] += d;
    H[4] += e;
    H[5] += f;
    H[6] += g;
    H[7] += h;
}


void sha512_pad_and_result(const char *message, uint64_t length) {
    uint64_t bit_len = length * 8;
    int i, j;

    
    uint64_t M[16];
    for (i = 0; i < 16; i++) {
        M[i] = 0;
        for (j = 0; j < 8; j++) {
            M[i] |= ((uint64_t)message[i * 8 + j] & 0xFF) << ((7 - j) * 8);
        }
    }

    
    M[length / 8] |= 0x80ULL << ((7 - (length % 8)) * 8);

    
    if (length % 8 > 8 - 2)
        sha512_transform(M);
    
    M[14] = bit_len >> 56;
    M[15] = bit_len;

    
    sha512_transform(M);

    
    for (i = 0; i < 8; i++) {
        printf("%016llx", H[i]);
    }
    printf("\n");
}


void sha512(const char *message) {
    int len = strlen(message);
    sha512_pad_and_result(message, len);
}

int main() {
    
    const char *input_message = "Hello, SHA-512!";
    sha512(input_message);

    return 0;
}
