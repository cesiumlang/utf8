#pragma once

// Work around missing/deleted char32_t stream operator
// This allows utpp's CheckEqual to print char32_t values properly
// Must be defined BEFORE including utpp to ensure it's found by ADL

#include <ostream>  // IWYU pragma: keep

// Provide the operator for compilers/standards that need it:
// - MSVC 2022+ deletes the char32_t stream operator
// - Clang with C++20 also seems to need this fix
#if (defined(_MSC_VER) && _MSC_VER >= 1930) || \
    (defined(__clang__) && __cplusplus >= 202002L)

    inline std::ostream& operator<<(std::ostream& os, char32_t c) {
        return os << static_cast<uint32_t>(c);
    }

#endif

#include <utpp/utpp.h>  // IWYU pragma: keep
