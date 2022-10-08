#include "siege_of_orgrimmar.hpp"
#include "GameObjectAI.h"
#include "ObjectMgr.h"
#include "SceneHelper.h"

#define MAX_SHA_POWER 100
#define SHA_POWER_PERIODIC 600

#define DEFAULT_PRIDE_INCREASE 5

#define MAX_LINGERING_CORRUPTIONS 10

#define GIFT_OF_TITANS_COUNT_10 2
#define GIFT_OF_TITANS_COUNT_25 5
#define MARK_OF_ARROGANCE_COUNT_10 2
#define MARK_OF_ARROGANCE_COUNT_25 5

enum ScriptedTextNorushen
{
    SAY_GIFT_OF_THE_TITANS  = 0,
    SAY_FINAL_GIFT          = 1,
    SAY_NORUSHEN_INTRO_1    = 2,
    SAY_NORUSHEN_INTRO_2    = 3,
};

#define SOUND_DEATH 38897

enum ScriptedTextShaOfPride
{
    SAY_AGGRO               = 0,
    SAY_DEATH               = 1,
    SAY_UNLEASHED           = 2,
    SAY_INTRO               = 3,
    SAY_KILL                = 4,
    SAY_SELF_REFLECTION     = 5,
    SAY_SWELLING_PRIDE      = 6,
    SAY_CORRUPTED_PRISON    = 7,
};

enum ScriptedTextJaina
{
    SAY_JAINA_INTRO_1   = 0,
    SAY_JAINA_INTRO_2   = 1,
    SAY_JAINA_INTRO_3   = 2,
    SAY_JAINA_INTRO_4   = 3,
    SAY_JAINA_INTRO_5   = 4,
};

enum ScriptedTextLorthemar
{
    SAY_LORTHEMAR_INTRO_1 = 0,
    SAY_LORTHEMAR_INTRO_2 = 1,
    SAY_LORTHEMAR_INTRO_3 = 2,
    SAY_LORTHEMAR_INTRO_4 = 3,
    SAY_LORTHEMAR_INTRO_5 = 4,
};

Position npcAfterShaOfPridePos[7] =
{
    { 750.75f, 1131.48f, 356.08f, 1.73f}, // Jaina
    { 740.28f, 1129.70f, 356.08f, 1.73f}, // Lor'themar
    { 744.46f, 1134.51f, 356.08f, 1.73f}, // Gorehowl
    { 785.54f, 1171.07f, 356.08f, 4.14f}, // Portal to Orgrimmar (alliance)
    { 782.49f, 1165.84f, 356.08f, 0.82f}, // Jaina near portal
    { 688.79f, 1151.24f, 356.08f, 5.81f}, // Portal to Orgrimmar (horde)
    { 695.27f, 1146.95f, 356.08f, 2.62f}  // Lor'themar near portal
};

Position galakrasPlayersPos[3] =
{
    { 1366.50f, -5416.54f, 10.47f, 1.59f}, // alliance intro position
    { 1767.58f, -5265.74f, 6.97f, 2.90f},  // horde intro position
    { 1440.49f, -5015.87f, 12.11f, 1.67f}  // position at the docks
};


enum Spells
{
    // Intro

    SPELL_SHA_VORTEX                = 146024,

    // Lingering Corruption
    SPELL_CORRUPTED_TOUCH           = 149207,
    SPELL_CORRUPTED_TOUCH_DMG       = 149209,

    // Boss

    SPELL_ZERO_POWER                = 72242,

    SPELL_BERSERK                   = 26662,

    SPELL_PRIDE                     = 144343,

    SPELL_SWELLING_PRIDE            = 144400,
    SPELL_BURSTING_PRIDE            = 144910, // 25-49 pride
    SPELL_BURSTING_PRIDE_DMG        = 144911,
    SPELL_PROJECTION_1              = 144952, // 50-74 pride
    SPELL_PROJECTION_2              = 145526, // explode visual (without dmg)
    SPELL_PROJECTION_MISSILE        = 145066, // triggers non-existed spell 145324
    SPELL_PROJECTION_DMG            = 145320,
    SPELL_PROJECTION_MARK           = 146822,
    SPELL_AURA_OF_PRIDE             = 146817, // 75-99 pride
    SPELL_AURA_OF_PRIDE_DMG         = 146818,
    SPELL_OVERCOME_1                = 144843, // buff
    SPELL_OVERCOME_2                = 144863, // debuff

    SPELL_GIFT_OF_THE_TITANS        = 146595, // casted by norushen
    SPELL_GIFT_OF_THE_TITANS_1      = 144359, // 1 player
    SPELL_GIFT_OF_THE_TITANS_2      = 146594, // 2 players
    SPELL_GIFT_OF_THE_TITANS_AOE    = 144363, // search 8 yards
    SPELL_POWER_OF_THE_TITANS       = 144364,
    SPELL_FINAL_GIFT                = 144854,

    SPELL_MARK_OF_ARROGANCE         = 144351,

    SPELL_WOUNDED_PRIDE             = 144358,

    SPELL_SELF_REFLECTION           = 144800,
    SPELL_SELF_REFLECTION_SPAWN     = 144784,
    SPELL_SELF_REFLECTION_DMG       = 144788,

    SPELL_REACHING_ATTACK           = 144774,

    SPELL_UNLEASHED                 = 144832,
    SPELL_UNLEASHED_DMG             = 144836,

    SPELL_CORRUPTED_PRISON_1        = 144574,
    SPELL_CORRUPTED_PRISON_2        = 144636,
    SPELL_CORRUPTED_PRISON_3        = 144683,
    SPELL_CORRUPTED_PRISON_4        = 144684,
    SPELL_CORRUPTED_PRISON_DMG      = 144615, // knockback players
    SPELL_CORRUPTED_PRISON_OBJECT_1 = 144550, // ?
    SPELL_CORRUPTED_PRISON_OBJECT_2 = 144552, // ?
    SPELL_CORRUPTED_PRISON_OBJECT_3 = 144559, // ?

    // heroic spells
    SPELL_BANISHMENT_AOE_1          = 146823, // targets player
    SPELL_BANISHMENT_AOE_2          = 147028, // ?
    SPELL_BANISHMENT_TELEPORT       = 148705,
    SPELL_BANISHMENT                = 145215,
    SPELL_BANISHMENT_CLONE          = 147365, // a wrong spell, I cannot find the correct one
    SPELL_BANISHMENT_AREATRIGGERS   = 145217, // creates triggers
    SPELL_BANISHMENT_SCALE          = 145684,
    SPELL_BANISHMENT_STUN           = 146623,
    SPELL_CORRUPTION_PERIODIC_DMG   = 145219,

    SPELL_ORB_OF_LIGHT_AREATRIGGER  = 145299,
    SPELL_ORB_OF_LIGHT_DEBUFF       = 145345,
    SPELL_ORB_OF_LIGHT_DUMMY        = 145705, // ?
    SPELL_ORB_OF_LIGHT_HEAL         = 149008,

    SPELL_ETHEREAL_CORRUPTION       = 149027,
    SPELL_ETHEREAL_CORRUPTION_DMG   = 149031,

    // Manifestation of Pride
    SPELL_MANIFESTATION_SPAWN       = 144778,
    SPELL_MOCKING_BLAST             = 144379,
    SPELL_LAST_WORD                 = 144370,

    SPELL_RIFT_OF_CORRUPTION_VISUAL_1   = 147186,
    SPELL_RIFT_OF_CORRUPTION_VISUAL_2   = 147210,
    SPELL_RIFT_OF_CORRUPTION_VISUAL_3   = 147211,
    SPELL_RIFT_OF_CORRUPTION_CLOSE      = 147199,
    SPELL_UNSTABLE_CORRUPTION_PERIODIC  = 147183,     ///< Summon NPC_RIFT_OF_CORRUPTION
    SPELL_UNSTABLE_CORRUPTION_PERIODIC_2    = 147389,
    SPELL_UNSTABLE_CORRUPTION_MISSILE   = 147391,
    SPELL_UNSTABLE_CORRUPTION_DMG       = 147198,
    SPELL_COLLAPSING_RIFT               = 147388,
    SPELL_WEAKENED_RESOLVE              = 147207,
};

enum Adds
{
    NPC_MANIFESTATION_OF_PRIDE  = 71946,
    NPC_REFLECTION              = 72172,
    NPC_SHADOW_PRISON           = 72017,
    NPC_SHA_VORTEX              = 72239,
    NPC_RIFT_OF_CORRUPTION      = 72846,
    NPC_CORRUPTED_FRAGMENT      = 72569,
    NPC_ETHEREAL_CORRUPTION     = 73972
};

enum Events
{
    EVENT_SPAWN_SHA_OF_PRIDE     = 1,
    EVENT_GIFT_OF_THE_TITANS,
    EVENT_FINAL_GIFT,

    EVENT_BERSERK,

    EVENT_REACHING_ATTACK,
    EVENT_MARK_OF_ARROGANCE,
    EVENT_SHADOW_PRISON,
    EVENT_SWELLING_PRIDE,
    EVENT_WOUNDED_PRIDE,
    EVENT_MANIFESTATION,
    EVENT_SELF_REFLECTION,
    EVENT_BANISHMENT,

    EVENT_REFLECTION_DMG,

    EVENT_GET_READY,
    EVENT_MOVE,
    EVENT_MOCKING_BLAST,
};

enum Timers
{
    TIMER_BERSERK                   = 10 * MINUTE * IN_MILLISECONDS,
    TIMER_BANISHMENT    = 37500
};

enum Actions
{
    ACTION_LINGERING_CORRUPTION_DIED    = 1,
    ACTION_UNLEASHED,
    ACTION_RESET,
    ACTION_COMPLETED,
    ACTION_COMBAT_START,
};

enum eData
{
    DATA_TRAPPED_PLAYER = 1,
    DATA_TRAP_USED,
    DATA_TRAP_DEACTIVATED,
    DATA_BANISHED_PLAYER,
    DATA_BANISHED_PLAYER_REMOVE
};

enum PrideLevels
{
    PRIDE_MAX   = 100,
};

const uint32 prisonSpells[MAX_SHADOW_PRISONS] =
{
    SPELL_CORRUPTED_PRISON_1,
    SPELL_CORRUPTED_PRISON_2,
    SPELL_CORRUPTED_PRISON_3,
    SPELL_CORRUPTED_PRISON_4
};

const Position shaVortexPos = {747.83f, 1112.96f, 356.08f, 4.96f};

const Position manifestationPos10Man1 = { 735.34f, 1173.69f, 356.08f, 4.88f };    ///< Spawn on 10-Man Normal & Heroic
const Position manifestationPos25Man1 = { 809.4360f, 1126.069f, 356.08f, 3.34f }; ///< Spawn-1 on 25-Man Normal & Heroic
const Position manifestationPos25Man2 = { 686.6197f, 1099.645f, 356.08f, 0.21f }; ///< Spawn-2 on 25-Man Normal & Heroic

const Position prisonPos[MAX_SHADOW_PRISONS] =
{
    {764.30f, 1137.92f, 356.08f, 4.17f},
    {772.71f, 1096.25f, 356.08f, 2.53f},
    {731.98f, 1087.30f, 356.08f, 0.93f},
    {722.91f, 1128.89f, 356.08f, 5.65f}
};

enum BanishmentSizes : int
{
    MAN_10 = 1,
    MAN_25 = 3
};

const static std::vector<Position> s_RiftOfCorruptionPos =
{
    {756.455688f, 1070.445679f, 356.08f, 0.214239f},
    {788.021362f, 1083.490234f, 356.08f, 0.635736f},
    {790.660400f, 1116.040039f, 356.08f, 1.716968f},
    {778.604553f, 1155.088501f, 356.08f, 2.217879f},
    {743.775757f, 1155.686401f, 356.08f, 3.354089f},
    {706.478577f, 1142.788574f, 356.08f, 4.007716f},
    {705.524841f, 1106.764282f, 356.08f, 4.829329f},
    {719.434448f, 1072.366943f, 356.08f, 5.452409f}
};

const static std::vector<Position> s_MazeOuterPos =
{
    { 790.22f, 1178.94f, 356.072f, 4.87f },
    { 813.41f, 1070.07f, 356.072f, 1.71f },
    { 705.09f, 1046.00f, 356.072f, 1.67f },
    { 681.32f, 1155.88f, 356.072f, 0.15f }
};

#define MAX_MAZE_LINES 4
const static std::vector<Position> s_MazeLinesPos[MAX_MAZE_LINES] =
{
    {
        { 707.41f, 1110.85f, 356.072f, 1.69f},
        { 701.38f, 1142.33f, 356.072f, 1.79f },
        { 733.47f, 1150.15f, 356.072f, 0.16f },
        { 731.86f, 1157.54f, 356.072f, 3.06f },
        { 691.11f, 1148.89f, 356.072f, 4.93f },
        { 699.57f, 1109.44f, 356.072f, 0.07f }
    },
    {
        { 702.20f, 1096.29f, 356.072f, 4.91f },
        { 711.16f, 1056.51f, 356.072f, 4.97f },
        { 750.82f, 1064.71f, 356.072f, 3.93f },
        { 748.95f, 1072.20f, 356.072f, 3.29f },
        { 717.15f, 1066.25f, 356.072f, 3.35f },
        { 709.54f, 1097.71f, 356.072f, 1.72f }
    },
    {
        { 762.17f, 1074.80f, 356.072f, 0.18f },
        { 763.56f, 1067.35f, 356.072f, 0.18f },
        { 804.61f, 1076.12f, 356.072f, 0.20f },
        { 795.80f, 1115.63f, 356.072f, 1.72f },
        { 788.24f, 1113.43f, 356.072f, 3.50f },
        { 794.56f, 1082.61f, 356.072f, 3.03f }
    },
    {
        { 786.17f, 1128.11f, 356.072f, 1.76f },
        { 794.04f, 1128.93f, 356.072f, 1.76f },
        { 784.82f, 1169.42f, 356.072f, 3.23f },
        { 746.28f, 1161.56f, 356.072f, 4.72f },
        { 747.09f, 1153.45f, 356.072f, 6.12f },
        { 778.13f, 1160.16f, 356.072f, 4.85f }
    }
};

