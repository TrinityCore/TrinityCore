#include "siege_of_orgrimmar.hpp"
#include "SpellAuraEffects.h"

#define MALKOROK_POWER_TYPE POWER_ENERGY
#define MALKOROK_POWER_MAX 100

#define ENERGY_UPDATE_TIMER 1000 // in milliseconds
#define FIRST_PHASE_DURATION 140000 // in milliseconds
//#define FIRST_PHASE_DURATION 10000 // in milliseconds

// The boss regenerates 100 rage in 140 seconds
// He should cast the '3 smashes and 1 breath' combo two times per phase
// So he casts arcing smash each 10-15 energy

enum ScriptedTexts
{
    SAY_AGGRO               = 0,
    SAY_DEATH               = 1,
    SAY_INTRO               = 2,
    SAY_WIPE                = 3,
    SAY_ARCING_SMASH        = 4,
    SAY_BREATH_OF_YSHAARJ   = 5,
    SAY_BLOOD_RAGE          = 6,
    SAY_ZERK                = 7,
};

enum Spells
{
    SPELL_ZERO_MANA_REGEN           = 96301,

    SPELL_ERADICATE                 = 143916,

    SPELL_ANCIENT_MIASMA_AURA       = 142861,
    SPELL_ANCIENT_MIASMA_DMG        = 142906,
    SPELL_ANCIENT_MIASMA_DUMMY_1    = 143018, // on dummy npc
    SPELL_ANCIENT_MIASMA_DUMMY_2    = 143042, // casted by miasmas on blood rage beginning
    SPELL_ANCIENT_MIASMA_DUMMY_3    = 143047, // maybe casted by controller npc 71459
    SPELL_EXPEL_MIASMA              = 143199,
    SPELL_ANCIENT_MIASMA_DUMMY_4    = 143983, // from miasmas to the boss on blood rage beginning
    SPELL_ANCIENT_MIASMA_DUMMY_5    = 149440, // casted by miasmas after blood rage (and after hit by 149443)
    SPELL_ANCIENT_MIASMA_DUMMY_6    = 149443, // aoe spell from the boss to all miasmas after blood rage

    SPELL_ANCIENT_BARRIER           = 142862,
    SPELL_WEAK_ANCIENT_BARRIER      = 142863,
    SPELL_MIDDLE_ANCIENT_BARRIER    = 142864,
    SPELL_STRONG_ANCIENT_BARRIER    = 142865,

    SPELL_BLOOD_RAGE                = 142879,
    SPELL_BLOOD_RAGE_DMG            = 142890,
    SPELL_RELENTLESS_ASSAULT        = 143261,

    SPELL_SEISMIC_SLAM              = 142851,
    SPELL_SEISMIC_SLAM_DMG          = 142849,
    SPELL_SEISMIC_SLAM_SUMMON       = 143586, // on heroic

    SPELL_ARCING_SMASH_JUMP         = 142898,
    SPELL_ARCING_SMASH_DUMMY        = 142826, // triggered by jump spell
    SPELL_ARCING_SMASH_CHANNEL      = 143805, //
    SPELL_ARCING_SMASH_DUMMY_2      = 143806, // ?
    SPELL_ARCING_SMASH_DMG          = 142815,

    SPELL_BREATH_OF_YSHAARJ         = 142842,
    SPELL_BREATH_OF_YSHAARJ_DMG     = 142816,

    SPELL_FATAL_STRIKES             = 146254,
    SPELL_FATAL_STRIKE              = 142990,

    SPELL_IMPLODING_ENERGY          = 142980,
    SPELL_IMPLODING_ENERGY_AOE      = 142988,
    SPELL_IMPLODING_ENERGY_AURA     = 144069,
    SPELL_IMPLODING_ENERGY_DMG      = 142986,
    SPELL_IMPLODING_ENERGY_DMG_2    = 142987, // if nobody was hit by first dmg spell

    SPELL_DISPLACED_ENERGY          = 142913,
    SPELL_DISPLACED_ENERGY_DMG      = 142928,

    SPELL_ESSENSE_OF_YSHAARJ_SELF   = 143846,
    SPELL_ESSENSE_OF_YSHAARJ_DUMMY  = 143848, // triggered by 143846
    SPELL_ESSENSE_OF_YSHAARJ_DUMMY_2    = 143902,
    SPELL_ESSENSE_OF_YSHAARJ_AREATRIGGER    = 143850,
    SPELL_ESSENSE_OF_YSHAARJ_DMG    = 143857,
    SPELL_ESSENSE_OF_YSHAARJ_SCRIPT = 143908, // ?
    SPELL_ESSENSE_OF_YSHAARJ_EXPLODE = 143913, // visual

    SPELL_LANGUISH_AURA             = 142989,
    SPELL_LANGUISH_DEBUFF           = 143919,
};

enum Adds
{
    NPC_CONTROLLER          = 71459, // casts 71459 spell
    NPC_ANCIENT_MIASMA      = 71513,
    NPC_ARCING_SMASH        = 71455,
    NPC_IMPLOSION           = 71470,

    NPC_LIVING_CORRUPTION   = 71644, // on heroic
};

enum Events
{
    EVENT_BERSERK   = 1,
    EVENT_ARCING_SMASH_JUMP,
    EVENT_IMPLODING_ENERGY,
    EVENT_DISPLACED_ENERGY,
    EVENT_CLEAR_ARCING_SMASH,
    EVENT_BLOOD_RAGE,
};

enum Actions
{
    ACTION_ENERGY_FULL  = 1,
    ACTION_ENERGY_EMPTY,
    ACTION_IMPLOSION_DAMAGE,
    ACTION_ENDLESS_RAGE,
    ACTION_EXPEL_MIASMA,
    ACTION_SEISMIC_SLAM,
    ACTION_ARCING_SMASH,
    ACTION_BREATH_OF_YSHAARJ,
};

enum Timers
{
    TIMER_BERSERK                   = 6 * MINUTE * IN_MILLISECONDS,
    TIMER_EVADE_CHECK               = 5 * IN_MILLISECONDS,

    TIMER_IMPLODING_ENERGY          = 5 * IN_MILLISECONDS, // explodes in 10 seconds after arcing smash

