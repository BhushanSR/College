#Advance Columnar

import math

def advanced_columnar_encrypt(text, key):
    text = text.replace(" ", "")
    cols = len(key)
    rows = math.ceil(len(text) / cols)
    text += 'X' * (cols * rows - len(text))  # Padding
    grid = [text[i:i + cols] for i in range(0, len(text), cols)]
    sorted_key = sorted((char, idx) for idx, char in enumerate(key))
    return ''.join(''.join(row[idx] for row in grid) for _, idx in sorted_key)

def advanced_columnar_decrypt(cipher_text, key):
    cols = len(key)
    rows = math.ceil(len(cipher_text) / cols)
    sorted_key = sorted((char, idx) for idx, char in enumerate(key))
    col_lengths = [rows] * (len(cipher_text) % cols) + [rows - 1] * (cols - len(cipher_text) % cols)
    grid = [''] * cols
    idx = 0
    for _, col_idx in sorted_key:
        grid[col_idx] = cipher_text[idx:idx + col_lengths[col_idx]]
        idx += col_lengths[col_idx]
    return ''.join(''.join(grid[col][row] for col in range(cols) if row < len(grid[col])) for row in range(rows))

# Example Usage
message, key = "WE ARE DISCOVERED FLEE AT ONCE", "4312567"
encrypted = advanced_columnar_encrypt(message, key)
decrypted = advanced_columnar_decrypt(encrypted, key)

print("Encrypted:", encrypted)
print("Decrypted:", decrypted)
