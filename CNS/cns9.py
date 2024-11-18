#Simple RSA

import random
from sympy import isprime

def generate_prime_candidate(length):
    while True:
        p = random.getrandbits(length)
        if isprime(p):
            return p

def generate_keypair(bitsize=8):
    p = generate_prime_candidate(bitsize)
    q = generate_prime_candidate(bitsize)
    n = p * q
    phi_n = (p - 1) * (q - 1)

    e = 65537  # Public exponent (common choice)
    d = pow(e, -1, phi_n)  # Private exponent (modular inverse)

    return ((e, n), (d, n))

def encrypt(public_key, plaintext):
    e, n = public_key
    return [pow(ord(char), e, n) for char in plaintext]

def decrypt(private_key, ciphertext):
    d, n = private_key
    return ''.join([chr(pow(char, d, n)) for char in ciphertext])

# Example Usage
public_key, private_key = generate_keypair(bitsize=8)

plaintext = "HELLO"
ciphertext = encrypt(public_key, plaintext)
decrypted_message = decrypt(private_key, ciphertext)

print("Public Key:", public_key)
print("Private Key:", private_key)
print("Encrypted Message:", ciphertext)
print("Decrypted Message:", decrypted_message)