    TIMER_DISPLACED_ENERGY_FIRST    = 3500,
    TIMER_DISPLACED_ENERGY          = 11000,
};

enum Phases : int
{
    PHASE_NONE                  = 0,
    PHASE_MIGHT_OF_THE_KORKRON  = 1,
    PHASE_ENDLESS_RAGE          = 2,
    PHASE_EXPEL_MIASMA          = 3,
};

const Position miasmasPos[4] =
{
    {1914.38f, -4950.57f, -198.96f, 3.77f}, // at center
    {1897.40f, -4962.41f, -198.86f, 0.54f},
    {1932.11f, -4961.39f, -198.99f, 2.07f},
    {1926.67f, -4934.21f, -198.99f, 2.32f}
};

const Position centerPos = {1914.38f, -4950.57f, -198.96f, 3.77f};

#define SEISMIC_SLAM_COUNT 6
const float seismicSlamEnergy[SEISMIC_SLAM_COUNT]
{
    4.f, 18.f, 32.f, 54.f, 68.f, 82.f
};

#define ARCING_SMASH_COUNT 6
const float arcingSmashEnergy[ARCING_SMASH_COUNT]
{
    10.f, 25.f, 40.f, 60.f, 75.f, 90.f
};

#define BREATH_OF_YSHAARJ_COUNT 2
const float breathOfYshaarjEnergy[BREATH_OF_YSHAARJ_COUNT]
{
    48.f, 98.f
};

#define IMPLODING_ENERGY_MIN_DIST 20.f
#define IMPLODING_ENERGY_MAX_DIST 30.f
#define IMPLODING_ENERGY_COUNT_10PPL 3
#define IMPLODING_ENERGY_COUNT_25PPL 7

#define LANGUISH_RANGE 3.f

#define ESSENSE_OF_YSHAARJ_COUNT_10 2
#define ESSENSE_OF_YSHAARJ_COUNT_25 5

#define EVADE_DISTANCE 45.f

class EnergyRegenerator
{
    public:

        EnergyRegenerator(Creature* owner) : m_Owner(owner) { }

        void Activate() { m_IsActive = true; }
        bool IsActive() const { return m_IsActive; }
        void Stop()
        {
            m_IsActive = false;
        }

        void Reset()
        {
            Stop();
            m_Owner->SetPower(MALKOROK_POWER_TYPE, 0);
            m_UpdateTimer = ENERGY_UPDATE_TIMER;
            m_OwnerEnergy = 0.f;
            m_SeismicSlamCount = 0;
            m_ArcingSmashCount = 0;
            m_BreathOfYshaarjCount = 0;

            UpdateOwnerEnergy();
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

        void UpdateEnergy()
        {
            int32 currentEnergy = (int32)m_OwnerEnergy;
            if (currentEnergy >= MALKOROK_POWER_MAX)
                return;

            float updatePart = (float)FIRST_PHASE_DURATION / (float)ENERGY_UPDATE_TIMER;
            float energyToAdd = (float)MALKOROK_POWER_MAX / updatePart;
            m_OwnerEnergy += energyToAdd;

            UpdateOwnerEnergy();

            if (m_SeismicSlamCount < SEISMIC_SLAM_COUNT &&
                m_OwnerEnergy >= seismicSlamEnergy[m_SeismicSlamCount])
            {
                ++m_SeismicSlamCount;
                m_Owner->AI()->DoAction(ACTION_SEISMIC_SLAM);
            }

            if (m_ArcingSmashCount < ARCING_SMASH_COUNT &&
                m_OwnerEnergy >= arcingSmashEnergy[m_ArcingSmashCount])
            {
                ++m_ArcingSmashCount;
                m_Owner->AI()->DoAction(ACTION_ARCING_SMASH);
            }

            if (m_BreathOfYshaarjCount < BREATH_OF_YSHAARJ_COUNT &&
                m_OwnerEnergy >= breathOfYshaarjEnergy[m_BreathOfYshaarjCount])
            {
                ++m_BreathOfYshaarjCount;
                m_Owner->AI()->DoAction(ACTION_BREATH_OF_YSHAARJ);
            }

            if ((int)m_OwnerEnergy >= MALKOROK_POWER_MAX)
            {
                m_Owner->AI()->DoAction(ACTION_ENERGY_FULL);
            }
        }

        void UpdateOwnerEnergy()
        {
            m_Owner->SetPower(MALKOROK_POWER_TYPE, (int)m_OwnerEnergy);
        }

    private:

        Creature* m_Owner;
        uint32 m_UpdateTimer;
        bool m_IsActive;
        float m_OwnerEnergy;

        uint32 m_SeismicSlamCount;
        uint32 m_ArcingSmashCount;
        uint32 m_BreathOfYshaarjCount;
};

class boss_malkorok : public CreatureScript
{
    public:

        boss_malkorok() : CreatureScript("boss_malkorok") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_malkorokAI(creature);
        }

        struct boss_malkorokAI : public BossAI
        {
            boss_malkorokAI(Creature* creature) : BossAI(creature, DATA_MALKOROK),
                m_EnergyRegenerator(creature), checkEvadeTimer(TIMER_EVADE_CHECK), m_CombatAuraHelper(creature)
            {
                //ApplyAllImmunities(true);
                me->setActive(true);
            }

            void Reset() override
            {
                _Reset();
                me->RemoveAllAreaTriggers();

                m_EnergyRegenerator.Reset();

                InitPowers();
                SpawnMiasmas();
                RemoveInstanceAuras();

                SetPhase(PHASE_NONE);

                me->SetReactState(REACT_DEFENSIVE);
            }

            void EnterCombat(Unit* who) override
            {
                Talk(SAY_AGGRO);

                events.ScheduleEvent(EVENT_BERSERK, TIMER_BERSERK);

                me->AddAura(SPELL_FATAL_STRIKES, me);

                ToggleEssenseOfYshaarj(true);

                m_EnergyRegenerator.Activate();

                ActivateMiasma(true);

                SetPhase(PHASE_MIGHT_OF_THE_KORKRON);

                DoZoneInCombat();
                instance->SetBossState(DATA_MALKOROK, IN_PROGRESS);
            }

