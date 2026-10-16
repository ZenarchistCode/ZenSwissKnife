modded class ActionConstructor
{
    override void RegisterActions(TTypenameArray actions)
    {
        super.RegisterActions(actions);

        //! SWISS KNIFE
        actions.Insert(ActionZenSwissKnifeConvert_BaseTool);
        actions.Insert(ActionZenSwissKnifeConvert_Knife);
        actions.Insert(ActionZenSwissKnifeConvert_CanOpener);
        actions.Insert(ActionZenSwissKnifeConvert_Screwdriver);
        actions.Insert(ActionZenSwissKnifeConvert_SmallSaw);
        actions.Insert(ActionZenSwissKnifeConvert_Lockpick);
        actions.Insert(ActionZenSwissKnifeConvert_Scissors);
    }
}