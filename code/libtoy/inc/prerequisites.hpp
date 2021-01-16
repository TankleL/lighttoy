#pragma once

#include <type_traits>
#include <array>
#include <memory>
#include "eigen"

namespace libtoy
{
    template<typename T>
    using uptr = std::unique_ptr<T>;

    template<typename T>
    using sptr = std::shared_ptr<T>;

    template<typename T>
    using wptr = std::weak_ptr<T>;
    

    typedef float scalar_t;
    //typedef double scalar_t;

    typedef std::array<int, 2> resolution_t;
    typedef std::array<uint8_t, 3> pixel_rgb_t;
}