            void JustDied(Unit* who) override
            {
                Talk(SAY_DEATH);

                _JustDied();

                RemoveInstanceAuras();
            }

            // todo check this
            /*bool CanRegeneratePower(Powers power) const override
            {
                return false;
            }*/

            void MovementInform(uint32 type, uint32 id) override
            {
                if (id == EVENT_JUMP) // 1004
                {
                    me->GetMotionMaster()->MovementExpired(false);
                    me->StopMoving();
                    DoArcingSmash();
                }
            }

            void DoAction(const int32 action) override
            {
                if (action == ACTION_SEISMIC_SLAM)
                {
                    DoSeismicSlam();
                }
                else if (action == ACTION_ARCING_SMASH)
                {
                    DoArcingSmashJump();
                }
                else if (action == ACTION_BREATH_OF_YSHAARJ)
                {
                    DoBreathOfYshaarj();
                }
                else if (action == ACTION_ENERGY_FULL)
                {
                    DoBloodRageDelayed(); // use delayed event to prevent interrupting
                }
                else if (action == ACTION_ENERGY_EMPTY)
                {
                    DoMightOfTheKorkron();
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (CheckEvade(diff))
                    return;

                events.Update(diff);

                m_EnergyRegenerator.Update(diff);

                m_CombatAuraHelper.UpdateCombatAuras(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (DoExpelMiasma())
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                if (IsEndlessRagePhase())
                {
                    if (!me->HasUnitState(UNIT_STATE_CASTING) && me->isAttackReady() && me->IsWithinMeleeRange(me->GetVictim()))
                    {
                        DoCastVictim(SPELL_BLOOD_RAGE_DMG, true);
                        me->resetAttackTimer();
                    }
                }
                else
                {
                    DoMeleeAttackIfReady();
                }
            }

            void ExecuteEvent(const uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_BERSERK:
                        Talk(SAY_ZERK);
                        DoCastAOE(SPELL_ERADICATE);
                        break;
                    case EVENT_ARCING_SMASH_JUMP:
                        DoArcingSmashJump();
                        break;
                    case EVENT_IMPLODING_ENERGY:
                        DoImplodingEnergy();
                        break;
                    case EVENT_DISPLACED_ENERGY:
                        me->CastCustomSpell(SPELL_DISPLACED_ENERGY, SPELLVALUE_MAX_TARGETS, Is25ManRaid() ? 4 : 2, me, false);
                        events.ScheduleEvent(EVENT_DISPLACED_ENERGY, TIMER_DISPLACED_ENERGY);
                        break;
                    case EVENT_CLEAR_ARCING_SMASH:
                        summons.DespawnEntry(NPC_ARCING_SMASH);
                        break;
                    case EVENT_BLOOD_RAGE:
                        DoBloodRage();
                        break;
                }
            }

        private:

            void SetPhase(Phases phase) { m_Phase = phase; }
            bool IsMightOfTheKorkronPhase() const { return m_Phase == PHASE_MIGHT_OF_THE_KORKRON; }
            bool IsEndlessRagePhase() const { return m_Phase == PHASE_ENDLESS_RAGE; }

            void InitPowers()
            {
                me->AddAura(SPELL_ZERO_MANA_REGEN, me);

                me->SetPowerType(MALKOROK_POWER_TYPE);
                me->SetMaxPower(MALKOROK_POWER_TYPE, MALKOROK_POWER_MAX);
                me->SetPower(MALKOROK_POWER_TYPE, 0);
            }

            void SpawnMiasmas()
            {
                for (uint8 i = 0; i < 4; ++i)
                {
                    me->SummonCreature(NPC_ANCIENT_MIASMA, miasmasPos[i]);
                }
            }

            void ActivateMiasma(bool activate)
            {
                if (activate)
                {
                    DoCastAOE(SPELL_ANCIENT_MIASMA_AURA, true);
                    DoCastAOE(SPELL_ANCIENT_MIASMA_DMG, true);

                    m_CombatAuraHelper.RegisterCombatAura(Spells::SPELL_ANCIENT_MIASMA_AURA);
                    m_CombatAuraHelper.RegisterCombatAura(Spells::SPELL_ANCIENT_MIASMA_DMG);
                }
                else
                {
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ANCIENT_MIASMA_AURA);
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ANCIENT_MIASMA_DMG);

                    m_CombatAuraHelper.UnregisterCombatAura(Spells::SPELL_ANCIENT_MIASMA_AURA);
                    m_CombatAuraHelper.UnregisterCombatAura(Spells::SPELL_ANCIENT_MIASMA_DMG);
                }
            }

