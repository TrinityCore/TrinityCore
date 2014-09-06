#pragma once

using namespace std;

typedef set<uint32> ItemIds;
typedef set<uint32> SpellIds;

#include "../pchdef.h"

namespace ai
{
    class ChatHelper : public PlayerbotAIAware
    {
    public:
        ChatHelper(PlayerbotAI* ai);

    public:
        static string formatMoney(uint32 copper);
        static uint32 parseMoney(string& text);
        static ItemIds parseItems(string& text);
        uint32 parseSpell(string& text);
        static string formatQuest(Quest const* quest);
        static string formatItem(ItemTemplate const * proto, int count = 0);
        static string formatSpell(SpellInfo const *sInfo);
        static string formatGameobject(GameObject* go);
        static string formatQuestObjective(string name, int available, int required);
        static list<ObjectGuid> parseGameobjects(string& text);

        static ChatMsg parseChat(string& text);
        static string formatChat(ChatMsg chat);

        static string formatClass(Player* player, int spec);
        static string formatClass(uint8 cls);
        static string formatRace(uint8 race);

        static uint32 parseItemQuality(string text);
        static bool parseItemClass(string text, uint32 *itemClass, uint32 *itemSubClass);
        static uint32 parseSlot(string text);

        static bool parseable(string text);

    private:
        static map<string, uint32> consumableSubClasses;
        static map<string, uint32> tradeSubClasses;
        static map<string, uint32> itemQualities;
        static map<string, uint32> slots;
        static map<string, ChatMsg> chats;
        static map<uint8, string> classes;
        static map<uint8, string> races;
        static map<uint8, map<uint8, string> > specs;
    };
};
