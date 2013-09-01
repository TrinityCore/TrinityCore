#include "HookMgr.h"
#include "Includes.h"

// misc
void HookMgr::OnLootItem(Player* player, Item* item, uint32 count, uint64 guid)
{
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        (*it)->OnLootItem(player, item, count, guid);
}
void HookMgr::OnFirstLogin(Player* player)
{
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        (*it)->OnFirstLogin(player);
}
void HookMgr::OnEquip(Player* player, Item* item, uint8 bag, uint8 slot)
{
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        (*it)->OnEquip(player, item, bag, slot);
}
void HookMgr::OnRepop(Player* player)
{
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        (*it)->OnRepop(player);
}
void HookMgr::OnResurrect(Player* player)
{
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        (*it)->OnResurrect(player);
}
InventoryResult HookMgr::OnCanUseItem(const Player* player, uint32 itemEntry)
{
    Player* player2 = const_cast<Player*>(player);
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
    {
        InventoryResult value = (*it)->OnCanUseItem(player2, itemEntry);
        if (value != EQUIP_ERR_OK)
            return value;
    }
    return EQUIP_ERR_OK;
}
void HookMgr::HandleGossipSelectOption(Player* player, uint64 guid, uint32 sender, uint32 action, std::string code, uint32 menuId)
{
    if (!player || !player->IsInWorld() || player->PlayerTalkClass->GetGossipMenu().GetMenuId() != menuId)
        return;
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        (*it)->HandleGossipSelectOption(player, guid, sender, action, code, menuId);
}
bool HookMgr::OnChat(Player* player, uint32 type, uint32 lang, std::string& msg)
{
    bool result = true;
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        if (!(*it)->OnChat(player, type, lang, msg))
            result = false;
    return result;
}
bool HookMgr::OnChat(Player* player, uint32 type, uint32 lang, std::string& msg, Group* group)
{
    bool result = true;
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        if (!(*it)->OnChat(player, type, lang, msg, group))
            result = false;
    return result;
}
bool HookMgr::OnChat(Player* player, uint32 type, uint32 lang, std::string& msg, Guild* guild)
{
    bool result = true;
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        if (!(*it)->OnChat(player, type, lang, msg, guild))
            result = false;
    return result;
}
bool HookMgr::OnChat(Player* player, uint32 type, uint32 lang, std::string& msg, Channel* channel)
{
    bool result = true;
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        if (!(*it)->OnChat(player, type, lang, msg, channel))
            result = false;
    return result;
}
void HookMgr::OnEngineRestart()
{
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        (*it)->OnEngineRestart();
}
// item
bool HookMgr::OnDummyEffect(Unit* caster, uint32 spellId, SpellEffIndex effIndex, Item* target)
{
    bool result = false;
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        if ((*it)->OnDummyEffect(caster, spellId, effIndex, target))
            result = true;
    return result;
}
bool HookMgr::OnQuestAccept(Player* player, Item* item, Quest const* quest)
{
    bool result = false;
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        if ((*it)->OnQuestAccept(player, item, quest))
            result = true;
    return result;
}
bool HookMgr::OnUse(Player* player, Item* item, SpellCastTargets const& targets)
{
    bool result = false;
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        if ((*it)->OnUse(player, item, targets))
            result = true;
    return result;
}
bool HookMgr::OnExpire(Player* player, ItemTemplate const* proto)
{
    bool result = false;
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        if ((*it)->OnExpire(player, proto))
            result = true;
    return result;
}
// creature
bool HookMgr::OnDummyEffect(Unit* caster, uint32 spellId, SpellEffIndex effIndex, Creature* target)
{
    bool result = false;
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        if ((*it)->OnDummyEffect(caster, spellId, effIndex, target))
            result = true;
    return result;
}
bool HookMgr::OnGossipHello(Player* player, Creature* creature)
{
    bool result = false;
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        if ((*it)->OnGossipHello(player, creature))
            result = true;
    return result;
}
bool HookMgr::OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
{
    bool result = false;
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        if ((*it)->OnGossipSelect(player, creature, sender, action))
            result = true;
    return result;
}
bool HookMgr::OnGossipSelectCode(Player* player, Creature* creature, uint32 sender, uint32 action, const char* code)
{
    bool result = false;
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        if ((*it)->OnGossipSelectCode(player, creature, sender, action, code))
            result = true;
    return result;
}
bool HookMgr::OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
{
    bool result = false;
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        if ((*it)->OnQuestAccept(player, creature, quest))
            result = true;
    return result;
}
bool HookMgr::OnQuestSelect(Player* player, Creature* creature, Quest const* quest)
{
    bool result = false;
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        if ((*it)->OnQuestSelect(player, creature, quest))
            result = true;
    return result;
}
bool HookMgr::OnQuestComplete(Player* player, Creature* creature, Quest const* quest)
{
    bool result = false;
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        if ((*it)->OnQuestComplete(player, creature, quest))
            result = true;
    return result;
}
bool HookMgr::OnQuestReward(Player* player, Creature* creature, Quest const* quest, uint32 opt)
{
    bool result = false;
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        if ((*it)->OnQuestReward(player, creature, quest, opt))
            result = true;
    return result;
}
uint32 HookMgr::GetDialogStatus(Player* player, Creature* creature)
{
    uint32 result = 0;
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        result = (*it)->GetDialogStatus(player, creature);
    return result;
}
// gameobject
bool HookMgr::OnDummyEffect(Unit* caster, uint32 spellId, SpellEffIndex effIndex, GameObject* target)
{
    bool result = false;
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        if ((*it)->OnDummyEffect(caster, spellId, effIndex, target))
            result = true;
    return result;
}
bool HookMgr::OnGossipHello(Player* player, GameObject* go)
{
    bool result = false;
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        if ((*it)->OnGossipHello(player, go))
            result = true;
    return result;
}
bool HookMgr::OnGossipSelect(Player* player, GameObject* go, uint32 sender, uint32 action)
{
    bool result = false;
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        if ((*it)->OnGossipSelect(player, go, sender, action))
            result = true;
    return result;
}
bool HookMgr::OnGossipSelectCode(Player* player, GameObject* go, uint32 sender, uint32 action, const char* code)
{
    bool result = false;
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        if ((*it)->OnGossipSelectCode(player, go, sender, action, code))
            result = true;
    return result;
}
bool HookMgr::OnQuestAccept(Player* player, GameObject* go, Quest const* quest)
{
    bool result = false;
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        if ((*it)->OnQuestAccept(player, go, quest))
            result = true;
    return result;
}
bool HookMgr::OnQuestReward(Player* player, GameObject* go, Quest const* quest, uint32 opt)
{
    bool result = false;
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        if ((*it)->OnQuestReward(player, go, quest, opt))
            result = true;
    return result;
}
uint32 HookMgr::GetDialogStatus(Player* player, GameObject* go)
{
    bool result = 0;
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        result = (*it)->GetDialogStatus(player, go);
    return result;
}
void HookMgr::OnDestroyed(GameObject* go, Player* player)
{
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        (*it)->OnDestroyed(go, player);
}
void HookMgr::OnDamaged(GameObject* go, Player* player)
{
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        (*it)->OnDamaged(go, player);
}
void HookMgr::OnLootStateChanged(GameObject* go, uint32 state, Unit* unit)
{
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        (*it)->OnLootStateChanged(go, state, unit);
}
void HookMgr::OnGameObjectStateChanged(GameObject* go, uint32 state)
{
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        (*it)->OnGameObjectStateChanged(go, state);
}
// areatrigger
bool HookMgr::OnTrigger(Player* player, AreaTriggerEntry const* trigger)
{
    bool result = false;
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        if ((*it)->OnTrigger(player, trigger))
            result = true;
    return result;
}
// weather
void HookMgr::OnChange(Weather* weather, WeatherState state, float grade)
{
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        (*it)->OnChange(weather, state, grade);
}
// condition
bool HookMgr::OnConditionCheck(Condition* condition, ConditionSourceInfo& sourceInfo)
{
    bool result = true;
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        if (!(*it)->OnConditionCheck(condition, sourceInfo))
            result = false;
    return result;
}
// transport
void HookMgr::OnAddPassenger(Transport* transport, Player* player)
{
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        (*it)->OnAddPassenger(transport, player);
}
void HookMgr::OnAddCreaturePassenger(Transport* transport, Creature* creature)
{
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        (*it)->OnAddCreaturePassenger(transport, creature);
}
void HookMgr::OnRemovePassenger(Transport* transport, Player* player)
{
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        (*it)->OnRemovePassenger(transport, player);
}
void HookMgr::OnRelocate(Transport* transport, uint32 waypointId, uint32 mapId, float x, float y, float z)
{
    for (HookPointerSet::const_iterator it = hookPointers.begin(); it != hookPointers.end(); ++it)
        (*it)->OnRelocate(transport, waypointId, mapId, x, y, z);
}
