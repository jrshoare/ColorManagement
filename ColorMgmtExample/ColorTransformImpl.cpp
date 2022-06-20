#include "pch.h"
#include "ColorTransformImpl.h"
#include "ColorProfileImpl.h"
#include <stdexcept>

namespace Ffei
{
namespace Example
{

	ColorTransformImpl::ColorTransformImpl()
		: _handle(nullptr)
	{

	}

	/*virtual*/ ColorTransformImpl::~ColorTransformImpl()
	{
		if (_handle != nullptr)
		{
			cmsDeleteTransform(_handle);
			_handle = nullptr;
		}
	}

	void ColorTransformImpl::Create(const ColorProfileImpl& input, const ColorProfileImpl& output)
	{
		if (_handle != nullptr)
		{
			throw std::runtime_error("transform is already created");
		}

		cmsHTRANSFORM handle = cmsCreateTransform(input._handle, TYPE_RGB_8, output._handle, TYPE_RGB_8, INTENT_RELATIVE_COLORIMETRIC, 0);
		if (handle == nullptr)
		{
			throw std::runtime_error("failed to create transform");
		}
		_handle = handle;
	}

	void ColorTransformImpl::Transform(uint8_t *buffer, uint32_t pixels_per_line, uint32_t line_count, uint32_t line_stride)
	{
		if (_handle == nullptr)
		{
			throw std::runtime_error("transform has not been created");
		}

		cmsDoTransformLineStride(_handle, buffer, buffer, pixels_per_line, line_count, line_stride, line_stride, 0, 0);
	}

}
}