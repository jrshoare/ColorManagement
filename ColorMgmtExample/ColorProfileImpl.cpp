#include "pch.h"
#include "ColorProfileImpl.h"
#include <codecvt>
#include <stdexcept>

namespace Ffei
{
namespace Example
{

	ColorProfileImpl::ColorProfileImpl()
		: _handle(nullptr)
	{

	}

	/*virtual*/ ColorProfileImpl::~ColorProfileImpl()
	{
		if (_handle != nullptr)
		{
			cmsCloseProfile(_handle);
			_handle = nullptr;
		}
	}

	void ColorProfileImpl::Open(const std::wstring& filepath)
	{
		if (_handle != nullptr)
		{
			throw std::runtime_error("profile is already open");
		}

		// lcms requires path as 'const char *' so convert wide string to UTF-8
		std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
		std::string str_path = converter.to_bytes(filepath);
		const char *icc_path = str_path.c_str();

		cmsHPROFILE handle = cmsOpenProfileFromFile(icc_path, "r");
		if (handle == nullptr)
		{
			throw std::runtime_error("failed to open profile");
		}
		_handle = handle;
	}

	void ColorProfileImpl::Create_sRGB()
	{
		if (_handle != nullptr)
		{
			throw std::runtime_error("profile is already open");
		}

		cmsHPROFILE handle = cmsCreate_sRGBProfile();
		if (handle == nullptr)
		{
			throw std::runtime_error("failed to create sRGB profile");
		}
		_handle = handle;
	}

	bool ColorProfileImpl::HasTag(uint32_t tag)
	{
		if (_handle == nullptr)
		{
			throw std::runtime_error("profile is not open");
		}

		cmsBool hasTag = cmsIsTag(_handle, (cmsTagSignature)tag);
		return hasTag == TRUE;
	}

}
}