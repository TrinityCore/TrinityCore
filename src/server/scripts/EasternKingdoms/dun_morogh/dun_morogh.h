#ifndef DEF_DUNMOROGH_H
#define DEF_DUNMOROGH_H

#include "scriptPCH.h"

enum EventData
{
    NPC_ANGUS               = 10610,
    NPC_SHORTY              = 10611,
    NPC_RIFLEMAN_WHEELER    = 10803,
    NPC_RIFLEMAN_MIDDLECAMP = 10804,
    NPC_SPOTTER_KLEMMY      = 10805,

    NPC_DUMMY               = 11875,
    NPC_ADVANCED_DUMMY      = 12385,

    NPC_EVENT_WATCHER       = 20113,

    SPELL_TARGET_DUMMY_1    = 18634,
    SPELL_TARGET_DUMMY_2    = 18907,
    SPELL_TARGET_DUMMY_3    = 19723,
    SPELL_MORTAR_ANIMATE    = 18655,
    SPELL_MORTAR_SHOT       = 16786,

    SPELL_SHOOT_1 = 16572,
    SPELL_SHOOT_2 = 16767,
    SPELL_SHOOT_3 = 16768,
    SPELL_SHOOT_4 = 16772,
    SPELL_SHOOT_5 = 16775,
    SPELL_SHOOT_6 = 16776,
    SPELL_SHOOT_7 = 16777,
    SPELL_SHOOT_8 = 16778,
    SPELL_SHOOT_9 = 16779,
    SPELL_SHOOT_10 = 16780,

    EPOS_ANGUS = 2,
    EPOS_SHORTY = 4,
    EPOS_WHEELER = 1,
    EPOS_MIDDLECAMP = 1,
    EPOS_KLEMMY = 5,

    SOUND_MORTAR_TEAM_1 = 6251,
    SOUND_MORTAR_TEAM_2 = 6252,
    SOUND_MORTAR_TEAM_3 = 6254,
    SOUND_MORTAR_TEAM_4 = 6255,
    SOUND_MORTAR_TEAM_5 = 6256,
    SOUND_MORTAR_TEAM_6 = 6258,

    SOUND_RIFLEMAN_1 = 6246,
    SOUND_RIFLEMAN_2 = 6247,
    SOUND_RIFLEMAN_3 = 6248,
    SOUND_RIFLEMAN_4 = 6249,
    SOUND_RIFLEMAN_5 = 6250,

    SHOOT1EMOTE1 = 6107,
    SHOOT1EMOTE2 = 6140,
    SHOOT2EMOTE1 = 6106,
    SHOOT2EMOTE2 = 6141,
    SHOOT3EMOTE1 = 6118,
    SHOOT3EMOTE2 = 6142,
    SHOOT4EMOTE1 = 6120,
    SHOOT5EMOTE1 = 6121,
    SHOOT6EMOTE1 = 6124,
    SHOOT7EMOTE1 = 6122,
    SHOOT7EMOTE2 = 6123,
    SHOOT8EMOTE1 = 6137,
    SHOOT9EMOTE1 = 6136,
    SHOOT10EMOTE1 = 6138
};

static float const AngusMove[3][3] =
{
    { -6008.86f,  -203.437f, 407.109f },
    { -6026.91f,  -229.77f,  413.516f },
    { -6031.005f, -230.541f, 414.352f }
};

static float const ShortyMove[5][3] =
{
    { -6007.53f,  -202.155f, 407.448f },
    { -6024.688f, -229.102f, 413.319f },
    { -6030.384f, -235.56f,  414.562f },
    { -6036.222f, -234.658f, 415.189f },
    { -6031.382f, -228.204f, 414.394f }
};

static float const WheelerMove[2][3] =
{
    { -6009.09f, -198.498f, 406.676f },
    { -6031.93f, -221.088f, 413.134f }
};

static float const MiddlecampMove[2][3] =
{
    { -6011.36f, -198.926f, 406.795f },
    { -6034.14f, -223.333f, 413.481f }
};

static float const KlemmyMove[6][3] =
{
    { -6007.24f,  -200.258f, 406.765f },
    { -6011.1f,   -197.1f,   406.759f },
    { -6015.579f, -180.775f, 408.181f },
    { -6036.183f, -185.032f, 420.112f },
    { -6052.63f,  -198.484f, 421.852f },
    { -6065.057f, -203.547f, 423.924f }
};

