#include "cpr/multipart.h"

namespace cpr {

Multipart::Multipart(const std::initializer_list<Part>& parts) : parts{parts} {}

} // namespace cpr
