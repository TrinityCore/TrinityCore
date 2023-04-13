////From:https://uiwow.com/thread-4045-1-1.html?_dsign=3e6b26cb
//#pragma execution_character_set("UTF-8")
//
////全副本重置卷轴脚本
//class DD_UnbindScrollItemScript : public ItemScript
//{
//public:
//        DD_UnbindScrollItemScript() : ItemScript("DD_UnbindScrollItemScript"){ }
//
//        bool OnUse(Player* player, Item* item, SpellCastTargets const& /*targets*/) 
//        {
//                for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
//                {
//                        BoundInstancesMap const& binds = sInstanceSaveMgr->PlayerGetBoundInstances(player->GetGUIDLow(), Difficulty(i));
//                        for (BoundInstancesMap::const_iterator itr = binds.begin(); itr != binds.end();)
//                        {
//                                sInstanceSaveMgr->PlayerUnbindInstance(player->GetGUIDLow(), itr->first, Difficulty(i), true, player);
//                        }
//                }
//                return true; 
//        }
//};
//
//void AddDD_UnbindScrollScripts() 
//{
//        new DD_UnbindScrollItemScript();
//}
