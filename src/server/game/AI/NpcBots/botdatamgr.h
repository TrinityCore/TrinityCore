#ifndef _BOTDATAMGR_H
#define _BOTDATAMGR_H

#include "botcommon.h"

class Creature;

enum NpcBotDataUpdateType
{
    NPCBOT_UPDATE_OWNER                 = 1,
    NPCBOT_UPDATE_ROLES,
    NPCBOT_UPDATE_SPEC,
    NPCBOT_UPDATE_DISABLED_SPELLS,
    NPCBOT_UPDATE_FACTION,
    NPCBOT_UPDATE_EQUIPS,
    NPCBOT_UPDATE_ERASE,
    NPCBOT_UPDATE_END
};

struct NpcBotData
{
    typedef std::set<uint32> DisabledSpellsContainer;

    friend class BotDataMgr;
public:
    uint32 owner;
    uint16 roles;
    uint32 faction;
    uint8 spec;
    uint32 equips[BOT_INVENTORY_SIZE];
    DisabledSpellsContainer disabled_spells;

private:
    explicit NpcBotData(uint16 iroles, uint32 ifaction, uint8 ispec = 1) : owner(0), roles(iroles), faction(ifaction), spec(ispec)
    {
        for (uint8 i = 0; i != BOT_INVENTORY_SIZE; ++i)
            equips[i] = 0;
    }
    NpcBotData(NpcBotData const&);
};

struct NpcBotAppearanceData
{
    friend class BotDataMgr;
public:
    uint8 gender;
    uint8 skin;
    uint8 face;
    uint8 hair;
    uint8 haircolor;
    uint8 features;
private:
    explicit NpcBotAppearanceData() {}
    NpcBotAppearanceData(NpcBotAppearanceData const&);
};

struct NpcBotExtras
{
    friend class BotDataMgr;
public:
    uint8 race;
    uint8 bclass;
private:
    explicit NpcBotExtras() {}
    NpcBotExtras(NpcBotExtras const&);
};

class BotDataMgr
{
    public:
        static void LoadNpcBots();

        static void AddNpcBotData(uint32 entry, uint16 roles, uint8 spec, uint32 faction);
        static NpcBotData const* SelectNpcBotData(uint32 entry);
        static void UpdateNpcBotData(uint32 entry, NpcBotDataUpdateType updateType, void* data = nullptr);
        static void UpdateNpcBotDataAll(uint32 playerGuid, NpcBotDataUpdateType updateType, void* data = nullptr);

        static NpcBotAppearanceData const* SelectNpcBotAppearance(uint32 entry);
        static NpcBotExtras const* SelectNpcBotExtras(uint32 entry);

        static bool AllBotsLoaded();

        static void RegisterBot(Creature const* bot);
        static void UnregisterBot(Creature const* bot);
        static Creature const* FindBotInWorld(uint32 entry);

    private:

        BotDataMgr() {}
        BotDataMgr(BotDataMgr const&);
};

#endif
