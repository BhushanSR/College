#Polayalphabetic Cipher

def polyalphabetic_cipher(text, key, mode='encrypt'):
    result = []
    key = key.lower()  # Ensure the key is in lowercase
    key_index = 0  # Track the current position in the key
    
    for char in text:
        if char.isalpha():  # Process only alphabetic characters
            shift = ord(key[key_index]) - ord('a')
            if mode == 'decrypt':
                shift = -shift  # Reverse shift for decryption
            
            start = ord('A') if char.isupper() else ord('a')
            new_char = chr((ord(char) - start + shift) % 26 + start)
            result.append(new_char)
            
            # Move to the next letter in the key (cycle if necessary)
            key_index = (key_index + 1) % len(key)
        else:
            result.append(char)  # Keep non-alphabetic characters unchanged
    
    return ''.join(result)

# Example Usage
message = "Attack at dawn!"
keyword = "lemon"

# Encrypt the message
encrypted_message = polyalphabetic_cipher(message, keyword, mode='encrypt')
print("Encrypted:", encrypted_message)

# Decrypt the message
decrypted_message = polyalphabetic_cipher(encrypted_message, keyword, mode='decrypt')
print("Decrypted:", decrypted_message)
