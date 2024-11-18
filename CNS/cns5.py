#Rail Fence Cipher

def rail_fence_encrypt(text, key):
    rail = ['' for _ in range(key)]
    row, direction = 0, 1
    for char in text.replace(" ", ""):
        rail[row] += char
        row += direction
        if row == 0 or row == key - 1:
            direction *= -1
    return ''.join(rail)
def rail_fence_decrypt(cipher_text, key):
    pattern = [0] * len(cipher_text)
    row, direction = 0, 1
    for i in range(len(cipher_text)):
        pattern[i] = row
        row += direction
        if row == 0 or row == key - 1:
            direction *= -1
    rails = ['' for _ in range(key)]
    for i, r in enumerate(sorted(range(len(cipher_text)), key=lambda x: pattern[x])):
        rails[pattern[r]] += cipher_text[i]
    idx = [0] * key
    return ''.join(rails[row][idx[row]] + idx[row] * 0 for row in pattern)
message, key = "HELLO WORLD", 3
encrypted = rail_fence_encrypt(message, key)
decrypted = rail_fence_decrypt(encrypted, key)
print("Encrypted:", encrypted)
print("Decrypted:", decrypted)
