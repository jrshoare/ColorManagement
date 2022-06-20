// ColorMgmtExample.Test.cpp
//

#include <ColorTransform.h>
#include <vector>
#include <iostream>

int main()
{
	try
	{
		std::cout << "Create the transform" << std::endl;
		std::wstring iccpath = L"ColorMgmtExample.icc";
		Ffei::Example::ColorTransform xform(iccpath);

		uint32_t pixels_per_line = 1024;
		uint32_t line_count = 512;
		uint32_t bytes_per_pixel = 3;
		uint32_t padding_bytes = 5;
		uint32_t line_stride = (pixels_per_line * bytes_per_pixel) + padding_bytes;
		uint32_t buffer_size = line_stride * line_count;

		std::vector<uint8_t> buffer(buffer_size);

		std::cout << "Fill a sample buffer with greyscale pixels" << std::endl;
		// fill buffer with greyscale pixels 0..255
		uint32_t line_offset = 0;
		for (uint32_t line = 0; line < line_count; line++)
		{
			uint32_t pixel_offset = line_offset;
			uint32_t color = 0;
			for (uint32_t pixel = 0; pixel < pixels_per_line; pixel++)
			{
				uint8_t fill_color = (uint8_t)(color % 256);

				buffer[pixel_offset] = fill_color;
				buffer[pixel_offset + 1] = fill_color;
				buffer[pixel_offset + 2] = fill_color;

				color++;
				pixel_offset += bytes_per_pixel;
			}
			// set padding bytes to 0xEF
			for (uint32_t padding = 0; padding < padding_bytes; padding++)
			{
				buffer[pixel_offset + padding] = 0xEF;
			}

			line_offset += line_stride;
		}

		std::cout << "Perform the transform" << std::endl;
		// transform the contents of the buffer in situ
		xform.Transform(&buffer[0], pixels_per_line, line_count, line_stride);

		std::cout << "Done!" << std::endl;
	}
	catch (const std::runtime_error& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}
