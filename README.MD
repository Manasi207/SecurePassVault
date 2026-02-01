# SecurePass Vault – A Console-Based Password Manager (C++ & DSA)

SecurePass Vault is a console-based C++ application which is a lightweight password manager. It demonstrates how Data Structures & Algorithms (DSA) can be applied to solve real-world problems like secure storage, fast retrieval, and efficient organization of sensitive data.

## 🔐Features

1. User Authentication → Master password protected (with hashing).

2. Organized Storage → Passwords stored by website using HashMap.

3. Fast Search → Autocomplete and prefix-based search with Trie.

4. Password History → Restore old passwords using Stack/Doubly Linked List.

5. Auto-Vault Cleanup → Auto-delete least-used/oldest passwords using Queue or Priority Queue.

6. Strong Password Generator → Backtracking/random generation with rules.

7. Encryption Simulation → Encoded storage for added security.

8. File Persistence → Save and load vault data from local file system.

## Tech & Concepts Used

1. C++ (OOP + STL)

2. DSA: HashMap, Trie, Stack, Queue, Priority Queue, Backtracking.

3. File Handling: Serialization for vault persistence.

4. Security Basics: Hashing + Encryption simulation.

### 1.Compile - g++ main.cpp src/_.cpp security/_.cpp utils/\*.cpp -I include -o SecurePass

### 2.Run - SecurePass.exe or ./SecurePass

## 📁 Project Directory Structure

```
SecurePassVault/
│
├── main.cpp
│
├── include/                         ← Core Headers
│   ├── Auth.h
│   ├── PasswordManager.h
│   ├── Trie.h
│   ├── History.h
│   ├── Generator.h
│   ├── Encryption.h
│   └── Storage.h
│
├── src/                             ← Core Implementations
│   ├── Auth.cpp
│   ├── PasswordManager.cpp
│   ├── Trie.cpp
│   ├── History.cpp
│   ├── Generator.cpp
│   ├── Encryption.cpp
│   └── Storage.cpp
│
├── model/                           ← NEW – Data Model
│   └── Credential.h                 ← site, url, username, encPassword
│
├── security/                        ← NEW – Better Encryption Layer
│   ├── AESManager.h
│   └── AESManager.cpp
│
├── data/                            ← Persistent Storage
│   ├── vault.dat                    ← encrypted credentials
│   └── master.hash                  ← hashed master password
│
├── utils/                           ← Helper Utilities
│   ├── helpers.h
│   └── helpers.cpp
│
└── README.md
```
