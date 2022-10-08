#include "siege_of_orgrimmar.hpp"
#include "GameObjectAI.h"
#include "SceneHelper.h"

#define THOK_POWER_TYPE POWER_MANA
#define THOK_POWER_MAX 100

#define ENERGY_UPDATE_TIMER 500 // in milliseconds
#define DEFAULT_ENERGY_REGEN_DURATION 12000 // in milliseconds
#define MINIMUM_ENERGY_REGEN_DURATION 1000

// The boss regenerates 100 energy in 12 seconds at the beginning
// Each acceleration increase regeneration rate to -2 seconds

enum ScriptedTexts
{
    SAY_AKOLIK_1    = 0,
    SAY_AKOLIK_2    = 1,
    SAY_AKOLIK_3    = 2,

    SAY_GORAI_1     = 0,

    SAY_MONTAK_1    = 0,
};

enum Spells
{
    // Intro
    SPELL_LIGHTNING_CHAIN           = 147987,
    SPELL_KILL_JAILERS              = 147994,

    SPELL_ZERO_MANA_REGEN           = 96301,

    SPELL_BERSERK                   = 26662,

    SPELL_POWER_REGEN_AURA          = 143345,
    SPELL_POWER_REGEN               = 143409, // triggered by 143345
    SPELL_CLUMP_CHECK               = 143430, // triggered by 143345 and by 143991, used to check for bloodied targets count

    SPELL_FEARSOME_ROAR             = 143426,
    SPELL_PANIC                     = 143766,

    SPELL_TAIL_LASH                 = 143428,

    SPELL_DEAFENING_SCREECH         = 143343,
    SPELL_ACCELERATION              = 143411,

    SPELL_SHOCK_BLAST_PERIODIC      = 143991, // ?
    SPELL_SHOCK_BLAST_FORCE         = 143706, // casted on shock collar
    SPELL_SHOCK_BLAST_DMG           = 143707, // casted by shock collar

    SPELL_BLOODIED_WOUNDS           = 143451,
    SPELL_BLOODIED                  = 143452,

    SPELL_BLOOD_FRENZY_KNOCKBACK    = 144067,
    SPELL_BLOOD_FRENZY              = 143440,
    SPELL_BLOOD_FRENZY_SPEED        = 143442,

    SPELL_FIXATE_AOE                = 143445,
    SPELL_ATTACK_ME                 = 146539,
    SPELL_FIXATE_IMMUNITY           = 146540,
    SPELL_FIXATE_DUMMY              = 146581,

    SPELL_CHOMP_CHECKER             = 126100,
    SPELL_CHOMP                     = 143465,
    SPELL_CHOMP_2                   = 147996, // casted by npc when thok eats him
    SPELL_MEAT_EXPLOSION            = 130620, // casted by npc when he dies

    SPELL_MENDING                   = 149569, // in heroic, boss casts the spell after eating npc

    SPELL_SKELETON_KEY              = 146589,
    SPELL_UNLOCKING                 = 143917,

    // Acid
    SPELL_ACID_BREATH               = 143780,
    SPELL_CORROSIVE_BLOOD_FORCE     = 143795, // casted on shock collar
    SPELL_CORROSIVE_BLOOD_DMG       = 143791,

    // Ice
    SPELL_FREEZING_BREATH           = 143773,
    SPELL_ICY_BLOOD_FORCE           = 143801, // casted on shock collar
    SPELL_ICY_BLOOD_DMG             = 143800,
    SPELL_FROZEN_SOLID_STUN_1       = 143775,
    SPELL_FROZEN_SOLID_SUMMON       = 143776,
    SPELL_FROZEN_SOLID_STUN_2       = 143777,

    // Fire
    SPELL_SCORCHING_BREATH          = 143767,
    SPELL_BURNING_BLOOD_FORCE       = 143781, // casted on shock collar
    SPELL_BURNING_BLOOD_AOE         = 143782,
    SPELL_BURNING_BLOOD_DMG         = 143783,
    SPELL_BURNING_BLOOD_PERIODIC    = 143784,

    // Kor'kron Jailer
    SPELL_ENRAGE                    = 145974,

    // AKolik
    SPELL_AKOLIKS_INCANTATION       = 144016,

    // Waterspeaker Gorai
    SPELL_WATER_OF_PURITY           = 144013,
    SPELL_RESTORATIVE_WATERS        = 144117,
    SPELL_RESTORATIVE_WATERS_HEAL   = 144118,

    // Montak
    SPELL_FIRE_OF_THE_SPIRITS       = 144014,
    SPELL_FLAME_COATING             = 144115,
    SPELL_FLAME_COATING_DMG         = 144116,

    // Captive Cave Bat
    SPELL_VAMPIRIC_FRENZY_AURA      = 147980,
    SPELL_VAMPIRIC_FRENZY_DMG_1     = 147978, // triggered every second by 147980
    SPELL_VAMPIRIC_FRENZY_DMG_2     = 147981, // second dmg spell, same as 147978 but not triggered

    // Starved Yeti
    SPELL_WRECKING_BALL_VISUAL      = 147946, // red beam at the dest
    SPELL_WRECKING_BALL_DUMMY       = 147952,
    SPELL_WRECKING_BALL_AURA        = 148144, // while moving
    SPELL_WRECKING_BALL_DMG_1       = 148143, // while moving
    SPELL_WRECKING_BALL_DMG_2       = 148145, // at the end
};

enum Adds
{
    NPC_SHOCK_COLLAR        = 71645,
    NPC_FOOTS_COLLAR        = 73200,
    NPC_KORKRON_JAILER      = 71658,
    NPC_ICE_TOMB            = 71720,
    NPC_AKOLIK              = 71742,
    NPC_SKUMBLADE_CAPTIVE   = 71744,
    NPC_WATERSPEAKER_GORAI  = 71749,
    NPC_INKGILL_CAPTIVE     = 71753,
    NPC_MONTAK              = 71763,
    NPC_GAI_CHO_REFUGEE     = 71764,

    NPC_STARVED_YETI        = 73526, // in heroic, 1273.469, -5200.588, -232.0436, 2.026163
    NPC_CAPTIVE_CAVE_BAT    = 73522, // in heroic
};

enum Events
{
    EVENT_FEARSOME_ROAR     = 1,
    EVENT_DEAFENING_SCREECH,
    EVENT_TAIL_LASH,
    EVENT_SHOCK_BLAST,
    EVENT_BLOODIED_CHECK,
    EVENT_BLOOD_FRENZY_INIT,
    EVENT_BLOOD_FRENZY_FIXATE,
    EVENT_BLOOD_FRENZY_MOVE,
    EVENT_BERSERK,

    // Starved Yeti
    EVENT_WRECKING_BALL,
};

enum Actions
{
    ACTION_FULL_POWER   = 1,
    ACTION_RESET_POWER,
    ACTION_BLOOD_FRENZY,
    ACTION_ATTACK_PRISONER,
    ACTION_CONTINUE_ATTACKING,
    ACTION_CONTINUE_ATTACKING_ACID,
    ACTION_CONTINUE_ATTACKING_FROST,
    ACTION_CONTINUE_ATTACKING_FIRE,

    ACTION_SAUROK_OPEN,
    ACTION_YAUNGOL_OPEN,
    ACTION_JINYU_OPEN,

    ACTION_PRISONER_RELEASED,

    ACTION_RELEASE_BEAST,
    ACTION_WRECKING_BALL,
};

enum Timers
{
    TIMER_BERSERK               = 10 * MINUTE * IN_MILLISECONDS,

    TIMER_FEARSOME_ROAR_FIRST   = 11 * IN_MILLISECONDS,
    TIMER_FEARSOME_ROAR         = 11 * IN_MILLISECONDS,
    TIMER_TAIL_LASH_FIRST       = 8 * IN_MILLISECONDS,
    TIMER_TAIL_LASH             = 15 * IN_MILLISECONDS,
    TIMER_SHOCK_BLAST           = 5 * IN_MILLISECONDS,
    TIMER_BLOODIED              = 2 * IN_MILLISECONDS,
    TIMER_FIXATE_FIRST          = 5 * IN_MILLISECONDS,
    TIMER_FIXATE                = 14 * IN_MILLISECONDS,

