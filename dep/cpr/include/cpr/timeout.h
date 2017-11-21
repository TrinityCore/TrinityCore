#ifndef CPR_TIMEOUT_H
#define CPR_TIMEOUT_H

#include <chrono>
#include <cstdint>

namespace cpr {

class Timeout {
  public:
    Timeout(const std::chrono::milliseconds& duration) : ms{duration} {}
    Timeout(const std::int32_t& milliseconds) : Timeout{std::chrono::milliseconds(milliseconds)} {}

    long Milliseconds() const;

    std::chrono::milliseconds ms;
};

} // namespace cpr

#endif
