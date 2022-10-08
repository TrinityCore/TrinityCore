/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_ZULGURUB_H
#define DEF_ZULGURUB_H

enum
{
    ZULGURUB_MAX_ENCOUNTER  = 13,

    SPELL_HAKKAR_POWER      = 24692,
    SPELL_HAKKAR_POWER_DOWN = 24693,

    NPC_LORKHAN             = 11347,
    NPC_ZATH                = 11348,
    NPC_THEKAL              = 14599,
    NPC_JINDO               = 11380,
    NPC_HAKKAR              = 14834,
    NPC_VENOXIS             = 14507,
    NPC_ARLOKK              = 14515,
    NPC_MARLI               = 14510,
    NPC_RAZZASHI_SKITTERER  = 14880,
    NPC_RAZZASHI_VENOMBROOD = 14532,
    NPC_HAKARI_SHADOWCASTER = 11338,
    NPC_RAZZASHI_BROODWIDOW = 11370,
    NPC_GAHZRANKA           = 15114,
    NPC_JEKLIK              = 14517,
    
    TYPE_HAKKAR_POWER       = 0, // set data triggered by spell 24693
    TYPE_ARLOKK             = 1,
    TYPE_JEKLIK             = 2,
    TYPE_VENOXIS            = 3,
    TYPE_MARLI              = 4,
    TYPE_OHGAN              = 5,
    TYPE_THEKAL             = 6,
    TYPE_ZATH               = 7,
    TYPE_LORKHAN            = 8,
    TYPE_HAKKAR             = 9,
    TYPE_RANDOM_BOSS        = 10,
    TYPE_JINDO              = 11,
    TYPE_GAHZRANKA          = 12,

    DATA_JINDO              = 13,
    DATA_LORKHAN            = 14,
    DATA_THEKAL             = 15,
    DATA_ZATH               = 16,
    DATA_HAKKAR             = 17,
    DATA_GAHZRANKA          = 18
};

class instance_zulgurub : public ScriptedInstance
{
    public:
        instance_zulgurub(Map* pMap) : ScriptedInstance(pMap), m_randomBossSpawned(false) {Initialize();};

        void Initialize() override;
        void Create() override;

        bool IsEncounterInProgress() const override;
        void OnCreatureCreate(Creature* pCreature) override;
        void OnCreatureDeath(Creature * pCreature) override;
        void SetData(uint32 uiType, uint32 uiData) override;
        char const* Save() override;
        void Load(char const* chrIn) override;
        void HandleLoadCreature(uint32 dataType, uint64 &storeGuid, Creature* pCrea); // Nostalrius

        uint32 GetData(uint32 uiType) override;
        uint64 GetData64(uint32 uiData) override;

        // each time High Priest dies lower Hakkar's HP
        void UpdateHakkarPowerStacks();
        Unit* Thekal_GetUnitThatCanRez();
        uint32 GenerateRandomBoss();
        void SpawnRandomBoss();

    protected:
        std::string strInstData;
        bool m_randomBossSpawned;
        uint32 randomBossEntry;
        // If all High Priest bosses were killed. Lorkhan, Zath and Ohgan are added too.
        uint32 m_auiEncounter[ZULGURUB_MAX_ENCOUNTER];

        // Storing Lorkhan, Zath and Thekal because we need to cast on them later. Jindo is needed for heal function too.
        uint64 m_uiLorKhanGUID;
        uint64 m_uiZathGUID;
        uint64 m_uiThekalGUID;
        uint64 m_uiJindoGUID;
        uint64 m_uiHakkarGUID;
        uint64 m_uiGahzrankaGUID;

        uint64 m_uiMarliGUID;
        std::list<uint64> m_lMarliTrashGUIDList;
};

#endif
