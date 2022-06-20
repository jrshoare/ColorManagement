#include "pch.h"
#include "ColorProfile.h"
#include "ColorProfileImpl.h"
#include <string>

namespace Ffei
{
namespace Example
{

	ColorProfile::ColorProfile()
		: _profile(std::make_unique<ColorProfileImpl>())
	{

	}

	/*virtual*/ ColorProfile::~ColorProfile()
	{

	}

	void ColorProfile::Open(const std::wstring& filepath)
	{
		_profile->Open(filepath);
	}

	void ColorProfile::Create_sRGB()
	{
		_profile->Create_sRGB();
	}

	bool ColorProfile::HasTag(uint32_t tag)
	{
		return _profile->HasTag(tag);
	}
}
}