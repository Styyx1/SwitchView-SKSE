#include "Manager.h"
#include "Settings.h"

void CameraSwitch::ViewChanger::Change()
{
	const auto player = RE::PlayerCharacter::GetSingleton();
	const auto p_cam = RE::PlayerCamera::GetSingleton();
	static bool view_saved{ false };

	if (p_cam->IsInFirstPerson() && player->IsInCombat()) {
		view_saved = true;
		p_cam->ForceThirdPerson();
		logger::info("changed View");
	}
	if (p_cam->IsInThirdPerson() && !player->IsInCombat() && view_saved) {
		view_saved = false;
		p_cam->ForceFirstPerson();
		logger::info("returned to init view");
	}
};
	//if (settings->in_combat && settings->lock_third_person) {
	//	if (p_cam->IsInFirstPerson() && player->IsInCombat()) {
	//		view_saved = true;
	//		logger::info("saved view in combat and in third person");
	//		p_cam->ForceThirdPerson();
	//	};
	//	if (p_cam->IsInThirdPerson() && !player->IsInCombat() && view_saved) {
	//		view_saved = false;
	//		logger::info("reverted bool in combat and 3rd person");
	//		p_cam->ForceFirstPerson();
	//		logger::info("reverted view in combat and in third person");
	//	}	
	//}
	//if (settings->in_combat && !settings->lock_third_person) {
	//	if (p_cam->IsInThirdPerson() && player->IsInCombat()) {
	//		view_saved = true;
	//		logger::info("saved view in combat and in first person");
	//		p_cam->ForceFirstPerson();
	//	};
	//	if (p_cam->IsInFirstPerson() && !player->IsInCombat() && view_saved) {
	//		view_saved = false;
	//		logger::info("reverted bool in combat and 1st person");
	//		p_cam->ForceThirdPerson();
	//	};
	//}
	//if (!settings->in_combat && settings->lock_third_person) {
	//	if (p_cam->IsInFirstPerson() && player->IsWeaponDrawn()) {
	//		view_saved = true;
	//		logger::info("saved view outside of combat and in third person");
	//		p_cam->ForceThirdPerson();
	//	};
	//	if (p_cam->IsInThirdPerson() && !player->IsWeaponDrawn() && view_saved) {
	//		view_saved = false;
	//		logger::info("reverted bool outside of combat and 3rd person");
	//		p_cam->ForceFirstPerson();
	//	};
	//}
	//if (!settings->in_combat && !settings->lock_third_person) {
	//	if (p_cam->IsInThirdPerson() && player->IsInCombat()) {
	//		view_saved = true;
	//		logger::info("saved view outside of combat and in first person");
	//		p_cam->ForceFirstPerson();
	//	};
	//	if (p_cam->IsInFirstPerson() && !player->IsInCombat() && view_saved) {
	//		view_saved = false;
	//		logger::info("reverted bool outside of combat and 1st person");
	//		p_cam->ForceThirdPerson();
	//	}
	//}
	

void CameraSwitch::ViewChanger::ActorUpdateF(RE::Actor* a_actor, float a_zPos, RE::TESObjectCELL* a_cell)
{
	auto switcher = CameraSwitch::ViewChanger::GetSingleton();
	switcher->Change();	
	return _ActorUpdateF(a_actor, a_zPos, a_cell); 
}

		






