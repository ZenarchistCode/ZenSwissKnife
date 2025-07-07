// Base class - no tool selected
class ZenSwissKnife extends ToolBase
{
	static const bool SWISS_KNIFE_DEBUG = false; // Only turn on when debugging

	static const float DURATION_NERF = 2; // Actions take 2x longer with Swiss tool
	static const int TOOL_COUNT = 6;

	static const string RUINED_TEXTURE			= "ZenSwissKnife/data/textures/swissknife/swissknife_destruct_co.paa";
	static const string DAMAGED_TEXTURE			= "ZenSwissKnife/data/textures/swissknife/swissknife_damage_co.paa";
	static const string DAMAGED_BASE_TEXTURE	= "ZenSwissKnife/data/textures/swissknife/swissknife_damage_base_co.paa";
	static const string PRISTINE_TEXTURE		= "ZenSwissKnife/data/textures/swissknife/swissknife_co.paa";

	protected float m_ZenCanOpenerHealth	= 1;
	protected float m_ZenScrewdriverHealth	= 1;
	protected float m_ZenKnifeHealth		= 1;
	protected float m_ZenSawHealth			= 1;
	protected float m_ZenLockpickHealth		= 1;
	protected float m_ZenScissorsHealth		= 1;

	void ZenSwissKnife()
	{
		ShowToolType(this, "packed");
		RegisterSwissNetSync();
	}

	// Called when Central Economy engine spawns this item into the world as loot
	override void EEOnCECreate()
	{
		super.EEOnCECreate();

		// This makes it so you don't gotta set cfgspawnabletypes.xml to spawn Pristine.
		// This item handles its damage textures internally so we need the base object to always spawn Pristine.
		SetHealth(GetMaxHealth());
	}

