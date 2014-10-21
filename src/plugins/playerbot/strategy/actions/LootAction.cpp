#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "LootAction.h"

#include "../../LootObjectStack.h"
#include "../../PlayerbotAIConfig.h"
#include "../../../ahbot/AhBot.h"
#include "../../RandomPlayerbotMgr.h"
#include "../values/ItemUsageValue.h"
#include "../../GuildTaskMgr.h"

using namespace ai;

bool LootAction::Execute(Event event)
{
    if (!AI_VALUE(bool, "has available loot"))
        return false;

    LootObject const& lootObject = AI_VALUE(LootObjectStack*, "available loot")->GetLoot(sPlayerbotAIConfig.lootDistance);
    context->GetValue<LootObject>("loot target")->Set(lootObject);
    return true;
}

enum ProfessionSpells
{
    ALCHEMY                      = 2259,
    BLACKSMITHING                = 2018,
    COOKING                      = 2550,
    ENCHANTING                   = 7411,
    ENGINEERING                  = 49383,
    FIRST_AID                    = 3273,
    FISHING                      = 7620,
    HERB_GATHERING               = 2366,
    INSCRIPTION                  = 45357,
    JEWELCRAFTING                = 25229,
    MINING                       = 2575,
    SKINNING                     = 8613,
    TAILORING                    = 3908
};

bool OpenLootAction::Execute(Event event)
{
    LootObject lootObject = AI_VALUE(LootObject, "loot target");
    bool result = DoLoot(lootObject);
    if (result)
    {
        AI_VALUE(LootObjectStack*, "available loot")->Remove(lootObject.guid);
        context->GetValue<LootObject>("loot target")->Set(LootObject());
    }
    return result;
}

bool OpenLootAction::DoLoot(LootObject& lootObject)
{
    if (lootObject.IsEmpty())
        return false;

    Creature* creature = ai->GetCreature(lootObject.guid);
    if (creature && bot->GetDistance(creature) > INTERACTION_DISTANCE)
        return false;

    if (creature && creature->HasFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE))
    {
        bot->GetMotionMaster()->Clear();
        WorldPacket* const packet = new WorldPacket(CMSG_LOOT, 8);
        *packet << lootObject.guid;
        bot->GetSession()->QueuePacket(packet);
        return true;
    }

    if (creature)
    {
        SkillType skill = creature->GetCreatureTemplate()->GetRequiredLootSkill();
        if (!CanOpenLock(skill, lootObject.reqSkillValue))
            return false;

        bot->GetMotionMaster()->Clear();
        switch (skill)
        {
        case SKILL_ENGINEERING:
            return bot->HasSkill(SKILL_ENGINEERING) ? ai->CastSpell(ENGINEERING, creature) : false;
        case SKILL_HERBALISM:
            return bot->HasSkill(SKILL_HERBALISM) ? ai->CastSpell(32605, creature) : false;
        case SKILL_MINING:
            return bot->HasSkill(SKILL_MINING) ? ai->CastSpell(32606, creature) : false;
        default:
            return bot->HasSkill(SKILL_SKINNING) ? ai->CastSpell(SKINNING, creature) : false;
        }
    }

    GameObject* go = ai->GetGameObject(lootObject.guid);
    if (go && bot->GetDistance(go) > INTERACTION_DISTANCE)
        return false;

    bot->GetMotionMaster()->Clear();
    if (lootObject.skillId == SKILL_MINING)
        return bot->HasSkill(SKILL_MINING) ? ai->CastSpell(MINING, bot) : false;

    if (lootObject.skillId == SKILL_HERBALISM)
        return bot->HasSkill(SKILL_HERBALISM) ? ai->CastSpell(HERB_GATHERING, bot) : false;

    uint32 spellId = GetOpeningSpell(lootObject);
    if (!spellId)
        return false;

    return ai->CastSpell(spellId, bot);
}

