#pragma once
#include "ColorProfile.h"
#include <lcms2.h>

namespace Ffei
{
namespace Example
{

	class ColorTransformImpl
	{
	public:
		ColorTransformImpl();
		virtual ~ColorTransformImpl();

	public:
		void Create(const ColorProfileImpl& input, const ColorProfileImpl& output);

		void Transform(uint8_t *buffer, uint32_t pixels_per_line, uint32_t line_count, uint32_t line_stride);

	private:
		cmsHTRANSFORM _handle;
	};

}
}
