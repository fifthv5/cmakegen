# CMakeLists.txt Generator

A simple and lightweight C++ command-line tool designed to bootstrap new C++ projects. It guides you through a few prompts to automatically generate a tailored, valid `CMakeLists.txt` configuration file.

## Features

- **Project Metadata:** Sets the project name and executable target name.
- **C++ Standard Selection:** Allows configuration of C++ standards (e.g., 17, 20, 23).
- **Multi-Library Support:** Interactively adds multiple external dependencies (like `raylib`, `OpenCV`, or `fmt`) using CMake's `find_package` and links them efficiently under `target_link_libraries`.
- **Zero Dependencies:** Built entirely using standard C++ features (`<iostream>`, `<fstream>`, `<vector>`).

## Quick Start

### 1. Compile the Generator
Compile the source file using any modern C++ compiler:
```bash
g++ -std=c++17 generator.cpp -o cmake_gen
```

### 2. Run the Program
Execute the binary in the root directory of your new project:
```bash
./cmake_gen
```

### 3. Build Your Target Project
Once the script generates your `CMakeLists.txt`, build your program using the standard CMake workflow:
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Prompt Example

```text
Enter project name: MyGame
Enter C++ standard version (e.g., 17, 20): 17
Enter output executable name: game

--- External Libraries Configuration ---
Enter library names one by one (e.g., raylib, OpenCV, Threads).
Press Enter on a blank line when you are finished.

Enter library name (or leave blank to finish): raylib
Enter library name (or leave blank to finish): OpenCV
Enter library name (or leave blank to finish): 

Success! CMakeLists.txt has been generated with 2 libraries.
```