uint32 OpenLootAction::GetOpeningSpell(LootObject& lootObject)
{
    GameObject* go = ai->GetGameObject(lootObject.guid);
    if (go && go->isSpawned())
        return GetOpeningSpell(lootObject, go);

    return 0;
}

uint32 OpenLootAction::GetOpeningSpell(LootObject& lootObject, GameObject* go)
{
    for (PlayerSpellMap::iterator itr = bot->GetSpellMap().begin(); itr != bot->GetSpellMap().end(); ++itr)
    {
        uint32 spellId = itr->first;

        const SpellInfo* pSpellInfo = sSpellMgr->GetSpellInfo(spellId);
        if (!pSpellInfo)
            continue;

        if (itr->second->state == PLAYERSPELL_REMOVED || itr->second->disabled || pSpellInfo->IsPassive())
            continue;

        if (spellId == MINING || spellId == HERB_GATHERING)
            continue;

        if (CanOpenLock(lootObject, pSpellInfo, go))
            return spellId;
    }

    for (uint32 spellId = 0; spellId < sSpellStore.GetNumRows(); spellId++)
    {
        if (spellId == MINING || spellId == HERB_GATHERING)
            continue;

        const SpellInfo* pSpellInfo = sSpellMgr->GetSpellInfo(spellId);
        if (!pSpellInfo)
            continue;

        if (CanOpenLock(lootObject, pSpellInfo, go))
            return spellId;
    }

    return 0; //Spell 3365 = Opening?
}

bool OpenLootAction::CanOpenLock(LootObject& lootObject, const SpellInfo* pSpellInfo, GameObject* go)
{
    for (int effIndex = 0; effIndex <= EFFECT_2; effIndex++)
    {
        if (pSpellInfo->Effects[effIndex].Effect != SPELL_EFFECT_OPEN_LOCK && pSpellInfo->Effects[effIndex].Effect != SPELL_EFFECT_SKINNING)
            return false;

        uint32 lockId = go->GetGOInfo()->GetLockId();
        if (!lockId)
            return false;

        LockEntry const *lockInfo = sLockStore.LookupEntry(lockId);
        if (!lockInfo)
            return false;

        bool reqKey = false;                                    // some locks not have reqs

        for(int j = 0; j < 8; ++j)
        {
            switch(lockInfo->Type[j])
            {
            /*
            case LOCK_KEY_ITEM:
                return true;
            */
            case LOCK_KEY_SKILL:
                {
                    if(uint32(pSpellInfo->Effects[effIndex].MiscValue) != lockInfo->Index[j])
                        continue;

                    uint32 skillId = SkillByLockType(LockType(lockInfo->Index[j]));
                    if (skillId == SKILL_NONE)
                        return true;

                    if (CanOpenLock(skillId, lockInfo->Skill[j]))
                        return true;
                }
            }
        }
    }

    return false;
}

bool OpenLootAction::CanOpenLock(uint32 skillId, uint32 reqSkillValue)
{
    uint32 skillValue = bot->GetSkillValue(skillId);
    return skillValue >= reqSkillValue || !reqSkillValue;
}

