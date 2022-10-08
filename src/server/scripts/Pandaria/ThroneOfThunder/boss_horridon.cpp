#include "throne_of_thunder.h"
#include "GridNotifiers.h"
#include "Vehicle.h"
#include "GameObjectAI.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum eSpells
{
    //===============================================
    // Horridon

    // Triple Puncture
    SPELL_TRIPLE_PUNCTURE = 136767, // Casted on Main Tank

    // Double Swipe
    SPELL_DOUBLE_SWIPE = 136741, // Launch everything
    SPELL_DOUBLE_SWIPE_FRONT = 136740, // Frontal damages
    SPELL_DOUBLE_SWIPE_BACK = 136739, // Back damages

    // Charge
    SPELL_CHARGE = 136769,

    // Dire Call
    SPELL_DIRE_CALL = 137458, // Launch everything
    SPELL_SUMMON_DIREHORN_SPIRIT_SELECTOR = 140947,
    SPELL_SUMMON_DIREHORN_SPIRIT = 140945,

    // After a charge at a door
    SPELL_HEADACHE = 137294,
    SPELL_CRACKED_SHELL = 137240,

    // Enrage
    SPELL_RAMPAGE = 136821,

    //===============================================
    // Farraki
    SPELL_STONE_GAZE = 136708, // Stonegazer
    SPELL_BLAZING_SUNLIGHT = 136719, // Wastewalker
    SPELL_SUMMON_SAND_TRAP = 136725, // Wastewalker

    //===============================================
    // Gurubashi
    SPELL_RENDING_CHARGE = 136653, // Bloodlord
    SPELL_RENDING_CHARGE_DAMAGES = 136654, // Bloodlord 
    SPELL_VENOM_BOLT_VOLLEY = 136587, // Venom Priest
    SPELL_SUMMON_VENOMOUS_EFFUSION = 136644, // Venom Priest

    //===============================================
    // Drakkari
    SPELL_UNCONTROLLED_ABOMINATION = 136709, // Risen Drakkari Champion / Warrior
    SPELL_DEADLY_PLAGUE = 136710, // Risen Drakkari Champion / Warrior 
    SPELL_MORTAL_STRIKE = 136670, // Frozen Warlord
    SPELL_SUMMON_FROZEN_ORB = 136564, // Frozen Warlord

    //===============================================
    // Amani
    SPELL_FIREBALL = 136465, // Flame Caster
    SPELL_SWIPE = 136463, // Warbear
    SPELL_CHAIN_LIGHTNING = 136480, // Beast Shaman
    SPELL_HEX_OF_CONFUSION = 136512, // 
    SPELL_SUMMON_LIGHTNING_NOVA_TOTEM = 136487, // 

    //===============================================
    // Zandalari
    SPELL_DINO_MENDING = 136797, // Dinomancer
    SPELL_DINO_FORM = 137237, // 
    SPELL_SUMMON_ORB_OF_CONTROL_FARRAKI = 137445, // 
    SPELL_SUMMON_ORB_OF_CONTROL_GURUBASHI = 137447, // 
    SPELL_SUMMON_ORB_OF_CONTROL_DRAKKARI = 137448, // 
    SPELL_SUMMON_ORB_OF_CONTROL_AMANI = 137449, // 

    //===============================================
    // Summons
    SPELL_DIRE_FIXATION = 140946, // Dire Horn Spirit
    SPELL_WEAK_LINK = 140948, // Dire Horn Spirit
    SPELL_SAND_TRAP_PERIODIC = 136724,
    SPELL_SAND_TRAP = 136723, // SpellScript needed (radius)
    SPELL_SUMMON_LIVING_POISON = 136644, // Three times ?
    SPELL_LIVING_POISON_PERIODIC = 136645,
    SPELL_LIVING_POISON = 136646,
    SPELL_FROZEN_BOLT_PERIODIC = 136572,
    SPELL_FROZEN_BOLT = 136573, // Frozen Orb
    SPELL_LIGHTNING_NOVA_PERIODIC = 136489, // Lightning Nova Totem
    SPELL_LIGHTNING_NOVA = 136490,

    //===============================================
    // Jalak
    SPELL_BESTIAL_CRY = 136817,

    //===============================================
    // Orb of Control
    SPELL_CONTROL_HORRIDON_FARRAKI = 137433,
    SPELL_CONTROL_HORRIDON_GURUBASHI = 137442,
    SPELL_CONTROL_HORRIDON_DRAKKARI = 137443,
    SPELL_CONTROL_HORRIDON_AMANI = 137444,
};

enum eEvents
{
    //===============================================
    // Horridon
    EVENT_TRIPLE_PUNCTURE = 1,
    EVENT_DOUBLE_SWIPE = 2,
    EVENT_HORRIDON_CHARGE = 3, // 
    EVENT_DIRE_CALL = 4,
    EVENT_PREPARE_CHARGE = 5, // Pseudo hack
    EVENT_CHARGE_AT_DOOR = 6,
    EVENT_BERSERK = 34,
    EVENT_EVADE_CHECK = 35,

    //===============================================
    // Farraki
    EVENT_STONE_GAZE = 7,
    EVENT_BLAZING_LIGHT = 8,
    EVENT_SUMMON_SAND_TRAP = 9,

    //===============================================
    // Gurubashi
    EVENT_RENDING_CHARGE = 10,
    EVENT_GURUBASHI_VENOM_BOLT_VOLLEY = 11,
    EVENT_SUMMON_VENOMOUS_EFFUSION = 12,

    //===============================================
    // Drakkari
    EVENT_SWITCH_TARGET = 13, // Risen Drakkari doesn't have a real threat list
    EVENT_MORTAL_STRIKE = 14,
    EVENT_SUMMON_FROZEN_ORB = 15,

    //===============================================
    // Amani
    EVENT_FIREBALL = 16,
    EVENT_SWIPE = 17,
    EVENT_CHAIN_LIGHTNING = 18,
    EVENT_HEX_OF_CONFUSION = 19,
    EVENT_SUMMON_LIGHTNING_NOVA_TOTEM = 20,

    //===============================================
    // Zandalari
    EVENT_DINO_MENDING = 21,

    //===============================================
    // Summons
    EVENT_EFFUSION_VENOM_BOLT_VOLLEY = 22,

    //===============================================
    // Jalak
    EVENT_BESTIAL_CRY = 23,

    //===============================================
    // Helper
    EVENT_SUMMON_MINOR = 24, // 
    EVENT_SUMMON_MAJOR = 25, // 
    EVENT_SUMMON_ZANDALARI_DINOMANCER = 26, // 
    EVENT_SUMMON_MINOR_DRAKKARI = 27, // 
    EVENT_TRANSITION = 28, // 

    //===============================================
    // RP Event Helper
    EVENT_CHECK_PLAYERS = 29, // Every 500 ms to not flood the world
    EVENT_INTRO_PART_I = 30, // Jalak begins it's speech... 
    EVENT_INTRO_PART_II = 31, // Continues
    EVENT_INTRO_PART_III = 32, // Horridon breaks free and go and kill every... oh wait... that's not the time
    EVENT_INTRO_PART_IV = 33, // Now Horridon breaks free 

    //===============================================
    // Direhorn
    EVENT_TARGET_A_RANDOM_PLAYER,
    EVENT_DAMAGE_IF_NEARBY,
    EVENT_RETURN_TO_COMBAT,
    EVENT_CALL_JALAK,
    EVENT_DOUBLE_SWIPE_ACTION,
};

enum eCreatures
{
    //===============================================
    // Farraki
    MOB_SUL_LITHUZ_STONEGAZER = 69172,
    MOB_FARRAKI_SKIRMISHER = 69173,
    MOB_FARRAKI_WASTEWALKER = 69175, // Total of three will be called to action

    //===============================================
    // Gurubashi
    MOB_GURUBASHI_BLOODLORD = 69167,
    MOB_GURUBASHI_VENOM_PRIEST = 69164, // Total of three will be called to action

    //===============================================
    // Drakkari
    MOB_RISEN_DRAKKARI_WARRIOR = 69184,
    MOB_RISEN_DRAKKARI_CHAMPION = 69185,
    MOB_DRAKKARI_FROZEN_WARLORD = 69178, // Total of three will be called to action

    //===============================================
    // Amani
    MOB_AMANI_SHI_PROTECTOR = 69169,
    MOB_AMANI_SHI_FLAME_CASTER = 69168,
    MOB_AMANI_WARBEAR = 69177, // Total of three will be called to action
    MOB_AMANI_SHI_BEAST_SHAMAN = 69176, // Riding Amani Warbears, attackable once Amani Warbear has fallen

    //===============================================
    // Zandalari
    MOB_ZANDALARI_DINOMANCER = 69221, // Jumping periodically during subphases

    //===============================================
    // Summons
    MOB_DIREHORN_SPIRIT = 70688, // Only spawn in Heroic
    MOB_SAND_TRAP = 69346, // Summoned by Farraki Wastewalker
    MOB_VENOMOUS_EFFUSION = 69314, // Summoned by Gurubashi Venom Priests
    MOB_LIVING_POISON = 69313, // Created when a Venomous Effusion is created
    MOB_FROZEN_ORB = 69268, // Summoned by Drakkari Frozen Warlords
    MOB_LIGHTNING_NOVA_TOTEM = 69215, // Summoned by Amani'Shi Beast Shaman

    //===============================================
    // Others
};

enum eActions
{
    //===============================================
    // Controller
    ACTION_FIGHT_BEGIN = 0,
    ACTION_FIGHT_RESET = 1,
    ACTION_ENTER_NEXT_TRASH_PHASE = 2,
    ACTION_FIGHT_END = 3,
    ACTION_PREPARE_TRANSITION = 4,
    ACTION_RESET_AFTER_CRASH = 10,

    //===============================================
    // Jalak
    ACTION_ENTER_PHASE_TWO = 5,

    //===============================================
    // Horridon
    ACTION_INTRO = 6,
    ACTION_PREPARE_CHARGE = 7,
    ACTION_CONTROL_APPLY = 8,

    //===============================================
    //Living Poison
    ACTION_LIVING_POISON_DESPAWN = 9,
    ACTION_DOUBLE_SWIPE = 12,
    ACTION_FORCE_RESET = 13,
};


enum eMotions
{
    //===============================================
    // Majors
    MOTION_MAJOR_JUMP = 6845,

    //===============================================
    // Zandalari Dinomancers
    MOTION_DINOMANCER_JUMP = 7849,

    //===============================================
    // Horridon
    MOTION_HORRIDON_CHARGE = 4551,
    MOTION_HORRIDON_DOOR_CHARGE = 3205,

};


enum eTalks : uint32
{
    TALK_INTRO_FIRST = 0, // Welcome weaklings
    TALK_INTRO_SECOND = 1, // The tribes have assembled
    TALK_INTRO_THIRD = 2, // Now, witness the true might
    TALK_ENTER_PHASE_2 = 3, // Hahaha, now it be my turn
    TALK_DRAKKARI = 4, // Drakkari tribe
    TALK_GURUBASHI = 5,
    TALK_FARRAKI = 6,
    TALK_AMANI = 7,
    TALK_ON_JALAK_KILLED_UNIT = 8, // Ya skull
    TALK_ON_HORRIDON_KILLED_UNIT = 9, // Da'kala koraste

    EMOTE_FARRAKI = 0,
    EMOTE_GURUBASHI = 1,
    EMOTE_DRAKKARI = 2,
    EMOTE_AMANI = 3,
    EMOTE_CHARGE = 4,
    EMOTE_FARAKKI_DOOR = 5,
    EMOTE_GURUBASHI_DOOR = 6,
    EMOTE_DRAKKARI_DOOR = 7,
    EMOTE_AMANI_DOOR = 8,
};

