#ifndef CPR_BODY_H
#define CPR_BODY_H

#include <cstring>

#include <initializer_list>
#include <string>

#include "cpr/defines.h"

namespace cpr {

class Body : public std::string {
  public:
    Body() = default;
    Body(const Body& rhs) = default;
    Body(Body&& rhs) = default;
    Body& operator=(const Body& rhs) = default;
    Body& operator=(Body&& rhs) = default;
    explicit Body(const char* raw_string) : std::string(raw_string) {}
    explicit Body(const char* raw_string, size_t length) : std::string(raw_string, length) {}
    explicit Body(size_t to_fill, char character) : std::string(to_fill, character) {}
    explicit Body(const std::string& std_string) : std::string(std_string) {}
    explicit Body(const std::string& std_string, size_t position, size_t length = std::string::npos)
            : std::string(std_string, position, length) {}
    explicit Body(std::string&& std_string) : std::string(std::move(std_string)) {}
    explicit Body(std::initializer_list<char> il) : std::string(il) {}
    template <class InputIterator>
    explicit Body(InputIterator first, InputIterator last)
            : std::string(first, last) {}
};

} // namespace cpr

#endif
