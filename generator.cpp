#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string project_name;
    std::string cpp_version;
    std::string executable_name;
    std::vector<std::string> libraries;

    // Gather basic project details
    std::cout << "Enter project name: ";
    std::getline(std::cin, project_name);

    std::cout << "Enter C++ standard version (e.g., 17, 20): ";
    std::getline(std::cin, cpp_version);

    std::cout << "Enter output executable name: ";
    std::getline(std::cin, executable_name);

    // Loop to collect multiple libraries
    std::cout << "\n--- External Libraries Configuration ---\n";
    std::cout << "Enter library names one by one (e.g., raylib, OpenCV, Threads).\n";
    std::cout << "Press Enter on a blank line when you are finished.\n\n";

    while (true) {
        std::string lib;
        std::cout << "Enter library name (or leave blank to finish): ";
        std::getline(std::cin, lib);
        
        if (lib.empty()) {
            break;
        }
        libraries.push_back(lib);
    }

    // Open file for writing
    std::ofstream cmake_file("CMakeLists.txt");
    if (!cmake_file.is_open()) {
        std::cerr << "Error: Could not create CMakeLists.txt" << std::endl;
        return 1;
    }

    // Base configuration
    cmake_file << "cmake_minimum_required(VERSION 3.12)\n\n";
    cmake_file << "project(" << project_name << " VERSION 1.0)\n\n";
    cmake_file << "set(CMAKE_CXX_STANDARD " << cpp_version << ")\n";
    cmake_file << "set(CMAKE_CXX_STANDARD_REQUIRED ON)\n\n";

    // Add find_package for each library
    if (!libraries.empty()) {
        for (const auto& lib : libraries) {
            cmake_file << "find_package(" << lib << " REQUIRED)\n";
        }
        cmake_file << "\n";
    }

    // Executable target
    cmake_file << "add_executable(" << executable_name << " main.cpp)\n";

    // Link all libraries to the target
    if (!libraries.empty()) {
        cmake_file << "target_link_libraries(" << executable_name << " PRIVATE\n";
        for (const auto& lib : libraries) {
            cmake_file << "    " << lib << "\n";
        }
        cmake_file << ")\n";
    }

    cmake_file.close();
    std::cout << "\nSuccess! CMakeLists.txt has been generated with " << libraries.size() << " libraries.\n";
    return 0;
}