enum eGameObjects
{
    //===============================================
    // Orbs of Control
    GOB_ORB_OF_CONTROL_FARRAKI = 218193,
    GOB_ORB_OF_CONTROL_GURUBASHI = 218374,
    GOB_ORB_OF_CONTROL_DRAKKARI = 218375,
    GOB_ORB_OF_CONTROL_AMANI = 218376,

    //===============================================
    // Others
    GOB_HORRIDON_PRISON_DOOR = 218674,
};

enum eDatas : uint32
{
    DATA_AMANI_BEAST_SHAMAN_LIGHTNING_COUNT = 0, // To know how many time we stroke
};


enum eBossPhases : uint32
{
    BOSS_PHASE_SUMMONS = 0,
    BOSS_PHASE_JALAK = 1
};
#define MAX_BOSS_PHASE BOSS_PHASE_JALAK + 1

enum eTrashPhases : uint32
{
    TRASH_PHASE_FARRAKI = 0,
    TRASH_PHASE_GURUBASHI = 1,
    TRASH_PHASE_DRAKKARI = 2,
    TRASH_PHASE_AMANI = 3,

    MAX_TRASH_PHASE = TRASH_PHASE_AMANI + 1,
};


enum eMajorsCycle
{
    MAJOR_CYCLE_FIRST = 0,
    MAJOR_CYCLE_SECOND = 1,

    MAX_MAJOR_CYCLE = 2,
};


enum eDrakkariCycle
{
    DRAKKARI_CYCLE_FIRST = 0,
    DRAKKARI_CYCLE_SECOND = 1,

    MAX_DRAKKARI_CYCLE = 2,
};

//=========================================================
// Positions

#define MAX_SUMMON_POSITIONS_BY_PHASE   3
#define MAX_JUMP_POSITIONS_BY_PHASE     3

// Major trashes jump positions
static const Position farrakiWastewalkerJumpPositions[MAX_JUMP_POSITIONS_BY_PHASE] =
{
    { 5467.25f, 5816.40f, 129.9f, 4.08f },
    { 5483.03f, 5790.85f, 129.9f, 3.16f },
    { 5468.46f, 5797.77f, 129.9f, 3.94f },
};

static const Position gurubashiVenomPriestJumpPositions[MAX_JUMP_POSITIONS_BY_PHASE] =
{
    { 5501.31f, 5709.33f, 129.9f, 2.12f },
    { 5474.69f, 5712.25f, 129.9f, 2.58f },
    { 5459.25f, 5694.25f, 129.9f, 1.09f },
};

static const Position drakkariFrozenWarlordJumpPositions[MAX_JUMP_POSITIONS_BY_PHASE] =
{
    { 5400.35f, 5693.92f, 129.9f, 0.72f },
    { 5392.05f, 5711.79f, 129.9f, 0.91f },
    { 5371.40f, 5728.19f, 129.9f, 0.60f },
};

static const Position amaniWarbearJumpPositions[MAX_JUMP_POSITIONS_BY_PHASE] =
{
    { 5363.80f, 5787.88f, 129.90f, 5.38f },
    { 5385.03f, 5793.05f, 129.90f, 5.62f },
    { 5397.14f, 5811.65f, 129.90f, 5.16f },
};


// Summoning of minor and medium trashes positions
static const Position farrakiTrashSummonPositions[MAX_SUMMON_POSITIONS_BY_PHASE] =
{
    { 5505.863281f, 5841.025391f, 130.537231f, 0.000000f },
    { 5514.541992f, 5841.049316f, 130.537231f, 0.000000f },
    { 5513.420898f, 5827.835938f, 130.537231f, 0.000000f },
};

static const Position gurubashiTrashSummonPositions[MAX_SUMMON_POSITIONS_BY_PHASE] =
{
    { 5520.958008f, 5675.670898f, 130.537231f, 0.000000f },
    { 5519.500000f, 5667.600098f, 130.537231f, 0.000000f },
    { 5509.516113f, 5668.375000f, 130.537231f, 0.000000f },
};

static const Position drakkariTrashSummonPositions[MAX_SUMMON_POSITIONS_BY_PHASE] =
{
    { 5358.775391f, 5662.011719f, 130.537231f, 0.000000f },
    { 5346.132324f, 5668.255859f, 130.537231f, 0.000000f },
    { 5346.598633f, 5677.144043f, 130.537231f, 0.000000f },
};

static const Position amaniTrashSummonPositions[MAX_SUMMON_POSITIONS_BY_PHASE] =
{
    { 5346.283203f, 5824.987305f, 130.537231f, 0.000000f },
    { 5348.529785f, 5839.762207f, 130.537231f, 0.000000f },
    { 5360.542969f, 5844.966309f, 130.537231f, 0.000000f },
};


// Jump positions for Zandalari Dinomancers
static const Position zandalariDinomancersJumpPositions[MAX_TRASH_PHASE][MAX_JUMP_POSITIONS_BY_PHASE] =
{
    {
        { 5467.25f, 5816.40f, 129.9f, 4.08f },
        { 5483.03f, 5790.85f, 129.9f, 3.16f },
        { 5468.46f, 5797.77f, 129.9f, 3.94f },
    },
    {
        { 5501.31f, 5709.33f, 129.9f, 2.12f },
        { 5474.69f, 5712.25f, 129.9f, 2.58f },
        { 5459.25f, 5694.25f, 129.9f, 1.09f },
    },
    {
        { 5400.35f, 5693.92f, 129.9f, 0.72f },
        { 5392.05f, 5711.79f, 129.9f, 0.91f },
        { 5371.40f, 5728.19f, 129.9f, 0.60f },
    },
    {
        { 5363.80f, 5787.88f, 129.90f, 5.38f },
        { 5385.03f, 5793.05f, 129.90f, 5.62f },
        { 5397.14f, 5811.65f, 129.90f, 5.16f },
    }
};

// Summoning positions for Zandalari Dinomancers
static const Position zandalariDinomancersSummonPositions[] =
{
    { 5326.83f, 5787.72f, 169.237f, 6.10253f },
    { 5536.14f, 5721.06f, 169.238f, 2.95279f },
    { 5325.51f, 5720.81f, 169.237f, 0.32948f },
    { 5418.50f, 5666.55f, 192.349f, 1.45472f },
    { 5447.01f, 5667.53f, 192.352f, 1.64919f },
    { 5340.08f, 5648.40f, 190.758f, 0.87616f },
    { 5521.05f, 5649.76f, 190.653f, 2.39193f },
    { 5537.03f, 5784.27f, 169.238f, 3.67703f },
    { 5534.14f, 5838.86f, 190.416f, 3.98585f },
    { 5377.32f, 5884.95f, 190.356f, 5.23621f },
};

// Relocation of Horridon's Home Position
static const Position middlePosition = { 5431.621094f, 5763.865723f, 129.606461f, 1.57860f };

static uint32 GetNewEmoteBySpell(uint32 spellId)
{
    switch (spellId)
    {
    case SPELL_CONTROL_HORRIDON_FARRAKI:
        return EMOTE_FARAKKI_DOOR;
    case SPELL_CONTROL_HORRIDON_GURUBASHI:
        return EMOTE_GURUBASHI_DOOR;
    case SPELL_CONTROL_HORRIDON_DRAKKARI:
        return EMOTE_DRAKKARI_DOOR;
    case SPELL_CONTROL_HORRIDON_AMANI:
        return EMOTE_AMANI_DOOR;
    }
    return 0;
}

static uint32 GetSummoningOrbSpellByPhase(uint32 phase)
{
    switch (phase)
    {
    case TRASH_PHASE_FARRAKI:
        return SPELL_SUMMON_ORB_OF_CONTROL_FARRAKI;

    case TRASH_PHASE_GURUBASHI:
        return SPELL_SUMMON_ORB_OF_CONTROL_GURUBASHI;

    case TRASH_PHASE_DRAKKARI:
        return SPELL_SUMMON_ORB_OF_CONTROL_DRAKKARI;

    case TRASH_PHASE_AMANI:
        return SPELL_SUMMON_ORB_OF_CONTROL_AMANI;

    default:
        return 0;
    }
}

static uint32 GetControlSpellByOrb(GameObject* pOrb)
{
    switch (pOrb->GetEntry())
    {
    case GOB_ORB_OF_CONTROL_FARRAKI:
        return SPELL_CONTROL_HORRIDON_FARRAKI;

    case GOB_ORB_OF_CONTROL_GURUBASHI:
        return SPELL_CONTROL_HORRIDON_GURUBASHI;

    case GOB_ORB_OF_CONTROL_DRAKKARI:
        return SPELL_CONTROL_HORRIDON_DRAKKARI;

    case GOB_ORB_OF_CONTROL_AMANI:
        return SPELL_CONTROL_HORRIDON_AMANI;

    default:
        return 0;
    }
}

static uint32 GetControlSpellByPhase(eTrashPhases ePhase)
{
    switch (ePhase)
    {
    case TRASH_PHASE_FARRAKI:
        return SPELL_CONTROL_HORRIDON_FARRAKI;

    case TRASH_PHASE_GURUBASHI:
        return SPELL_CONTROL_HORRIDON_GURUBASHI;

    case TRASH_PHASE_DRAKKARI:
        return SPELL_CONTROL_HORRIDON_DRAKKARI;

    case TRASH_PHASE_AMANI:
        return SPELL_CONTROL_HORRIDON_AMANI;

    default:
        return 0;
    }
}

static Position GetChargePositionByDoor(GameObject* pDoor)
{
    switch (pDoor->GetEntry())
    {
    case GOB_TRIBAL_DOOR_FARRAKI:
        return { 5502.53f, 5826.19f, 130.53f, 0.82f };

    case GOB_TRIBAL_DOOR_GURUBASHI:
        return { 5501.19f, 5865.15f, 130.53f, 5.39f };

    case GOB_TRIBAL_DOOR_DRAKKARI:
        return { 5361.72f, 5863.75f, 130.53f, 3.89f };

    case GOB_TRIBAL_DOOR_AMANI:
        return { 5363.09f, 5823.77f, 130.53f, 2.35f };

    default:
        return { 0.0f, 0.0f, 0.0f, 0.0f };
    }
}


// Helper AI
class npc_horridon_event_helper : public CreatureScript
{
public:
    npc_horridon_event_helper() : CreatureScript("npc_horridon_event_helper") { }

    class npc_horridon_event_helper_AI : public ScriptedAI
    {
    public:
        npc_horridon_event_helper_AI(Creature* pCreature) : ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript()), summons(me)
        {
            events.Reset();
            jumpers.clear();
            me->AddUnitState(UNIT_STATE_ROOT);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);

            uiTrashPhase = MAX_TRASH_PHASE;
            uiMinorTrashId = 0;
            memset(&uiMediumTrashId, 0, sizeof(uiMediumTrashId));
            uiMajorTrashId = 0;
            uiMajorCycle = MAJOR_CYCLE_FIRST;
            uiDrakkariCycle = DRAKKARI_CYCLE_FIRST;

