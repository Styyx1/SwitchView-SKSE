#include "Settings.h"

Settings* Settings::GetSingleton()
{
	static Settings singleton;
	return std::addressof(singleton);
}

void Settings::LoadSettings()
{
	logger::info("Loading settings");
	CSimpleIniA ini;
	ini.SetUnicode();
	constexpr auto path = L"Data/SKSE/Plugins/SwitchViewSKSE.ini";
	ini.LoadFile(path);

	const char* section = "Settings";

	// Load INI file keys from section and populate with default values if not found
	lock_third_person = ini.GetBoolValue(section, "bLockThirdPerson");
	in_combat = ini.GetBoolValue(section, "bInCombat");
}
