#include "../pchdef.h"
#include "playerbot.h"
#include "ChatHelper.h"

using namespace ai;
using namespace std;

map<string, uint32> ChatHelper::consumableSubClasses;
map<string, uint32> ChatHelper::tradeSubClasses;
map<string, uint32> ChatHelper::itemQualities;
map<string, uint32> ChatHelper::slots;
map<string, ChatMsg> ChatHelper::chats;
map<uint8, string> ChatHelper::classes;
map<uint8, string> ChatHelper::races;
map<uint8, map<uint8, string> > ChatHelper::specs;

template<class T>
static bool substrContainsInMap(string searchTerm, map<string, T> searchIn)
{
    for (typename map<string, T>::iterator i = searchIn.begin(); i != searchIn.end(); ++i)
    {
		string term = i->first;
		if (term.size() > 1 && searchTerm.find(term) != string::npos)
            return true;
    }

    return false;
}

ChatHelper::ChatHelper(PlayerbotAI* ai) : PlayerbotAIAware(ai)
{
    itemQualities["poor"] = ITEM_QUALITY_POOR;
    itemQualities["gray"] = ITEM_QUALITY_POOR;
    itemQualities["normal"] = ITEM_QUALITY_NORMAL;
    itemQualities["white"] = ITEM_QUALITY_NORMAL;
    itemQualities["uncommon"] = ITEM_QUALITY_UNCOMMON;
    itemQualities["green"] = ITEM_QUALITY_UNCOMMON;
    itemQualities["rare"] = ITEM_QUALITY_RARE;
    itemQualities["blue"] = ITEM_QUALITY_RARE;
    itemQualities["epic"] = ITEM_QUALITY_EPIC;
    itemQualities["violet"] = ITEM_QUALITY_EPIC;

    consumableSubClasses["potion"] = ITEM_SUBCLASS_POTION;
    consumableSubClasses["elixir"] = ITEM_SUBCLASS_ELIXIR;
    consumableSubClasses["flask"] = ITEM_SUBCLASS_FLASK;
    consumableSubClasses["scroll"] = ITEM_SUBCLASS_SCROLL;
    consumableSubClasses["food"] = ITEM_SUBCLASS_FOOD;
    consumableSubClasses["bandage"] = ITEM_SUBCLASS_BANDAGE;
    consumableSubClasses["enchant"] = ITEM_SUBCLASS_CONSUMABLE_OTHER;

    tradeSubClasses["cloth"] = ITEM_SUBCLASS_CLOTH;
    tradeSubClasses["leather"] = ITEM_SUBCLASS_LEATHER;
    tradeSubClasses["metal"] = ITEM_SUBCLASS_METAL_STONE;
    tradeSubClasses["stone"] = ITEM_SUBCLASS_METAL_STONE;
    tradeSubClasses["ore"] = ITEM_SUBCLASS_METAL_STONE;
    tradeSubClasses["meat"] = ITEM_SUBCLASS_MEAT;
    tradeSubClasses["herb"] = ITEM_SUBCLASS_HERB;
    tradeSubClasses["elemental"] = ITEM_SUBCLASS_ELEMENTAL;
    tradeSubClasses["disenchants"] = ITEM_SUBCLASS_ENCHANTING;
    tradeSubClasses["enchanting"] = ITEM_SUBCLASS_ENCHANTING;
    tradeSubClasses["gems"] = ITEM_SUBCLASS_JEWELCRAFTING;
    tradeSubClasses["jewels"] = ITEM_SUBCLASS_JEWELCRAFTING;
    tradeSubClasses["jewelcrafting"] = ITEM_SUBCLASS_JEWELCRAFTING;

    slots["head"] = EQUIPMENT_SLOT_HEAD;
    slots["neck"] = EQUIPMENT_SLOT_NECK;
    slots["shoulder"] = EQUIPMENT_SLOT_SHOULDERS;
    slots["shirt"] = EQUIPMENT_SLOT_BODY;
    slots["chest"] = EQUIPMENT_SLOT_CHEST;
    slots["waist"] = EQUIPMENT_SLOT_WAIST;
    slots["legs"] = EQUIPMENT_SLOT_LEGS;
    slots["feet"] = EQUIPMENT_SLOT_FEET;
    slots["wrist"] = EQUIPMENT_SLOT_WRISTS;
    slots["hands"] = EQUIPMENT_SLOT_HANDS;
    slots["finger 1"] = EQUIPMENT_SLOT_FINGER1;
    slots["finger 2"] = EQUIPMENT_SLOT_FINGER2;
    slots["trinket 1"] = EQUIPMENT_SLOT_TRINKET1;
    slots["trinket 2"] = EQUIPMENT_SLOT_TRINKET2;
    slots["back"] = EQUIPMENT_SLOT_BACK;
    slots["main hand"] = EQUIPMENT_SLOT_MAINHAND;
    slots["off hand"] = EQUIPMENT_SLOT_OFFHAND;
    slots["ranged"] = EQUIPMENT_SLOT_RANGED;
    slots["tabard"] = EQUIPMENT_SLOT_TABARD;

    chats["party"] = CHAT_MSG_PARTY;
    chats["p"] = CHAT_MSG_PARTY;
    chats["guild"] = CHAT_MSG_GUILD;
    chats["g"] = CHAT_MSG_GUILD;
    chats["raid"] = CHAT_MSG_RAID;
    chats["r"] = CHAT_MSG_RAID;
    chats["whisper"] = CHAT_MSG_WHISPER;
    chats["w"] = CHAT_MSG_WHISPER;

    classes[CLASS_DRUID] = "druid";
    specs[CLASS_DRUID][0] = "balance";
    specs[CLASS_DRUID][1] = "feral combat";
    specs[CLASS_DRUID][2] = "restoration";

    classes[CLASS_HUNTER] = "hunter";
    specs[CLASS_HUNTER][0] = "beast mastery";
    specs[CLASS_HUNTER][1] = "marksmanship";
    specs[CLASS_HUNTER][2] = "survival";

    classes[CLASS_MAGE] = "mage";
    specs[CLASS_MAGE][0] = "arcane";
    specs[CLASS_MAGE][1] = "fire";
    specs[CLASS_MAGE][2] = "frost";

    classes[CLASS_PALADIN] = "paladin";
    specs[CLASS_PALADIN][0] = "holy";
    specs[CLASS_PALADIN][1] = "protection";
    specs[CLASS_PALADIN][2] = "retribution";

    classes[CLASS_PRIEST] = "priest";
    specs[CLASS_PRIEST][0] = "discipline";
    specs[CLASS_PRIEST][1] = "holy";
    specs[CLASS_PRIEST][2] = "shadow";

    classes[CLASS_ROGUE] = "rogue";
    specs[CLASS_ROGUE][0] = "assasination";
    specs[CLASS_ROGUE][1] = "combat";
    specs[CLASS_ROGUE][2] = "subtlety";

    classes[CLASS_SHAMAN] = "shaman";
    specs[CLASS_SHAMAN][0] = "elemental";
    specs[CLASS_SHAMAN][1] = "enhancement";
    specs[CLASS_SHAMAN][2] = "restoration";

    classes[CLASS_WARLOCK] = "warlock";
    specs[CLASS_WARLOCK][0] = "affliction";
    specs[CLASS_WARLOCK][1] = "demonology";
    specs[CLASS_WARLOCK][2] = "destruction";

    classes[CLASS_WARRIOR] = "warrior";
    specs[CLASS_WARRIOR][0] = "arms";
    specs[CLASS_WARRIOR][1] = "fury";
    specs[CLASS_WARRIOR][2] = "protection";

    races[RACE_BLOODELF] = "Blood Elf";
    races[RACE_DRAENEI] = "Draenei";
    races[RACE_DWARF] = "Dwarf";
    races[RACE_GNOME] = "Gnome";
    races[RACE_HUMAN] = "Human";
    races[RACE_NIGHTELF] = "Night Elf";
    races[RACE_ORC] = "Orc";
    races[RACE_TAUREN] = "Tauren";
    races[RACE_TROLL] = "Troll";
    races[RACE_UNDEAD_PLAYER] = "Undead";
}

