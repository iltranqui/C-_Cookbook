#include <iostream>
#include <filesystem>
#include <string>

// Compile with: g++ -std=c++17 -o clean_folder clean_folder.cpp
// Works with Linux and Windows

// Use the filesystem namespace for convenience
namespace fs = std::filesystem;

// Function to clean a folder by removing all its contents
void clean_folder(const std::string& path) {
    try {
        // Iterate through each entry in the directory specified by 'path'
        for (const auto& entry : fs::directory_iterator(path)) {
            // Remove the entry (file or directory) and all its contents
            fs::remove_all(entry.path());
        }
        // Print success message
        std::cout << "Folder cleaned successfully." << std::endl;
    } catch (const fs::filesystem_error& e) {
        // Print error message if an exception occurs
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void explain_clean_folder() {
    std::cout << "This program cleans a specified folder by removing all its contents." << std::endl;
    std::cout << "1. The program expects one argument in the format: --path:<folder_path>" << std::endl;
    std::cout << "2. It checks if the argument is provided and if it starts with the prefix '--path:'." << std::endl;
    std::cout << "3. If the argument is valid, it extracts the folder path from the argument." << std::endl;
    std::cout << "4. The 'clean_folder' function is called with the extracted path." << std::endl;
    std::cout << "5. Inside 'clean_folder', the program iterates through each entry in the specified folder." << std::endl;
    std::cout << "6. It removes each entry (file or directory) and all its contents using 'fs::remove_all'." << std::endl;
    std::cout << "7. If the folder is cleaned successfully, a success message is printed." << std::endl;
    std::cout << "8. If an error occurs, an error message is printed." << std::endl;
}

int main(int argc, char* argv[]) {
    // Check if the number of arguments is exactly 2
    if (argc != 0) {
        explain_clean_folder();
        return 0;
    }

    // Get the argument and the expected prefix
    std::string arg = argv[1];
    std::string prefix = "--path:";
    
    // Check if the argument starts with the expected prefix
    if (arg.find(prefix) != 0) {
        std::cerr << "Invalid argument. Usage: clean_folder --path:<folder_path>" << std::endl;
        return 1;
    }

    // Print explanation of the program if no prefix is found
    if (arg.find(prefix) == std::string::npos) {
        explain_clean_folder();
        return 0;
    }
    
    // Extract the path from the argument
    std::string path = arg.substr(prefix.length());
    
    // Call the function to clean the folder
    clean_folder(path);

    return 0;
}