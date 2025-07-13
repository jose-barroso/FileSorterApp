/*
* File Sorter App in modern c++17
Made by: José Barroso
*/
#include <iostream>
#include <filesystem>
#include <exception>
#include <set>
#include <string>
#include "filesystem_utils.hpp"

namespace fs = std::filesystem;

int main()
{
    try { // Error handling
        std::string directory_input; // Receive user input
        bool validInput = false; //Get a valid input to avoid errors
        std::string procede_input;

        while (!validInput) { //first get a valid input
            std::cout << "What's the directory you want to organize: ";
            //std::cin only works until it finds a space, so I should use getline
            std::getline(std::cin, directory_input);

            if (directory_input.empty()) {
                std::cout << "You have to enter text." << std::endl;
            }
            else if (directory_exists(directory_input)) {
                std::cout << "This directory is valid." << std::endl;
                validInput = true;
            }
            else {
                std::cout << "Directory does not exist." << std::endl;
            }
        }
        const fs::path filePath = directory_input; // Atribute the correct working path to a variable.
        validInput = false; //reset the variable

        // Print in the console all files contained in the directory
        std::cout << "\nFiles contained in this directory:" << std::endl;
        for (const auto& file : list_files(filePath)) {
            std::cout << file << std::endl;
        }

        // Get extensions of files in filePath directory, and make a set containing every each extension
        std::set<std::string> uniqueExtensions;
        for (const auto& file : list_files(filePath)) {
            fs::path p(file);
            if (p.has_extension()) {
                uniqueExtensions.insert(p.extension().string());
            }
        }

        //Print all unique file extensions that were found and stored in the set uniqueExtensions
        std::cout << "\nUnique file extensions detected: ";
        for (const auto& extension : uniqueExtensions) {
            std::cout << extension << ", ";
        }

        while (!validInput) {
            std::cout << "\n\nDo you wish to procede and move every file to it's extension directory? (Y/N): ";
            std::cin >> procede_input;
            if (procede_input == "Y" || procede_input == "y") {
                validInput = true;
            }
            else if (procede_input == "N" || procede_input == "n") {
                return 0;
            }
            else {
                std::cout << "\nInput response is not valid!";
            }
        }
        validInput = false; //reset the variable

        // Since the input response was Y for yes, execute the code to move the files.

        for (const auto& extension : uniqueExtensions) { // For every file extension, make a directory for it
            fs::path targetDir = filePath / extension; // Create the path (string) for the .extension directory
            if (!fs::is_directory(targetDir)) { // If the extension directory doesnt exist already
                fs::create_directory(targetDir); // Create a directory for the extension
            }
            for (const auto& file : list_files(filePath)) { // Check in every file for the extension we are looking for
                fs::path p(file); // Attribute a path to the file

                if (p.has_extension() && p.extension() == extension) { // If the file has an extension and it's the one we are looking for
                    fs::rename(p, targetDir / p.filename()); // Move the file to the new directory ( old dir/filename -> new dir/filename)
                }
            }
        }
    }
    catch (const fs::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << '\n';
        std::cerr << "Path 1: " << e.path1() << '\n';
        std::cerr << "Path 2: " << e.path2() << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << "Standard exception: " << e.what() << '\n';
    }
    catch (...) {
        std::cerr << "Unknown error!\n";
    }
}