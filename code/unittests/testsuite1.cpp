#include "gtest/gtest.h"
#include "libtoy.hpp"

using namespace libtoy;

namespace TestSuite1NS
{

    TEST(TestSuite1, Case1)
    {
        EXPECT_EQ(1, 1);
    }

    TEST(Texture2DTests, getset)
    {
        Texture2D<pixel_rgba_t> tex2d({ 4, 4 });

        for (int y = 0; y < 4; ++y)
        {
            for (int x = 0; x < 4; ++x)
            {
                auto test_pixel = pixel_rgba_t({
                    (uint8_t)(x),
                    (uint8_t)(x),
                    (uint8_t)(y*10),
                    (uint8_t)(y*10) });
                tex2d[x][y] = test_pixel;
            }
        }

        EXPECT_EQ(pixel_rgba_t({0, 0, 0, 0}), tex2d[0][0]);
        EXPECT_EQ(pixel_rgba_t({3, 3, 30, 30}), tex2d[3][3]);
        EXPECT_EQ(pixel_rgba_t({1, 1, 20, 20}), tex2d[1][2]);
        EXPECT_EQ(pixel_rgba_t({2, 2, 10, 10}), tex2d[2][1]);
    }

}