    // Starved Yeti
    TIMER_WRECKING_BALL_FIRST   = 4 * IN_MILLISECONDS,
    TIMER_WRECKING_BALL         = 19 * IN_MILLISECONDS, // 15 secs stun after dmg + 4 secs
};

enum eData
{
    DATA_THOK_IS_INTRO              = 1,
    DATA_DEAFENING_SCREECH_COUNT,
    DATA_FIXATE_GUID,
    DATA_PRISONER_GUID,
    DATA_NPC_NUMBER,

    POINT_WRECKING_BALL,
};

enum Phases : int
{
    PHASE_NONE      = 0,
    PHASE_NORMAL    = 1,
    PHASE_ACID      = 2,
    PHASE_FROST     = 3,
    PHASE_FIRE      = 4,
    PHASE_FRENZY    = 5,
};

enum VehicleSeats
{
    SEAT_SHOCK_COLLAR   = 0,
    SEAT_RIGHT_FOOT     = 4,
    SEAT_LEFT_FOOT      = 5,
    SEAT_FACE           = 6,
};

enum Points
{
    POINT_THOK_POS  = 1,
    POINT_PRISONER,

    POINT_OUT_OF_PRISON,


};

enum Items
{
    ITEM_SKELETON_KEY   = 100948,
};

#define BLOODIED_PLAYERS_COUNT_10 5
#define BLOODIED_PLAYERS_COUNT_25 15

#define CAPTIVE_CAVE_BATS_COUNT 7
const Position captiveCaveBatPos[CAPTIVE_CAVE_BATS_COUNT] =
{
    { 1278.523f, -5191.788f, -280.8389f, 2.180029f },
    { 1260.793f, -5212.596f, -276.4608f, 1.922045f },
    { 1263.5f, -5214.085f, -259.1307f, 1.941185f },
    { 1255.297f, -5211.448f, -259.1628f, 1.874746f },
    { 1280.135f, -5199.753f, -280.7762f, 2.147932f },
    { 1279.668f, -5200.719f, -272.6732f, 2.138875f },
    { 1280.45f, -5200.299f, -251.0793f, 2.147595f }
};

#define WRECING_BALL_POS_COUNT 8
const Position wreckingBallPos[WRECING_BALL_POS_COUNT] =
{
    { 1165.089722f, -5056.974121f, -290.45f, 3.885522f },
    { 1136.564819f, -5100.233398f, -290.45f, 4.554421f },
    { 1148.650146f, -5152.220703f, -290.45f, 5.299671f },
    { 1192.260132f, -5181.404297f, -290.45f, 6.273988f },
    { 1245.067261f, -5168.517090f, -290.45f, 0.699406f },
    { 1273.747681f, -5122.564941f, -290.44f, 1.313326f },
    { 1266.348022f, -5071.812500f, -290.50f, 2.079967f },
    { 1219.368896f, -5044.836914f, -290.44f, 3.005437f }
};

const Position thokPos = { 1183.07f, -5125.92f, -289.94f, 0.58f };
const Position starvedYetiPos = { 1273.469f, -5200.588f, -232.0436f, 2.026163f };
const Position jailerPos = { 1295.988f, -5050.776f, -290.38f, 3.70f };

enum Prisoners : int
{
    PRISONER_AKOLIK = 0,
    PRISONER_GORAI  = 1,
    PRISONER_MONTAK = 2,
};

#define PRISONERS_COUNT 3
const Position prisonersPos[PRISONERS_COUNT][2] =
{
    {
        { 1311.245f, -5145.018f, -288.02f, 3.118788f }, // Akolik start position
        { 1275.661f, -5124.638f, -290.44f, 2.799044f }  // Akolik position after
    },
    {
        { 1228.625f, -4995.946f, -288.35f, 4.3426f },   // Gorai start position
        { 1218.651f, -5040.521f, -290.34f, 4.5910f }    // Gorai position after
    },
    {
        { 1089.359f, -5087.655f, -288.42f, 6.054901f }, // Montak start position
        { 1133.783f, -5096.753f, -290.40f, 6.069799f }  // Montak position after
    }
};

#define SKUMBLADE_CAPTIVE_COUNT 4
const Position skumbladePos[SKUMBLADE_CAPTIVE_COUNT][2] =
{
    {
        { 1314.161f, -5118.792f, -288.5541f, 2.954293f },
        { 1276.336f, -5137.182f, -290.1734f, 2.820425f }
    },
    {
        { 1319.276f, -5131.729f, -288.3864f, 2.235062f },
        { 1278.192f, -5131.603f, -290.1211f, 2.820425f }
    },
    {
        { 1322.847f, -5118.474f, -288.832f, 1.456779f },
        {1273.7095f, -5130.111f, -290.449f, 2.805153f},
    },
    {
        { 1318.3f, -5147.077f, -288.0766f, 3.108934f },
        { 1279.9f, -5121.639f, -290.1472f, 2.799044f }
    }
};

#define INKGILL_CAPTIVE_COUNT 5
const Position inkgillPos[INKGILL_CAPTIVE_COUNT][2] =
{
    {
        { 1231.823f, -5000.554f, -288.4443f, 1.753894f },
        { 1228.401f, -5038.873f, -290.0691f, 4.600235f }
    },
    {
        { 1225.957f, -5001.205f, -288.2832f, 1.100402f },
        { 1223.537f, -5038.280f, -290.0912f, 4.591072f }
    },
    {
        { 1220.72f, -4993.896f, -288.1514f, 0.136699f },
        { 1220.93f, -5037.962f, -290.1045f, 4.591072f }
    },
    {
        { 1236.137f, -4996.323f, -288.5711f, 2.5672f },
        { 1217.957f, -5036.330f, -290.0172f, 4.5910f }
    },
    {
        { 1222.25f, -4997.592f, -288.1912f, 0.5543658f },
        { 1214.96f, -5037.903f, -290.1876f, 4.591072f  }
    }
};

#define GAI_CHO_CAPTIVE_COUNT 3
const Position gaichoPos[GAI_CHO_CAPTIVE_COUNT][2] =
{
    {
        { 1091.905f, -5081.665f, -288.6278f, 5.608939f },
        { 1130.083f, -5096.790f, -290.1282f, 6.103397f }
    },
    {
        { 1094.582f, -5088.113f, -287.8883f, 5.498443f },
        { 1129.364f, -5100.679f, -290.1301f, 6.100343f }
    },
    {
        { 1088.113f, -5092.963f, -288.2752f, 5.436639f },
        { 1130.882f, -5092.471f, -290.1244f, 6.100343f }
    }
};

struct BloodiedSelector : public std::unary_function<Unit*, bool>
{
    public:

        BloodiedSelector() { }

        bool operator()(Unit const* target) const
        {
            if (!target)
                return false;

            if (target->GetTypeId() != TYPEID_PLAYER)
                return false;

            if (target->GetHealthPct() >= 50.f)
                return false;

            if (target->HasAura(SPELL_BLOODIED))
                return false;

            return true;
        }
};

class ThokEnergyRegenerator
{
    public:

        ThokEnergyRegenerator(Creature* owner) : m_Owner(owner) { }

        void Activate() { m_IsActive = true; }
        bool IsActive() const { return m_IsActive; }
        void Stop()  { m_IsActive = false; }

        void Initialize()
        {
            Stop();

            ResetEnergy();
        }

        void ResetEnergy()
        {
            m_Owner->SetPower(THOK_POWER_TYPE, 0);
            m_UpdateTimer = ENERGY_UPDATE_TIMER;
            m_OwnerEnergy = 0.f;
            m_FullPowerReached = false;

            CalcDuration();

            UpdateOwnerEnergyVisual();
        }

