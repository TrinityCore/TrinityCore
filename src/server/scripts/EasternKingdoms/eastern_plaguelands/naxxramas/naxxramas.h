/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_NAXXRAMAS_H
#define DEF_NAXXRAMAS_H

#include "scriptPCH.h"
#include "Utilities/EventMap.h"

enum NAXX_ENCOUNTERS_TYPES
{
    TYPE_ANUB_REKHAN            = 0,
    TYPE_FAERLINA               = 1,
    TYPE_MAEXXNA                = 2,

    TYPE_NOTH                   = 3,
    TYPE_HEIGAN                 = 4,
    TYPE_LOATHEB                = 5,

    TYPE_RAZUVIOUS              = 6,
    TYPE_GOTHIK                 = 7,
    TYPE_FOUR_HORSEMEN          = 8,

    TYPE_PATCHWERK              = 9,
    TYPE_GROBBULUS              = 10,
    TYPE_GLUTH                  = 11,
    TYPE_THADDIUS               = 12,

    TYPE_SAPPHIRON              = 13,
    TYPE_KELTHUZAD              = 14,

    MAX_ENCOUNTER               = 15
};

enum NaxxNPCs : uint32
{
    NPC_ANUB_REKHAN             = 15956,
    NPC_FAERLINA                = 15953,
    NPC_MAEXXNA                 = 15952,

    NPC_PATCHWERK               = 16028,
    NPC_GROBBULUS               = 15931,
    NPC_GLUTH                   = 15932,
    NPC_THADDIUS                = 15928,
    NPC_STALAGG                 = 15929,
    NPC_FEUGEN                  = 15930,
    NPC_TESLA_COIL              = 16218,

    NPC_NOTH                    = 15954,
    NPC_HEIGAN                  = 15936,
    NPC_LOATHEB                 = 16011,

    NPC_RAZUVIOUS               = 16061,
    NPC_GOTHIK                  = 16060,
    NPC_MOGRAINE                = 16062,
    NPC_ZELIEK                  = 16063,
    NPC_THANE                   = 16064,
    NPC_BLAUMEUX                = 16065,

    NPC_SAPPHIRON               = 15989,
    NPC_KELTHUZAD               = 15990,

    // Gothik adds
    NPC_SUB_BOSS_TRIGGER        = 16137,    //summon locations
    NPC_UNREL_TRAINEE           = 16124,
    NPC_UNREL_DEATH_KNIGHT      = 16125,
    NPC_UNREL_RIDER             = 16126,
    NPC_SPECT_TRAINEE           = 16127,
    NPC_SPECT_DEATH_KNIGTH      = 16148,
    NPC_SPECT_RIDER             = 16150,
    NPC_SPECT_HORSE             = 16149,

    // Kel'Thuzad adds
    NPC_SOLDIER_FROZEN          = 16427,
    NPC_UNSTOPPABLE_ABOM        = 16428,
    NPC_SOUL_WEAVER             = 16429,
    NPC_GUARDIAN                = 16441,

    NPC_MR_BIGGLESWORTH         = 16998,
    NPC_LICH_KING               = 16980,

    NPC_PatchworkGolem          = 16017,
    NPC_BileRetcher             = 16018,
    NPC_SludgeBelcher           = 16029,
    NPC_EmbalmingSlime          = 16024,
    NPC_LivingMonstrosity       = 16021,
    NPC_SurgicalAssistant       = 16022,
    NPC_MadScientist            = 16020,

    NPC_NaxxramasFollower       = 16505,
    NPC_NaxxramasWorshipper     = 16506,
    NPC_ZombieChow              = 16360,
    NPC_DeathKnightCaptain      = 16145,
    NPC_DeathKnightUnderstudy   = 16803,
    NPC_StitchedGiant           = 16025,
    NPC_SewageSlime             = 16375,
    NPC_LivingPoison            = 16027,
    NPC_DeathchargerSteed       = 16067,
    NPC_DeathKnight             = 16146,
    NPC_RisenSquire             = 16154,
    NPC_DarkTouchedWarrior      = 16156,
    NPC_DoomTouchedWarrior      = 16157,
    NPC_DeathTouchedWarrior     = 16158,
    NPC_DeathKnightCavalier     = 16163,
    NPC_BonyConstruct           = 16167,
    NPC_SkeletalSmith           = 16193,
    NPC_DeathknightVindicator   = 16451,
    NPC_NecroKnightGuardian     = 16452,
    NPC_DeathLord               = 16861,
    NPC_StoneskinGargoyle       = 16168,
    NPC_PlagueBeast             = 16034,
    NPC_FrenziedBat             = 16036,
    NPC_PlaguedBat              = 16037,
    NPC_DreadCreeper            = 15974,
    NPC_CarrionSpinner          = 15975,
    NPC_VenomStalker            = 15976,
    NPC_PoisonousSkitterer      = 15977,
    NPC_CryptReaver             = 15978,
    NPC_NaxxramasCultist        = 15980,
    NPC_NaxxramasAcolyte        = 15981,
    NPC_PlaguedGhoul            = 16447,
    NPC_NecroStalker            = 16453,
    NPC_SpiritOfNaxxramas       = 16449,
    NPC_PlaguedGargoyle         = 16446,
    NPC_ShadeOfNaxxramas        = 16164,
    NPC_NecroKnight             = 16165,
    NPC_PlagueSlime             = 16243,
    NPC_InfectiousGhoul         = 16244,
    NPC_FalloutSlime            = 16290,
    NPC_MutatedGrub             = 16297,
    NPC_NecropolisAcolyte       = 16368,
    NPC_BileSludge              = 16142,
    NPC_UnholyAxe               = 16194,
    NPC_UnholyStaff             = 16215,
    NPC_UnholySwords            = 16216,
    NPC_LightningTotem          = 16385,
    NPC_PlaguedDeathhound       = 16448,

