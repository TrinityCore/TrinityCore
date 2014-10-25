#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "WhoAction.h"
#include "../../AiFactory.h"
#include "../ItemVisitors.h"
#include "../../../ahbot/AhBot.h"
#include "../../RandomPlayerbotMgr.h"

using namespace ai;

map<uint32, string> WhoAction::skills;

#ifndef WIN32
inline int strcmpi(const char* s1, const char* s2)
{
    for (; *s1 && *s2 && (toupper(*s1) == toupper(*s2)); ++s1, ++s2);
    return *s1 - *s2;
}
#endif

bool WhoAction::Execute(Event event)
{
    Player* owner = event.getOwner();
    if (!owner)
        return false;

    string tell = "";
    string text = event.getParam();
    if (!text.empty())
    {
        if (!sRandomPlayerbotMgr.IsRandomBot(bot))
            return false;

        tell = QuerySkill(text);
        if (tell.empty())
        {
            tell = QueryTrade(text);
        }
    }
    else
    {
        tell = QuerySpec(text);
    }

    if (tell.empty())
        return false;

    // ignore random bot chat filter
	bot->Whisper(tell, LANG_UNIVERSAL, owner);
    return true;
}


string WhoAction::QueryTrade(string text)
{
    ostringstream out;

    list<Item*> items = InventoryAction::parseItems(text);
    for (list<Item*>::iterator i = items.begin(); i != items.end(); ++i)
    {
        Item* sell = *i;
        int32 sellPrice = auctionbot.GetSellPrice(sell->GetTemplate()) * sRandomPlayerbotMgr.GetSellMultiplier(bot) * sell->GetCount();
        if (!sellPrice)
            continue;

        out << "Selling " << chat->formatItem(sell->GetTemplate(), sell->GetCount()) << " for " << chat->formatMoney(sellPrice);
        return out.str();
    }

    return "";
}

string WhoAction::QuerySkill(string text)
{
    ostringstream out;
    InitSkills();

    for (map<uint32, string>::iterator i = skills.begin(); i != skills.end(); ++i)
    {
        string name = i->second;
        uint16 skill = i->first;
        if (!strcmpi(text.c_str(), name.c_str()) && bot->HasSkill(skill))
        {
            string skillName = i->second;
            uint32 spellId = AI_VALUE2(uint32, "spell id", skillName);
            uint16 value = bot->GetSkillValue(skill);
            uint16 maxSkill = bot->GetMaxSkillValue(skill);
            ObjectGuid guid = bot->GetGUID();
            string data = "0";
            out << "|cFFFFFF00|Htrade:" << spellId << ":" << value << ":" << maxSkill << ":"
                    << std::hex << std::uppercase << guid.GetRawValue()
                    << std::nouppercase << std::dec << ":" << data
                    << "|h[" << skills[skill] << "]|h|r"
                    << " |h|cff00ff00" << value << "|h|cffffffff/"
                    << "|h|cff00ff00" << maxSkill << "|h|cffffffff ";
        }
    }

    return out.str();
}

string WhoAction::QuerySpec(string text)
{
    ostringstream out;

    int spec = AiFactory::GetPlayerSpecTab(bot);
    out << "|h|cffffffff" << chat->formatClass(bot, spec);
    out << " (|h|cff00ff00" << (uint32)bot->getLevel() << "|h|cffffffff lvl), ";
    out << "|h|cff00ff00" << ai->GetEquipGearScore(bot, false, false) << "|h|cffffffff GS (";

    ItemCountByQuality visitor;
    IterateItems(&visitor, ITERATE_ITEMS_IN_EQUIP);

    bool needSlash = false;
    if (visitor.count[ITEM_QUALITY_EPIC])
    {
        out << "|h|cffff00ff" << visitor.count[ITEM_QUALITY_EPIC] << "|h|cffffffff";
        needSlash = true;
    }

    if (visitor.count[ITEM_QUALITY_RARE])
    {
        if (needSlash) out << "/";
        out << "|h|cff8080ff" << visitor.count[ITEM_QUALITY_RARE] << "|h|cffffffff";
        needSlash = true;
    }

    if (visitor.count[ITEM_QUALITY_UNCOMMON])
    {
        if (needSlash) out << "/";
        out << "|h|cff00ff00" << visitor.count[ITEM_QUALITY_UNCOMMON] << "|h|cffffffff";
        needSlash = true;
    }

    out << ")";

    return out.str();
}


void WhoAction::InitSkills()
{
    if (!skills.empty())
        return;

    skills[SKILL_ALCHEMY] = "Alchemy";
    skills[SKILL_ENCHANTING] = "Enchanting";
    skills[SKILL_SKINNING] = "Skinning";
    skills[SKILL_JEWELCRAFTING] = "Jewelcrafting";
    skills[SKILL_INSCRIPTION] = "Inscription";
    skills[SKILL_TAILORING] = "Tailoring";
    skills[SKILL_LEATHERWORKING] = "Leatherworking";
    skills[SKILL_ENGINEERING] = "Engineering";
    skills[SKILL_HERBALISM] = "Herbalism";
    skills[SKILL_MINING] = "Mining";
    skills[SKILL_BLACKSMITHING] = "Blacksmithing";
    skills[SKILL_COOKING] = "Cooking";
    skills[SKILL_FIRST_AID] = "First Aid";
    skills[SKILL_FISHING] = "Fishing";
}
