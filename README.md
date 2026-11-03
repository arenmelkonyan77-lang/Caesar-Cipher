# Password Manager (C)

A command-line password manager written in C. It keeps your passwords
behind a master password and stores them in a file using Caesar-cipher
encryption, so the saved file is unreadable without the program.

## What it does
- Asks for a master password at startup (default: 1234)
- Add a password (website name + password)
- View all saved passwords
- Saves everything to password.txt between runs
- The saved file is encrypted with a Caesar cipher

## How to run

### Option 1 — download the binary
Download the executable from the Releases page (built for Linux x86-64):

    ./password-manager-linux

### Option 2 — build from source (any OS with gcc)

    gcc manager.c -o manager
    ./manager

## How it works
- Passwords are kept in a struct array in memory
- On exit they are encrypted and written to password.txt
- On startup the file is read back and decrypted

## Note
This uses a Caesar cipher for learning. It is not secure enough for real
passwords yet — a stronger cipher (AES) is planned.

## Author
Aren Melkonyan