    NPC_EyeStalk                = 16236,
    NPC_ArchmageTarsis          = 16381
};

enum NaxxAreaTriggers : uint32
{
    AREATRIGGER_KELTHUZAD       = 4112,
    AREATRIGGER_FAERLINA        = 4115,     // Used for faerlinas greet message
    AREATRIGGER_GOTHIK          = 4116,
    AREATRIGGER_ANUB            = 4119,     // Triggers the greet-message from anub

    // AREATRIGGER_EXIT_NAXXRAMAS      =
    AREATRIGGER_BEHIND_FROSTWYRM_TP = 4120, // not sure why this one is there.
    AREATRIGGER_FROSTWYRM_TP        = 4167,
    AREATRIGGER_HUB_TO_FROSTWYRM    = 4156,     // Teleport to sapphiron from center of naxx

    AREATRIGGER_THADDIUS_ENTRANCE   = 4113,

    AREATRIGGER_START_DK_WING       = 4117
};

static const WorldLocation toFrostwyrmTPPos(533, 3498.13f, -5349.6f, 144.967f, 1.48353f);
static const WorldLocation entranceHubTPPos(533, 3023.52f, -3434.31f, 296.1f, 0.0f);

enum NaxxGOs : uint32
{
    // Arachnid Quarter
    GO_ARAC_ANUB_DOOR           = 181126,   //encounter door - open on click after click auto open/close on encounter pull/kill/reset
    GO_ARAC_ANUB_GATE           = 181195,   //open after boss is dead
    GO_ARAC_FAER_WEB            = 181235,   //encounter door
    GO_ARAC_FAER_DOOR           = 194022,   //after faerlina, to outer ring
    GO_ARAC_MAEX_INNER_DOOR     = 181197,   //encounter door
    GO_ARAC_MAEX_OUTER_DOOR     = 181209,   //right before maex

    // Plague Quarter
    GO_PLAG_NOTH_ENTRY_DOOR     = 181200,   //encounter door
    GO_PLAG_NOTH_EXIT_DOOR      = 181201,   //exit, open when boss dead
    GO_PLAG_HEIG_ENTRY_DOOR     = 181202,
    GO_PLAG_HEIG_EXIT_DOOR      = 181203,   //exit, open when boss dead
    GO_PLAG_HEIG_OLD_EXIT_DOOR  = 181496,   //between heigan and loatheb. Unsure if used
    GO_PLAG_LOAT_DOOR           = 181241,   //encounter door

    // Military Quarter
    GO_PLAG_SLIME01_DOOR        = 181198,   //not used
    GO_PLAG_SLIME02_DOOR        = 181199,   //not used
    GO_MILI_GOTH_ENTRY_GATE     = 181124,   //open after razuvious died
    GO_MILI_GOTH_EXIT_GATE      = 181125,   //exit, open at boss dead
    GO_MILI_GOTH_COMBAT_GATE    = 181170,   //used while encounter is in progress
    GO_MILI_HORSEMEN_DOOR       = 181119,   //encounter door

    GO_CHEST_HORSEMEN_NORM      = 181366,   //four horsemen event, DoRespawnGameObject() when event == DONE

    // Construct Quarter
    GO_CONS_PATH_EXIT_DOOR      = 181123,
    GO_CONS_GLUT_EXIT_DOOR      = 181120,
    GO_CONS_THAD_DOOR           = 181121,   // Thaddius encounter door

