# Encrypted Password Manager

A command-line password manager written in C. It keeps your passwords
behind a master password and saves them to a file using Caesar-cipher
encryption, so the saved file is unreadable without the program.

## Features
- Master password login
- Add passwords (service name + password)
- View saved passwords
- Saves to a file so passwords persist between runs
- The saved file is encrypted (Caesar cipher)

## How to run
You need a C compiler (gcc):

    gcc manager.c -o manager
    ./manager

The default master password is 1234.

## How it works
- Passwords are kept in a struct array in memory
- On exit they are encrypted and written to password.txt
- On start the file is read back and decrypted

## Note
This project uses a Caesar cipher for learning. It is not strong enough
for real passwords yet — a stronger cipher (AES) is planned.

## Author
Aren Melkonyan
