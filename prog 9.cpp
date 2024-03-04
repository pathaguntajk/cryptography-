#include <stdio.h>
#include <math.h>


long long int power(long long int base, long long int exp, long long int mod);
long long int generate_key(long long int base, long long int private_key, long long int prime);

int main() {
    
    long long int prime = 23;
    long long int base = 5;

    
    long long int private_key_alice = 6;

    
    long long int private_key_bob = 15;

    
    long long int public_key_alice = generate_key(base, private_key_alice, prime);
    long long int public_key_bob = generate_key(base, private_key_bob, prime);

    

    
    long long int shared_secret_alice = generate_key(public_key_bob, private_key_alice, prime);
    long long int shared_secret_bob = generate_key(public_key_alice, private_key_bob, prime);

    printf("Prime: %lld, Base: %lld\n", prime, base);
    printf("Alice's Public Key: %lld\n", public_key_alice);
    printf("Bob's Public Key: %lld\n", public_key_bob);
    printf("Shared Secret (Alice): %lld\n", shared_secret_alice);
    printf("Shared Secret (Bob): %lld\n", shared_secret_bob);

    return 0;
}


long long int power(long long int base, long long int exp, long long int mod) {
    if (exp == 0) {
        return 1;
    }

    if (exp % 2 == 0) {
        long long int half_pow = power(base, exp / 2, mod);
        return (half_pow * half_pow) % mod;
    } else {
        return (base * power(base, exp - 1, mod)) % mod;
    }
}


long long int generate_key(long long int base, long long int private_key, long long int prime) {
    return power(base, private_key, prime);
}