            jumpPositions = NULL;
        }

        Creature* GetHorridon()
        {
            return me->FindNearestCreature(BOSS_HORRIDON, 500.0f, true);
        }

        bool IsWipe()
        {
            if (Creature* pHorridon = GetHorridon())
            {
                return ((pHorridon->IsInCombat() || pHorridon->GetVictim()) && pHorridon->getThreatManager().isThreatListEmpty());
            }

            return true;
        }

        void DoAction(int32 iAction) override
        {
            switch (iAction)
            {
            case ACTION_FIGHT_BEGIN:
                FightBegin();
                break;

            case ACTION_ENTER_NEXT_TRASH_PHASE:
                EnterNextPhase();
                break;

            case ACTION_FIGHT_RESET:
                summons.DespawnAll();
                FightReset();
                break;

            case ACTION_FIGHT_END:
                summons.DespawnAll();
                FightEnd();
                break;

            case ACTION_PREPARE_TRANSITION:
                PrepareTransition();
                break;

            case ACTION_RESET_AFTER_CRASH:
                ResetRequiredCreatures();
                break;

            default:
                break;
            }
        }

        void ForceHorridonToEvade();

        void ResetRequiredCreatures()
        {
            std::list<Creature*> resets;
            GetCreatureListWithEntryInGrid(resets, me, MOB_DRAKKARI_FROZEN_WARLORD, 1000.f);
            GetCreatureListWithEntryInGrid(resets, me, MOB_GURUBASHI_VENOM_PRIEST, 1000.f);
            GetCreatureListWithEntryInGrid(resets, me, MOB_FARRAKI_WASTEWALKER, 1000.f);
            GetCreatureListWithEntryInGrid(resets, me, MOB_AMANI_WARBEAR, 1000.f);
            GetCreatureListWithEntryInGrid(resets, me, MOB_ZANDALARI_DINOMANCER, 1000.f);

            for (Creature* pCreature : resets)
            {
                if (!pCreature->IsAlive())
                    pCreature->Respawn();
            }
        }

        uint8 MaxSummonsByPhase()
        {
            switch (uiTrashPhase)
            {
            case TRASH_PHASE_FARRAKI:
            case TRASH_PHASE_DRAKKARI:
                return 3;
            case TRASH_PHASE_GURUBASHI:
            case TRASH_PHASE_AMANI:
                return 2;
            }

            return 3;
        }

        bool CheckFlyingHacks()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (player->IsAlive())
                    {
                        if (player->IsFlying() && !player->IsGameMaster())
                        {
                            player->Kill(player, true);
                            player->GetSession()->KickPlayer();
                        }
                    }
                }
            return true;
        }

        void UpdateAI(uint32 uiDiff)
        {
            CheckFlyingHacks();

            if (uiTrashPhase == MAX_TRASH_PHASE)
                return;

            events.Update(uiDiff);

            // Handle gate timings a bit better at least
            if (uiNextGateTimer)
            {
                if (uiNextGateTimer <= uiDiff)
                    uiNextGateTimer = 0;
                else
                    uiNextGateTimer -= uiDiff;
            }

            while (uint32 uiEventId = events.ExecuteEvent())
            {
                switch (uiEventId)
                {
                case EVENT_SUMMON_MINOR:
                    if (summonPositions)
                    {
                        if (!bHasEmotedForGate)
                        {
                            if (Creature* pHorridon = GetHorridon())
                                pHorridon->AI()->Talk(uiTrashPhase);

                            bHasEmotedForGate = true;
                        }

                        std::list<uint32> entries;

                        if (uiMinorTrashId)
                            entries.push_back(uiMinorTrashId);
                        if (uiMediumTrashId[0])
                            entries.push_back(uiMediumTrashId[0]);
                        if (uiMediumTrashId[1])
                            entries.push_back(uiMediumTrashId[1]);

                        if (entries.empty()) // Entries is empty, no need to reschedule event
                            break;

                        uint8 maxSummonsPerPhase = MaxSummonsByPhase();

                        for (uint8 i = 0; i < maxSummonsPerPhase; ++i)
                        {
                            uint32 uiSummonEntry = Trinity::Containers::SelectRandomContainerElement(entries);
                            me->SummonCreature(uiSummonEntry, summonPositions[urand(0, 2)]);
                        }


                        events.ScheduleEvent(EVENT_SUMMON_MINOR, 19000);
                    }
                    break;

                case EVENT_SUMMON_MAJOR:
                    if (jumpPositions)
                    {
                        std::list<Creature*> majors;
                        GetCreatureListWithEntryInGrid(majors, me, uiMajorTrashId, 1000.0f);

                        majors.remove_if([this](Creature* const pCreature) -> bool
                            {
                                return !pCreature->IsAlive();
                            });

                        if (!majors.empty())
                        {
                            if (uiMajorCycle == MAJOR_CYCLE_FIRST)
                            {
                                if (Creature* pCreature = Trinity::Containers::SelectRandomContainerElement(majors))
                                {
                                    pCreature->GetMotionMaster()->MoveJump(jumpPositions[urand(0, MAX_JUMP_POSITIONS_BY_PHASE - 1)], 20.0f, 42.0f, MOTION_MAJOR_JUMP);
                                    jumpers.push_back(pCreature);
                                }
                            }
                            else
                            {
                                for (Creature* pCreature : majors)
                                {
                                    if (!pCreature->IsInCombat())
                                    {
                                        pCreature->GetMotionMaster()->MoveJump(jumpPositions[urand(0, MAX_JUMP_POSITIONS_BY_PHASE - 1)], 20.0f, 42.0f, MOTION_MAJOR_JUMP);
                                        jumpers.push_back(pCreature);
                                    }
                                }
                            }
                        }

                        ++uiMajorCycle;
                        events.ScheduleEvent(EVENT_SUMMON_MAJOR, 20 * IN_MILLISECONDS);
                    }
                    break;

                case EVENT_SUMMON_ZANDALARI_DINOMANCER:
                {
                    Position const summonPosition = zandalariDinomancersSummonPositions[urand(0, 9)];
                    if (Creature* pDinomancer = me->SummonCreature(MOB_ZANDALARI_DINOMANCER, summonPosition))
                        pDinomancer->GetMotionMaster()->MoveJump(zandalariDinomancersJumpPositions[uiTrashPhase][urand(0, MAX_SUMMON_POSITIONS_BY_PHASE - 1)], 20.0f, 42.0f, MOTION_DINOMANCER_JUMP);
                    //TODO: only one dinomancer per phase
                    //events.CancelEvent(EVENT_SUMMON_ZANDALARI_DINOMANCER);
                    break;
                }

                case EVENT_SUMMON_MINOR_DRAKKARI:
                {
                    switch (uiDrakkariCycle)
                    {
                    case DRAKKARI_CYCLE_FIRST:
                        uiDrakkariCycle = DRAKKARI_CYCLE_SECOND;
                        if (summonPositions)
                        {
                            me->SummonCreature(MOB_RISEN_DRAKKARI_CHAMPION, summonPositions[urand(0, MAX_SUMMON_POSITIONS_BY_PHASE - 1)]);
                            me->SummonCreature(MOB_RISEN_DRAKKARI_WARRIOR, summonPositions[urand(0, MAX_SUMMON_POSITIONS_BY_PHASE - 1)]);
                            events.ScheduleEvent(EVENT_SUMMON_MINOR_DRAKKARI, urand(6, 10) * IN_MILLISECONDS);
                        }
                        break;

                    case DRAKKARI_CYCLE_SECOND:
                        uiDrakkariCycle = DRAKKARI_CYCLE_FIRST;
                        if (summonPositions)
                        {
                            me->SummonCreature(MOB_RISEN_DRAKKARI_CHAMPION, summonPositions[urand(0, MAX_SUMMON_POSITIONS_BY_PHASE - 1)]);
                            events.ScheduleEvent(EVENT_SUMMON_MINOR_DRAKKARI, urand(8, 15) * IN_MILLISECONDS);
                        }
                        break;
                    }

                    break;
                }

                case EVENT_TRANSITION:
                    EnterNextPhase();
                    break;

                default:
                    break;
                }
            }
        }

        void JustSummoned(Creature* pSummoned)
        {
            summons.Summon(pSummoned);
        }

        void SummonedCreatureDespawn(Creature* pSummoned)
        {
            summons.Despawn(pSummoned);
        }

        uint32 GetTrashPhase() const
        {
            return uiTrashPhase;
        }

    private:
        SummonList summons;
        EventMap                events;
        InstanceScript* pInstance;
        Position         summonPositions[3];
        const Position* jumpPositions;
        std::list<Creature*>    jumpers;
        uint32                  uiTrashPhase;
        uint32                  uiMinorTrashId;
        uint32                  uiMediumTrashId[2];
        uint32                  uiMajorTrashId;
        uint32                  uiMajorCycle;
        uint32                  uiDrakkariCycle;
        uint32                  uiNextGateTimer;
        bool                    bHasEmotedForGate;

        void FightReset()
        {
            // Be sure that we have not already reset
            if (uiTrashPhase == MAX_TRASH_PHASE && summonPositions == NULL && jumpPositions == NULL)
                return;

            uiNextGateTimer = 0;

            std::list<GameObject*> pOrbs;

            GetGameObjectListWithEntryInGrid(pOrbs, me, GOB_ORB_OF_CONTROL_AMANI, 400.f);
            GetGameObjectListWithEntryInGrid(pOrbs, me, GOB_ORB_OF_CONTROL_FARRAKI, 400.f);
            GetGameObjectListWithEntryInGrid(pOrbs, me, GOB_ORB_OF_CONTROL_GURUBASHI, 400.f);
            GetGameObjectListWithEntryInGrid(pOrbs, me, GOB_ORB_OF_CONTROL_DRAKKARI, 400.f);

            for (GameObject* pOrb : pOrbs)
                pOrb->AddObjectToRemoveList();


            // Respawn dead jumpers
            for (Creature* pJumpersIter : jumpers)
            {
                if (pJumpersIter->isDead())
                {
                    pJumpersIter->Respawn();
                    if (pJumpersIter->AI())
                        pJumpersIter->AI()->EnterEvadeMode();
                }

                // Creature will automatically reset because it is registered in DB; no need to make them
                // return to home position or Reset() them.
            }

            // Boss reset by themselves, but won't revive if dead
            if (Creature* pHorridon = GetHorridon())
            {
                if (pHorridon->isDead())
                    pHorridon->Respawn();
            }

            if (Creature* pWarGodJalak = GetJalak())
            {
                if (pWarGodJalak->isDead())
                {
                    pWarGodJalak->Respawn();
                    //pWarGodJalak->AI()->EnterEvadeMode();
                }
            }

            events.Reset();
            summons.DespawnAll();
            jumpers.clear();

            uiTrashPhase = MAX_TRASH_PHASE;
            uiMinorTrashId = 0;
            memset(&uiMediumTrashId, 0, sizeof(uiMediumTrashId));
            uiMajorTrashId = 0;
            uiMajorCycle = MAJOR_CYCLE_FIRST;
            uiDrakkariCycle = DRAKKARI_CYCLE_FIRST;

            jumpPositions = NULL;
        }

        void FightBegin()
        {
            EnterNextPhase(true);
        }

        void FightEnd()
        {
            summons.DespawnAll();
            jumpers.clear();
            events.Reset();

            uiTrashPhase = MAX_TRASH_PHASE;
        }

        void DemoralizeLivingPoison()
        {
            std::list<Creature*> poisonList;
            GetCreatureListWithEntryInGrid(poisonList, me, MOB_LIVING_POISON, 400.f);

            for (auto const pCreature : poisonList)
            {
                if (pCreature->AI())
                    pCreature->AI()->DoAction(ACTION_LIVING_POISON_DESPAWN);
            }
        }

        Creature* GetJalak()
        {
            return me->FindNearestCreature(MOB_WAR_GOD_JALAK, 500.0f, true);
        }

        void EnterNextPhase(bool reset = false)
        {
            uiMajorCycle = MAJOR_CYCLE_FIRST;
            uiDrakkariCycle = DRAKKARI_CYCLE_FIRST;

            if (reset)
                uiTrashPhase = TRASH_PHASE_FARRAKI;
            else
                ++uiTrashPhase;

            bHasEmotedForGate = false;
            if (Creature* pJalak = GetJalak())
            {
                switch (uiTrashPhase)
                {
                case TRASH_PHASE_FARRAKI:
                    uiMinorTrashId = MOB_SUL_LITHUZ_STONEGAZER;
                    uiMediumTrashId[0] = MOB_FARRAKI_SKIRMISHER;
                    uiMediumTrashId[1] = 0;
                    uiMajorTrashId = MOB_FARRAKI_WASTEWALKER;
                    for (int i = 0; i < 3; ++i)
                        summonPositions[i] = farrakiTrashSummonPositions[i];
                    jumpPositions = farrakiWastewalkerJumpPositions;
                    if (Creature* pJalak = GetJalak())
                        pJalak->AI()->Talk(TALK_FARRAKI);
                    break;

                case TRASH_PHASE_GURUBASHI:
                    uiMinorTrashId = MOB_GURUBASHI_BLOODLORD;
                    uiMajorTrashId = MOB_GURUBASHI_VENOM_PRIEST;
                    memset(&uiMediumTrashId, 0, sizeof(uiMediumTrashId));
                    for (int i = 0; i < 3; ++i)
                        summonPositions[i] = gurubashiTrashSummonPositions[i];
                    jumpPositions = gurubashiVenomPriestJumpPositions;
                    pJalak->AI()->Talk(TALK_GURUBASHI);
                    break;

                case TRASH_PHASE_DRAKKARI:
                    uiMajorTrashId = MOB_DRAKKARI_FROZEN_WARLORD;
                    for (int i = 0; i < 3; ++i)
                        summonPositions[i] = drakkariTrashSummonPositions[i];
                    jumpPositions = drakkariFrozenWarlordJumpPositions;
                    pJalak->AI()->Talk(TALK_DRAKKARI);
                    DemoralizeLivingPoison();
                    break;

                case TRASH_PHASE_AMANI:
                    uiMinorTrashId = MOB_AMANI_SHI_PROTECTOR;
                    uiMediumTrashId[0] = MOB_AMANI_SHI_FLAME_CASTER;
                    uiMediumTrashId[1] = 0;
                    uiMajorTrashId = MOB_AMANI_WARBEAR;
                    for (int i = 0; i < 3; ++i)
                        summonPositions[i] = amaniTrashSummonPositions[i];
                    jumpPositions = amaniWarbearJumpPositions;
                    pJalak->AI()->Talk(TALK_AMANI);
                    break;

                case MAX_TRASH_PHASE:
                    if (Creature* pJalak = GetJalak())
                        pJalak->AI()->DoAction(ACTION_ENTER_PHASE_TWO);
                    return;

                default:
                    return;
                }

                events.Reset();


                if (uiTrashPhase != TRASH_PHASE_DRAKKARI)
                {
                    events.ScheduleEvent(EVENT_SUMMON_MINOR, 5 * IN_MILLISECONDS);
                }
                else
                {
                    events.ScheduleEvent(EVENT_SUMMON_MINOR_DRAKKARI, 5 * IN_MILLISECONDS);
                }

                events.ScheduleEvent(EVENT_SUMMON_MAJOR, 20 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SUMMON_ZANDALARI_DINOMANCER, 1 * MINUTE * IN_MILLISECONDS);

                uiNextGateTimer = 120000;
            }
        }

        void PrepareTransition()
        {
            events.Reset();
            events.ScheduleEvent(EVENT_TRANSITION, uiNextGateTimer + 7000);
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_horridon_event_helper_AI(pCreature);
    }
};
typedef npc_horridon_event_helper::npc_horridon_event_helper_AI HorridonHelperAI;

