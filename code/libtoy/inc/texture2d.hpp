#pragma once

#include "prerequisites.hpp"

namespace libtoy
{
    class Texture2D
    {
    public:
        Texture2D(const resolution_t& resolution);

    private:
        resolution_t _resolution;
        uptr<pixel_rgb_t> _pixels;
    };

    //public:
    //    Texture2D(const Math::Resolution& resolution);
    //    virtual ~Texture2D();

    //public:
    //    Math::Resolution get_resolution() const;
    //    Math::Color get_pixel(int x, int y) const;
    //    const Light::byte* get_buffer() const;
    //    void set_pixel(int x, int y, const Math::Color& value);
    //        
    //protected:
    //    Math::Resolution				m_resolution;
    //    Light::byte*					m_p_pixels;		// R8G8B8 format, align = 1.
    //};

    //inline Texture2D::Texture2D(const Math::Resolution& resolution) :
    //    m_resolution(resolution),
    //    m_p_pixels(new Light::byte[resolution.get_width() * resolution.get_height() * 3])  // R8G8B8 format, align = 1.
    //{}

    //inline Texture2D::~Texture2D()
    //{}

    //inline Math::Resolution Texture2D::get_resolution() const
    //{
    //    return m_resolution;
    //}

    //inline Math::Color Texture2D::get_pixel(int x, int y) const
    //{
    //    assert(m_resolution.get_width() != 0 && m_resolution.get_height() != 0);
    //    assert(x >= 0 && x <= m_resolution.get_width());
    //    assert(y >= 0 && y <= m_resolution.get_height());

    //    Light::byte* p_pixel = m_p_pixels + (x + y * m_resolution.get_width()) * 3;

    //    Math::Color reval;
    //    reval.m_r = ((Math::decimal)p_pixel[0]) / 255.0f;
    //    reval.m_g = ((Math::decimal)p_pixel[1]) / 255.0f;
    //    reval.m_b = ((Math::decimal)p_pixel[2]) / 255.0f;

    //    return reval;
    //}

    //inline const Light::byte* Texture2D::get_buffer() const
    //{
    //    return m_p_pixels;
    //}

    //inline void Texture2D::set_pixel(int x, int y, const Math::Color& value)
    //{
    //    assert(m_resolution.get_width() != 0 && m_resolution.get_height() != 0);
    //    assert(x >= 0 && x <= m_resolution.get_width());
    //    assert(y >= 0 && y <= m_resolution.get_height());

    //    Light::byte* p_pixel = m_p_pixels + (x + y * m_resolution.get_width()) * 3;
    //    p_pixel[0] = value.m_r * 255;
    //    p_pixel[1] = value.m_g * 255;
    //    p_pixel[2] = value.m_b * 255;
    //}
}



