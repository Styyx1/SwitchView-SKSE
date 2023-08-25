#pragma once

#include "Manager.h"

namespace CameraSwitch
{
	class Hooks : protected ViewChanger
	{
	public:
		Hooks()
		{
		}
		virtual ~Hooks()
		{
		}
		static void InstallActorUpdateHook();

	private:
	protected:
	};
};
