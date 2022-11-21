#include "esp_netif.h"
#include "lwip/inet.h"

#include "esp_http_server.h"

#include <functional>
#include <string_view>
#include <vector>

/// More will get supported in the future
enum class Method {get, post};
struct Route {
    std::string_view uri;
    Method method;
    std::function<void()> handler;
};

class HttpServer {
    httpd_handle_t server = nullptr;
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
    
    /// routes is used for the C++ interface
    std::vector<Route> routes;

    /// routes will be converted to this
    std::vector<httpd_uri_t> uris;

public:
    void addRoute(std::string_view, uri, Method method, std::function<void()> handler);
    void start();
    void end();
};