string ChatHelper::formatMoney(uint32 copper)
{
    ostringstream out;
	if (!copper)
	{
		out << "0|TInterface\\AddOns\\AtlasLoot\\Images\\bronze:0|t";
		return out.str();
	}

    uint32 gold = uint32(copper / 10000);
    copper -= (gold * 10000);
    uint32 silver = uint32(copper / 100);
    copper -= (silver * 100);
    out << " ";
    if (gold > 0)
        out << gold <<  "|TInterface\\AddOns\\AtlasLoot\\Images\\gold:0|t ";
    if (silver > 0 && gold < 50)
        out << silver <<  "|TInterface\\AddOns\\AtlasLoot\\Images\\silver:0|t ";
	if (copper > 0 && gold < 10)
		out << copper <<  "|TInterface\\AddOns\\AtlasLoot\\Images\\bronze:0|t";

    return out.str();
}

uint32 ChatHelper::parseMoney(string& text)
{
    // if user specified money in ##g##s##c format
    string acum = "";
    uint32 copper = 0;
    for (uint8 i = 0; i < text.length(); i++)
    {
        if (text[i] == 'g')
        {
            copper += (atol(acum.c_str()) * 100 * 100);
            acum = "";
        }
        else if (text[i] == 'c')
        {
            copper += atol(acum.c_str());
            acum = "";
        }
        else if (text[i] == 's')
        {
            copper += (atol(acum.c_str()) * 100);
            acum = "";
        }
        else if (text[i] == ' ')
            break;
        else if (text[i] >= 48 && text[i] <= 57)
            acum += text[i];
        else
        {
            copper = 0;
            break;
        }
    }
    return copper;
}

