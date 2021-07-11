/* Copyright (C) 2006 - 2010 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_BLACKROCK_SPIRE_H
#define DEF_BLACKROCK_SPIRE_H

enum
{
    MAX_ROOMS                   = 7,
    MAX_STADIUM_WAVES           = 7,
    MAX_STADIUM_MOBS_PER_WAVE   = 5,

    TYPE_ROOM_EVENT             = 0,
    TYPE_EMBERSEER              = 1,
    TYPE_FLAMEWREATH            = 2,                        // Only summon once per instance
    TYPE_STADIUM                = 3,
    TYPE_VALTHALAK              = 4,                        // Only summon once per instance
    TYPE_EVENT_DOOR_UBRS        = 5,                        // UBRS door event
    TYPE_SOLAKAR                = 6,                        // Rookery event
    INSTANCE_BRS_MAX_ENCOUNTER  = 7,

    NPC_SCARSHIELD_INFILTRATOR  = 10299,
    NPC_BLACKHAND_SUMMONER      = 9818,
    NPC_BLACKHAND_VETERAN       = 9819,
    NPC_PYROGUARD_EMBERSEER     = 9816,
    NPC_BLACKHAND_INCANCERATOR  = 10316,
    NPC_BLACKHAND_ELITE         = 10317,
    NPC_LORD_VICTOR_NEFARIUS    = 10162,
    NPC_REND_BLACKHAND          = 10429,
    NPC_GYTH                    = 10339,
    NPC_SOLAKAR                 = 10264,
    NPC_ROOKERY_GUARDIAN        = 10258,
    NPC_ROOKERY_HATCHER         = 10683,
    NPC_SOLAKAR_TRIGGER         = 160014,
    NPC_DRAKKISATH              = 10363,
    NPC_THE_BEAST               = 10430,
    NPC_CHROMATIC_WHELP         = 10442,                    // related to Gyth arena event
    NPC_CHROMATIC_DRAGON        = 10447,
    NPC_BLACKHAND_HANDLER       = 10742,

    NPC_FIREBRAND_GRUNT         = 9259,
    NPC_BANNOK_GRIMAXE          = 9596,

    // Doors
    GO_EMBERSEER_IN             = 175244,
    GO_DOORS                    = 175705,
    GO_EMBERSEER_OUT            = 175153,
    GO_GYTH_ENTRY_DOOR          = 164726,
    GO_GYTH_COMBAT_DOOR         = 175185,                   // control in boss_script, because will auto-close after each wave
    GO_GYTH_EXIT_DOOR           = 175186,

    GO_BLACKROCK_ALTAR          = 175706,

    GO_ROOM_7_RUNE              = 175194,
    GO_ROOM_3_RUNE              = 175195,
    GO_ROOM_6_RUNE              = 175196,
    GO_ROOM_1_RUNE              = 175197,
    GO_ROOM_5_RUNE              = 175198,
    GO_ROOM_2_RUNE              = 175199,
    GO_ROOM_4_RUNE              = 175200,

    GO_ROOKERY_EGG              = 175124,
    GO_FATHER_FLAME             = 175245,

    // UBRS door event
    GO_DOOR_URBS                = 164725,
    GO_BRAZIER01                = 175528,
    GO_BRAZIER02                = 175529,
    GO_BRAZIER03                = 175530,
    GO_BRAZIER04                = 175531,
    GO_BRAZIER05                = 175532,
    GO_BRAZIER06                = 175533,

    // Emberseer event
    GO_EMBERSEER_RUNE01         = 175187,
    GO_EMBERSEER_RUNE02         = 175267,
    GO_EMBERSEER_RUNE03         = 175268,
    GO_EMBERSEER_RUNE04         = 175269,
    GO_EMBERSEER_RUNE05         = 175270,
    GO_EMBERSEER_RUNE06         = 175271,
    GO_EMBERSEER_RUNE07         = 175272,
};

class instance_blackrock_spire : public ScriptedInstance, private DialogueHelper
{
    public:
        instance_blackrock_spire(Map* pMap);
        ~instance_blackrock_spire() override {}

        void Initialize() override;

        void OnObjectCreate(GameObject* pGo) override;
        void OnCreatureCreate(Creature* pCreature) override;
        void OnCreatureDeath(Creature* pCreature) override;
        void OnCreatureEvade(Creature* pCreature) override;

        void SetData(uint32 uiType, uint32 uiData) override;
        void SetData64(uint32 uiType, uint64 uiData) override;
        uint32 GetData(uint32 uiType) override;
        uint64 GetData64(uint32 uiType) override;

        char const* Save() override { return strInstData.c_str(); }
        void Load(char const* chrIn) override;

        void DoSortRoomEventMobs();
        void GetIncanceratorGUIDList(std::list<uint64> &lList) { lList = m_lIncanceratorGUIDList; }
        void GetRookeryEggGUIDList(std::list<uint64> &lList) { lList = m_lRookeryEggGUIDList; }

        void Update(uint32 uiDiff) override;

    protected:
        void JustDidDialogueStep(int32 iEntry) override;
        Creature* GetSpeakerByEntry(uint32 uiEntry) override;
        void DoSendNextStadiumWave();
        void DespawnStadiumSpectators();

        uint32 m_auiEncounter[INSTANCE_BRS_MAX_ENCOUNTER];
        std::string strInstData;
        
        uint64 m_uiEmberseerGUID;
        uint64 m_uiNefariusGUID;
        uint64 m_uiGythGUID;
        uint64 m_uiInfiltratorGUID;
        uint64 m_uiDrakkisathGUID;
        uint64 m_uiBeastGUID;
        uint64 m_uiRendGUID;

        uint64 m_uiEmberseerInDoorGUID;
        uint64 m_uiEmberseerCombatDoorGUID;
        uint64 m_uiEmberseerOutDoorGUID;
        uint64 m_uiGythEntryDoorGUID;
        uint64 m_uiGythCombatDoorGUID;
        uint64 m_uiGythExitDoorGUID;

        uint64 m_uiFatherFlameGUID;
        uint32 m_uiFatherFlame_timer;
        uint32 m_uiFatherFlame_WaveCount;
        uint64 m_uiSolakarTriggerGUID;

        uint64 m_uiUBRSDoorGUID;
        uint64 m_uiBrazier01GUID;
        uint64 m_uiBrazier02GUID;
        uint64 m_uiBrazier03GUID;
        uint64 m_uiBrazier04GUID;
        uint64 m_uiBrazier05GUID;
        uint64 m_uiBrazier06GUID;

        uint64 m_uiEmberseerRune01GUID;
        uint64 m_uiEmberseerRune02GUID;
        uint64 m_uiEmberseerRune03GUID;
        uint64 m_uiEmberseerRune04GUID;
        uint64 m_uiEmberseerRune05GUID;
        uint64 m_uiEmberseerRune06GUID;
        uint64 m_uiEmberseerRune07GUID;

        uint64 m_uiBlackRockAltarGUID;

        uint32 m_uiUBRSDoor_Timer;
        uint32 m_uiUBRSDoor_Step;

        uint32 m_uiStadiumEventTimer;
        uint8 m_uiStadiumWaves;
        uint8 m_uiStadiumMobsAlive;

        uint64 m_auiRoomRuneGUID[MAX_ROOMS];
        std::list<uint64> m_alRoomEventMobGUIDSorted[MAX_ROOMS];
        std::list<uint64> m_lRoomEventMobGUIDList;
        std::list<uint64> m_lIncanceratorGUIDList;
        std::list<uint64> m_lRookeryEggGUIDList;
        GuidList m_lStadiumSpectatorsGUIDList;

        bool m_bBannokSpawned;
};

#endif
