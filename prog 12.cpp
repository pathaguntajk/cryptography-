#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int mod_inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}


int generate_signature(int message, int private_key, int prime) {
    
    int signature = (int)pow(message, private_key) % prime;
    return signature;
}


int verify_signature(int message, int signature, int public_key, int prime) {
    int original_message = (int)pow(signature, public_key) % prime;
    return original_message == message;
}

int main() {
    
    int private_key = 7;
    int public_key = mod_inverse(private_key, 11); 
    int prime = 11;

    
    int message = 5;

    
    int signature = generate_signature(message, private_key, prime);
    int is_verified = verify_signature(message, signature, public_key, prime);

    
    printf("Original Message: %d\n", message);
    printf("Generated Signature: %d\n", signature);
    printf("Verification Result: %s\n", is_verified ? "Verified" : "Not Verified");

    return 0;
}