// RP Event Helper AI
class npc_horridon_rp_event_helper : public CreatureScript
{
public:
    npc_horridon_rp_event_helper() : CreatureScript("npc_horridon_rp_event_helper") { }

    class npc_horridon_rp_event_helper_AI : public ScriptedAI
    {
    public:
        npc_horridon_rp_event_helper_AI(Creature* pCreature) :
            ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript()), bIntroDone(false)
        {
            me->AddUnitState(UNIT_STATE_ROOT);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
        }

        void Reset()
        {
            bIntroDone = false;
            events.Reset();
            events.ScheduleEvent(EVENT_CHECK_PLAYERS, 500);
        }

        Creature* GetHorridonHelper()
        {
            return me->FindNearestCreature(NPC_HORRIDON_EVENT_HELPER, 500.0f, true);
        }

        Creature* GetJalak()
        {
            return me->FindNearestCreature(MOB_WAR_GOD_JALAK, 500.0f, true);
        }

        Creature* GetHorridon()
        {
            return me->FindNearestCreature(BOSS_HORRIDON, 500.0f, true);
        }

        void UpdateAI(uint32 uiDiff)
        {
            if (bIntroDone)
                return;

            events.Update(uiDiff);

            while (uint32 uiEventId = events.ExecuteEvent())
            {
                switch (uiEventId)
                {
                case EVENT_CHECK_PLAYERS:
                {
                    std::list<Player*> playerList;
                    GetPlayerListInGrid(playerList, me, 25.f);

                    if (playerList.empty())
                    {
                        events.ScheduleEvent(EVENT_CHECK_PLAYERS, 500);
                    }
                    else
                    {
                        if (Creature* pHelper = GetHorridonHelper())
                        {
                            if (pHelper->AI())
                                pHelper->AI()->DoAction(ACTION_RESET_AFTER_CRASH);
                        }
                        events.ScheduleEvent(EVENT_INTRO_PART_I, 1000);
                        events.ScheduleEvent(EVENT_INTRO_PART_II, 7500);
                        events.ScheduleEvent(EVENT_INTRO_PART_III, 27500);
                        events.ScheduleEvent(EVENT_INTRO_PART_IV, 30000);
                    }

                    break;
                }

                case EVENT_INTRO_PART_I:
                    if (Creature* pJalak = GetJalak())
                        pJalak->AI()->Talk(TALK_INTRO_FIRST);
                    break;

                case EVENT_INTRO_PART_II:
                    if (Creature* pJalak = GetJalak())
                        pJalak->AI()->Talk(TALK_INTRO_SECOND);
                    break;

                case EVENT_INTRO_PART_III:
                    if (Creature* pJalak = GetJalak())
                        pJalak->AI()->Talk(TALK_INTRO_THIRD);

                    // Horridon should break door?
                    if (GameObject* pDoor = me->FindNearestGameObject(GOB_HORRIDON_PRISON_DOOR, 50000.0f))
                        pDoor->SetGoState(GO_STATE_ACTIVE);
                    break;

                case EVENT_INTRO_PART_IV:
                    if (Creature* pHorridon = GetHorridon())
                        pHorridon->AI()->DoAction(ACTION_INTRO);
                    bIntroDone = true;
                    break;

                default:
                    break;
                }
            }
        }

    private:
        EventMap        events;
        InstanceScript* pInstance;
        bool            bIntroDone;
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_horridon_rp_event_helper_AI(pCreature);
    }
};


// Horridon AI
class boss_horridon : public CreatureScript
{
public:
    boss_horridon() : CreatureScript("boss_horridon") {}

    struct boss_horridon_AI : public BossAI
    {
        boss_horridon_AI(Creature* pCreature) : BossAI(pCreature, DATA_HORRIDON), pInstance(pCreature->GetInstanceScript()), bJalakCalled(false)
        {
            me->SetReactState(REACT_PASSIVE);
            pChargeDoor = NULL;
            events.Reset();
        }

        EventMap m_mBerserkEvents;
        float const_orientation;

        float GetPretdeterminedOrientation() const
        {
            return const_orientation;
        }


        Creature* GetHorridonHelper()
        {
            return me->FindNearestCreature(NPC_HORRIDON_EVENT_HELPER, 500.0f, true);
        }

        Creature* GetJalak()
        {
            return me->FindNearestCreature(MOB_WAR_GOD_JALAK, 500.0f, true);
        }


        void Reset()
        {
            const_orientation = 0.0f;
            m_mBerserkEvents.Reset();
            events.Reset();
            pChargeDoor = NULL;
            bJalakCalled = false;
            me->RemoveAurasDueToSpell(SPELL_HEADACHE);
            me->RemoveAurasDueToSpell(SPELL_CRACKED_SHELL);
            me->RemoveAurasDueToSpell(SPELL_RAMPAGE);
            me->SetHomePosition(middlePosition);

            if (Creature* pHorridonHelper = GetHorridonHelper())
            {
                if (CreatureAI* pHelperAI = pHorridonHelper->AI())
                    pHelperAI->DoAction(ACTION_FIGHT_RESET);
            }

            pInstance->SetBossState(DATA_HORRIDON, NOT_STARTED);
            pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            DespawnDirehorns();
            DespawnEffusions();
            DespawnBombs();
            DespawnLivingPoisons();
            RemovePhase();
        }

        void EnterEvadeMode(EvadeReason w)
        {
            //if (me->HasUnitState(UNIT_STATE_CANNOT_TURN))
              //  me->SetControlled(false, UNIT_STATE_CANNOT_TURN);
            float x, y, z, o;

            me->GetHomePosition(x, y, z, o);
            /*
            me->NearTeleportTo(x, y, z, o);
            me->SetFacingTo(o);
            */
            me->GetMotionMaster()->Clear(false);
            me->GetMotionMaster()->MovePoint(5000, x, y, z);

            BossAI::EnterEvadeMode();
            if (Creature* jalak = me->FindNearestCreature(MOB_WAR_GOD_JALAK, 500.0f, true))
                jalak->AI()->DoAction(ACTION_FORCE_RESET);
        }

        void DespawnDirehorns()
        {
            std::list<Creature*> cList;
            me->GetCreatureListWithEntryInGrid(cList, 70688, 500.0f);
            if (!cList.empty())
                for (std::list<Creature*>::const_iterator itr = cList.begin(); itr != cList.end(); ++itr)
                    (*itr)->DespawnOrUnsummon();
        }

        // just in case if the main AI doesn't have smth like this
        void DespawnLivingPoisons()
        {
            std::list<Creature*> cList;
            me->GetCreatureListWithEntryInGrid(cList, MOB_LIVING_POISON, 500.0f);
            if (!cList.empty())
                for (std::list<Creature*>::const_iterator itr = cList.begin(); itr != cList.end(); ++itr)
                    (*itr)->DespawnOrUnsummon();
        }

        void RemovePhase()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    player->RemoveAura(SPELL_DIRE_FIXATION);
                }
        }

        void DespawnEffusions()
        {
            std::list<Creature*> cList;
            me->GetCreatureListWithEntryInGrid(cList, MOB_VENOMOUS_EFFUSION, 500.0f);
            if (!cList.empty())
                for (std::list<Creature*>::const_iterator itr = cList.begin(); itr != cList.end(); ++itr)
                    (*itr)->DespawnOrUnsummon();
        }


        void DespawnWarGodJalak()
        {
            std::list<Creature*> WarGod;
            me->GetCreatureListWithEntryInGrid(WarGod, MOB_WAR_GOD_JALAK, 800.0f);
            if (!WarGod.empty())
                for (std::list<Creature*>::const_iterator itr = WarGod.begin(); itr != WarGod.end(); ++itr)
                    (*itr)->DespawnOrUnsummon();
        }

        void DespawnBombs()
        {
            std::list<Creature*> bombs;
            me->GetCreatureListWithEntryInGrid(bombs, MOB_FROZEN_ORB, 800.0f);
            if (!bombs.empty())
                for (std::list<Creature*>::const_iterator itr = bombs.begin(); itr != bombs.end(); ++itr)
                    (*itr)->DespawnOrUnsummon();
        }

        // To avoid the endless combat and mob spawning
        void KillTriggersandHelpers()
        {
            if (Creature* trigger = me->FindNearestCreature(NPC_HORRIDON_EVENT_HELPER, 500.0f, true))
                trigger->Kill(trigger);
            if (Creature* trigger2 = me->FindNearestCreature(662202, 500.0f, true))
                trigger2->Kill(trigger2);
        }

        void EnterCombat(Unit* pVictim)
        {
            events.ScheduleEvent(EVENT_TRIPLE_PUNCTURE, 10 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_DOUBLE_SWIPE, 15 * IN_MILLISECONDS);
            //events.ScheduleEvent(EVENT_EVADE_CHECK, 2000);
            m_mBerserkEvents.ScheduleEvent(EVENT_BERSERK, 12 * MINUTE * IN_MILLISECONDS);

            if (IsHeroic())
                events.ScheduleEvent(EVENT_DIRE_CALL, 60 * IN_MILLISECONDS);
            pInstance->SetBossState(DATA_HORRIDON, IN_PROGRESS);
            pInstance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

            if (Creature* pHorridonHelper = GetHorridonHelper())
            {
                if (CreatureAI* pHelperAI = pHorridonHelper->AI())
                    pHelperAI->DoAction(ACTION_FIGHT_BEGIN);
            }

            DoZoneInCombat(me, 200.f);

        }

        void EnterEvadeModeIfRequired()
        {
            Position pos = me->GetHomePosition();
            if (me->GetExactDist2d(&pos) > 190.f)
            {
                EnterEvadeMode(EVADE_REASON_BOUNDARY);
                return;
            }

            events.ScheduleEvent(EVENT_EVADE_CHECK, 2000);
        }

        void DoAction(int32 iAction) override
        {
            switch (iAction)
            {
            case ACTION_INTRO:
                me->GetMotionMaster()->MoveCharge(middlePosition.GetPositionX(), middlePosition.GetPositionY(), middlePosition.GetPositionZ(), 42.0f, MOTION_HORRIDON_CHARGE);
                me->SetHomePosition(middlePosition);
                break;
            case ACTION_DOUBLE_SWIPE:
                events.ScheduleEvent(EVENT_DOUBLE_SWIPE_ACTION, 1500, 0, 0);
                break;
            default:
                break;
            }
        }

        void DamageTaken(Unit* who, uint32& damage)
        {
            if (me->HealthBelowPct(30) && !bJalakCalled)
            {
                bJalakCalled = true;
                events.ScheduleEvent(EVENT_CALL_JALAK, 1 * MINUTE * IN_MILLISECONDS);
            }
        }

        void UpdateAI(uint32 uiDiff)
        {
            if (!UpdateVictim())
            {
                me->ClearUnitState(UNIT_STATE_CANNOT_TURN);
                return;
            }
            events.Update(uiDiff);
            m_mBerserkEvents.Update(uiDiff);

            switch (m_mBerserkEvents.ExecuteEvent())
            {
            case EVENT_BERSERK:
                DoCast(me, SPELL_BERSERK, true);
                break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (me->HasUnitState(UNIT_STATE_CANNOT_TURN) && !me->HasAura(SPELL_HEADACHE))
                me->ClearUnitState(UNIT_STATE_CANNOT_TURN);

            while (uint32 uiEventId = events.ExecuteEvent())
            {
                switch (uiEventId)
                {
                case EVENT_CALL_JALAK:
                    if (Creature* pJalak = GetJalak())
                    {
                        if (CreatureAI* pJalakAI = pJalak->AI())
                            pJalakAI->DoAction(ACTION_ENTER_PHASE_TWO);
                    }
                    break;
                case EVENT_TRIPLE_PUNCTURE:
                    if (Unit* pVictim = me->GetVictim())
                        DoCast(pVictim, SPELL_TRIPLE_PUNCTURE);
                    events.ScheduleEvent(EVENT_TRIPLE_PUNCTURE, urand(10, 15) * IN_MILLISECONDS);
                    break;

                case EVENT_DOUBLE_SWIPE:
                {
                    if (Unit* target = me->GetVictim())
                    {
                        me->SetReactState(REACT_PASSIVE);
                        me->AttackStop();
                        me->StopMoving();
                        if (Creature* trigger = me->SummonCreature(60942, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 5000))
                        {
                            me->SetFacingToObject(trigger);
                            me->AddThreat(trigger, 9.9999999f);
                            me->CastSpell(trigger, SPELL_DOUBLE_SWIPE);
                        }
                        events.ScheduleEvent(EVENT_RETURN_TO_COMBAT, 4000);
                        events.ScheduleEvent(EVENT_HORRIDON_CHARGE, 15000);
                        break;
                    }
                }
                case EVENT_DOUBLE_SWIPE_ACTION:
                {
                    if (Unit* target = me->GetVictim())
                    {
                        me->SetReactState(REACT_PASSIVE);
                        me->AttackStop();
                        me->StopMoving();
                        if (Creature* trigger = me->SummonCreature(60942, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 5000))
                        {
                            me->SetFacingToObject(trigger);
                            me->AddThreat(trigger, 9.9999999f);
                            me->CastSpell(trigger, SPELL_DOUBLE_SWIPE);
                        }
                        events.ScheduleEvent(EVENT_RETURN_TO_COMBAT, 4000);
                        break;
                    }
                }
                case EVENT_RETURN_TO_COMBAT:
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                case EVENT_HORRIDON_CHARGE:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 200.0f, true))
                    {
                        DoCast(pTarget, SPELL_CHARGE);
                        Talk(EMOTE_CHARGE, pTarget);
                    }
                    events.ScheduleEvent(EVENT_DOUBLE_SWIPE, 15000);
                    break;
                case EVENT_DIRE_CALL:
                    DoCastAOE(SPELL_DIRE_CALL);
                    events.ScheduleEvent(EVENT_DIRE_CALL, 60 * IN_MILLISECONDS);
                    break;
                default:
                    break;
                }
            }


            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* pKiller)
        {
            pInstance->SetBossState(DATA_HORRIDON, DONE);
            if (Creature* pController = GetHorridonHelper())
                pController->AI()->DoAction(ACTION_FIGHT_END);

            pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            DespawnDirehorns();
            DespawnEffusions();
            DespawnLivingPoisons();
            DespawnWarGodJalak();
            DespawnBombs();
            RemovePhase();
            KillTriggersandHelpers();
        }

        void MovementInform(uint32 uiMotionType, uint32 uiMovementId)
        {
            switch (uiMovementId)
            {
            case MOTION_HORRIDON_DOOR_CHARGE:
                if (me->GetVictim())
                    me->GetMotionMaster()->MoveChase(me->GetVictim());
                DoCast(me, SPELL_HEADACHE, true);
                pChargeDoor->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                break;
            case MOTION_HORRIDON_CHARGE:
                me->SetReactState(REACT_AGGRESSIVE);
                break;
            case EVENT_CHARGE:
                events.RescheduleEvent(EVENT_DOUBLE_SWIPE, 12000 + rand() % 8000);
                DoCast(SPELL_DOUBLE_SWIPE);
                const_orientation = me->GetOrientation();
                me->SetFacingTo(const_orientation);
                break;

            default:
                break;
            }

        }

        void ChargeAtDoor(GameObject* pDoor)
        {
            if (!pDoor)
                return;

            pChargeDoor = pDoor;
            float fX, fY;
            events.DelayEvents(3000);
            GetPositionWithDistInOrientation(me, me->GetDistance(pDoor) - 5.f, me->GetAngle(pDoor), fX, fY);
            me->GetMotionMaster()->MovementExpired();
            me->GetMotionMaster()->MoveCharge(fX, fY, 130.8f, 42.0f, MOTION_HORRIDON_DOOR_CHARGE);
        }

    private:
        EventMap        events;
        GameObject* pChargeDoor;
        InstanceScript* pInstance;
        bool            bJalakCalled;
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_horridon_AI(pCreature);
    }
};

typedef boss_horridon::boss_horridon_AI HorridonAI;

void npc_horridon_event_helper::npc_horridon_event_helper_AI::ForceHorridonToEvade()
{
    if (Creature* pHorridon = GetHorridon())
    {
        pHorridon->ClearUnitState(UNIT_STATE_CANNOT_TURN);
        pHorridon->ClearUnitState(UNIT_STATE_STUNNED);

        if (HorridonAI* pAI = dynamic_cast<HorridonAI*>(pHorridon->AI()))
            pAI->EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
    }
}
// Jalak AI
class mob_war_god_jalak : public CreatureScript
{
public:
    mob_war_god_jalak() : CreatureScript("mob_war_god_jalak") { }

    class mob_war_god_jalak_AI : public ScriptedAI
    {
    public:
        mob_war_god_jalak_AI(Creature* pCreature) : ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript()), uiPhase(BOSS_PHASE_SUMMONS)
        {
        }

        Creature* GetHorridonHelper()
        {
            return me->FindNearestCreature(NPC_HORRIDON_EVENT_HELPER, 500.0f, true);
        }

        Creature* GetJalak()
        {
            return me->FindNearestCreature(MOB_WAR_GOD_JALAK, 500.0f, true);
        }

        Creature* GetHorridon()
        {
            return me->FindNearestCreature(BOSS_HORRIDON, 500.0f, true);
        }


        void Reset()
        {
            events.Reset();
            uiPhase = BOSS_PHASE_SUMMONS;
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            if (Creature* pHorridonHelper = GetHorridonHelper())
            {
                if (CreatureAI* pHelperAI = pHorridonHelper->AI())
                    pHelperAI->DoAction(ACTION_FIGHT_RESET);
            }
        }

        void DoAction(int32 iAction) override
        {
            switch (iAction)
            {
            case ACTION_ENTER_PHASE_TWO:
                if (uiPhase != BOSS_PHASE_JALAK)
                {
                    Talk(TALK_ENTER_PHASE_2);
                    uiPhase = BOSS_PHASE_JALAK;
                    me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                    if (Creature* pHorridon = GetHorridon())
                    {
                        Position toRelocate = *pHorridon;
                        Position relocater = { frand(0.0f, 5.0f), frand(0.0f, 5.0f), 0.0f, 0.0f };
                        toRelocate.RelocateOffset(relocater);
                        me->GetMotionMaster()->MoveJump(toRelocate, 32.0f, 32.0f);
                    }
                }
                break;
            case ACTION_FORCE_RESET:
                me->GetMotionMaster()->MovePoint(0, 5433.27f, 5674.01f, 192.23f, false);
                break;
            }
        }

        void MovementInform(uint32 uiMotionType, uint32 uiMovementId)
        {
            if (uiMotionType == EFFECT_MOTION_TYPE)
            {
                switch (uiMovementId)
                {
                case EVENT_JUMP:
                {
                    me->SetInCombatWithZone();
                    std::list<Player*> playerList;

                    GetPlayerListInGrid(playerList, me, 500.0f);
                    playerList.sort([this](Player const* first, Player const* second) -> bool
                        {
                            return first->GetExactDist2d(this->me) < second->GetExactDist2d(this->me);
                        });

                    if (!playerList.empty() && playerList.front())
                    {
                        Player* pFirst = playerList.front();
                        me->AddThreat(pFirst, 100000.0f);
                        ScriptedAI::AttackStart(pFirst);
                    }

                    break;
                }

                default:
                    break;
                }
            }
        }

        void EnterCombat(Unit* pVictim)
        {
            events.ScheduleEvent(EVENT_BESTIAL_CRY, 10 * IN_MILLISECONDS);
        }

        void UpdateAI(uint32 uiDiff)
        {
            if (uiPhase == BOSS_PHASE_SUMMONS)
                return;

            if (!UpdateVictim())
                return;

            events.Update(uiDiff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 uiEventId = events.ExecuteEvent())
            {
                switch (uiEventId)
                {
                case EVENT_BESTIAL_CRY:
                    DoCastAOE(SPELL_BESTIAL_CRY);
                    events.ScheduleEvent(EVENT_BESTIAL_CRY, 15 * IN_MILLISECONDS);
                    break;

                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }

        void KilledUnit(Unit* pKilled)
        {
            Talk(TALK_ON_JALAK_KILLED_UNIT);
        }

        void JustDied(Unit* pKiller)
        {
            if (GetHorridon() && GetHorridon()->isDead())
            {
                pInstance->SetBossState(DATA_HORRIDON, DONE);
                if (Creature* pController = GetHorridonHelper())
                    pController->AI()->DoAction(ACTION_FIGHT_END);
            }
            else
            {
                if (Creature* pHorridon = GetHorridon())
                    pHorridon->AddAura(SPELL_RAMPAGE, pHorridon);
            }

            Talk(TALK_ON_HORRIDON_KILLED_UNIT);
        }

    private:
        EventMap        events;
        InstanceScript* pInstance;
        uint32          uiPhase;
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_war_god_jalak_AI(pCreature);
    }
};


// Trashs AI (does not include summons of spells)
class mob_horridon_trashs : public CreatureScript
{
public:
    mob_horridon_trashs() : CreatureScript("mob_horridon_trashs") { }

