/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_TEMPLE_OF_AHNQIRAJ_H
#define DEF_TEMPLE_OF_AHNQIRAJ_H

enum
{
    TYPE_SKERAM                 = 0,
    TYPE_SARTURA                = 1,
    TYPE_FANKRISS               = 2,
    TYPE_HUHURAN                = 3,
    TYPE_TWINS                  = 4,
    TYPE_CTHUN                  = 5,
    TYPE_BUG_TRIO               = 6,
    TYPE_VISCIDUS               = 7,
    TYPE_OURO                   = 8,
    
    MAX_ENCOUNTER               = 10,
};

enum
{
    NPC_VEKNISS_SOLDIER         = 15229,
    NPC_VEKNISS_WARRIOR         = 15230,
    NPC_VEKNISS_GUARDIAN        = 15233,
    NPC_VEKNISS_STINGER         = 15235,
    NPC_VEKNISS_WASP            = 15236,
    NPC_VEKNISS_HIVE_CRAWLER    = 15240,
    NPC_QIRAJI_MINDSLAYER       = 15246,
    NPC_QIRAJI_BRAINWASHER      = 15247,
    NPC_QIRAJI_LASHER           = 15249,
    NPC_QIRAJI_SLAYER           = 15250,
    NPC_QIRAJI_CHAMPION         = 15252,
    NPC_OBSIDIAN_ERADICATOR     = 15262,
    NPC_SKERAM                  = 15263,
    NPC_ANUBISATH_SENTINEL      = 15264,
    NPC_VEKNILASH               = 15275,
    NPC_VEKLOR                  = 15276,
    NPC_ANUBISATH_DEFENDER      = 15277,
    NPC_VISCIDUS                = 15299,
    NPC_VEKNISS_DRONE           = 15300,
    NPC_ANUBISATH_WARDER        = 15311,
    NPC_OBSIDIAN_NULLIFIER      = 15312,
    NPC_QIRAJI_SCARAB           = 15316,
    NPC_QIRAJI_SCORPION         = 15317,
    NPC_MERITHRA_OF_THE_DREAM   = 15378,
    NPC_CAELESTRASZ             = 15379,
    NPC_ARYGOS                  = 15380,
    NPC_ANDORGOS                = 15502,
    NPC_KANDROSTRASZ            = 15503,
    NPC_VETHSERA                = 15504,
    NPC_PRINCESS_HUHURAN        = 15509,
    NPC_FANKRISS_THE_UNYIELDING = 15510,
    NPC_KRI                     = 15511,
    NPC_BATTLEGUARD_SARTURA     = 15516,
    NPC_OURO                    = 15517,
    NPC_ANUBISATH_WARRIOR       = 15537,
    NPC_ANUBISATH_SWARMGUARD    = 15538,
    NPC_PRINCESS_YAUJ           = 15543,
    NPC_VEM                     = 15544,
    NPC_EYE_OF_C_THUN           = 15589,
    NPC_YAUJ_BROOD              = 15621,
    NPC_VEKNISS_BORER           = 15622,
    NPC_SPAWN_OF_FANKRISS       = 15630,
    NPC_OURO_SCARAB             = 15718,
    NPC_OURO_SPAWNER            = 15957,
    NPC_CTHUN                   = 15727,
    NPC_CTHUN_PORTAL            = 15896,
    NPC_VEKNISS_HATCHLING       = 15962,
    NPC_MASTERS_EYE             = 15963,
    NPC_SARTURA_S_ROYAL_GUARD   = 15984,

    GO_SKERAM_GATE              = 180636,
    GO_TWINS_ENTER_DOOR         = 180634,
    GO_TWINS_EXIT_DOOR          = 180635,
    GO_SANDWORM_BASE            = 180795,
    GO_GRASP_OF_CTHUN           = 180745,

    AREATRIGGER_TWIN_EMPERORS   = 4047,
    AREATRIGGER_SARTURA         = 4052,
    AREATRIGGER_STOMACH_GROUND  = 4033,
    AREATRIGGER_STOMACH_AIR     = 4034,
    AREATRIGGER_CTHUN_KNOCKBACK = 4036,

    // Whispered on players around the map
    SAY_CTHUN_WHISPER_1         = -1531033,
    SAY_CTHUN_WHISPER_2         = -1531034,
    SAY_CTHUN_WHISPER_3         = -1531035,
    SAY_CTHUN_WHISPER_4         = -1531036,
    SAY_CTHUN_WHISPER_5         = -1531037,
    SAY_CTHUN_WHISPER_6         = -1531038,
    SAY_CTHUN_WHISPER_7         = -1531039,
    SAY_CTHUN_WHISPER_8         = -1531040,



    SPELL_SUMMON_PLAYER         = 20477,

