#pragma once

#include "prerequisites.hpp"
#include "exceptions.hpp"
#include "texture2d.hpp"

namespace libtoy
{
    class ImageUtils
    {
	public:
        template<class _PixelType>
        static void save_texture_as_ppm6(std::ostringstream& oss, const Texture2D<_PixelType>& tex)
        {
			resolution_t resolution = tex.get_resolution();

			// form the header
			oss << "P6" << std::endl;
			oss << resolution[0] << " "
				<< resolution[1] << std::endl;
			oss << "255" << std::endl;

			// output image data
			for (int y = 1; y <= resolution[1]; ++y)
			{
				for (int x = 0; x < resolution[0]; ++x)
				{
					_PixelType clr = tex[x][resolution[1] - y];
					auto r = static_cast<uint8_t>(clr.R * 255.0f);
					auto g = static_cast<uint8_t>(clr.G * 255.0f);
					auto b = static_cast<uint8_t>(clr.B * 255.0f);

					oss << r << g << b;
				}
			}
        }


        template<class _PixelType>
        static void save_texture_as_ppm6(const std::string& filepath, const Texture2D<_PixelType>& tex)
		{
			std::ofstream bmp_file(file_path, std::ios::binary);
			if (false == bmp_file.is_open())
			{
				throw msg_exception("cannot open the file for outputting bmp data");
			}

			std::ostringstream oss;
			save_texture_as_ppm6(oss, tex);
			bmp_file << oss.str();
		}
    };
}





