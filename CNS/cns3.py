#Playfair Cipher

def generate_playfair_key_matrix(key):
    alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ"
    key = key.upper().replace("J", "I")
    seen = set()
    matrix = [char for char in key + alphabet if char not in seen and not seen.add(char)]
    return [matrix[i:i + 5] for i in range(0, 25, 5)]

def preprocess_text(text, mode='encrypt'):
    text = text.upper().replace("J", "I")
    text = "".join(filter(str.isalpha, text))
    if mode == 'encrypt':
        pairs = []
        i = 0
        while i < len(text):
            if i + 1 < len(text) and text[i] == text[i + 1]:
                pairs.append(text[i] + 'X')
                i += 1
            else:
                pairs.append(text[i:i + 2] if i + 1 < len(text) else text[i] + 'X')
                i += 2
        return pairs
    return text

def find_position(matrix, char):
    for row_index, row in enumerate(matrix):
        if char in row:
            return row_index, row.index(char)

def playfair_cipher(text, key, mode='encrypt'):
    matrix = generate_playfair_key_matrix(key)
    pairs = preprocess_text(text, mode='encrypt')
    result = []
    shift = 1 if mode == 'encrypt' else -1
    for pair in pairs:
        row1, col1 = find_position(matrix, pair[0])
        row2, col2 = find_position(matrix, pair[1])
        if row1 == row2:
            result.extend([matrix[row1][(col1 + shift) % 5], matrix[row2][(col2 + shift) % 5]])
        elif col1 == col2:
            result.extend([matrix[(row1 + shift) % 5][col1], matrix[(row2 + shift) % 5][col2]])
        else:
            result.extend([matrix[row1][col2], matrix[row2][col1]])
    return ''.join(result)

# Example Usage
message = "HELLO WORLD"
keyword = "PLAYFAIR"
encrypted_message = playfair_cipher(message, keyword, mode='encrypt')
decrypted_message = playfair_cipher(encrypted_message, keyword, mode='decrypt')

print("Encrypted:", encrypted_message)
print("Decrypted:", decrypted_message)