        void Update(const uint32 diff)
        {
            if (!m_IsActive)
                return;

            if (m_UpdateTimer <= diff)
            {
                m_UpdateTimer = ENERGY_UPDATE_TIMER;

                UpdateEnergy();
            }
            else
            {
                m_UpdateTimer -= diff;
            }
        }

    private:

        void CalcDuration()
        {
            uint32 screechCount = m_Owner->AI()->GetData(DATA_DEAFENING_SCREECH_COUNT);
            uint32 decreaseDuration = screechCount * 2000;

            if (decreaseDuration >= (DEFAULT_ENERGY_REGEN_DURATION))
            {
                m_PhaseDuration = MINIMUM_ENERGY_REGEN_DURATION;
            }
            else
            {
                m_PhaseDuration = DEFAULT_ENERGY_REGEN_DURATION - decreaseDuration;
            }
        }

        void UpdateEnergy()
        {
            // Full power should be triggered in next update after the energy is full
            if (!m_FullPowerReached && (int)m_OwnerEnergy >= THOK_POWER_MAX)
            {
                m_FullPowerReached = true;
                m_Owner->AI()->DoAction(ACTION_FULL_POWER);
                return;
            }

            int32 currentEnergy = (int32)m_OwnerEnergy;
            if (currentEnergy >= THOK_POWER_MAX)
                return;

            if (m_FullPowerReached)
                m_FullPowerReached = false;

            float updatePart = m_PhaseDuration / (float)ENERGY_UPDATE_TIMER;
            float energyToAdd = (float)THOK_POWER_MAX / updatePart;
            m_OwnerEnergy += energyToAdd;

            UpdateOwnerEnergyVisual();
        }

        void UpdateOwnerEnergyVisual()
        {
            m_Owner->SetPower(THOK_POWER_TYPE, (int)m_OwnerEnergy);
        }

    private:

        Creature* m_Owner;
        uint32 m_UpdateTimer;
        bool m_IsActive;
        float m_OwnerEnergy;
        float m_PhaseDuration;
        bool m_FullPowerReached;
};

class PrisonsController
{
    public:

        PrisonsController(Creature* owner) : m_Owner(owner) { }

        void ResetPrisons()
        {
            OpenClosePrison(DATA_SAUROK_PRISON_1, false);
            OpenClosePrison(DATA_SAUROK_PRISON_2, false);
            OpenClosePrison(DATA_YAUNGOL_PRISON_1, false);
            OpenClosePrison(DATA_YAUNGOL_PRISON_2, false);
            OpenClosePrison(DATA_JINYU_PRISON_1, false);
            OpenClosePrison(DATA_JINYU_PRISON_2, false);
        }

        void OpenPrison(Prisoners prisoner)
        {
            if (prisoner == PRISONER_AKOLIK)
            {
                OpenClosePrison(DATA_SAUROK_PRISON_1, true);
                OpenClosePrison(DATA_SAUROK_PRISON_2, true);
            }
            else if (prisoner == PRISONER_GORAI)
            {
                OpenClosePrison(DATA_JINYU_PRISON_1, true);
                OpenClosePrison(DATA_JINYU_PRISON_2, true);
            }
            else if (prisoner == PRISONER_MONTAK)
            {
                OpenClosePrison(DATA_YAUNGOL_PRISON_1, true);
                OpenClosePrison(DATA_YAUNGOL_PRISON_2, true);
            }
        }

    private:

        void OpenClosePrison(uint32 type, bool open)
        {
            if (InstanceScript* pInstance = m_Owner->GetInstanceScript())
            {
                if (GameObject* pGo = pInstance->instance->GetGameObject(pInstance->GetObjectGuid(type)))
                    pGo->SetGoState(open ? GO_STATE_ACTIVE : GO_STATE_READY);
            }
        }

    private:

        Creature* m_Owner;
};

class boss_thok_the_bloodthirsty : public CreatureScript
{
    public:

        boss_thok_the_bloodthirsty() : CreatureScript("boss_thok_the_bloodthirsty") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_thok_the_bloodthirstyAI(creature);
        }

        struct boss_thok_the_bloodthirstyAI : public BossAI
        {
            boss_thok_the_bloodthirstyAI(Creature* creature) : BossAI(creature, DATA_THOK_THE_BLOODTHIRSTY),
                m_EnergyRegenerator(creature), m_PrisonsController(creature),
                m_IsInIntro(true), m_Phase(PHASE_NONE), m_FixateGuid(ObjectGuid::Empty), m_PrisonerGuid(ObjectGuid::Empty),
                m_IsYetiReleased(false), m_IsBatsReleased(false)
            {
                //ApplyAllImmunities(true);

                // Skull Bash increases energy cost of screech, it causes bug
                me->ApplySpellImmune(0, IMMUNITY_ID, 82365, true);

                me->setActive(true);
                me->SetBoundingRadius(6.0f);
                me->SetCombatReach(18.0f);

                EnableThok(false);

                if (instance->GetData(DATA_THOK_THE_BLOODTHRISTY_INTRO) == DONE)
                {
                    KillJailersIntro();
                }
            }

            void Reset() override
            {
                _Reset();

                m_EnergyRegenerator.Initialize();
                m_PrisonsController.ResetPrisons();

                InitPowers();
                InitVehicles();
                InitAdds();

                // reapply immunities to prevent bugs after spells with 'immunity_mask' effects.
                //ApplyAllImmunities(true);

                me->SetReactState(REACT_DEFENSIVE);

                m_Phase = PHASE_NONE;
                m_FixateGuid = ObjectGuid::Empty;
                m_PrisonerGuid = ObjectGuid::Empty;
                m_IsYetiReleased = false;
                m_IsBatsReleased = false;
            }

            void EnterCombat(Unit* who) override
            {
                m_Phase = PHASE_NORMAL;

                m_EnergyRegenerator.Activate();

                events.ScheduleEvent(EVENT_FEARSOME_ROAR, TIMER_FEARSOME_ROAR_FIRST);
                events.ScheduleEvent(EVENT_TAIL_LASH, TIMER_TAIL_LASH_FIRST);
                events.ScheduleEvent(EVENT_SHOCK_BLAST, TIMER_SHOCK_BLAST);
                events.ScheduleEvent(EVENT_BLOODIED_CHECK, TIMER_BLOODIED);
                events.ScheduleEvent(EVENT_BERSERK, TIMER_BERSERK);

                if (IsHeroic())
                {
                    SpawnCaptiveCaveBat();
                    SpawnStarvedYeti();
                }

                DoZoneInCombat();
                instance->SetBossState(DATA_THOK_THE_BLOODTHIRSTY, IN_PROGRESS);
            }

            void DoAction(const int32 action) override
            {
                switch (action)
                {
                    case ACTION_THOK_THE_BLOODTHIRSTY_INTRO:
                        KillJailersIntro();
                        break;
                    case ACTION_FULL_POWER:
                        DelayedDeafeningScreech();
                        break;
                    case ACTION_RESET_POWER:
                        m_EnergyRegenerator.ResetEnergy();
                        break;
                    case ACTION_BLOOD_FRENZY:
                        if (m_Phase == PHASE_FRENZY)
                            return;
                        m_Phase = PHASE_FRENZY;
                        events.ScheduleEvent(EVENT_BLOOD_FRENZY_INIT, 1);
                        break;
                    case ACTION_SAUROK_OPEN:
                        OpenPrison(PRISONER_AKOLIK);
                        break;
                    case ACTION_YAUNGOL_OPEN:
                        OpenPrison(PRISONER_MONTAK);
                        break;
                    case ACTION_JINYU_OPEN:
                        OpenPrison(PRISONER_GORAI);
                        break;
                    case ACTION_ATTACK_PRISONER:
                        AttackPrisoner();
                        break;
                    case ACTION_CONTINUE_ATTACKING:
                        ContinueAttackingWithPhase(PHASE_NORMAL);
                        break;
                    case ACTION_CONTINUE_ATTACKING_ACID:
                        ContinueAttackingWithPhase(PHASE_ACID);
                        break;
                    case ACTION_CONTINUE_ATTACKING_FROST:
                        ContinueAttackingWithPhase(PHASE_FROST);
                        break;
                    case ACTION_CONTINUE_ATTACKING_FIRE:
                        ContinueAttackingWithPhase(PHASE_FIRE);
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_THOK_IS_INTRO:
                        return (int)m_IsInIntro;
                    case DATA_DEAFENING_SCREECH_COUNT:
                        return GetDeafeningScreechCount();
                }

                return 0;
            }

            void SetGUID(ObjectGuid guid, int32 type) override
            {
                if (type == DATA_FIXATE_GUID)
                {
                    m_FixateGuid = guid;
                }
                else if (type == DATA_PRISONER_GUID)
                {
                    m_PrisonerGuid = guid;
                }
            }

            void JustDied(Unit* who) override
            {
                _JustDied();

                m_EnergyRegenerator.Stop();
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type == POINT_MOTION_TYPE)
                {
                    if (id == POINT_THOK_POS)
                    {
                        EnableThok(true);
                    }
                    else if (id == POINT_PRISONER)
                    {
                        EatPrisoner();
                    }
                }
            }

            // todo check this
            /*bool CanRegeneratePower(Powers power) const override
            {
                return false;
            }*/

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                m_EnergyRegenerator.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                DoMeleeAttackIfReady();
            }

            void ExecuteEvent(const uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_BERSERK:
                        DoBerserk();
                        break;
                    case EVENT_FEARSOME_ROAR:
                        DoFearsomeRoar();
                        events.ScheduleEvent(EVENT_FEARSOME_ROAR, TIMER_FEARSOME_ROAR);
                        break;
                    case EVENT_DEAFENING_SCREECH:
                        DoDeafeningScreech();
                        break;
                    case EVENT_TAIL_LASH:
                        DoTailLash();
                        events.ScheduleEvent(EVENT_TAIL_LASH, TIMER_TAIL_LASH);
                        break;
                    case EVENT_SHOCK_BLAST:
                        DoShockBlast();
                        events.ScheduleEvent(EVENT_SHOCK_BLAST, TIMER_SHOCK_BLAST);
                        break;
                    case EVENT_BLOODIED_CHECK:
                        DoBloodiedCheck();
                        events.ScheduleEvent(EVENT_BLOODIED_CHECK, TIMER_BLOODIED);
                        break;
                    case EVENT_BLOOD_FRENZY_INIT:
                        BloodFrenzyInit();
                        events.ScheduleEvent(EVENT_BLOOD_FRENZY_FIXATE, TIMER_FIXATE_FIRST);
                        break;
                    case EVENT_BLOOD_FRENZY_FIXATE:
                        BloodFrenzyFixate();
                        events.ScheduleEvent(EVENT_BLOOD_FRENZY_MOVE, 2000);
                        break;
                    case EVENT_BLOOD_FRENZY_MOVE:
                        BloodFrenzyMove();
                        break;
                    default:
                        break;
                }
            }

        private:

            void InitPowers()
            {
                me->AddAura(SPELL_ZERO_MANA_REGEN, me);

                me->SetPowerType(THOK_POWER_TYPE);
                me->SetMaxPower(THOK_POWER_TYPE, THOK_POWER_MAX);
                me->SetPower(THOK_POWER_TYPE, 0);
            }

            void InitVehicles()
            {
                if (Creature* pShockCollar = me->SummonCreature(NPC_SHOCK_COLLAR, *me))
                {
                    pShockCollar->EnterVehicle(me, SEAT_SHOCK_COLLAR);
                }

                if (Creature* pFootCollar = me->SummonCreature(NPC_FOOTS_COLLAR, *me))
                {
                    pFootCollar->EnterVehicle(me, SEAT_RIGHT_FOOT);
                }

                if (Creature* pFootCollar = me->SummonCreature(NPC_FOOTS_COLLAR, *me))
                {
                    pFootCollar->EnterVehicle(me, SEAT_LEFT_FOOT);
                }
            }

            void InitAdds()
            {
                me->SummonCreature(NPC_AKOLIK, prisonersPos[PRISONER_AKOLIK][0]);
                me->SummonCreature(NPC_WATERSPEAKER_GORAI, prisonersPos[PRISONER_GORAI][0]);
                me->SummonCreature(NPC_MONTAK, prisonersPos[PRISONER_MONTAK][0]);

                for (uint8 i = 0; i < SKUMBLADE_CAPTIVE_COUNT; ++i)
                    if (Creature* pCaptive = me->SummonCreature(NPC_SKUMBLADE_CAPTIVE, skumbladePos[i][0]))
                        pCaptive->AI()->SetData(DATA_NPC_NUMBER, i);

                for (uint8 i = 0; i < INKGILL_CAPTIVE_COUNT; ++i)
                    if (Creature* pCaptive = me->SummonCreature(NPC_INKGILL_CAPTIVE, inkgillPos[i][0]))
                        pCaptive->AI()->SetData(DATA_NPC_NUMBER, i);

                for (uint8 i = 0; i < GAI_CHO_CAPTIVE_COUNT; ++i)
                    if (Creature* pCaptive = me->SummonCreature(NPC_GAI_CHO_REFUGEE, gaichoPos[i][0]))
                        pCaptive->AI()->SetData(DATA_NPC_NUMBER, i);
            }

            void KillJailersIntro()
            {
                if (!m_IsInIntro)
                    return;

                m_IsInIntro = false;

                me->RemoveAura(SPELL_LIGHTNING_CHAIN);
                DoCastAOE(SPELL_KILL_JAILERS);

                me->GetMotionMaster()->MovePoint(POINT_THOK_POS, thokPos);
                me->SetHomePosition(thokPos);
            }

            void EnableThok(bool value)
            {
                if (value)
                {
                    me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
                }
                else
                {
                    me->SetUnitFlags(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
                }
            }

            uint32 GetDeafeningScreechCount() const
            {
                if (Aura* aur = me->GetAura(SPELL_ACCELERATION))
                {
                    return aur->GetStackAmount();
                }

                return 0;
            }

            void DoBerserk()
            {
                DoCast(me, SPELL_BERSERK);
            }

            void DoFearsomeRoar()
            {
                if (m_Phase == PHASE_NORMAL)
                {
                    DoCastVictim(SPELL_FEARSOME_ROAR);
                }
                else if (m_Phase == PHASE_ACID)
                {
                    DoCastVictim(SPELL_ACID_BREATH);
                }
                else if (m_Phase == PHASE_FROST)
                {
                    DoCastVictim(SPELL_FREEZING_BREATH);
                }
                else if (m_Phase == PHASE_FIRE)
                {
                    DoCastVictim(SPELL_SCORCHING_BREATH);
                }
            }

            void DelayedDeafeningScreech()
            {
                events.RescheduleEvent(EVENT_DEAFENING_SCREECH, 1);
            }

            void DoDeafeningScreech()
            {
                DoCast(SPELL_DEAFENING_SCREECH);
            }

            void DoTailLash()
            {
                DoCast(me, SPELL_TAIL_LASH);
            }

            void DoShockBlast()
            {
                if (m_Phase == PHASE_NORMAL)
                {
                    DoCastAOE(SPELL_SHOCK_BLAST_FORCE, true);
                }
                else if (m_Phase == PHASE_ACID)
                {
                    DoCastAOE(SPELL_CORROSIVE_BLOOD_FORCE, true);
                }
                else if (m_Phase == PHASE_FROST)
                {
                    DoCastAOE(SPELL_ICY_BLOOD_FORCE, true);
                }
                else if (m_Phase == PHASE_FIRE)
                {
                    DoCastAOE(SPELL_BURNING_BLOOD_FORCE, true);
                }
            }

            void DoBloodiedCheck()
            {
                BloodiedSelector selector;
                std::list<Unit*> targets;
                SelectTargetList(targets, selector, 25, SELECT_TARGET_RANDOM);

                for (Unit* target : targets)
                    me->AddAura(SPELL_BLOODIED, target);
            }

            void BloodFrenzyInit()
            {
                me->SetReactState(REACT_PASSIVE);
                me->AttackStop();

                m_EnergyRegenerator.Stop();

                events.CancelEvent(EVENT_FEARSOME_ROAR);
                events.CancelEvent(EVENT_TAIL_LASH);
                events.CancelEvent(EVENT_BLOODIED_CHECK);

                me->RemoveAura(SPELL_ACCELERATION);

                DoCast(me, SPELL_BLOOD_FRENZY_KNOCKBACK);

                SpawnJailer();
            }

            void BloodFrenzyFixate()
            {
                DoCastAOE(SPELL_FIXATE_AOE);
                me->ClearUnitState(UNIT_STATE_CASTING);

                events.ScheduleEvent(EVENT_BLOOD_FRENZY_FIXATE, TIMER_FIXATE);
            }

            void BloodFrenzyMove()
            {
                if (Unit* target = ObjectAccessor::GetUnit(*me, m_FixateGuid))
                {
                    me->SetOrientation(me->GetAngle(target));
                    me->SetFacingToObject(target);
                    me->GetMotionMaster()->MoveFollow(target, 0.0f, 0.0f);
                }

                me->AddAura(SPELL_CHOMP_CHECKER, me);
            }

            void SpawnJailer()
            {
                me->SummonCreature(NPC_KORKRON_JAILER, jailerPos);
            }

            void OpenPrison(Prisoners prisoner)
            {
                m_PrisonsController.OpenPrison(prisoner);

                if (prisoner == PRISONER_AKOLIK)
                {
                    EntryCheckPredicate prisonerPred(NPC_AKOLIK);
                    summons.DoAction(ACTION_PRISONER_RELEASED, prisonerPred);

                    EntryCheckPredicate captivePred(NPC_SKUMBLADE_CAPTIVE);
                    summons.DoAction(ACTION_PRISONER_RELEASED, captivePred);
                }
                else if (prisoner == PRISONER_MONTAK)
                {
                    EntryCheckPredicate prisonerPred(NPC_MONTAK);
                    summons.DoAction(ACTION_PRISONER_RELEASED, prisonerPred);

                    EntryCheckPredicate captivePred(NPC_GAI_CHO_REFUGEE);
                    summons.DoAction(ACTION_PRISONER_RELEASED, captivePred);
                }
                else if (prisoner == PRISONER_GORAI)
                {
                    EntryCheckPredicate prisonerPred(NPC_WATERSPEAKER_GORAI);
                    summons.DoAction(ACTION_PRISONER_RELEASED, prisonerPred);

                    EntryCheckPredicate captivePred(NPC_INKGILL_CAPTIVE);
                    summons.DoAction(ACTION_PRISONER_RELEASED, captivePred);
                }
            }

            void AttackPrisoner()
            {
                events.CancelEvent(EVENT_BLOOD_FRENZY_FIXATE);
                events.CancelEvent(EVENT_BLOOD_FRENZY_MOVE);

                me->RemoveAura(SPELL_CHOMP_CHECKER);
                me->RemoveAura(SPELL_BLOOD_FRENZY);
                me->RemoveAura(SPELL_BLOOD_FRENZY_SPEED);

                me->StopMoving();

                if (Creature* pPrisoner = instance->instance->GetCreature(m_PrisonerGuid))
                {
                    me->GetMotionMaster()->MovePoint(POINT_PRISONER, *pPrisoner);
                }
            }

            void EatPrisoner()
            {
                if (Creature* pPrisoner = instance->instance->GetCreature(m_PrisonerGuid))
                {
                    int32 seatId = SEAT_FACE;
                    pPrisoner->CastCustomSpell(me, SPELL_CHOMP_2, &seatId, NULL, NULL, true);
                }
            }

            void ContinueAttackingWithPhase(Phases phase)
            {
                me->SetReactState(REACT_AGGRESSIVE);

                m_Phase = phase;

                m_EnergyRegenerator.Activate();

                ReleaseBeast();

                events.ScheduleEvent(EVENT_FEARSOME_ROAR, TIMER_FEARSOME_ROAR_FIRST);
                events.ScheduleEvent(EVENT_TAIL_LASH, TIMER_TAIL_LASH_FIRST);
                events.ScheduleEvent(EVENT_BLOODIED_CHECK, TIMER_BLOODIED);
            }

            void SpawnCaptiveCaveBat()
            {
                for (uint8 i = 0; i < CAPTIVE_CAVE_BATS_COUNT; ++i)
                {
                    me->SummonCreature(NPC_CAPTIVE_CAVE_BAT, captiveCaveBatPos[i]);
                }
            }

            void SpawnStarvedYeti()
            {
                me->SummonCreature(NPC_STARVED_YETI, starvedYetiPos);
            }

            void ReleaseBeast()
            {
                if (!IsHeroic())
                    return;

                if (!m_IsBatsReleased)
                {
                    m_IsBatsReleased = true;
                    EntryCheckPredicate batsEntry(NPC_CAPTIVE_CAVE_BAT);
                    summons.DoAction(ACTION_RELEASE_BEAST, batsEntry);
                }
                else if (!m_IsYetiReleased)
                {
                    m_IsYetiReleased = true;
                    EntryCheckPredicate yetiEntry(NPC_STARVED_YETI);
                    summons.DoAction(ACTION_RELEASE_BEAST, yetiEntry);
                }
            }

        private:

            ThokEnergyRegenerator m_EnergyRegenerator;
            PrisonsController m_PrisonsController;
            Phases m_Phase;
            bool m_IsInIntro;
            ObjectGuid m_FixateGuid;
            ObjectGuid m_PrisonerGuid;
            bool m_IsYetiReleased;
            bool m_IsBatsReleased;
        };
};

