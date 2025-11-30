#include "Organizer.h"
#include <iostream>
#include <algorithm>

namespace fs = std::filesystem;

Organizer::Organizer(const std::string& targetPath) : rootPath(targetPath) {
    initializeRules();
}

void Organizer::initializeRules() {
    // Images
    extensionMap[".jpg"] = "Images";
    extensionMap[".jpeg"] = "Images";
    extensionMap[".png"] = "Images";
    extensionMap[".gif"] = "Images";
    extensionMap[".bmp"] = "Images";

    // Documents
    extensionMap[".pdf"] = "Documents";
    extensionMap[".doc"] = "Documents";
    extensionMap[".docx"] = "Documents";
    extensionMap[".txt"] = "Documents";
    extensionMap[".ppt"] = "Documents";
    extensionMap[".pptx"] = "Documents";
    extensionMap[".xls"] = "Documents";
    extensionMap[".xlsx"] = "Documents";

    // Audio
    extensionMap[".mp3"] = "Audio";
    extensionMap[".wav"] = "Audio";
    extensionMap[".flac"] = "Audio";

    // Video
    extensionMap[".mp4"] = "Video";
    extensionMap[".mkv"] = "Video";
    extensionMap[".avi"] = "Video";
    extensionMap[".mov"] = "Video";

    // Archives
    extensionMap[".zip"] = "Archives";
    extensionMap[".rar"] = "Archives";
    extensionMap[".7z"] = "Archives";
    
    // Code
    extensionMap[".cpp"] = "Code";
    extensionMap[".h"] = "Code";
    extensionMap[".py"] = "Code";
    extensionMap[".js"] = "Code";
    extensionMap[".html"] = "Code";
    extensionMap[".css"] = "Code";
}

void Organizer::organize() {
    if (!fs::exists(rootPath) || !fs::is_directory(rootPath)) {
        std::cerr << "Invalid directory path: " << rootPath << std::endl;
        return;
    }

    std::cout << "Organizing folder: " << rootPath << std::endl;

    for (const auto& entry : fs::directory_iterator(rootPath)) {
        if (entry.is_regular_file()) {
            moveFile(entry);
        }
    }
    std::cout << "Organization complete!" << std::endl;
}

std::string Organizer::getCategory(const std::string& extension) {
    std::string ext = extension;
    std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);

    if (extensionMap.find(ext) != extensionMap.end()) {
        return extensionMap[ext];
    }
    return "Others";
}

void Organizer::moveFile(const fs::directory_entry& entry) {
    std::string ext = entry.path().extension().string();
    if (ext.empty()) return;

    std::string category = getCategory(ext);
    fs::path categoryDir = rootPath / category;

    if (!fs::exists(categoryDir)) {
        fs::create_directory(categoryDir);
    }

    fs::path targetPath = categoryDir / entry.path().filename();
    
    // Handle duplicates by renaming
    if (fs::exists(targetPath)) {
        int counter = 1;
        std::string stem = entry.path().stem().string();
        std::string extension = entry.path().extension().string();
        do {
            targetPath = categoryDir / (stem + "_" + std::to_string(counter++) + extension);
        } while (fs::exists(targetPath));
    }

    try {
        fs::rename(entry.path(), targetPath);
        std::cout << "Moved: " << entry.path().filename() << " -> " << category << std::endl;
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error moving file " << entry.path().filename() << ": " << e.what() << std::endl;
    }
}
