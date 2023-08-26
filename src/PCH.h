#pragma once

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include "RE/Skyrim.h"
#include "SKSE/SKSE.h"
#include <ClibUtil/numeric.hpp>
#include <ClibUtil/simpleINI.hpp>
#include <ClibUtil/string.hpp>
#include <spdlog/sinks/basic_file_sink.h>


#define DLLEXPORT __declspec(dllexport)

namespace logger = SKSE::log;
using namespace std::literals;

namespace stl
{
	using namespace SKSE::stl;
}
#ifdef SKYRIM_AE
#	define OFFSET(se, ae) ae
#else
#	define OFFSET(se, ae) se
#endif

#include "Version.h"
