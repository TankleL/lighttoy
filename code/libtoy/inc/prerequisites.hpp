#pragma once

#include <type_traits>
#include <array>
#include <memory>
#include <cassert>
#include <limits>
#include "eigen"

namespace libtoy
{
    template<typename T>
    using uptr = std::unique_ptr<T>;

    template<typename T>
    using sptr = std::shared_ptr<T>;

    template<typename T>
    using wptr = std::weak_ptr<T>;
    

    using scalar_t = float;
    //using scalar_t = double;

    constexpr scalar_t SCALAR_EPSILON = std::numeric_limits<scalar_t>::epsilon();

    typedef std::array<int, 2> resolution_t; // [0] for width, [1] for height

    typedef struct {
        union 
        {
            scalar_t RGB[3];
            scalar_t R;
            scalar_t G;
            scalar_t B;
        };
    } pixel_rgb_t;

    typedef struct {
        union 
        {
            scalar_t RGBA[4];

            struct {
                scalar_t R;
                scalar_t G;
                scalar_t B;
                scalar_t A;
            };
        };
    } pixel_rgba_t;

    inline bool scalar_equal(const scalar_t& left, const scalar_t& right)
    {
        return std::abs(left - right) <= SCALAR_EPSILON;
    }

    inline bool operator==(const pixel_rgba_t& left, const pixel_rgba_t& right)
    {
        return scalar_equal(left.R, right.R) &&
            scalar_equal(left.G, right.G) &&
            scalar_equal(left.B, right.B) &&
            scalar_equal(left.A, right.A);
    }
}



