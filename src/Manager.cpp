#include "Manager.h"

void CameraSwitch::ViewChanger::Change()
{
	const auto player = RE::PlayerCharacter::GetSingleton();
	const auto p_cam = RE::PlayerCamera::GetSingleton();
	static bool view_saved{false};

	if (player->IsInCombat())
	{
		view_saved = true;
		p_cam->ForceThirdPerson();
		//logger::info("changed View");		
	}		
	if (p_cam->IsInThirdPerson() && !player->IsInCombat() && view_saved) {
		view_saved = false;
		p_cam->ForceFirstPerson();
		//logger::info("returned to init view");
	}		
};
void CameraSwitch::ViewChanger::ActorUpdateF(RE::Actor* a_actor, float a_zPos, RE::TESObjectCELL* a_cell)
{
	auto switcher = CameraSwitch::ViewChanger::GetSingleton();
	switcher->Change();	
	return _ActorUpdateF(a_actor, a_zPos, a_cell); 
}

		






