# 🏦 Online Banking Application

A simple terminal-based banking application implemented in Python. It allows users to create accounts, log in securely, deposit/withdraw funds, check their balance, and calculate interest on deposits.

---

## 📁 Project Structure

```
.
├── main.py              # Main CLI interface
├── utils.py             # Input handling and validation utilities
├── auth.py              # Authentication logic and PIN hashing
├── banking.py           # Banking operations and interest calculations
├── README.md            # Project documentation
```

---

## 🚀 Features

* ✅ Account creation with PIN
* 🔐 Secure PIN hashing (SHA-256)
* 💰 Deposit and Withdraw functionality
* 📈 Balance check
* 📁 Interest calculator (continuous compounding)
* 🔄 PIN change
* 🛡️ Input validation and retry logic

---

## 🧪 Requirements

* Python 3.6+

No external libraries required — fully standard library.

---

## 💠 How to Run

1. Clone or download this repository.
2. Ensure all `.py` files are in the same folder.
3. Run the app with:

```bash
python main.py
```

---

## 🧠 Interest Formula Used

The application uses **continuous compounding** for interest:

```
A = Pe^(rt)
```

Where:

* `P` = Principal amount
* `r` = Annual interest rate (in decimal)
* `t` = Time in years
* `e` = Euler's number

---

## 📌 Notes

* All data is stored in-memory (no persistence).
* Meant for learning/demo purposes — not production-ready.
* For added features, consider:

  * Saving user data to a file or database
  * Adding user sessions
  * Converting to a Flask/Tkinter app

---

## 📄 License

MIT License – Free to use, modify, and distribute.
