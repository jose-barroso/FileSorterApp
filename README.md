# 📂 File Sorter Application

![C++20](https://img.shields.io/badge/C%2B%2B-20-blue?logo=c%2B%2B&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20Mac-lightgrey)
![License](https://img.shields.io/badge/License-MIT-yellow)

A command-line application written in **C++20** that automatically organizes files in a directory by grouping them into folders based on their file extensions.

---

## ✨ Features

- 📁 Automatically detects all files in a given directory.
- 🗂️ Groups files into subfolders by extension (e.g., `.txt`, `.jpg`, `.cpp`, etc.).
- 🧠 Uses **modern C++20** and the standard `<filesystem>` library.
- ✅ User confirmation before moving files.
- 🛡️ Robust exception and error handling.

---

## 📦 Requirements

- 🔧 **C++20-compatible compiler** (e.g., MSVC, g++, clang++)
- 🛠️ **CMake** (optional)
- 💻 **Visual Studio 2022** or any IDE with C++20 support

---

## 🚀 How to Compile

### ✅ With Visual Studio 2022
1. Open the `.sln` solution file.
2. Build the project in `Release` or `Debug` mode.
3. Run the generated executable.

### 🧪 With g++ via Terminal
```bash
g++ -std=c++20 -o file_sorter main.cpp filesystem_utils.cpp
./file_sorter

📌 Notes
Works on Windows, Linux, and macOS.
You can easily customize the destination folder or file grouping logic.

📝 License
MIT License © José Barroso
