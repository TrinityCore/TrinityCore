/*
    Dungeon : Mogu'shan palace 87-89
    Trial of the king
    Jade servers
    */

#include "CreatureAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "mogu_shan_palace.h"

#define SPELL_GUARDIAN_GRUNT 85667

enum eBosses
{
    BOSS_MING_THE_CUNNING,
    BOSS_KUAI_THE_BRUTE,
    BOSS_HAIYAN_THE_UNSTOPPABLE,
};

class mob_xian_the_weaponmaster_trigger : public CreatureScript
{
    public:
    mob_xian_the_weaponmaster_trigger() : CreatureScript("mob_xian_the_weaponmaster_trigger")
    { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_xian_the_weaponmaster_trigger_AI(creature);
    }

    enum eEvents
    {
        EVENT_TALK_0 = 1,
        EVENT_TALK_1 = 2,
        EVENT_JUMP_XIAN = 3,
        EVENT_DISAPPEAR = 4
    };

    enum eSpells
    {
        SPELL_MOGU_JUMP = 120444,
    };

    enum eTalks
    {
        TALK_INTRO_01,
        TALK_INTRO_02,
    };

    struct mob_xian_the_weaponmaster_trigger_AI : public ScriptedAI
    {
        mob_xian_the_weaponmaster_trigger_AI(Creature* creature) : ScriptedAI(creature)
        {
            event_go = false;
        }
        EventMap events;
        bool event_go;

        void Reset()
        {
            event_go = false;
            me->GetMotionMaster()->MoveTargetedHome();
            //SetCanSeeEvenInPassiveMode(true);
        }

        void MoveInLineOfSight(Unit* who)
        {
            // If Lorewalker stonestep sees a player, launch the speech.
            if (!event_go && who->GetTypeId() == TYPEID_PLAYER && who->GetAreaId() == 6471)//Salle de l'assemblée cramoisie
            {
                if (me->GetInstanceScript())
                    me->GetInstanceScript()->SetData(TYPE_MING_INTRO, 0);
                event_go = true;
                events.ScheduleEvent(EVENT_TALK_0, 3000);
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_TALK_0:
                        Talk(TALK_INTRO_01);
                        me->GetMotionMaster()->MovePoint(0, -4220.277f, -2600.117f, 16.47f);
                        events.ScheduleEvent(EVENT_TALK_1, 4000);
                        break;
                    case EVENT_TALK_1:
                        me->GetMotionMaster()->MovePoint(0, -4229.333f, -2624.051f, 16.47f);
                        events.ScheduleEvent(EVENT_JUMP_XIAN, 7000);
                        break;
                    case EVENT_JUMP_XIAN:
                        Talk(TALK_INTRO_02);
                        me->GetMotionMaster()->MoveJump(-4296.391f, -2613.577f, 22.325f, 30.f, 20.f);
                        events.ScheduleEvent(EVENT_DISAPPEAR, 5000);
                        break;
                    case EVENT_DISAPPEAR:
                        me->CastSpell(me, SPELL_MOGU_JUMP, false);
                        if (me->GetInstanceScript())
                            me->GetInstanceScript()->SetData(TYPE_MING_ATTACK, 0);
                        me->SetVisible(false);
                        break;
                }
            }
        }
    };
};

class boss_ming_the_cunning : public CreatureScript
{
    public:
    boss_ming_the_cunning() : CreatureScript("boss_ming_the_cunning")
    { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_ming_the_cunning_AI(creature);
    }

    enum eEvents
    {
        EVENT_LIGHTNING_BOLT = 1,
        EVENT_WHIRLING_DERVISH = 2,
        EVENT_MAGNETIC_FIELD = 3,
        EVENT_BOSS_RETIRE = 4,

        EVENT_INTRO = 5,
        EVENT_OUTRO_01 = 6,
        EVENT_OUTRO_02 = 7,
    };

    enum eSpells
    {
        SPELL_LIGHTNING_BOLT = 123654,
        SPELL_WHIRLING_DERVISH = 119981,
        SPELL_MAGNETIC_FIELD = 120100,
        SPELL_MAGNETIC_FIELD_2 = 120101,
        SPELL_MAGNETIC_FIELD_3 = 120099,
    };