    // Cast periodically on players around the instance
    SPELL_WHISPERINGS_CTHUN_1   = 26195,
    SPELL_WHISPERINGS_CTHUN_2   = 26197,
    SPELL_WHISPERINGS_CTHUN_3   = 26198,
    SPELL_WHISPERINGS_CTHUN_4   = 26258,
    SPELL_WHISPERINGS_CTHUN_5   = 26259,
};

class TwinsIntroDialogue : public DialogueHelper
{
public:
    TwinsIntroDialogue();
    void Start();
    bool StartedOrDone();
    void SetDone();

protected:
    void JustDidDialogueStep(int32 iEntry) override;
private:
    bool m_StartedOrDone;
};

class instance_temple_of_ahnqiraj : public ScriptedInstance
{
public:
    instance_temple_of_ahnqiraj(Map* pMap);

    void Initialize() override;

    bool IsEncounterInProgress() const override;

    void OnCreatureRespawn(Creature* pCreature) override;
    void OnCreatureCreate(Creature* pCreature) override;
    void OnObjectCreate(GameObject* pGo) override;

    void SetData(uint32 uiType, uint32 uiData) override;
    uint32 GetData(uint32 uiType) override;

    bool CheckConditionCriteriaMeet(Player const* player, uint32 map_id, WorldObject const* source, uint32 instance_condition_id) const override;

    void GetRoyalGuardGUIDList(GuidList& lList) { lList = m_lRoyalGuardGUIDList; }

    char const* Save() override { return m_strInstData.c_str(); }
    void Load(char const* chrIn) override;

    void Update(uint32 uiDiff) override;

    bool TwinsDialogueStartedOrDone();

private:
    uint32 m_auiEncounter[MAX_ENCOUNTER];
    std::string m_strInstData;

    uint32 m_uiBugTrioDeathCount;
    GuidList m_lRoyalGuardGUIDList;

    TwinsIntroDialogue m_twinsIntroDialogue;
    DialogueHelper m_twinsDeadDialogue;
    std::vector<ObjectGuid> graspsOfCthun;
    
    void UpdateCThunWhisper(uint32 diff);
    std::vector<std::pair<ObjectGuid, uint32>> cthunWhisperMutes;
    uint32 m_uiCthunWhisperTimer;
    uint32 m_uiCthunPrevWhisperTimer;

    // The following functions, variables etc, are used to handle the C'thun stomach.
    // One might argue if they should be in boss_cthun.cpp instead, but it makes it a whole
    // lot easier to handle this logic if it's handled by the instance script.
public:
    void DoHandleTempleAreaTrigger(uint32 uiTriggerId);
    void HandleStomachTriggers(Player* pPlayer, AreaTriggerEntry const* pAt);
    void AddPlayerToStomach(Unit* p);
    bool PlayerInStomach(Unit* p);
    bool KillPlayersInStomach();

private:
    enum eStomachSpells {
        SPELL_PUNT_UPWARD               = 26224, //knocks up like craaayy everyone in range, maybe too big radius. Only works if thing is targeting player?
        SPELL_EXIT_STOMACH_KNOCKBACK    = 26230, //knocks well back, but must be cast probably an invisible trigger, if not by cthun outside
        
        SPELL_DIGESTIVE_ACID            = 26476, // Must be stacked and removed manually. 
        EXIT_KNOCKBACK_CREATURE         = 15800, // Exit trigger creature used for stomach and cthun knockups/knockbacks
        PUNT_CREATURE                   = 15922, // Trigger for cthuns belly knockup spell
        SPELL_QUAKE                     = 26093, //used for its visual only with SendSpellGo. It deals damage if cast normally
        SPELL_PORT_OUT_STOMACH          = 26648, // Not yet used, was killing c'thun too. Maybe that's intended => a respawn?
    };
    struct StomachTimers {
        uint32 acidDebuff;
        uint32 timeSincePortedFromStomach;
        uint32 timeSincePortedToStomach;
        bool didKnockback;
        StomachTimers() :
            acidDebuff(StomachTimers::ACID_REFRESH_RATE),
            timeSincePortedFromStomach(0),
            timeSincePortedToStomach(0),
            didKnockback(false)
        {}
        static uint32 const PUNT_CAST_TIME = 3000;
        static uint32 const ACID_REFRESH_RATE = 5000;
    };
    using CThunStomachList = std::vector<std::pair<ObjectGuid, StomachTimers>>;
    void UpdateStomachOfCthun(uint32 diff);
    CThunStomachList::iterator PlayerInStomachIter(Unit* unit);
    void TeleportPlayerToCThun(Player* pPlayer);
    void PerformCthunKnockback();

    ObjectGuid puntCreatureGuid;
    uint32 quakeTimer;
    uint32 puntCountdown;

    std::vector<std::pair<ObjectGuid, StomachTimers>> playersInStomach;
};

#endif