    GO_HUB_PORTAL               = 181229,   // portal to frostwyrm lair
    // Frostwyrm Lair
    GO_SAPPHIRON_SPAWN          = 181356,
    GO_KELTHUZAD_WATERFALL_DOOR = 181225,   // open after sapphiron is dead
    GO_KELTHUZAD_DOOR           = 181228,   // open after sapphiron is dead. Possibly not until players are close?

    // Shiny things appearing at central hub eyes when killing boss
    GO_MILI_EYE_RAMP            = 181210,
    GO_PLAG_EYE_RAMP            = 181211,
    GO_ARAC_EYE_RAMP            = 181212,
    GO_CONS_EYE_RAMP            = 181213,

    // eye looking things at end of wings. Ports ut to central hub.
    GO_ARAC_PORTAL              = 181575,
    GO_CONS_PORTAL              = 181576,
    GO_PLAG_PORTAL              = 181577,
    GO_MILI_PORTAL              = 181578,

    // Shiny things appearing at above GObs when killing boss.
    GO_MILI_EYE_BOSS            = 181230,
    GO_PLAG_EYE_BOSS            = 181231,
    GO_CONS_EYE_BOSS            = 181232,
    GO_ARAC_EYE_BOSS            = 181233,

    // Kel'Thuzad window portals. "opening" on 40%
    // NOTE: the ids are used to loop over the GObjs,
    // so if they change, update code in instance_naxxramas::ToggleKelThuzadWindows
    GO_KT_WINDOW_1              = 181402,
    GO_KT_WINDOW_2              = 181403,
    GO_KT_WINDOW_3              = 181404,
    GO_KT_WINDOW_4              = 181405,

    GO_CONS_NOX_TESLA_FEUGEN    = 181477,
    GO_CONS_NOX_TESLA_STALAGG   = 181478
};

enum NaxxZoneScriptTexts
{
    // Background screams in Instance if Thaddius still alive
    THADDIUS_SAY_SCREAM1 = 13092, // todo: add use
    THADDIUS_SAY_SCREAM2 = 13093, // todo: add use
    THADDIUS_SAY_SCREAM3 = 13094, // todo: add use
    THADDIUS_SAY_SCREAM4 = 13095, // todo: add use

    //when each of the 4 wing bosses dies
    KELTHUZAD_SAY_TAUNT1 = 12984,
    KELTHUZAD_SAY_TAUNT2 = 12985,
    KELTHUZAD_SAY_TAUNT3 = 12986,
    KELTHUZAD_SAY_TAUNT4 = 12987,

    // when bigglesworth dies, rip
    KELTHUZAD_SAY_CAT_DIED = 13150,

    //when shappiron dies. dialog between kel and lich king (in this order)
    SAY_SAPP_DIALOG1        = 12990,
    SAY_SAPP_DIALOG2_LICH   = 12988,
    SAY_SAPP_DIALOG3        = 12991,
    SAY_SAPP_DIALOG4_LICH   = 12989,
    SAY_SAPP_DIALOG5        = 12992,

    // greets used on areatriggers
    SAY_FAERLINA_GREET      = 12852,
    SAY_THADDIUS_GREET      = 13091,

    SAY_KORT_TAUNT1         = 13038, // To arms, ye roustabouts! We've got company!
    SAY_ZELI_TAUNT3         = 13103, // Do not continue! Turn back while there's still time!
    SAY_MOG_TAUNT3          = 13060, // Life is meaningless. It is in death that we are truly tested.
    SAY_BLAU_TAUNT3         = 13016, // The first kill goes to me! Anyone care to wager?

    SAY_4HM_DIALOGUE_1      = 13101,
    SAY_4HM_DIALOGUE_2      = 13014,
    SAY_4HM_DIALOGUE_3      = 13058,
    SAY_4HM_DIALOGUE_4      = 13015,
    SAY_4HM_DIALOGUE_5      = 13102,
    SAY_4HM_DIALOGUE_6      = 13039,
    SAY_4HM_DIALOGUE_7      = 13059
};

struct GothTrigger
{
    bool bIsRightSide;
    bool bIsAnchorHigh;
};

