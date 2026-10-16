modded class ModItemRegisterCallbacks
{
	override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{
		super.RegisterOneHanded(pType, pBehavior);

		//! SWISS KNIFE
		pType.AddItemInHandsProfileIK("ZenSwissKnife", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/screwdriver.anm");
		pType.AddItemInHandsProfileIK("ZenSwissKnife_Lockpick", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/screwdriver.anm");
		pType.AddItemInHandsProfileIK("ZenSwissKnife_CanOpener", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/screwdriver.anm");
	}
}