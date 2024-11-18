#Simple Columnar Cipher

import math

def columnar_encrypt(text, key):
    text = text.replace(" ", "")
    cols = len(key)
    rows = math.ceil(len(text) / cols)
    grid = ['' for _ in range(cols)]
    for i, char in enumerate(text):
        grid[i % cols] += char
    sorted_key = sorted((char, idx) for idx, char in enumerate(key))
    return ''.join(grid[idx] for _, idx in sorted_key)

def columnar_decrypt(cipher_text, key):
    cols = len(key)
    rows = math.ceil(len(cipher_text) / cols)
    sorted_key = sorted((char, idx) for idx, char in enumerate(key))
    grid = [''] * cols
    col_lengths = [rows - (len(cipher_text) % cols <= i) for i in range(cols)]
    idx = 0
    for _, col_idx in sorted_key:
        grid[col_idx] = cipher_text[idx:idx + col_lengths[col_idx]]
        idx += col_lengths[col_idx]
    return ''.join(grid[i % cols][i // cols] for i in range(len(cipher_text)))

# Example Usage
message, key = "HELLO WORLD", "3142"
encrypted = columnar_encrypt(message, key)
decrypted = columnar_decrypt(encrypted, key)

print("Encrypted:", encrypted)
print("Decrypted:", decrypted)

