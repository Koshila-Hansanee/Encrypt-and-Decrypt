#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define XOR_KEY 0x55 // Choose any key you like (must be the same for encryption and decryption)

bool handle_error(const char* message) {
    fprintf(stderr, "Error: %s\n", message);
    return false;
}

bool encrypt_data(const unsigned char* key, const unsigned char* input, size_t input_len, unsigned char** output, size_t* output_len) {
    // Check for null pointers and input length
    if (key == NULL || input == NULL || output == NULL || output_len == NULL || input_len == 0) {
        return handle_error("Invalid input or output pointers or input length.");
    }

    // Calculate the size of the output buffer and allocate memory
    size_t encrypted_len = input_len;
    *output = (unsigned char*)malloc(encrypted_len);
    if (*output == NULL) {
        return handle_error("Memory allocation failed.");
    }

    // Encrypt the data using XOR
    for (size_t i = 0; i < encrypted_len; ++i) {
        (*output)[i] = input[i] ^ key[i % 2]; // Use the XOR_KEY for demonstration (key[i % 2])
    }

    *output_len = encrypted_len;
    return true;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    // Replace this key with your actual encryption key
    unsigned char key[] = {XOR_KEY, XOR_KEY};

    // Read input file
    FILE* input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Failed to open input file.\n");
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    size_t input_file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    unsigned char* input_data = (unsigned char*)malloc(input_file_size);
    if (input_data == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        fclose(input_file);
        return 1;
    }

    if (fread(input_data, 1, input_file_size, input_file) != input_file_size) {
        fprintf(stderr, "Error: Failed to read input data.\n");
        fclose(input_file);
        free(input_data);
        return 1;
    }

    fclose(input_file);

    // Encrypt the data
    unsigned char* encrypted_data;
    size_t encrypted_len;

    if (!encrypt_data(key, input_data, input_file_size, &encrypted_data, &encrypted_len)) {
        fprintf(stderr, "Error: Data encryption failed.\n");
        free(input_data);
        return 1;
    }

    // Write encrypted data to the output file
    FILE* output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        fprintf(stderr, "Error: Failed to open output file.\n");
        free(input_data);
        free(encrypted_data);
        return 1;
    }

    if (fwrite(encrypted_data, 1, encrypted_len, output_file) != encrypted_len) {
        fprintf(stderr, "Error: Failed to write encrypted data.\n");
        fclose(output_file);
        free(input_data);
        free(encrypted_data);
        return 1;
    }

    fclose(output_file);
    free(input_data);
    free(encrypted_data);

    printf("Data encrypted successfully.\n");
    return 0;
}