class npc_thok_the_bloodthirsty_tesla_coil : public CreatureScript
{
    public:
        npc_thok_the_bloodthirsty_tesla_coil() : CreatureScript("npc_thok_the_bloodthirsty_tesla_coil") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_thok_the_bloodthirsty_tesla_coilAI(creature);
        }

        struct npc_thok_the_bloodthirsty_tesla_coilAI : public Scripted_NoMovementAI
        {
            npc_thok_the_bloodthirsty_tesla_coilAI(Creature* creature) : Scripted_NoMovementAI(creature),
                m_CoilAppliedOnThok(false)
            {
                pInstance = creature->GetInstanceScript();
            }

            void UpdateAI(const uint32 diff)
            {
                UpdateCoilOnThok();
            }

        private:

            void UpdateCoilOnThok()
            {
                if (m_CoilAppliedOnThok)
                    return;

                if (Creature* pThok = me->FindNearestCreature(NPC_THOK_THE_BLOODTHIRSTY, 10.0f))
                {
                    m_CoilAppliedOnThok = true;

                    if (pThok->AI()->GetData(DATA_THOK_IS_INTRO) == 1)
                    {
                        DoCast(pThok, SPELL_LIGHTNING_CHAIN);
                    }
                }
            }

        private:

            bool m_CoilAppliedOnThok;
            InstanceScript* pInstance;
        };
};

class npc_thok_the_bloodthirsty_collar : public CreatureScript
{
    public:
        npc_thok_the_bloodthirsty_collar() : CreatureScript("npc_thok_the_bloodthirsty_collar") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_thok_the_bloodthirsty_collarAI(creature);
        }

        struct npc_thok_the_bloodthirsty_collarAI : public Scripted_NoMovementAI
        {
            npc_thok_the_bloodthirsty_collarAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                pInstance = creature->GetInstanceScript();

                me->SetReactState(REACT_PASSIVE);
                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
            }

        private:

        private:

            InstanceScript* pInstance;
        };
};

