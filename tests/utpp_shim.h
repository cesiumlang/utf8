#pragma once

// Work around Visual Studio 2022's deleted char32_t stream operator
// This allows utpp's CheckEqual to print char32_t values properly
// Must be defined BEFORE including utpp to ensure it's found by ADL
#include <ostream>  // IWYU pragma: keep
inline std::ostream& operator<<(std::ostream& os, char32_t c) {
    return os << static_cast<uint32_t>(c);
}

#include <utpp/utpp.h>  // IWYU pragma: keep
