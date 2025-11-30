#include <iostream>
#include <string>
#include "Organizer.h"

int main(int argc, char* argv[]) {
    std::string path;

    if (argc > 1) {
        path = argv[1];
    } else {
        std::cout << "Enter the full path of the folder to organize: ";
        std::getline(std::cin, path);
    }

    if (path.empty()) {
        std::cout << "No path provided. Exiting." << std::endl;
        return 1;
    }

    Organizer organizer(path);
    organizer.organize();

    std::cout << "Press Enter to exit...";
    std::cin.get(); 

    return 0;
}