class npc_thok_the_bloodthirsty_prisoner : public CreatureScript
{
    public:
        npc_thok_the_bloodthirsty_prisoner() : CreatureScript("npc_thok_the_bloodthirsty_prisoner") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_thok_the_bloodthirsty_prisonerAI(creature);
        }

        struct npc_thok_the_bloodthirsty_prisonerAI : public ScriptedAI
        {
            npc_thok_the_bloodthirsty_prisonerAI(Creature* creature) : ScriptedAI(creature), m_SceneHelper(creature->GetGUID(), creature->GetMap())
            {
                pInstance = creature->GetInstanceScript();

                me->SetReactState(REACT_PASSIVE);

                switch (me->GetEntry())
                {
                    case NPC_AKOLIK: m_Prisoner = PRISONER_AKOLIK; break;
                    case NPC_WATERSPEAKER_GORAI: m_Prisoner = PRISONER_GORAI; break;
                    case NPC_MONTAK: m_Prisoner = PRISONER_MONTAK; break;
                }
            }

            void DoAction(const int32 action) override
            {
                if (action == ACTION_PRISONER_RELEASED)
                {
                    MoveOutOfPrison();
                }
            }

            void UpdateAI(const uint32 diff)
            {
                m_SceneHelper.UpdateSceneHelper(diff);
            }

        private:

            void MoveOutOfPrison()
            {
                if (m_Prisoner >= PRISONERS_COUNT)
                    return;

                me->GetMotionMaster()->MovePoint(POINT_OUT_OF_PRISON, prisonersPos[m_Prisoner][1]);

                BeginScene();
            }

            void BeginScene()
            {
                if (m_Prisoner == PRISONER_AKOLIK)
                {
                    m_SceneHelper.Clear();

                    m_SceneHelper.AddSceneActionTalk(SAY_AKOLIK_1, 3000);
                    m_SceneHelper.AddSceneActionTalk(SAY_AKOLIK_2, 6000);
                    m_SceneHelper.AddSceneActionTalk(SAY_AKOLIK_3, 6000);
                    m_SceneHelper.AddSceneCast(SPELL_AKOLIKS_INCANTATION, 1000);

                    m_SceneHelper.Activate();
                }
                else if (m_Prisoner == PRISONER_GORAI)
                {
                    m_SceneHelper.Clear();

                    m_SceneHelper.AddSceneActionTalk(SAY_GORAI_1, 3000);
                    m_SceneHelper.AddSceneCast(SPELL_WATER_OF_PURITY, 3000);

                    m_SceneHelper.Activate();
                }
                else if (m_Prisoner == PRISONER_MONTAK)
                {
                    m_SceneHelper.Clear();

                    m_SceneHelper.AddSceneActionTalk(SAY_MONTAK_1, 3000);
                    m_SceneHelper.AddSceneCast(SPELL_FIRE_OF_THE_SPIRITS, 3000);

                    m_SceneHelper.Activate();
                }
            }

        private:
            SceneHelper m_SceneHelper;
            InstanceScript* pInstance;
            Prisoners m_Prisoner;
        };
};

class npc_thok_the_bloodthirsty_captive : public CreatureScript
{
    public:
        npc_thok_the_bloodthirsty_captive() : CreatureScript("npc_thok_the_bloodthirsty_captive") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_thok_the_bloodthirsty_captiveAI(creature);
        }

        struct npc_thok_the_bloodthirsty_captiveAI : public ScriptedAI
        {
            npc_thok_the_bloodthirsty_captiveAI(Creature* creature) : ScriptedAI(creature),
                m_NpcNumber(0)
            {
                pInstance = creature->GetInstanceScript();

                me->SetReactState(REACT_PASSIVE);
            }

            void SetData(uint32 type, uint32 data) override
            {
                if (type == DATA_NPC_NUMBER)
                {
                    m_NpcNumber = data;
                }
            }

            void DoAction(const int32 action) override
            {
                if (action == ACTION_PRISONER_RELEASED)
                {
                    MoveOutOfPrison();
                }
            }

        private:

            void MoveOutOfPrison()
            {
                if (me->GetEntry() == NPC_SKUMBLADE_CAPTIVE)
                {
                    me->GetMotionMaster()->MovePoint(POINT_OUT_OF_PRISON, skumbladePos[m_NpcNumber][1]);
                }
                else if (me->GetEntry() == NPC_INKGILL_CAPTIVE)
                {
                    me->GetMotionMaster()->MovePoint(POINT_OUT_OF_PRISON, inkgillPos[m_NpcNumber][1]);
                }
                else if (me->GetEntry() == NPC_GAI_CHO_REFUGEE)
                {
                    me->GetMotionMaster()->MovePoint(POINT_OUT_OF_PRISON, gaichoPos[m_NpcNumber][1]);
                }
            }

        private:

            InstanceScript* pInstance;
            uint32 m_NpcNumber;
        };
};

struct npc_thok_the_bloodthirsty_captive_beastAI : public ScriptedAI
{
    npc_thok_the_bloodthirsty_captive_beastAI(Creature* creature) : ScriptedAI(creature)
    {
        //ApplyAllImmunities(true);
        me->SetReactState(REACT_PASSIVE);
    }

    void Reset() override
    {
        events.Reset();
    }

    void DoAction(const int32 action) override
    {
        if (action == ACTION_RELEASE_BEAST)
        {
            HandleReleaseBeast();
        }
    }

    void JustDied(Unit* killer) override
    {
        events.Reset();
    }

protected:

    virtual void HandleReleaseBeast() { }
};

class npc_thok_the_bloodthirsty_captive_cave_bat : public CreatureScript
{
    public:
        npc_thok_the_bloodthirsty_captive_cave_bat() : CreatureScript("npc_thok_the_bloodthirsty_captive_cave_bat") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_thok_the_bloodthirsty_captive_cave_batAI(creature);
        }

        struct npc_thok_the_bloodthirsty_captive_cave_batAI : public npc_thok_the_bloodthirsty_captive_beastAI
        {
            npc_thok_the_bloodthirsty_captive_cave_batAI(Creature* creature) : npc_thok_the_bloodthirsty_captive_beastAI(creature)
            {
                me->SetReactState(REACT_PASSIVE);

                me->SetDisableGravity(true);
            }

            void Reset() override
            {
                npc_thok_the_bloodthirsty_captive_beastAI::Reset();
            }

            void JustDied(Unit* killer) override
            {
                npc_thok_the_bloodthirsty_captive_beastAI::JustDied(killer);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }

        protected:

            void HandleReleaseBeast() override
            {
                me->SetReactState(REACT_AGGRESSIVE);
            }

        };
};

class npc_thok_the_bloodthirsty_starved_yeti : public CreatureScript
{
    public:
        npc_thok_the_bloodthirsty_starved_yeti() : CreatureScript("npc_thok_the_bloodthirsty_starved_yeti") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_thok_the_bloodthirsty_starved_yetiAI(creature);
        }

        struct npc_thok_the_bloodthirsty_starved_yetiAI : public npc_thok_the_bloodthirsty_captive_beastAI
        {
            npc_thok_the_bloodthirsty_starved_yetiAI(Creature* creature) : npc_thok_the_bloodthirsty_captive_beastAI(creature)
            {
            }

            void Reset() override
            {
                npc_thok_the_bloodthirsty_captive_beastAI::Reset();

                m_NextWreckingBallPos = wreckingBallPos[0];
            }

            void EnterCombat(Unit* victim) override
            {
                events.ScheduleEvent(EVENT_WRECKING_BALL, TIMER_WRECKING_BALL_FIRST);
            }

            void MovementInform(uint32 type, uint32 data) override
            {
                if (data == EVENT_JUMP)
                {
                    me->GetMotionMaster()->MovementExpired(false);
                    events.ScheduleEvent(EVENT_WRECKING_BALL, TIMER_WRECKING_BALL_FIRST);
                }
                else if (data == POINT_WRECKING_BALL)
                {
                    me->GetMotionMaster()->MovementExpired(false);

                    HandleWreckingBallEnd();
                }
            }

            void DoAction(const int32 action) override
            {
                npc_thok_the_bloodthirsty_captive_beastAI::DoAction(action);

                if (action == ACTION_WRECKING_BALL)
                {
                    HandleWreckingBallCast();
                }
            }

            void JustDied(Unit* killer) override
            {
                npc_thok_the_bloodthirsty_captive_beastAI::JustDied(killer);
            }

            void UpdateAI(const uint32 diff) override
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
                        case EVENT_WRECKING_BALL:
                            DoWreckingBall();
                            break;
                    }
                }
            }

        private:

            void HandleReleaseBeast() override
            {
                me->GetMotionMaster()->MoveJump(wreckingBallPos[4], 42.f, 20.f);
            }

            void DoWreckingBall()
            {
                GetFarestWreckingBallPosition(m_NextWreckingBallPos);
                SpawnWreckingBallMark(m_NextWreckingBallPos);

                DoCast(me, SPELL_WRECKING_BALL_DUMMY);
            }

            void HandleWreckingBallCast()
            {
                me->GetMotionMaster()->MoveCharge(m_NextWreckingBallPos.GetPositionX(), m_NextWreckingBallPos.GetPositionY(), m_NextWreckingBallPos.GetPositionZ(), 42.f, POINT_WRECKING_BALL);
            }

            void GetFarestWreckingBallPosition(Position& position)
            {
                std::list<Position> positions;
                for (auto& pos : wreckingBallPos)
                    positions.push_back(pos);

                positions.sort(PositionsCompareOrderPred(me, false));

                positions.resize(3);

                position = Trinity::Containers::SelectRandomContainerElement(positions);
            }

            void SpawnWreckingBallMark(Position& pos)
            {
                if (Creature* pTrigger = me->SummonCreature(WORLD_TRIGGER, pos, TEMPSUMMON_TIMED_DESPAWN, 6000))
                {
                    pTrigger->AddAura(SPELL_WRECKING_BALL_VISUAL, pTrigger);
                }
            }

            void HandleWreckingBallEnd()
            {
                DoCast(me, SPELL_WRECKING_BALL_DMG_2, true);

                events.ScheduleEvent(EVENT_WRECKING_BALL, TIMER_WRECKING_BALL);
            }

        private:

            class PositionsCompareOrderPred
            {
                public:
                    PositionsCompareOrderPred(const WorldObject* object, bool ascending = true) : m_object(object), m_ascending(ascending) {}
                    bool operator() (Position& a, Position& b) const
                    {
                        return m_ascending ? m_object->GetDistance(a) < m_object->GetDistance(b) :
                                             m_object->GetDistance(a) > m_object->GetDistance(b);
                    }
                private:
                    const WorldObject* m_object;
                    const bool m_ascending;
            };

        private:
            Position m_NextWreckingBallPos;

        };
};

class spell_thok_the_bloodthirsty_deafening_screech : public SpellScriptLoader
{
    public:
        spell_thok_the_bloodthirsty_deafening_screech() : SpellScriptLoader("spell_thok_the_bloodthirsty_deafening_screech") { }

        class spell_thok_the_bloodthirsty_deafening_screech_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_thok_the_bloodthirsty_deafening_screech_SpellScript);

            void HandleHitTarget(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                if (GetCaster()->GetMap()->IsHeroic())
                {
                    if (Aura const* aur = GetCaster()->GetAura(SPELL_ACCELERATION))
                    {
                        if (aur->GetStackAmount() >= 30)
                        {
                            SetHitDamage(GetHitDamage() * 3);
                        }
                    }
                }
            }

            void HandleAfterCast()
            {
                if (!GetCaster())
                    return;

                if (Creature* pThok = GetCaster()->ToCreature())
                {
                    pThok->AI()->DoAction(ACTION_RESET_POWER);
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_thok_the_bloodthirsty_deafening_screech_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
                AfterCast += SpellCastFn(spell_thok_the_bloodthirsty_deafening_screech_SpellScript::HandleAfterCast);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_thok_the_bloodthirsty_deafening_screech_SpellScript();
        }
};

class spell_thok_the_bloodthirsty_bloodied : public SpellScriptLoader
{
    public:
        spell_thok_the_bloodthirsty_bloodied() : SpellScriptLoader("spell_thok_the_bloodthirsty_bloodied") { }

        class spell_thok_the_bloodthirsty_bloodied_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_thok_the_bloodthirsty_bloodied_AuraScript);

            void HandleApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
            {
                if (!GetUnitOwner())
                    return;

                GetUnitOwner()->AddAura(SPELL_BLOODIED_WOUNDS, GetUnitOwner());
            }

            void HandleRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
            {
                if (!GetUnitOwner())
                    return;

                GetUnitOwner()->RemoveAura(SPELL_BLOODIED_WOUNDS);
            }

            void Register()
            {
                AfterEffectApply += AuraEffectApplyFn(spell_thok_the_bloodthirsty_bloodied_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectApplyFn(spell_thok_the_bloodthirsty_bloodied_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_thok_the_bloodthirsty_bloodied_AuraScript();
        }
};

class spell_thok_the_bloodthirsty_bloodied_wounds : public SpellScriptLoader
{
    public:
        spell_thok_the_bloodthirsty_bloodied_wounds() : SpellScriptLoader("spell_thok_the_bloodthirsty_bloodied_wounds") { }

        class spell_thok_the_bloodthirsty_bloodied_wounds_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_thok_the_bloodthirsty_bloodied_wounds_AuraScript);

            bool Load()
            {
                m_BloodiedPlayersCount = GetUnitOwner()->GetMap()->Is25ManRaid() ? BLOODIED_PLAYERS_COUNT_25 : BLOODIED_PLAYERS_COUNT_10;

                return true;
            }

            void HandlePeriodic(AuraEffect const* aurEff)
            {
                if (!GetUnitOwner())
                    return;

                if (GetUnitOwner()->GetHealthPct() >= 50.f)
                {
                    GetUnitOwner()->RemoveAura(SPELL_BLOODIED);
                    return;
                }

                if (GetNearBloodiedPlayersCount() >= m_BloodiedPlayersCount)
                {
                    if (Creature* pThok = GetThokTheBloodthirsty(GetUnitOwner()))
                    {
                        pThok->AI()->DoAction(ACTION_BLOOD_FRENZY);
                    }
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_thok_the_bloodthirsty_bloodied_wounds_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }

        private:

            class BloodiedPlayersCheck
            {
                public:

                    BloodiedPlayersCheck(WorldObject const* obj, float range) :
                        _obj(obj), _range(range) {}

                    bool operator()(Player* u)
                    {
                        if (!u->IsAlive())
                            return false;

                        if (_obj->GetDistance2d(u) >= _range)
                            return false;

                        if (!u->HasAura(SPELL_BLOODIED))
                            return false;

                        return true;
                    }

                private:
                    WorldObject const* _obj;
                    float _range;
            };

        private:

            uint32 GetNearBloodiedPlayersCount()
            {
                const float bloodiedRange = 10.0f;

                std::list<Player*> players;
                BloodiedPlayersCheck check(GetUnitOwner(), bloodiedRange);
                Trinity::PlayerListSearcher<BloodiedPlayersCheck> searcher(GetUnitOwner(), players, check);
                //GetUnitOwner()->VisitNearbyWorldObject(bloodiedRange, searcher);
                Cell::VisitWorldObjects(GetUnitOwner(), searcher, bloodiedRange);

                return players.size();
            }

            Creature* GetThokTheBloodthirsty(WorldObject* const searcher)
            {
                if (InstanceScript* pInstance = searcher->GetInstanceScript())
                {
                    return pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_THOK_THE_BLOODTHIRSTY));
                }

                return NULL;
            }

        private:

           uint8 m_BloodiedPlayersCount;

        };

        AuraScript* GetAuraScript() const
        {
            return new spell_thok_the_bloodthirsty_bloodied_wounds_AuraScript();
        }
};

class spell_thok_the_bloodthirsty_fixate : public SpellScriptLoader
{
    public:
        spell_thok_the_bloodthirsty_fixate() : SpellScriptLoader("spell_thok_the_bloodthirsty_fixate") { }