const static std::vector<Position> s_MazeInnerPos =
{
    { 718.79f, 1110.09f, 356.072f, 0.21f },
    { 732.73f, 1113.37f, 356.072f, 0.22f },
    { 740.80f, 1125.62f, 356.072f, 1.16f },
    { 738.16f, 1140.65f, 356.072f, 4.76f },
    { 744.55f, 1142.53f, 356.072f, 4.88f },
    { 747.68f, 1128.62f, 356.312f, 5.16f },
    { 762.27f, 1119.56f, 356.072f, 5.72f },
    { 776.37f, 1122.79f, 356.072f, 0.25f },
    { 777.17f, 1116.58f, 356.072f, 3.34f },
    { 762.07f, 1113.13f, 356.142f, 3.36f },
    { 754.31f, 1100.38f, 356.072f, 4.90f },
    { 757.35f, 1085.07f, 356.072f, 4.94f },
    { 750.99f, 1084.61f, 356.072f, 2.49f },
    { 747.56f, 1099.66f, 356.072f, 1.76f },
    { 734.32f, 1106.83f, 356.312f, 2.72f },
    { 719.45f, 1104.09f, 356.072f, 3.33f }
};

#define ORB_OF_LIGHT_COUNT 16
const Position OrbOfLightPos[ORB_OF_LIGHT_COUNT] =
{
    { 707.33f, 1049.58f, 356.072f, 0.22f },
    { 810.36f, 1072.77f, 356.085f, 0.30f },
    { 788.93f, 1177.47f, 356.072f, 3.25f },
    { 684.71f, 1152.18f, 356.072f, 4.98f },
    { 739.01f, 1153.83f, 356.072f, 5.15f },
    { 775.52f, 1155.16f, 356.072f, 4.94f },
    { 790.83f, 1121.30f, 356.072f, 4.38f },
    { 791.18f, 1084.94f, 356.072f, 3.34f },
    { 756.84f, 1070.19f, 356.072f, 3.43f },
    { 720.37f, 1069.57f, 356.072f, 2.11f },
    { 705.69f, 1103.52f, 356.072f, 1.73f },
    { 704.35f, 1139.94f, 356.072f, 0.43f },
    { 733.48f, 1121.81f, 356.072f, 4.38f },
    { 739.00f, 1099.27f, 356.072f, 6.21f },
    { 761.87f, 1105.65f, 356.072f, 1.31f },
    { 756.88f, 1127.60f, 356.072f, 2.59f }
};

#define ETHEREAL_CORRUPTION_COUNT 7
const Position s_EtherealCorruptions[ETHEREAL_CORRUPTION_COUNT] =
{
    { 721.04f, 1070.79f, 356.072f, 0.20f },
    { 790.54f, 1084.72f, 356.072f, 1.98f },
    { 775.54f, 1154.06f, 356.072f, 4.04f },
    { 766.33f, 1108.42f, 356.072f, 0.51f },
    { 733.85f, 1121.66f, 356.072f, 1.47f },
    { 749.05f, 1139.95f, 356.072f, 4.97f },
    { 762.96f, 1123.65f, 356.072f, 2.78f }
};

constexpr uint32 EtherealCorruptionsPath[ETHEREAL_CORRUPTION_COUNT] = { 739720, 739721, 739722, 739723, 739724, 739725, 739726 };

enum ePhaseMasks
{
    DEFAULT         = 1,
    BANISHMENT_ALL  = 65534
};

inline void TryIncreasePrideOnUnit(Unit* target, int32 prideToAdd)
{
    int32 currentPride = target->GetPower(POWER_ALTERNATE_POWER);
    if (currentPride >= PRIDE_MAX)
        return;

    if (target->HasAura(SPELL_GIFT_OF_THE_TITANS_1) ||
        target->HasAura(SPELL_GIFT_OF_THE_TITANS_2))
        return;

    int32 newPride = std::min(currentPride + prideToAdd, (int)PRIDE_MAX);

    target->SetPower(POWER_ALTERNATE_POWER, newPride);
}

Creature* GetShaOfPride(WorldObject* p_Searcher)
{
    if (InstanceScript* l_Instance = p_Searcher->GetInstanceScript())
        return l_Instance->instance->GetCreature(l_Instance->GetObjectGuid(DATA_SHA_OF_PRIDE));

    return nullptr;
}

/// Check if players can be damaged by maze walls
// todo fix this
bool IsPlayerInMaze(Player* p_Player)
{
    /*if (!Trinity::IsPositionInZone(*p_Player, s_MazeOuterPos))
        return false;

    constexpr float l_CircleRange = 9.0f;

    for (uint8 i = 0; i < MAX_SHADOW_PRISONS; ++i)
        if (p_Player->GetExactDist2d(&prisonPos[i]) <= l_CircleRange)
            return false;

    for (uint8 i = 0; i < MAX_MAZE_LINES; ++i)
        if (Trinity::IsPositionInZone(*p_Player, s_MazeLinesPos[i]))
            return false;

    if (Trinity::IsPositionInZone(*p_Player, s_MazeInnerPos))
        return false;*/

    //return true;
    return false;
}

class PrisonData
{
    public:

        PrisonData()
        {
            Clear();
        }

        bool HasPlayer() const
        {
            return m_TargetGuid != ObjectGuid::Empty;
        }

        bool HasTraps() const
        {
            return !m_TrapGuids.empty();
        }

        bool RemoveTrapGuid(ObjectGuid trapGuid)
        {
            std::set<ObjectGuid>::iterator itr = m_TrapGuids.find(trapGuid);
            if (itr == m_TrapGuids.end())
                return false;

            m_TrapGuids.erase(itr);

            return true;
        }

        void SetTargetGuid(ObjectGuid targetGuid)
        {
            m_TargetGuid = targetGuid;
        }

        ObjectGuid GetTargetGuid() const
        {
            return m_TargetGuid;
        }

        void SetPrisonGuid(ObjectGuid prisonGuid)
        {
            m_PrisonGuid = prisonGuid;
        }

        ObjectGuid GetPrisonGuid() const
        {
            return m_PrisonGuid;
        }

        void SetPrison(uint8 prison)
        {
            m_Prison = prison;
        }

        uint8 GetPrison() const
        {
            return m_Prison;
        }

        void SetSpellId(uint32 spellId)
        {
            m_SpellId = spellId;
        }

        uint32 GetSpellId() const
        {
            return m_SpellId;
        }

        void AddTrapGuid(ObjectGuid trapGuid)
        {
            m_TrapGuids.insert(trapGuid);
        }

        std::set<ObjectGuid>& GetTrapGuids()
        {
            return m_TrapGuids;
        }

        void Clear()
        {
            m_TargetGuid = ObjectGuid::Empty;
            m_PrisonGuid = ObjectGuid::Empty;
            m_Prison = 0;
            m_TrapGuids.clear();
            m_SpellId = 0;
        }

    private:

    private:

        ObjectGuid m_TargetGuid;
        ObjectGuid m_PrisonGuid;
        uint8 m_Prison;
        std::set<ObjectGuid> m_TrapGuids;
        uint32 m_SpellId;
};

class PrisonController
{
    public:

        PrisonController(InstanceScript* pInstance)
        {
            m_pInstance = pInstance;
        }

        bool CatchPlayer(Unit* catcher, ObjectGuid playerGuid)
        {
            if (!HasFreePrison())
                return false;

            Player* player = ObjectAccessor::FindPlayer(playerGuid);
            if (!player)
                return false;

            uint8 prison = GetFreePrisonIndex();

            uint32 spellId = GetSpellIdForPrison(prison);

            if (Creature* pPrisonTrigger = catcher->SummonCreature(NPC_SHADOW_PRISON, prisonPos[prison]))
            {
                pPrisonTrigger->CastSpell(pPrisonTrigger, SPELL_CORRUPTED_PRISON_DMG, true);
                pPrisonTrigger->DespawnOrUnsummon(1000);
            }

            player->InterruptNonMeleeSpells(false);
            catcher->CastSpell(player, spellId, true);

            ActivatePrisonAndTraps(prison, playerGuid, spellId);

            return true;
        }

        void TrapUsed(ObjectGuid trapGuid)
        {
            if (PrisonData* prisonData = GetPrisonDataByTrap(trapGuid))
            {
                if (prisonData->RemoveTrapGuid(trapGuid))
                {
                    if (!prisonData->HasTraps())
                        DeactivatePrisonAndTraps(prisonData->GetPrison());
                }
            }
        }

        bool HasFreePrison() const
        {
            for (uint8 i = 0; i < MAX_SHADOW_PRISONS; ++i)
            {
                if (!m_Prisons[i].HasPlayer())
                    return true;
            }

            return false;
        }

        void DeactivateAllPrisons()
        {
            for (uint8 i = 0; i < MAX_SHADOW_PRISONS; ++i)
            {
                DeactivatePrisonAndTraps(i);
            }
        }

        void FreePlayer(ObjectGuid playerGuid)
        {
            if (PrisonData* prisonData = GetPrisonDataByPlayer(playerGuid))
            {
                DeactivatePrisonAndTraps(prisonData->GetPrison());
            }
        }

    public:

        static uint32 GetSpellIdForPrisonTrapEntry(uint32 entry)
        {
            switch (entry)
            {
                case GO_WEST_SHADOW_PRISON_A:
                case GO_WEST_SHADOW_PRISON_B:
                case GO_WEST_SHADOW_PRISON_C:
                    return SPELL_CORRUPTED_PRISON_1;
                case GO_NORTH_SHADOW_PRISON_A:
                case GO_NORTH_SHADOW_PRISON_B:
                case GO_NORTH_SHADOW_PRISON_C:
                    return SPELL_CORRUPTED_PRISON_2;
                case GO_EAST_SHADOW_PRISON_A:
                case GO_EAST_SHADOW_PRISON_B:
                case GO_EAST_SHADOW_PRISON_C:
                    return SPELL_CORRUPTED_PRISON_3;
                case GO_SOUTH_SHADOW_PRISON_A:
                case GO_SOUTH_SHADOW_PRISON_B:
                case GO_SOUTH_SHADOW_PRISON_C:
                    return SPELL_CORRUPTED_PRISON_4;
            }

            return 0;
        }

    private:

        GameObject* GetPrison(uint8 prison)
        {
            if (!m_pInstance)
                return NULL;

            switch (prison)
            {
                case SHADOW_PRISON_WEST: return m_pInstance->instance->GetGameObject(m_pInstance->GetObjectGuid(DATA_WEST_SHADOW_PRISON));
                case SHADOW_PRISON_NORTH: return m_pInstance->instance->GetGameObject(m_pInstance->GetObjectGuid(DATA_NORTH_SHADOW_PRISON));
                case SHADOW_PRISON_EAST: return m_pInstance->instance->GetGameObject(m_pInstance->GetObjectGuid(DATA_EAST_SHADOW_PRISON));
                case SHADOW_PRISON_SOUTH: return m_pInstance->instance->GetGameObject(m_pInstance->GetObjectGuid(DATA_SOUTH_SHADOW_PRISON));
            }

            return NULL;
        }

        GameObject* GetPrisonTrap(uint8 prison, uint8 prisonTrap)
        {
            switch (prison)
            {
                case SHADOW_PRISON_WEST:
                    switch (prisonTrap)
                    {
                        case SHADOW_PRISON_TRAP_A: return m_pInstance->instance->GetGameObject(m_pInstance->GetObjectGuid(DATA_WEST_SHADOW_PRISON_A));
                        case SHADOW_PRISON_TRAP_B: return m_pInstance->instance->GetGameObject(m_pInstance->GetObjectGuid(DATA_WEST_SHADOW_PRISON_B));
                        case SHADOW_PRISON_TRAP_C: return m_pInstance->instance->GetGameObject(m_pInstance->GetObjectGuid(DATA_WEST_SHADOW_PRISON_C));
                    }
                    break;
                case SHADOW_PRISON_NORTH:
                    switch (prisonTrap)
                    {
                        case SHADOW_PRISON_TRAP_A: return m_pInstance->instance->GetGameObject(m_pInstance->GetObjectGuid(DATA_NORTH_SHADOW_PRISON_A));
                        case SHADOW_PRISON_TRAP_B: return m_pInstance->instance->GetGameObject(m_pInstance->GetObjectGuid(DATA_NORTH_SHADOW_PRISON_B));
                        case SHADOW_PRISON_TRAP_C: return m_pInstance->instance->GetGameObject(m_pInstance->GetObjectGuid(DATA_NORTH_SHADOW_PRISON_C));
                    }
                    break;
                case SHADOW_PRISON_EAST:
                    switch (prisonTrap)
                    {
                        case SHADOW_PRISON_TRAP_A: return m_pInstance->instance->GetGameObject(m_pInstance->GetObjectGuid(DATA_EAST_SHADOW_PRISON_A));
                        case SHADOW_PRISON_TRAP_B: return m_pInstance->instance->GetGameObject(m_pInstance->GetObjectGuid(DATA_EAST_SHADOW_PRISON_B));
                        case SHADOW_PRISON_TRAP_C: return m_pInstance->instance->GetGameObject(m_pInstance->GetObjectGuid(DATA_EAST_SHADOW_PRISON_C));
                    }
                    break;
                case SHADOW_PRISON_SOUTH:
                    switch (prisonTrap)
                    {
                        case SHADOW_PRISON_TRAP_A: return m_pInstance->instance->GetGameObject(m_pInstance->GetObjectGuid(DATA_SOUTH_SHADOW_PRISON_A));
                        case SHADOW_PRISON_TRAP_B: return m_pInstance->instance->GetGameObject(m_pInstance->GetObjectGuid(DATA_SOUTH_SHADOW_PRISON_B));
                        case SHADOW_PRISON_TRAP_C: return m_pInstance->instance->GetGameObject(m_pInstance->GetObjectGuid(DATA_SOUTH_SHADOW_PRISON_C));
                    }
                    break;
            }

            return NULL;
        }

