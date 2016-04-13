#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "temple_of_jade_serpent.h"

enum eSpellsLiu
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

enum eStatusLiu
{
    PHASE_1 = 1,
    PHASE_2 = 2,
    PHASE_3 = 3,
};

enum eActions
{
    ACTION_YU_LON_DONE          = 0,
    ACTION_MINIONS_DEAD         = 1
};

enum eEventsLiu
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

enum eTextsLiu
{
    TALK_AGGRO_01,
    TALK_DEATH_01,
    TALK_EVENT_01,
    TALK_EVENT_02,
    TALK_INTRO_01,
    TALK_KILL_01,
    TALK_KILL_02,
};

enum eCreaturesLiu
{
    CREATURE_TRIGGER_WAVE = 56789,
};

enum eZonesLiu
{
    ZONE_LIU_FIGHT = 6118,
};

Position serpentWavePositions[4][2] = 
{
    { {932.775f, -2548.743f, 179.821f, 1.254f}, {939.796f, -2530.586f, 179.941f, 0.0f} },
    { {940.014f, -2564.114f, 179.821f, 5.978f}, {957.711f, -2570.030f, 179.941f, 0.0f} },
    { {925.971f, -2572.423f, 179.821f, 4.395f}, {919.606f, -2591.245f, 179.941f, 0.0f} },
    { {918.923f, -2557.356f, 179.821f, 2.821f}, {901.839f, -2551.843f, 179.941f, 0.0f} }
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
            boss_liu_flameheart_AI(Creature* creature) : BossAI(creature, DATA_LIU_FLAMEHEART_EVENT)
            {
                me->SetVisible(false);

                std::list<Creature*> liuCreatures;
                GetCreatureListWithEntryInGrid(liuCreatures,me,ZONE_LIU_FIGHT,100.0f);
                for(auto creature : liuCreatures)
                    creature->Respawn();

                minionDeads = 0;
            }

            uint32 minionDeads;

            void Reset()
            {
                me->CastSpell(me, SPELL_POSSESSED_BY_SHA, false);
                me->CastSpell(me, SPELL_DUST_VISUAL, false);

                _Reset();
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_YU_LON_DONE:
                    {
                        me->LowerPlayerDamageReq(me->GetHealth());
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        me->CastSpell(me, SPELL_TRANSFORM_VISUAL, false);
                        me->Kill(me);
                        instance->SetBossState(DATA_LIU_FLAMEHEART_EVENT, DONE);
                        break;
                    }
                    case ACTION_MINIONS_DEAD:
                    {
                        //make Liu Flameheart jump if all 3 adds are deads.
                        if (++minionDeads >= 3)
                        {
                            me->SetVisible(true);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                            Talk(TALK_INTRO_01);
                            me->GetMotionMaster()->MoveJump(929.68f, -2560.80f, 180.06f, 20, 40);
                            me->SetHomePosition(929.68f, -2560.80f, 180.06f, me->GetOrientation());
                        }
                        break;
                    }
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
                events.SetPhase(PHASE_1);
                events.ScheduleEvent(EVENT_SERPENT_STRIKE,  5000, PHASE_1);
                events.ScheduleEvent(EVENT_SERPENT_KICK,    5000, PHASE_1);

                _EnterCombat();
            }

            void DamageTaken(Unit* attacker, uint32& damage)
            {
                float healthPct = me->GetHealthPct();
                if (healthPct < 70.f && events.IsInPhase(PHASE_1))
                {
                    me->AddAura(SPELL_JADE_ESSENCE, me);

                    events.SetPhase(PHASE_2);
                    events.ScheduleEvent(EVENT_JADE_SERPENT_STRIKE, 5000,  PHASE_2);
                    events.ScheduleEvent(EVENT_JADE_SERPENT_KICK,   10000, PHASE_2);
                    Talk(TALK_EVENT_01);
                }
                else if (healthPct < 30.f && events.IsInPhase(PHASE_2))
                {
                    events.ScheduleEvent(EVENT_SUMMON_YULON, 500, PHASE_3);
                    Talk(TALK_EVENT_02);
                    events.SetPhase(PHASE_3);
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SERPENT_STRIKE:
                        case EVENT_JADE_SERPENT_STRIKE:
                        {
                            me->CastSpell(me->GetVictim(), eventId == EVENT_SERPENT_STRIKE ? SPELL_SERPENT_STRIKE: SPELL_JADE_SERPENT_STRIKE, false);
                            Map::PlayerList const& PlayerList = me->GetInstanceScript()->instance->GetPlayers();

                            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                            {
                                Player* player = i->GetSource();

                                if (!player)
                                    continue;

                                if (player->GetDistance2d(me) < 10.f)
                                    player->KnockbackFrom(me->GetPositionX(), me->GetPositionY(), 10, 10);
                            }

                            events.ScheduleEvent(eventId, 10000); // Re-schedule the same event
                            events.ScheduleEvent(eventId == EVENT_SERPENT_STRIKE ? EVENT_SERPENT_WAVE:   EVENT_JADE_SERPENT_WAVE, 4000);
                            break;
                        }
                        case EVENT_SERPENT_KICK:
                        case EVENT_JADE_SERPENT_KICK:
                        {
                            me->CastSpell(me->GetVictim(), eventId == EVENT_SERPENT_KICK ? SPELL_SERPENT_KICK: SPELL_JADE_SERPENT_KICK, false);
                            events.ScheduleEvent(eventId, 10000); // Re-schedule the same event
                            break;
                        }
                        case EVENT_SERPENT_WAVE:
                        case EVENT_JADE_SERPENT_WAVE:
                        {
                            for (uint8 i = 0; i < 4; ++i)
                            {
                                if (TempSummon* sum = me->SummonCreature(CREATURE_TRIGGER_WAVE, serpentWavePositions[i][0].GetPositionX(),
                                                                                                serpentWavePositions[i][0].GetPositionY(),
                                                                                                serpentWavePositions[i][0].GetPositionZ(),
                                                                                                serpentWavePositions[i][0].GetOrientation()))
                                {
                                    sum->SetDisplayId(11686);
                                    sum->CastSpell(sum, eventId == EVENT_SERPENT_WAVE ? SPELL_SERPENT_WAVE_VISUAL: SPELL_JADE_SERPENT_WAVE_VISUAL, false);
                                    sum->CastSpell(sum, SPELL_SERPENT_WAVE_PERIODIC, false);
                                    sum->GetMotionMaster()->MovePoint(0, serpentWavePositions[i][1].GetPositionX(),
                                                                         serpentWavePositions[i][1].GetPositionY(),
                                                                         serpentWavePositions[i][1].GetPositionZ());
                                    sum->DespawnOrUnsummon(3200);
                                }
                            }
                            break;
                        }
                        case EVENT_SUMMON_YULON:
                        {
                            me->CastSpell(me, SPELL_SUMMON_JADE_SERPENT, false);
                            me->CastSpell(me, SPELL_JADE_SOUL, false);
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            me->ApplySpellImmune(SPELL_JADE_SOUL, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, true);
                            me->ApplySpellImmune(SPELL_JADE_SOUL, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, true);
                            me->SetReactState(REACT_PASSIVE);
                            me->AddUnitState(UNIT_STATE_ROOT);
                            events.ScheduleEvent(EVENT_AURA_JADE, 3000);
                            break;
                        }
                        case EVENT_AURA_JADE:
                        {
                            me->CastSpell(me, SPELL_JADE_SOUL, false);
                            events.ScheduleEvent(EVENT_AURA_JADE, 2500);
                            break;
                        }
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

class boss_yu_lon : public CreatureScript
{
    public:
        boss_yu_lon() : CreatureScript("boss_yu_lon") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_yu_lon_AI(creature);
        }

        struct boss_yu_lon_AI : public ScriptedAI
        {
            boss_yu_lon_AI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;

            void Reset()
            {
                events.Reset();

                if (TempSummon* meTemp = me->ToTempSummon())
                    if (Unit* summoner = meTemp->GetSummoner())
                        if (Creature* liu = summoner->ToCreature())
                            me->SetHealth(liu->GetHealth());
            }

            void EnterCombat(Unit* unit)
            {
                events.ScheduleEvent(EVENT_JADE_FIRE, 100);
            }

            void JustDied(Unit* died)
            {
                // Todo : He should not die
                me->CastSpell(me, 132387, false);

                Creature* liu = me->GetMap()->GetCreature(GetGUID(me->GetInstanceScript()->GetData64(CREATURE_LIU_FLAMEHEART)));
                if (liu && liu->GetAI())
                    liu->GetAI()->DoAction(ACTION_YU_LON_DONE);
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_JADE_FIRE:
                        {
                            if (Unit* victim = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(victim, SPELL_JADE_FIRE, false);
                            events.ScheduleEvent(EVENT_JADE_FIRE, 1700);
                            break;
                        }
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
            mob_trigger_liu_flameheart_AI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;

            void Reset()
            {
                events.ScheduleEvent(1, 500);
            }

            void UpdateAI(uint32 diff)
            {
                events.Update(diff);

                while(uint32 eventId = events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        case 1:
                        {
                            Creature* liu = me->GetMap()->GetCreature(GetGUID(me->GetInstanceScript()->GetData64(CREATURE_LIU_FLAMEHEART)));
                            if(liu && liu->HealthBelowPct(70))
                                me->CastSpell(me, 107103, false);
                            events.ScheduleEvent(1, 1000);
                            break;
                        }
                    }
                }
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
            mob_minion_of_doubt_AI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;

            void EnterCombat(Unit* unit)
            {
                events.ScheduleEvent(1, 2000);
                events.ScheduleEvent(2, 4000);
            }

            void JustDied(Unit* killer)
            {
                Creature* liu = me->GetMap()->GetCreature(GetGUID(me->GetInstanceScript()->GetData64(CREATURE_LIU_FLAMEHEART)));

                if(liu && liu->GetAI())
                    liu->GetAI()->DoAction(ACTION_MINIONS_DEAD);
            }

            void UpdateAI(uint32 diff)
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
                            me->CastSpell(me->GetVictim(), 110099, false);
                            events.ScheduleEvent(1, 5000);
                            break;
                        case 2:
                            me->CastSpell(me->GetVictim(), 110125, false);
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
            mob_lesser_sha_AI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;

            void Reset()
            {
                events.Reset();
            }

            void EnterCombat(Unit* unit)
            {
                events.ScheduleEvent(1, 2000);
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case 1:
                            me->CastSpell(me->GetVictim(), 122527, false);
                            events.ScheduleEvent(1, 5000);
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };
};

class mob_jade_fire: public CreatureScript
{
public:
    mob_jade_fire() : CreatureScript("mob_jade_fire") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_jade_fire_AI(creature);
    }

    struct mob_jade_fire_AI : public ScriptedAI
    {
        mob_jade_fire_AI(Creature* creature) : ScriptedAI(creature) { }

        void Reset()
        {
            me->SetReactState(REACT_PASSIVE);
            me->CastSpell(me, 107108, true);
            me->DespawnOrUnsummon(5000);
        }
    };
};


void AddSC_boss_liu_flameheat()
{
    new boss_liu_flameheart();
    new boss_yu_lon();
    new mob_trigger_liu_flameheart();
    //Trashes
    new mob_minion_of_doubt();
    new mob_lesser_sha();
    new mob_jade_fire();
}
