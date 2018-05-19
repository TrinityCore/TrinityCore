#include "cpr/ssl_options.h"

namespace cpr {

VerifySsl::VerifySsl(bool verify) : verify_{verify} {}

VerifySsl::operator bool() const {
    return verify_;
}

} // namespace cpr