            void RemoveInstanceAuras()
            {
                ActivateMiasma(false);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ANCIENT_BARRIER);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_LANGUISH_DEBUFF);
            }

            bool CheckEvade(const uint32 diff)
            {
                if (checkEvadeTimer <= diff)
                {
                    checkEvadeTimer = TIMER_EVADE_CHECK;

                    if (me->GetExactDist(me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY(), me->GetHomePosition().GetPositionZ()) >= EVADE_DISTANCE)
                    {
                        EnterEvadeMode();
                        return true;
                    }
                }
                else
                {
                    checkEvadeTimer -= diff;
                }

                return false;
            }

            void DoSeismicSlam()
            {
                DoCastAOE(SPELL_SEISMIC_SLAM);
            }

            void DoArcingSmashJump()
            {
                if (me->GetDistance(centerPos) > 2.0f)
                {
                    DoCast(me, SPELL_ARCING_SMASH_JUMP);
                }
                else
                {
                    DoArcingSmash();
                }
            }

            void DoArcingSmash()
            {
                Talk(SAY_ARCING_SMASH);

                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true);
                if (!target)
                    return;

                if (Creature* pSmash = me->SummonCreature(NPC_ARCING_SMASH, centerPos))
                {
                    pSmash->SetReactState(REACT_PASSIVE);

                    pSmash->SetFacingToObject(target);
                    pSmash->SetOrientation(me->GetAngle(target));
                    pSmash->CastSpell(pSmash, SPELL_ARCING_SMASH_DMG);
                }

                me->SetFacingToObject(target);
                me->SetOrientation(me->GetAngle(target));

                // Reset attack flags to enable attacking after casting
                me->AttackStop();

                // There is a bug with the spell
                // it will be interrupted on moving
                me->GetMotionMaster()->Clear(false);
                me->GetMotionMaster()->MovementExpired(false);
                me->StopMoving();

                DoCast(me, SPELL_ARCING_SMASH_CHANNEL);

                events.ScheduleEvent(EVENT_IMPLODING_ENERGY, TIMER_IMPLODING_ENERGY);
            }

            void DoBreathOfYshaarj()
            {
                Talk(SAY_BREATH_OF_YSHAARJ);
                DoCastAOE(SPELL_BREATH_OF_YSHAARJ);

                events.ScheduleEvent(EVENT_CLEAR_ARCING_SMASH, 5000);
            }

            void GetImplodingEnergyPositions(std::list<Position>& positions)
            {
                positions.clear();

                uint8 count = Is25ManRaid() ? IMPLODING_ENERGY_COUNT_25PPL: IMPLODING_ENERGY_COUNT_10PPL;

                Position firstImplodingPosition;

                float firstAngle = frand(0.f, 2 * float(M_PI));
                float firstDist = frand(IMPLODING_ENERGY_MIN_DIST, IMPLODING_ENERGY_MAX_DIST);
                firstImplodingPosition.m_positionX = centerPos.GetPositionX() + firstDist * std::cos(firstAngle);
                firstImplodingPosition.m_positionY = centerPos.GetPositionY() + firstDist * std::sin(firstAngle);
                firstImplodingPosition.m_positionZ = centerPos.GetPositionZ() + 1.0f;
                firstImplodingPosition.SetOrientation(0.f);
                positions.push_back(firstImplodingPosition);

                float angleDiff = 2 * M_PI / (count + 1);

                for (uint8 i = 1; i < count; ++i)
                {
                    Position implodingPosition;

                    float angle = firstAngle + (angleDiff * i);
                    float dist = frand(IMPLODING_ENERGY_MIN_DIST, IMPLODING_ENERGY_MAX_DIST);
                    implodingPosition.m_positionX = centerPos.GetPositionX() + dist * std::cos(angle);
                    implodingPosition.m_positionY = centerPos.GetPositionY() + dist * std::sin(angle);
                    implodingPosition.m_positionZ = centerPos.GetPositionZ() + 1.0f;
                    implodingPosition.SetOrientation(0.f);

                    positions.push_back(implodingPosition);
                }
            }

            void DoImplodingEnergy()
            {
                std::list<Position> positions;

                GetImplodingEnergyPositions(positions);

                for (auto positionItr = positions.begin(); positionItr != positions.end(); ++positionItr)
                {
                    me->SummonCreature(NPC_IMPLOSION, *positionItr);
                }

                DoCastAOE(SPELL_IMPLODING_ENERGY);
            }

            void DoBloodRageDelayed()
            {
                events.ScheduleEvent(EVENT_BLOOD_RAGE, 1);
            }

            void DoBloodRage()
            {
                Talk(SAY_BLOOD_RAGE);

                //ToggleEssenseOfYshaarj(false);
                SetPhase(PHASE_ENDLESS_RAGE);

                events.CancelEvent(EVENT_ARCING_SMASH_JUMP);
                events.CancelEvent(EVENT_IMPLODING_ENERGY);

                m_EnergyRegenerator.Stop();

                me->RemoveAura(SPELL_FATAL_STRIKES);

                EntryCheckPredicate check(NPC_ANCIENT_MIASMA);
                summons.DoAction(ACTION_ENDLESS_RAGE, check);

                ActivateMiasma(false);

                events.ScheduleEvent(EVENT_DISPLACED_ENERGY, TIMER_DISPLACED_ENERGY_FIRST);

                DoCast(me, SPELL_BLOOD_RAGE);
            }

            bool DoExpelMiasma()
            {
                if (!IsEndlessRagePhase())
                    return false;

                if (me->GetPower(MALKOROK_POWER_TYPE) > 0)
                    return false;

                events.CancelEvent(EVENT_DISPLACED_ENERGY);

                SetPhase(PHASE_EXPEL_MIASMA);

                DoCastAOE(SPELL_ANCIENT_MIASMA_DUMMY_6, true);
                DoCast(SPELL_EXPEL_MIASMA);

                return true;
            }

            void DoMightOfTheKorkron()
            {
                //ToggleEssenseOfYshaarj(true);
                SetPhase(PHASE_MIGHT_OF_THE_KORKRON);

                me->RemoveAura(SPELL_BLOOD_RAGE);
                me->AddAura(SPELL_FATAL_STRIKES, me);
                me->AddAura(SPELL_RELENTLESS_ASSAULT, me);

                m_EnergyRegenerator.Reset();
                m_EnergyRegenerator.Activate();

                ActivateMiasma(true);
            }

            void ToggleEssenseOfYshaarj(bool activate)
            {
                if (!IsHeroic())
                    return;

                if (activate)
                    DoCast(me, SPELL_ESSENSE_OF_YSHAARJ_SELF, true);
                else
                    me->RemoveAura(SPELL_ESSENSE_OF_YSHAARJ_SELF);
            }

        private:

            EnergyRegenerator m_EnergyRegenerator;
            Phases m_Phase;
            uint32 checkEvadeTimer;
            CombatAuraHelper m_CombatAuraHelper;
        };
};

