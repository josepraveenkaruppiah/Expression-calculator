---

````markdown
# 🧮 C Expression-Based Calculator

A lightweight yet powerful command-line calculator written in C. It supports standard arithmetic expressions, memory operations, and additional mathematical functions — all in a single-line input, just like a real calculator!

---

## 📌 Features

- ✅ Expression evaluation (e.g. `10+20*3-5`)
- ✅ Operator precedence and parentheses `()`
- ✅ Supports:
  - Addition `+`
  - Subtraction `-`
  - Multiplication `*`
  - Division `/`
  - Modulus `%`
- ✅ Square root: `sqrt <number>`
- ✅ Square: `sq <number>`
- ✅ Memory operations:
  - `M+ <number>`: Add to memory
  - `M- <number>`: Subtract from memory
  - `MR`: Memory Recall
  - `MC`: Memory Clear
- ✅ Exit anytime using `exit`

---

## 🚀 Getting Started

### 🔧 Requirements
- A C compiler (e.g. `gcc`)
- POSIX-compliant terminal (Linux/macOS/WSL) or MinGW for Windows

### 🛠️ Compilation

```bash
gcc calculator_expr.c -o calculator -lm
````

### ▶️ Run the Program

```bash
./calculator
```

---

## 🧪 Sample Usage

```
>>> 10 + 20 - 5 * 2
= 20.00

>>> sqrt 81
√81.00 = 9.00

>>> sq 12
12.00² = 144.00

>>> M+ 100
Memory: 100.00

>>> MR
Memory Recall: 100.00

>>> 50 + MR
= 150.00

>>> exit
```

---

## 📂 File Structure

```
📁 calculator-project/
├── calculator_expr.c    # Source code
└── README.md            # Project documentation
```

## 📄 License

This project is licensed under the MIT License – feel free to use, modify, and distribute.

```
