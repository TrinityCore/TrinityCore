#include "cpr/proxies.h"

#include <initializer_list>
#include <map>
#include <string>
#include <utility>

namespace cpr {

Proxies::Proxies(const std::initializer_list<std::pair<const std::string, std::string>>& hosts)
        : hosts_{hosts} {}

bool Proxies::has(const std::string& protocol) const {
    return hosts_.count(protocol) > 0;
}

const std::string& Proxies::operator[](const std::string& protocol) {
    return hosts_[protocol];
}

} // namespace cpr
