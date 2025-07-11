class ZenSwissKnife_CanOpener extends CanOpener
{
	protected float m_ZenBaseHealth;
	protected float m_ZenScrewdriverHealth;
	protected float m_ZenKnifeHealth;
	protected float m_ZenSawHealth;
	protected float m_ZenLockpickHealth;
	protected float m_ZenScissorsHealth;

	void ZenSwissKnife_CanOpener()
	{
		ZenSwissKnife.ShowToolType(this, "can_opener");
	}

	override bool NameOverride(out string output)
	{
		output = GetGame().ConfigGetTextOut("CfgVehicles " + GetType() + " displayName") + " (#STR_CfgVehicles_CanOpener0)";
		return true;
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionZenSwissKnifeConvert_BaseTool);
	}

	// If tool is ruined, set it back to packed tool state and make this tool no longer usable
	override void EEHealthLevelChanged(int oldLevel, int newLevel, string zone)
	{
		super.EEHealthLevelChanged(oldLevel, newLevel, zone);

		if (GetGame().IsDedicatedServer())
		{
			if (newLevel == GameConstants.STATE_RUINED)
				ZenSwissKnife.ConvertKnife(this);
			else
			{
				UpdateSwissToolTexture();
				SetSynchDirty();
			}
		}
	}
	
	void GetSwissToolHealthOut(out float base, out float canopener, out float screwdriver, out float knife, out float saw, out float lockpick, out float sewing)
	{
		if (GetGame().IsClient())
			return;
		
		base				= m_ZenBaseHealth;
		canopener			= GetHealth01();
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
		
		SetHealth01("","", canopener);

		m_ZenBaseHealth			= base;
		m_ZenScrewdriverHealth	= screwdriver;
		m_ZenKnifeHealth		= knife;
		m_ZenSawHealth			= saw;
		m_ZenLockpickHealth		= lockpick;
		m_ZenScissorsHealth		= sewing;

		UpdateSwissToolTexture();
		SetSynchDirty();

		//ZenSwissKnife.DebugMessage("base=" + base + " canopener=" + canopener + " screwdriver=" + screwdriver + " knife=" + knife + " lockpick=" + lockpick + " sewing=" + sewing);
	}

	float GetSwissToolHealth(string toolType)
	{
		switch (toolType)
		{
			case "ZenSwissKnife_CanOpener":		return GetHealth01();
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
		
		ctx.Write(m_ZenBaseHealth);
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

		if (!ctx.Read(m_ZenBaseHealth))
			m_ZenBaseHealth = 1;

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

		UpdateSwissToolTexture();
		return true;
	}

	void UpdateSwissToolTexture()
	{
		ZenSwissKnife.UpdateSwissToolTexture(this);
	}

	#ifdef MAPLINK
	override void OnUApiSave(UApiEntityStore data)
	{
		super.OnUApiSave(data);
		
		data.Write("m_ZenBaseHealth", m_ZenBaseHealth);
		data.Write("m_ZenCanOpenerHealth", GetHealth01());
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

		SetHealth01("", "", data.GetFloat("m_ZenCanOpenerHealth"));
		m_ZenBaseHealth			= data.GetFloat("m_ZenBaseHealth");
		m_ZenScrewdriverHealth	= data.GetFloat("m_ZenScrewdriverHealth");
		m_ZenKnifeHealth		= data.GetFloat("m_ZenKnifeHealth");
		m_ZenSawHealth			= data.GetFloat("m_ZenSawHealth");
		m_ZenLockpickHealth		= data.GetFloat("m_ZenLockpickHealth");
		m_ZenScissorsHealth		= data.GetFloat("m_ZenScissorsHealth");
		UpdateSwissToolTexture();

		Print("[ZenSwissKnife::MapLink] Loaded knife data.");
	}
	#endif
}