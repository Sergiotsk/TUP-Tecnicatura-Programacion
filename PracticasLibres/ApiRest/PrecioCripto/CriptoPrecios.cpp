#include <iostream>        // Flujo de E/S estándar: std::cout, std::cin, std::getline
#include <string>          // std::string para manejar cadenas de texto
#include <unordered_map>   // std::unordered_map para mapear TICKER -> ID de CoinGecko
#include <algorithm>       // std::transform para convertir a mayúsculas
#include <optional>        // std::optional para devolver precio o "sin valor"
#include <cpr/cpr.h>       // Librería CPR: cliente HTTP basado en libcurl
#include <nlohmann/json.hpp> // Librería JSON para parsear respuestas HTTP

using json = nlohmann::json; // Alias de tipo: escribimos 'json' en vez de 'nlohmann::json'

// Mapa de tickers (lo que escribe el usuario) a IDs oficiales de CoinGecko
// Ejemplo: "BTC" -> "bitcoin"; CoinGecko usa IDs en minúsculas y palabras completas
const std::unordered_map<std::string, std::string> TICKER_TO_ID = {
    {"BTC", "bitcoin"},     // Bitcoin
    {"ETH", "ethereum"},    // Ethereum
    {"SOL", "solana"},      // Solana
    {"ADA", "cardano"},     // Cardano
    {"DOT", "polkadot"},    // Polkadot
    {"BNB", "binancecoin"}, // BNB (Binance Coin)
    {"XRP", "ripple"},      // XRP (Ripple)
    {"DOGE", "dogecoin"}    // Dogecoin

  };

// Utilidad: convierte una cadena a MAYÚSCULAS para comparar tickers sin importar el caso
std::string to_upper(std::string s) {
    // std::transform aplica una función (toupper) a cada carácter del rango [begin, end)
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return std::toupper(c); });
    return s; // Devuelve la cadena transformada
}

// Llama al endpoint /simple/price de CoinGecko para obtener el precio de 'id' en la moneda 'vs'
// Devuelve std::optional<double>: tiene valor si la llamada y el parseo fueron correctos; 
// devuelve std::nullopt si hubo error de red/HTTP o estructura JSON inesperada.
std::optional<double> fetch_price(const std::string& id, const std::string& vs) {
    // Construye y ejecuta una petición GET con CPR
    auto res = cpr::Get(
        cpr::Url{"https://api.coingecko.com/api/v3/simple/price"}, // URL del recurso
        cpr::Parameters{{"ids", id}, {"vs_currencies", vs}},     // Query string ?ids=...&vs_currencies=...
        cpr::Timeout{5000},                                         // Timeout de 5 segundos
        cpr::Header{{"User-Agent", "ApiRestMenu/1.0"}}           // Cabecera opcional (buen práctica)
    );

    // Si hubo error de red (res.error) o el HTTP status no fue 200 OK, devolvemos "sin valor"
    if (res.error || res.status_code != 200) return std::nullopt;

    try {
        // Parseamos el cuerpo de la respuesta (res.text) como JSON
        json j = json::parse(res.text);
        // Esperamos una estructura { "<id>": { "<vs>": <precio> } }
        if (j.contains(id) && j[id].contains(vs)) {
            return j[id][vs].get<double>(); // Extraemos el precio como double
        }
    } catch (...) {
        // Cualquier excepción de parseo/accés queda silenciada y devolvemos "sin valor"
    }
    return std::nullopt; // No se halló el dato esperado
}

int main() {
    const std::string vs = "usd"; // Moneda fiat en la que queremos ver el precio (USD)

    while (true) { // Bucle del menú interactivo
        std::cout << "\n== Consulta de precio (CoinGecko) ==\n"; // Título del menú
        std::cout << "Ingrese ticker (BTC, ETH, SOL, ...), o 'salir': "; // Prompt al usuario
        std::string ticker; // Variable donde guardamos lo ingresado
        if (!std::getline(std::cin, ticker)) break; // Si falla la entrada, salimos del programa

        if (ticker == "salir" || ticker == "SALIR") break; // Condición de salida explícita
        ticker = to_upper(ticker); // Normalizamos a MAYÚSCULAS para buscar en el mapa

        // Buscamos el ticker en el mapa; si no existe, informamos y pedimos otro
        auto it = TICKER_TO_ID.find(ticker);
        if (it == TICKER_TO_ID.end()) {
            std::cout << "Ticker desconocido. Agregalo al mapa TICKER_TO_ID o intenta otro.\n";
            continue; // Volvemos al inicio del bucle para pedir otra entrada
        }

        // Obtenemos el precio: traducimos ticker -> id (it->second) y consultamos en 'vs'
        auto price = fetch_price(it->second, vs);
        if (price.has_value()) {
            // *price desreferencia el optional y muestra el double contenido
            std::cout << "Precio de " << ticker << ": " << *price << " " << vs << "\n";
        } else {
            // Mensaje de error genérico; puede ser red, HTTP distinto de 200 o JSON inesperado
            std::cout << "No se pudo obtener el precio (red/HTTP/JSON).\n";
        }
    }

    std::cout << "Hasta luego.\n"; // Mensaje final de despedida
    return 0; // Código de salida exitoso del programa
}

