#include "botpch.h"
#include "../../playerbot.h"
#include "SetCraftAction.h"

#include "../../../ahbot/AhBotConfig.h"
#include "../../ServerFacade.h"
#include "../values/CraftValue.h"
using namespace ai;

map<uint32, SkillLineAbilityEntry const*> SetCraftAction::skillSpells;

bool SetCraftAction::Execute(Event event)
{
    Player* master = GetMaster();

    if (!master)
        return false;

    string link = event.getParam();

    CraftData& data = AI_VALUE(CraftData&, "craft");
    if (link == "reset")
    {
        data.Reset();
        ai->TellMaster("I will not craft anything");
        return true;
    }

    if (link == "?")
    {
        TellCraft();
        return true;
    }

    ItemIds itemIds = chat->parseItems(link);
    if (itemIds.empty())
    {
        ai->TellMaster("Usage: 'craft [itemId]' or 'craft reset'");
        return false;
    }

    uint32 itemId = *itemIds.begin();
    ItemPrototype const* proto = sObjectMgr.GetItemPrototype(itemId);
    if (!proto)
        return false;

    if (skillSpells.empty())
    {
        for (uint32 j = 0; j < sSkillLineAbilityStore.GetNumRows(); ++j)
        {
            SkillLineAbilityEntry const* skillLine = sSkillLineAbilityStore.LookupEntry(j);
            if (skillLine)
                skillSpells[skillLine->spellId] = skillLine;
        }
    }

    data.required.clear();
    data.obtained.clear();

    for (PlayerSpellMap::iterator itr = bot->GetSpellMap().begin(); itr != bot->GetSpellMap().end(); ++itr) {
        const uint32 spellId = itr->first;

        if (itr->second.state == PLAYERSPELL_REMOVED || itr->second.disabled || IsPassiveSpell(spellId))
            continue;

        const SpellEntry* const pSpellInfo = sServerFacade.LookupSpellInfo(spellId);
        if (!pSpellInfo)
            continue;

        SkillLineAbilityEntry const* skillLine = skillSpells[spellId];
        if (skillLine)
        {
            for (int i = 0; i < 3; ++i)
            {
                if (pSpellInfo->Effect[i] == SPELL_EFFECT_CREATE_ITEM)
                {
                    if (itemId == pSpellInfo->EffectItemType[i])
                    {
                        for (uint32 x = 0; x < MAX_SPELL_REAGENTS; ++x)
                        {
                            if (pSpellInfo->Reagent[x] <= 0)
                                { continue; }

                            uint32 itemid = pSpellInfo->Reagent[x];
                            uint32 reagentsRequired = pSpellInfo->ReagentCount[x];
                            if (itemid)
                            {
                                data.required[itemid] = reagentsRequired;
                                data.obtained[itemid] = 0;
                            }
                        }
                    }
                }
            }
        }
    }

    if (data.required.empty())
    {
        ai->TellMaster("I cannot craft this");
        return false;
    }

    data.itemId = itemId;

    TellCraft();
    return true;
}

void SetCraftAction::TellCraft()
{
    CraftData& data = AI_VALUE(CraftData&, "craft");
    if (data.IsEmpty())
    {
        ai->TellMaster("I will not craft anything");
        return;
    }

    ItemPrototype const* proto = sObjectMgr.GetItemPrototype(data.itemId);
    if (!proto)
        return;

    ostringstream out;
    out << "I will craft " << chat->formatItem(proto) << " using reagents: ";
    bool first = true;
    for (map<uint32, int>::iterator i = data.required.begin(); i != data.required.end(); ++i)
    {
        uint32 item = i->first;
        int required = i->second;
        ItemPrototype const* reagent = sObjectMgr.GetItemPrototype(item);
        if (reagent)
        {
            if (first) { first = false; } else out << ", ";
            out << chat->formatItem(reagent, required);
            uint32 given = data.obtained[item];
            if (given)
            {
                out << "|cffffff00(x" << given << " given)|r ";
            }
        }
    }

    out << " (craft fee: " << chat->formatMoney(GetCraftFee(data)) << ")";
    ai->TellMaster(out.str());
}

uint32 SetCraftAction::GetCraftFee(CraftData& data)
{
    if (data.IsEmpty())
        return 0;

    ItemPrototype const* proto = sObjectMgr.GetItemPrototype(data.itemId);
    if (!proto)
        return 0;

    uint32 level = max(proto->ItemLevel, proto->RequiredLevel);
    return sAhBotConfig.defaultMinPrice * level * level / 40;
}
