// Model credit: https://sketchfab.com/3d-models/swiss-army-knife-6eee61cfddfa41eb9cc8685db0d7cf86

class CfgPatches
{
	class ZenSwissKnife
	{
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Scripts"
		};
	};
};

class CfgMods
{
	class ZenSwissKnife
	{
		dir = "ZenSwissKnife";
		name = "Zen's Swiss Knife";
		author = "Zenarchist";
		credits = "";
		version = "1.0";
		type = "mod";
		dependencies[] = 
		{ 
			"Game", 
			"World", 
			"Mission" 
		};
		class defs
		{
			class engineScriptModule
			{
				files[]=
				{
					"ZenSwissKnife/scripts/1_Core",
					"ZenSwissKnife/scripts/Common"
				};
			};
			class gameLibScriptModule
			{
				files[]=
				{
					"ZenSwissKnife/scripts/2_GameLib",
					"ZenSwissKnife/scripts/Common"
				};
			};
			class gameScriptModule
			{
				files[] = 
				{ 
					"ZenSwissKnife/scripts/Common",
					"ZenSwissKnife/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				files[] = 
				{ 
					"ZenSwissKnife/scripts/Common",
					"ZenSwissKnife/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				files[] = 
				{ 
					"ZenSwissKnife/scripts/Common",
					"ZenSwissKnife/scripts/5_mission"
				};
			};
		};
	};
};

class CfgVehicles
{
	class Inventory_Base;

	//! SWISS KNIFE 
	// Swiss knife base
	class ZenSwissKnife: Inventory_Base
	{
		scope=2;

		//! TOOL ENABLE/DISABLE CONFIG OVERRIDE - if you don't want one of these available for use on your server, set to 0.
		ZenSwissKnife_CanOpener		= 1;
		ZenSwissKnife_Lockpick		= 1;
		ZenSwissKnife_Screwdriver	= 1;
		ZenSwissKnife_Knife			= 1;
		ZenSwissKnife_Scissors		= 1;
		ZenSwissKnife_SmallSaw		= 1;

