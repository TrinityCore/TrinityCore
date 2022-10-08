/* Copyright (C) 2009 - 2010 Nostalrius <http://nostalrius.ath.cx/>
 * Auteur        : Daemon, Chakor
 * All rights reserved */

#ifndef __DEF_DIRE_MAUL_HEADER
#define __DEF_DIRE_MAUL_HEADER

enum
{
    MAX_CRISTALS              = 5,

    TYPE_CRISTAL_EVENT        = 1,
    TYPE_IMMOL_THAR           = 2,
    DATA_TENDRIS_AGGRO        = 3,
    TYPE_BOSS_ZEVRIM          = 4,
    TYPE_SPEAK_ECORCEFER      = 5,
    TYPE_GORDOK_TRIBUTE       = 6,
    TYPE_BROKEN_TRAP          = 7,
    TYPE_GORDOK_OGRE_SUIT     = 8,
    TYPE_CHORUSH_EQUIPMENT    = 9,
    TYPE_MOLDAR               = 10,
    TYPE_ALZZIN               = 11,

    INSTANCE_DIRE_MAUL_MAX_ENCOUNTER = 12,

    DATA_TANNIN_LOOTED            = 13,
    DATA_DREADSTEED_RITUAL_PLAYER = 14,

    // DM East
    NPC_OLD_IRONBARK       = 11491,
    NPC_ZEVRIM             = 11490, // Non utilise
    NPC_ALZZIN             = 11492,

    GO_CRUMBLE_WALL        = 177220,
    GO_FELVINE_SHARD       = 179559,
    GO_CORRUPT_VINE        = 179502,
    GO_DOOR_ALZZIN_IN      = 181496,

    // DM West
    NPC_IMMOL_THAR_GARDIEN = 11466,
    NPC_IMMOL_THAR         = 11496,
    NPC_TORTHELDRIN        = 11486,
    NPC_RESTE_MANA         = 11483,
    NPC_ARCANE_ABERRATION  = 11480,

    NPC_TENDRIS            = 11489,
    NPC_TENDRIS_PROTECTOR  = 11459,

    SAY_FREE_IMMOLTHAR     = 9364,
    SAY_KING_DEAD          = 9472,
    SAY_IMMOL_THAR_DEAD    = 9407,

    FACTION_FRIENDLY       = 35,

    GO_FORCE_FIELD         = 179503,
    GO_MAGIC_VORTEX        = 179506,
    GO_CRISTAL_1_EVENT     = 177259,
    GO_CRISTAL_2_EVENT     = 177257,
    GO_CRISTAL_3_EVENT     = 177258,
    GO_CRISTAL_4_EVENT     = 179504,
    GO_CRISTAL_5_EVENT     = 179505,
    GO_RITUAL_CANDLE_AURA  = 179688, // invis trap - true caster of 23226

    // DM North
    NPC_GUARD_MOLDAR       = 14326,
    NPC_GUARD_FENGUS       = 14321,
    NPC_GUARD_SLIPKIK      = 14323,
    NPC_CAPTAIN_KROMCRUSH  = 14325,
    NPC_CHORUSH            = 14324,
    NPC_KING_GORDOK        = 11501,
    NPC_MIZZLE_THE_CRAFTY  = 14353,

    GO_BROKEN_TRAP         = 179485,
    GO_FIXED_TRAP          = 179512,

    SPELL_KING_OF_GORDOK   = 22799,

    GO_GORDOK_TRIBUTE_0    = 179564,
    GO_GORDOK_TRIBUTE_1    = 300400,
    GO_GORDOK_TRIBUTE_2    = 300401,
    GO_GORDOK_TRIBUTE_3    = 300402,
    GO_GORDOK_TRIBUTE_4    = 300403,
    GO_GORDOK_TRIBUTE_5    = 300404,
    GO_GORDOK_TRIBUTE_6    = 300405,

