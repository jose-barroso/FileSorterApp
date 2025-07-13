# 📂 File Sorter Application

Uma aplicação de linha de comandos em **C++20** que organiza automaticamente os ficheiros de um diretório, agrupando-os por extensão.

---

## ✨ Funcionalidades

- Deteta todos os ficheiros num diretório.
- Agrupa automaticamente ficheiros em subpastas com base na sua extensão (por exemplo, `.txt`, `.jpg`, `.cpp`, etc.).
- Utiliza **C++ moderno** e a biblioteca padrão `<filesystem>`.
- Permite ao utilizador confirmar antes de mover os ficheiros.
- Lida com exceções e erros de forma robusta.

---

## 📦 Requisitos

- **Compilador com suporte para C++20** (ex: MSVC, g++, clang++)
- **CMake** (opcional)
- **Visual Studio 2022** ou outro ambiente com suporte a C++20

---

## 🚀 Como compilar

### Usando o Visual Studio 2022
1. Abre a solução `.sln`.
2. Compila em modo `Release` ou `Debug`.
3. Executa o binário gerado.

### Usando o terminal (g++)
```bash
g++ -std=c++20 -o file_sorter main.cpp filesystem_utils.cpp
./file_sorter