    class mob_horridon_trashs_AI : public ScriptedAI
    {
    public:
        mob_horridon_trashs_AI(Creature* pCreature) :
            ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript()),
            pRendingChargeTarget(NULL), uiChainLightningCount(0)
        {
            events.Reset();
        }

        void Reset() override
        {
            events.Reset();
            pRendingChargeTarget = NULL;
        }
        Creature* GetHorridonHelper()
        {
            return me->FindNearestCreature(NPC_HORRIDON_EVENT_HELPER, 500.0f, true);
        }

        Creature* GetJalak()
        {
            return me->FindNearestCreature(MOB_WAR_GOD_JALAK, 500.0f, true);
        }

        Creature* GetHorridon()
        {
            return me->FindNearestCreature(BOSS_HORRIDON, 500.0f, true);
        }

        void JustSummoned(Creature* pSummoned) override
        {
            if (Creature* Helper = GetHorridonHelper())
            {
                if (Helper->AI())
                    Helper->AI()->JustSummoned(pSummoned);
            }
        }

        void EnterEvadeMode(EvadeReason w) override
        {
            float x, y, z, o;

            me->GetHomePosition(x, y, z, o);
            me->NearTeleportTo(x, y, z, o);
            me->SetFacingTo(o);

            ScriptedAI::EnterEvadeMode();
        }

        void IsSummonedBy(Unit* pSummoner) override
        {
            DoZoneInCombat(me, 1000.f);

            // Schedule events
            switch (me->GetEntry())
            {
            case MOB_SUL_LITHUZ_STONEGAZER:
                events.ScheduleEvent(EVENT_STONE_GAZE, 5 * IN_MILLISECONDS);
                break;

            case MOB_GURUBASHI_BLOODLORD:
                events.ScheduleEvent(EVENT_RENDING_CHARGE, 5 * IN_MILLISECONDS);
                break;

            case MOB_RISEN_DRAKKARI_CHAMPION:
            case MOB_RISEN_DRAKKARI_WARRIOR:
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_THREAT, true);
                DoCast(me, SPELL_UNCONTROLLED_ABOMINATION);
                events.ScheduleEvent(EVENT_SWITCH_TARGET, 10 * IN_MILLISECONDS);
                break;

            case MOB_AMANI_SHI_FLAME_CASTER:
                events.ScheduleEvent(EVENT_FIREBALL, 5 * IN_MILLISECONDS);
                break;

            case MOB_AMANI_SHI_BEAST_SHAMAN:
                events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 5 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_HEX_OF_CONFUSION, 10 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SUMMON_LIGHTNING_NOVA_TOTEM, 15 * IN_MILLISECONDS);
                break;

            default:
                break;
            }
        }

        void MovementInform(uint32 uiMotionType, uint32 uiMovementId) override
        {
            if (uiMovementId == MOTION_MAJOR_JUMP)
            {
                me->SetInCombatWithZone(); // Call it now to not bug the npcs around
                switch (me->GetEntry())
                {
                case MOB_FARRAKI_WASTEWALKER:
                    events.ScheduleEvent(EVENT_BLAZING_LIGHT, 10 * IN_MILLISECONDS);
                    events.ScheduleEvent(EVENT_SUMMON_SAND_TRAP, 5000 + rand() % 5000);
                    break;

                case MOB_GURUBASHI_VENOM_PRIEST:
                    events.ScheduleEvent(EVENT_GURUBASHI_VENOM_BOLT_VOLLEY, 10 * IN_MILLISECONDS);
                    events.ScheduleEvent(EVENT_SUMMON_VENOMOUS_EFFUSION, 15 * IN_MILLISECONDS);
                    break;

                case MOB_DRAKKARI_FROZEN_WARLORD:
                    events.ScheduleEvent(EVENT_MORTAL_STRIKE, 10 * IN_MILLISECONDS);
                    events.ScheduleEvent(EVENT_SUMMON_FROZEN_ORB, 15 * IN_MILLISECONDS);
                    break;

                case MOB_AMANI_WARBEAR:
                    events.ScheduleEvent(EVENT_SWIPE, 10 * IN_MILLISECONDS);
                    break;

                default:
                    break;
                }

                // Select target and move towards it
                if (Creature* pHorridon = GetHorridon())
                {
                    if (CreatureAI* pHorridonAI = pHorridon->AI())
                    {
                        if (Unit* pTarget = pHorridonAI->SelectTarget(SELECT_TARGET_RANDOM))
                        {
                            me->SetInCombatWith(pTarget);
                            ScriptedAI::AttackStart(pTarget);
                        }
                    }
                }
            }

            //if (uiMovementId == EVENT_CHARGE)
            //    DoCast(pRendingChargeTarget, SPELL_RENDING_CHARGE_DAMAGES);;
        }

        bool HasAuraOfType(Unit* pUnit)
        {
            return (pUnit->HasAuraType(SPELL_AURA_MOD_PACIFY_SILENCE) || pUnit->HasAura(SPELL_STONE_GAZE));
        }

        /* @ RAGELESS nu avem deloc asa ceva CastInterrupted
        void CastInterrupted(SpellInfo const* spell) override
        {
            switch (spell->Id)
            {
            case SPELL_SUMMON_SAND_TRAP:
                events.ScheduleEvent(EVENT_SUMMON_SAND_TRAP, 500);
                break;
            case SPELL_VENOM_BOLT_VOLLEY:
                events.ScheduleEvent(EVENT_GURUBASHI_VENOM_BOLT_VOLLEY, 2000);
                break;
            case SPELL_BLAZING_SUNLIGHT:
                events.ScheduleEvent(EVENT_BLAZING_LIGHT, 500);
                break;
            case SPELL_SUMMON_FROZEN_ORB:
                events.ScheduleEvent(EVENT_SUMMON_FROZEN_ORB, 500);
                break;
            case SPELL_FIREBALL:
                events.ScheduleEvent(EVENT_FIREBALL, 2400);
                break;
            case SPELL_HEX_OF_CONFUSION:
                events.ScheduleEvent(EVENT_HEX_OF_CONFUSION, 4000);
                break;
            }
        }
        */

        void UpdateAI(uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            events.Update(uiDiff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 uiEventId = events.ExecuteEvent())
            {
                switch (uiEventId)
                {
                    // Farraki
                case EVENT_STONE_GAZE:
                    if (Unit* pVictim = me->GetVictim())
                    {
                        if (!HasAuraOfType(pVictim))
                        {
                            DoCast(pVictim, SPELL_STONE_GAZE);
                            events.ScheduleEvent(EVENT_STONE_GAZE, 15 * IN_MILLISECONDS);

                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                ScriptedAI::AttackStart(pTarget);

                            return;
                        }
                        events.ScheduleEvent(EVENT_STONE_GAZE, 15000);
                    }
                    break;

                case EVENT_BLAZING_LIGHT:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        DoCast(pTarget, SPELL_BLAZING_SUNLIGHT);
                    events.ScheduleEvent(EVENT_BLAZING_LIGHT, 10 * IN_MILLISECONDS);
                    break;

                case EVENT_SUMMON_SAND_TRAP:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(pTarget, SPELL_SUMMON_SAND_TRAP);
                    events.ScheduleEvent(EVENT_SUMMON_SAND_TRAP, 15000 + rand() % 10000);
                    break;

                    // Gurubashi
                case EVENT_RENDING_CHARGE:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1))
                    {
                        pRendingChargeTarget = pTarget;
                        DoCast(pTarget, SPELL_RENDING_CHARGE);
                        DoCast(pTarget, SPELL_RENDING_CHARGE_DAMAGES);
                    }
                    events.ScheduleEvent(EVENT_RENDING_CHARGE, 10 * IN_MILLISECONDS);
                    break;

                case EVENT_GURUBASHI_VENOM_BOLT_VOLLEY:
                    DoCastAOE(SPELL_VENOM_BOLT_VOLLEY);
                    events.ScheduleEvent(EVENT_GURUBASHI_VENOM_BOLT_VOLLEY, 10 * IN_MILLISECONDS);
                    break;

                case EVENT_SUMMON_VENOMOUS_EFFUSION:
                    DoCast(me, SPELL_SUMMON_VENOMOUS_EFFUSION);
                    events.ScheduleEvent(EVENT_SUMMON_VENOMOUS_EFFUSION, 30 * IN_MILLISECONDS);
                    break;

                    // Drakkari
                case EVENT_SWITCH_TARGET:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1))
                    {
                        DoResetThreat();
                        me->AddThreat(pTarget, 100000.0f);
                        ScriptedAI::AttackStart(pTarget);
                    }
                    events.ScheduleEvent(EVENT_SWITCH_TARGET, 7 * IN_MILLISECONDS);
                    break;

                case EVENT_MORTAL_STRIKE:
                    if (Unit* pVictim = me->GetVictim())
                        DoCast(pVictim, SPELL_MORTAL_STRIKE);
                    events.ScheduleEvent(EVENT_MORTAL_STRIKE, 10 * IN_MILLISECONDS);
                    break;

                case EVENT_SUMMON_FROZEN_ORB:
                    DoCast(me, SPELL_SUMMON_FROZEN_ORB);
                    events.ScheduleEvent(EVENT_SUMMON_FROZEN_ORB, 30 * IN_MILLISECONDS);
                    break;

                    // Amani
                case EVENT_FIREBALL:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(pTarget, SPELL_FIREBALL);
                    events.ScheduleEvent(EVENT_FIREBALL, 10 * IN_MILLISECONDS);
                    break;

                case EVENT_SWIPE:
                    DoCastAOE(SPELL_SWIPE);
                    events.ScheduleEvent(EVENT_SWIPE, 10 * IN_MILLISECONDS);
                    break;

                case EVENT_CHAIN_LIGHTNING:
                    if (Unit* pPrimaryTarget = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(pPrimaryTarget, SPELL_CHAIN_LIGHTNING);
                    events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 10 * IN_MILLISECONDS);
                    break;

                case EVENT_HEX_OF_CONFUSION:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        DoCast(pTarget, SPELL_HEX_OF_CONFUSION);
                    events.ScheduleEvent(EVENT_HEX_OF_CONFUSION, 10 * IN_MILLISECONDS);
                    break;

                case EVENT_SUMMON_LIGHTNING_NOVA_TOTEM:
                    DoCast(me, SPELL_SUMMON_LIGHTNING_NOVA_TOTEM);
                    events.ScheduleEvent(EVENT_SUMMON_LIGHTNING_NOVA_TOTEM, 30 * IN_MILLISECONDS);
                    break;

                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* pKiller) override
        {
            if (me->GetEntry() == MOB_AMANI_WARBEAR)
            {
                me->SummonCreature(MOB_AMANI_SHI_BEAST_SHAMAN, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
            }
        }

        uint32 GetData(uint32 uiIndex) const
        {
            if (uiIndex == DATA_AMANI_BEAST_SHAMAN_LIGHTNING_COUNT)
                return uiChainLightningCount;

            return 0;
        }

        void SetData(uint32 uiIndex, uint32 uiValue) override
        {
            if (uiIndex == DATA_AMANI_BEAST_SHAMAN_LIGHTNING_COUNT)
            {
                if (++uiChainLightningCount == 3)
                    uiChainLightningCount = 0;
            }
        }

    private:
        EventMap        events;
        InstanceScript* pInstance;
        Unit* pRendingChargeTarget;
        uint32          uiChainLightningCount;
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_horridon_trashs_AI(pCreature);
    }
};


// Summons AI
class mob_horridon_summons : public CreatureScript
{
public:
    mob_horridon_summons() : CreatureScript("mob_horridon_summons") { }

