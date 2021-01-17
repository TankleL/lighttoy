#pragma once

#include <type_traits>
#include <array>
#include <memory>
#include <cassert>
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

    typedef std::array<int, 2> resolution_t; // [0] for width, [1] for height

    typedef struct {
        union 
        {
            std::uint8_t RGB[3];
            std::uint8_t R;
            std::uint8_t G;
            std::uint8_t B;
        };
    } pixel_rgb_t;

    typedef struct {
        union 
        {
            std::uint8_t RGBA[4];

            struct {
                std::uint8_t R;
                std::uint8_t G;
                std::uint8_t B;
                std::uint8_t A;
            };
        };
    } pixel_rgba_t;

    inline bool operator==(const pixel_rgba_t& left, const pixel_rgba_t& right)
    {
        return left.R == right.R &&
            left.G == right.G &&
            left.B == right.B &&
            left.A == right.A;
    }
}



