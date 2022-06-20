#pragma once
#include <lcms2.h>
#include <string>

namespace Ffei
{
namespace Example
{

	class ColorProfileImpl
	{
	public:
		ColorProfileImpl();
		virtual ~ColorProfileImpl();

	public:
		void Open(const std::wstring& filepath);
		void Create_sRGB();
		bool HasTag(uint32_t tag);

	private:
		cmsHPROFILE _handle;

	private:
		friend class ColorTransformImpl;
	};

}
}
