#ifndef CPR_AUTH_H
#define CPR_AUTH_H

#include <string>

#include "cpr/defines.h"

namespace cpr {

class Authentication {
  public:
    template <typename UserType, typename PassType>
    Authentication(UserType&& username, PassType&& password)
            : username_{CPR_FWD(username)}, password_{CPR_FWD(password)},
              auth_string_{username_ + ":" + password_} {}

    const char* GetAuthString() const noexcept;

  private:
    std::string username_;
    std::string password_;
    std::string auth_string_;
};

} // namespace cpr

#endif
