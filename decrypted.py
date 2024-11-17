def xor_encrypt_decrypt(data, key):
    key_len = len(key)
    return ''.join(chr(ord(data[i]) ^ ord(key[i % key_len])) for i in range(len(data)))

def read_file(file_path):
    with open(file_path, 'r') as file:
        return file.read()

def write_file(file_path, data):
    with open(file_path, 'w') as file:
        file.write(data)

def main():
    input_file = 'neuracecar_encrypted.txt'
    output_file = 'neuracecar_decrypted.txt'
    key = '20246810'

    data = read_file(input_file)
    decrypted_data = xor_encrypt_decrypt(data, key)
    write_file(output_file, decrypted_data)

if __name__ == '__main__':
    main()