class npc_malkorok_ancient_miasma : public CreatureScript
{
public:
    npc_malkorok_ancient_miasma() : CreatureScript("npc_malkorok_ancient_miasma") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_malkorok_ancient_miasmaAI(creature);
    }

    struct npc_malkorok_ancient_miasmaAI : public Scripted_NoMovementAI
    {
        npc_malkorok_ancient_miasmaAI(Creature* creature) : Scripted_NoMovementAI(creature)
        {
            me->SetUnitFlags(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC));
            me->SetReactState(REACT_PASSIVE);
        }

        void Reset() override
        {
            if (IsCenterMiasma())
            {
                me->AddAura(SPELL_ANCIENT_MIASMA_DUMMY_1, me);
            }
        }

        void DamageTaken(Unit* who, uint32& damage) override
        {
            // UNIT_FLAG_NON_ATTACKABLE is removed because delayed spells cannot hit npc with this flag
            // So protect npc from any damage
            damage = 0;
        }

        void DoAction(const int32 action) override
        {
            if (action == ACTION_ENDLESS_RAGE)
            {
                if (IsCenterMiasma())
                {
                    me->RemoveAura(SPELL_ANCIENT_MIASMA_DUMMY_1);
                }
                else
                {
                    DoCast(me, SPELL_ANCIENT_MIASMA_DUMMY_4, true);
                    DoCast(me, SPELL_ANCIENT_MIASMA_DUMMY_2);
                }
            }
            else if (action == ACTION_EXPEL_MIASMA)
            {
                if (IsCenterMiasma())
                {
                    me->AddAura(SPELL_ANCIENT_MIASMA_DUMMY_1, me);
                }
                else
                {
                    DoCast(me, SPELL_ANCIENT_MIASMA_DUMMY_5);
                }
            }
        }

    private:

        bool IsCenterMiasma() const
        {
            return me->GetDistance(miasmasPos[0]) <= 2.0f;
        }

    };
};

class npc_malkorok_arcing_smash : public CreatureScript
{
    public:
        npc_malkorok_arcing_smash() : CreatureScript("npc_malkorok_arcing_smash") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_malkorok_arcing_smashAI(creature);
        }

        struct npc_malkorok_arcing_smashAI : public Scripted_NoMovementAI
        {
            npc_malkorok_arcing_smashAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC));
                me->SetReactState(REACT_PASSIVE);
            }
        };
};

class npc_malkorok_implosion : public CreatureScript
{
    public:
        npc_malkorok_implosion() : CreatureScript("npc_malkorok_implosion") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_malkorok_implosionAI(creature);
        }

        struct npc_malkorok_implosionAI : public Scripted_NoMovementAI
        {
            npc_malkorok_implosionAI(Creature* creature) : Scripted_NoMovementAI(creature),
                m_UpdateTimer(4000), m_IsExploded(false)
            {
                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC));
                me->SetReactState(REACT_PASSIVE);
            }

            void Reset() override
            {
                me->AddAura(SPELL_IMPLODING_ENERGY_AURA, me);

                m_UpdateTimer = 4000;
                m_IsExploded = false;
            }

            void DoAction(const int32 action) override
            {
                if (action == ACTION_IMPLOSION_DAMAGE)
                {
                    DoCastAOE(SPELL_IMPLODING_ENERGY_DMG_2, true);
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (m_IsExploded)
                    return;

                if (m_UpdateTimer <= diff)
                {
                    m_IsExploded = true;

                    DoCastAOE(SPELL_IMPLODING_ENERGY_DMG);

                    me->DespawnOrUnsummon(1000);
                }
                else
                {
                    m_UpdateTimer -= diff;
                }
            }

        private:

            uint32 m_UpdateTimer;
            bool m_IsExploded;

        };
};

class npc_malkorok_living_corruption : public CreatureScript
{
    public:
        npc_malkorok_living_corruption() : CreatureScript("npc_malkorok_living_corruption") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_malkorok_living_corruptionAI(creature);
        }

        struct npc_malkorok_living_corruptionAI : public ScriptedAI
        {
            npc_malkorok_living_corruptionAI(Creature* creature) : ScriptedAI(creature),
                m_MoveTimer(2000), m_IsMoving(false), m_UpdateTargetsTimer(1000)
            {
                me->SetReactState(REACT_PASSIVE);
            }

            void Reset() override
            {
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                UpdateMoving(diff);

                UpdateTargets(diff);

                DoMeleeAttackIfReady();
            }

        private:

            void UpdateMoving(const uint32 diff)
            {
                if (m_IsMoving)
                    return;

                if (m_MoveTimer <= diff)
                {
                    BeginMoving();
                }
                else
                {
                    m_MoveTimer -= diff;
                }
            }

            void BeginMoving()
            {
                if (m_IsMoving)
                    return;

                m_IsMoving = true;

                me->AddAura(SPELL_LANGUISH_AURA, me);

                me->SetReactState(REACT_AGGRESSIVE);
            }

            void UpdateTargets(const uint32 diff)
            {
                if (!m_IsMoving)
                    return;

                if (m_UpdateTargetsTimer <= diff)
                {
                    m_UpdateTargetsTimer = 1000;

                    ApplySpellToPlayersInRange(me, SPELL_LANGUISH_DEBUFF, LANGUISH_RANGE, true);
                }
                else
                {
                    m_UpdateTargetsTimer -= diff;
                }
            }

        private:

            uint32 m_MoveTimer;
            bool m_IsMoving;
            uint32 m_UpdateTargetsTimer;

        };
};

class spell_malkorok_seismic_slam : public SpellScriptLoader
{
    public:
        spell_malkorok_seismic_slam() : SpellScriptLoader("spell_malkorok_seismic_slam") { }

        class spell_malkorok_seismic_slam_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_malkorok_seismic_slam_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                if (Creature* pCreature = GetCaster()->ToCreature())
                {
                    Unit* target = NULL;
                    target = pCreature->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0, -15.0f, true);
                    if (!target)
                        target = pCreature->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true);

                    if (target)
                    {
                        targets.clear();
                        targets.push_back(target);
                    }
                }
            }

            void HandleHitTarget(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetCaster()->CastSpell(GetHitUnit(), SPELL_SEISMIC_SLAM_DMG, true);

                if (GetCaster()->GetMap()->IsHeroic())
                {
                    GetCaster()->CastSpell(GetHitUnit(), SPELL_SEISMIC_SLAM_SUMMON, true);
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_malkorok_seismic_slam_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_malkorok_seismic_slam_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_malkorok_seismic_slam_SpellScript();
        }
};

class EntryCheck
{
    public:

        EntryCheck(uint32 entry) : m_Entry(entry) { }

        bool operator()(WorldObject* object) const
        {
            if (object->GetEntry() == m_Entry)
                return false;

            return true;
        }

    private:

        uint32 m_Entry;
};

class spell_malkorok_breath_of_yshaarj : public SpellScriptLoader
{
    public:
        spell_malkorok_breath_of_yshaarj() : SpellScriptLoader("spell_malkorok_breath_of_yshaarj") { }

        class spell_malkorok_breath_of_yshaarj_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_malkorok_breath_of_yshaarj_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                EntryCheck entryCheck(NPC_ARCING_SMASH);
                targets.remove_if(entryCheck);
            }

            void HandleHitTarget(SpellEffIndex /*effIndex*/)
            {
                if (!GetHitUnit())
                    return;

                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_BREATH_OF_YSHAARJ_DMG, true);
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_malkorok_breath_of_yshaarj_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnEffectHitTarget += SpellEffectFn(spell_malkorok_breath_of_yshaarj_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_malkorok_breath_of_yshaarj_SpellScript();
        }
};

class spell_malkorok_imploding_energy_dmg : public SpellScriptLoader
{
    public:
        spell_malkorok_imploding_energy_dmg() : SpellScriptLoader("spell_malkorok_imploding_energy_dmg") { }

        class spell_malkorok_imploding_energy_dmg_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_malkorok_imploding_energy_dmg_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                if (targets.empty())
                {
                    if (Creature* pCreature = GetCaster()->ToCreature())
                    {
                        pCreature->AI()->DoAction(ACTION_IMPLOSION_DAMAGE);
                    }
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_malkorok_imploding_energy_dmg_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_malkorok_imploding_energy_dmg_SpellScript();
        }
};

class spell_malkorok_ancient_miasma_6 : public SpellScriptLoader
{
    public:
        spell_malkorok_ancient_miasma_6() : SpellScriptLoader("spell_malkorok_ancient_miasma_6") { }

        class spell_malkorok_ancient_miasma_6_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_malkorok_ancient_miasma_6_SpellScript);

            void HandleHitTarget(SpellEffIndex /*effIndex*/)
            {
                if (!GetHitUnit())
                    return;

                if (Creature* pMiasma = GetHitUnit()->ToCreature())
                {
                    pMiasma->AI()->DoAction(ACTION_EXPEL_MIASMA);
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_malkorok_ancient_miasma_6_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_malkorok_ancient_miasma_6_SpellScript();
        }
};

class spell_malkorok_expel_miasma : public SpellScriptLoader
{
    public:
        spell_malkorok_expel_miasma() : SpellScriptLoader("spell_malkorok_expel_miasma") { }

        class spell_malkorok_expel_miasma_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_malkorok_expel_miasma_SpellScript);

            void HandleHitTarget(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster())
                    return;

                if (Creature* pCreature = GetCaster()->ToCreature())
                {
                    pCreature->AI()->DoAction(ACTION_ENERGY_EMPTY);
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_malkorok_expel_miasma_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_malkorok_expel_miasma_SpellScript();
        }
};

class spell_malkorok_ancient_miasma_heal_absorb : public SpellScriptLoader
{
    public:
        spell_malkorok_ancient_miasma_heal_absorb() : SpellScriptLoader("spell_malkorok_ancient_miasma_heal_absorb") { }

        class spell_malkorok_ancient_miasma_heal_absorb_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_malkorok_ancient_miasma_heal_absorb_AuraScript);

            //bool CalculateAmount(AuraEffect const* /*auraEffect*/, int32& amount, bool& /*canBeRecalculated*/)
            void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
            {
                amount = -1;
            }

            //void HandleAbsorb(AuraEffect* aurEff, int32& remainingHeal, uint32& absorbAmount)
            void HandleOnAbsorb(AuraEffect* aurEff, DamageInfo& dinfo, uint32& absorbAmount)
            {
                //todo check this
                absorbAmount = aurEff->CalculateAmount(GetCaster());

                if (!GetUnitOwner())
                    return;


                if (AuraEffect* aurEffect = GetUnitOwner()->GetAuraEffect(SPELL_ANCIENT_BARRIER, EFFECT_0))
                {
                    uint32 oldAmount = aurEffect->GetAmount();
                    //uint32 newAmount = std::min(GetUnitOwner()->GetMaxHealth(), oldAmount + absorbAmount);
                    uint32 newAmount;
                    if (GetUnitOwner()->GetMaxHealth() < oldAmount + absorbAmount)
                        newAmount = GetUnitOwner()->GetMaxHealth();
                    else if (oldAmount + absorbAmount < GetUnitOwner()->GetMaxHealth())
                        newAmount = oldAmount + absorbAmount;

                    if (oldAmount != newAmount)
                    {
                        aurEffect->SetAmount(newAmount);
                    }
                }
                else
                {
                    //int32 basePoints = std::min(GetUnitOwner()->GetMaxHealth(), absorbAmount);
                    int32 basePoints;
                    if (GetUnitOwner()->GetMaxHealth() < absorbAmount)
                        basePoints = GetUnitOwner()->GetMaxHealth();
                    else if (absorbAmount < GetUnitOwner()->GetMaxHealth())
                        basePoints = absorbAmount;

                    GetUnitOwner()->CastCustomSpell(GetUnitOwner(), SPELL_ANCIENT_BARRIER, &basePoints, NULL, NULL, true);
                }
            }

            void Register()
            {
                //DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_malkorok_ancient_miasma_heal_absorb_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_HEAL_ABSORB);
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_malkorok_ancient_miasma_heal_absorb_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_HEAL_ABSORB);
                //OnEffectAbsorbHeal += AuraEffectAbsorbHealFn(spell_malkorok_ancient_miasma_heal_absorb_AuraScript::HandleAbsorb, EFFECT_0);
                AfterEffectAbsorb += AuraEffectAbsorbFn(spell_malkorok_ancient_miasma_heal_absorb_AuraScript::HandleOnAbsorb, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_malkorok_ancient_miasma_heal_absorb_AuraScript();
        }
};

class spell_malkorok_ancient_barrier : public SpellScriptLoader
{
    public:
        spell_malkorok_ancient_barrier() : SpellScriptLoader("spell_malkorok_ancient_barrier") { }

        class spell_malkorok_ancient_barrier_AuraScript : public AuraScript
        {