        int8 GetFreePrisonIndex() const
        {
            for (uint8 i = 0; i < MAX_SHADOW_PRISONS; ++i)
            {
                if (m_Prisons[i].GetTargetGuid() == ObjectGuid::Empty)
                    return i;
            }

            return -1;
        }

        PrisonData* GetPrisonDataByTrap(ObjectGuid trapGuid)
        {
            for (uint8 i = 0; i < MAX_SHADOW_PRISONS; ++i)
            {
                if (m_Prisons[i].HasPlayer() &&
                    (m_Prisons[i].GetTrapGuids().find(trapGuid) != m_Prisons[i].GetTrapGuids().end()))
                    return &m_Prisons[i];
            }

            return NULL;
        }

        PrisonData* GetPrisonDataByPlayer(ObjectGuid playerGuid)
        {
            for (uint8 i = 0; i < MAX_SHADOW_PRISONS; ++i)
            {
                if (m_Prisons[i].HasPlayer() && m_Prisons[i].GetTargetGuid() == playerGuid)
                    return &m_Prisons[i];
            }

            return NULL;
        }

        void ActivatePrisonAndTraps(uint8 prison, ObjectGuid playerGuid, uint32 spellId)
        {
            PrisonData& prisonData = m_Prisons[prison];

            if (GameObject* pGo = GetPrison(prison))
            {
                pGo->SetGoState(GO_STATE_ACTIVE);
                prisonData.SetPrisonGuid(pGo->GetGUID());
            }

            uint8 skipTrap = urand(0, MAX_SHADOW_PRISON_TRAPS - 1);

            for (uint8 j = 0; j < MAX_SHADOW_PRISON_TRAPS; ++j)
            {
                if (j == skipTrap)
                    continue;

                if (GameObject* prisonTrap = GetPrisonTrap(prison, j))
                {
                    prisonTrap->SetGoState(GO_STATE_READY);
                    prisonTrap->AI()->SetGUID(playerGuid, DATA_TRAPPED_PLAYER);
                    prisonData.AddTrapGuid(prisonTrap->GetGUID());
                }
            }

            prisonData.SetPrison(prison);
            prisonData.SetTargetGuid(playerGuid);
            prisonData.SetSpellId(spellId);
        }

        void DeactivatePrisonAndTraps(uint8 prison)
        {
            FreePrisonPlayer(prison);

            if (GameObject* pGo = GetPrison(prison))
                pGo->SetGoState(GO_STATE_READY);

            for (uint8 j = 0; j < MAX_SHADOW_PRISON_TRAPS; ++j)
            {
                if (GameObject* prisonTrap = GetPrisonTrap(prison, j))
                {
                    prisonTrap->SetGoState(GO_STATE_ACTIVE);
                    //prisonTrap->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
                }
            }
        }

        void FreePrisonPlayer(uint8 prison)
        {
            if (prison >= MAX_SHADOW_PRISONS)
                return;

            if (m_Prisons[prison].HasPlayer())
                if (Player* player = ObjectAccessor::FindPlayer(m_Prisons[prison].GetTargetGuid()))
                    player->RemoveAura(m_Prisons[prison].GetSpellId());

            m_Prisons[prison].Clear();
        }

        static uint32 GetSpellIdForPrison(uint8 prison)
        {
            ASSERT(prison < MAX_SHADOW_PRISONS);

            return prisonSpells[prison];
        }

    private:

        InstanceScript* m_pInstance;
        PrisonData m_Prisons[MAX_SHADOW_PRISONS];
};

class BanishController
{
    private:

        struct BanishedPlayer
        {
            ObjectGuid PlayerGUID = ObjectGuid::Empty;
            ObjectGuid FragmentGUID = ObjectGuid::Empty;
            uint32 Phase = 1;
            std::set<ObjectGuid> CorruptionGUIDs;
        };

        class OrbOfLightCheck
        {
            public:
                OrbOfLightCheck(const WorldObject* object, float maxRange) :
                    m_pObject(object), m_fRange(maxRange) {}

                bool operator() (AreaTrigger* p_AreaTrigger)
                {
                    if (p_AreaTrigger->GetSpellId() != Spells::SPELL_ORB_OF_LIGHT_AREATRIGGER)
                        return false;

                    return m_pObject->IsWithinDist(p_AreaTrigger, m_fRange, false);
                }
            private:
                const WorldObject* m_pObject;
                float m_fRange;
        };

        template<class Check>
        struct OrbOfLightSearcher
        {
            std::list<AreaTrigger*> &m_AreaTriggers;
            Check& m_Check;

            OrbOfLightSearcher(WorldObject const* p_Searcher, std::list<AreaTrigger*>& p_AreaTriggers, Check& p_Check)
                : m_AreaTriggers(p_AreaTriggers), m_Check(p_Check) {}

            void Visit(AreaTriggerMapType& p_AreaTriggerMap)
            {
                for (AreaTriggerMapType::iterator l_Iterator = p_AreaTriggerMap.begin(); l_Iterator != p_AreaTriggerMap.end(); ++l_Iterator)
                {
                    if (m_Check(l_Iterator->GetSource()))
                        m_AreaTriggers.push_back(l_Iterator->GetSource());
                }
            }

            template<class NOT_INTERESTED> void Visit(GridRefManager<NOT_INTERESTED> &) {}
        };

    public:
        explicit BanishController(Creature* p_Owner) : m_Owner(p_Owner) { }

        void ClearBanishAll()
        {
            for (auto l_Iter = m_BanishedPlayers.begin(); l_Iter != m_BanishedPlayers.end();)
            {
                ClearBanish(l_Iter);
            }
        }

        void ClearBanish(ObjectGuid p_TargetGuid)
        {
            auto l_BanishedPlayer = m_BanishedPlayers.find(p_TargetGuid);
            if (l_BanishedPlayer == m_BanishedPlayers.end())
                return;

            ClearBanish(l_BanishedPlayer);
        }

        void ClearBanishByFragment(ObjectGuid p_FragmentGuid)
        {
            auto l_BanishedPlayer = std::find_if(m_BanishedPlayers.begin(), m_BanishedPlayers.end(), [p_FragmentGuid](std::pair<ObjectGuid, BanishedPlayer> const& pair) -> bool
            {
                return pair.second.FragmentGUID == p_FragmentGuid;
            });

            if (l_BanishedPlayer != m_BanishedPlayers.end())
                ClearBanish(l_BanishedPlayer);
        }

        void SetBanish(ObjectGuid p_TargetGuid)
        {
            /// Set max limit (phase mask 65534)
            if (m_BanishedPlayers.size() >= 15)
                return;

            auto l_ExistedPlayer = m_BanishedPlayers.find(p_TargetGuid);
            if (l_ExistedPlayer != m_BanishedPlayers.end())
                return;

            if (Player* p_Player = GetPlayer(p_TargetGuid))
            {
                auto& l_BanishedPlayer = m_BanishedPlayers[p_TargetGuid];
                l_BanishedPlayer.PlayerGUID = p_TargetGuid;
                l_BanishedPlayer.Phase = 1 << m_BanishedPlayers.size();

                m_Owner->CastCustomSpell(Spells::SPELL_BANISHMENT, SpellValueMod::SPELLVALUE_BASE_POINT1, (int32)l_BanishedPlayer.Phase, p_Player, true);

                m_Owner->AddAura(Spells::SPELL_BANISHMENT_STUN, p_Player);
                p_Player->CastSpell(p_Player, Spells::SPELL_BANISHMENT_TELEPORT);

                if (Creature* l_Summon = m_Owner->SummonCreature(Adds::NPC_CORRUPTED_FRAGMENT, *p_Player, TempSummonType::TEMPSUMMON_MANUAL_DESPAWN))
                {
                    p_Player->AddAura(Spells::SPELL_BANISHMENT_CLONE, l_Summon);
                    l_BanishedPlayer.FragmentGUID = l_Summon->GetGUID();
                }

                SpawnOrbOfLights(p_Player);
                SpawnEtherealCorruptions(l_BanishedPlayer);
            }
        }

        ObjectGuid GetFragmentGUID(ObjectGuid p_PlayerGuid)
        {
            auto l_ExistedPlayer = m_BanishedPlayers.find(p_PlayerGuid);
            if (l_ExistedPlayer == m_BanishedPlayers.end())
                return ObjectGuid::Empty;

            return l_ExistedPlayer->second.FragmentGUID;
        }

        bool HasBanishedPlayers() const
        {
            return !m_BanishedPlayers.empty();
        }

        void Update(uint32 p_Diff)
        {
            if (!HasBanishedPlayers())
                return;

            if (m_CheckTimer > p_Diff)
            {
                m_CheckTimer -= p_Diff;
                return;
            }

            m_CheckTimer = 1 * IN_MILLISECONDS;

            for (auto l_Iter = m_BanishedPlayers.begin(); l_Iter != m_BanishedPlayers.end();)
            {
                Player* l_Player = GetPlayer(l_Iter->second.PlayerGUID);
                if (l_Player == nullptr)
                {
                    l_Iter = m_BanishedPlayers.erase(l_Iter);
                    continue;
                }

                if (!l_Player->IsAlive() || !m_Owner->IsInMap(l_Player) || !m_Owner->IsWithinDist(l_Player, 300.0f, true) || !l_Player->HasAura(Spells::SPELL_BANISHMENT))
                {
                    ClearBanish(l_Iter);
                    continue;
                }

                if (!IsPlayerInMaze(l_Player))
                {
                    if (!l_Player->HasAura(Spells::SPELL_CORRUPTION_PERIODIC_DMG))
                        m_Owner->AddAura(Spells::SPELL_CORRUPTION_PERIODIC_DMG, l_Player);
                }
                else
                {
                    l_Player->RemoveAura(Spells::SPELL_CORRUPTION_PERIODIC_DMG);
                }

                ++l_Iter;
            }
        }

    private:

        Player* GetPlayer(ObjectGuid p_Guid)
        {
            return ObjectAccessor::FindPlayer(p_Guid);
        }

        void SpawnOrbOfLights(Unit* p_Owner)
        {
            for (uint8 i = 0; i < ORB_OF_LIGHT_COUNT; ++i)
                p_Owner->CastSpell(OrbOfLightPos[i].GetPositionX(), OrbOfLightPos[i].GetPositionY(), OrbOfLightPos[i].GetPositionZ(), Spells::SPELL_ORB_OF_LIGHT_AREATRIGGER, true);
        }

        void SpawnEtherealCorruptions(BanishedPlayer& p_BanishedPlayer)
        {
            for (uint8 i = 0; i < ETHEREAL_CORRUPTION_COUNT; ++i)
            {
                if (Creature* l_Creature = m_Owner->SummonCreature(Adds::NPC_ETHEREAL_CORRUPTION, s_EtherealCorruptions[i]))
                {
                    l_Creature->SetDBPhase(p_BanishedPlayer.Phase);
                    //l_Creature->SetPhaseMask(p_BanishedPlayer.Phase, true);
                    l_Creature->GetMotionMaster()->MovePath(EtherealCorruptionsPath[i], true);
                    p_BanishedPlayer.CorruptionGUIDs.insert(l_Creature->GetGUID());
                }
            }
        }

        bool CanBeDamaged(Unit* p_Target) const
        {
            return p_Target->IsAlive();
        }

        void ClearBanish(std::unordered_map<ObjectGuid, BanishedPlayer>::iterator& l_BanishedPlayerIter)
        {
           // std::list<AreaTrigger*> l_AreaTriggers;
            std::vector<AreaTrigger*> l_AreaTriggers;
            std::list<AreaTrigger*> areatriggers;

            if (Player* l_Player = GetPlayer(l_BanishedPlayerIter->second.PlayerGUID))
            {
                l_Player->RemoveAura(Spells::SPELL_BANISHMENT);
                //l_Player->GetAreaTriggerList(l_AreaTriggers, Spells::SPELL_ORB_OF_LIGHT_AREATRIGGER);
                l_AreaTriggers = l_Player->GetAreaTriggers(Spells::SPELL_ORB_OF_LIGHT_AREATRIGGER);

                // convert vector to list
                for (AreaTrigger* trigger : l_AreaTriggers)
                    areatriggers.push_back(trigger);
            }
            else
            {
                GetOrbOfLightsTriggers(areatriggers);
            }

            if (Creature* l_Fragment = ObjectAccessor::GetCreature(*m_Owner, l_BanishedPlayerIter->second.FragmentGUID))
                l_Fragment->DespawnOrUnsummon();

            for (auto l_AreaTrigger : l_AreaTriggers)
                // todo check valid
                //if (l_AreaTrigger->GetPhaseMask() & l_BanishedPlayerIter->second.Phase)
                if (l_AreaTrigger->GetDBPhase() != 0 && l_BanishedPlayerIter->second.Phase)
                    l_AreaTrigger->SetDuration(0);

            for (auto l_CorruptionGUID : l_BanishedPlayerIter->second.CorruptionGUIDs)
                if (Creature* l_Corruption = ObjectAccessor::GetCreature(*m_Owner, l_CorruptionGUID))
                    l_Corruption->DespawnOrUnsummon();

            l_BanishedPlayerIter = m_BanishedPlayers.erase(l_BanishedPlayerIter);
        }

        void GetOrbOfLightsTriggers(std::list<AreaTrigger*>& p_AreaTriggers)
        {
            CellCoord pair(Trinity::ComputeCellCoord(m_Owner->GetPositionX(), m_Owner->GetPositionY()));
            Cell cell(pair);
            cell.SetNoCreate();

            OrbOfLightCheck check(m_Owner, 300.0f);
            OrbOfLightSearcher<OrbOfLightCheck> searcher(m_Owner, p_AreaTriggers, check);
            TypeContainerVisitor<OrbOfLightSearcher<OrbOfLightCheck>, GridTypeMapContainer> visitor(searcher);

            cell.Visit(pair, visitor, *(m_Owner->GetMap()), *m_Owner, 300.0f);
        }

    private:

        Creature* m_Owner;
        uint64 m_CheckTimer = 1 * IN_MILLISECONDS;
        std::unordered_map<ObjectGuid /*guid*/, BanishedPlayer> m_BanishedPlayers;
};