    ITEM_GORDOK_INNER_DOOR_KEY = 18268,
    ITEM_GORDOK_COURTYARD_KEY  = 18266,
};

struct sGossipMenuItems
{
    uint16 m_uiMenu;
    char const* m_chItem;
};

const sGossipMenuItems sKromcrushGossips[4] =
{
    { 6913, "Um, I'm taking some prisoners we found outside before the king for punishment." },
    { 6915, "Er... that's how I found them. I wanted to show the king that they were a threat. Say Captain... I overhead Guard Fengus calling you a fat, useless knoll lover. " },
    { 6914, "So, now that I'm the king... what have you got for me?!" },
    { 6920, "This sounds like a task worthy of the new king!" }
};

const sGossipMenuItems sMizzleGossips[4] =
{
    { 6876, "I'm the new king? What are you talking about?"},
    { 6882, "It's good to be King! Now, let's get back to what you were talking about before..."},
    { 6895, "Henchmen? Tribute?"},
    { 6916, "Well then... show me the tribute!"}
};

class instance_dire_maul : public ScriptedInstance
{
    public:
        instance_dire_maul(Map* pMap);
        ~instance_dire_maul() override {}

        void Initialize() override;

        void OnPlayerEnter(Player* pPlayer) override;
        void OnPlayerLeave(Player* pPlayer) override;
        void OnObjectCreate(GameObject* pGo) override;
        void OnCreatureDeath(Creature* pCreature) override;
        void OnCreatureCreate(Creature* pCreature) override;

        void SetData(uint32 uiType, uint32 uiData) override;
        void SetData64(uint32 uiType, uint64 uiData) override;
        uint32 GetData(uint32 uiType) override;
        uint64 GetData64(uint32 uiType) override;

        char const* Save() override { return strInstData.c_str(); }
        void Load(char const* chrIn) override;

        uint8 GetChoRushEquipment();
        void DoSortCristalsEventMobs();

    protected:
        uint32 m_auiEncounter[INSTANCE_DIRE_MAUL_MAX_ENCOUNTER];
        std::string strInstData;

        // East
        uint64 m_uiDoorAlzzinInGUID;
        uint64 m_uiCrumbleWallGUID;
        uint64 m_uiCorruptVineGUID;
        std::list<uint64> m_lFelvineShardGUIDs;

        // West
        uint64 m_uiMagicVortexGUID;
        uint64 m_uiForceFieldGUID;
        uint64 m_uiImmolTharGUID;
        uint64 m_uiTortheldrinGUID;
        uint64 m_auiCristalsGUID[MAX_CRISTALS];
        uint64 m_uiRitualCandleAuraGUID;
        uint64 m_uiRitualPlayerGUID;

        std::list<uint64> m_alCristalsEventtMobGUIDSorted[MAX_CRISTALS];
        std::list<uint64> m_lCristalsEventtMobGUIDList;
        std::list<uint64> m_lImmolTharGardiensMobGUIDList;
        std::list<uint64> m_lTendrisProtectorsMobGUIDList;

        // North
        uint32 m_uiGuardAliveCount;
        uint64 m_uiTendrisGUID;
        uint64 m_uiOldIronbarkGUID;
        uint64 m_uiSlipKikGUID;
        uint64 m_uiCaptainKromcrushGUID;
        uint64 m_uiKingGordokGUID;
        uint64 m_uiChoRushTheObserverGUID;
        uint8 m_uiChoRushEquipment;

        uint64 m_uiGordokTribute0GUID;
        uint64 m_uiGordokTribute1GUID;
        uint64 m_uiGordokTribute2GUID;
        uint64 m_uiGordokTribute3GUID;
        uint64 m_uiGordokTribute4GUID;
        uint64 m_uiGordokTribute5GUID;
        uint64 m_uiGordokTribute6GUID;

        uint64 m_uiBrokenTrapGUID;
        bool m_bIsGordokTributeRespawned;
        bool m_bIsTanninLooted;
};

#endif