ItemIds ChatHelper::parseItems(string& text)
{
    ItemIds itemIds;

    uint8 pos = 0;
    while (true)
    {
        int i = text.find("Hitem:", pos);
        if (i == -1)
            break;
        pos = i + 6;
        int endPos = text.find(':', pos);
        if (endPos == -1)
            break;
        string idC = text.substr(pos, endPos - pos);
        uint32 id = atol(idC.c_str());
        pos = endPos;
        if (id)
            itemIds.insert(id);
    }

    return itemIds;
}

string ChatHelper::formatQuest(Quest const* quest)
{
    ostringstream out;
    out << "|cFFFFFF00|Hquest:" << quest->GetQuestId() << ':' << quest->GetQuestLevel() << "|h[" << quest->GetTitle() << "]|h|r";
    return out.str();
}

string ChatHelper::formatGameobject(GameObject* go)
{
    ostringstream out;
    out << "|cFFFFFF00|Hfound:" << go->GetGUID() << ":" << go->GetEntry() << ":" <<  "|h[" << go->GetGOInfo()->name << "]|h|r";
    return out.str();
}

string ChatHelper::formatSpell(SpellInfo const *sInfo)
{
    ostringstream out;
    out << "|cffffffff|Hspell:" << sInfo->Id << "|h[" << sInfo->SpellName[LOCALE_enUS] << "]|h|r";
    return out.str();
}

string ChatHelper::formatItem(ItemTemplate const * proto, int count)
{
    char color[32];
    sprintf(color, "%x", ItemQualityColors[proto->Quality]);

    ostringstream out;
    out << "|c" << color << "|Hitem:" << proto->ItemId
        << ":0:0:0:0:0:0:0" << "|h[" << proto->Name1
        << "]|h|r";

    if (count > 1)
        out << "x" << count;

    return out.str();
}

ChatMsg ChatHelper::parseChat(string& text)
{
    if (chats.find(text) != chats.end())
        return chats[text];

    return CHAT_MSG_SYSTEM;
}

string ChatHelper::formatChat(ChatMsg chat)
{
    switch (chat)
    {
    case CHAT_MSG_GUILD:
        return "guild";
    case CHAT_MSG_PARTY:
        return "party";
    case CHAT_MSG_WHISPER:
        return "whisper";
    case CHAT_MSG_RAID:
        return "raid";
    }

    return "unknown";
}


uint32 ChatHelper::parseSpell(string& text)
{
    PlayerbotChatHandler handler(ai->GetBot());
    return handler.extractSpellId(text);
}

