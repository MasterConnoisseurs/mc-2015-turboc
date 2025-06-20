# 💻 C++ Projects I Developed During My First Year in College (2015)

This repository contains a series of Turbo C++ console-based mini-projects.

---

## 📚 Table of Contents

1. [📅 Year Calendar Generator](#-1-year-calendar-generator)
2. [🔤 Typing Speed Game](#-2-typing-speed-game)
3. [👋 Hello World with Name Input](#-3-hello-world-with-name-input)
4. [🧮 Basic Calculator](#-4-basic-calculator)
5. [🏦 USB-Based ATM (Single Account)](#-5-usb-based-atm-single-account)
6. [🏧 Multi-Account ATM with PIN & Logs](#-6-multi-account-atm-with-pin--logs)

---

### 📅 1. Year Calendar Generator

**Description:**  
Prompts the user for a year and generates a full 12-month calendar in the console. Handles leap years and aligns days properly.

**Features:**
- Leap year detection
- Accurate start day calculation
- Cleanly formatted output for all months

> 📁 File: `calendar.cpp`

---

### 🔤 2. Typing Speed Game

**Description:**  
A console-based typing game where random letters fall from the top. You must type the matching character before it reaches the bottom. The speed increases as your score increases.

**Features:**
- Real-time character detection (`kbhit`, `getch`)
- Speed scaling based on score
- Score tracking and retry option

> 📁 File: `typing_game.cpp`

---

### 👋 3. Hello World with Name Input

**Description:**  
A simple program that asks for the user's name and prints a personalized greeting.

**Example Output:**
Hello World!
Hello Dennis

> 📁 File: `hello_name.cpp`

---

### 🧮 4. Basic Calculator

**Description:**  
A calculator that performs basic arithmetic operations between two numbers.

**Features:**
- Addition, subtraction, multiplication, division
- Input validation
- Division-by-zero check

> 📁 File: `calculator.cpp`

---

### 🏦 5. USB-Based ATM (Single Account)

**Description:**  
Simulates an ATM that requires a USB key file (`account.dat`) containing a secret key and a balance. Verifies the key, asks for PIN, and allows deposit/withdraw transactions. All data is read from and written to the USB.

**Features:**
- USB file verification (`account.dat`)
- PIN entry with masking
- Deposit and withdraw with file updates
- Transaction retry loop

> 📁 File: `atm_usb_singlefile.cpp`  
> 📁 Example USB file (`account.dat`):
---

### 🏧 6. Multi-Account ATM with PIN & Logs

**Description:**  
Advanced ATM simulation with support for multiple accounts in a single file. Users log in with a username and masked PIN. Includes deposit, withdraw, balance checking, PIN change, and transaction logging.

**Features:**
- Multiple users in one file (`username,pin,balance`)
- PIN masking and 3-attempt limit
- Change PIN option
- Transaction logging to `receipt.txt`
- Realistic ATM-style UI

> 📁 File: `multi_account_atm.cpp`  
> 📁 Example USB `account.dat`:
