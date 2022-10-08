/*
    Dungeon : Template of the Jade Serpent 85-87
    Liu Flameheat third boss
    Jade servers
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

#define TYPE_LIU_FLAMEHEART_STATUS 6
#define TYPE_IS_WIPE 7

enum eBosses
{
    BOSS_LIU_FLAMEHEART,
    BOSS_YU_LON,
    BOSS_TRIGGER,
};

enum eSpells
{
    //LIU FLAMEHEART Event:
    SPELL_POSSESSED_BY_SHA                  = 110164, //On Spawn
    SPELL_DUST_VISUAL                       = 110518, //On Spawn
    SPELL_SERPENT_DANCE_TRIGGER             = 106878,
    SPELL_SERPENT_STRIKE                    = 106823, //2 24 24 - 5 25 38 419912664 419923538 every 10 seconds
    SPELL_SERPENT_WAVE_SUMMON_CONTROLLER    = 106982, // 1 or 2 seconds after serpent strike
    SPELL_SERPENT_KICK                      = 106856, // 419913710 419924520, every 10 seconds
    SPELL_JADE_ESSENCE                      = 106797, //AddAura on phase 2
    SPELL_JADE_SERPENT_DANCE_TRIGGER        = 106882,
    SPELL_JADE_SERPENT_STRIKE               = 106841,
    SPELL_JADE_SERPENT_WAVE_SUMMON_CONTROLLER=106995,
    SPELL_JADE_SERPENT_KICK                 = 106864,
    SPELL_DEATH_SIPHON                      = 116783,
    SPELL_SUMMON_JADE_SERPENT               = 106895,
    SPELL_JADE_SOUL                         = 106909,

    SPELL_JADE_SERPENT_HEALTH               = 106924,
    SPELL_SHARED_HEALTH                     = 114711,
    SPELL_TRANSFORM_VISUAL                  = 74620, //When the dragon is dead, cast this and remove the possess aura.
    SPELL_JADE_FIRE                         = 107045,
    SPELL_JADE_FIRE_MISSILE                 = 107098,
    SPELL_JADE_FIRE_SUMMON                  = 107103,
    SPELL_CLEANSING_BREATH                  = 132387,

    SPELL_JADE_SERPENT_WAVE_DMG             = 118540,

    SPELL_SERPENT_WAVE_SUMMON               = 118551,
    SPELL_SERPENT_WAVE_SUMMON_N             = 118549,
    SPELL_SERPENT_WAVE_SUMMON_E             = 106930,
    SPELL_SERPENT_WAVE_SUMMON_S             = 106928,
    SPELL_SERPENT_WAVE_SUMMON_W             = 106931,

    SPELL_JADE_SERPENT_WAVE_VISUAL          = 107002,
    SPELL_SERPENT_WAVE_VISUAL               = 106939,
    SPELL_SERPENT_WAVE_PERIODIC             = 106959,
    SPELL_JADE_SERPENT_WAVE_PERIODIC        = 107054,
    SPELL_JADE_SERPENT_WAVE_STALKER_PERIODIC= 106879,
    SPELL_JADE_SERPENT_WAVE                 = 119508,
    SPELL_SERPENT_WAVE                      = 106938,

    SPELL_JADE_FIRE_PERIODIC                = 107108,
};

enum eStatus
{
    PHASE_1,
    PHASE_2,
    PHASE_3,
};

enum eEvents
{
    EVENT_SERPENT_STRIKE        = 1,
    EVENT_SERPENT_KICK          = 2,
    EVENT_SERPENT_WAVE          = 3,

    EVENT_JADE_SERPENT_STRIKE   = 4,
    EVENT_JADE_SERPENT_KICK     = 5,
    EVENT_JADE_SERPENT_WAVE     = 6,

    EVENT_SUMMON_YULON          = 7,
    EVENT_JADE_FIRE             = 8,

    EVENT_AURA_JADE             = 9,
    EVENT_LIU_FALL              = 10,
};

enum eTexts
{
    TALK_AGGRO_01,
    TALK_DEATH_01,
    TALK_EVENT_01,
    TALK_EVENT_02,
    TALK_INTRO_01,
    TALK_KILL_01,
    TALK_KILL_02,
};

enum eCreatures
{
    CREATURE_TRIGGER_WAVE = 56789,
};

class boss_liu_flameheart : public CreatureScript
{
    public:
        boss_liu_flameheart() : CreatureScript("boss_liu_flameheart") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_liu_flameheart_AI(creature);
        }

        struct boss_liu_flameheart_AI : public BossAI
        {
            boss_liu_flameheart_AI(Creature* creature) : BossAI(creature, BOSS_LIU_FLAMEHEART)
            {
                me->CastSpell(me, SPELL_POSSESSED_BY_SHA, false);
                status = PHASE_1;
                me->CastSpell(me, SPELL_DUST_VISUAL, false);
                wipe_timer = 2000;
                Talk(TALK_INTRO_01);
            }
            eStatus status;
            uint32 wipe_timer;

            void Reset()
            {
                status = PHASE_1;
                _Reset();
            }

            void DoAction(const int32 action)
            {
                switch (action)
                {
                case 0:
                    me->setFaction(35);
                    me->getThreatManager().resetAllAggro();
                    me->SetReactState(REACT_PASSIVE);
                    break;
                }
            }

            void KilledUnit(Unit* u)
            {
                if (urand(0, 1))
                    Talk(TALK_KILL_01);
                else
                    Talk(TALK_KILL_02);
            }

            void EnterCombat(Unit* unit)
            {
                Talk(TALK_AGGRO_01);
                events.ScheduleEvent(EVENT_SERPENT_STRIKE, 5000);
                events.ScheduleEvent(EVENT_JADE_SERPENT_KICK, 5000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (wipe_timer <= diff)
                {
                    if (me->GetInstanceScript() && me->GetInstanceScript()->GetData(TYPE_IS_WIPE))
                    {
                        me->GetInstanceScript()->SetData(TYPE_IS_WIPE, 1);
                        wipe_timer = 2000;
                    }
                }
                else
                    wipe_timer -= diff;

                if (!UpdateVictim())
                    return;

                events.Update(diff);
                
                if (me->GetHealthPct() < 70.f && status == PHASE_1)
                {
                    me->AddAura(SPELL_JADE_ESSENCE, me);

                    events.Reset();
                    events.ScheduleEvent(EVENT_JADE_SERPENT_STRIKE, 5000);
                    events.ScheduleEvent(EVENT_JADE_SERPENT_KICK, 10000);
                    Talk(TALK_EVENT_01);
                    status = PHASE_2;
                }
                if (me->GetHealthPct() < 30.f && status == PHASE_2)
                {
                    events.Reset();
                    events.ScheduleEvent(EVENT_SUMMON_YULON, 500);
                    Talk(TALK_EVENT_02);
                    status = PHASE_3;
                }

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_SERPENT_STRIKE:
                        {
                            me->CastSpell(me->getVictim(), SPELL_SERPENT_STRIKE, false);
                            Map::PlayerList const& PlayerList = me->GetInstanceScript()->instance->GetPlayers();

                            if (!PlayerList.isEmpty())
                            {
                                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                                {
                                    Player* plr = i->getSource();
                                    if( !plr)
                                        continue;
                                    if (plr->GetDistance2d(me) < 10.f)
                                        plr->KnockbackFrom(me->GetPositionX(), me->GetPositionY(), 10, 10);
                                }
                            }
                            events.ScheduleEvent(EVENT_SERPENT_STRIKE, 10000);
                            events.ScheduleEvent(EVENT_SERPENT_WAVE, 4000);
                        }
                        break;
                    case EVENT_SERPENT_KICK:
                        me->CastSpell(me->getVictim(), SPELL_SERPENT_KICK, false);
                        events.ScheduleEvent(EVENT_SERPENT_KICK, 10000);
                        break;
                    case EVENT_SERPENT_WAVE:
                        {
                            TempSummon* sum = nullptr;
                            sum = me->SummonCreature(CREATURE_TRIGGER_WAVE, 932.775f, -2548.743f, 179.821f, 1.254f);
                            if (sum)
                            {
                                sum->SetDisplayId(11686);
                                sum->CastSpell(sum, SPELL_SERPENT_WAVE_VISUAL, false);
                                sum->CastSpell(sum, SPELL_SERPENT_WAVE_PERIODIC, false);
                                sum->GetMotionMaster()->MovePoint(0, 939.796f, -2530.586f, 179.941f);
                                sum->ForcedDespawn(3200);
                            }
                            sum = me->SummonCreature(CREATURE_TRIGGER_WAVE, 940.014f, -2564.114f, 179.821f, 5.978f);
                            if (sum)
                            {
                                sum->SetDisplayId(11686);
                                sum->CastSpell(sum, SPELL_SERPENT_WAVE_VISUAL, false);
                                sum->CastSpell(sum, SPELL_SERPENT_WAVE_PERIODIC, false);
                                sum->GetMotionMaster()->MovePoint(0, 957.711f, -2570.030f, 179.941f);
                                sum->ForcedDespawn(3200);
                            }
                            sum = me->SummonCreature(CREATURE_TRIGGER_WAVE, 925.971f, -2572.423f, 179.821f, 4.395f);
                            if (sum)
                            {
                                sum->SetDisplayId(11686);
                                sum->CastSpell(sum, SPELL_SERPENT_WAVE_VISUAL, false);
                                sum->CastSpell(sum, SPELL_SERPENT_WAVE_PERIODIC, false);
                                sum->GetMotionMaster()->MovePoint(0, 919.606f, -2591.245f, 179.941f);
                                sum->ForcedDespawn(3200);
                            }
                            sum = me->SummonCreature(CREATURE_TRIGGER_WAVE, 918.923f, -2557.356f, 179.821f, 2.821f);
                            if (sum)
                            {
                                sum->SetDisplayId(11686);
                                sum->CastSpell(sum, SPELL_SERPENT_WAVE_VISUAL, false);
                                sum->CastSpell(sum, SPELL_SERPENT_WAVE_PERIODIC, false);
                                sum->GetMotionMaster()->MovePoint(0, 901.839f, -2551.843f, 179.941f);
                                sum->ForcedDespawn(3200);
                            }
                        }
                        break;
                    case EVENT_JADE_SERPENT_STRIKE:
                        {
                            me->CastSpell(me->getVictim(), SPELL_JADE_SERPENT_STRIKE, false);

                            Map::PlayerList const& PlayerList = me->GetInstanceScript()->instance->GetPlayers();

                            if (!PlayerList.isEmpty())
                            {
                                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                                {
                                    Player* plr = i->getSource();
                                    if( !plr)
                                        continue;
                                    if (plr->GetDistance2d(me) < 10.f)
                                        plr->KnockbackFrom(me->GetPositionX(), me->GetPositionY(), 10, 10);
                                }
                            }
                            events.ScheduleEvent(EVENT_JADE_SERPENT_STRIKE, 10000);
                            events.ScheduleEvent(EVENT_JADE_SERPENT_WAVE, 4000);
                        }
                        break;
                    case EVENT_JADE_SERPENT_KICK:
                        me->CastSpell(me->getVictim(), SPELL_JADE_SERPENT_KICK, false);
                        events.ScheduleEvent(EVENT_JADE_SERPENT_KICK, 10000);
                        break;
                    case EVENT_JADE_SERPENT_WAVE:
                        {
                            TempSummon* sum = nullptr;
                            sum = me->SummonCreature(CREATURE_TRIGGER_WAVE, 932.775f, -2548.743f, 179.821f, 1.254f);
                            if (sum)
                            {
                                sum->SetDisplayId(11686);
                                sum->CastSpell(sum, SPELL_JADE_SERPENT_WAVE_VISUAL, false);
                                sum->CastSpell(sum, SPELL_SERPENT_WAVE_PERIODIC, false);
                                sum->GetMotionMaster()->MovePoint(0, 939.796f, -2530.586f, 179.941f);
                                sum->ForcedDespawn(3200);
                            }
                            sum = me->SummonCreature(CREATURE_TRIGGER_WAVE, 940.014f, -2564.114f, 179.821f, 5.978f);
                            if (sum)
                            {
                                sum->SetDisplayId(11686);
                                sum->CastSpell(sum, SPELL_JADE_SERPENT_WAVE_VISUAL, false);
                                sum->CastSpell(sum, SPELL_SERPENT_WAVE_PERIODIC, false);
                                sum->GetMotionMaster()->MovePoint(0, 957.711f, -2570.030f, 179.941f);
                                sum->ForcedDespawn(3200);
                            }
                            sum = me->SummonCreature(CREATURE_TRIGGER_WAVE, 925.971f, -2572.423f, 179.821f, 4.395f);
                            if (sum)
                            {
                                sum->SetDisplayId(11686);
                                sum->CastSpell(sum, SPELL_JADE_SERPENT_WAVE_VISUAL, false);
                                sum->CastSpell(sum, SPELL_SERPENT_WAVE_PERIODIC, false);
                                sum->GetMotionMaster()->MovePoint(0, 919.606f, -2591.245f, 179.941f);
                                sum->ForcedDespawn(3200);
                            }
                            sum = me->SummonCreature(CREATURE_TRIGGER_WAVE, 918.923f, -2557.356f, 179.821f, 2.821f);
                            if (sum)
                            {
                                sum->SetDisplayId(11686);
                                sum->CastSpell(sum, SPELL_JADE_SERPENT_WAVE_VISUAL, false);
                                sum->CastSpell(sum, SPELL_SERPENT_WAVE_PERIODIC, false);
                                sum->GetMotionMaster()->MovePoint(0, 901.839f, -2551.843f, 179.941f);
                                sum->ForcedDespawn(3200);
                            }
                        }
                        break;
                    case EVENT_SUMMON_YULON:
                        me->CastSpell(me, SPELL_SUMMON_JADE_SERPENT, false);
                        me->CastSpell(me, SPELL_JADE_SOUL, false);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        me->ApplySpellImmune(SPELL_JADE_SOUL, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, true);
                        me->ApplySpellImmune(SPELL_JADE_SOUL, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, true);
                        me->SetReactState(REACT_PASSIVE);
                        me->AddUnitState(UNIT_STATE_ROOT);
                        events.ScheduleEvent(EVENT_AURA_JADE, 3000);
                        break;

                    case EVENT_AURA_JADE:
                        me->CastSpell(me, SPELL_JADE_SOUL, false);
                        events.ScheduleEvent(EVENT_AURA_JADE, 2500);
                        break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

class boss_yu_lon_tojs : public CreatureScript
{
    public:
        boss_yu_lon_tojs() : CreatureScript("boss_yu_lon_tojs") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_yu_lon_tojs_AI(creature);
        }

        struct boss_yu_lon_tojs_AI : public BossAI
        {
            boss_yu_lon_tojs_AI(Creature* creature) : BossAI(creature, BOSS_YU_LON)
            {
            }

            void EnterCombat(Unit* unit)
            {
                events.ScheduleEvent(EVENT_JADE_FIRE, 100);
            }

            void JustDied(Unit* died)
            {
                me->CastSpell(me, 132387, false);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_JADE_FIRE:
                        me->CastSpell(SelectTarget(SELECT_TARGET_RANDOM), SPELL_JADE_FIRE, false);
                        events.ScheduleEvent(EVENT_JADE_FIRE, 1700);
                        break;
                    }
                }
                
                DoMeleeAttackIfReady();
            }
        };
};

class mob_trigger_liu_flameheart: public CreatureScript
{
    public:
        mob_trigger_liu_flameheart() : CreatureScript("mob_trigger_liu_flameheart") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_trigger_liu_flameheart_AI(creature);
        }

        struct mob_trigger_liu_flameheart_AI : public ScriptedAI
        {
            mob_trigger_liu_flameheart_AI(Creature* creature) : ScriptedAI(creature)
            {
                if (me->GetInstanceScript() && me->GetInstanceScript()->GetData(TYPE_LIU_FLAMEHEART_STATUS))
                    timer = 500;
                else
                    timer = 0;
            }
            uint32 timer;

            void UpdateAI(const uint32 diff)
            {
                if (timer <= diff)
                {
                    if (me->GetInstanceScript() && me->GetInstanceScript()->GetData(TYPE_LIU_FLAMEHEART_STATUS))
                    {
                        me->CastSpell(me, 107103, false);
                        timer = 1000;
                    }
                }
                else
                    timer -= diff;
            }
        };
};

class mob_minion_of_doubt: public CreatureScript
{
    public:
        mob_minion_of_doubt() : CreatureScript("mob_minion_of_doubt") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_minion_of_doubt_AI(creature);
        }

        struct mob_minion_of_doubt_AI : public ScriptedAI
        {
            mob_minion_of_doubt_AI(Creature* creature) : ScriptedAI(creature)
            {
            }
            EventMap events;

            void EnterCombat(Unit* unit)
            {
                events.ScheduleEvent(1, 2000);
                events.ScheduleEvent(2, 4000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case 1:
                        me->CastSpell(me->getVictim(), 110099, false);
                        events.ScheduleEvent(1, 5000);
                        break;
                    case 2:
                        me->CastSpell(me->getVictim(), 110125, false);
                        events.ScheduleEvent(2, 5000);
                        break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };
};

class mob_lesser_sha: public CreatureScript
{
    public:
        mob_lesser_sha() : CreatureScript("mob_lesser_sha") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_lesser_sha_AI(creature);
        }

        struct mob_lesser_sha_AI : public ScriptedAI
        {
            mob_lesser_sha_AI(Creature* creature) : ScriptedAI(creature)
            {
            }
            EventMap events;

            void EnterCombat(Unit* unit)
            {
                events.ScheduleEvent(1, 2000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case 1:
                        me->CastSpell(me->getVictim(), 122527, false);
                        events.ScheduleEvent(1, 5000);
                        break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };
};

void AddSC_boss_liu_flameheat()
{
    new boss_liu_flameheart();
    new boss_yu_lon_tojs();
    new mob_trigger_liu_flameheart();
    //Trashes
    new mob_minion_of_doubt();
    new mob_lesser_sha();
}