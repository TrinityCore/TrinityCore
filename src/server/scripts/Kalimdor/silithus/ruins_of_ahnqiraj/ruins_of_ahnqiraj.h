/* Copyright (C) 2006 - 2010 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_RUINS_OF_AHNQIRAJ_H
#define DEF_RUINS_OF_AHNQIRAJ_H

#include <array>
#include <deque>

//#define DEBUG_MODE

struct SpawnLocations
{
    float x, y, z;
};

enum
{
    TYPE_KURINNAXX          = 0,
    TYPE_GENERAL_ANDOROV    = 1,
    TYPE_RAJAXX             = 2,
    TYPE_BURU               = 3,
    TYPE_MOAM               = 4,
    TYPE_AYAMISS            = 5,
    TYPE_OSSIRIAN           = 6,
    INSTANCE_RUINS_AQ_MAX_ENCOUNTER = 7,

    TYPE_QIRAJI_GLADIATOR   = 8,
};

/* This type of data = the count of living mobs in each wave.
     The instance counts down thanks to OnCreatureDeath  */
#define WAVE_MAX 7
#define WAVE_OFFSET 10
#define WAVE_MEMBERS_INIT_COUNT 7
enum
{
    TYPE_WAVE1              = WAVE_OFFSET,
    TYPE_WAVE2              = WAVE_OFFSET+1,
    TYPE_WAVE3              = WAVE_OFFSET+2,
    TYPE_WAVE4              = WAVE_OFFSET+3,
    TYPE_WAVE5              = WAVE_OFFSET+4,
    TYPE_WAVE6              = WAVE_OFFSET+5,
    TYPE_WAVE7              = WAVE_OFFSET+6
};

enum
{
    DATA_KURINNAXX      = 0,
    DATA_RAJAXX         = 1,
    DATA_BURU           = 2,
    DATA_AYAMIS         = 3,
    DATA_MOAM           = 4,
    DATA_OSSIRIAN       = 5,
    DATA_ANDOROV        = 6,

    DATA_QEEZ           = 7,
    DATA_TUUBID         = 8,
    DATA_DRENN          = 9,
    DATA_XURREM         = 10,
    DATA_YEGGETH        = 11,
    DATA_PAKKON         = 12,
    DATA_ZERRAN         = 13,

    DATA_CRYSTAL        = 14,
    DATA_CRYSTAL_INIT   = 15,
    DATA_YEGGETH_SHIELD = 16,
};

enum
{
    NPC_MOAM            =   15340,
    NPC_AYAMISS         =   15369,
    NPC_OSSIRIAN        =   15339,
    NPC_BURU            =   15370,
    NPC_RAJAXX          =   15341,
    NPC_SWARMGUARD_NEEDLER = 15344,
    NPC_KURINNAXX       =   15348,
    NPC_COLONEL_ZERRAN  =   15385,
    NPC_MAJOR_YEGGETH   =   15386,
    NPC_QIRAJI_WARRIOR  =   15387,
    NPC_MAJOR_PAKKON    =   15388,
    NPC_CAPTAIN_DRENN   =   15389,
    NPC_CAPTAIN_XURREM  =   15390,
    NPC_CAPTAIN_TUUBID  =   15392,
    NPC_CAPTAIN_QEEZ    =   15391,
    NPC_KALDOREI_ELITE  =   15473,
    NPC_GENERAL_ANDOROV =   15471,

    // Gossip menu ids
    ANDOROV_GOSSIP_NOT_STARTED = 6629,
    ANDOROV_GOSSIP_IN_PROGRESS = 7048,
    ANDOROV_GOSSIP_DONE        = 7047,

    // Crystal Weaknesses
    SPELL_FIRE_WEAKNESS         =   25177,
    SPELL_NATURE_WEAKNESS       =   25180,
    SPELL_FROST_WEAKNESS        =   25178,
    SPELL_ARCANE_WEAKNESS       =   25171,
    SPELL_SHADOW_WEAKNESS       =   25183,

    GO_OSSIRIAN_CRYSTAL = 180619,
    CRYSTAL_TRIGGER     = 15590
};

