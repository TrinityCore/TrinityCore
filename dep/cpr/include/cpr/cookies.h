#ifndef CPR_COOKIES_H
#define CPR_COOKIES_H

#include <initializer_list>
#include <map>
#include <sstream>
#include <string>

namespace cpr {

class Cookies {
  public:
    Cookies() {}
    Cookies(const std::initializer_list<std::pair<const std::string, std::string>>& pairs);
    Cookies(const std::map<std::string, std::string>& map) : map_{map} {}

    std::string& operator[](const std::string& key);
    std::string GetEncoded() const;

  private:
    std::map<std::string, std::string> map_;
};

} // namespace cpr

#endif