	protected void RegisterSwissNetSync()
	{
		RegisterNetSyncVariableFloat("m_ZenCanOpenerHealth");
		RegisterNetSyncVariableFloat("m_ZenScrewdriverHealth");
		RegisterNetSyncVariableFloat("m_ZenKnifeHealth");
		RegisterNetSyncVariableFloat("m_ZenSawHealth");
		RegisterNetSyncVariableFloat("m_ZenLockpickHealth");
		RegisterNetSyncVariableFloat("m_ZenScissorsHealth");
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionZenSwissKnifeConvert_Knife);
		AddAction(ActionZenSwissKnifeConvert_Screwdriver);
		AddAction(ActionZenSwissKnifeConvert_SmallSaw);
		AddAction(ActionZenSwissKnifeConvert_CanOpener);
		AddAction(ActionZenSwissKnifeConvert_Lockpick);
		AddAction(ActionZenSwissKnifeConvert_Scissors);
	}

	override void EEHealthLevelChanged(int oldLevel, int newLevel, string zone)
	{
		super.EEHealthLevelChanged(oldLevel, newLevel, zone);

		if (GetGame().IsDedicatedServer())
		{
			UpdateSwissToolTexture(this, true);
			SetSynchDirty();
		}
	}

	void GetSwissToolHealthOut(out float base, out float canopener, out float screwdriver, out float knife, out float saw, out float lockpick, out float sewing)
	{
		if (GetGame().IsClient())
			return;
		
		base				= GetHealth01("","");
		canopener			= m_ZenCanOpenerHealth;
		screwdriver			= m_ZenScrewdriverHealth;
		knife				= m_ZenKnifeHealth;
		saw					= m_ZenSawHealth;
		lockpick			= m_ZenLockpickHealth;
		sewing				= m_ZenScissorsHealth;
	}

	void SetSwissToolHealthConvert(float base, float canopener, float screwdriver, float knife, float saw, float lockpick, float sewing)
	{
		if (GetGame().IsClient())
			return;
		
		m_ZenCanOpenerHealth	= canopener;
		m_ZenScrewdriverHealth	= screwdriver;
		m_ZenKnifeHealth		= knife;
		m_ZenSawHealth			= saw;
		m_ZenLockpickHealth		= lockpick;
		m_ZenScissorsHealth		= sewing;

		// Set base tool health to average of all tools
		SetHealth01("", "", Math.Min(GetToolHealth01(), base));

		UpdateSwissToolTexture(this, true);
		SetSynchDirty();
	}

	// Average of all tools
	float GetToolHealth01()
	{
		return (m_ZenCanOpenerHealth + m_ZenScrewdriverHealth + m_ZenKnifeHealth + m_ZenSawHealth + m_ZenLockpickHealth + m_ZenScissorsHealth) / TOOL_COUNT;
	}

	float GetSwissToolHealth(string toolType)
	{
		switch (toolType)
		{
			case "ZenSwissKnife_CanOpener":		return m_ZenCanOpenerHealth;
			case "ZenSwissKnife_Screwdriver":	return m_ZenScrewdriverHealth;
			case "ZenSwissKnife_Knife":			return m_ZenKnifeHealth;
			case "ZenSwissKnife_SmallSaw":		return m_ZenSawHealth;
			case "ZenSwissKnife_Lockpick":		return m_ZenLockpickHealth;
			case "ZenSwissKnife_Scissors":		return m_ZenScissorsHealth;
		}

		return -1;
	}

	//! SAVE/LOAD TOOL HEALTH
	override void OnStoreSave(ParamsWriteContext ctx)
	{
		super.OnStoreSave(ctx);
		
		ctx.Write(m_ZenCanOpenerHealth);
		ctx.Write(m_ZenScrewdriverHealth);
		ctx.Write(m_ZenKnifeHealth);
		ctx.Write(m_ZenSawHealth);
		ctx.Write(m_ZenLockpickHealth);
		ctx.Write(m_ZenScissorsHealth);
	}

	override bool OnStoreLoad(ParamsReadContext ctx, int version)
	{   
		if (!super.OnStoreLoad(ctx, version))
			return false;

		if (!ctx.Read(m_ZenCanOpenerHealth))
			m_ZenCanOpenerHealth = 1;

		if (!ctx.Read(m_ZenScrewdriverHealth))
			m_ZenScrewdriverHealth = 1;

		if (!ctx.Read(m_ZenKnifeHealth))
			m_ZenKnifeHealth = 1;

		if (!ctx.Read(m_ZenSawHealth))
			m_ZenSawHealth = 1;

		if (!ctx.Read(m_ZenLockpickHealth))
			m_ZenLockpickHealth = 1;

		if (!ctx.Read(m_ZenScissorsHealth))
			m_ZenScissorsHealth = 1;

		UpdateSwissToolTexture(this, true);
		return true;
	}

	static void UpdateSwissToolTexture(EntityAI knife, bool isBase = false)
	{
		if (knife.IsRuined())
		{
			knife.SetObjectTexture(0, RUINED_TEXTURE);
		} else
		if (knife.GetHealth01() <= GameConstants.DAMAGE_DAMAGED_VALUE)
		{
			if (isBase)
				knife.SetObjectTexture(0, DAMAGED_BASE_TEXTURE);
			else
				knife.SetObjectTexture(0, DAMAGED_TEXTURE);
		} else
		{
			knife.SetObjectTexture(0, PRISTINE_TEXTURE);
		}
	}

	//! SHOW/HIDE TOOL SIMPLE SELECTIONS
	static void ShowToolType(ItemBase item, string selectionName)
    {
        TStringArray selectionNames = new TStringArray;
        item.ConfigGetTextArray("simpleHiddenSelections", selectionNames);

		if (!selectionNames)
			return;

        int selectionId;
		foreach (string name : selectionNames)
		{
			selectionId = selectionNames.Find(name);
			if (name == selectionName)
				item.SetSimpleHiddenSelectionState(selectionId, 1);
			else 
				item.SetSimpleHiddenSelectionState(selectionId, 0);
		}
    }

	//! TEST FOR KNIFE OBJECT IN ACTION DATA 
	static bool IsSwissKnifeUsed(ActionData action_data)
	{
		if (action_data == NULL)
		{
			return false;
		}

		if (action_data.m_MainItem != NULL && action_data.m_MainItem.GetType().Contains("ZenSwissKnife"))
		{
			return true;
		}

		if (action_data.m_Target != NULL)
		{
			Object targetObj = action_data.m_Target.GetObject();
			if (targetObj != NULL && targetObj.GetType().Contains("ZenSwissKnife"))
			{
				return true;
			}
		}

		return false;
	}

	//! CONVERT KNIFE TOOL
	static void ConvertKnife(notnull EntityAI old_item, string new_item = "ZenSwissKnife")
	{
		old_item.GetInventory().ReplaceItemWithNew(InventoryMode.SERVER, new ReplaceZenSwissKnifeLambda(old_item, new_item));
	}

	static void DebugMessage(string msg)
	{
		if (SWISS_KNIFE_DEBUG)
		{
			#ifdef ZENMODPACK
			ZenFunctions.DebugMessage(msg);
			#endif

			Print("[ZenSwissKnife::DEBUG] " + msg);
		}
	}

	#ifdef MAPLINK
	override void OnUApiSave(UApiEntityStore data)
	{
		super.OnUApiSave(data);
		
		data.Write("m_ZenBaseHealth", GetHealth01("",""));
		data.Write("m_ZenCanOpenerHealth", m_ZenCanOpenerHealth);
		data.Write("m_ZenScrewdriverHealth", m_ZenScrewdriverHealth);
		data.Write("m_ZenKnifeHealth", m_ZenKnifeHealth);
		data.Write("m_ZenSawHealth", m_ZenSawHealth);
		data.Write("m_ZenLockpickHealth", m_ZenLockpickHealth);
		data.Write("m_ZenScissorsHealth", m_ZenScissorsHealth);

		Print("[ZenSwissKnife::MapLink] Saved knife data.");
	}
	
	override void OnUApiLoad(UApiEntityStore data)
	{
		super.OnUApiLoad(data);

		SetHealth01("", "", Math.Min(GetToolHealth01(), data.GetFloat("m_ZenBaseHealth")));
		m_ZenCanOpenerHealth	= data.GetFloat("m_ZenCanOpenerHealth");
		m_ZenScrewdriverHealth	= data.GetFloat("m_ZenScrewdriverHealth");
		m_ZenKnifeHealth		= data.GetFloat("m_ZenKnifeHealth");
		m_ZenSawHealth			= data.GetFloat("m_ZenSawHealth");
		m_ZenLockpickHealth		= data.GetFloat("m_ZenLockpickHealth");
		m_ZenScissorsHealth		= data.GetFloat("m_ZenScissorsHealth");
		UpdateSwissToolTexture(this, true);

		Print("[ZenSwissKnife::MapLink] Loaded knife data.");
	}
	#endif
}
