#include <stdio.h>
#include <stdint.h>
#include <string.h>


typedef struct {
    uint32_t h[5];
    uint64_t length;
} SHA1Context;


void sha1_init(SHA1Context *ctx);
void sha1_update(SHA1Context *ctx, const uint8_t *input, size_t length);
void sha1_final(SHA1Context *ctx, uint8_t digest[20]);

int main() {
    
    const char *message = "Hello, SHA-1!";

    
    SHA1Context ctx;
    uint8_t digest[20];

    
    sha1_init(&ctx);

    
    sha1_update(&ctx, (const uint8_t *)message, strlen(message));

    
    sha1_final(&ctx, digest);

    
    printf("SHA-1 Digest: ");
    for (int i = 0; i < 20; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return 0;
}


void sha1_init(SHA1Context *ctx) {
    ctx->h[0] = 0x67452301;
    ctx->h[1] = 0xEFCDAB89;
    ctx->h[2] = 0x98BADCFE;
    ctx->h[3] = 0x10325476;
    ctx->h[4] = 0xC3D2E1F0;
    ctx->length = 0;
}


void sha1_update(SHA1Context *ctx, const uint8_t *input, size_t length) {
    
    
}


void sha1_final(SHA1Context *ctx, uint8_t digest[20]) {
    
    
}
