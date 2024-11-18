#Diffie-Hellman

def diffie_hellman_key_exchange(p, g, private_a, private_b):
    # Public keys
    public_a = pow(g, private_a, p)
    public_b = pow(g, private_b, p)
    
    # Shared secret keys
    shared_key_a = pow(public_b, private_a, p)
    shared_key_b = pow(public_a, private_b, p)
    
    return public_a, public_b, shared_key_a, shared_key_b

# Example Usage
p = 23  # Prime modulus
g = 5   # Primitive root
private_a = 6  # Alice's private key
private_b = 15 # Bob's private key

public_a, public_b, shared_key_a, shared_key_b = diffie_hellman_key_exchange(p, g, private_a, private_b)

print("Public Key (Alice):", public_a)
print("Public Key (Bob):", public_b)
print("Shared Key (Alice):", shared_key_a)
print("Shared Key (Bob):", shared_key_b)