list<ObjectGuid> ChatHelper::parseGameobjects(string& text)
{
    list<ObjectGuid> gos;
    //    Link format
    //    |cFFFFFF00|Hfound:" << guid << ':'  << entry << ':'  <<  "|h[" << gInfo->name << "]|h|r";
    //    |cFFFFFF00|Hfound:9582:1731|h[Copper Vein]|h|r

    uint8 pos = 0;
    while (true)
    {
        // extract GO guid
        int i = text.find("Hfound:", pos);     // base H = 11
        if (i == -1)     // break if error
            break;

        pos = i + 7;     //start of window in text 11 + 7 = 18
        int endPos = text.find(':', pos);     // end of window in text 22
        if (endPos == -1)     //break if error
            break;
        istringstream stream(text.substr(pos, endPos - pos));
        uint64 guid; stream >> guid;

        // extract GO entry
        pos = endPos + 1;
        endPos = text.find(':', pos);     // end of window in text
        if (endPos == -1)     //break if error
            break;

        std::string entryC = text.substr(pos, endPos - pos);     // get string within window i.e entry
        uint32 entry = atol(entryC.c_str());     // convert ascii to float

        ObjectGuid lootCurrent = ObjectGuid(guid);

        if (guid)
            gos.push_back(lootCurrent);
    }

    return gos;
}

string ChatHelper::formatQuestObjective(string name, int available, int required)
{
    ostringstream out;
    out << "|cFFFFFFFF" << name << (available >= required ? "|c0000FF00: " : "|c00FF0000: ")
        << available << "/" << required << "|r";

    return out.str();
}


uint32 ChatHelper::parseItemQuality(string text)
{
    if (itemQualities.find(text) == itemQualities.end())
        return MAX_ITEM_QUALITY;

    return itemQualities[text];
}

bool ChatHelper::parseItemClass(string text, uint32 *itemClass, uint32 *itemSubClass)
{
    if (text == "questitem")
    {
        *itemClass = ITEM_CLASS_QUEST;
        *itemSubClass = ITEM_SUBCLASS_QUEST;
        return true;
    }

    if (consumableSubClasses.find(text) != consumableSubClasses.end())
    {
        *itemClass = ITEM_CLASS_CONSUMABLE;
        *itemSubClass = consumableSubClasses[text];
        return true;
    }

    if (tradeSubClasses.find(text) != tradeSubClasses.end())
    {
        *itemClass = ITEM_CLASS_TRADE_GOODS;
        *itemSubClass = tradeSubClasses[text];
        return true;
    }

    return false;
}

uint32 ChatHelper::parseSlot(string text)
{
    if (slots.find(text) != slots.end())
        return slots[text];

    return EQUIPMENT_SLOT_END;
}

bool ChatHelper::parseable(string text)
{
    return text.find("|H") != string::npos ||
            text == "questitem" ||
            substrContainsInMap<uint32>(text, consumableSubClasses) ||
            substrContainsInMap<uint32>(text, tradeSubClasses) ||
            substrContainsInMap<uint32>(text, itemQualities) ||
            substrContainsInMap<uint32>(text, slots) ||
            substrContainsInMap<ChatMsg>(text, chats) ||
            parseMoney(text) > 0;
}

string ChatHelper::formatClass(Player* player, int spec)
{
    uint8 cls = player->getClass();

    ostringstream out;
    out << specs[cls][spec] << " (";

    int c0 = 0, c1 = 0, c2 = 0;
    PlayerTalentMap& talentMap = player->GetTalentMap(0);
    for (PlayerTalentMap::iterator i = talentMap.begin(); i != talentMap.end(); ++i)
    {
        uint32 spellId = i->first;
        TalentSpellPos const* talentPos = GetTalentSpellPos(spellId);
        if(!talentPos)
            continue;

        TalentEntry const* talentInfo = sTalentStore.LookupEntry(talentPos->talent_id);

        if (!talentInfo)
            continue;

        uint32 const* talentTabIds = GetTalentTabPages(player->getClass());
        if (talentInfo->TalentTab == talentTabIds[0]) c0++;
        if (talentInfo->TalentTab == talentTabIds[1]) c1++;
        if (talentInfo->TalentTab == talentTabIds[2]) c2++;
    }

    out << (c0 ? "|h|cff00ff00" : "") << c0 << "|h|cffffffff/";
    out << (c1 ? "|h|cff00ff00" : "") << c1 << "|h|cffffffff/";
    out << (c2 ? "|h|cff00ff00" : "") << c2 << "|h|cffffffff";

    out <<  ") " << classes[cls];
    return out.str();
}

string ChatHelper::formatClass(uint8 cls)
{
    return classes[cls];
}

string ChatHelper::formatRace(uint8 race)
{
    return races[race];
}
