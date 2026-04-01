#include <iostream>
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0A00 // Windows 10 for cpp-httplib
#endif
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
    // Cliente apuntando al dominio

    // Request GET
    auto res = cpr::Get(cpr::Url{"https://api.chucknorris.io/jokes/random"});

    if (res.status_code == 200) {
        // Parseo el JSON
        json joke = json::parse(res.text);

        std::cout << " CHISTE DE CHUCK NORRIS \n";
        std::cout << joke["value"].get<std::string>() << std::endl;
        std::cout << "\nURL: " << joke["url"].get<std::string>() << std::endl;
    } else {
        std::cout << "Error al conectarse a la API: " 
                  << res.status_code 
                  << std::endl;
    }

    return 0;
}
