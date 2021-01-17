#pragma once

#include "prerequisites.hpp"

namespace libtoy
{
    /* **************************************************************
     * DECLARATION
    ************************************************************** */
    template<class _PixelType>
    class Texture2D
    {
    public:
        struct PixelResolver
        {
            friend Texture2D;
        public:
            _PixelType& operator[](int y);

        private:
            _PixelType* _base;
            int _x;
            int _width;
        };

    public:
        Texture2D() = delete;
        explicit Texture2D(const resolution_t& resolution);
        Texture2D(const Texture2D& rhs);
        Texture2D(Texture2D&& rhs) noexcept;
        virtual ~Texture2D() noexcept;

        Texture2D& operator=(const Texture2D& rhs);
        Texture2D& operator=(Texture2D&& rhs) noexcept;

    public:
        PixelResolver operator[](int x);

    private:
        resolution_t _resolution;
        uptr<_PixelType[]> _pixels;
    };


    /* **************************************************************
     * DEFINITIONS
    ************************************************************** */
    template<class _PixelType>
    inline Texture2D<_PixelType>::Texture2D(const resolution_t& resolution)
        : _resolution(resolution)
        , _pixels(std::make_unique<_PixelType[]>((resolution[0] * resolution[1])))
    {}

    template<class _PixelType>
    inline Texture2D<_PixelType>::Texture2D(const Texture2D& rhs)
        : _resolution(rhs._resolution)
        , _pixels(std::make_unique<_PixelType>(rhs._pixels))
    {}

    template<class _PixelType>
    inline Texture2D<_PixelType>::Texture2D(Texture2D&& rhs) noexcept
        : _resolution(std::move(rhs._resolution))
        , _pixels(std::move(rhs._pixels))
    {}

    template<class _PixelType>
    inline Texture2D<_PixelType>::~Texture2D() noexcept
    {}

    template<class _PixelType>
    inline Texture2D<_PixelType>& Texture2D<_PixelType>::operator=(const Texture2D& rhs)
    {
        _resolution = rhs._resolution;
        _pixels = std::make_unique<_PixelType>(rhs._pixels);
        return *this;
    }

    template<class _PixelType>
    inline Texture2D<_PixelType>& Texture2D<_PixelType>::operator=(Texture2D&& rhs) noexcept
    {
        _resolution = std::move(rhs._resolution);
        _pixels = std::move(rhs._pixels);
        return *this;
    }

    template<class _PixelType>
    inline typename Texture2D<_PixelType>::PixelResolver Texture2D<_PixelType>::operator[](int x)
    {
        PixelResolver resolver;
        resolver._base = _pixels.get();
        resolver._x = x;
        resolver._width = _resolution[0];
        return resolver;
    }

    template<class _PixelType>
    inline _PixelType& Texture2D<_PixelType>::PixelResolver::operator[](int y)
    {
        _PixelType* pixel = _base + (_x + y * _width);
        return *pixel;
    }

}



