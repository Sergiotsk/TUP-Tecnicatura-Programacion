#ifndef ORGANIZER_H
#define ORGANIZER_H

#include <string>
#include <vector>
#include <map>
#include <filesystem>

class Organizer {
public:
    Organizer(const std::string& targetPath);
    void organize();

private:
    std::filesystem::path rootPath;
    std::map<std::string, std::string> extensionMap;

    void initializeRules();
    std::string getCategory(const std::string& extension);
    void moveFile(const std::filesystem::directory_entry& entry);
};

#endif // ORGANIZER_H
