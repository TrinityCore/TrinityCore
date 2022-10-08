/*
 *
 */

#ifndef DEF_STORMWIND_RENDEZVOUS_H
#define DEF_STORMWIND_RENDEZVOUS_H

#include "scriptPCH.h"

/*
 *
 */

struct Coords
{
    float x, y, z, o;
};

static Coords RoweWaypoints[] =
{
    { -9058.07f, 441.32f, 93.06f, 3.84f },
    { -9084.88f, 419.23f, 92.42f, 3.83f }
};

static Coords WindsorWaypoints[] =
{
    { -9050.406250f, 443.974792f, 93.056458f, 0.659825f },
    { -8968.008789f, 509.771759f, 96.350754f, 0.679460f },
    { -8954.638672f, 519.920410f, 96.355453f, 0.680187f },
    { -8933.738281f, 500.683533f, 93.842247f, 5.941573f },
    { -8923.248047f, 496.464294f, 93.858475f, 0.688045f },
    { -8907.830078f, 509.035645f, 93.842529f, 2.163023f },
    { -8927.302734f, 542.173523f, 94.291695f, 0.606364f },
    { -8825.773438f, 623.565918f, 93.838066f, 5.484471f },
    { -8795.209961f, 590.400269f, 97.495560f, 0.644063f },
    { -8769.717773f, 608.193298f, 97.130692f, 5.507248f },
    { -8736.326172f, 574.955811f, 97.385048f, 3.886185f },
    { -8749.043945f, 560.525330f, 97.400307f, 5.502535f },
    { -8730.701172f, 540.466370f, 101.105370f, 5.431850f },
    { -8713.182617f, 519.765442f, 97.185402f, 0.707678f },
    { -8673.321289f, 554.135986f, 97.267708f, 6.174048f },
    { -8651.262695f, 551.696045f, 97.002983f, 5.525308f },
    { -8618.138672f, 518.573425f, 103.123642f, 5.497819f },
    { -8566.013672f, 465.536804f, 104.597160f, 5.481625f },
    { -8548.403320f, 466.680695f, 104.533554f, 5.387382f },
    { -8529.294922f, 443.376495f, 104.917046f, 5.399162f },
    { -8507.087891f, 415.847321f, 108.385857f, 5.371674f },
    { -8486.496094f, 389.750427f, 108.590248f, 5.391308f },
    { -8455.687500f, 351.054321f, 120.885910f, 5.391308f },
    { -8446.392578f, 339.602783f, 121.329506f, 5.359892f }
};

static Coords WindsorEventMove[] =
{
    { -8964.973633f, 512.194519f, 96.355247f, 3.835189f },
    { -8963.196289f, 510.056549f, 96.355240f, 3.835189f },
    { -8961.235352f, 507.696808f, 96.595337f, 3.835189f },
    { -8959.596680f, 505.725403f, 96.595490f, 3.835189f },
    { -8967.410156f, 515.123535f, 96.354881f, 3.835189f },
    { -8968.840820f, 516.844482f, 96.595253f, 3.835189f },
    { -8970.687500f, 519.065796f, 96.595245f, 3.835189f },
    { -8958.585938f, 506.907959f, 96.595634f, 2.294317f },
    { -8960.827148f, 505.079407f, 96.593971f, 2.255047f },
    { -8962.866211f, 503.415009f, 96.591331f, 2.255047f },
    { -8969.562500f, 520.014587f, 96.595673f, 5.388790f },
    { -8971.773438f, 518.239868f, 96.594200f, 5.388790f },
    { -8973.923828f, 516.513611f, 96.590904f, 5.475183f },
    { -8976.549805f, 514.405701f, 96.590057f, 5.388790f },
    { -8506.340820f, 338.364441f, 120.88584f, 6.219385f },
    { -8449.006836f, 337.693451f, 121.32955f, 5.826686f }
};

const Coords WindsorSummon = { -9148.40f, 371.32f, 91.0f, 0.70f };

uint32 MasqueradeDialogSteps[] =
{
    8091, 8090, 8107, 8109, 8119, 8121, 8123, 8133, 8124, 8125, 8132, 8126, 8134, 8127, 8128, 8129, 8130, 8205, 8206,
    8207, 8208, 8210, 8212, 8211, 8214, 8215, 8216, 8218, 8226, 8227, 8219, 8228, 8236, 8235, 8237, 8238, 8239, 8247,
    8246, 8248, 8266, 8249, 8250, 8251
};

enum
{
    QUEST_STORMWIND_RENDEZVOUS      = 6402,
    QUEST_THE_GREAT_MASQUERADE      = 6403,

    NPC_REGINALD_WINDSOR            = 12580,
    NPC_ONYXIA_ELITE_GUARD          = 12739,
    NPC_ANDUIN_WRYNN                = 1747,
    NPC_BOLVAR_FORDRAGON            = 1748,
    NPC_KATRANA_PRESTOR             = 1749,
    NPC_STORMWIND_CITY_GUARD        = 68,
    NPC_STORMWIND_CITY_PATROL       = 1976,
    NPC_MERCUTIO                    = 12581,
    NPC_MARCUS_JONATHAN             = 466,
    NPC_STORMWIND_ROYAL_GUARD       = 1756,
    NPC_LADY_ONYXIA                 = 12756,
    NPC_ROWE                        = 17804,