class boss_sha_of_pride : public CreatureScript
{
    public:
        boss_sha_of_pride() : CreatureScript("boss_sha_of_pride") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_sha_of_prideAI(creature);
        }

        struct boss_sha_of_prideAI : public BossAI
        {
            boss_sha_of_prideAI(Creature* creature) : BossAI(creature, DATA_SHA_OF_PRIDE), m_PrisonController(instance), m_CombatHelper(creature), m_BanishController(creature)
            {
                //ApplyAllImmunities(true);

                me->setActive(true);

                me->SetBoundingRadius(21.0f);
                me->SetCombatReach(21.0f);

                energyTimer = SHA_POWER_PERIODIC;
                isUnleashed = false;

                m_CombatHelper.RegisterCombatAura(SPELL_PRIDE);
            }

            void Reset()
            {
                _Reset();

                me->SetReactState(REACT_DEFENSIVE);

                m_PrisonController.DeactivateAllPrisons();
                m_BanishController.ClearBanishAll();

                InitPowers();

                KillOvercomePlayers();
                RemoveInstanceAuras();

                SendResetToNorushen();

                energyTimer = SHA_POWER_PERIODIC;
                isUnleashed = false;
            }

            void AttackStart(Unit* who)
            {
                if (!who)
                    return;

                if (me->Attack(who, true))
                    DoStartNoMovement(who);
            }

            void EnterCombat(Unit* who) override
            {
                Talk(SAY_AGGRO);

                events.ScheduleEvent(EVENT_REACHING_ATTACK, 2000);
                events.ScheduleEvent(EVENT_MARK_OF_ARROGANCE, 20500);
                events.ScheduleEvent(EVENT_SELF_REFLECTION, 20500);
                events.ScheduleEvent(EVENT_SHADOW_PRISON, 42000);
                events.ScheduleEvent(EVENT_WOUNDED_PRIDE, 10000);
                events.ScheduleEvent(EVENT_MANIFESTATION, 48000);
                events.ScheduleEvent(EVENT_BERSERK, TIMER_BERSERK);

                if (IsHeroic())
                {
                    me->CastSpell(me, SPELL_UNSTABLE_CORRUPTION_PERIODIC, true);
                    events.ScheduleEvent(Events::EVENT_BANISHMENT, Timers::TIMER_BANISHMENT);
                }

                ApplyPrideOnPlayers();

                SendStartToNorushen();

                instance->SetBossState(DATA_SHA_OF_PRIDE, IN_PROGRESS);
                DoZoneInCombat();
            }

            void SetGUID(ObjectGuid guid, int32 type) override
            {
                switch (type)
                {
                    case eData::DATA_TRAP_USED:
                        m_PrisonController.TrapUsed(guid);
                        break;
                    case eData::DATA_TRAP_DEACTIVATED:
                        m_PrisonController.FreePlayer(guid);
                        break;
                    case eData::DATA_BANISHED_PLAYER:
                        m_BanishController.SetBanish(guid);
                        break;
                    case eData::DATA_BANISHED_PLAYER_REMOVE:
                        m_BanishController.ClearBanish(guid);
                        break;

                }
            }

            ObjectGuid GetFragmentGUID(ObjectGuid p_PlayerGuid)
            {
                return m_BanishController.GetFragmentGUID(p_PlayerGuid);
            }

            void SummonedCreatureDies(Creature* p_Summon, Unit* p_Killer) override
            {
                if (p_Summon->GetEntry() == Adds::NPC_CORRUPTED_FRAGMENT)
                    m_BanishController.ClearBanishByFragment(p_Summon->GetGUID());
            }

            void KilledUnit(Unit* victim)
            {
                if (!victim || !victim->IsPlayer())
                    return;

                Talk(SAY_KILL);

                m_PrisonController.FreePlayer(victim->GetGUID());
            }

            void JustDied(Unit* who)
            {
                _JustDied();

                DoPlaySoundToSet(me, SOUND_DEATH);

                KillOvercomePlayers();
                RemoveInstanceAuras();

                m_PrisonController.DeactivateAllPrisons();
                m_BanishController.ClearBanishAll();

                switch (GetDifficulty())
                {
                    case DIFFICULTY_10_N:
                        instance->DoRespawnGameObject(instance->GetObjectGuid(DATA_VAULT_OF_FORBIDDEN_TREASURES_10), DAY);
                        break;
                    case DIFFICULTY_25_N:
                        instance->DoRespawnGameObject(instance->GetObjectGuid(DATA_VAULT_OF_FORBIDDEN_TREASURES_25), DAY);
                        break;
                    case DIFFICULTY_10_HC:
                        instance->DoRespawnGameObject(instance->GetObjectGuid(DATA_VAULT_OF_FORBIDDEN_TREASURES_10H), DAY);
                        break;
                    case DIFFICULTY_25_HC:
                        instance->DoRespawnGameObject(instance->GetObjectGuid(DATA_VAULT_OF_FORBIDDEN_TREASURES_25H), DAY);
                        break;
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                m_BanishController.Update(diff);
                events.Update(diff);

                UpdateEnergy(diff);

                m_CombatHelper.UpdateCombatAuras(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (CheckUnleashed())
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BERSERK:
                            me->AddAura(SPELL_BERSERK, me);
                            break;
                        case EVENT_REACHING_ATTACK:
                            if (!me->IsWithinMeleeRange(me->GetVictim()))
                                DoCastVictim(SPELL_REACHING_ATTACK);
                            events.ScheduleEvent(EVENT_REACHING_ATTACK, 2000);
                            break;
                        case EVENT_MARK_OF_ARROGANCE:
                            DoCastAOE(SPELL_MARK_OF_ARROGANCE);
                            events.ScheduleEvent(EVENT_MARK_OF_ARROGANCE, 20500);
                            break;
                        case EVENT_SWELLING_PRIDE:
                            Talk(SAY_SWELLING_PRIDE);

                            DoCastAOE(SPELL_SWELLING_PRIDE);

                            events.RescheduleEvent(EVENT_WOUNDED_PRIDE, 11000);
                            events.RescheduleEvent(EVENT_MANIFESTATION, 48000);
                            events.RescheduleEvent(EVENT_SELF_REFLECTION, 20500);
                            events.RescheduleEvent(EVENT_SHADOW_PRISON, 42000);
                            events.RescheduleEvent(Events::EVENT_BANISHMENT, Timers::TIMER_BANISHMENT + 3 * IN_MILLISECONDS /* Swelling Pride casting time*/);
                            break;
                        case EVENT_SHADOW_PRISON:
                        {
                            Talk(SAY_CORRUPTED_PRISON);

                            std::list<Unit*> targets;
                            SelectTargetList(targets, ShadowPrisonTargetSelector(me), RAID_MODE(2, 4, 2, 4), SELECT_TARGET_RANDOM);

                            if (targets.size() > 1)
                            {
                                targets.remove(me->GetVictim());
                            }
                            else if (targets.empty())
                            {
                                targets.push_back(me->GetVictim());
                            }

                            for (std::list<Unit*>::const_iterator itr = targets.begin(); itr != targets.end(); ++itr)
                            {
                                m_PrisonController.CatchPlayer(me, (*itr)->GetGUID());
                            }

                            events.ScheduleEvent(EVENT_SHADOW_PRISON, 42000);
                            break;
                        }
                        case EVENT_WOUNDED_PRIDE:
                            DoCastVictim(SPELL_WOUNDED_PRIDE);
                            events.ScheduleEvent(EVENT_WOUNDED_PRIDE, 26000);
                            break;
                        case EVENT_MANIFESTATION:
                            SpawnManifestation();
                            break;
                        case EVENT_SELF_REFLECTION:
                            Talk(SAY_SELF_REFLECTION);
                            DoCast(me, SPELL_SELF_REFLECTION);
                            break;
                        case Events::EVENT_BANISHMENT:
                            DoBanishment();
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:

            void InitPowers()
            {
                me->AddAura(SPELL_ZERO_POWER, me);

                me->SetPowerType(POWER_ENERGY);
                me->SetMaxPower(POWER_ENERGY, MAX_SHA_POWER);
                me->SetPower(POWER_ENERGY, 0);
            }

            void UpdateEnergy(const uint32 diff)
            {
                if (energyTimer <= diff)
                {
                    energyTimer = SHA_POWER_PERIODIC;

                    int32 curEnergy = me->GetPower(POWER_ENERGY);
                    if (curEnergy < MAX_SHA_POWER)
                    {
                        int32 newEnergy = curEnergy + 1;
                        if (newEnergy >= MAX_SHA_POWER)
                        {
                            events.ScheduleEvent(EVENT_SWELLING_PRIDE, 1);
                        }

                        me->SetPower(POWER_ENERGY, curEnergy + 1);
                    }
                }
                else
                {
                    energyTimer -= diff;
                }
            }

            void ApplyPrideOnPlayers()
            {
                instance->DoAddAuraOnPlayers(SPELL_PRIDE);
            }

            void RemoveInstanceAuras()
            {
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CORRUPTED_PRISON_1);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CORRUPTED_PRISON_2);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CORRUPTED_PRISON_3);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CORRUPTED_PRISON_4);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_PRIDE);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_OVERCOME_1);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_OVERCOME_2);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MARK_OF_ARROGANCE);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_GIFT_OF_THE_TITANS_1);
            }

            void KillOvercomePlayers()
            {
                Map::PlayerList const& PlayerList = instance->instance->GetPlayers();
                if (!PlayerList.isEmpty())
                {
                    for (Map::PlayerList::const_iterator itr = PlayerList.begin(); itr != PlayerList.end(); ++itr)
                    {
                        if (Player* player = itr->GetSource())
                        {
                            // kill only charmed targets
                            if (player->HasAura(SPELL_OVERCOME_2))
                            {
                                me->Kill(player);
                            }
                        }
                    }
                }
            }

            void SpawnManifestation()
            {
                switch (GetDifficulty())
                {
                    case DIFFICULTY_10_N:
                    case DIFFICULTY_10_HC:
                        me->SummonCreature(NPC_MANIFESTATION_OF_PRIDE, manifestationPos10Man1);
                        break;
                    case DIFFICULTY_25_N:
                    case DIFFICULTY_25_HC:
                        me->SummonCreature(NPC_MANIFESTATION_OF_PRIDE, manifestationPos25Man1);
                        me->SummonCreature(NPC_MANIFESTATION_OF_PRIDE, manifestationPos25Man2);
                        break;
                }
            }

            void DoBanishment()
            {
                DoCastAOE(Spells::SPELL_BANISHMENT_AOE_1);
            }

            bool CheckUnleashed()
            {
                if (isUnleashed)
                    return false;

                if (me->GetHealthPct() > 30.0f)
                    return false;

                isUnleashed = true;

                Talk(SAY_UNLEASHED);

                DoCast(me, SPELL_UNLEASHED);

                events.RescheduleEvent(Events::EVENT_BANISHMENT, Timers::TIMER_BANISHMENT + 9 * IN_MILLISECONDS /* Unleashed casting time*/);

                return true;
            }

            void SendStartToNorushen()
            {
                if (Creature* pNorushen = ObjectAccessor::GetCreature(*me, instance->GetObjectGuid(DATA_SHA_OF_PRIDE_NORUSHEN)))
                {
                    if (pNorushen->AI())
                        pNorushen->AI()->DoAction(ACTION_COMBAT_START);
                }
            }

            void SendResetToNorushen()
            {
                if (Creature* pNorushen = instance->instance->GetCreature(instance->GetObjectGuid(DATA_SHA_OF_PRIDE_NORUSHEN)))
                {
                    pNorushen->AI()->DoAction(ACTION_RESET);
                }
            }

            void SendDoneToNorushen()
            {
                if (Creature* pNorushen = instance->instance->GetCreature(instance->GetObjectGuid(DATA_SHA_OF_PRIDE_NORUSHEN)))
                {
                    pNorushen->AI()->DoAction(ACTION_COMPLETED);
                }
            }

        private:

            PrisonController m_PrisonController;
            uint32 energyTimer;
            bool isUnleashed;
            CombatAuraHelper m_CombatHelper;
            BanishController m_BanishController;

        private:

            struct ShadowPrisonTargetSelector : public std::unary_function<Unit*, bool>
            {
                const Unit* me;
                float m_dist;
                bool m_playerOnly;
                int32 m_aura;

                ShadowPrisonTargetSelector(Unit const* unit) : me(unit) {}

                bool operator()(Unit const* target) const
                {
                    if (!me)
                        return false;

                    if (!target)
                        return false;

                    if (!target->IsPlayer())
                        return false;

                    Unit* _target = (Unit*)target;

                    if (Player* player = _target->ToPlayer())
                    {
                        if (player->GetRoleForGroup() == ROLE_TANK ||
                            player->GetRoleForGroup() == ROLE_HEALER)
                            return false;
                    }

                    return true;
                }
            };

        };
};

class npc_sha_of_pride_norushen : public CreatureScript
{
    public:
        npc_sha_of_pride_norushen() : CreatureScript("npc_sha_of_pride_norushen") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_sha_of_pride_norushenAI(creature);
        }

        struct npc_sha_of_pride_norushenAI : public Scripted_NoMovementAI
        {
            npc_sha_of_pride_norushenAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                me->setActive(true);
                me->SetReactState(REACT_PASSIVE);
                SetCanSeeEvenInPassiveMode(true);

                pInstance = me->GetInstanceScript();
                introDone = false;
                shaSpawned = false;
                lingeringCorruptionCount = 0;
                shaVortexGuid = ObjectGuid::Empty;
                isFinalGiftDone = false;

                SpawnVortexAndLingeringCorruption();
            }

            void Reset()
            {
                introDone = false;
                shaSpawned = false;
                lingeringCorruptionCount = 0;
                isFinalGiftDone = false;
                //shaVortexGuid = 0; do not do it
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (introDone)
                    return;

                if (who->IsPlayer())
                {
                    if (me->GetDistance(who) <= 10.0f)
                    {
                        introDone = true;

                        Talk(SAY_NORUSHEN_INTRO_1);
                    }
                }
            }

            void DoAction(const int32 action)
            {
                switch (action)
                {
                    case ACTION_LINGERING_CORRUPTION_DIED:
                        UpdateLingeringCorruption(1);
                        break;
                    case ACTION_UNLEASHED:
                        DelayedFinalGift();
                        //FinalGift();
                        break;
                    case ACTION_RESET:
                        isFinalGiftDone = false;
                        events.CancelEvent(EVENT_GIFT_OF_THE_TITANS);
                        events.CancelEvent(EVENT_FINAL_GIFT);
                        if (!me->IsAlive())
                            me->Respawn();
                        break;
                    case ACTION_COMPLETED:
                        events.CancelEvent(EVENT_FINAL_GIFT);
                        break;
                    case ACTION_COMBAT_START:
                        events.ScheduleEvent(EVENT_GIFT_OF_THE_TITANS, 20000);
                        break;
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                events.Reset();
            }

            void UpdateAI(const uint32 diff)
            {
                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SPAWN_SHA_OF_PRIDE:
                            SpawnShaOfPride();
                            break;
                        case EVENT_GIFT_OF_THE_TITANS:
                            Talk(SAY_GIFT_OF_THE_TITANS);
                            me->CastSpell(me, SPELL_GIFT_OF_THE_TITANS, false);
                            events.ScheduleEvent(EVENT_GIFT_OF_THE_TITANS, 40000);
                            break;
                        case EVENT_FINAL_GIFT:
                            FinalGift();
                            break;
                        default:
                            break;
                    }
                }
            }

        private:

            void SpawnVortexAndLingeringCorruption()
            {
                if (pInstance)
                {
                    if (pInstance->GetBossState(DATA_SHA_OF_PRIDE) == DONE)
                        return;
                }

                if (Creature* pCreature = me->SummonCreature(NPC_SHA_VORTEX, shaVortexPos))
                {
                    shaVortexGuid = pCreature->GetGUID();

                    pCreature->AddAura(SPELL_SHA_VORTEX, pCreature);

                    for (uint8 i = 0; i < MAX_LINGERING_CORRUPTIONS; ++i)
                    {
                        Position pos = pCreature->GetRandomNearPosition(frand(20.0f, 60.0f));
                        pCreature->SummonCreature(NPC_LINGERING_CORRUPTION, pos);
                    }
                }
            }

            void UpdateLingeringCorruption(int32 addCount)
            {
                if (shaSpawned)
                    return;

                lingeringCorruptionCount += addCount;

                if (!introDone)
                {
                    introDone = true;

                    Talk(SAY_NORUSHEN_INTRO_1);
                }

                if (lingeringCorruptionCount >= MAX_LINGERING_CORRUPTIONS)
                {
                    shaSpawned = true;

                    Talk(SAY_NORUSHEN_INTRO_2);

                    if (Creature* pShaVortex = ObjectAccessor::GetCreature(*me, shaVortexGuid))
                        pShaVortex->DespawnOrUnsummon();

                    DelayedSpawnShaOfPride();
                }
            }

            bool CanSpawnShaOfPride()
            {
                if (!pInstance)
                    return false;

                if (pInstance->GetData64(DATA_SHA_OF_PRIDE) != 0)
                    return false;

                if (pInstance->GetBossState(DATA_SHA_OF_PRIDE) == IN_PROGRESS ||
                    pInstance->GetBossState(DATA_SHA_OF_PRIDE) == DONE)
                    return false;

                return true;
            }

            void DelayedSpawnShaOfPride()
            {
                if (!CanSpawnShaOfPride())
                    return;

                events.ScheduleEvent(EVENT_SPAWN_SHA_OF_PRIDE, 10000);
            }

            void SpawnShaOfPride()
            {
                if (!CanSpawnShaOfPride())
                    return;

                if (Creature* pSha = me->SummonCreature(NPC_SHA_OF_PRIDE, shaVortexPos))
                {
                    pSha->AI()->Talk(SAY_INTRO);
                }
            }

            void DelayedFinalGift()
            {
                events.CancelEvent(EVENT_GIFT_OF_THE_TITANS);
                events.ScheduleEvent(EVENT_FINAL_GIFT, 100);
            }

            void FinalGift()
            {
                if (isFinalGiftDone)
                    return;

                isFinalGiftDone = true;

                events.CancelEvent(EVENT_GIFT_OF_THE_TITANS);

                Talk(SAY_FINAL_GIFT);

                DoCastAOE(SPELL_FINAL_GIFT);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_OVERCOME_1);
                me->Kill(me);
            }

        private:

            InstanceScript* pInstance;
            ObjectGuid shaVortexGuid;
            bool introDone;
            uint32 lingeringCorruptionCount;
            bool shaSpawned;
            bool isFinalGiftDone;

        };
};

class npc_sha_of_pride_lingering_corruption : public CreatureScript
{
    public:
        npc_sha_of_pride_lingering_corruption() : CreatureScript("npc_sha_of_pride_lingering_corruption") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_sha_of_pride_lingering_corruptionAI(creature);
        }

        struct npc_sha_of_pride_lingering_corruptionAI : public ScriptedAI
        {
            npc_sha_of_pride_lingering_corruptionAI(Creature* creature) : ScriptedAI(creature)
            {
                me->setActive(true);

                pInstance = me->GetInstanceScript();
            }

            void Reset()
            {

            }

            void JustDied(Unit* who)
            {
                DoCastAOE(SPELL_CORRUPTED_TOUCH, true);

                SendLingeringCorruptionDied();

                me->DespawnOrUnsummon(2000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }

        private:

            void SendLingeringCorruptionDied()
            {
                if (pInstance)
                {
                    if (Creature* pNorushen = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_SHA_OF_PRIDE_NORUSHEN)))
                    {
                        pNorushen->AI()->DoAction(ACTION_LINGERING_CORRUPTION_DIED);
                    }
                }
            }

        private:

            InstanceScript* pInstance;
        };
};

class npc_sha_of_pride_manifestation_of_pride : public CreatureScript
{
    public:
        npc_sha_of_pride_manifestation_of_pride() : CreatureScript("npc_sha_of_pride_manifestation_of_pride") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_sha_of_pride_manifestation_of_prideAI(creature);
        }

        struct npc_sha_of_pride_manifestation_of_prideAI : public ScriptedAI
        {
            npc_sha_of_pride_manifestation_of_prideAI(Creature* creature) : ScriptedAI(creature)
            {
                me->setActive(true);
                me->SetReactState(REACT_PASSIVE);

                pInstance = me->GetInstanceScript();
            }

            void Reset()
            {
                me->AddUnitState(UNIT_STATE_ROOT);
            }

            void IsSummonedBy(Unit* owner)
            {
                DoCast(me, SPELL_MANIFESTATION_SPAWN, true);
            }

            void EnterCombat(Unit* who)
            {
                events.ScheduleEvent(EVENT_GET_READY, 3000);
            }

            void JustDied(Unit* who)
            {
                DoCastAOE(SPELL_LAST_WORD, true);

                me->DespawnOrUnsummon(2000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_GET_READY:
                            me->RemoveAura(SPELL_MANIFESTATION_SPAWN);      ///< Spawn Creature (Animation)
                            events.ScheduleEvent(EVENT_MOVE, 2000);         ///< Next Event (2s to let Creature Spawn)
                            break;
                        case EVENT_MOVE:
                            me->SetReactState(REACT_AGGRESSIVE);            ///< Aggro (Creatured Spawned)
                            events.ScheduleEvent(EVENT_MOCKING_BLAST, 1);   ///< Next Event (Instantly Start Cast)
                            break;
                        case EVENT_MOCKING_BLAST:
                            DoCastAOE(SPELL_MOCKING_BLAST);
                            events.ScheduleEvent(EVENT_MOCKING_BLAST, 3000);
                            break;
                    }
                }
            }

        private:

        private:

            InstanceScript* pInstance;
        };
};

class npc_sha_of_pride_reflection : public CreatureScript
{
    public:
        npc_sha_of_pride_reflection() : CreatureScript("npc_sha_of_pride_reflection") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_sha_of_pride_reflectionAI(creature);
        }

        struct npc_sha_of_pride_reflectionAI : public ScriptedAI
        {
            npc_sha_of_pride_reflectionAI(Creature* creature) : ScriptedAI(creature)
            {
                me->setActive(true);
                me->SetReactState(REACT_PASSIVE);

                pInstance = me->GetInstanceScript();
            }

            void Reset()
            {

            }

            void IsSummonedBy(Unit* owner)
            {
                DoCast(me, SPELL_SELF_REFLECTION_SPAWN, true);
            }

            void EnterCombat(Unit* who)
            {
                events.ScheduleEvent(EVENT_REFLECTION_DMG, 3000);
                events.ScheduleEvent(EVENT_MOVE, 4000);
            }

            void JustDied(Unit* who)
            {
                me->DespawnOrUnsummon(2000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_MOVE:
                            me->SetReactState(REACT_AGGRESSIVE);
                            break;
                        case EVENT_REFLECTION_DMG:
                            DoCastAOE(SPELL_SELF_REFLECTION_DMG);
                            me->RemoveAura(SPELL_SELF_REFLECTION_SPAWN);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:

        private:

            InstanceScript* pInstance;
        };
};

class npc_sha_of_pride_rift_of_corruption : public CreatureScript
{
    public:
        npc_sha_of_pride_rift_of_corruption() : CreatureScript("npc_sha_of_pride_rift_of_corruption") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_sha_of_pride_rift_of_corruptionAI(creature);
        }

        struct npc_sha_of_pride_rift_of_corruptionAI : public Scripted_NoMovementAI
        {
            npc_sha_of_pride_rift_of_corruptionAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC));

                me->SetReactState(REACT_PASSIVE);

                m_CheckCloseTimer = 1000;
                m_IsClosing = false;
            }

            void Reset() override
            {
                me->AddAura(SPELL_RIFT_OF_CORRUPTION_VISUAL_1, me);
                me->CastSpell(me, SPELL_UNSTABLE_CORRUPTION_PERIODIC_2, true);
            }

            void UpdateAI(const uint32 diff) override
            {
                UpdateClose(diff);
            }

        private:

            void UpdateClose(const uint32 diff)
            {
                if (m_IsClosing)
                    return;

                if (m_CheckCloseTimer <= diff)
                {
                    m_CheckCloseTimer = 1000;

                    if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0, 2.0f, true, -SPELL_WEAKENED_RESOLVE))
                        DoClose(target);
                }
                else
                    m_CheckCloseTimer -= diff;
            }

            void DoClose(Unit* actor)
            {
                m_IsClosing = true;

                DoCastAOE(SPELL_COLLAPSING_RIFT);
                me->AddAura(SPELL_WEAKENED_RESOLVE, actor);
                DoCast(me, SPELL_RIFT_OF_CORRUPTION_CLOSE, true);

                me->RemoveAura(SPELL_UNSTABLE_CORRUPTION_PERIODIC);

                me->DespawnOrUnsummon(500);
            }

        private:
            uint32 m_CheckCloseTimer;
            bool m_IsClosing;
        };
};

class go_sha_of_pride_shadow_prison_trap : public GameObjectScript
{
    public:
        go_sha_of_pride_shadow_prison_trap() : GameObjectScript("go_sha_of_pride_shadow_prison_trap") { }

        GameObjectAI* GetAI(GameObject* pGo) const
        {
            return new go_sha_of_pride_shadow_prison_trapAI(pGo);
        }

        struct go_sha_of_pride_shadow_prison_trapAI : public GameObjectAI
        {
            go_sha_of_pride_shadow_prison_trapAI(GameObject* p_Go) : GameObjectAI(p_Go)
            {
                playersTimer = 2000;
                catchedPlayerGuid = ObjectGuid::Empty;
            }

            void SetGUID(ObjectGuid guid, int32 id) override
            {
                if (id == DATA_TRAPPED_PLAYER)
                {
                    catchedPlayerGuid = guid;
                }
            }

            void UpdateAI(uint32 diff)
            {
                UpdatePlayers(diff);
            }

        private:

            void UpdatePlayers(const uint32 diff)
            {
                if (go->GetGoState() != GO_STATE_READY)
                    return;

                if (playersTimer <= diff)
                {
                    playersTimer = 1000;

                    if (PlayersCount(10.0f) >= 2)
                    {
                        SendFreePlayer();
                    }
                }
                else
                {
                    playersTimer-= diff;
                }
            }

            void UpdatePlayersOld(const uint32 diff)
            {
                if (go->GetGoState() != GO_STATE_READY)
                    return;

                if (playersTimer <= diff)
                {
                    playersTimer = 2000;

                    Player* player = GetPlayer(10.0f);
                    if (!player)
                        return;

                    float dist = go->GetDistance2d(player);

                    if (dist < 5.0f || dist > 7.5f)
                        return;

                    //               _______A
                    //        /\
                    //       /  \
                    //      /    \   _______B
                    //     /@@@@@@\
                    //    /@@@@@@@@\ _______C
                    //
                    //   1<--------->2      1 and 2 - angles, A-C - radius, B-C - height for area
                    //
                    //
                    // A-B = 5.0f
                    // A-C > 7.5f
                    //
                    // so area is between 5.0f and 7.5f height and 1 and 2 angles
                    //
                    // I've calculated 3 basic constants:
                    // orientation of trap (GameObject) and 1 and 2 angles we need

                    // if orientation of the trap is defOri
                    // then player's angle should be between minAngle and maxAngle
                    const float defOri = 5.335980f;
                    const float minAngle = 1.868661f;
                    const float maxAngle = 3.25126290f;

                    float diff = defOri - go->GetOrientation();
                    float normalizedDiff = go->NormalizeOrientation(diff);
                    float plrAngle = go->GetAngle(player);
                    float normalizedAngleWithDiff = go->NormalizeOrientation(plrAngle + normalizedDiff);

                    if (normalizedAngleWithDiff > minAngle && normalizedAngleWithDiff < maxAngle)
                    {
                        go->SetGoState(GO_STATE_ACTIVE);
                        SendTrapUsed();
                    }
                }
                else
                {
                    playersTimer -= diff;
                }
            }

            void SendTrapUsed()
            {
                if (InstanceScript* pInstance = go->GetInstanceScript())
                {
                    if (Creature* pSha = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_SHA_OF_PRIDE)))
                    {
                        pSha->AI()->SetGUID(go->GetGUID(), DATA_TRAP_USED);
                    }
                }
            }

            void SendFreePlayer()
            {
                if (InstanceScript* pInstance = go->GetInstanceScript())
                {
                    if (Creature* pSha = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_SHA_OF_PRIDE)))
                    {
                        pSha->AI()->SetGUID(catchedPlayerGuid, DATA_TRAP_DEACTIVATED);
                    }
                }
            }

            // use this function instead of basic 'GetPlayerListInGrid'
            Player* GetPlayer(float range)
            {
                uint32 auraId = PrisonController::GetSpellIdForPrisonTrapEntry(go->GetEntry());
                if (!auraId)
                    return NULL;

                Player* player = NULL;
                PlayerTrapActivatorCheck check(go, range, auraId);
                Trinity::PlayerSearcher<PlayerTrapActivatorCheck> searcher(go, player, check);
                //go->VisitNearbyWorldObject(range, searcher);
                Cell::VisitWorldObjects(go, searcher, range);
                return player;
            }

            uint32 PlayersCount(float range)
            {
                uint32 auraId = PrisonController::GetSpellIdForPrisonTrapEntry(go->GetEntry());
                if (!auraId)
                    return 0;

                std::list<Player*> players;
                PlayerTrapActivatorCheckNew check(go, 4.5f, 8.1f, auraId);
                Trinity::PlayerListSearcher<PlayerTrapActivatorCheckNew> searcher(go, players, check);
                //go->VisitNearbyWorldObject(range, searcher);
                Cell::VisitWorldObjects(go, searcher, range);
                return players.size();
            }

        private:

            uint32 playersTimer;
            ObjectGuid catchedPlayerGuid;

        private:

            class PlayerTrapActivatorCheck
            {
                public:
                    PlayerTrapActivatorCheck(WorldObject const* obj, float range, uint32 skipAuraId) : _obj(obj), _range(range), _skipAuraId(skipAuraId) {}
                    bool operator()(Player* u)
                    {
                        if (!u->IsAlive())
                            return false;

                        if (_obj->GetDistance2d(u) > _range)
                            return false;

                        if (u->HasAura(_skipAuraId))
                            return false;

                        return true;
                    }

                private:
                    WorldObject const* _obj;
                    float _range;
                    uint32 _skipAuraId;
            };

            class PlayerTrapActivatorCheckNew
            {
                public:
                    PlayerTrapActivatorCheckNew(WorldObject const* obj, float rangeMin, float rangeMax, uint32 skipAuraId) :
                        _obj(obj), _rangeMax(rangeMax), _rangeMin(rangeMin), _skipAuraId(skipAuraId) {}
                    bool operator()(Player* u)
                    {
                        if (!u->IsAlive())
                            return false;

                        if (_obj->GetDistance2d(u) < _rangeMin)
                            return false;

                        if (_obj->GetDistance2d(u) > _rangeMax)
                            return false;

                        if (u->HasAura(_skipAuraId))
                            return false;

                        return true;
                    }

                private:
                    WorldObject const* _obj;
                    float _rangeMax;
                    float _rangeMin;
                    uint32 _skipAuraId;
            };

        };
};

class npc_sha_of_pride_jaina_proudmoore : public CreatureScript
{
    public:
        npc_sha_of_pride_jaina_proudmoore() : CreatureScript("npc_sha_of_pride_jaina_proudmoore") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_sha_of_pride_jaina_proudmooreAI(creature);
        }

        struct npc_sha_of_pride_jaina_proudmooreAI : public ScriptedAI
        {
            npc_sha_of_pride_jaina_proudmooreAI(Creature* creature) : ScriptedAI(creature), m_SceneHelper(creature->GetGUID(), creature->GetMap())
            {
                me->setActive(true);
                me->SetReactState(REACT_PASSIVE);

                pInstance = creature->GetInstanceScript();
            }

            void Reset()
            {

            }

            void DoAction(const int32 action)
            {
                if (action == ACTION_SHA_OF_PRIDE_JAINA)
                {
                    m_SceneHelper.Clear();

                    m_SceneHelper.AddSceneActionTalk(SAY_JAINA_INTRO_1, 1000);
                    m_SceneHelper.AddSceneActionTalk(SAY_JAINA_INTRO_2, 14000);
                    m_SceneHelper.AddSceneActionTalk(SAY_JAINA_INTRO_3, 6000);
                    m_SceneHelper.AddSceneActionTalk(SAY_JAINA_INTRO_4, 13000);
                    m_SceneHelper.AddSceneSummonCreature(NPC_PORTAL_TO_ORGRIMMAR_1, npcAfterShaOfPridePos[3], 18000);
                    m_SceneHelper.AddSceneActionMovePos(npcAfterShaOfPridePos[4], 1);
                    if (IsAllianceInstance())
                    {
                        m_SceneHelper.AddSceneActionTalk(SAY_JAINA_INTRO_5, 1);
                    }

                    m_SceneHelper.Activate();
                }
            }

            void UpdateAI(const uint32 diff)
            {
                m_SceneHelper.UpdateSceneHelper(diff);
            }


        private:

            bool IsAllianceInstance()
            {
                return (pInstance && pInstance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE);
            }

        private:

            InstanceScript* pInstance;
            SceneHelper m_SceneHelper;
        };
};

class npc_sha_of_pride_lorthemar_theron : public CreatureScript
{
    public:
        npc_sha_of_pride_lorthemar_theron() : CreatureScript("npc_sha_of_pride_lorthemar_theron") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_sha_of_pride_lorthemar_theronAI(creature);
        }

        struct npc_sha_of_pride_lorthemar_theronAI : public ScriptedAI
        {
            npc_sha_of_pride_lorthemar_theronAI(Creature* creature) : ScriptedAI(creature), m_SceneHelper(creature->GetGUID(), creature->GetMap())
            {
                me->setActive(true);
                me->SetReactState(REACT_PASSIVE);

                pInstance = creature->GetInstanceScript();
            }

            void Reset()
            {

            }

            void DoAction(const int32 action)
            {
                if (action == ACTION_SHA_OF_PRIDE_LORTHEMAR)
                {
                    m_SceneHelper.Clear();

                    m_SceneHelper.AddSceneActionTalk(SAY_LORTHEMAR_INTRO_1, 11000);
                    m_SceneHelper.AddSceneActionTalk(SAY_LORTHEMAR_INTRO_2, 6000);
                    m_SceneHelper.AddSceneActionTalk(SAY_LORTHEMAR_INTRO_3, 11000);
                    m_SceneHelper.AddSceneActionTalk(SAY_LORTHEMAR_INTRO_4, 18000);
                    m_SceneHelper.AddSceneSummonCreature(NPC_PORTAL_TO_ORGRIMMAR_1, npcAfterShaOfPridePos[5], 5000);
                    m_SceneHelper.AddSceneActionMovePos(npcAfterShaOfPridePos[6], 1);
                    if (IsHordeInstance())
                    {
                        m_SceneHelper.AddSceneActionTalk(SAY_LORTHEMAR_INTRO_5, 1);
                    }

                    m_SceneHelper.Activate();
                }
            }

            void UpdateAI(const uint32 diff)
            {
                m_SceneHelper.UpdateSceneHelper(diff);
            }

        private:

            bool IsHordeInstance()
            {
                return (pInstance && pInstance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE);
            }

        private:
            SceneHelper m_SceneHelper;
            InstanceScript* pInstance;
        };
};

class npc_sha_of_pride_portal_to_orgrimmar : public CreatureScript
{
    public:
        npc_sha_of_pride_portal_to_orgrimmar() : CreatureScript("npc_sha_of_pride_portal_to_orgrimmar") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_sha_of_pride_portal_to_orgrimmarAI(creature);
        }

        struct npc_sha_of_pride_portal_to_orgrimmarAI : public Scripted_NoMovementAI
        {
            npc_sha_of_pride_portal_to_orgrimmarAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                me->setActive(true);
                me->SetReactState(REACT_PASSIVE);
                me->SetDisplayId(51795);
                me->SetUnitFlags(UnitFlags(UNIT_NPC_FLAG_GOSSIP));
                me->SetUnitFlags2(UnitFlags2(UNIT_FLAG_NOT_SELECTABLE));

                pInstance = creature->GetInstanceScript();
            }

            void Reset()
            {

            }

            void UpdateAI(const uint32 diff)
            {

            }

            void sGossipHello(Player* player) override
            {
                if (IsAllianceInstance())
                {
                    player->NearTeleportTo(galakrasPlayersPos[0]);
                }
                else if (IsHordeInstance())
                {
                    player->NearTeleportTo(galakrasPlayersPos[1]);
                }

                SendPlayerTeleported();
            }

        private:

            bool IsAllianceInstance()
            {
                return (pInstance && pInstance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE);
            }

            bool IsHordeInstance()
            {
                return (pInstance && pInstance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE);
            }

            void SendPlayerTeleported()
            {
                if (pInstance)
                {
                    pInstance->SetData(DATA_FIRST_GALAKRAS_INTRO, DONE);
                }
            }

        private:

            InstanceScript* pInstance;
        };
};

/// Ethereal Corruption - 73972
class npc_sha_of_pride_ethereal_corruption : public CreatureScript
{
    public:
        npc_sha_of_pride_ethereal_corruption() : CreatureScript("npc_sha_of_pride_ethereal_corruption") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_sha_of_pride_ethereal_corruptionAI(creature);
        }

        struct npc_sha_of_pride_ethereal_corruptionAI : public ScriptedAI
        {
            npc_sha_of_pride_ethereal_corruptionAI(Creature* creature) : ScriptedAI(creature)
            {
                //me->SetPhaseMask(ePhaseMasks::BANISHMENT_ALL, true);
                me->SetDBPhase(ePhaseMasks::BANISHMENT_ALL);
                me->SetReactState(REACT_PASSIVE);

                me->SetUnitFlags(UnitFlags(UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_NOT_SELECTABLE | UnitFlags::UNIT_FLAG_IMMUNE_TO_PC));
            }

            void Reset() override
            {
                me->AddAura(Spells::SPELL_ETHEREAL_CORRUPTION, me);
            }
        };
};

/// Corrupted Fragment - 72569
class npc_sha_of_pride_corrupted_fragment : public CreatureScript
{
    public:
        npc_sha_of_pride_corrupted_fragment() : CreatureScript("npc_sha_of_pride_corrupted_fragment") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_sha_of_pride_corrupted_fragmentAI(creature);
        }

        struct npc_sha_of_pride_corrupted_fragmentAI : public ScriptedAI
        {
            npc_sha_of_pride_corrupted_fragmentAI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetReactState(REACT_PASSIVE);
                me->AddAura(Spells::SPELL_BANISHMENT_SCALE, me);
            }
        };
};

class spell_sha_of_pride_corrupted_touch : public SpellScriptLoader
{
    public:
        spell_sha_of_pride_corrupted_touch() : SpellScriptLoader("spell_sha_of_pride_corrupted_touch") { }

        class spell_sha_of_pride_corrupted_touch_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_of_pride_corrupted_touch_AuraScript);

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes mode)
            {
                if (!GetUnitOwner())
                    return;

                GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_CORRUPTED_TOUCH_DMG, true);
            }

            void Register()
            {
                AfterEffectRemove += AuraEffectApplyFn(spell_sha_of_pride_corrupted_touch_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_sha_of_pride_corrupted_touch_AuraScript();
        }
};

class spell_sha_of_pride_swelling_pride : public SpellScriptLoader
{
    public:
        spell_sha_of_pride_swelling_pride() : SpellScriptLoader("spell_sha_of_pride_swelling_pride") { }

        class spell_sha_of_pride_swelling_pride_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_of_pride_swelling_pride_SpellScript);

            void HandleHit(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                DoUniqueEffectsOnUnit(GetHitUnit());

                TryIncreasePrideOnUnit(GetHitUnit(), DEFAULT_PRIDE_INCREASE);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_of_pride_swelling_pride_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }

        private:

            void DoUniqueEffectsOnUnit(Unit* target)
            {
                Unit* caster = GetCaster();

                int32 currentPride = target->GetPower(POWER_ALTERNATE_POWER);

                if (currentPride >= 25 && currentPride < 50)
                {
                    caster->CastSpell(target, SPELL_BURSTING_PRIDE, true);
                }
                else if (currentPride >= 50 && currentPride < 75)
                {
                    Position l_MissilePos;
                    target->GetContactPoint(caster, l_MissilePos.m_positionX, l_MissilePos.m_positionY, l_MissilePos.m_positionZ);
                    target->GetFirstCollisionPosition(/*l_MissilePos,*/ frand(10.f, 15.f), frand(0.f, 2.f * float(M_PI)));
                    l_MissilePos.m_positionZ = target->GetPositionZ();

                    caster->AddAura(SPELL_PROJECTION_MARK, target);
                    caster->CastSpell(l_MissilePos, SPELL_PROJECTION_1, true);
                    target->CastSpell(l_MissilePos, SPELL_PROJECTION_MISSILE, true);
                }
                else if (currentPride >= 75 && currentPride < 100)
                {
                    caster->CastSpell(target, SPELL_AURA_OF_PRIDE, true);
                }
                else if (currentPride >= 100)
                {
                    if (target->HasAura(SPELL_OVERCOME_1))
                    {
                        caster->CastSpell(target, SPELL_OVERCOME_2, true);
                    }
                }
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_sha_of_pride_swelling_pride_SpellScript();
        }
};

class spell_sha_of_pride_mark_of_arrogance : public SpellScriptLoader
{
    public:
        spell_sha_of_pride_mark_of_arrogance() : SpellScriptLoader("spell_sha_of_pride_mark_of_arrogance") { }

        class spell_sha_of_pride_mark_of_arrogance_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_of_pride_mark_of_arrogance_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                const uint32 targetsCount = GetCaster()->GetMap()->Is25ManRaid() ? MARK_OF_ARROGANCE_COUNT_25 : MARK_OF_ARROGANCE_COUNT_10;

