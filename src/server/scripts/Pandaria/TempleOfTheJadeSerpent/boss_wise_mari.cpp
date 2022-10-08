/*
    Dungeon : Template of the Jade Serpent 85-87
    Wise mari
    Jade servers
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum eBoss
{
    BOSS_WASE_MARI = 1,
};

enum eSpells
{
    SPELL_WATER_BUBBLE              = 106062,
    SPELL_CALL_WATER                = 106526,
    SPELL_CORRUPTED_FOUTAIN         = 106518,
    SPELL_SHA_RESIDUE               = 106653,
    SPELL_HYDROLANCE_PRECAST        = 115220,
    SPELL_HYDROLANCE_DMG_BOTTOM     = 106267,
    SPELL_HYDROLANCE_VISUAL         = 106055,
    SPELL_HYDROLANCE_DMG            = 106105,
    SPELL_WASH_AWAY                 = 106331,
};

enum eTexts
{
    TEXT_INTRO            = 0,
    TEXT_AGGRO            = 1,
    TEXT_BOSS_EMOTE_AGGRO = 2,
    TEXT_CALL_WATER       = 3,
    TEXT_PHASE_SWITCH     = 4,
    TEXT_DEATH            = 5,
    TEXT_KILL_PLAYER      = 6,
};

enum eEvents
{
    EVENT_CALL_WATER        = 1,
    EVENT_HYDROLANCE        = 2,
    EVENT_HYDROLANCE_START  = 3,
    EVENT_SWITCH_PHASE_TWO  = 4,
    EVENT_WASH_AWAY         = 5,
};

enum eCreatures
{
    CREATURE_FOUTAIN_TRIGGER            = 56586,
    CREATURE_CORRUPT_DROPLET            = 62358,
    CREATURE_HYDROLANCE_BOTTOM_TRIGGER  = 56542,
};

enum eTimers
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
            boss_wise_mari_AI(Creature* creature) : BossAI(creature, BOSS_WASE_MARI)
            {
                creature->AddUnitState(UNIT_STATE_ROOT | UNIT_STATE_CANNOT_TURN);
            }

            bool ennemyInArea;
            bool intro;
            uint8 phase;
            uint8 foutainCount;
            uint64 foutainTrigger[4];
            uint32 hydrolancePhase;

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

                    itr->RemoveAllAuras();
                }

                hydrolancePhase = 0;
                foutainCount = 0;
                phase = 0;
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

                    foutainTrigger[++tab] = itr->GetGUID();
                }

                searcher.clear();
                GetCreatureListWithEntryInGrid(searcher, me, CREATURE_CORRUPT_DROPLET, 50.0f);
                for (auto itr : searcher)
                {
                    if (!itr)
                        continue;

                    if (itr->isSummon())
                        itr->ForcedDespawn();
                }

                me->SetInCombatWithZone();
                me->CastSpell(me, SPELL_WATER_BUBBLE, true);
                Talk(TEXT_AGGRO);
                Talk(TEXT_BOSS_EMOTE_AGGRO);
                intro = true;
                phase = 1;
                hydrolancePhase = HYDROLANCE_BOTTOM;
                events.ScheduleEvent(EVENT_CALL_WATER, 8000);
                events.ScheduleEvent(EVENT_HYDROLANCE_START, TIMER_HYDROLANCE_START);

                _EnterCombat();
            }

            void DoAction(const int32 action)
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
            }

            void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/)
            {

            }

            void MoveInLineOfSight(Unit* who)
            {
                if(who->GetTypeId() != TYPEID_PLAYER)
                    return;

                if(intro)
                    return;

                if(!ennemyInArea)
                {
                    Talk(TEXT_INTRO);
                    ennemyInArea = true;
                    return;
                }
                
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                // Wise Mari don't rotate
                if (me->GetUInt32Value(UNIT_FIELD_TARGET))
                    me->SetUInt32Value(UNIT_FIELD_TARGET, 0);

                if (me->HasUnitState(UNIT_STATE_CASTING) && phase != 2)
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CALL_WATER:
                        {
                            if (phase != 1)
                                break;

                            Talk(TEXT_CALL_WATER);

                            Creature* trigger = me->GetCreature(*me, foutainTrigger[++foutainCount]);
                            if (trigger)
                            {
                                me->CastSpell(trigger, SPELL_CALL_WATER, true);
                                trigger->AddAura(SPELL_CORRUPTED_FOUTAIN, trigger);
                            }

                            if (foutainCount == 4)
                            {
                                phase = 2;
                                events.ScheduleEvent(EVENT_SWITCH_PHASE_TWO, TIMER_SWITCH_PHASE_TWO);
                                break;
                            }
                            events.ScheduleEvent(EVENT_CALL_WATER, TIMER_CALL_WATTER + rand() % 6000);
                            break;
                        }

                        case EVENT_HYDROLANCE_START:
                        {
                            if (phase != 1)
                                break;

                            float facing = 0.00f;
                            events.ScheduleEvent(EVENT_HYDROLANCE, TIMER_HYDROLANCE);
                            switch (hydrolancePhase)
                            {
                                case HYDROLANCE_BOTTOM:
                                    {
                                        std::list<Creature*> trigger;
                                        me->GetCreatureListWithEntryInGrid(trigger,CREATURE_HYDROLANCE_BOTTOM_TRIGGER, 50.0f);
                                        for (auto itr : trigger)
                                            itr->CastSpell(itr, SPELL_HYDROLANCE_PRECAST, true);
                                        facing = 1.23f;
                                        break;
                                    }
                                case HYDROLANCE_RIGHT:
                                    for (int i = 0; i < 5; i++)
                                        me->CastSpell(hydrolanceRightTrigger[i][0], hydrolanceRightTrigger[i][1], hydrolanceRightTrigger[i][2], SPELL_HYDROLANCE_PRECAST, true);
                                    facing = 3.55f;
                                    break;
                                case HYDROLANCE_LEFT:
                                    for (int i = 0; i < 5; i++)
                                        me->CastSpell(hydrolanceLeftTrigger[i][0], hydrolanceLeftTrigger[i][1], hydrolanceLeftTrigger[i][2], SPELL_HYDROLANCE_PRECAST, true);
                                    facing = 5.25f;
                                    break;
                            }
                            me->CastSpell(me, SPELL_HYDROLANCE_VISUAL, false);
                            me->UpdatePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), facing);
                            me->SetFacingTo(facing);
                            break;
                        }

                        case EVENT_HYDROLANCE:
                        {
                            if (phase != 1)
                                break;
                            switch (hydrolancePhase)
                            {
                                case HYDROLANCE_BOTTOM:
                                {
                                    std::list<Creature*> trigger;
                                    me->GetCreatureListWithEntryInGrid(trigger,CREATURE_HYDROLANCE_BOTTOM_TRIGGER, 50.0f);
                                    for (auto itr : trigger)
                                        itr->CastSpell(itr->GetPositionX(), itr->GetPositionY(), itr->GetPositionZ(), SPELL_HYDROLANCE_DMG_BOTTOM, true);
                                    break;
                                }
                                case HYDROLANCE_RIGHT:
                                    for (int i = 0; i < 5; i++)
                                        me->CastSpell(hydrolanceRightTrigger[i][0], hydrolanceRightTrigger[i][1], hydrolanceRightTrigger[i][2], SPELL_HYDROLANCE_DMG, true);
                                    break;
                                case HYDROLANCE_LEFT:
                                    for (int i = 0; i < 5; i++)
                                        me->CastSpell(hydrolanceLeftTrigger[i][0], hydrolanceLeftTrigger[i][1], hydrolanceLeftTrigger[i][2], SPELL_HYDROLANCE_DMG, true);
                                    break;
                            }

                            if( hydrolancePhase == HYDROLANCE_RIGHT)
                                hydrolancePhase = HYDROLANCE_BOTTOM;
                            else
                                hydrolancePhase++;

                            events.ScheduleEvent(EVENT_HYDROLANCE_START, TIMER_HYDROLANCE_START);
                            break;

                        }

                        case EVENT_SWITCH_PHASE_TWO:
                        {
                            if (phase !=2)
                                break;

                            Talk(TEXT_PHASE_SWITCH);

                            me->RemoveAurasDueToSpell(SPELL_WATER_BUBBLE);
                            float facing = me->GetOrientation();
                            facing += M_PI/48;

                            if(facing > M_PI*2)
                                facing -= M_PI*2;

                            //me->UpdatePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), facing);
                            me->SetOrientation(facing);
                            me->SetFacingTo(facing);
                            me->CastSpell(me, SPELL_WASH_AWAY, true);
                            events.ScheduleEvent(EVENT_WASH_AWAY, TIMER_WASH_AWAY);
                            break;
                        }

                        case EVENT_WASH_AWAY:
                        {
                            if (phase !=2)
                                break;

                            float facing = me->GetOrientation();
                            facing += M_PI/48;

                            if(facing > M_PI*2)
                                facing -= M_PI*2;

                            me->SetOrientation(facing);
                            me->SetFacingTo(facing);

                            events.ScheduleEvent(EVENT_WASH_AWAY, TIMER_WASH_AWAY);
                            break;
                        }
                    }
                }

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
            mob_corrupt_living_water_AI(Creature* creature) : ScriptedAI(creature)
            {
            }


            void Reset()
            {
            }

            void JustDied(Unit* /*killer*/)
            {
                for (int i = 0; i < 4; i++)
                {
                    Position pos;
                    me->GetRandomNearPosition(pos, 4.0f);
                    Creature* droplet = me->SummonCreature(CREATURE_CORRUPT_DROPLET, pos);
                    if (!droplet)
                        continue;

                    if(Unit* unit = SelectTarget(SELECT_TARGET_RANDOM))
                        droplet->Attack(unit, true);
                }

                me->CastSpell(me, SPELL_SHA_RESIDUE, true);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }
        };
};

void AddSC_boss_wise_mari()
{
    new boss_wase_mari();
    new mob_corrupt_living_water();
}
