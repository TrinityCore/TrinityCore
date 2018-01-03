#include "ScriptMgr.h"
#include "blackwing_descent.h"
#include "Vehicle.h"
#include "Unit.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CombatAI.h"
#include "PassiveAI.h"
#include "ObjectMgr.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "Vehicle.h"
#include "VehicleDefines.h"
#include "Spell.h"
#include "Player.h"
#include "Map.h"
#include "InstanceScript.h"

enum Spells
{
    // General
    SPELL_BERSERK                   = 64238,
    SPELL_RELEASE_ABBERATIONS       = 77569,
    SPELL_RELEASE_ALL_ABBERATIONS   = 77991,
    SPELL_REMEDY                    = 77912,
    SPELL_ARCANE_STORM              = 77896,

    // Red Phase
    SPELL_THROW_RED_BOTTLE          = 77925,
    SPELL_DRINK_RED                 = 88699,
    SPELL_SCORCHING_BLAST           = 77679,
    SPELL_CONSUMING_FLAMES          = 77786,

    // Blue Phase
    SPELL_THROW_BLUE_BOTTLE         = 77932,
    SPELL_DRINK_BLUE                = 88700,
    SPELL_BITING_CHILL              = 77760,

    SPELL_FLASH_FREEZE              = 77699,
    SPELL_FLASH_FREEZE_SUMMON       = 77711,
    SPELL_FLASH_FREEZE_VISUAL       = 77712,

    // Green Phase
    SPELL_THROW_GREEN_BOTTLE        = 77937,
    SPELL_DRINK_GREEN               = 77938,
    SPELL_DEBILITATING_SLIME        = 77602, // Cauldron spray visual after throw.
    SPELL_DEBILITATING_SLIME_DEBUFF = 92910,

    // Black Phase
    SPELL_THROW_BLACK_BOTTLE        = 92831,
    SPELL_DRINK_BLACK               = 92828,
    SPELL_SHADOW_IMBUED             = 92716,

    SPELL_ENGULFING_DARKNESS        = 92754,

    // Final Phase
    SPELL_DRINK_ALL_BOTTLES         = 95662,
    SPELL_ACID_NOVA                 = 78225,
    SPELL_MAGMA_JET                 = 78194, // summons the controller
    SPELL_MAGMA_JET_SUMMON          = 78094,
    SPELL_ABSOLUTE_ZERO             = 78223,
    SPELL_ABSOLUTE_ZERO_DMG         = 93041,
    SPELL_ABSOLUTE_ZERO_TRANSFORM   = 78201
};

enum Events
{
    // General
    EVENT_NEW_PHASE = 1,
    EVENT_DRINK_BOTTLE,
    EVENT_UNLOCK_SPELLS,
    EVENT_WAIT_SWITCH_PHASE,
    EVENT_BERSERK,
    EVENT_REMEDY,
    EVENT_ARCANE_STORM,

    // Red Phase
    EVENT_SCORCHING_BLAST,
    EVENT_CONSUMING_FLAMES,

    // Blue Phase
    EVENT_BITING_CHILL,
    EVENT_FLASH_FREEZE,

    // Green Phase
    EVENT_CAULDRON_EXPLODE,
    EVENT_RELEASE_ABBERATIONS,

    // Black Phase
    EVENT_SUMMON_VILE_SWILL,
    EVENT_ENGULFING_DARKNESS,

    // Final Phase
    EVENT_ACID_NOVA,
    EVENT_DRINK_ALL,
    EVENT_MAGMA_JETS,
    EVENT_ABSOLUTE_ZERO,

    EVENT_LOW_HEALTH,
    EVENT_BEFORE_SUBJECTS,

    EVENT_TALK_ME,
    EVENT_TALK_NEFARIAN,

    EVENT_ZERO_TRANSFORM,
    EVENT_ZERO_MOVE
};

enum ScriptTexts
{
    SAY_AGGRO                       = 1,
    SAY_RED                         = 6,
    SAY_BLUE                        = 9,
    SAY_GREEN                       = 7,
    SAY_LOW_HEALTH                  = 8,
    SAY_SLAY                        = 3, // 0 & 1
    SAY_DEATH                       = 4,
    SAY_BEFORE_SUBJECTS             = 5,
    SAY_SUBJECTS                    = 16,

    // Announces
    SAY_RED_V                       = 10,
    SAY_BLUE_V                      = 11,
    SAY_GREEN_V                     = 12,
    SAY_PRIME                       = 13,
    SAY_ABBER                       = 14,
    SAY_SPERE                       = 15
};

Position const MaloriakPositions[5] =
{
    {-106.148842f, -473.517365f, 73.454552f, 4.699424f}, // Cauldron Position
    {-75.459419f, -430.066071f, 73.274872f, 3.609182f}, // Add summon Positions
    {-77.055763f, -441.063354f, 73.489388f, 3.285442f},
    {-75.247200f, -499.593018f, 73.240547f, 2.064154f},
    {-143.885178f, -457.006409f, 73.369576f, 0.112437f}
};

enum Phases
{
    PHASE_NON = 1,
    PHASE_RED,
    PHASE_BLUE,
    PHASE_GREEN,
    PHASE_BLACK,
    PHASE_FINAL,
};

#define TIMER_PHASE 45000

class boss_maloriak : public CreatureScript
{
public:
    boss_maloriak() : CreatureScript("boss_maloriak") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_maloriakAI (creature);
    }

    struct boss_maloriakAI : public BossAI
    {
        boss_maloriakAI(Creature* creature) : BossAI(creature, DATA_MALORIAK)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        uint8 phase;
        uint32 abberationsLeft;
        uint8 lastPhase;
        bool spellsLocked;
        bool wasInBlackPhase;
        bool final;
        bool say;
        uint8 withoutGreenPhase;

        void Reset() override
        {
            events.Reset();

            if (instance)
                instance->SetBossState(DATA_MALORIAK, NOT_STARTED);

            if (Creature* nefarianHelperheroic = me->FindNearestCreature(NPC_NEFARIAN_HELPER_HEROIC, 150.0f, true))
                nefarianHelperheroic->DespawnOrUnsummon(100);

            me->SetReactState(REACT_AGGRESSIVE);
            abberationsLeft = 18;
            withoutGreenPhase = 0;
            wasInBlackPhase = true;
            spellsLocked = false;
            say = false;
            UpdatePhase(PHASE_NON);
            DespawnMinions();
            final = false;

            _Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();

            if (instance)
            {
                instance->SetBossState(DATA_MALORIAK, IN_PROGRESS);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me); // Add
            }

            if(me->GetMap()->IsHeroic())
            {
                events.ScheduleEvent(EVENT_TALK_NEFARIAN, 500);
                events.ScheduleEvent(EVENT_TALK_ME, 11500);
                me->SummonCreature(NPC_NEFARIAN_HELPER_HEROIC,-130.073f, -467.043f, 73.353f, 1.01f ,TEMPSUMMON_MANUAL_DESPAWN);
            }
            else
            events.ScheduleEvent(EVENT_TALK_ME, 500);

            events.ScheduleEvent(EVENT_NEW_PHASE, urand(20000,22000));
            events.ScheduleEvent(EVENT_REMEDY, urand(25000,28000));
            events.ScheduleEvent(EVENT_ARCANE_STORM, urand(15000,16000));

            events.ScheduleEvent(EVENT_BERSERK, me->GetMap()->IsHeroic() ? 720000 : 420000);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            if(me->GetHealthPct() < 25 && phase != PHASE_FINAL && final == false)
            {   // Enter Final Phase
                uint32 uiBerserker = events.GetNextEventTime(EVENT_BERSERK);
                events.Reset();
                events.ScheduleEvent(EVENT_BERSERK, uiBerserker);
                events.ScheduleEvent(EVENT_DRINK_ALL, 100);
                events.ScheduleEvent(EVENT_ACID_NOVA, urand(6000, 10000));
                events.ScheduleEvent(EVENT_MAGMA_JETS, urand(12000, 15000));
                events.ScheduleEvent(EVENT_ABSOLUTE_ZERO, urand(16000, 20000));

                phase = PHASE_FINAL;
                final = true;
                me->InterruptNonMeleeSpells(true);

                DoCast(SPELL_RELEASE_ALL_ABBERATIONS);
                if(abberationsLeft > 0)
                    for (uint8 i = 0; i < abberationsLeft; i++)
                        me->SummonCreature(NPC_ABBERATON, MaloriakPositions[urand(1,4)]);

                Talk(SAY_LOW_HEALTH);
                Talk(SAY_PRIME);
                events.ScheduleEvent(EVENT_LOW_HEALTH, 6000);
            };

            if(me->GetHealthPct() < 30 && say == false)
            {
               Talk(SAY_BEFORE_SUBJECTS);
               say = true;
            }

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                // General and Phase Switching
                case EVENT_NEW_PHASE:
                    UpdatePhase(urand(PHASE_RED, PHASE_BLUE));
                    spellsLocked = true;
                    events.ScheduleEvent(EVENT_NEW_PHASE, TIMER_PHASE);
                    break;

                case EVENT_TALK_ME:
                    Talk(SAY_AGGRO);
                    return;

                case EVENT_TALK_NEFARIAN:
                    if (Creature* nefarianHelperheroic = me->FindNearestCreature(NPC_NEFARIAN_HELPER_HEROIC, 150.0f, true))
                    nefarianHelperheroic->AI()->Talk(14);
                    return;

                case EVENT_DRINK_BOTTLE:

                    if(Unit* cauldron = me->FindNearestCreature(38365, 100.f))
                    {
                        switch(phase)
                        {
                        case PHASE_RED:
                            DoCast(cauldron, SPELL_THROW_RED_BOTTLE);
                            DoCast(me, SPELL_DRINK_RED);
                            break;

                        case PHASE_BLUE:
                            DoCast(cauldron, SPELL_THROW_BLUE_BOTTLE);
                            DoCast(me, SPELL_DRINK_BLUE);
                            break;

                        case PHASE_GREEN:
                            DoCast(cauldron, SPELL_THROW_GREEN_BOTTLE);
                            DoCast(me, SPELL_DRINK_GREEN);
                            break;

                        case PHASE_BLACK:
                            DoCast(cauldron, SPELL_THROW_BLACK_BOTTLE);
                            DoCast(me, SPELL_DRINK_BLACK);
                            me->AddAura(SPELL_SHADOW_IMBUED, me);
                            break;
                        }
                    }

                    events.ScheduleEvent(EVENT_WAIT_SWITCH_PHASE, 1000);
                    break;

                case EVENT_WAIT_SWITCH_PHASE:
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->GetMotionMaster()->MoveChase(me->GetVictim());

                    // Intialize Phase Events
                    switch(phase)
                    {
                    case PHASE_RED:
                        Talk(SAY_RED);
                        Talk(SAY_RED_V);
                        events.ScheduleEvent(EVENT_SCORCHING_BLAST, 7000);
                        events.ScheduleEvent(EVENT_CONSUMING_FLAMES, 3000);
                        break;

                    case PHASE_BLUE:
                        Talk(SAY_BLUE);
                        Talk(SAY_BLUE_V);
                        events.ScheduleEvent(EVENT_BITING_CHILL, 7000);
                        events.ScheduleEvent(EVENT_FLASH_FREEZE, 9000);
                        break;

                    case PHASE_GREEN:
                        Talk(SAY_GREEN);
                        Talk(SAY_GREEN_V);
                        events.ScheduleEvent(EVENT_CAULDRON_EXPLODE, 2000);
                        break;

                    case PHASE_BLACK:
                        if (Creature* nefarianHelperheroic = me->FindNearestCreature(NPC_NEFARIAN_HELPER_HEROIC, 150.0f, true))
                        nefarianHelperheroic->AI()->Talk(15);
                        events.ScheduleEvent(EVENT_SUMMON_VILE_SWILL, urand(4000,6000));
                        events.ScheduleEvent(EVENT_ENGULFING_DARKNESS, 9000);
                        break;
                    }

                    if(phase != PHASE_BLACK && phase != PHASE_FINAL)
                        events.ScheduleEvent(EVENT_RELEASE_ABBERATIONS, urand(12000,17000));

                    events.ScheduleEvent(EVENT_UNLOCK_SPELLS, 1500);
                    break;

                    // Misc
                case EVENT_UNLOCK_SPELLS:
                    spellsLocked = false;
                    break;

                case EVENT_BERSERK:
                    DoCast(me,SPELL_BERSERK);
                    break;

                case EVENT_REMEDY:
                    if(spellsLocked)
                        events.ScheduleEvent(EVENT_REMEDY, 1500);
                    else
                    {
                        DoCast(me,SPELL_REMEDY);
                        events.ScheduleEvent(EVENT_REMEDY, urand(15000,18000));
                    }
                    break;

                case EVENT_ARCANE_STORM:
                    if(spellsLocked)
                        events.ScheduleEvent(EVENT_ARCANE_STORM, 1500);
                    else
                    {
                        me->AttackStop();
                        DoCastAOE(SPELL_ARCANE_STORM);
                        events.ScheduleEvent(EVENT_ARCANE_STORM, urand(27000,29000));
                    }
                    break;

                    // Red Phase
                case EVENT_SCORCHING_BLAST:
                    DoCastAOE(SPELL_SCORCHING_BLAST);
                    events.ScheduleEvent(EVENT_SCORCHING_BLAST, urand(15000, 17000));
                    break;

                case EVENT_CONSUMING_FLAMES:
                    if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 200, true))
                        DoCast(target, SPELL_CONSUMING_FLAMES);

                    events.ScheduleEvent(EVENT_CONSUMING_FLAMES, urand(7000, 8500));
                    break;

                    // Blue Phase
                case EVENT_BITING_CHILL:
                    if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 200, true))
                        DoCast(target, SPELL_BITING_CHILL);

                    events.ScheduleEvent(EVENT_BITING_CHILL, urand(8000, 10000));
                    break;

                case EVENT_FLASH_FREEZE:
                    if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 200, true))
                        target->CastSpell(target, SPELL_FLASH_FREEZE_SUMMON, true);

                    events.ScheduleEvent(EVENT_FLASH_FREEZE, urand(11000, 13000));
                    break;

                    // Green Phase
                case EVENT_CAULDRON_EXPLODE:
                    if(Creature* trigger = me->FindNearestCreature(38365, 100.0f))
                    trigger->CastSpell(trigger, SPELL_DEBILITATING_SLIME, true);
                    DoCastCausticSlime();
                    events.ScheduleEvent(EVENT_CAULDRON_EXPLODE, 15000);
                    break;

                case EVENT_RELEASE_ABBERATIONS:
                    Talk(SAY_ABBER);
                    DoCast(SPELL_RELEASE_ABBERATIONS);
                    SetAbberations(GetAbberations()-3);
                    break;

                    // Black Phase
                case EVENT_SUMMON_VILE_SWILL:
                    me->SummonCreature(NPC_VILE_SWILL, MaloriakPositions[urand(1,4)]);
                    events.ScheduleEvent(EVENT_SUMMON_VILE_SWILL, urand(4000,5000));
                    break;

                case EVENT_ENGULFING_DARKNESS:
                    DoCastAOE(SPELL_ENGULFING_DARKNESS);
                    events.ScheduleEvent(EVENT_ENGULFING_DARKNESS, 16000);
                    break;

                    // Final Phase
                case EVENT_DRINK_ALL:
                    DoCast(me, SPELL_DRINK_ALL_BOTTLES);
                    return;

                case EVENT_LOW_HEALTH:
                    Talk(SAY_SUBJECTS);
                    return;

                case EVENT_ACID_NOVA:
                    {
                    // All Players
                    Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
                    if (!PlayerList.isEmpty())
                    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    me->AddAura(SPELL_ACID_NOVA,  i->GetSource());
                    }
                    events.ScheduleEvent(EVENT_ACID_NOVA, urand(20000, 30000));
                    break;

                case EVENT_MAGMA_JETS:
                    DoCast(me, SPELL_MAGMA_JET);
                    events.ScheduleEvent(EVENT_MAGMA_JETS, urand(16000, 20000));
                    break;

                case EVENT_ABSOLUTE_ZERO:
                    Talk(SAY_SPERE);
                    if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 200, true))
                        DoCast(target, SPELL_ABSOLUTE_ZERO);
                    events.ScheduleEvent(EVENT_ABSOLUTE_ZERO, urand(10000, 12000));
                    break;

                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }

        void KilledUnit(Unit* /*who*/) override
        {
            Talk(SAY_SLAY-urand(0,1));
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            DespawnMinions();

            if (Creature* nefarianHelperheroic = me->FindNearestCreature(NPC_NEFARIAN_HELPER_HEROIC, 150.0f, true))
            {
                nefarianHelperheroic->AI()->Talk(16);
                nefarianHelperheroic->DespawnOrUnsummon(15000);
            }

            if (instance)
            {
                instance->SetBossState(DATA_MALORIAK, DONE);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove
            }

            _JustDied();
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            Reset();

            me->GetMotionMaster()->MoveTargetedHome();

            if (instance)
            {
                instance->SetBossState(DATA_MALORIAK, FAIL);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove
            }

            _EnterEvadeMode();
        }

        void JustSummoned(Creature* summon) override
        {
            summon->AI()->DoZoneInCombat();
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE || id != 1)
                return;

            if(GameObject* cauldron = me->FindNearestGameObject(GOB_MALORIAKS_CAULDRON,100.f))
            {
                cauldron->SendCustomAnim(phase);
                me->SetFacingToObject(cauldron);
            }

            events.ScheduleEvent(EVENT_DRINK_BOTTLE, 1500);
        }

        uint32 GetAbberations()
        {
            return abberationsLeft;
        }

        void SetAbberations(uint32 value)
        {
            abberationsLeft = value;
        }

    private:
        void UpdatePhase(uint8 newPhase)
        {
            // Cancel current Phase Events

            switch(phase)
            {
            case PHASE_RED:
                events.CancelEvent(EVENT_SCORCHING_BLAST);
                events.CancelEvent(EVENT_CONSUMING_FLAMES);
                break;

            case PHASE_BLUE:
                events.CancelEvent(EVENT_BITING_CHILL);
                events.CancelEvent(EVENT_FLASH_FREEZE);
                break;

            case PHASE_GREEN:
                events.CancelEvent(EVENT_CAULDRON_EXPLODE);
                break;

            case PHASE_BLACK:
                me->RemoveAura(SPELL_SHADOW_IMBUED);
                events.CancelEvent(EVENT_SUMMON_VILE_SWILL);
                events.CancelEvent(EVENT_ENGULFING_DARKNESS);
                break;
            }

            phase = newPhase;

            if(phase == PHASE_NON)
                return;

            // In Heroic Mode every 2. Phase is a Black Phase
            if((me->GetMap()->IsHeroic()) && (!wasInBlackPhase))
            {
                phase = PHASE_BLACK;
                wasInBlackPhase = true;
            } else
            {
                withoutGreenPhase++;
                wasInBlackPhase = false;

                if(lastPhase == phase )
                {
                    if(phase == PHASE_RED)
                        phase = PHASE_BLUE;
                    else if(phase == PHASE_BLUE)
                        phase = PHASE_RED;
                }

                lastPhase = phase;
            }

            // Every 3. Phase is a Green Phase
            if(withoutGreenPhase >= 3)
            {
                if(phase == PHASE_BLACK)
                    wasInBlackPhase = false;

                phase = PHASE_GREEN;
                withoutGreenPhase = 0;
            }

            me->SetReactState(REACT_PASSIVE);
            me->AttackStop();
            me->GetMotionMaster()->MovePoint(1, MaloriakPositions[0]);
        }

        inline void DespawnMinions()
        {
            DespawnCreatures(NPC_ABBERATON);
            DespawnCreatures(NPC_PRIME_SUBJECT);
            DespawnCreatures(NPC_FLASH_FREEZE);
            DespawnCreatures(NPC_VILE_SWILL);
            DespawnCreatures(NPC_MAGMA_JET_CONTROLLER);
            DespawnCreatures(NPC_ABSOLUTE_ZERO);
        }

        void DespawnCreatures(uint32 entry)
        {
            std::list<Creature*> creatures;
               GetCreatureListWithEntryInGrid(creatures, me, entry, 1000.0f);

            if (creatures.empty())
               return;

            for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                 (*iter)->DespawnOrUnsummon();
        }

        inline void DoCastCausticSlime()
        {
            // All Players
            Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
            if (!PlayerList.isEmpty())
                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    me->AddAura(SPELL_DEBILITATING_SLIME_DEBUFF,  i->GetSource());

            // Maloriak and all his Minions
            me->AddAura(SPELL_DEBILITATING_SLIME_DEBUFF, me);

            std::list<Creature*> creatures;

            // Abberations
            GetCreatureListWithEntryInGrid(creatures, me, NPC_ABBERATON, 50.0f);

            if (!creatures.empty())
                for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                    me->AddAura(SPELL_DEBILITATING_SLIME_DEBUFF,  (*iter));

            // Vile Swill (Hardmode)
            GetCreatureListWithEntryInGrid(creatures, me, NPC_VILE_SWILL, 50.0f);

            if (!creatures.empty())
                for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                    me->AddAura(SPELL_DEBILITATING_SLIME_DEBUFF,  (*iter));
        }
    };
};

class mob_flash_freeze_maloriak : public CreatureScript
{
public:
    mob_flash_freeze_maloriak() : CreatureScript("mob_flash_freeze_maloriak") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_flash_freeze_maloriakAI (creature);
    }

    struct mob_flash_freeze_maloriakAI : public ScriptedAI
    {
        mob_flash_freeze_maloriakAI(Creature* creature) : ScriptedAI(creature) { }

        Unit* target;
        uint32 timerChecktarget;

        void IsSummonedBy(Unit* summoner) override
        {
            target = summoner;
            timerChecktarget = 500;

            if(target)
                me->AddAura(SPELL_FLASH_FREEZE, target);

            me->AddAura(SPELL_FLASH_FREEZE_VISUAL, me);
        }

        void UpdateAI(uint32 diff) override
        {
            if (timerChecktarget <= diff)
            {
                // Check weather the Debuff on Target is Expired
                if(target && !target->HasAura(SPELL_FLASH_FREEZE))
                    me->DespawnOrUnsummon(100);

                timerChecktarget = 500;

            } else timerChecktarget -= diff;
        }

        void JustDied(Unit* /*killer*/) override
        {
            if(target)
                target->RemoveAura(SPELL_FLASH_FREEZE);

            me->DespawnOrUnsummon(100);
        }
    };
};

class mob_absolute_zero : public CreatureScript
{
public:
    mob_absolute_zero() : CreatureScript("mob_absolute_zero") { }

    struct mob_absolute_zeroAI : public ScriptedAI
    {
        mob_absolute_zeroAI(Creature* creature) : ScriptedAI(creature)
        {
            creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_NON_ATTACKABLE);
            creature->SetSpeed(MOVE_RUN, 1.5f);
        }

        void Reset() override
        {
            events.Reset();
            notactive = true;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            notactive = true;
            events.ScheduleEvent(EVENT_ZERO_TRANSFORM, 500);
        }

        void UpdateAI(uint32 diff) override
        {
            if(!UpdateVictim())
                return;

            events.Update(diff);

            if (Unit* player = me->SelectNearestPlayer(80.0f))
            {
                if (!notactive && me->GetDistance(player) <= 5.0f)
                {
                    DoCast(me, SPELL_ABSOLUTE_ZERO_DMG);
                    me->RemoveAllAuras();
                    me->DespawnOrUnsummon(1000);
                }
            }

            if(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                case EVENT_ZERO_TRANSFORM:
                    DoCast(me, SPELL_ABSOLUTE_ZERO_TRANSFORM);
                    events.ScheduleEvent(EVENT_ZERO_MOVE, 4000);
                    break;
                case EVENT_ZERO_MOVE:
                    notactive = false;
                    me->GetMotionMaster()->MoveRandom(20.0f);
                    break;
                }
            }
        }
    private:
        EventMap events;
        bool notactive;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_absolute_zeroAI (creature);
    }
};

class spell_release_abberations : public SpellScriptLoader
{
public:
    spell_release_abberations() : SpellScriptLoader("spell_release_abberations") { }

    class spell_release_abberationsSpellScript : public SpellScript
    {
        PrepareSpellScript(spell_release_abberationsSpellScript);

        bool Validate(SpellInfo const* /*spell*/) override
        {
            return true;
        }

        bool Load() override
        {
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if(Unit* caster = GetCaster())
                    for (uint8 i = 0; i<=2; i++)
                        caster->SummonCreature(NPC_ABBERATON, MaloriakPositions[urand(1,4)]);
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_release_abberationsSpellScript::HandleDummy,EFFECT_0,SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_release_abberationsSpellScript();
    }
};

class spell_release_all_abberations : public SpellScriptLoader
{
public:
    spell_release_all_abberations() : SpellScriptLoader("spell_release_all_abberations") { }

    class spell_release_all_abberationsSpellScript : public SpellScript
    {
        PrepareSpellScript(spell_release_all_abberationsSpellScript);

        bool Validate(SpellInfo const* /*spell*/) override
        {
            return true;
        }

        bool Load() override
        {
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if(Unit* caster = GetCaster())
                for (uint8 i = 0; i < 2; i++)
                    caster->SummonCreature(NPC_PRIME_SUBJECT, MaloriakPositions[urand(1,4)]);
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_release_all_abberationsSpellScript::HandleDummy,EFFECT_0,SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_release_all_abberationsSpellScript();
    }
};

void AddSC_boss_maloriak()
{
    new boss_maloriak();
    new mob_flash_freeze_maloriak();
    new mob_absolute_zero();
    new spell_release_abberations();
    new spell_release_all_abberations();
}