    class mob_horridon_summons_AI : public ScriptedAI
    {
    public:
        mob_horridon_summons_AI(Creature* pCreature) :
            ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript()) /*, fSandTrapRadius(0.0f) */
        {
            // me->SetReactState(REACT_PASSIVE);
            events.Reset();
        }

        void IsSummonedBy(Unit* pSummoner)
        {
            me->SetInCombatWithZone();
            switch (me->GetEntry())
            {
            case MOB_SAND_TRAP:
                DoCast(me, SPELL_SAND_TRAP_PERIODIC);
                break;

            case MOB_FROZEN_ORB:
                me->SetDisplayId(11686);
                me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_THREAT, true);
                me->SetReactState(REACT_PASSIVE);
                me->ClearUnitState(UNIT_STATE_ROOT);
                me->GetMotionMaster()->MoveRandom(15.f);
                DoCast(me, SPELL_FROZEN_BOLT_PERIODIC);
                break;

            case MOB_LIGHTNING_NOVA_TOTEM:
                DoCast(me, SPELL_LIGHTNING_NOVA_PERIODIC);
                break;

            default:
                break;
            }
        }

        void UpdateAI(uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            events.Update(uiDiff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 uiEventId = events.ExecuteEvent())
            {
                switch (uiEventId)
                {
                case EVENT_EFFUSION_VENOM_BOLT_VOLLEY:
                    DoCastAOE(SPELL_VENOM_BOLT_VOLLEY);
                    events.ScheduleEvent(EVENT_EFFUSION_VENOM_BOLT_VOLLEY, 5 * IN_MILLISECONDS);
                    break;

                default:
                    break;
                }
            }
        }

    private:
        EventMap        events;
        InstanceScript* pInstance;
        // float           fSandTrapRadius;
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_horridon_summons_AI(pCreature);
    }
};
typedef mob_horridon_summons::mob_horridon_summons_AI HorridonSummonsAI;


// Zandalari Dinomancer AI
class mob_zandalari_dinomancer : public CreatureScript
{
public:
    mob_zandalari_dinomancer() : CreatureScript("mob_zandalari_dinomancer") { }

    class mob_zandalari_dinomancer_AI : public ScriptedAI
    {
    public:
        mob_zandalari_dinomancer_AI(Creature* pCreature) :
            ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript()),
            bIsUnderFiftyPercent(false)
        {
            events.Reset();
        }
        Creature* GetHorridonHelper()
        {
            return me->FindNearestCreature(NPC_HORRIDON_EVENT_HELPER, 500.0f, true);
        }

        Creature* GetJalak()
        {
            return me->FindNearestCreature(MOB_WAR_GOD_JALAK, 500.0f, true);
        }

        Creature* GetHorridon()
        {
            return me->FindNearestCreature(BOSS_HORRIDON, 500.0f, true);
        }

        void MovementInform(uint32 uiMotionType, uint32 uiMovementId)
        {
            if (uiMovementId == MOTION_DINOMANCER_JUMP)
            {
                me->SetInCombatWithZone();
                if (Creature* pHorridon = GetHorridon())
                {
                    // me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                    DoCast(pHorridon, SPELL_DINO_MENDING);
                    events.ScheduleEvent(EVENT_DINO_MENDING, 30 * IN_MILLISECONDS);
                }
            }
        }

        void CheckPrimaryTarget()
        {
            Unit* myTarget = me->GetVictim();
            // if no target and this function is called it will crash the server, we don't want taht
            if (!myTarget)
                return;
            // work only in combat
            if (me->IsInCombat())
                if (myTarget->IsPet() || myTarget->IsGuardian())
                    me->Kill(myTarget);
        }

        void UpdateAI(uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            CheckPrimaryTarget();

            events.Update(uiDiff);

            if (HealthBelowPct(50) && !bIsUnderFiftyPercent)
            {
                bIsUnderFiftyPercent = true;

                me->InterruptNonMeleeSpells(true);
                me->InterruptSpell(CURRENT_CHANNELED_SPELL);

                if (Creature* pHelper = GetHorridonHelper())
                {
                    if (HorridonHelperAI* pHelperAI = dynamic_cast<HorridonHelperAI*>(pHelper->AI()))
                    {
                        uint32 uiSummonSpellId = GetSummoningOrbSpellByPhase(pHelperAI->GetTrashPhase());
                        DoCast(me, uiSummonSpellId);
                        Talk(0);
                    }
                }

                events.CancelEvent(EVENT_DINO_MENDING);
                DoCast(me, SPELL_DINO_FORM);
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 uiEventId = events.ExecuteEvent())
            {
                switch (uiEventId)
                {
                case EVENT_DINO_MENDING:
                    if (Creature* pHorridon = GetHorridon())
                        DoCast(pHorridon, SPELL_DINO_MENDING);
                    events.ScheduleEvent(EVENT_DINO_MENDING, 30 * IN_MILLISECONDS);
                    break;

                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        EventMap        events;
        InstanceScript* pInstance;
        bool            bIsUnderFiftyPercent;
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_zandalari_dinomancer_AI(pCreature);
    }
};

// Direhorn Spirit AI
class mob_direhorn_spirit : public CreatureScript
{
public:
    mob_direhorn_spirit() : CreatureScript("mob_direhorn_spirit") { }

    class mob_direhorn_spirit_AI : public ScriptedAI
    {
    public:
        mob_direhorn_spirit_AI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->SetSpeed(MOVE_WALK, 0.6f);
            me->SetSpeed(MOVE_RUN, 0.6f);
            me->AddAura(SPELL_WEAK_LINK, me);
        }

        EventMap events;
        // REWORK
        void IsSummonedBy(Unit* pSummoner)
        {
            events.ScheduleEvent(EVENT_TARGET_A_RANDOM_PLAYER, 500, 0, 0);
            me->SetInCombatWithZone();
            /*if (Player *pAsPlayer = pSummoner->ToPlayer())
            {
            me->SetPhaseMask(2, true);
            pAsPlayer->SetPhaseMask(3, true);
            pTarget = pAsPlayer;

            DoCast(pTarget, SPELL_DIRE_FIXATION);
            DoCast(me, SPELL_WEAK_LINK);
            */
        }

        //failsale?
        void DamageTaken(Unit* who, uint32& damage)
        {
            me->CastSpell(me, 140949, true); //knockback spell
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_TARGET_A_RANDOM_PLAYER:
                {
                    /*if (Creature* horridon = me->FindNearestCreature(BOSS_HORRIDON, 500.0f, true))
                    {
                    if (Unit* possibleTarget = horridon->GetVictim())
                    continue;*/
                    std::list<Unit*> targets;
                    SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
                    if (!targets.empty())
                        if (targets.size() >= 1)
                            targets.resize(1);

                    for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    {
                        me->AddAura(SPELL_DIRE_FIXATION, (*itr));
                        me->AI()->AttackStart((*itr));
                        me->AddThreat((*itr), 999999999.9f);
                        events.ScheduleEvent(EVENT_DAMAGE_IF_NEARBY, 2000, 0, 0);
                        break;
                    }
                    //}
                }
                case EVENT_DAMAGE_IF_NEARBY:
                {
                    Unit* playerNearby = me->GetVictim();

                    if (!playerNearby)
                    {
                        me->Kill(me);
                        break;
                    }

                    if (me->GetDistance(playerNearby) < 2.0f)
                    {
                        me->Kill(playerNearby, false);
                        playerNearby->RemoveAura(SPELL_DIRE_FIXATION);
                        me->DespawnOrUnsummon(100);
                    }

                    events.ScheduleEvent(EVENT_DAMAGE_IF_NEARBY, 500, 0, 0);
                    break;
                }
                }
            }
        }

        void JustDied(Unit* pKiller)
        {
            if (Unit* player = me->GetVictim())
            {
                if (!player)
                    return;

                player->RemoveAura(SPELL_DIRE_FIXATION);
            }
        }

    private:
        Player* pTarget;
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_direhorn_spirit_AI(pCreature);
    }
};

class npc_living_poison : public CreatureScript
{
    enum eEvents : uint32
    {
        EVENT_NONE,
        EVENT_MOVE
    };

public:
    npc_living_poison() : CreatureScript("npc_living_poison") {}

    struct npc_living_poisonAI : public ScriptedAI
    {
        npc_living_poisonAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
        }

        EventMap events;

        void IsSummonedBy(Unit* pSummoner) override
        {
            me->SetSpeed(MOVE_RUN, 2.0f);
            me->SetSpeed(MOVE_WALK, 2.0f);
            me->SetReactState(REACT_PASSIVE);
            me->SetFaction(7);
            me->AddAura(SPELL_LIVING_POISON_PERIODIC, me);
            //events.ScheduleEvent(EVENT_MOVE, 200 + rand() % 500);
        }

        // this AI should only move RANDOM so .. we make this simple
        void Reset()
        {
            me->GetMotionMaster()->MoveRandom(20.0f);
        }

        // is this a joke or what? this doesn't even working correctly 8-| 
        /*void DoAction(int32 iAction) override
        {
            if (iAction == ACTION_LIVING_POISON_DESPAWN)
            {
                events.CancelEvent(EVENT_MOVE);
                me->GetMotionMaster()->MovementExpired();
                me->GetMotionMaster()->MoveRandom(30.f);
            }
        }

        void Move()
        {
            if (Creature* pHorridon = GetHorridon(me))
            {
                if (Unit* pTarget = pHorridon->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 50.f, true))
                {
                    me->GetMotionMaster()->MovementExpired();
                    me->GetMotionMaster()->MovePoint(2, *pTarget);

                    events.ScheduleEvent(EVENT_MOVE, 5000 + rand() % 2000);
                    return;
                }
            }
            else
                me->GetMotionMaster()->MoveRandom(20.f);
        }

        void MovementInform(uint32 uiType, uint32 uiPointId) override
        {
            if (uiType != POINT_MOTION_TYPE)
                return;

            if (uiPointId == 2)
                events.RescheduleEvent(EVENT_MOVE, 200);
        }

        void UpdateAI(uint32 uiDiff)
        {
            events.Update(uiDiff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_MOVE:
                    Move();
                    break;
                }
            }
        }*/

    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_living_poisonAI(pCreature);
    }
};

class npc_venomous_effusion : public CreatureScript
{
    enum eEvents : uint32
    {
        EVENT_NONE,
        EVENT_VOLLEY,
    };

public:
    npc_venomous_effusion() : CreatureScript("npc_venomous_effusion") {}

    struct ai_impl : public ScriptedAI
    {
        ai_impl(Creature* pCreature) : ScriptedAI(pCreature) {}

        EventMap events;
        Creature* GetHorridonHelper()
        {
            return me->FindNearestCreature(NPC_HORRIDON_EVENT_HELPER, 500.0f, true);
        }

        Creature* GetJalak()
        {
            return me->FindNearestCreature(MOB_WAR_GOD_JALAK, 500.0f, true);
        }

        Creature* GetHorridon()
        {
            return me->FindNearestCreature(BOSS_HORRIDON, 500.0f, true);
        }

        void IsSummonedBy(Unit* pSummoner) override
        {
            events.ScheduleEvent(EVENT_VOLLEY, 3000 + rand() % 2000);

            if (Creature* pHorridonHelper = GetHorridonHelper())
            {
                if (pHorridonHelper->AI())
                    pHorridonHelper->AI()->JustSummoned(me);
            }

            DoZoneInCombat(me, 100.f);
        }

        void UpdateAI(uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            events.Update(uiDiff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_VOLLEY:
                    DoCast(SPELL_VENOM_BOLT_VOLLEY);
                    events.ScheduleEvent(EVENT_VOLLEY, 4000 + rand() % 2000);
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new ai_impl(pCreature);
    }
};

class npc_amani_shi_warbear : public CreatureScript
{
public:
    npc_amani_shi_warbear() : CreatureScript("npc_amani_shi_warbear") {}

    struct ai_impl : public ScriptedAI
    {
        ai_impl(Creature* pCreature) : ScriptedAI(pCreature)
        {
            m_shamanGuid = 0;
        }

