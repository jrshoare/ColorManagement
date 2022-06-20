#pragma once
#include <memory>
#include <string>

namespace Ffei
{
namespace Example
{

	// forward declare implementation class
	class ColorProfileImpl;

	// defines an color profile
	class ColorProfile
	{
	public:
		ColorProfile();
		virtual ~ColorProfile();

	public:
		void Open(const std::wstring& filepath);
		void Create_sRGB();
		bool HasTag(uint32_t tag);

	private:
		std::unique_ptr<ColorProfileImpl> _profile;

	private:
		friend class ColorTransform;
	};

}
}

