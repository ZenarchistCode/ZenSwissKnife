#ifdef MAPLINK
modded class UApiEntityStore
{
	// Swiss knife
	float m_ZenSwissBaseHealth;
	float m_ZenSwissCanOpenerHealth;
	float m_ZenSwissScrewdriverHealth;
	float m_ZenSwissKnifeHealth;
	float m_ZenSwissSawHealth;
	float m_ZenSwissLockpickHealth;
	float m_ZenSwissScissorsHealth;

	override void SaveEntity(notnull EntityAI item, bool recursive = true)
	{
		super.SaveEntity(item, recursive);

		if (item.GetType().Contains("ZenSwissKnife"))
		{
			Print("[ZenModPack::MapLink] Saving swiss knife: " + item.GetType());

			ZenSwissKnife knife1 = ZenSwissKnife.Cast(item);
			if (knife1)
			{
				knife1.GetSwissToolHealthOut(m_ZenSwissBaseHealth, m_ZenSwissCanOpenerHealth, m_ZenSwissScrewdriverHealth, m_ZenSwissKnifeHealth, m_ZenSwissSawHealth, m_ZenSwissLockpickHealth, m_ZenSwissScissorsHealth);
				return;
			}

			ZenSwissKnife_CanOpener knife2 = ZenSwissKnife_CanOpener.Cast(item);
			if (knife2)
			{
				knife2.GetSwissToolHealthOut(m_ZenSwissBaseHealth, m_ZenSwissCanOpenerHealth, m_ZenSwissScrewdriverHealth, m_ZenSwissKnifeHealth, m_ZenSwissSawHealth, m_ZenSwissLockpickHealth, m_ZenSwissScissorsHealth);
				return;
			}

			ZenSwissKnife_Knife knife3 = ZenSwissKnife_Knife.Cast(item);
			if (knife3)
			{
				knife3.GetSwissToolHealthOut(m_ZenSwissBaseHealth, m_ZenSwissCanOpenerHealth, m_ZenSwissScrewdriverHealth, m_ZenSwissKnifeHealth, m_ZenSwissSawHealth, m_ZenSwissLockpickHealth, m_ZenSwissScissorsHealth);
				return;
			}

			ZenSwissKnife_Lockpick knife4 = ZenSwissKnife_Lockpick.Cast(item);
			if (knife4)
			{
				knife4.GetSwissToolHealthOut(m_ZenSwissBaseHealth, m_ZenSwissCanOpenerHealth, m_ZenSwissScrewdriverHealth, m_ZenSwissKnifeHealth, m_ZenSwissSawHealth, m_ZenSwissLockpickHealth, m_ZenSwissScissorsHealth);
				return;
			}

			ZenSwissKnife_Scissors knife5 = ZenSwissKnife_Scissors.Cast(item);
			if (knife5)
			{
				knife5.GetSwissToolHealthOut(m_ZenSwissBaseHealth, m_ZenSwissCanOpenerHealth, m_ZenSwissScrewdriverHealth, m_ZenSwissKnifeHealth, m_ZenSwissSawHealth, m_ZenSwissLockpickHealth, m_ZenSwissScissorsHealth);
				return;
			}

			ZenSwissKnife_Screwdriver knife6 = ZenSwissKnife_Screwdriver.Cast(item);
			if (knife6)
			{
				knife6.GetSwissToolHealthOut(m_ZenSwissBaseHealth, m_ZenSwissCanOpenerHealth, m_ZenSwissScrewdriverHealth, m_ZenSwissKnifeHealth, m_ZenSwissSawHealth, m_ZenSwissLockpickHealth, m_ZenSwissScissorsHealth);
				return;
			}

			ZenSwissKnife_SmallSaw knife7 = ZenSwissKnife_SmallSaw.Cast(item);
			if (knife7)
			{
				knife7.GetSwissToolHealthOut(m_ZenSwissBaseHealth, m_ZenSwissCanOpenerHealth, m_ZenSwissScrewdriverHealth, m_ZenSwissKnifeHealth, m_ZenSwissSawHealth, m_ZenSwissLockpickHealth, m_ZenSwissScissorsHealth);
				return;
			}
		}
	}

	override void LoadEntity(EntityAI item)
	{
		super.LoadEntity(item);

		if (item && item.GetType().Contains("ZenSwissKnife"))
		{
			Print("[ZenModPack::MapLink] Loading swiss knife: " + item.GetType());

			ZenSwissKnife knife1 = ZenSwissKnife.Cast(item);
			if (knife1)
			{
				knife1.SetSwissToolHealthConvert(m_ZenSwissBaseHealth, m_ZenSwissCanOpenerHealth, m_ZenSwissScrewdriverHealth, m_ZenSwissKnifeHealth, m_ZenSwissSawHealth, m_ZenSwissLockpickHealth, m_ZenSwissScissorsHealth);
				return;
			}

			ZenSwissKnife_CanOpener knife2 = ZenSwissKnife_CanOpener.Cast(item);
			if (knife2)
			{
				knife2.SetSwissToolHealthConvert(m_ZenSwissBaseHealth, m_ZenSwissCanOpenerHealth, m_ZenSwissScrewdriverHealth, m_ZenSwissKnifeHealth, m_ZenSwissSawHealth, m_ZenSwissLockpickHealth, m_ZenSwissScissorsHealth);
				return;
			}

			ZenSwissKnife_Knife knife3 = ZenSwissKnife_Knife.Cast(item);
			if (knife3)
			{
				knife3.SetSwissToolHealthConvert(m_ZenSwissBaseHealth, m_ZenSwissCanOpenerHealth, m_ZenSwissScrewdriverHealth, m_ZenSwissKnifeHealth, m_ZenSwissSawHealth, m_ZenSwissLockpickHealth, m_ZenSwissScissorsHealth);
				return;
			}

			ZenSwissKnife_Lockpick knife4 = ZenSwissKnife_Lockpick.Cast(item);
			if (knife4)
			{
				knife4.SetSwissToolHealthConvert(m_ZenSwissBaseHealth, m_ZenSwissCanOpenerHealth, m_ZenSwissScrewdriverHealth, m_ZenSwissKnifeHealth, m_ZenSwissSawHealth, m_ZenSwissLockpickHealth, m_ZenSwissScissorsHealth);
				return;
			}

			ZenSwissKnife_Scissors knife5 = ZenSwissKnife_Scissors.Cast(item);
			if (knife5)
			{
				knife5.SetSwissToolHealthConvert(m_ZenSwissBaseHealth, m_ZenSwissCanOpenerHealth, m_ZenSwissScrewdriverHealth, m_ZenSwissKnifeHealth, m_ZenSwissSawHealth, m_ZenSwissLockpickHealth, m_ZenSwissScissorsHealth);
				return;
			}

			ZenSwissKnife_Screwdriver knife6 = ZenSwissKnife_Screwdriver.Cast(item);
			if (knife6)
			{
				knife6.SetSwissToolHealthConvert(m_ZenSwissBaseHealth, m_ZenSwissCanOpenerHealth, m_ZenSwissScrewdriverHealth, m_ZenSwissKnifeHealth, m_ZenSwissSawHealth, m_ZenSwissLockpickHealth, m_ZenSwissScissorsHealth);
				return;
			}

			ZenSwissKnife_SmallSaw knife7 = ZenSwissKnife_SmallSaw.Cast(item);
			if (knife7)
			{
				knife7.SetSwissToolHealthConvert(m_ZenSwissBaseHealth, m_ZenSwissCanOpenerHealth, m_ZenSwissScrewdriverHealth, m_ZenSwissKnifeHealth, m_ZenSwissSawHealth, m_ZenSwissLockpickHealth, m_ZenSwissScissorsHealth);
				return;
			}
		}
	}
}
#endif