                if (targets.size() > targetsCount)
                {
                    Trinity::Containers::RandomResize(targets, targetsCount);
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_of_pride_mark_of_arrogance_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        class spell_sha_of_pride_mark_of_arrogance_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_of_pride_mark_of_arrogance_AuraScript);

            void HandleDispel(DispelInfo* dispelInfo)
            {
                if (Unit* dispeller = dispelInfo->GetDispeller())
                    TryIncreasePrideOnUnit(dispeller, DEFAULT_PRIDE_INCREASE);
            }

            void Register()
            {
                AfterDispel += AuraDispelFn(spell_sha_of_pride_mark_of_arrogance_AuraScript::HandleDispel);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_sha_of_pride_mark_of_arrogance_SpellScript();
        }

        AuraScript* GetAuraScript() const
        {
            return new spell_sha_of_pride_mark_of_arrogance_AuraScript();
        }
};

class spell_sha_of_pride_bursting_pride_dmg : public SpellScriptLoader
{
    public:
        spell_sha_of_pride_bursting_pride_dmg() : SpellScriptLoader("spell_sha_of_pride_bursting_pride_dmg") { }

        class spell_sha_of_pride_bursting_pride_dmg_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_of_pride_bursting_pride_dmg_SpellScript);

            void HandleHit(SpellEffIndex effIndex)
            {
                if (!GetHitUnit())
                    return;

                TryIncreasePrideOnUnit(GetHitUnit(), DEFAULT_PRIDE_INCREASE);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_of_pride_bursting_pride_dmg_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_sha_of_pride_bursting_pride_dmg_SpellScript();
        }
};

class spell_sha_of_pride_projection_missile : public SpellScriptLoader
{
    public:
        spell_sha_of_pride_projection_missile() : SpellScriptLoader("spell_sha_of_pride_projection_missile") { }

        class spell_sha_of_pride_projection_missile_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_of_pride_projection_missile_SpellScript);

            void HandleHit(SpellEffIndex effIndex)
            {
                if (!GetCaster())
                    return;

                WorldLocation const* loc = GetHitDest();

                bool doDamage = true;

                if (Unit* targetedPlayer = GetOriginalCaster())
                {
                    float dist = loc->GetExactDist2d(targetedPlayer);
                    if (dist < 4.0f)
                    {
                        doDamage = false;
                    }
                }

                if (Creature* p_ShaOfPride = GetShaOfPride(GetCaster()))
                {
                    if (doDamage)
                    {
                        p_ShaOfPride->CastSpell(loc->GetPositionX(), loc->GetPositionY(), loc->GetPositionZ(), SPELL_PROJECTION_DMG, true);
                    }
                    else
                    {
                        p_ShaOfPride->CastSpell(loc->GetPositionX(), loc->GetPositionY(), loc->GetPositionZ(), SPELL_PROJECTION_2, true);
                    }
                }
            }

            void Register()
            {
                OnEffectHit += SpellEffectFn(spell_sha_of_pride_projection_missile_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_sha_of_pride_projection_missile_SpellScript();
        }
};

class spell_sha_of_pride_projection_dmg : public SpellScriptLoader
{
    public:
        spell_sha_of_pride_projection_dmg() : SpellScriptLoader("spell_sha_of_pride_projection_dmg") { }

        class spell_sha_of_pride_projection_dmg_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_of_pride_projection_dmg_SpellScript);

            void HandleHit(SpellEffIndex effIndex)
            {
                if (!GetHitUnit())
                    return;

                TryIncreasePrideOnUnit(GetHitUnit(), DEFAULT_PRIDE_INCREASE);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_of_pride_projection_dmg_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_sha_of_pride_projection_dmg_SpellScript();
        }
};

class spell_sha_of_pride_aura_of_pride_dmg : public SpellScriptLoader
{
    public:
        spell_sha_of_pride_aura_of_pride_dmg() : SpellScriptLoader("spell_sha_of_pride_aura_of_pride_dmg") { }

        class spell_sha_of_pride_aura_of_pride_dmg_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_of_pride_aura_of_pride_dmg_SpellScript);

            void HandleHit(SpellEffIndex effIndex)
            {
                if (!GetHitUnit())
                    return;

                TryIncreasePrideOnUnit(GetHitUnit(), DEFAULT_PRIDE_INCREASE);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_of_pride_aura_of_pride_dmg_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_sha_of_pride_aura_of_pride_dmg_SpellScript();
        }
};

class spell_sha_of_pride_pride : public SpellScriptLoader
{
    public:
        spell_sha_of_pride_pride() : SpellScriptLoader("spell_sha_of_pride_pride") { }

        class spell_sha_of_pride_pride_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_of_pride_pride_AuraScript);

            void HandlePeriodic(AuraEffect const* aurEff)
            {
                if (!GetUnitOwner() || !GetCaster())
                    return;

                int32 power = GetUnitOwner()->GetPower(POWER_ALTERNATE_POWER);

                if (power >= 100 && !GetUnitOwner()->HasAura(SPELL_OVERCOME_1))
                {
                    GetCaster()->AddAura(SPELL_OVERCOME_1, GetUnitOwner());
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_of_pride_pride_AuraScript::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_sha_of_pride_pride_AuraScript();
        }
};

class spell_sha_of_pride_wounded_pride : public SpellScriptLoader
{
    public:
        spell_sha_of_pride_wounded_pride() : SpellScriptLoader("spell_sha_of_pride_wounded_pride") { }

        class spell_sha_of_pride_wounded_pride_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_of_pride_wounded_pride_AuraScript);

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                if (!GetUnitOwner())
                    return;

                Unit* attacker = eventInfo.GetActor();
                if (!attacker)
                    return;

                if (attacker->GetEntry() != NPC_SHA_OF_PRIDE)
                    return;

                TryIncreasePrideOnUnit(GetUnitOwner(), DEFAULT_PRIDE_INCREASE);
            }

            void Register()
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_of_pride_wounded_pride_AuraScript::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_sha_of_pride_wounded_pride_AuraScript();
        }
};

class spell_sha_of_pride_mocking_blast : public SpellScriptLoader
{
    public:
        spell_sha_of_pride_mocking_blast() : SpellScriptLoader("spell_sha_of_pride_mocking_blast") { }

        class spell_sha_of_pride_mocking_blast_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_of_pride_mocking_blast_SpellScript);

            void HandleHit(SpellEffIndex effIndex)
            {
                if (!GetHitUnit())
                    return;

                TryIncreasePrideOnUnit(GetHitUnit(), DEFAULT_PRIDE_INCREASE);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_of_pride_mocking_blast_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_sha_of_pride_mocking_blast_SpellScript();
        }
};

class spell_sha_of_pride_last_word : public SpellScriptLoader
{
    public:
        spell_sha_of_pride_last_word() : SpellScriptLoader("spell_sha_of_pride_last_word") { }

        class spell_sha_of_pride_last_word_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_of_pride_last_word_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.clear();

                if (!GetCaster())
                    return;

                if (Creature* pCreature = GetCaster()->ToCreature())
                {
                    std::list<Player*> unitTargets;

                    pCreature->GetPlayerListInGrid(unitTargets, 100.0f);

                    if (!unitTargets.empty())
                    {
                        unitTargets.sort(Trinity::DistanceOrderPred(pCreature));
                        unitTargets.resize(2);

                        for (std::list<Player*>::const_iterator itr = unitTargets.begin(); itr != unitTargets.end(); ++itr)
                        {
                            targets.push_back((*itr));
                        }
                    }
                }
            }

            void HandleHit(SpellEffIndex effIndex)
            {
                if (!GetHitUnit())
                    return;

                TryIncreasePrideOnUnit(GetHitUnit(), DEFAULT_PRIDE_INCREASE);
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_of_pride_last_word_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnEffectHitTarget += SpellEffectFn(spell_sha_of_pride_last_word_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_sha_of_pride_last_word_SpellScript();
        }
};

class spell_sha_of_pride_self_reflection : public SpellScriptLoader
{
    public:
        spell_sha_of_pride_self_reflection() : SpellScriptLoader("spell_sha_of_pride_self_reflection") { }

        class spell_sha_of_pride_self_reflection_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_of_pride_self_reflection_AuraScript);

            void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Creature* pCreature = GetUnitOwner()->ToCreature())
                {
                    pCreature->AI()->SelectTargetList(m_Targets, 25, SELECT_TARGET_RANDOM, 0.0f, true);

                    PrideOrderPred pred(false);
                    m_Targets.sort(pred);

                    if (m_Targets.size() > 5)
                        m_Targets.resize(5);
                }
            }

            void HandlePeriodic(AuraEffect const* aurEff)
            {
                if (!GetUnitOwner())
                    return;

                if (Creature* pCreature = GetUnitOwner()->ToCreature())
                {
                    if (m_Targets.empty())
                        return;

                    Unit* target = *(m_Targets.begin());
                    m_Targets.erase(m_Targets.begin());

                    pCreature->SummonCreature(NPC_REFLECTION, *target);
                }
            }

            void Register()
            {
                OnEffectApply += AuraEffectApplyFn(spell_sha_of_pride_self_reflection_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_of_pride_self_reflection_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }

        private:

            class PrideOrderPred
            {
                public:
                    PrideOrderPred(bool ascending = true) : m_ascending(ascending) {}
                    bool operator() (const Unit* a, const Unit* b) const
                    {
                        float rA = a->GetPower(POWER_ALTERNATE_POWER);
                        float rB = b->GetPower(POWER_ALTERNATE_POWER);
                        return m_ascending ? rA < rB : rA > rB;
                    }

                private:
                    const bool m_ascending;
            };

        private:

            std::list<Unit*> m_Targets;

        };

        AuraScript* GetAuraScript() const
        {
            return new spell_sha_of_pride_self_reflection_AuraScript();
        }
};

class spell_sha_of_pride_self_reflection_dmg : public SpellScriptLoader
{
    public:
        spell_sha_of_pride_self_reflection_dmg() : SpellScriptLoader("spell_sha_of_pride_self_reflection_dmg") { }

        class spell_sha_of_pride_self_reflection_dmg_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_of_pride_self_reflection_dmg_SpellScript);

            void HandleHit(SpellEffIndex effIndex)
            {
                if (!GetHitUnit())
                    return;

                TryIncreasePrideOnUnit(GetHitUnit(), DEFAULT_PRIDE_INCREASE);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_of_pride_self_reflection_dmg_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_sha_of_pride_self_reflection_dmg_SpellScript();
        }
};

class spell_sha_of_pride_corrupted_prison_periodic : public SpellScriptLoader
{
    public:
        spell_sha_of_pride_corrupted_prison_periodic() : SpellScriptLoader("spell_sha_of_pride_corrupted_prison_periodic") { }

        class spell_sha_of_pride_corrupted_prison_periodic_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_of_pride_corrupted_prison_periodic_AuraScript);

            void HandlePeriodic(AuraEffect const* aurEff)
            {
                if (!GetUnitOwner())
                    return;

                TryIncreasePrideOnUnit(GetUnitOwner(), DEFAULT_PRIDE_INCREASE);
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_of_pride_corrupted_prison_periodic_AuraScript::HandlePeriodic, EFFECT_2, SPELL_AURA_PERIODIC_DAMAGE);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_sha_of_pride_corrupted_prison_periodic_AuraScript();
        }
};

class spell_sha_of_pride_corrupted_prison_dmg : public SpellScriptLoader
{
    public:
        spell_sha_of_pride_corrupted_prison_dmg() : SpellScriptLoader("spell_sha_of_pride_corrupted_prison_dmg") { }

        class spell_sha_of_pride_corrupted_prison_dmg_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_of_pride_corrupted_prison_dmg_SpellScript);

            void HandleHit(SpellEffIndex effIndex)
            {
                if (!GetHitUnit())
                    return;

                TryIncreasePrideOnUnit(GetHitUnit(), DEFAULT_PRIDE_INCREASE);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_of_pride_corrupted_prison_dmg_SpellScript::HandleHit, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_sha_of_pride_corrupted_prison_dmg_SpellScript();
        }
};

class spell_sha_of_pride_unleashed : public SpellScriptLoader
{
    public:
        spell_sha_of_pride_unleashed() : SpellScriptLoader("spell_sha_of_pride_unleashed") { }

        class spell_sha_of_pride_unleashed_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_of_pride_unleashed_SpellScript);

            void HandleHit(SpellEffIndex effIndex)
            {
                if (!GetHitUnit())
                    return;

                PreventHitDefaultEffect(effIndex);

                if (Creature* pNorushen = GetHitUnit()->ToCreature())
                {
                    pNorushen->AI()->DoAction(ACTION_UNLEASHED);
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_of_pride_unleashed_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_INSTAKILL);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_sha_of_pride_unleashed_SpellScript();
        }
};

class spell_sha_of_pride_unleashed_dmg : public SpellScriptLoader
{
    public:
        spell_sha_of_pride_unleashed_dmg() : SpellScriptLoader("spell_sha_of_pride_unleashed_dmg") { }

        class spell_sha_of_pride_unleashed_dmg_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_of_pride_unleashed_dmg_SpellScript);

            void HandleHit(SpellEffIndex effIndex)
            {
                if (!GetHitUnit())
                    return;

                TryIncreasePrideOnUnit(GetHitUnit(), DEFAULT_PRIDE_INCREASE);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_of_pride_unleashed_dmg_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_sha_of_pride_unleashed_dmg_SpellScript();
        }
};

class spell_sha_of_pride_gift_titans : public SpellScriptLoader
{
    public:
        spell_sha_of_pride_gift_titans() : SpellScriptLoader("spell_sha_of_pride_gift_titans") { }

