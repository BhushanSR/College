#Caesar Cipher

def caesar_cipher(text, shift, mode='encrypt'):
    
    if mode == 'decrypt':
        shift = -shift  # Reverse shift for decryption
    
    result = []
    
    for char in text:
        if char.isalpha():  # Process only alphabetic characters
            start = ord('A') if char.isupper() else ord('a')
            new_char = chr((ord(char) - start + shift) % 26 + start)
            result.append(new_char)
        else:
            result.append(char)  # Keep non-alphabetic characters unchanged
    
    return ''.join(result)


# Example Usage
message = "Hello, World!"
shift = 3

# Encrypt the message
encrypted_message = caesar_cipher(message, shift, mode='encrypt')
print("Encrypted:", encrypted_message)

# Decrypt the message
decrypted_message = caesar_cipher(encrypted_message, shift, mode='decrypt')
print("Decrypted:", decrypted_message)
