# Encrypt-and-Decrypt
1.	Confirm File Names: First, double-check that you have the following files in the same directory where you are running the Command Prompt:
•	dataencryption.c (the source code file containing the encryption program)
•	input.txt (the input file you want to encrypt)
•	output.txt (the file where the encrypted data will be stored)
2.	Compile the C Code: Make sure you have GCC installed on your system. You can verify this by running the following command in the Command Prompt:
bashCopy code

If GCC is not installed, you can download and install it.
Once GCC is installed, navigate to the directory where dataencryption.c is located using the cd command, like this:
bashCopy code

cd path/to/directory 
Then, compile the C code to create the executable dataencryption:

gcc -o dataencryption dataencryption.c 
If the compilation is successful, you should see the dataencryption executable in the same directory.
3.	Run the Encryption Program: After successful compilation, run the encryption program with the following command:

dataencryption input.txt output.txt 
Make sure that the input.txt file exists in the same directory, and the output.txt file will be created by the program.


*Note*
It is not necessary to enter two codes for encryption and decryption. I did it to get a proper understanding of my work
