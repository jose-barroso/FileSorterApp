#include <sys/types.h>
#include <sys/stat.h>
#include <filesystem>
#include <vector>
#include <string>
#include <vector>

struct stat info;
namespace fs = std::filesystem;

// System independed function to check if the path exists
bool directory_exists(const std::string& pathname) {
	if (fs::exists(pathname))
		return true;
	else if (!fs::exists(pathname)) //not sure if s_ifdir exist or not on my windows but we'll see
		return false;
}

// Returns a vector of strings with all path files. 
std::vector<std::string> list_files(const std::filesystem::path& pathname) {
	std::vector<std::string> files;
	for (const auto& entry : fs::directory_iterator(pathname)) {
		files.push_back(entry.path().string());
	}
	return files;
}