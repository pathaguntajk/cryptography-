#include <stdio.h>
#include <stdint.h>
#include <string.h>


typedef struct {
    uint32_t state[4];
    uint32_t count[2];
    uint8_t buffer[64];
} MD5Context;

void md5_init(MD5Context *ctx);
void md5_update(MD5Context *ctx, const uint8_t *input, size_t length);
void md5_final(MD5Context *ctx, uint8_t digest[16]);
void md5_transform(uint32_t state[4], const uint8_t block[64]);

#define MD5_BLOCK_SIZE 64
#define MD5_DIGEST_SIZE 16

int main() {
    
    const char *message = "Hello, MD5!";

    
    MD5Context ctx;
    uint8_t digest[MD5_DIGEST_SIZE];

    
    md5_init(&ctx);

    
    md5_update(&ctx, (const uint8_t *)message, strlen(message));

    
    md5_final(&ctx, digest);

    
    printf("MD5 Digest: ");
    for (int i = 0; i < MD5_DIGEST_SIZE; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return 0;
}


void md5_init(MD5Context *ctx) {
    ctx->state[0] = 0x67452301;
    ctx->state[1] = 0xEFCDAB89;
    ctx->state[2] = 0x98BADCFE;
    ctx->state[3] = 0x10325476;

    ctx->count[0] = 0;
    ctx->count[1] = 0;
}


void md5_update(MD5Context *ctx, const uint8_t *input, size_t length) {
    uint32_t i, index, part_len;

    index = (uint32_t)((ctx->count[0] >> 3) & 0x3F);

    if ((ctx->count[0] += (uint32_t)(length << 3)) < (uint32_t)(length << 3)) {
        ctx->count[1]++;
    }
    ctx->count[1] += (uint32_t)(length >> 29);

    part_len = 64 - index;

    if (length >= part_len) {
        memcpy(&ctx->buffer[index], input, part_len);
        md5_transform(ctx->state, ctx->buffer);

        for (i = part_len; i + 63 < length; i += 64) {
            md5_transform(ctx->state, &input[i]);
        }
        index = 0;
    } else {
        i = 0;
    }

    memcpy(&ctx->buffer[index], &input[i], length - i);
}


void md5_final(MD5Context *ctx, uint8_t digest[16]) {
    uint8_t padding[64];
    uint32_t bits[2];
    uint32_t index, pad_len;

    
    memcpy(padding, "\x80", 1);
    memset(padding + 1, 0, 63);

    index = (uint32_t)((ctx->count[0] >> 3) & 0x3F);
    pad_len = (index < 56) ? (56 - index) : (120 - index);
    md5_update(ctx, padding, pad_len);

    
    bits[0] = ctx->count[0];
    bits[1] = ctx->count[1];

    memcpy(ctx->buffer + 56, bits, 8);

    
    md5_transform(ctx->state, ctx->buffer);

    
    memcpy(digest, ctx->state, 16);
}


void md5_transform(uint32_t state[4], const uint8_t block[64]) {
    
    
}
