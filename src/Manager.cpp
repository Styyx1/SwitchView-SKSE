#include "Manager.h"
#include "Settings.h"

void CameraSwitch::ViewChanger::Change()
{
	const auto& player = RE::PlayerCharacter::GetSingleton();
	const auto& p_cam = RE::PlayerCamera::GetSingleton();
	const auto settings = Settings::GetSingleton();
	static bool view_saved{ false };
	if (Settings::in_combat == true) {
		logger::info("In Combat settings active");
		switch (Settings::lock_third_person) {
		case (true):
			{
				if (p_cam->IsInFirstPerson() && player->IsInCombat()) {
					view_saved = true;
					p_cam->ForceThirdPerson();
				}
				if (p_cam->IsInThirdPerson() && !player->IsInCombat() && view_saved) {
					view_saved = false;
					p_cam->ForceFirstPerson();
				}
				break;
			case (false):
				if (p_cam->IsInThirdPerson() && player->IsInCombat()) {
					view_saved = true;
					p_cam->ForceFirstPerson();
				}
				if (p_cam->IsInFirstPerson() && !player->IsInCombat() && view_saved) {
					view_saved = false;
					p_cam->ForceThirdPerson();
				}
				break;
			}
		}
	}
	if (settings->in_combat == false) {
		switch (Settings::lock_third_person) {
		case (true):
			{
				if (p_cam->IsInFirstPerson() && player->IsWeaponDrawn()) {
					view_saved = true;
					p_cam->ForceThirdPerson();
				}
				if (p_cam->IsInThirdPerson() && !player->IsWeaponDrawn() && view_saved) {
					view_saved = false;
					p_cam->ForceFirstPerson();
				}
				break;
			case (false):
				if (p_cam->IsInThirdPerson() && player->IsWeaponDrawn()) {
					view_saved = true;
					p_cam->ForceFirstPerson();
				}
				if (p_cam->IsInFirstPerson() && !player->IsWeaponDrawn() && view_saved) {
					view_saved = false;
					p_cam->ForceThirdPerson();
				}
				break;
			}
		}
	};
};
	void CameraSwitch::ViewChanger::ActorUpdateF(RE::Actor* a_actor, float a_zPos, RE::TESObjectCELL* a_cell)
{
	auto switcher = CameraSwitch::ViewChanger::GetSingleton();
	switcher->Change();	
	return _ActorUpdateF(a_actor, a_zPos, a_cell); 
}

		






