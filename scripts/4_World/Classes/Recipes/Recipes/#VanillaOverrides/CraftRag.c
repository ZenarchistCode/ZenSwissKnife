modded class CraftRag	
{	
    override bool CheckRecipe(ItemBase item1, ItemBase item2, PlayerBase player)
	{
        if (item1 && item1.IsInherited(ZenSwissKnife_Scissors))
            return false;

        return super.CheckRecipe(item1, item2, player);
	}
}
