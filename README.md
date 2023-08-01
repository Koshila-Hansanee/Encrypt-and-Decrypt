# Encrypt-and-Decrypt
Purpose of the Encryption Utility:

The encryption utility is a standalone GNU utility developed in C programming language. Its purpose is to provide a simple data encryption mechanism using the XOR (exclusive OR) operation. (My utility is a valuable exercise for learning basic encryption concepts, OpenSSL is a much more powerful and secure cryptographic library suitable for real-world applications where data security is a priority. When it comes to actual data protection, OpenSSL or other established cryptographic libraries are recommended for their robustness and industry-wide acceptance.) The utility takes an input file containing data, encrypts it using an XOR key, and then writes the encrypted data to an output file. The encryption is reversible, meaning the same key can be used to decrypt the data and obtain the original content.


To use the encryption utility,I follow these steps:

Compilation:
Before running the utility, you need to compile the C code to create an executable. Use the GCC (GNU Compiler Collection) to compile the dataencryption.c code. Open the Command Prompt (or Terminal on macOS/Linux), navigate to the directory containing the dataencryption.c file, and run the following command:

To compile the "dataencryption.c" file, use the command "gcc -o dataencryption dataencryption.c".
This will create an executable named encryption_utility in the same directory.

Running the Utility:
After successful compilation, you can run the encryption utility with the following command:

Please enter the command "dataencryption input.txt output.txt" to encrypt the contents of the input file and save the encrypted data in the output file.
Replace input_file with the name of the file you want to encrypt and output_file with the desired name for the encrypted output file. Both the input and output files should be located in the same directory as the dataencryption.c file.

Encryption Key (XOR_KEY):
By default, the utility uses the XOR_KEY 0x55 for encryption and decryption. If you wish to use a different key, you can modify the #define XOR_KEY 0x55 line in the code. Choose any 8-bit hexadecimal value (e.g., 0xAB, 0x3C, etc.) to replace 0x55 as your encryption key.

Dependencies:

The encryption utility is a simple program that does not require any external libraries or packages. It relies solely on the standard C libraries (stdio.h, stdlib.h, and stdbool.h) for basic input/output operations and memory management.

The utility is designed for educational and demonstration purposes and may not provide strong encryption suitable for secure data protection. For robust encryption requirements, consider using established cryptographic libraries and algorithms.
*Note*
It is not necessary to enter two codes for encryption and decryption. I did it to get a proper understanding of my work