    enum eTalks
    {
        TALK_INTRO,
        TALK_AGGRO,
        TALK_DEFEATED,
        TALK_KILLING,
        TALK_OUTRO_01,
        TALK_OUTRO_02,
    };

    enum eActions
    {
        ACTION_INTRO,
        ACTION_OUTRO_01,
        ACTION_OUTRO_02,
    };

    struct boss_ming_the_cunning_AI : public BossAI
    {
        boss_ming_the_cunning_AI(Creature* creature) : BossAI(creature, BOSS_MING_THE_CUNNING)
        {
            magnetic_timer = 1000;
        }
        uint32 magnetic_timer;

        void Reset()
        {
            if (me->GetInstanceScript())
                me->GetInstanceScript()->SetData(TYPE_WIPE_FIRST_BOSS, 0);
            me->GetMotionMaster()->MoveTargetedHome();
            _Reset();
        }

        void EnterCombat(Unit* unit)
        {
            Talk(TALK_AGGRO);
            me->CastSpell(me, SPELL_GUARDIAN_GRUNT, false);
            events.ScheduleEvent(EVENT_LIGHTNING_BOLT, 3000);
            events.ScheduleEvent(EVENT_WHIRLING_DERVISH, 10000);
            events.ScheduleEvent(EVENT_MAGNETIC_FIELD, 30000);
        }

        void KilledUnit(Unit* u)
        {
            Talk(TALK_KILLING);
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
                case ACTION_INTRO:
                    Talk(TALK_INTRO);
                    break;
                case ACTION_OUTRO_01:
                    Talk(TALK_OUTRO_01);
                    events.ScheduleEvent(EVENT_OUTRO_01, 3000);
                    break;
                case ACTION_OUTRO_02:
                    Talk(TALK_OUTRO_02);
                    events.ScheduleEvent(EVENT_OUTRO_02, 3000);
                    break;
            }
        }

        void DamageTaken(Unit* killer, uint32 &damage)
        {
            //We need to retire Ming and let the next boss enter combat.
            if (int(me->GetHealth()) - int(damage) <= 0)
            {
                Talk(TALK_DEFEATED);
                damage = 0;
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                me->GetMotionMaster()->MoveTargetedHome();
                me->AttackStop();
                events.Reset();
                events.ScheduleEvent(EVENT_BOSS_RETIRE, 4000);
                if (me->GetInstanceScript())
                    me->GetInstanceScript()->SetData(TYPE_MING_RETIRED, 0);
            }
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasAura(SPELL_MAGNETIC_FIELD))
            {
                if (magnetic_timer <= diff)
                {
                    //Grip the players
                    Map::PlayerList const& PlayerList = me->GetMap()->GetPlayers();
                    if (!PlayerList.isEmpty())
                    {
                        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                        {
                            Player* plr = i->GetSource();
                            if (!plr)
                                continue;
                            if (plr->GetDistance2d(me) <= 5.f)
                                plr->GetMotionMaster()->MoveJump(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 25.0f, 10.f);
                        }
                    }
                    magnetic_timer = 1000;
                }
                else
                    magnetic_timer -= diff;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_OUTRO_02:
                        if (me->GetInstanceScript())
                            me->GetInstanceScript()->SetData(TYPE_OUTRO_04, 0);
                        break;
                    case EVENT_OUTRO_01:
                        if (me->GetInstanceScript())
                            me->GetInstanceScript()->SetData(TYPE_OUTRO_02, 0);
                        break;
                    case EVENT_LIGHTNING_BOLT:
                        if (!me->HasAura(SPELL_MAGNETIC_FIELD))
                            me->CastSpell(me->GetVictim(), SPELL_LIGHTNING_BOLT, false);
                        events.ScheduleEvent(EVENT_LIGHTNING_BOLT, 6000);
                        break;
                    case EVENT_WHIRLING_DERVISH:
                        if (!me->HasAura(SPELL_MAGNETIC_FIELD))
                            me->CastSpell(me, SPELL_WHIRLING_DERVISH, false);
                        events.ScheduleEvent(EVENT_WHIRLING_DERVISH, 10000);
                        break;
                    case EVENT_MAGNETIC_FIELD:
                    {
                        me->CastSpell(me, SPELL_MAGNETIC_FIELD, false);
                        events.ScheduleEvent(EVENT_MAGNETIC_FIELD, 30000);
                    }
                    break;
                    case EVENT_BOSS_RETIRE:
                        if (me->GetInstanceScript())
                            me->GetInstanceScript()->SetData(TYPE_KUAI_ATTACK, 0);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class mob_whirling_dervish : public CreatureScript
{
    public:
    mob_whirling_dervish() : CreatureScript("mob_whirling_dervish")
    { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_whirling_dervish_AI(creature);
    }

    enum eSpells
    {
        SPELL_WIRHLING_DERVISH_2 = 119982,
        SPELL_WHIRLING_DERVISH_3 = 119994,
        SPELL_THROW = 120087,
        SPELL_THROW_2 = 120035,
    };

    struct mob_whirling_dervish_AI : public ScriptedAI
    {
        mob_whirling_dervish_AI(Creature* creature) : ScriptedAI(creature)
        {
            me->CastSpell(me, SPELL_WIRHLING_DERVISH_2, false);
            me->DespawnOrUnsummon(10000);
        }
        EventMap events;

        void EnterCombat(Unit* unit)
        {
            events.ScheduleEvent(1, 2000);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->GetVictim() && me->GetVictim()->GetDistance2d(me) > 5.0f)
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case 1:
                        me->CastSpell(me->GetVictim(), SPELL_THROW, false);
                        me->CastSpell(me->GetVictim(), SPELL_THROW_2, false);
                        me->Attack(SelectTarget(SELECT_TARGET_RANDOM), false);
                        events.ScheduleEvent(1, 3000);
                        break;
                }
            }
        }
    };
};