        class spell_sha_of_pride_gift_titans_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_of_pride_gift_titans_SpellScript);

            void HandleCast()
            {
                Unit* caster = GetCaster();
                if (!caster)
                    return;

                std::list<Player*> playerList;
                caster->GetPlayerListInGrid(playerList, 100.0f);
                playerList.remove_if(Trinity::UnitAuraCheck(true, SPELL_OVERCOME_1));

                uint32 targetsCount = caster->GetMap()->Is25ManRaid() ? GIFT_OF_TITANS_COUNT_25 : GIFT_OF_TITANS_COUNT_10;
                Trinity::Containers::RandomResize(playerList, targetsCount);

                for (Player* player : playerList)
                {
                    caster->AddAura(SPELL_GIFT_OF_THE_TITANS_1, player);
                }
            }

            void Register() override
            {
                OnCast += SpellCastFn(spell_sha_of_pride_gift_titans_SpellScript::HandleCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_of_pride_gift_titans_SpellScript();
        }
};

class spell_sha_of_pride_gift_of_the_titans_aura : public SpellScriptLoader
{
    public:
        spell_sha_of_pride_gift_of_the_titans_aura() : SpellScriptLoader("spell_sha_of_pride_gift_of_the_titans_aura") { }

        class spell_sha_of_pride_gift_of_the_titans_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_of_pride_gift_of_the_titans_aura_AuraScript);

            void HandlePeriodicTick(AuraEffect const* aurEff)
            {
                PreventDefaultAction();

                Unit* owner = GetUnitOwner();
                if (!owner)
                    return;

                std::list<Player*> playerList;
                GetPlayerListInGrid(playerList, owner, 8.f);

                playerList.remove_if(Trinity::UnitAuraCheck(false, SPELL_GIFT_OF_THE_TITANS_1));

                uint8 neededCount = owner->GetMap()->Is25ManRaid() ? 7 : 2;
                if (playerList.size() >= neededCount)
                {
                    if (!owner->HasAura(SPELL_POWER_OF_THE_TITANS))
                        owner->AddAura(SPELL_POWER_OF_THE_TITANS, owner);
                }
                else
                {
                    if (owner->HasAura(SPELL_POWER_OF_THE_TITANS))
                        owner->RemoveAura(SPELL_POWER_OF_THE_TITANS);
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_of_pride_gift_of_the_titans_aura_AuraScript::HandlePeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_of_pride_gift_of_the_titans_aura_AuraScript();
        }
};

class spell_sha_of_pride_unstable_corruption_dmg : public SpellScriptLoader
{
    public:
        spell_sha_of_pride_unstable_corruption_dmg() : SpellScriptLoader("spell_sha_of_pride_unstable_corruption_dmg") { }

        class spell_sha_of_pride_unstable_corruption_dmg_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_of_pride_unstable_corruption_dmg_SpellScript);

            void HandleHit(SpellEffIndex effIndex)
            {
                if (!GetHitUnit())
                    return;

                TryIncreasePrideOnUnit(GetHitUnit(), DEFAULT_PRIDE_INCREASE);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_of_pride_unstable_corruption_dmg_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_sha_of_pride_unstable_corruption_dmg_SpellScript();
        }
};

class spell_sha_of_pride_collapsing_rift : public SpellScriptLoader
{
    public:
        spell_sha_of_pride_collapsing_rift() : SpellScriptLoader("spell_sha_of_pride_collapsing_rift") { }

        class spell_sha_of_pride_collapsing_rift_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_of_pride_collapsing_rift_SpellScript);

            void HandleHit(SpellEffIndex effIndex)
            {
                if (!GetHitUnit())
                    return;

                TryIncreasePrideOnUnit(GetHitUnit(), DEFAULT_PRIDE_INCREASE);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_of_pride_collapsing_rift_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_sha_of_pride_collapsing_rift_SpellScript();
        }
};

class spell_sha_unstable_corruiption_periodic_summon : public SpellScriptLoader
{
public:
    spell_sha_unstable_corruiption_periodic_summon() : SpellScriptLoader("spell_sha_unstable_corruiption_periodic_summon") { }

    class spell_sha_unstable_corruiption_periodic_summon_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sha_unstable_corruiption_periodic_summon_AuraScript);

        void HandlePeriodic(AuraEffect const* aurEff)
        {
            if (!GetUnitOwner() || !GetUnitOwner()->GetAI())
                return;

            GetUnitOwner()->SummonCreature(NPC_RIFT_OF_CORRUPTION, Trinity::Containers::SelectRandomContainerElement(s_RiftOfCorruptionPos));
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_unstable_corruiption_periodic_summon_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_sha_unstable_corruiption_periodic_summon_AuraScript();
    }
};

class spell_sha_unstable_corruiption_periodic_trigger_missile : public SpellScriptLoader
{
public:
    spell_sha_unstable_corruiption_periodic_trigger_missile() : SpellScriptLoader("spell_sha_unstable_corruiption_periodic_trigger_missile") { }

    class spell_sha_unstable_corruiption_periodic_trigger_missile_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sha_unstable_corruiption_periodic_trigger_missile_AuraScript);

        void HandlePeriodic(AuraEffect const* aurEff)
        {
            PreventDefaultAction();

            TempSummon* caster = GetCaster() ? GetCaster()->ToTempSummon() : nullptr;
            if (!caster || !caster->GetAI())
                return;

            Unit* owner = caster->GetSummoner();
            if (!owner || !owner->GetAI())
                return;

            if (Unit* target = owner->GetAI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                GetCaster()->CastSpell(target, SPELL_UNSTABLE_CORRUPTION_MISSILE, false);
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_unstable_corruiption_periodic_trigger_missile_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_sha_unstable_corruiption_periodic_trigger_missile_AuraScript();
    }
};

struct BanishmentSelector : public std::unary_function<Unit*, bool>
{
    BanishmentSelector() {}

    bool operator()(Unit const* target) const
    {
        if (!target)
            return false;

        if (!target->IsPlayer())
            return false;

        if (target->ToPlayer()->GetRoleForGroup() == Roles::ROLE_TANK)
            return false;

        if (target->HasAura(Spells::SPELL_BANISHMENT))
            return false;

        return true;
    }
};

/// Called by Banishment - 146823
class spell_sha_of_pride_banishment_aoe_1 : public SpellScriptLoader
{
    public:
        spell_sha_of_pride_banishment_aoe_1() : SpellScriptLoader("spell_sha_of_pride_banishment_aoe_1") { }

        class spell_sha_of_pride_banishment_aoe_1_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_of_pride_banishment_aoe_1_SpellScript);

            bool Load() override
            {
                return GetCaster() && GetCaster()->IsCreature();
            }

            void FilterTargets(std::list<WorldObject*> & p_Targets)
            {
                // Recalculate targets
                p_Targets.clear();

                if (Creature* pCreature = GetCaster()->ToCreature())
                {
                    const uint8 l_Count = pCreature->GetMap()->Is25ManRaid() ? BanishmentSizes::MAN_25 : BanishmentSizes::MAN_10;

                    std::list<Unit*> l_NewTargets;
                    pCreature->AI()->SelectTargetList(l_NewTargets, BanishmentSelector(), l_Count, SelectAggroTarget::SELECT_TARGET_RANDOM);

                    for (auto l_Target : l_NewTargets)
                        p_Targets.push_back(l_Target);

                    Trinity::Containers::RandomResize(p_Targets, l_Count);
                }
            }

            void DoEffectHit(SpellEffIndex /*effIndex*/)
            {
                Unit* l_Caster = GetCaster();
                Unit* l_Target = GetHitUnit();
                if (!l_Caster || !l_Target)
                    return;

                if (Creature* l_Creature = l_Caster->ToCreature())
                {
                    l_Creature->AI()->SetGUID(l_Target->GetGUID(), eData::DATA_BANISHED_PLAYER);
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_of_pride_banishment_aoe_1_SpellScript::FilterTargets, SpellEffIndex::EFFECT_0, Targets::TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHit += SpellEffectFn(spell_sha_of_pride_banishment_aoe_1_SpellScript::DoEffectHit, SpellEffIndex::EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_sha_of_pride_banishment_aoe_1_SpellScript();
        }
};

/// Called by Orb of Light - 145345
class spell_sha_of_pride_orb_of_light_debuff : public SpellScriptLoader
{
    public:
        spell_sha_of_pride_orb_of_light_debuff() : SpellScriptLoader("spell_sha_of_pride_orb_of_light_debuff") { }

        class spell_sha_of_pride_orb_of_light_debuff_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_of_pride_orb_of_light_debuff_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.clear();

                Unit* l_Caster = GetCaster();
                if (l_Caster == nullptr)
                    return;

                Creature* l_Sha = GetShaOfPride(l_Caster);
                if (l_Sha == nullptr)
                    return;

                auto l_ShaAI = CAST_AI(boss_sha_of_pride::boss_sha_of_prideAI, l_Sha->AI());
                if (l_ShaAI == nullptr)
                    return;

                if (auto l_Fragment = ObjectAccessor::GetCreature(*l_Sha, l_ShaAI->GetFragmentGUID(l_Caster->GetGUID())))
                    targets.push_back(l_Fragment);
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_of_pride_orb_of_light_debuff_SpellScript::FilterTargets, SpellEffIndex::EFFECT_0, Targets::TARGET_UNIT_SRC_AREA_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_sha_of_pride_orb_of_light_debuff_SpellScript();
        }
};

/// Called by Orb of Light - 145299
struct spell_area_sha_of_pride_orb_of_light : AreaTriggerAI
{
    spell_area_sha_of_pride_orb_of_light(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* target) override
    {
        if (at->GetCaster() != target)
            return;

        if (!target->IsPlayer()/* || !(p_Target->GetPhaseMask() & 2)*/)
            return;

        if (at->GetDuration() != 0)
        {
            target->CastSpell(target, Spells::SPELL_ORB_OF_LIGHT_DEBUFF, true);
            at->SetDuration(0);
        }
    }
};

/// Ethereal Corruption - 149027
struct spell_area_sha_of_pride_ethereal_corruption : AreaTriggerAI
{
    spell_area_sha_of_pride_ethereal_corruption(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* target)
    {
        if (!target->IsPlayer() || target->HasAura(Spells::SPELL_BANISHMENT_STUN))
            return;

        Unit* l_Caster = at->GetCaster();
        if (!l_Caster)
            return;

        l_Caster->CastSpell(target, Spells::SPELL_ETHEREAL_CORRUPTION_DMG, true);

        // HACK:
        // Some players can survive after damage
        if (target->IsAlive())
            l_Caster->Kill(target);
    }

    void OnUpdate(uint32 diff)
    {
        if (m_UpdateTimer > diff)
        {
            m_UpdateTimer -= diff;
            return;
        }

        m_UpdateTimer = 1 * IN_MILLISECONDS;

        Unit* l_Caster = at->GetCaster();
        if (!l_Caster)
            return;

        /*std::list<ObjectGuid> guidList;
        GuidUnorderedSet const& guids = at->GetInsideUnits();
        for (ObjectGuid guid : guids)
            guidList.push_back(guid);*/

        auto l_Targets = at->GetInsideUnits();
        for (auto l_TargetGuid : l_Targets)
        {
            if (Unit* l_Target = ObjectAccessor::GetUnit(*l_Caster, l_TargetGuid))
                l_Caster->CastSpell(l_Target, Spells::SPELL_ETHEREAL_CORRUPTION_DMG, true);
        }
    }

    uint32 m_UpdateTimer = 1 * IN_MILLISECONDS;
};

void AddSC_boss_sha_of_pride()
{
    new boss_sha_of_pride();                        // 71734
    new npc_sha_of_pride_norushen();                // 71965
    new npc_sha_of_pride_lingering_corruption();    // 72791
    new npc_sha_of_pride_manifestation_of_pride();  // 71946
    new npc_sha_of_pride_reflection();              // 72172
    new npc_sha_of_pride_rift_of_corruption();      // 72846
    new go_sha_of_pride_shadow_prison_trap();       // 221758, 221759, 221757, 221755, 221750, 221754, 221753, 221751, 221752, 221761, 221760, 221756
    new npc_sha_of_pride_jaina_proudmoore();        // 73598
    new npc_sha_of_pride_lorthemar_theron();        // 73605
    new npc_sha_of_pride_portal_to_orgrimmar();     // 73535 73536
    new npc_sha_of_pride_ethereal_corruption();     // 73972
    new npc_sha_of_pride_corrupted_fragment();      // 72569

    new spell_sha_of_pride_corrupted_touch();       // 149207
    new spell_sha_of_pride_swelling_pride();        // 144400
    new spell_sha_of_pride_mark_of_arrogance();     // 144351
    new spell_sha_of_pride_bursting_pride_dmg();    // 144911
    new spell_sha_of_pride_projection_missile();    // 145066
    new spell_sha_of_pride_projection_dmg();        // 145320
    new spell_sha_of_pride_aura_of_pride_dmg();     // 146818
    new spell_sha_of_pride_pride();                 // 144343
    new spell_sha_of_pride_wounded_pride();         // 144358
    new spell_sha_of_pride_mocking_blast();         // 144379
    new spell_sha_of_pride_last_word();             // 144370
    new spell_sha_of_pride_self_reflection();       // 144800
    new spell_sha_of_pride_self_reflection_dmg();   // 144788
    new spell_sha_of_pride_corrupted_prison_periodic(); // 144574, 144636, 144683, 144684
    new spell_sha_of_pride_corrupted_prison_dmg();  // 144615
    new spell_sha_of_pride_unleashed();             // 144832
    new spell_sha_of_pride_unleashed_dmg();         // 144836
    new spell_sha_of_pride_gift_titans();           // 146595
    new spell_sha_of_pride_gift_of_the_titans_aura();   // 144359
    new spell_sha_of_pride_unstable_corruption_dmg();   // 147198
    new spell_sha_of_pride_collapsing_rift();       // 147388
    new spell_sha_unstable_corruiption_periodic_summon();  // 147183
    new spell_sha_unstable_corruiption_periodic_trigger_missile();  // 147389
    new spell_sha_of_pride_banishment_aoe_1();      // 146823
    new spell_sha_of_pride_orb_of_light_debuff();   // 145345

    RegisterAreaTriggerAI(spell_area_sha_of_pride_orb_of_light); // 145299
    RegisterAreaTriggerAI(spell_area_sha_of_pride_ethereal_corruption); // 149027
}