bool StoreLootAction::Execute(Event event)
{
    WorldPacket p(event.getPacket()); // (8+1+4+1+1+4+4+4+4+4+1)
    ObjectGuid guid;
    uint8 loot_type;
    uint32 gold = 0;
    uint8 items = 0;

    p.rpos(0);
    p >> guid;      // 8 corpse guid
    p >> loot_type; // 1 loot type

    if (p.size() > 10)
    {
        p >> gold;      // 4 money on corpse
        p >> items;     // 1 number of items on corpse
    }

    if (gold > 0)
    {
        WorldPacket* const packet = new WorldPacket(CMSG_LOOT_MONEY, 0);
        bot->GetSession()->QueuePacket(packet);
    }

    for (uint8 i = 0; i < items; ++i)
    {
        uint32 itemid;
        uint32 itemcount;
        uint8 lootslot_type;
        uint8 itemindex;
        bool grab = false;

        p >> itemindex;
        p >> itemid;
        p >> itemcount;
        p.read_skip<uint32>();  // display id
        p.read_skip<uint32>();  // randomSuffix
        p.read_skip<uint32>();  // randomPropertyId
        p >> lootslot_type;     // 0 = can get, 1 = look only, 2 = master get

        if (lootslot_type != LOOT_SLOT_TYPE_ALLOW_LOOT && lootslot_type != LOOT_SLOT_TYPE_OWNER)
            continue;

        if (loot_type != LOOT_SKINNING && !IsLootAllowed(itemid))
            continue;

        if (sRandomPlayerbotMgr.IsRandomBot(bot))
        {
            ItemTemplate const *proto = sObjectMgr->GetItemTemplate(itemid);
            if (proto)
            {
                uint32 price = itemcount * auctionbot.GetSellPrice(proto) * sRandomPlayerbotMgr.GetSellMultiplier(bot) + gold;
                uint32 lootAmount = sRandomPlayerbotMgr.GetLootAmount(bot);
                if (bot->GetGroup() && price)
                {
                    sRandomPlayerbotMgr.SetLootAmount(bot, lootAmount + price);
                }
                else if (lootAmount)
                {
                    sRandomPlayerbotMgr.SetLootAmount(bot, 0);
                }

                Group* group = bot->GetGroup();
                if (group)
                {
                    for (GroupReference *ref = group->GetFirstMember(); ref; ref = ref->next())
                    {
                        if( ref->GetSource() != bot)
                            sGuildTaskMgr.CheckItemTask(itemid, itemcount, ref->GetSource(), bot);
                    }
                }
            }
        }

        WorldPacket* const packet = new WorldPacket(CMSG_AUTOSTORE_LOOT_ITEM, 1);
        *packet << itemindex;
        bot->GetSession()->QueuePacket(packet);
    }

    AI_VALUE(LootObjectStack*, "available loot")->Remove(guid);

    // release loot
    WorldPacket* const packet = new WorldPacket(CMSG_LOOT_RELEASE, 8);
    *packet << guid;
    bot->GetSession()->QueuePacket(packet);
    return true;
}

bool StoreLootAction::IsLootAllowed(uint32 itemid)
{
    LootStrategy lootStrategy = AI_VALUE(LootStrategy, "loot strategy");

    if (lootStrategy == LOOTSTRATEGY_ALL)
        return true;

    set<uint32>& lootItems = AI_VALUE(set<uint32>&, "always loot list");
    if (lootItems.find(itemid) != lootItems.end())
        return true;

    ItemTemplate const *proto = sObjectMgr->GetItemTemplate(itemid);
    if (!proto)
        return false;

    uint32 max = proto->MaxCount;
    if (max > 0 && bot->HasItemCount(itemid, max, true))
        return false;

    if (proto->StartQuest ||
        proto->Bonding == BIND_QUEST_ITEM ||
        proto->Bonding == BIND_QUEST_ITEM1 ||
        proto->Class == ITEM_CLASS_QUEST)
        return true;

    if (lootStrategy == LOOTSTRATEGY_QUEST)
        return false;

    ostringstream out; out << itemid;
    ItemUsage usage = AI_VALUE2(ItemUsage, "item usage", out.str());
    if (usage == ITEM_USAGE_SKILL || usage == ITEM_USAGE_USE || usage == ITEM_USAGE_GUILD_TASK)
        return true;

    if (lootStrategy == LOOTSTRATEGY_SKILL)
        return false;

    if (proto->Class == ITEM_CLASS_MONEY || proto->Quality == ITEM_QUALITY_POOR)
        return true;

    if (lootStrategy == LOOTSTRATEGY_GRAY)
        return true;

    if (proto->Bonding == BIND_WHEN_PICKED_UP)
        return false;

    return true;
}