class mob_adepts : public CreatureScript
{
    public:
    mob_adepts() : CreatureScript("mob_adepts")
    { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_adepts_AI(creature);
    }

    enum eEvents
    {
        EVENT_APPLAUSE = 1,
        EVENT_TALK = 2,
    };

    enum eActions
    {
        ACTION_ENCOURAGE,
        ACTION_RETIRE,
        ACTION_ATTACK,
    };

    enum eStatus
    {
        STATUS_ATTACK_PLAYER,
        STATUS_ATTACK_GRUNTS,
    };

    enum eTalks
    {
        TALK_00,
        TALK_01,
        TALK_02,
        TALK_03,
        TALK_04,
    };

    struct mob_adepts_AI : public ScriptedAI
    {
        mob_adepts_AI(Creature* creature) : ScriptedAI(creature)
        {
            status = STATUS_ATTACK_PLAYER;
            me->SetReactState(REACT_AGGRESSIVE);
            me->setFaction(16);
        }
        EventMap events;
        uint8 status;

        void DoAction(int32 action)
        {
            switch (action)
            {
                case ACTION_ENCOURAGE:
                {
                    float x, y;
                    //GetPositionWithDistInOrientation(me, 5.0f, me->GetOrientation(), x, y);
                    me->GetMotionMaster()->MovePoint(0, x, y, me->GetMap()->GetHeight(0, x, y, me->GetPositionZ()));

                    me->CastSpell(me, 120867, false);
                    events.ScheduleEvent(EVENT_APPLAUSE + urand(0, 1), 500 + urand(500, 1500));
                    break;
                }
                case ACTION_RETIRE:
                {
                    float x, y;
                    //GetPositionWithDistInOrientation(me, -5.0f, me->GetOrientation(), x, y);
                    me->GetMotionMaster()->MovePoint(1, x, y, me->GetMap()->GetHeight(0, x, y, me->GetPositionZ()));

                    me->RemoveAura(120867);
                    me->CastSpell(me, 121569, false);
                    events.Reset();
                    break;
                }
                case ACTION_ATTACK:
                {
                    status = STATUS_ATTACK_GRUNTS;

                    float x, y;
                    //GetPositionWithDistInOrientation(me, 30.0f, me->GetOrientation(), x, y);
                    me->GetMotionMaster()->MovePoint(0, x, y, me->GetMap()->GetHeight(0, x, y, me->GetPositionZ()));

                    me->RemoveAura(121569);
                    events.Reset();
                    break;
                }
            }
        }

        void MovementInform(uint32 motionType, uint32 pointId)
        {
            if (pointId == 1)
                me->SetFacingTo(me->GetOrientation() - M_PI);
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (InstanceScript* lel = me->GetInstanceScript())
                if (lel->GetData(TYPE_HAIYAN_RETIRED) == 0 && lel->GetData(TYPE_KUAI_RETIRED) == 0 && lel->GetData(TYPE_MING_RETIRED) == 0)
                    return;

            if (who->GetTypeId() == TYPEID_PLAYER && who->GetAreaId() == 6471//Salle de l'assemblée cramoisie
                && me->GetDistance2d(who) < 2.0f
                && who->isInFront(me)
                && status != STATUS_ATTACK_GRUNTS)
            {
                me->CastSpell(who, 120035, false);
                me->AttackStop();
                Talk(TALK_00 + urand(0, 4));
            }
        }

        void UpdateAI(uint32 diff)
        {
            if (status == STATUS_ATTACK_GRUNTS && me->GetVictim() && me->GetVictim()->ToPlayer())
                me->AttackStop();

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_TALK:
                        events.ScheduleEvent(EVENT_APPLAUSE + urand(0, 1), 5000 + urand(500, 1500));
                        break;
                }
            }
        }
    };
};

class boss_kuai_the_brute : public CreatureScript
{
    public:
    boss_kuai_the_brute() : CreatureScript("boss_kuai_the_brute")
    { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_kuai_the_brute_AI(creature);
    }

    enum eEvents
    {
        EVENT_SHOCKWAVE = 1,
        EVENT_BOSS_RETIRE = 2,
        EVENT_SHOCKWAVE_2 = 3,

        EVENT_OUTRO_01 = 4,
        EVENT_OUTRO_02 = 5,
    };

    enum eCreatures
    {
        CREATURE_MU_SHIBA = 61453,
    };

    enum eSpells
    {
        SPELL_SHOCKWAVE = 119922,
        SPELL_PICK_SHOCKWAVE_TARGET = 120499,
        SPELL_SHOCKWAVE_2 = 119929,
        SPELL_SHOCKWAVE_3 = 119930,
        SPELL_SHOCKWAVE_4 = 119931,
        SPELL_SHOCKWAVE_5 = 119932,
        SPELL_SHOCKWAVE_6 = 119933,
    };

    enum eActions
    {
        ACTION_ATTACK,
        ACTION_ATTACK_STOP,
        ACTION_OUTRO_01,
        ACTION_OUTRO_02,
    };

    enum eTalks
    {
        TALK_AGGRO,
        TALK_DEFEATED,
        TALK_KILLING,
        TALK_OUTRO_01,
        TALK_OUTRO_02,
    };

    struct boss_kuai_the_brute_AI : public BossAI
    {
        boss_kuai_the_brute_AI(Creature* creature) : BossAI(creature, BOSS_KUAI_THE_BRUTE)
        {
            TempSummon* sum = me->SummonCreature(CREATURE_MU_SHIBA, me->GetPositionX() + 3 * cos(M_PI / 4), me->GetPositionY() + 3 * sin(M_PI / 4), me->GetPositionZ(), me->GetOrientation());
            if (sum)
            {
                pet_guid = sum->GetGUID();
                sum->setFaction(me->getFaction());
            }
        }
        uint64 pet_guid;

        void Reset()
        {
            if (me->GetInstanceScript())
                me->GetInstanceScript()->SetData(TYPE_WIPE_FIRST_BOSS, 1);
            me->GetMotionMaster()->MoveTargetedHome();
            _Reset();
        }

        void KilledUnit(Unit* u)
        {
            Talk(TALK_KILLING);
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
                case ACTION_OUTRO_01:
                    Talk(TALK_OUTRO_01);
                    events.ScheduleEvent(EVENT_OUTRO_01, 3000);
                    break;
                case ACTION_OUTRO_02:
                    Talk(TALK_OUTRO_02);
                    events.ScheduleEvent(EVENT_OUTRO_02, 3000);
                    break;
            }
        }