// Initial distance between the used crystal and new crystals before expanding the search
#define OSSIRIAN_CRYSTAL_INITIAL_DIST 80.0f
#define OSSIRIAN_CRYSTAL_NUM_ACTIVE 2

std::array<SpawnLocations, 11> const CrystalSpawn =
{{
    { -9407.164062f, 1959.240845f, 85.558998f }, // central spawn, not initially spawned since it was a nerfed mechanic added in 1.11
    { -9357.931641f, 1930.596802f, 85.556198f },
    { -9383.113281f, 2011.042725f, 85.556389f },
    { -9243.36f, 1979.04f, 85.556f },
    { -9281.68f, 1886.66f, 85.5558f },
    { -9241.8f, 1806.39f, 85.5557f },
    { -9366.78f, 1781.76f, 85.5561f },
    { -9297.668945f, 1747.256348f, 85.5566f },
    { -9430.37f, 1786.86f, 85.557f },
    { -9187.087891f, 1940.501099f, 85.5564f },
    { -9406.73f, 1863.13f, 85.5558f }
}};


struct instance_ruins_of_ahnqiraj : public ScriptedInstance
{
public:
    instance_ruins_of_ahnqiraj(Map* pMap);
    void Initialize() override;

    void SetData(uint32 uiType, uint32 uiData) override;
    uint32 GetData(uint32 uiType) override;
    bool IsEncounterInProgress() const override;
    uint64 GetData64(uint32 uiData) override;
    void OnCreatureEnterCombat(Creature * pCreature) override;
    void OnCreatureEvade(Creature* pCreature) override;
    void OnCreatureCreate(Creature* pCreature) override;
    void OnObjectCreate(GameObject *pGo) override;
    void OnCreatureDeath(Creature* pCreature) override;
    void Update(uint32 uiDiff) override;

    char const* Save() override;
    void Load(char const* chrIn) override;

    void SpawnNewCrystals(ObjectGuid usedCrystal);

private:
    uint8 GetWaveFromCreature(Creature* creature);
    void SetAndorovSquadRespawnTime(uint32 nextRespawnDelay);
    void SetAndorovSquadFaction(uint32 faction);
    void ForceAndorovSquadDespawn(uint32 timeToDespawn);

    uint32 m_auiEncounter[INSTANCE_RUINS_AQ_MAX_ENCOUNTER];
    uint32 m_uiWaveMembersCount[WAVE_MAX];

    uint64 m_uiKurinnaxxGUID;
    uint64 m_uiBuruGUID;
    uint64 m_uiOssirianGUID;
    uint64 m_uiAndorovGUID;
    std::list<uint64> m_lKaldoreiElites;
    std::list<uint64> m_lYeggethShieldList;
    std::list<uint64> m_lOssirianPylons;
    std::unordered_map<ObjectGuid, uint32> crystalIndexes;
    std::list<ObjectGuid> crystalGuids;
    std::deque<uint32> crystalIndexHistory;

    uint64 m_uiQeezGUID;
    uint64 m_uiTuubidGUID;
    uint64 m_uiDrennGUID;
    uint64 m_uiXurremGUID;
    uint64 m_uiYeggethGUID;
    uint64 m_uiPakkonGUID;
    uint64 m_uiZerranGUID;
    uint64 m_uiRajaxxGUID;

    uint32 m_uiGladiatorDeath;

    std::string strInstData;

    uint32 m_uiRajaxxEventResetTimer;
    bool m_bRajaxxEventIsToReset;

    bool m_bIsAQDoorOn;
    ObjectGuid p_doorGuid;
};

#ifdef DEBUG_MODE
enum
{
    AQ_RESPAWN_3_MINUTES    = 6,
    AQ_RESPAWN_5_MINUTES    = 60,
    AQ_RESPAWN_15_MINUTES   = 45,
    AQ_RESPAWN_FOUR_DAYS    = 345600
};
#else
enum
{
    AQ_RESPAWN_3_MINUTES    = 180,
    AQ_RESPAWN_5_MINUTES    = 300,
    AQ_RESPAWN_15_MINUTES   = 900,
    AQ_RESPAWN_FOUR_DAYS    = 345600
};
#endif

#endif
