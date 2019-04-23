#ifndef CPR_PROXIES_H
#define CPR_PROXIES_H

#include <initializer_list>
#include <map>
#include <string>
#include <utility>

namespace cpr {

class Proxies {
  public:
    Proxies() {}
    Proxies(const std::initializer_list<std::pair<const std::string, std::string>>& hosts);

    bool has(const std::string& protocol) const;
    const std::string& operator[](const std::string& protocol);

  private:
    std::map<std::string, std::string> hosts_;
};

} // namespace cpr

#endif
