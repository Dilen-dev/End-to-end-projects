# Payroll Management System (Console-based C++ Application)

A simple payroll management system for managing employee records, salary computation, and payslip generation. Built using C++ and intended for educational/demo purposes.

---

## 🔧 Features

- Employee login with password authentication
- Insert new employee records
- View all employees
- Search by employee code
- Edit specific fields (name, age, salary, etc.)
- Delete employee records
- Display detailed payslip with earnings & deductions
- File persistence (records are saved to `Records.txt`)

---

## 🗃 Data Fields

Each employee record contains:
- Name, Code, Designation, Experience, Age
- Salary, DA, HRA, PF, Tax, Allowances
- Loan status, Working hours, Gross pay

---

## 🛠 How to Build and Run

### 🖥 Requirements
- Windows OS (uses Windows-specific console API)
- A C++ compiler (like g++, MSVC)

### 🔄 Compilation (Using g++)
```bash
g++ -o payroll main.cpp