    FACTION_BOLVAR_COMBAT           = 11,
    FACTION_BOLVAR_NORMAL           = 12,

    GOSSIP_ROWE_COMPLETED           = 9066,
    GOSSIP_ROWE_READY               = 9065,
    GOSSIP_ROWE_BUSY                = 9064,
    GOSSIP_ROWE_NOTHING             = 9063,

    GO_FLARE_OF_JUSTICE             = 181987,

    SAY_SIGNAL_SENT                 = 14389,
    SAY_HISS                        = 8245,
    SAY_WINDSOR1                    = 8091,
    SAY_WINDSOR2                    = 8090,
    SAY_WINDSOR3                    = 8107,
    SAY_WINDSOR4                    = 8109,
    SAY_ONYXIA1                     = 8119,
    SAY_MARCUS1                     = 8121,
    SAY_WINDSOR5                    = 8123,
    SAY_WINDSOR6                    = 8133,
    SAY_MARCUS2                     = 8124,
    SAY_MARCUS3                     = 8125,
    SAY_MARCUS4                     = 8132,
    SAY_WINDSOR7                    = 8126,
    SAY_WINDSOR8                    = 8134,
    SAY_MARCUS5                     = 8127,
    SAY_MARCUS6                     = 8128,
    SAY_MARCUS7                     = 8129,
    SAY_MARCUS8                     = 8130,
    SAY_WINDSOR9                    = 8205,
    SAY_WINDSOR10                   = 8206,
    SAY_WINDSOR11                   = 8207,
    SAY_WINDSOR12                   = 8208,
    SAY_WINDSOR13                   = 8210,
    SAY_BOLVAR1                     = 8212,
    SAY_WINDSOR14                   = 8211,
    SAY_ONYXIA2                     = 8214,
    SAY_ONYXIA3                     = 8215,
    SAY_ONYXIA4                     = 8216,
    SAY_WINDSOR15                   = 8218,
    SAY_WINDSOR16                   = 8226,
    SAY_WINDSOR17                   = 8227,
    SAY_WINDSOR18                   = 8219,
    SAY_WINDSOR19                   = 8228,
    SAY_BOLVAR2                     = 8236,
    SAY_ONYXIA5                     = 8235,
    SAY_BOLVAR3                     = 8237,
    SAY_ONYXIA6                     = 8238,
    SAY_ONYXIA7                     = 8239,
    SAY_WINDSOR20                   = 8247,
    SAY_ONYXIA8                     = 8246,
    SAY_ONYXIA9                     = 8248,
    SAY_BOVLAR4                     = 8266,
    SAY_BOLVAR5                     = 8249,
    SAY_WINDSOR21                   = 8250,
    SAY_WINDSOR22                   = 8251,

    MOUNT_WINDSOR                   = 2410,

    SPELL_GREATER_INVISIBILITY      = 16380,
    SPELL_INVISIBILITY              = 23452,
    SPELL_WINDSOR_DEATH             = 20465,
    SPELL_WINSOR_READ_TABLETS       = 20358,
    SPELL_PRESTOR_DESPAWNS          = 20466,
    SPELL_WINDSOR_DISMISS_HORSE     = 20000
};

struct npc_reginald_windsorAI : ScriptedAI
{
    explicit npc_reginald_windsorAI(Creature* pCreature);

    uint32 Timer;
    uint32 Tick;
    uint64 GuardsGUIDs[30];
    uint64 DragsGUIDs[10];
    uint64 playerGUID;
    bool Begin;
    bool SummonHorse;
    bool ShooHorse;
    bool BeginQuest;
    bool NeedCheck;
    bool GuardNeed[6];
    bool PhaseFinale;
    bool TheEnd;
    bool CombatJustEnded;
    bool GreetPlayer;
    bool QuestAccepted;
    bool m_bRoweKnows;
    uint32 FinalTimer;
    uint32 GuardTimer[6];
    uint32 m_uiDespawnTimer;
    ObjectGuid m_squireRoweGuid;

    Player* GetPlayer() const;
    Creature* GetGuard(uint8 num) const;

    void Reset() override {}
    void ResetCreature() override;
    void JustDied(Unit* pKiller) override;
    void PokeRowe();
    void CompleteQuest();
    void EndScene();
    void UpdateAI_corpse(uint32 const uiDiff) override;
    void MoveInLineOfSight(Unit* Victim) override;
    void SpellHit(Unit* /*pCaster*/, SpellEntry const* pSpellEntry) override;
    void UpdateAI(uint32 const uiDiff) override;
};

/*
 *
 */

struct npc_squire_roweAI : ScriptedAI
{
    explicit npc_squire_roweAI(Creature* pCreature);

    uint32 m_uiTimer;
    uint32 m_uiStep;
    bool m_bEventProcessed;
    bool m_bWindsorUp;
    ObjectGuid m_playerGuid;

    void Reset() override {}
    void ResetCreature() override;
    void MovementInform(uint32 uiType, uint32 uiPointId) override;
    void UpdateAI(uint32 const uiDiff) override;
};

#endif
