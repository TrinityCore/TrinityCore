#ifndef CPR_LOW_SPEED_H
#define CPR_LOW_SPEED_H

#include <cstdint>

namespace cpr {

class LowSpeed {
  public:
    LowSpeed(const std::int32_t limit, const std::int32_t time) : limit(limit), time(time) {}

    std::int32_t limit;
    std::int32_t time;
};

} // namespace cpr

#endif
