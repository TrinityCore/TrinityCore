#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "temple_of_jade_serpent.h"

enum eSpellsWise
{
    SPELL_WATER_BUBBLE              = 106062,
    SPELL_REMOVE_WATER_BUBBLE       = 106612,
    SPELL_CALL_WATER                = 106526,
    SPELL_CORRUPTED_FOUTAIN         = 106518,
    SPELL_SHA_RESIDUE               = 106653,
    SPELL_HYDROLANCE_PRECAST        = 115220,
    SPELL_HYDROLANCE_DMG_BOTTOM     = 106267,
    SPELL_HYDROLANCE_VISUAL         = 106055,
    SPELL_HYDROLANCE_DMG            = 106105,
    SPELL_WASH_AWAY                 = 106331,
    SPELL_DRY                       = 128437,
    SPELL_BLESSING_WATER_SPEAKER    = 121483,
};

enum eTextsWise
{
    TEXT_INTRO            = 0,
    TEXT_AGGRO            = 1, //should have a emote
    TEXT_CALL_WATER       = 2,
    TEXT_PHASE_SWITCH     = 3,
    TEXT_DEATH            = 4,
    TEXT_KILL_PLAYER      = 5,
};

enum eEventsWise
{
    EVENT_CALL_WATER          = 1,
    EVENT_HYDROLANCE          = 2,
    EVENT_HYDROLANCE_START    = 3,
    EVENT_SWITCH_PHASE_TWO_1  = 4,
    EVENT_SWITCH_PHASE_TWO_2  = 5,
    EVENT_WASH_AWAY           = 6,
};

enum eCreaturesWise
{
    CREATURE_FOUTAIN_TRIGGER            = 56586,
    CREATURE_CORRUPT_DROPLET            = 62358,
    CREATURE_HYDROLANCE_BOTTOM_TRIGGER  = 56542,
};

enum eTimersWise
{
    TIMER_CALL_WATTER           = 29000,
    TIMER_HYDROLANCE_START      = 10000,
    TIMER_HYDROLANCE            =  5500,
    TIMER_SWITCH_PHASE_TWO      = 15000,
    TIMER_WASH_AWAY             =   125,
};

enum hydrolancePhase
{
    HYDROLANCE_BOTTOM   = 1,
    HYDROLANCE_LEFT     = 2,
    HYDROLANCE_RIGHT    = 3,
};

enum BossPhasesWise
{
    PHASE_SLEEPING_WATER = 1,
    PHASE_WATER_POWER    = 2,
};

static const float fountainTriggerPos[4][3] = 
{
    {1022.743f, -2544.295f, 173.7757f},
    {1023.314f, -2569.695f, 176.0339f},
    {1059.943f, -2581.648f, 176.1427f},
    {1075.231f, -2561.335f, 173.8758f},
};

static const float hydrolanceLeftTrigger[5][3] =
{
    {1061.411f, -2570.721f, 174.2403f},
    {1058.921f, -2573.487f, 174.2403f},
    {1055.910f, -2575.674f, 174.2403f},
    {1052.511f, -2577.188f, 174.2403f},
    {1048.871f, -2577.961f, 174.2403f},
};

static const float hydrolanceRightTrigger[5][3] =
{
    {1035.333f, -2573.693f, 174.2403f},
    {1032.795f, -2570.971f, 174.2403f},
    {1030.878f, -2567.781f, 174.2403f},
    {1029.667f, -2564.263f, 174.2403f},
    {1029.213f, -2560.569f, 174.2403f},
};

class boss_wase_mari : public CreatureScript
{
    public:
        boss_wase_mari() : CreatureScript("boss_wase_mari") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_wise_mari_AI(creature);
        }

        struct boss_wise_mari_AI : public BossAI
        {
            boss_wise_mari_AI(Creature* creature) : BossAI(creature, DATA_WISE_MARI_EVENT)
            {
                creature->AddUnitState(UNIT_STATE_ROOT | UNIT_STATE_CANNOT_TURN);
            }

            bool ennemyInArea;
            bool intro;
            uint8 foutainCount;
            uint64 foutainTrigger[4];
            uint32 hydrolancePhase;
            uint32 facingDoneSinceLastDry;

            void Reset()
            {
                for (uint8 i = 0; i < 4; i++)
                    foutainTrigger[i] = 0;

                std::list<Creature*> searcher;
                GetCreatureListWithEntryInGrid(searcher, me, CREATURE_FOUTAIN_TRIGGER, 50.0f);
                for (auto itr : searcher)
                {
                    if (!itr)
                        continue;

                    itr->Respawn(true);
                    itr->RemoveAllAuras();
                }

                hydrolancePhase = 0;
                foutainCount = 0;
                facingDoneSinceLastDry = 0;
                ennemyInArea= false;
                intro = false;
                me->RemoveAurasDueToSpell(SPELL_WATER_BUBBLE);

                _Reset();
            }

            void EnterCombat(Unit* /*who*/)
            {
                std::list<Creature*> searcher;
                GetCreatureListWithEntryInGrid(searcher, me, CREATURE_FOUTAIN_TRIGGER, 50.0f);
                uint8 tab = 0;
                for (auto itr : searcher)
                {
                    if (!itr)
                        continue;

                    itr->RemoveAllAuras();
                    foutainTrigger[++tab] = itr->GetGUID().GetEntry();
                }

                searcher.clear();
                GetCreatureListWithEntryInGrid(searcher, me, CREATURE_CORRUPT_DROPLET, 50.0f);
                for (auto corruptDroplet : searcher)
                    if (corruptDroplet)
                        if (corruptDroplet->IsSummon())
                            corruptDroplet->DespawnOrUnsummon();

                me->SetInCombatWithZone();
                me->CastSpell(me, SPELL_WATER_BUBBLE, true);
                Talk(TEXT_AGGRO);
                intro = true;
                events.SetPhase(PHASE_SLEEPING_WATER);
                hydrolancePhase = HYDROLANCE_BOTTOM;
                events.ScheduleEvent(EVENT_CALL_WATER,       8000,                   0, PHASE_SLEEPING_WATER);
                events.ScheduleEvent(EVENT_HYDROLANCE_START, TIMER_HYDROLANCE_START, 0, PHASE_SLEEPING_WATER);

                _EnterCombat();
            }

            void DoAction(int32 action)
            {
            }

            void KilledUnit(Unit* /*victim*/)
            {
                Talk(TEXT_KILL_PLAYER);
            }

            void JustDied(Unit* /*killer*/)
            {
                Talk(TEXT_DEATH);
                _JustDied();
                instance->DoCastSpellOnPlayers(SPELL_BLESSING_WATER_SPEAKER);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/)
            {

            }

            void MoveInLineOfSight(Unit* who)
            {
                if(who->GetTypeId() != TYPEID_PLAYER)
                    return;

                if(!intro && !ennemyInArea)
                {
                    Talk(TEXT_INTRO);
                    ennemyInArea = true;
                    return;
                }
            }

            void ExecuteEvent(uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_CALL_WATER:
                    {
                        Talk(TEXT_CALL_WATER);

                        /*Creature* trigger = me->GetCreature(*me, foutainTrigger[++foutainCount]);
                        if (trigger)
                        {
                            me->CastSpell(trigger, SPELL_CALL_WATER, true);
                            trigger->AddAura(SPELL_CORRUPTED_FOUTAIN, trigger);
                            trigger->SetInCombatWithZone();
                        }*/

                        if (foutainCount == 4)
                        {
                            events.ScheduleEvent(EVENT_SWITCH_PHASE_TWO_1, TIMER_SWITCH_PHASE_TWO, 0, PHASE_SLEEPING_WATER);
                            break;
                        }
                        events.ScheduleEvent(EVENT_CALL_WATER, TIMER_CALL_WATTER + urand(0, 6000), 0, PHASE_SLEEPING_WATER);
                        break;
                    }
                    case EVENT_HYDROLANCE_START:
                    {
                        float facing = 0.00f;
                        switch (hydrolancePhase)
                        {
                            case HYDROLANCE_BOTTOM:
                            {
                                std::list<Creature*> trigger;
                                me->GetCreatureListWithEntryInGrid(trigger, CREATURE_HYDROLANCE_BOTTOM_TRIGGER, 50.0f);
                                for (auto itr : trigger)
                                    itr->CastSpell(itr, SPELL_HYDROLANCE_PRECAST, true);
                                facing = 1.23f;
                                break;
                            }
                            case HYDROLANCE_RIGHT:
                            {
                                for (int i = 0; i < 5; i++)
                                    me->CastSpell(hydrolanceRightTrigger[i][0], hydrolanceRightTrigger[i][1], hydrolanceRightTrigger[i][2], SPELL_HYDROLANCE_PRECAST, true);
                                facing = 3.55f;
                                break;
                            }
                            case HYDROLANCE_LEFT:
                            {
                                for (int i = 0; i < 5; i++)
                                    me->CastSpell(hydrolanceLeftTrigger[i][0], hydrolanceLeftTrigger[i][1], hydrolanceLeftTrigger[i][2], SPELL_HYDROLANCE_PRECAST, true);
                                facing = 5.25f;
                                break;
                            }
                        }

                        me->CastSpell(me, SPELL_HYDROLANCE_VISUAL, false);
                        me->UpdatePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), facing);
                        me->SetFacingTo(facing);
                        events.ScheduleEvent(EVENT_HYDROLANCE, TIMER_HYDROLANCE, 0, PHASE_SLEEPING_WATER);
                        break;
                    }
                    case EVENT_HYDROLANCE:
                    {
                        switch (hydrolancePhase)
                        {
                            case HYDROLANCE_BOTTOM:
                            {
                                std::list<Creature*> trigger;
                                me->GetCreatureListWithEntryInGrid(trigger, CREATURE_HYDROLANCE_BOTTOM_TRIGGER, 50.0f);
                                for (auto itr : trigger)
                                    itr->CastSpell(itr->GetPositionX(), itr->GetPositionY(), itr->GetPositionZ(), SPELL_HYDROLANCE_DMG_BOTTOM, true);
                                break;
                            }
                            case HYDROLANCE_RIGHT:
                            {
                                for (int i = 0; i < 5; i++)
                                    me->CastSpell(hydrolanceRightTrigger[i][0], hydrolanceRightTrigger[i][1], hydrolanceRightTrigger[i][2], SPELL_HYDROLANCE_DMG, true);
                                break;
                            }

                            case HYDROLANCE_LEFT:
                            {
                                for (int i = 0; i < 5; i++)
                                    me->CastSpell(hydrolanceLeftTrigger[i][0], hydrolanceLeftTrigger[i][1], hydrolanceLeftTrigger[i][2], SPELL_HYDROLANCE_DMG, true);
                                break;
                            }
                        }

                        if (hydrolancePhase == HYDROLANCE_RIGHT)
                            hydrolancePhase = HYDROLANCE_BOTTOM;
                        else
                            hydrolancePhase++;

                        events.ScheduleEvent(EVENT_HYDROLANCE_START, TIMER_HYDROLANCE_START, 0, PHASE_SLEEPING_WATER);
                        break;
                    }
                    case EVENT_SWITCH_PHASE_TWO_1:
                    {
                        events.SetPhase(PHASE_WATER_POWER);
                        Talk(TEXT_PHASE_SWITCH);

                        me->CastSpell(me, SPELL_REMOVE_WATER_BUBBLE, false);
                        events.ScheduleEvent(EVENT_SWITCH_PHASE_TWO_2, 4100, 0, PHASE_WATER_POWER);
                        break;
                    }
                    case EVENT_SWITCH_PHASE_TWO_2:
                    {
                        me->RemoveAurasDueToSpell(SPELL_WATER_BUBBLE);
                        float facing = me->GetOrientation();
                        facing -= M_PI / 48;

                        if (facing < 0)
                            facing += M_PI * 2;

                        //me->UpdatePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), facing);
                        me->SetOrientation(facing);
                        me->SetFacingTo(facing);
                        me->CastSpell(me, SPELL_WASH_AWAY, true);
                        events.ScheduleEvent(EVENT_WASH_AWAY, TIMER_WASH_AWAY, 0, PHASE_WATER_POWER);
                        break;
                    }
                    case EVENT_WASH_AWAY:
                    {
                        float facing = me->GetOrientation();
                        facing -= M_PI / 48;

                        if (facing < 0)
                            facing += M_PI * 2;

                        me->SetOrientation(facing);
                        me->SetFacingTo(facing);

                        //Players can only be targetted by the lazor only once 1/8 of the cicle
                        facingDoneSinceLastDry -= M_PI / 48;
                        if (facingDoneSinceLastDry < 0)
                        {
                            facingDoneSinceLastDry += M_PI / 4;
                            if (me->GetInstanceScript())
                                me->GetInstanceScript()->DoCastSpellOnPlayers(SPELL_DRY);
                        }

                        events.ScheduleEvent(EVENT_WASH_AWAY, TIMER_WASH_AWAY, 0, PHASE_WATER_POWER);
                        break;
                    }
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                // Wise Mari don't rotate
                if (me->GetUInt32Value(UNIT_FIELD_TARGET))
                    me->SetUInt32Value(UNIT_FIELD_TARGET, 0);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                    ExecuteEvent(eventId);

            }
        };
};

class mob_corrupt_living_water : public CreatureScript
{
    public:
        mob_corrupt_living_water() : CreatureScript("mob_corrupt_living_water") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_corrupt_living_water_AI(creature);
        }

        struct mob_corrupt_living_water_AI : public ScriptedAI
        {
            mob_corrupt_living_water_AI(Creature* creature) : ScriptedAI(creature) { }

            void Reset()
            {
                me->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);
            }

            void JustDied(Unit* /*killer*/)
            {
                for (int i = 0; i < 3; i++)
                {
                    Position pos;
                    me->GetRandomNearPosition(4.0f);
                    Creature* droplet = me->SummonCreature(CREATURE_CORRUPT_DROPLET, pos);
                    if (!droplet)
                        continue;

                    droplet->SetInCombatWithZone();
                    if(Unit* unit = SelectTarget(SELECT_TARGET_RANDOM))
                        droplet->Attack(unit, true);
                }

                me->CastSpell(me, SPELL_SHA_RESIDUE, true);
            }
        };
};

// Wash Away - 106334
class spell_wise_mari_wash_away : public SpellScriptLoader
{
public:
    spell_wise_mari_wash_away() : SpellScriptLoader("spell_wise_mari_wash_away") { }

    class spell_wise_mari_wash_away_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_wise_mari_wash_away_SpellScript);

        void SelectTarget(std::list<WorldObject*>& targets)
        {
            for (auto target : targets)
            {
                //we only target players having dry aura
                if (!(target->ToPlayer() && target->ToPlayer()->HasAura(SPELL_DRY)))
                    targets.remove(target);
            }
        }

        void Register() override
        {
            for (uint8 i = EFFECT_0; i <= EFFECT_2; i++)
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_wise_mari_wash_away_SpellScript::SelectTarget, i, UNIT_FIELD_TARGET);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_wise_mari_wash_away_SpellScript();
    }
};


void AddSC_boss_wise_mari()
{
    new boss_wase_mari();
    new mob_corrupt_living_water();
    new spell_wise_mari_wash_away();
}
