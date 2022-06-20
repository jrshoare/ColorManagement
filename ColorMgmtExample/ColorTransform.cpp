#include "pch.h"
#include "ColorTransform.h"
#include "ColorProfile.h"
#include "ColorTransformImpl.h"

namespace
{
	const uint32_t FEIP_TAG = 0x46454950;	// 'FEIP'
}

namespace Ffei
{
namespace Example
{

	// constructor
	ColorTransform::ColorTransform(const std::wstring& iccpath)
		: _xform(std::make_unique<ColorTransformImpl>())
	{
		// use supplied file as input profile
		ColorProfile inputProfile;
		inputProfile.Open(iccpath);

		// allow only those profiles that contain the private tag written for Sierra slides
		if (!inputProfile.HasTag(FEIP_TAG))
		{
			throw std::runtime_error("unsupported profile type");
		}

		// use sRGB as the output profile
		ColorProfile outputProfile;
		outputProfile.Create_sRGB();

		_xform->Create(*(inputProfile._profile), *(outputProfile._profile));
	}

	/*virtual*/ ColorTransform::~ColorTransform()
	{

	}

	void ColorTransform::Transform(uint8_t *buffer, uint32_t pixels_per_line, uint32_t line_count, uint32_t line_stride)
	{
		_xform->Transform(buffer, pixels_per_line, line_count, line_stride);
	}

}
}