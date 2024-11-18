#Hill Cipher

import numpy as np

def hill_cipher_encrypt(text, key):
    text = text.upper().replace(" ", "")
    n = len(key)
    if len(text) % n != 0:
        text += "X" * (n - len(text) % n)
    
    text_matrix = [ord(char) - ord('A') for char in text]
    text_matrix = np.array(text_matrix).reshape(-1, n)
    key_matrix = np.array(key).reshape(n, n)
    
    encrypted_matrix = (text_matrix @ key_matrix) % 26
    encrypted_text = ''.join(chr(num + ord('A')) for num in encrypted_matrix.flatten())
    return encrypted_text

def hill_cipher_decrypt(cipher_text, key):
    n = len(key)
    cipher_matrix = [ord(char) - ord('A') for char in cipher_text]
    cipher_matrix = np.array(cipher_matrix).reshape(-1, n)
    key_matrix = np.array(key).reshape(n, n)
    
    key_inverse = np.linalg.inv(key_matrix) % 26
    key_inverse = np.round(key_inverse * np.linalg.det(key_matrix)).astype(int) % 26
    
    decrypted_matrix = (cipher_matrix @ key_inverse) % 26
    decrypted_text = ''.join(chr(num + ord('A')) for num in decrypted_matrix.flatten())
    return decrypted_text.strip("X")

# Example Usage
text = "HELLO"
key = [6, 24, 1, 13, 16, 10, 20, 17, 15]  # 3x3 key matrix

# Encrypt the text
encrypted_text = hill_cipher_encrypt(text, key)
print("Encrypted:", encrypted_text)

# Decrypt the text
decrypted_text = hill_cipher_decrypt(encrypted_text, key)
print("Decrypted:", decrypted_text)