		//! SHARED CONFIG
		displayName="$STR_CfgVehicles_ZenSwissKnife0";
		descriptionShort="$STR_CfgVehicles_ZenSwissKnife1";
		model="ZenSwissKnife\data\models\swissknife\swissknife.p3d";
		inventorySlot[]={ "Knife" };
		animClass="Knife";
		rotationFlags=17;
		isMeleeWeapon=1;
		itemSize[]={1,2};
		weight=300;
		fragility=0.0099999998;
		simpleHiddenSelections[]= 
		{
			"can_opener",
			"packed",
			"large_knife",
			"peg",
			"saw",
			"scissors",
			"small_knife"
	    };
		hiddenSelections[] = 
		{
			"texture"
		};
		hiddenSelectionsTextures[] = 
		{ 
			"ZenSwissKnife\data\textures\swissknife\swissknife_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						// RVMAT damage texture handled in item script
						{
							1,
							
							{
								""
							}
						},
						
						{
							0.69999999,
							
							{
								""
							}
						},
						
						{
							0.5,
							
							{
								""
							}
						},
						
						{
							0.30000001,
							
							{
								""
							}
						},
						
						{
							0,
							
							{
								""
							}
						}
					};
				};
			};
		};
		soundImpactType="metal";
	};

	//! CAN OPENER 
	class CanOpener;
	class ZenSwissKnife_CanOpener: CanOpener
	{
		scope=2;
		//! SHARED
		displayName="$STR_CfgVehicles_ZenSwissKnife0";
		descriptionShort="$STR_CfgVehicles_ZenSwissKnife1";
		model="ZenSwissKnife\data\models\swissknife\swissknife.p3d";
		inventorySlot[]={ "Knife" };
		animClass="Knife";
		rotationFlags=17;
		isMeleeWeapon=1;
		itemSize[]={1,2};
		weight=300;
		fragility=0.0099999998;
		simpleHiddenSelections[]= 
		{
			"can_opener",
			"packed",
			"large_knife",
			"peg",
			"saw",
			"scissors",
			"small_knife"
	    };
		hiddenSelections[] = 
		{
			"texture"
		};
		hiddenSelectionsTextures[] = 
		{ 
			"ZenSwissKnife\data\textures\swissknife\swissknife_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=40; // Vanilla 20
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"ZenSwissKnife\data\textures\swissknife\swissknife.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"ZenSwissKnife\data\textures\swissknife\swissknife.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"ZenSwissKnife\data\textures\swissknife\swissknife.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"ZenSwissKnife\data\textures\swissknife\swissknife.rvmat"
							}
						},
						
						{
							0,
							
							{
								"ZenSwissKnife\data\textures\swissknife\swissknife.rvmat"
							}
						}
					};
				};
			};
		};
		soundImpactType="metal";
		//! CAN OPENER
		openItemSpillRange[]={0,0};
	};

	//! LOCKPICK
	class Lockpick;
	class ZenSwissKnife_Lockpick: Lockpick
	{
		scope=2;
		//! SHARED
		displayName="$STR_CfgVehicles_ZenSwissKnife0";
		descriptionShort="$STR_CfgVehicles_ZenSwissKnife1";
		model="ZenSwissKnife\data\models\swissknife\swissknife.p3d";
		inventorySlot[]={ "Knife" };
		animClass="Knife";
		rotationFlags=17;
		isMeleeWeapon=1;
		itemSize[]={1,2};
		weight=300;
		fragility=0.0099999998;
		simpleHiddenSelections[]= 
		{
			"can_opener",
			"packed",
			"large_knife",
			"peg",
			"saw",
			"scissors",
			"small_knife"
	    };
		hiddenSelections[] = 
		{
			"texture"
		};
		hiddenSelectionsTextures[] = 
		{ 
			"ZenSwissKnife\data\textures\swissknife\swissknife_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=250; // Vanilla 125
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"ZenSwissKnife\data\textures\swissknife\swissknife.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"ZenSwissKnife\data\textures\swissknife\swissknife.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"ZenSwissKnife\data\textures\swissknife\swissknife.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"ZenSwissKnife\data\textures\swissknife\swissknife.rvmat"
							}
						},
						
						{
							0,
							
							{
								"ZenSwissKnife\data\textures\swissknife\swissknife.rvmat"
							}
						}
					};
				};
			};
		};
		soundImpactType="metal";
		//! LOCKPICK STUFF
		RestrainUnlockType=0;
		isLockpick=1;
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeFistLight";
				range=1;
			};
			class Heavy
			{
				ammo="MeleeFistHeavy";
				range=1;
			};
			class Sprint
			{
				ammo="MeleeFistHeavy";
				range=2.8;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class lockpicker_move_in
				{
					soundSet="lockpicker_move_in_SoundSet";
					id=110202;
				};
				class lockpicker_move_out
				{
					soundSet="lockpicker_move_out_SoundSet";
					id=110203;
				};
				class lockpicker_loop
				{
					soundSet="lockpicker_loop_SoundSet";
					id=203;
				};
				class lockpicker_end
				{
					soundSet="lockpicker_end_SoundSet";
					id=110204;
				};
			};
		};
	};

	//! SCREWDRIVER 
	class Screwdriver;
	class ZenSwissKnife_Screwdriver: Screwdriver
	{
		scope=2;
		//! SHARED
		displayName="$STR_CfgVehicles_ZenSwissKnife0";
		descriptionShort="$STR_CfgVehicles_ZenSwissKnife1";
		model="ZenSwissKnife\data\models\swissknife\swissknife.p3d";
		inventorySlot[]={ "Knife" };
		animClass="Knife";
		rotationFlags=17;
		isMeleeWeapon=1;
		itemSize[]={1,2};
		weight=300;
		fragility=0.0099999998;
		simpleHiddenSelections[]= 
		{
			"can_opener",
			"packed",
			"large_knife",
			"peg",
			"saw",
			"scissors",
			"small_knife"
	    };
		hiddenSelections[] = 
		{
			"texture"
		};
		hiddenSelectionsTextures[] = 
		{ 
			"ZenSwissKnife\data\textures\swissknife\swissknife_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100; // Vanilla 100
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"ZenSwissKnife\data\textures\swissknife\swissknife.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"ZenSwissKnife\data\textures\swissknife\swissknife.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"ZenSwissKnife\data\textures\swissknife\swissknife.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"ZenSwissKnife\data\textures\swissknife\swissknife.rvmat"
							}
						},
						
						{
							0,
							
							{
								"ZenSwissKnife\data\textures\swissknife\swissknife.rvmat"
							}
						}
					};
				};
			};
		};
		soundImpactType="metal";
		//! SCREWDRIVER
		repairableWithKits[]={4};
		repairCosts[]={5};
		suicideAnim="onehanded";
		RestrainUnlockType=1;
		openItemSpillRange[]={20,40};
		action="GestureMeleeBayonetStab";
		lockSoundSet="wrench_loop_SoundSet";
		compatibleLocks[]={1};
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeSharpLight_1";
				range=1.1;
			};
			class Heavy
			{
				ammo="MeleeSharpHeavy_1";
				range=1.1;
			};
			class Sprint
			{
				ammo="MeleeSharpHeavy_1";
				range=3.3;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class animalSkinning_in
				{
					soundSet="animalSkinning_in_SoundSet";
					id=516;
				};
				class animalSkinning
				{
					soundSet="animalSkinning_SoundSet";
					id=517;
				};
				class animalSkinning_out
				{
					soundSet="animalSkinning_out_SoundSet";
					id=518;
				};
				class mineScrewdriver_SoundSet
				{
					soundSet="mineScrewdriver_SoundSet";
					id=11161;
				};
			};
		};
	};

	//! KNIFE
	class KitchenKnife;
	class ZenSwissKnife_Knife: KitchenKnife
	{
		scope=2;
		//! SHARED
		displayName="$STR_CfgVehicles_ZenSwissKnife0";
		descriptionShort="$STR_CfgVehicles_ZenSwissKnife1";
		model="ZenSwissKnife\data\models\swissknife\swissknife.p3d";
		inventorySlot[]={ "Knife" };
		animClass="Knife";
		rotationFlags=17;
		isMeleeWeapon=1;
		itemSize[]={1,2};
		weight=300;
		fragility=0.0099999998;
		simpleHiddenSelections[]= 
		{
			"can_opener",
			"packed",
			"large_knife",
			"peg",
			"saw",
			"scissors",
			"small_knife"
	    };
		hiddenSelections[] = 
		{
			"texture"
		};
		hiddenSelectionsTextures[] = 
		{ 
			"ZenSwissKnife\data\textures\swissknife\swissknife_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=150; // Vanilla 100
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"ZenSwissKnife\data\textures\swissknife\swissknife.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"ZenSwissKnife\data\textures\swissknife\swissknife.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"ZenSwissKnife\data\textures\swissknife\swissknife.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"ZenSwissKnife\data\textures\swissknife\swissknife.rvmat"
							}
						},
						
						{
							0,
							
							{
								"ZenSwissKnife\data\textures\swissknife\swissknife.rvmat"
							}
						}
					};
				};
			};
		};
		soundImpactType="metal";
		//! KNIFE
		repairableWithKits[]={4};
		repairCosts[]={5};
		itemInfo[]={"Knife"};
		RestrainUnlockType=1;
		suicideAnim="onehanded";
		openItemSpillRange[]={10,20};
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeSharpLight_2";
				range=1.2;
			};
			class Heavy
			{
				ammo="MeleeSharpHeavy_2";
				range=1.2;
			};
			class Sprint
			{
				ammo="MeleeSharpHeavy_2";
				range=3.3;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class ChoppingTree
				{
					soundSet="ChoppingTree_SoundSet";
					id=415;
				};
				class animalSkinning_in
				{
					soundSet="animalSkinning_in_SoundSet";
					id=516;
				};
				class animalSkinning
				{
					soundSet="animalSkinning_SoundSet";
					id=517;
				};
				class animalSkinning_out
				{
					soundSet="animalSkinning_out_SoundSet";
					id=518;
				};
			};
		};
	};

	//! SCISSORS 
	class ZenSwissKnife_Knife;
	class ZenSwissKnife_Scissors: ZenSwissKnife_Knife
	{
		scope = 2;
		repairKitType=2;
		sewingDamage=5; // Health=100 / 20 repairs from pristine
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"ZenSwissKnife\data\textures\swissknife\swissknife.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"ZenSwissKnife\data\textures\swissknife\swissknife.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"ZenSwissKnife\data\textures\swissknife\swissknife.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"ZenSwissKnife\data\textures\swissknife\swissknife.rvmat"
							}
						},
						
						{
							0,
							
							{
								"ZenSwissKnife\data\textures\swissknife\swissknife.rvmat"
							}
						}
					};
				};
			};
		};
	};

	//! HAND SAW 
	class HandSaw;
	class ZenSwissKnife_SmallSaw: HandSaw
	{
		scope=2;
		//! SHARED
		displayName="$STR_CfgVehicles_ZenSwissKnife0";
		descriptionShort="$STR_CfgVehicles_ZenSwissKnife1";
		model="ZenSwissKnife\data\models\swissknife\swissknife.p3d";
		inventorySlot[]={ "Knife" };
		animClass="Knife";
		rotationFlags=17;
		isMeleeWeapon=1;
		itemSize[]={1,2};
		weight=300;
		fragility=0.0099999998;
		simpleHiddenSelections[]= 
		{
			"can_opener",
			"packed",
			"large_knife",
			"peg",
			"saw",
			"scissors",
			"small_knife"
	    };
		hiddenSelections[] = 
		{
			"texture"
		};
		hiddenSelectionsTextures[] = 
		{ 
			"ZenSwissKnife\data\textures\swissknife\swissknife_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100; // Vanilla 100
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"ZenSwissKnife\data\textures\swissknife\swissknife.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"ZenSwissKnife\data\textures\swissknife\swissknife.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"ZenSwissKnife\data\textures\swissknife\swissknife.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"ZenSwissKnife\data\textures\swissknife\swissknife.rvmat"
							}
						},
						
						{
							0,
							
							{
								"ZenSwissKnife\data\textures\swissknife\swissknife.rvmat"
							}
						}
					};
				};
			};
		};
		soundImpactType="metal";
		//! SAW
		repairableWithKits[]={4};
		repairCosts[]={15};
		itemInfo[]=
		{
			"Knife"
		};
		RestrainUnlockType=1;
		dismantle_action_type=64;
		openItemSpillRange[]={10,40};
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeSharpLight_1";
				range=1.2;
			};
			class Heavy
			{
				ammo="MeleeSharpHeavy_1";
				range=1.2;
			};
			class Sprint
			{
				ammo="MeleeSharpHeavy_1";
				range=3.3;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class CutTiesSaw_end
				{
					soundSet="CutTiesSaw_end_SoundSet";
					id=519;
				};
				class CutTiesSaw_loop
				{
					soundSet="CutTiesSaw_loop_SoundSet";
					id=520;
				};
				class drop
				{
					soundset="hacksaw_drop_SoundSet";
					id=898;
				};
				class HackSaw_loop
				{
					soundSet="HackSaw_loop_SoundSet";
					id=1123;
				};
				class HackSaw_end
				{
					soundSet="HackSaw_end_SoundSet";
					id=1124;
				};
			};
		};
	};
};