        class spell_thok_the_bloodthirsty_fixate_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_thok_the_bloodthirsty_fixate_SpellScript);

            void HandleHitTarget(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                if (Creature* pThok = GetCaster()->ToCreature())
                {
                    // 143445 has it's own red ray, don't cast another
                    //pThok->CastSpell(GetHitUnit(), SPELL_FIXATE_DUMMY, true);
                    pThok->CastSpell(pThok, SPELL_BLOOD_FRENZY, true);
                    pThok->AI()->SetGUID(GetHitUnit()->GetGUID(), DATA_FIXATE_GUID);
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_thok_the_bloodthirsty_fixate_SpellScript::HandleHitTarget, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_thok_the_bloodthirsty_fixate_SpellScript();
        }
};

class spell_thok_the_bloodthirsty_prisoner_threat_spell : public SpellScriptLoader
{
    public:
        spell_thok_the_bloodthirsty_prisoner_threat_spell() : SpellScriptLoader("spell_thok_the_bloodthirsty_prisoner_threat_spell") { }

        class spell_thok_the_bloodthirsty_prisoner_threat_spell_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_thok_the_bloodthirsty_prisoner_threat_spell_SpellScript);

            void HandleHitTarget(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                if (Creature* pThok = GetHitUnit()->ToCreature())
                {
                    pThok->AI()->SetGUID(GetCaster()->GetGUID(), DATA_PRISONER_GUID);
                    pThok->AI()->DoAction(ACTION_ATTACK_PRISONER);
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_thok_the_bloodthirsty_prisoner_threat_spell_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_thok_the_bloodthirsty_prisoner_threat_spell_SpellScript();
        }
};

class spell_thok_the_bloodthirsty_chomp_prisoner : public SpellScriptLoader
{
    public:
        spell_thok_the_bloodthirsty_chomp_prisoner() : SpellScriptLoader("spell_thok_the_bloodthirsty_chomp_prisoner") { }

        class spell_thok_the_bloodthirsty_chomp_prisoner_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_thok_the_bloodthirsty_chomp_prisoner_AuraScript);

            void HandleRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
            {
                if (!GetCaster() || !GetUnitOwner())
                    return;

                if (Creature* pThok = GetUnitOwner()->ToCreature())
                {
                    pThok->Kill(GetCaster());

                    if (pThok->GetMap()->IsHeroic())
                        pThok->CastSpell(pThok, SPELL_MENDING, true);

                    switch (GetCaster()->GetEntry())
                    {
                        case NPC_AKOLIK: pThok->AI()->DoAction(ACTION_CONTINUE_ATTACKING_ACID); break;
                        case NPC_MONTAK: pThok->AI()->DoAction(ACTION_CONTINUE_ATTACKING_FROST); break;
                        case NPC_WATERSPEAKER_GORAI: pThok->AI()->DoAction(ACTION_CONTINUE_ATTACKING_FIRE); break;
                        default: pThok->AI()->DoAction(ACTION_CONTINUE_ATTACKING); break;
                    }
                }
            }

            void Register()
            {
                AfterEffectRemove += AuraEffectApplyFn(spell_thok_the_bloodthirsty_chomp_prisoner_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_CONTROL_VEHICLE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_thok_the_bloodthirsty_chomp_prisoner_AuraScript();
        }
};

class spell_thok_the_bloodthirsty_wrecking_ball_dummy : public SpellScriptLoader
{
    public:
        spell_thok_the_bloodthirsty_wrecking_ball_dummy() : SpellScriptLoader("spell_thok_the_bloodthirsty_wrecking_ball_dummy") { }

        class spell_thok_the_bloodthirsty_wrecking_ball_dummy_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_thok_the_bloodthirsty_wrecking_ball_dummy_SpellScript);

            void HandleHitTarget(SpellEffIndex effIndex)
            {
                if (!GetCaster())
                    return;

                if (Creature* pYetti = GetHitUnit()->ToCreature())
                {
                    pYetti->AI()->DoAction(ACTION_WRECKING_BALL);
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_thok_the_bloodthirsty_wrecking_ball_dummy_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_thok_the_bloodthirsty_wrecking_ball_dummy_SpellScript();
        }
};

class go_thok_the_bloodthirsty_prison : public GameObjectScript
{
    public:

        go_thok_the_bloodthirsty_prison() : GameObjectScript("go_thok_the_bloodthirsty_prison")
        {
        }

        GameObjectAI* GetAI(GameObject* go) const
        {
            return new go_thok_the_bloodthirsty_prisonAI(go);
        }

        struct go_thok_the_bloodthirsty_prisonAI : public GameObjectAI
        {
            go_thok_the_bloodthirsty_prisonAI(GameObject* go) : GameObjectAI(go)
            {
            }

            bool GossipHello(Player* player, bool /*reportUse*/) override
            {
                if (!IsEncounterInProgress(player))
                    return true;

                if (!player->HasItemCount(ITEM_SKELETON_KEY, 1))
                    return true;

                player->DestroyItemCount(ITEM_SKELETON_KEY, 1, true);

                if (Creature* pThok = GetThokTheBloodthirsty())
                {
                    switch (go->GetEntry())
                    {
                        case GO_SAUROK_PRISON_1:
                        case GO_SAUROK_PRISON_2:
                            pThok->AI()->DoAction(ACTION_SAUROK_OPEN);
                            break;
                        case GO_YAUNGOL_PRISON_1:
                        case GO_YAUNGOL_PRISON_2:
                            pThok->AI()->DoAction(ACTION_YAUNGOL_OPEN);
                            break;
                        case GO_JINYU_PRISON_1:
                        case GO_JINYU_PRISON_2:
                            pThok->AI()->DoAction(ACTION_JINYU_OPEN);
                            break;
                    }
                }

                return true;
            }

        private:

            Creature* GetThokTheBloodthirsty()
            {
                if (InstanceScript* pInstance = go->GetInstanceScript())
                {
                    return pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_THOK_THE_BLOODTHIRSTY));
                }

                return NULL;
            }

            bool IsEncounterInProgress(WorldObject* searcher)
            {
                if (InstanceScript* pInstance = searcher->GetInstanceScript())
                {
                    if (pInstance->GetBossState(DATA_THOK_THE_BLOODTHIRSTY) == IN_PROGRESS)
                        return true;
                }

                return false;
            }

        };
};

class spell_thok_the_bloodthirsty_chomp_checker : public SpellScriptLoader
{
public:
    spell_thok_the_bloodthirsty_chomp_checker() : SpellScriptLoader("spell_thok_the_bloodthirsty_chomp_checker") { }

    class spell_thok_the_bloodthirsty_chomp_checker_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_thok_the_bloodthirsty_chomp_checker_SpellScript);

        void HandleHitTarget(SpellEffIndex effIndex)
        {
            if (GetHitUnit())
                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_CHOMP, true);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_thok_the_bloodthirsty_chomp_checker_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_thok_the_bloodthirsty_chomp_checker_SpellScript();
    }
};

void AddSC_boss_thok_the_bloodthirsty()
{
    new boss_thok_the_bloodthirsty();                       // 71529
    new npc_thok_the_bloodthirsty_tesla_coil();             // 73198
    new npc_thok_the_bloodthirsty_collar();                 // 71645 73200
    new npc_thok_the_bloodthirsty_prisoner();               // 71742 71749 71763
    new npc_thok_the_bloodthirsty_captive();                // 71744 71753 71764
    new npc_thok_the_bloodthirsty_captive_cave_bat();       // 73522
    new npc_thok_the_bloodthirsty_starved_yeti();           // 73526

    new spell_thok_the_bloodthirsty_deafening_screech();    // 143343
    new spell_thok_the_bloodthirsty_bloodied();             // 143452
    new spell_thok_the_bloodthirsty_bloodied_wounds();      // 143451
    new spell_thok_the_bloodthirsty_fixate();               // 143445
    new spell_thok_the_bloodthirsty_prisoner_threat_spell();  // 144016 144013 144014
    new spell_thok_the_bloodthirsty_chomp_prisoner();       // 147996
    new spell_thok_the_bloodthirsty_wrecking_ball_dummy();  // 147952

    new go_thok_the_bloodthirsty_prison();                  // 222046 222047 223005 223006 222010 222011
    new spell_thok_the_bloodthirsty_chomp_checker();        // 126101
}
