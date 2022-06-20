#pragma once

#ifdef COLORMGMTEXAMPLE_EXPORT
#	define COLORMGMTEXAMPLE_API	__declspec(dllexport)
#else
#	define COLORMGMTEXAMPLE_API	__declspec(dllimport)
#endif