        void EnterCombat(Unit* unit)
        {
            Talk(TALK_AGGRO);
            events.ScheduleEvent(EVENT_SHOCKWAVE, 3000);

            if (Creature* mu_shiba = me->GetMap()->GetCreature(instance->GetObjectGuid(pet_guid)))
                mu_shiba->AI()->DoAction(ACTION_ATTACK);
        }

        void DamageTaken(Unit* killer, uint32 &damage)
        {
            //We need to retire Ming and let the next boss enter combat.
            if (int(me->GetHealth()) - int(damage) <= 0)
            {
                Talk(TALK_DEFEATED);
                damage = 0;
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                me->GetMotionMaster()->MoveTargetedHome();
                me->AttackStop();
                events.Reset();
                events.ScheduleEvent(EVENT_BOSS_RETIRE, 4000);
                if (me->GetInstanceScript())
                    me->GetInstanceScript()->SetData(TYPE_KUAI_RETIRED, 0);

                Creature* mu_shiba = me->GetMap()->GetCreature(instance->GetObjectGuid(pet_guid));
                if (mu_shiba && mu_shiba->IsAlive())
                {
                    mu_shiba->GetMotionMaster()->MoveFollow(me, 2.0f, M_PI / 4);
                    if (mu_shiba->GetAI())
                        mu_shiba->GetAI()->DoAction(ACTION_ATTACK_STOP);
                }
            }
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_OUTRO_02:
                        if (me->GetInstanceScript())
                            me->GetInstanceScript()->SetData(TYPE_OUTRO_05, 0);
                        break;
                    case EVENT_OUTRO_01:
                        if (me->GetInstanceScript())
                            me->GetInstanceScript()->SetData(TYPE_OUTRO_01, 0);
                        break;
                    case EVENT_SHOCKWAVE:
                    {
                        me->CastSpell(me->GetVictim(), SPELL_SHOCKWAVE, false);
                        me->AddUnitState(UNIT_STATE_CANNOT_TURN);
                        events.ScheduleEvent(EVENT_SHOCKWAVE, 15000);
                        events.ScheduleEvent(EVENT_SHOCKWAVE_2, 4000);
                    }
                    break;
                    case EVENT_BOSS_RETIRE:
                        if (me->GetInstanceScript())
                            me->GetInstanceScript()->SetData(TYPE_HAIYAN_ATTACK, 0);
                        DoAction(ACTION_OUTRO_01);
                        break;
                    case EVENT_SHOCKWAVE_2:
                        me->ClearUnitState(UNIT_STATE_CANNOT_TURN);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class mob_mu_shiba : public CreatureScript
{
    public:
    mob_mu_shiba() : CreatureScript("mob_mu_shiba")
    { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_mu_shiba_AI(creature);
    }

    enum eSpells
    {
        SPELL_RAVAGE = 119948,
    };

    enum eActions
    {
        ACTION_ATTACK,
        ACTION_ATTACK_STOP,
    };

    struct mob_mu_shiba_AI : public ScriptedAI
    {
        mob_mu_shiba_AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
        }
        EventMap events;

        void Reset()
        {
            DoAction(ACTION_ATTACK_STOP);
        }

        void EnterCombat(Unit* unit)
        {
            events.ScheduleEvent(1, 2000);
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
                case ACTION_ATTACK:
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                    DoZoneInCombat();

                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        AttackStart(target);
                    break;
                case ACTION_ATTACK_STOP:
                    events.Reset();
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                    break;
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
                    case 1:
                        me->CastSpell(me->GetVictim(), SPELL_RAVAGE, false);
                        me->Attack(SelectTarget(SELECT_TARGET_RANDOM), false);
                        events.ScheduleEvent(1, 25000);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class boss_haiyan_the_unstoppable : public CreatureScript
{
    public:
    boss_haiyan_the_unstoppable() : CreatureScript("boss_haiyan_the_unstoppable")
    { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_haiyan_the_unstoppable_AI(creature);
    }

    enum eEvents
    {
        EVENT_TRAUMATIC_BLOW = 1,
        EVENT_CONFLAGRATE = 2,
        EVENT_METEOR = 3,
        EVENT_BOSS_RETIRE = 4,
        EVENT_CONFLAGRATE_2 = 5,

        EVENT_OUTRO_01 = 6,
    };

    enum eSpells
    {
        SPELL_TRAUMATIC_BLOW = 123655,
        SPELL_CONFLAGRATE = 120160,
        SPELL_CONFLAGRATE_2 = 120167,
        SPELL_CONFLAGRATE_3 = 120161,
        SPELL_CONFLAGRATE_4 = 120201,
        SPELL_METEOR = 120195,
        SPELL_METEOR_2 = 120194,
        SPELL_METEOR_3 = 120196,
    };

    enum eTalks
    {
        TALK_AGGRO,
        TALK_DEFEATED,
        TALK_KILLING,
        TALK_OUTRO_01,
        TALK_OUTRO_02,
    };

    enum eActions
    {
        ACTION_OUTRO_01,
        ACTION_OUTRO_02,
    };

    struct boss_haiyan_the_unstoppable_AI : public BossAI
    {
        boss_haiyan_the_unstoppable_AI(Creature* creature) : BossAI(creature, BOSS_HAIYAN_THE_UNSTOPPABLE)
        { }

        void EnterCombat(Unit* unit)
        {
            Talk(TALK_AGGRO);
            events.ScheduleEvent(EVENT_TRAUMATIC_BLOW, 3000);
            events.ScheduleEvent(EVENT_CONFLAGRATE, 10000);
            events.ScheduleEvent(EVENT_METEOR, 30000);
        }

        void Reset()
        {
            if (me->GetInstanceScript())
                me->GetInstanceScript()->SetData(TYPE_WIPE_FIRST_BOSS, 2);
            me->GetMotionMaster()->MoveTargetedHome();
            _Reset();
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
                case ACTION_OUTRO_01:
                    Talk(TALK_OUTRO_01);
                    events.ScheduleEvent(EVENT_OUTRO_01, 3000);
                    break;
                case ACTION_OUTRO_02:
                    Talk(TALK_OUTRO_02);
                    break;
            }
        }

        void KilledUnit(Unit* u)
        {
            Talk(TALK_KILLING);
        }

        void DamageTaken(Unit* killer, uint32 &damage)
        {
            //We need to retire Ming and let the next boss enter combat.
            if (int(me->GetHealth()) - int(damage) <= 0)
            {
                Talk(TALK_DEFEATED);
                damage = 0;
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                me->GetMotionMaster()->MoveTargetedHome();
                me->AttackStop();
                events.Reset();
                events.ScheduleEvent(EVENT_BOSS_RETIRE, 4000);
                if (me->GetInstanceScript())
                    me->GetInstanceScript()->SetData(TYPE_HAIYAN_RETIRED, 0);
            }
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_OUTRO_01:
                        if (me->GetInstanceScript())
                            me->GetInstanceScript()->SetData(TYPE_OUTRO_03, 0);
                        break;
                    case EVENT_TRAUMATIC_BLOW:
                        me->CastSpell(me->GetVictim(), SPELL_TRAUMATIC_BLOW, false);
                        events.ScheduleEvent(EVENT_TRAUMATIC_BLOW, 6000);
                        break;
                    case EVENT_CONFLAGRATE:
                        me->CastSpell(me->GetVictim(), SPELL_CONFLAGRATE, false);
                        events.ScheduleEvent(EVENT_CONFLAGRATE, 10000);
                        events.ScheduleEvent(EVENT_CONFLAGRATE_2, 2000);
                        break;
                    case EVENT_METEOR:
                        me->CastSpell(SelectTarget(SELECT_TARGET_RANDOM), SPELL_METEOR, false);
                        events.ScheduleEvent(EVENT_METEOR, 30000);
                        break;
                    case EVENT_BOSS_RETIRE:
                        if (me->GetInstanceScript())
                            me->GetInstanceScript()->SetData(TYPE_ALL_ATTACK, 0);
                        break;
                    case EVENT_CONFLAGRATE_2:
                        me->CastSpell(me->GetVictim(), SPELL_CONFLAGRATE_4, false);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_trial_of_the_king()
{
    new mob_xian_the_weaponmaster_trigger();
    new boss_ming_the_cunning();
    new mob_whirling_dervish();
    new mob_adepts();
    new boss_kuai_the_brute();
    new mob_mu_shiba();
    new boss_haiyan_the_unstoppable();
}