        public:

            spell_malkorok_ancient_barrier_AuraScript() :
                m_CurrentVisualSpell(0), m_CurrentBarrierAmount(0)
            {

            }

        private:

            PrepareAuraScript(spell_malkorok_ancient_barrier_AuraScript);

            void HandlePeriodic(AuraEffect const* /*aurEff*/)
            {
                if (!GetUnitOwner())
                    return;

                uint32 maxBarrierAmount = GetUnitOwner()->GetMaxHealth();
                if (maxBarrierAmount == 0)
                    return;

                uint32 newBarrierAmount = GetAura()->GetEffect(EFFECT_0)->GetAmount();

                float barrierPct = (100.0f * newBarrierAmount) / maxBarrierAmount;
                uint32 newVisualSpellId = GetVisualSpellForAmount(barrierPct);

                if (m_CurrentVisualSpell != newVisualSpellId)
                {
                    if (m_CurrentVisualSpell)
                        GetUnitOwner()->RemoveAura(m_CurrentVisualSpell);

                    GetUnitOwner()->AddAura(newVisualSpellId, GetUnitOwner());

                    m_CurrentVisualSpell = newVisualSpellId;
                }

                if (m_CurrentBarrierAmount != newBarrierAmount)
                {
                    m_CurrentBarrierAmount = newBarrierAmount;

                    if (AuraEffect* aurEff = GetUnitOwner()->GetAuraEffect(m_CurrentVisualSpell, EFFECT_0))
                    {
                        aurEff->SetAmount(m_CurrentBarrierAmount);
                    }
                }
            }

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetUnitOwner())
                    return;

                GetUnitOwner()->RemoveAura(m_CurrentVisualSpell);
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_malkorok_ancient_barrier_AuraScript::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
                AfterEffectRemove += AuraEffectRemoveFn(spell_malkorok_ancient_barrier_AuraScript::HandleRemove, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }

        private:

            uint32 GetVisualSpellForAmount(const float barrierPct) const
            {
                uint32 spellId = 0;

                if (barrierPct >= 90.f)
                {
                    spellId = SPELL_STRONG_ANCIENT_BARRIER;
                }
                else if (barrierPct >= 20.0f)
                {
                    spellId = SPELL_MIDDLE_ANCIENT_BARRIER;
                }
                else
                {
                    spellId = SPELL_WEAK_ANCIENT_BARRIER;
                }

                return spellId;
            }

        private:

            uint32 m_CurrentVisualSpell;
            uint32 m_CurrentBarrierAmount;

        };

        AuraScript* GetAuraScript() const
        {
            return new spell_malkorok_ancient_barrier_AuraScript();
        }
};

struct DisplacedEnergyTargetSelector : public std::unary_function<Unit*, bool>
{
    const Unit* me;

    DisplacedEnergyTargetSelector(Unit const* unit) : me(unit) {}

    bool operator()(Unit const* target) const
    {
        if (!target)
            return false;

        if (!target->IsPlayer())
            return false;

        if (me->GetVictim() && me->GetVictim()->GetGUID() == target->GetGUID())
            return false;

        return true;
    }
};

class spell_malkorok_displaced_energy : public SpellScriptLoader
{
    public:
        spell_malkorok_displaced_energy() : SpellScriptLoader("spell_malkorok_displaced_energy") { }

        class spell_malkorok_displaced_energy_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_malkorok_displaced_energy_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                // Recalculate targets
                targets.clear();

                if (!GetCaster())
                    return;

                if (Creature* pCreature = GetCaster()->ToCreature())
                {
                    uint8 targetsCount = pCreature->GetMap()->Is25ManRaid() ? 4 : 2;
                    std::list<Unit*> newTargets;
                    pCreature->AI()->SelectTargetList(newTargets, DisplacedEnergyTargetSelector(pCreature), targetsCount, SELECT_TARGET_RANDOM);

                    for (auto target : newTargets)
                        targets.push_back(target);

                    if (targets.size() > targetsCount)
                        Trinity::Containers::RandomResize(targets, targetsCount);
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_malkorok_displaced_energy_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_malkorok_displaced_energy_SpellScript::FilterTargets, EFFECT_2, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_malkorok_displaced_energy_SpellScript();
        }

        class spell_malkorok_displaced_energy_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_malkorok_displaced_energy_AuraScript);

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetCaster() || !GetUnitOwner())
                    return;

                GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_DISPLACED_ENERGY_DMG, true, NULL, NULL, GetCaster()->GetGUID());
            }

            void Register()
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_malkorok_displaced_energy_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            }

        };

        AuraScript* GetAuraScript() const
        {
            return new spell_malkorok_displaced_energy_AuraScript();
        }
};

class spell_malkorok_essense_of_yshaarj : public SpellScriptLoader
{
    public:
        spell_malkorok_essense_of_yshaarj() : SpellScriptLoader("spell_malkorok_essense_of_yshaarj") { }

        class spell_malkorok_essense_of_yshaarj_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_malkorok_essense_of_yshaarj_AuraScript);

            void HandlePeriodic(AuraEffect const* /*aurEff*/)
            {
                if (!GetUnitOwner())
                    return;

                PreventDefaultAction();

                uint8 count = GetUnitOwner()->GetMap()->Is25ManRaid() ? ESSENSE_OF_YSHAARJ_COUNT_25 : ESSENSE_OF_YSHAARJ_COUNT_10;

                // one of essenses is spawned in the first effect (EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL), we use second effect to create additional essenses.
                --count;

                for (uint8 i = 0; i < count; ++i)
                {
                    GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_ESSENSE_OF_YSHAARJ_DUMMY, true);
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_malkorok_essense_of_yshaarj_AuraScript::HandlePeriodic, EFFECT_2, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_malkorok_essense_of_yshaarj_AuraScript();
        }
};

class spell_malkorok_essense_of_yshaarj_dummy : public SpellScriptLoader
{
    public:
        spell_malkorok_essense_of_yshaarj_dummy() : SpellScriptLoader("spell_malkorok_essense_of_yshaarj_dummy") { }