static float const KlemmySubMove[6][3] =
{
    { -6077.19f,  -213.034f, 423.954f },
    { -6069.06f,  -213.475f, 422.496f },
    { -6066.45f,  -206.174f, 423.246f },
    { -6059.34f,  -209.405f, 421.426f },
    { -6055.81f,  -224.631f, 419.216f },
    { -6041.05f,  -223.555f, 415.293f }
};

/*
* Angus (Mortar Team event support)
*/

struct npc_angusAI : ScriptedAI
{
    explicit npc_angusAI(Creature* pCreature);

    bool m_bEventProcessed;
    bool m_bActionPosReached;
    bool m_bReturningHome;
    bool m_bSubEventProcessed;
    uint32 m_uiDoTimer;
    uint8 m_uiAction;

    void Reset() override;
    void StartEvent();
    void FinishEvent();
    void StartSubEvent();
    void MovementInform(uint32 uiType, uint32 uiPointId) override;
    void UpdateAI(uint32 const uiDiff) override;
};

/*
* Rifleman Middlecamp (Mortar Team event support)
*/

struct npc_rifleman_middlecampAI : ScriptedAI
{
    explicit npc_rifleman_middlecampAI(Creature* pCreature);

    bool m_bEventProcessed;
    bool m_bActionPosReached;
    bool m_bSubEventProcessed;
    bool m_bReturningHome;
    uint32 m_uiDoTimer;
    uint8 m_uiAction;

    void Reset() override;
    void StartEvent();
    void FinishEvent();
    void StartSubEvent();
    void MovementInform(uint32 uiType, uint32 uiPointId) override;
    void UpdateAI(uint32 const uiDiff) override;
};

/*
* Rifleman Wheeler (Mortar Team event support)
*/

struct npc_rifleman_wheelerAI : ScriptedAI
{
    explicit npc_rifleman_wheelerAI(Creature* pCreature);

    bool m_bEventProcessed;
    bool m_bActionPosReached;
    bool m_bSubEventProcessed;
    bool m_bReturningHome;
    uint32 m_uiDoTimer;
    uint8 m_uiAction;

    void Reset() override;
    void StartEvent();
    void FinishEvent();
    void StartSubEvent();
    void PokeMortarGuys() const;
    void MovementInform(uint32 uiType, uint32 uiPointId) override;
    void UpdateAI(uint32 const uiDiff) override;
};

/*
* Shorty (Mortar Team event support)
*/

struct npc_shortyAI : ScriptedAI
{
    explicit npc_shortyAI(Creature* pCreature);

    bool m_bEventProcessed;
    bool m_bActionPosReached;
    bool m_bReturningHome;
    bool m_bSubEventProcessed;
    uint32 m_uiDoTimer;
    uint8 m_uiAction;

    void Reset() override;
    void StartEvent();
    void FinishEvent();
    void StartSubEvent();
    void PokeRiflemen() const;
    void MovementInform(uint32 uiType, uint32 uiPointId) override;
    void UpdateAI(uint32 const uiDiff) override;
};

/*
* Spotter Klemmy (Mortar Team event support)
*/

struct npc_spotter_klemmyAI : ScriptedAI
{
    explicit npc_spotter_klemmyAI(Creature* pCreature);

    bool m_bEventProcessed;
    bool m_bActionPosReached;
    bool m_bReturningHome;
    bool m_bSubEventProcessed;
    bool m_bSubMoveProcessed;
    uint32 m_uiDoTimer;
    uint8 m_uiAction;
    uint16 m_uiSubCount;

    void Reset() override;
    void StartEvent();
    void FinishEvent();
    void StartSubEvent();
    void MovementInform(uint32 uiType, uint32 uiPointId) override;
    void UpdateAI(uint32 const uiDiff) override;
};

/*
* Mortar Team Watcher (Mortar Team event support)
*/

struct npc_mortar_team_watcherAI : ScriptedAI
{
    explicit npc_mortar_team_watcherAI(Creature* pCreature);

    bool m_bEventStartSent;
    bool m_bEventFinishSent;
    uint32 m_uiEventTimer;

    void Reset() override;
    void PokeAll(bool start = true);
    void UpdateAI(uint32 const uiDiff) override;
};

/*
* Mortar Team Target Dummy (Mortar Team event support)
*/

struct npc_mortar_team_target_dummyAI : ScriptedAI
{
    explicit npc_mortar_team_target_dummyAI(Creature* pCreature);

    void Reset() override;
    void SpellHit(Unit* /*pCaster*/, SpellEntry const* pSpell) override;
    void UpdateAI(uint32 const uiDiff) override;
};

#endif
