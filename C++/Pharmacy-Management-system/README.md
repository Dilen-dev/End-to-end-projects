💊 Pharmacy Management System
A simple console-based Pharmacy Management System built with C++. This program allows pharmacy staff to manage over-the-counter (OTC) medicine orders by creating, modifying, deleting, and summarizing customer transactions.

📜 Features
📦 Take new medicine orders

🧾 Print receipt and make payment

🗑️ Delete medicine orders

🛠️ Modify existing orders

📊 View daily sales summary

❌ Exit system gracefully

🧠 Technologies Used
Language: C++

Concepts: Classes, Structs, Pointers, Linked Lists, File I/O, and Console I/O

🚀 How to Run
Compile the source file:

bash
Copy
Edit
g++ Pharmacy\ Mangement\ System.cpp -o pharmacy_system
Run the executable:

bash
Copy
Edit
./pharmacy_system
🧪 Sample Medicines Offered
ID	Name	Type	Price (M)
1	Probiotics	OTC	2.00
2	Vitamin C (500mg)	OTC	3.00
3	Acid Free C (500mg)	OTC	1.00
4	Women's Multivate	OTC	4.00
5	Marino Tablet	OTC	1.00
6	Maxi Cal Tablet	OTC	5.00
7	Amino Zinc Tablet	OTC	7.00
8	Burnex	OTC	4.00
9	Fabuloss 5	OTC	3.00
10	Royal Propollen	OTC	5.00

🧹 Data Structure Used
Orders are stored using a singly linked list to dynamically manage multiple customer transactions during the day.

📁 File Structure
nginx
Copy
Edit
Pharmacy Mangement System.cpp  # Main source code
README.md                      # Project description and usage guide
⚠️ Known Limitations
Only supports OTC medicine (hardcoded)

No persistent data storage (session-based only)

Max 10 items per order

Spelling error in "Management" in file name

📌 Author
Created by Lenyolosa Emmanuel Lenyolosa
For educational use and basic project showcasing.