static constexpr uint8 max_stalks = 20;
static constexpr float eyeStalkPossitions[max_stalks][4] =
{
    { 2761.28f, -3765.37f, 275.08f, 1.24f },
    { 2770.17f, -3782.11f, 275.08f, 1.33f },
    { 2798.11f, -3788.94f, 275.08f, 2.35f },
    { 2797.91f, -3776.86f, 275.08f, 2.25f },
    { 2792.06f, -3762.52f, 275.08f, 2.9f, },
    { 2789.87f, -3752.15f, 275.08f, 2.74f },
    { 2804.21f, -3757.96f, 275.08f, 3.9f },
    { 2821.16f, -3759.75f, 275.08f, 4.47f },
    { 2834.64f, -3751.23f, 275.08f, 4.27f },
    { 2843.54f, -3768.08f, 275.08f, 3.06f },
    { 2862.4f,  -3758.3f,  275.08f, 4.8f },
    { 2877.8f,  -3762.46f, 275.08f, 4.8f },
    { 2894.11f, -3757.89f, 275.08f, 4.56f },
    { 2895.25f, -3779.5f,  275.08f, 2.4f },
    { 2881.59f, -3782.22f, 275.08f, 2.79f },
    { 2867.2f,  -3778.21f, 275.08f, 3.01f },
    { 2851.39f, -3776.54f, 275.08f, 2.69f },
    { 2846.16f, -3789.13f, 275.08f, 1.79f },
    { 2830.09f, -3776.49f, 275.08f, 0.94f },
    { 2813.34f, -3780.97f, 275.08f, 1.84f },
};

class instance_naxxramas : public ScriptedInstance
{
public:
    instance_naxxramas(Map* pMap);
    ~instance_naxxramas() override { }

    void Initialize() override;

    bool IsEncounterInProgress() const override;

    void OnCreatureCreate(Creature* pCreature) override;
    void OnObjectCreate(GameObject* pGo) override;
    void OnCreatureRespawn(Creature * pCreature) override;

    void SetData(uint32 uiType, uint32 uiData) override;
    uint32 GetData(uint32 uiType) override;
    uint64 GetData64(uint32 uiData) override;

    uint64 GetGOUuid(NaxxGOs which);

    char const* Save() override { return strInstData.c_str(); }
    void Load (char const* chrIn) override;

    // goth
    void SetGothTriggers();
    Creature* GetClosestAnchorForGoth(Creature* pSource, bool bRightSide);
    void GetGothSummonPointCreatures(std::list<Creature*> &lList, bool bRightSide);
    bool IsInRightSideGothArea(Unit const* pUnit);

    // kel
    void OnKTAreaTrigger(AreaTriggerEntry const* pAT); //impl in boss_kelthuzad.cpp
    void SetChamberCenterCoords(float fX, float fY, float fZ);
    void GetChamberCenterCoords(float &fX, float &fY, float &fZ) { fX = m_fChamberCenterX; fY = m_fChamberCenterY; fZ = m_fChamberCenterZ; }
    void ToggleKelThuzadWindows(bool setOpen);

    void OnPlayerDeath(Player* p) override;
    void OnCreatureDeath(Creature* pCreature) override;

    void onNaxxramasAreaTrigger(Player* pPlayer, AreaTriggerEntry const* pAt);

    void UpdateAutomaticBossEntranceDoor(NaxxGOs which, uint32 uiData, int requiredPreBossData = -1);  // GO closes when uiData==IN_PROGRESS, otherwise opens
    void UpdateAutomaticBossEntranceDoor(GameObject* pGO, uint32 uiData, int requiredPreBossData = -1);// GO closes when uiData==IN_PROGRESS, otherwise opens

    void UpdateManualDoor(NaxxGOs which, uint32 uiData);
    void UpdateManualDoor(GameObject* pGO, uint32 uiData);

    void UpdateBossGate(NaxxGOs which, uint32 uiData);          // GO_STATE_ACTIVE when uiData==DONE, otherwise GO_STATE_READY
    void UpdateBossGate(GameObject* pGO, uint32 uiData);        // GO_STATE_ACTIVE when uiData==DONE, otherwise GO_STATE_READY

    void UpdateTeleporters(uint32 uiType, uint32 uiData);           // Updates all portals related to an endboss specified by uiType
    void SetTeleporterVisualState(GameObject* pGO, uint32 uiData);  // Sets the state of a specific eye-portal
    void SetTeleporterState(GameObject* pGO, uint32 uiData);        // Sets the state of a specific eye-portal visual GO

    uint8 GetNumEndbossDead();
    GuidList m_alHeiganTrapGuids[4];

    bool HandleEvadeOutOfHome(Creature* pWho);

    void OnCreatureEnterCombat(Creature * creature) override;

    bool WingsAreCleared();

private:
    bool m_faerlinaHaveGreeted;
    bool m_thaddiusHaveGreeted;
    bool m_haveDoneDKWingIntro;
    uint32 m_horsemenDeathCounter;
    uint64 m_uiHorsemenChestGUID;

protected:
    uint32 m_auiEncounter[MAX_ENCOUNTER];
    std::string strInstData;

    std::list<uint64> m_lGothTriggerList;
    std::unordered_map<uint64, GothTrigger> m_mGothTriggerMap;

    float m_fChamberCenterX;
    float m_fChamberCenterY;
    float m_fChamberCenterZ;

private:
    EventMap m_events;
    void Update(uint32 diff) override;
};

#endif