/*
=========================================
 Recordatorio de compilación (MSYS2 MinGW)
=========================================
Requisitos instalados con pacman (desde "MSYS2 MinGW x64"):
  - mingw-w64-x86_64-cpr
  - mingw-w64-x86_64-nlohmann-json
  (Estos paquetes traen libcurl, OpenSSL y zlib necesarios.)

Compilar con g++ de MinGW64 (importante usar este ejecutable):
  C:\msys64\mingw64\bin\g++.exe -Wall -Wextra -O2 -std=c++17 CriptoPrecios.cpp ^
    -o output\CriptoPrecios.exe ^
    -I"C:\msys64\mingw64\include" -L"C:\msys64\mingw64\lib" ^
    -lcpr -lcurl -lssl -lcrypto -lz -lws2_32 -lcrypt32

Ejecución:
  - Asegurar que C:\msys64\mingw64\bin esté en el PATH al ejecutar el .exe
    (para que encuentre las DLLs de curl/openssl/zlib).
  - Ejecutar: .\output\CriptoPrecios.exe

Notas:
  - Si aparece "undefined reference" al linkear, verificar que se usó el g++ de mingw64
    y que los paquetes están instalados.
  - Si falta algún header (cpr/json), revisar que los includes apunten a mingw64\include.

Alternativa con CMake (opcional):
  - Crear un CMakeLists.txt que encuentre cpr y nlohmann_json y haga target_link_libraries
    (simplifica recordar flags). 
*/

/*
=========================================
 Guía conceptual: Flujo de un API REST en C++
=========================================
1) ¿Qué es un API REST?
   - Un servicio web que expone recursos (datos/acciones) mediante URLs (endpoints) usando HTTP.
   - Usa métodos HTTP estándar: GET (leer), POST (crear), PUT/PATCH (actualizar), DELETE (borrar).
   - Los datos se envían/reciben usualmente en JSON. El servidor responde con un código de estado HTTP.

2) Flujo general de consumo (cliente):
   - a) Construir la URL del endpoint (por ejemplo, /api/v3/simple/price).
   - b) Preparar parámetros de consulta (query string), headers y timeouts.
   - c) Enviar la solicitud (request) y esperar la respuesta (response).
   - d) Verificar errores de red (timeout, DNS, TLS) y el status code (2xx = OK, 4xx/5xx = error).
   - e) Parsear el cuerpo (JSON) y extraer los campos que necesitás.
   - f) Manejar errores y casos borde (campos faltantes, tipos inesperados, límite de rate, etc.).

3) ¿Qué es el "parseo" (parsing)?
   - Es el proceso de convertir una cadena de texto (por ejemplo, la respuesta JSON) a una estructura
     de datos en memoria que el programa pueda manipular (objetos, mapas, arrays, números, strings).
   - En este programa: usamos nlohmann::json para parsear res.text a un objeto json.
     Ejemplo: json j = json::parse(res.text);
   - "Serializar" es el proceso inverso: convertir estructuras a texto JSON para enviarlas.

4) Herramientas usadas en C++
   - cpr: cliente HTTP (encima de libcurl). Permite hacer GET/POST, setear headers, timeouts, etc.
   - nlohmann::json: parser JSON estilo DOM (cargás todo el JSON en memoria y accedés por llaves).
   - std::optional: expresa "valor o ausencia de valor" sin usar números mágicos ni punteros nulos.
   - std::unordered_map: para mapear tickers a IDs de CoinGecko.

5) Cabeceras y headers HTTP
   - Content-Type: describe el formato (application/json).
   - Authorization: tokens/keys si la API lo requiere (CoinGecko en general no pide key para simple/price).
   - User-Agent: buena práctica identificar tu cliente.

6) Códigos de estado HTTP (muy comunes)
   - 200 OK: éxito.
   - 400 Bad Request: parámetros inválidos.
   - 401 Unauthorized / 403 Forbidden: falta o no válido el token/API key.
   - 404 Not Found: endpoint o recurso inexistente.
   - 429 Too Many Requests: límite de rate excedido (aplicá backoff/retry).
   - 5xx: error del servidor (reintentar con backoff exponencial).

7) Buenas prácticas de cliente
   - Timeouts: evitá colgarte indefinidamente (cpr::Timeout{...}).
   - Retries/backoff: ante 429/5xx, reintentá con espera creciente.
   - Manejo de errores: chequeá res.error y res.status_code antes de parsear.
   - Validación de JSON: corroborá que existan las llaves y tipos antes de acceder.
   - Logging: registrá errores y respuestas inesperadas para diagnosticar.
   - Rate limiting: respetá límites de la API (CoinGecko tiene límites públicos documentados).
   - TLS/SSL: asegurate de tener librerías/dlls de OpenSSL o SChannel según el stack.

8) Consideraciones específicas en C++
   - Excepciones: json::parse puede lanzar; capturá y manejá para no crashear.
   - Tipos numéricos: los precios pueden ser double; considerá precisión/locale.
   - Unicode/UTF-8: strings en JSON suelen estar en UTF-8; nlohmann::json maneja UTF-8.
   - Thread-safety: si consumís APIs desde threads múltiples, asegurate de sincronizar.

9) CoinGecko en particular
   - simple/price: no requiere API key; acepta múltiple ids y múltiples vs_currencies.
   - Evitá hacer llamadas en bucle apretado (agregá sleeps o acumulá consultas).
   - Para datos más ricos (cambios 24h, market caps), usá endpoints más completos.

10) Extensiones para tu programa
   - Permitir múltiples tickers en una sola consulta (ids separados por coma).
   - Elegir la moneda fiat en el menú (usd, ars, eur).
   - Agregar retries/backoff simple si status_code es 429 o 5xx.
   - Guardar un cache simple para evitar repetir llamadas idénticas en poco tiempo.
*/