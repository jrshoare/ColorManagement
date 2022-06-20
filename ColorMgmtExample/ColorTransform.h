#pragma once
#include "ColorMgmtExample.h"
#include <memory>
#include <string>

namespace Ffei
{
namespace Example
{

	// forward declare implementation class
	class ColorTransformImpl;

	// defines a color transform
	class ColorTransform
	{
	public:
		// constructor & destructor
		COLORMGMTEXAMPLE_API ColorTransform(const std::wstring& iccpath);
		virtual COLORMGMTEXAMPLE_API ~ColorTransform();

		// transform the pixels in the input buffer
		// - buffer:			buffer containing 24-bit RGB pixels
		// - pixels_per_line	number of pixels per line
		// - line_count			number of lines
		// - line_stride		number of bytes per line
		void COLORMGMTEXAMPLE_API Transform(uint8_t *buffer, uint32_t pixels_per_line, uint32_t line_count, uint32_t line_stride);

	private:
		std::unique_ptr<ColorTransformImpl> _xform;
	};

}
}

