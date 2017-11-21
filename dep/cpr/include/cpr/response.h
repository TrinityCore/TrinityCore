#ifndef CPR_RESPONSE_H
#define CPR_RESPONSE_H

#include <cstdint>
#include <string>

#include "cpr/cookies.h"
#include "cpr/cprtypes.h"
#include "cpr/defines.h"
#include "cpr/error.h"

namespace cpr {

class Response {
  public:
    Response() = default;

    template <typename TextType, typename HeaderType, typename UrlType, typename CookiesType,
              typename ErrorType>
    Response(const std::int32_t& p_status_code, TextType&& p_text, HeaderType&& p_header, UrlType&& p_url,
             const double& p_elapsed, CookiesType&& p_cookies = Cookies{},
             ErrorType&& p_error = Error{})
            : status_code{p_status_code}, text{CPR_FWD(p_text)}, header{CPR_FWD(p_header)},
              url{CPR_FWD(p_url)}, elapsed{p_elapsed}, cookies{CPR_FWD(p_cookies)},
              error{CPR_FWD(p_error)} {}

    std::int32_t status_code;
    std::string text;
    Header header;
    Url url;
    double elapsed;
    Cookies cookies;
    Error error;
};

} // namespace cpr

#endif