        class spell_malkorok_essense_of_yshaarj_dummy_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_malkorok_essense_of_yshaarj_dummy_SpellScript);

            void HandleLaunch(SpellEffIndex /*effIndex*/)
            {
                float minRange = 14.f;
                float maxRange = 40.f;

                float x, y, z;
                float angle = frand(0.f, float(M_PI) * 2);
                float dist = frand(minRange, maxRange);

                x = centerPos.m_positionX + dist * std::cos(angle);
                y = centerPos.m_positionY + dist * std::sin(angle);
                z = centerPos.m_positionZ;

                WorldLocation summonPos = *GetExplTargetDest();
                summonPos.Relocate(x, y, z);
                SetExplTargetDest(summonPos);

                WorldLocation* dest = GetHitDest();
                if (dest)
                {
                    dest->Relocate(summonPos);
                }
            }

            void HandleHit(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster())
                    return;

                WorldLocation summonPos = *GetExplTargetDest();

                GetCaster()->CastSpell(summonPos.GetPositionX(), summonPos.GetPositionY(), summonPos.GetPositionZ(), SPELL_ESSENSE_OF_YSHAARJ_AREATRIGGER, true);
            }

            void Register()
            {
                OnEffectLaunch += SpellEffectFn(spell_malkorok_essense_of_yshaarj_dummy_SpellScript::HandleLaunch, EFFECT_0, SPELL_EFFECT_DUMMY);
                OnEffectHit += SpellEffectFn(spell_malkorok_essense_of_yshaarj_dummy_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_malkorok_essense_of_yshaarj_dummy_SpellScript();
        }
};

class spell_malkorok_essense_of_yshaarj_dmg : public SpellScriptLoader
{
    public:
        spell_malkorok_essense_of_yshaarj_dmg() : SpellScriptLoader("spell_malkorok_essense_of_yshaarj_dmg") { }

        class spell_malkorok_essense_of_yshaarj_dmg_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_malkorok_essense_of_yshaarj_dmg_SpellScript);

            void DoBeforeHit(SpellMissInfo /*missInfo*/)
            {
                if (!GetHitUnit())
                    return;

                GetHitUnit()->RemoveAura(SPELL_ANCIENT_BARRIER);
            }

            void Register()
            {
                //BeforeHit += SpellHitFn(spell_malkorok_essense_of_yshaarj_dmg_SpellScript::HandleBeforeHit);
                BeforeHit += BeforeSpellHitFn(spell_malkorok_essense_of_yshaarj_dmg_SpellScript::DoBeforeHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_malkorok_essense_of_yshaarj_dmg_SpellScript();
        }
};

// todo readd this
/*class spell_malkorok_languish : public SpellScriptLoader
{
    public:
        spell_malkorok_languish() : SpellScriptLoader("spell_malkorok_languish") { }

        class spell_malkorok_languish_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_malkorok_languish_AuraScript);

            void OnUpdate(uint32 diff)
            {
                if (!GetUnitOwner())
                    return;

                if (!GetCaster() || !GetCaster()->IsAlive())
                {
                    Remove();
                    return;
                }

                if (m_UpdateTimer <= diff)
                {
                    m_UpdateTimer = 1000;

                    if (GetCaster()->GetExactDist(GetUnitOwner()) > LANGUISH_RANGE)
                    {
                        Remove();
                    }
                }
                else
                {
                    m_UpdateTimer -= diff;
                }
            }

            void Register()
            {
                OnEffectUpdate += AuraEffectUpdateFn(spell_malkorok_languish_AuraScript::OnUpdate, EFFECT_0, SPELL_AURA_MOD_DECREASE_SPEED);
            }

        private:

            uint32 m_UpdateTimer = 1000;
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_malkorok_languish_AuraScript();
        }
};*/

struct spell_area_malkorok_essense_of_yshaarj : AreaTriggerAI
{
    spell_area_malkorok_essense_of_yshaarj(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* target)
    {
        Unit* caster = at->GetCaster();
        if (!caster || !target)
            return;

        // Correct the distance, because it can be not exact distance for 'AddTarget'
        float distance = at->GetExactDist2d(target);
        if (distance > 1.f)
            return;

        if (at->GetDuration() != 0)
        {
            caster->CastSpell(target, SPELL_ESSENSE_OF_YSHAARJ_DMG, true);
            caster->CastSpell(at->GetPositionX(), at->GetPositionY(), at->GetPositionZ(), SPELL_ESSENSE_OF_YSHAARJ_EXPLODE, true);
            at->SetDuration(0);
        }
    }

    void OnUpdate(uint32 /*diff*/)
    {
        // HACK:
        // Spell 143848 has low speed, so triggers can be spawned after malkorok's reset.
        // Despawn trigger
        if (at->GetDuration() == 0)
            return;

        if (InstanceScript* pInstance = at->GetInstanceScript())
        {
            if (pInstance->GetBossState(DATA_MALKOROK) != IN_PROGRESS)
            {
                at->SetDuration(0);
            }
        }
    }
};

void AddSC_boss_malkorok()
{
    new boss_malkorok();                                // 71454
    new npc_malkorok_ancient_miasma();                  // 71513
    new npc_malkorok_arcing_smash();                    // 71455
    new npc_malkorok_implosion();                       // 71470
    new npc_malkorok_living_corruption();               // 71644

    new spell_malkorok_seismic_slam();                  // 142851
    new spell_malkorok_breath_of_yshaarj();             // 142842
    new spell_malkorok_imploding_energy_dmg();          // 142986
    new spell_malkorok_ancient_miasma_6();              // 149443
    new spell_malkorok_expel_miasma();                  // 143199
    new spell_malkorok_ancient_miasma_heal_absorb();    // 142861
    new spell_malkorok_ancient_barrier();               // 142862
    new spell_malkorok_displaced_energy();              // 142913
    new spell_malkorok_essense_of_yshaarj();            // 143846
    new spell_malkorok_essense_of_yshaarj_dummy();      // 143848
    new spell_malkorok_essense_of_yshaarj_dmg();        // 143857
    //new spell_malkorok_languish();                      // 143919

    RegisterAreaTriggerAI(spell_area_malkorok_essense_of_yshaarj);       // 143850
}
