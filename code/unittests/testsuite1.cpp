#include "gtest/gtest.h"
#include "libtoy.hpp"

using namespace libtoy;

namespace TestSuite1NS
{

    inline Texture2D<pixel_rgba_t> _create_test_texture1()
    {
        Texture2D<pixel_rgba_t> tex2d({ 4, 4 });

        for (int y = 0; y < 4; ++y)
        {
            for (int x = 0; x < 4; ++x)
            {
                auto test_pixel = pixel_rgba_t({
                    (scalar_t)(x),
                    (scalar_t)(x),
                    (scalar_t)(y*10),
                    (scalar_t)(y*10) });
                tex2d[x][y] = test_pixel;
            }
        }

        return tex2d;
    }

    TEST(TestSuite1, Case1)
    {
        EXPECT_EQ(1, 1);
    }

    TEST(Texture2DTests, getset)
    {
        Texture2D<pixel_rgba_t> tex2d = _create_test_texture1();

        EXPECT_EQ(pixel_rgba_t({0, 0, 0, 0}), tex2d[0][0]);
        EXPECT_EQ(pixel_rgba_t({3, 3, 30, 30}), tex2d[3][3]);
        EXPECT_EQ(pixel_rgba_t({1, 1, 20, 20}), tex2d[1][2]);
        EXPECT_EQ(pixel_rgba_t({2, 2, 10, 10}), tex2d[2][1]);
    }

    TEST(ImageUtilsTests, save_ppm6)
    {
        Texture2D<pixel_rgba_t> tex2d = _create_test_texture1();

        std::ostringstream oss;
        ImageUtils::save_texture_as_ppm6(oss, tex2d);
    }
}