        EventMap events;
        uint64 m_shamanGuid;

        Creature* GetShaman() const
        {
            return me->FindNearestCreature(MOB_AMANI_SHI_BEAST_SHAMAN, 500.0f, true);
        }

        void EnterEvadeMode(EvadeReason w) override
        {
            float x, y, z, o;

            me->GetHomePosition(x, y, z, o);
            me->NearTeleportTo(x, y, z, o);
            me->SetFacingTo(o);

            ScriptedAI::EnterEvadeMode();
        }

        void Reset() override
        {
            events.Reset();
            /*if (Creature* pShaman = GetShaman())
            {
                pShaman->DespawnOrUnsummon();
                m_shamanGuid = 0;
            }

            if (Creature* pNewShaman = me->SummonCreature(MOB_AMANI_SHI_BEAST_SHAMAN, *me))
            {
                pNewShaman->EnterVehicle(me, 0);
                pNewShaman->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                m_shamanGuid = pNewShaman->GetGUID();
            }*/
        }

        void JustDied(Unit* pKiller) override
        {
            me->SummonCreature(MOB_AMANI_SHI_BEAST_SHAMAN, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
        }

        void MovementInform(uint32 uiMotionType, uint32 uiMovementId) override
        {
            if (uiMovementId == MOTION_MAJOR_JUMP)
            {
                DoZoneInCombat(me, 200.f);
                events.ScheduleEvent(EVENT_SWIPE, 6000 + rand() % 4000);

                /*if (Creature *pHorridon = GetHorridon(me))
                {
                    if (CreatureAI *pHorridonAI = pHorridon->AI())
                    {
                        if (Unit *pTarget = pHorridonAI->SelectTarget(SELECT_TARGET_RANDOM))
                        {
                            AttackStart(pTarget);
                            if (GetShaman() && GetShaman()->AI())
                                GetShaman()->AI()->AttackStart(pTarget);
                        }
                    }
                }*/
            }
        }

        void UpdateAI(uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            events.Update(uiDiff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
            case EVENT_SWIPE:
                DoCastAOE(SPELL_SWIPE);
                events.ScheduleEvent(EVENT_SWIPE, 10 * IN_MILLISECONDS);
                break;
            }

            DoMeleeAttackIfReady();
        }

    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new ai_impl(pCreature);
    }
};



//////////////////////////////////////////////////////////////////////////
// Spell Helpers
// Helper for Double Swipe
class DoubleSwipeTargetSelector
{
public:
    DoubleSwipeTargetSelector(Unit* caster, bool front) :
        pCaster(caster), bFront(front) { }

    bool operator()(WorldObject const* object) const
    {
        if (object->GetTypeId() != TYPEID_PLAYER)
            return false;

        if (bFront)
        {
            return pCaster->HasInArc(35.0f, object);
        }
        else
        {
            bool bToReturn = false;

            pCaster->SetOrientation(-pCaster->GetOrientation());
            if (pCaster->HasInArc(35.0f, object))
                bToReturn = true;
            pCaster->SetOrientation(-pCaster->GetOrientation());

            return bToReturn;
        }
    }

private:
    Unit* pCaster;
    bool bFront;
};

class isValidDoubleStrikeTargetPredicate
{
private:
    Unit* caster;
    uint32 spellId;
    float orientation;
public:
    isValidDoubleStrikeTargetPredicate(Unit* _caster, uint32 _spellId, float _orientation) : caster(_caster), spellId(_spellId), orientation(_orientation) {}

    bool operator()(WorldObject* target) const
    {
        float arc = caster->NormalizeOrientation(spellId == SPELL_DOUBLE_SWIPE_FRONT ? (3.14f / 4.9f) : ((2.0f * 3.14f) - (3.14f / 4.9f)));

        float angle = caster->GetAngle(target);
        angle -= orientation;

        // move angle to range -pi ... +pi
        angle = caster->NormalizeOrientation(angle);
        if (angle > 3.14f)
            angle -= 2.0f * 3.14f;

        float lborder = -1.0f * (arc / 2.0f);                        // in range -pi..0
        float rborder = (arc / 2.0f);                             // in range 0..pi

        if (spellId == SPELL_DOUBLE_SWIPE_FRONT)
            return !((angle >= lborder) && (angle <= rborder));
        else
            return ((angle >= lborder) && (angle <= rborder));
    }
};

// Target selection for Double Swipe
class spell_horridon_double_swipe : public SpellScriptLoader
{
public:
    spell_horridon_double_swipe() : SpellScriptLoader("spell_horridon_double_swipe") { }

    class spell_horridon_double_swipe_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_horridon_double_swipe_SpellScript)

            void FilterTargets(std::list<WorldObject*>& targets)
        {
            if (Creature* pHorridon = GetCaster()->ToCreature())
            {
                if (HorridonAI* pAI = dynamic_cast<HorridonAI*>(pHorridon->AI()))
                {
                    float ori = pAI->GetPretdeterminedOrientation();
                    targets.remove_if(isValidDoubleStrikeTargetPredicate(pHorridon, GetSpellInfo()->Id, ori));
                }
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_horridon_double_swipe_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_horridon_double_swipe_SpellScript();
    }
};


// Chain Lightning
class spell_horridon_chain_lightning : public SpellScriptLoader
{
public:
    spell_horridon_chain_lightning() : SpellScriptLoader("spell_horridon_chain_lightning") { }

    class spell_horridon_chain_lightning_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_horridon_chain_lightning_SpellScript)

            void HandleEffectHitTarget(SpellEffIndex effectIndex)
        {
            if (Unit* pHitUnit = GetHitUnit())
            {
                Unit* pCaster = GetOriginalCaster();
                if (!pCaster)
                    pCaster = GetCaster();

                if (!pCaster)
                    return;

                if (UnitAI* pCasterAI = pCaster->GetAI())
                {
                    uint32 uiCount = pCasterAI->GetData(DATA_AMANI_BEAST_SHAMAN_LIGHTNING_COUNT);

                    if (uiCount == 0 && pCaster == GetOriginalCaster())
                        return;

                    Unit* pNewTarget = NULL;
                    uint32 uiLoopCount = 0; // Prevent infinite loop in case boss is being soloed

                    do
                    {
                        pNewTarget = pCasterAI->SelectTarget(SELECT_TARGET_RANDOM);
                        ++uiLoopCount;
                    } while (pNewTarget == pHitUnit && uiLoopCount <= 10);

                    if (!pNewTarget || pNewTarget == pHitUnit)
                        return;

                    pHitUnit->CastSpell(pNewTarget, SPELL_CHAIN_LIGHTNING, false, NULL, NULL, pCaster->GetGUID());

                    pCasterAI->SetData(DATA_AMANI_BEAST_SHAMAN_LIGHTNING_COUNT, 0);
                }
            }
        }

        void Register()
        {
            //OnEffectHitTarget += SpellEffectFn(spell_horridon_chain_lightning_SpellScript::HandleEffectHitTarget, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_horridon_chain_lightning_SpellScript();
    }
};


// Living Sand (radius calc)
class spell_horridon_sand_trap : public SpellScriptLoader
{
public:
    spell_horridon_sand_trap() : SpellScriptLoader("spell_horridon_sand_trap") {  }

    class spell_horridon_sand_trap_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_horridon_sand_trap_SpellScript)

            void HandleSelectTargets(std::list<WorldObject*>& targets)
        {
            if (!GetCaster())
                return;

            Creature* pCaster = GetCaster()->ToCreature();
            float fRadius = 1.0f; // Basis

            // Recalc radius according to stack amount
            if (Aura* pGrow = pCaster->GetAura(GetSpellInfo()->Id))
            {
                uint8 uiCount = pGrow->GetStackAmount();
                for (uint8 i = 0; i < uiCount; ++i)
                    fRadius *= 1.0f;
            }

            // Remove target that are not in the radius
            targets.remove_if([pCaster, fRadius](WorldObject const* pTarget) -> bool
                {
                    return pCaster->GetExactDist2d(pTarget) >= fRadius;
                });
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_horridon_sand_trap_SpellScript::HandleSelectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_horridon_sand_trap_SpellScript();
    }
};

class spell_headache : public SpellScriptLoader
{
public:
    spell_headache() : SpellScriptLoader("spell_headache") {}

    class aura_impl : public AuraScript
    {
        PrepareAuraScript(aura_impl);

        void HandleAuraRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            if (Creature* Horridon = GetOwner()->ToCreature())
            {
                if (Horridon->GetVictim())
                    Horridon->GetMotionMaster()->MoveChase(Horridon->GetVictim());
            }
        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(aura_impl::HandleAuraRemove, EFFECT_0, SPELL_EFFECT_APPLY_AURA, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new aura_impl();
    }
};

class spell_double_swipe_aura : public SpellScriptLoader
{
public:
    spell_double_swipe_aura() : SpellScriptLoader("spell_double_swipe_aura") {}

    class aura_impl : public AuraScript
    {
        PrepareAuraScript(aura_impl);

        void HandleOnApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            if (Creature* owner = GetOwner()->ToCreature())
            {
                //if (HorridonAI* pAI = dynamic_cast<HorridonAI*>(owner->AI()))
               // {
               //     owner->SetOrientation(pAI->GetPretdeterminedOrientation());
              //  }
                /*
                std::list<Player*> potentials;
                GetPlayerListInGrid(potentials, owner, 30.f);

                if (!potentials.empty())
                {
                    if (Player* pTarget = Trinity::Containers::SelectRandomContainerElement(potentials))
                        owner->SetOrientation(owner->GetAngle(pTarget));
                }*/

                owner->SetControlled(true, UNIT_STATE_CANNOT_TURN);
            }
        }

        void HandleOnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            if (Unit* owner = GetOwner()->ToUnit())
                owner->SetControlled(false, UNIT_STATE_CANNOT_TURN);
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(aura_impl::HandleOnApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(aura_impl::HandleOnApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new aura_impl();
    }
};

// Charge - 136769
class bfa_spell_horridon_charge : public SpellScriptLoader
{
public:
    bfa_spell_horridon_charge() : SpellScriptLoader("bfa_spell_horridon_charge") {}

    class bfa_spell_horridon_charge_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_horridon_charge_SpellScript);

        void HandleAfterCast()
        {
            Unit* caster = GetCaster();

            if (!caster)
                return;

            caster->AddAura(136769, caster);
        }

        void Register()
        {
            AfterCast += SpellCastFn(bfa_spell_horridon_charge_SpellScript::HandleAfterCast);
        }
    };

    class bfa_spell_horridon_charge_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_horridon_charge_AuraScript);

        void HandleRemove(AuraEffect const* pAuraEffect, AuraEffectHandleModes eMode)
        {
            Unit* caster = GetCaster();

            if (!caster)
                return;
            if (caster->ToCreature() && caster->ToCreature()->AI())
                caster->ToCreature()->AI()->DoAction(ACTION_DOUBLE_SWIPE);
            //caster->CastSpell(caster, SPELL_DOUBLE_SWIPE);
        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_horridon_charge_AuraScript::HandleRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_horridon_charge_AuraScript();
    }

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_horridon_charge_SpellScript();
    }       
};

void AddSC_boss_horridon()
{
    // boss / helpers  
    new npc_horridon_event_helper();
    new npc_horridon_rp_event_helper();
    new boss_horridon();
    new mob_war_god_jalak();

    // trash/mobs
    new mob_horridon_trashs();
    new mob_horridon_summons();
    new mob_zandalari_dinomancer();
    new mob_direhorn_spirit();
    new npc_living_poison();
    new npc_venomous_effusion();
    new npc_amani_shi_warbear();

    // Spells
    new spell_horridon_double_swipe();
    new spell_horridon_chain_lightning();
    new spell_horridon_sand_trap();
    new spell_headache();
    new spell_double_swipe_aura();
    new bfa_spell_horridon_charge();
}
