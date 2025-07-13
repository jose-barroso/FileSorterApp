#include <string>
#include <vector>
#include <filesystem>
#ifndef FILESYSTEM_UTILS_H
#define FILESYSTEM_UTILS_H

bool directory_exists(const std::string& pathname); //to check if the directory exists in the system
std::vector<std::string> list_files(const std::filesystem::path& pathname); //returns a vector of strings with all path files

#endif