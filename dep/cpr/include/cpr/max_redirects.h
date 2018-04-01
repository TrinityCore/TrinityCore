#ifndef CPR_MAX_REDIRECTS_H
#define CPR_MAX_REDIRECTS_H

#include <cstdint>

namespace cpr {

class MaxRedirects {
  public:
    explicit MaxRedirects(const std::int32_t number_of_redirects)
            : number_of_redirects(number_of_redirects) {}

    std::int32_t number_of_redirects;
};

} // namespace cpr

#endif
