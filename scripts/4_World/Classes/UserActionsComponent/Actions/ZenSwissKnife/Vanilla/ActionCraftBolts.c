modded class ActionCraftBolts
{
    override void InitCuttingTypes()
	{
        super.InitCuttingTypes();

        if (CUTTING_TYPES.Find("ZenSwissKnife_Knife") >= 0)
            return;

		CUTTING_TYPES.Insert("ZenSwissKnife_Knife");
	}
}