#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Misc
{
    // Quests
    QUEST_SEWER_CLEANING        = 80017,

    SUNREAVER_KILL_CREDIT       = 100062,

    SAY_BRASAEL_AGGRO           = 0,
};

enum Spells
{
    // Assassin
	SPELL_SINISTER_STRIKE		= 59409,
	SPELL_KIDNEY_SHOT			= 72335,

    // Duelist
    SPELL_MIGHTY_KICK           = 69021,

    // Pyromancer
    SPELL_FIRE_ARMOR            = 43046,
    SPELL_FIREBALL              = 100003,
    SPELL_FIREBLAST             = 100004,
    SPELL_PYROBLAST             = 100005,

    // Forsthand
    SPELL_FROST_ARMOR           = 43008,
    SPELL_FROSTBOLT             = 100006,
    SPELL_ICE_LANCE             = 100007,
    SPELL_FROST_CONE            = 65023,

    // Brasael
    SPELL_SCORCH                = 100055,
    SPELL_METEOR                = 100054,
    SPELL_DRAGON_BREATH         = 37289,
    SPELL_POSTCOMBUSTION        = 59183
};

enum Casting
{
    // Assassin
    CASTING_SINISTER_STRIKE		= 1,
	CASTING_KIDNEY_SHOT			= 2,

    // Duelist
    CASTING_MIGHTY_KICK         = 1,

    // Pyromancer
    CASTING_FIREBALL            = 1,
	CASTING_FIREBLAST           = 2,
	CASTING_PYROBLAST           = 3,

    // Forsthand
    CASTING_FROSTBOLT           = 1,
	CASTING_ICE_LANCE           = 2,
	CASTING_FROST_CONE          = 3,

    // Brasael
    CASTING_SCORCH              = 1,
    CASTING_METEOR              = 2,
    CASTING_DRAGON_BREATH       = 3,
    CASTING_POSTCOMBUSTION      = 4
};

void KillCredit(Unit* killer)
{
    if (killer->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* player = killer->ToPlayer();
    if (player && player->GetQuestStatus(QUEST_SEWER_CLEANING) == QUEST_STATUS_INCOMPLETE)
        player->KilledMonsterCredit(SUNREAVER_KILL_CREDIT);
}

class npc_sunreaver_assassin : public CreatureScript
{
    public:
    npc_sunreaver_assassin() : CreatureScript("npc_sunreaver_assassin") {}

    struct npc_sunreaver_assassinAI : public ScriptedAI
    {
        npc_sunreaver_assassinAI(Creature* creature) : ScriptedAI(creature) {}

        void JustEngagedWith(Unit* /*who*/) override
        {
            events.ScheduleEvent(CASTING_SINISTER_STRIKE, 5s);
            events.ScheduleEvent(CASTING_KIDNEY_SHOT, 10s);
        }

        void JustDied(Unit* killer) override
        {
            KillCredit(killer);
        }

        void Reset() override
        {
            events.Reset();
        }

        void UpdateAI(uint32 diff) override
        {
            // Combat
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case CASTING_SINISTER_STRIKE:
                        DoCast(SPELL_SINISTER_STRIKE);
                        events.RescheduleEvent(CASTING_SINISTER_STRIKE, 14s, 28s);
                        break;

                    case CASTING_KIDNEY_SHOT:
                        if (Unit * target = SelectTarget(SELECT_TARGET_MINTHREAT, 0))
                            DoCast(target, SPELL_KIDNEY_SHOT);
                        events.RescheduleEvent(CASTING_KIDNEY_SHOT, 32s, 60s);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature * creature) const override
    {
        return new npc_sunreaver_assassinAI(creature);
    }
};

class npc_sunreaver_duelist : public CreatureScript
{
    public:
    npc_sunreaver_duelist() : CreatureScript("npc_sunreaver_duelist") {}

    struct npc_sunreaver_duelistAI : public ScriptedAI
    {
        npc_sunreaver_duelistAI(Creature* creature) : ScriptedAI(creature) {}

        void JustEngagedWith(Unit* /*who*/) override
        {
            events.ScheduleEvent(CASTING_MIGHTY_KICK, 5s);
        }

        void JustDied(Unit* killer) override
        {
            KillCredit(killer);
        }

        void Reset() override
        {
            events.Reset();
        }

        void UpdateAI(uint32 diff) override
        {
            // Combat
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case CASTING_MIGHTY_KICK:
                        DoCast(SPELL_MIGHTY_KICK);
                        events.RescheduleEvent(CASTING_MIGHTY_KICK, 14s, 28s);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sunreaver_duelistAI(creature);
    }
};

class npc_sunreaver_pyromancer : public CreatureScript
{
    public:
    npc_sunreaver_pyromancer() : CreatureScript("npc_sunreaver_pyromancer") {}

    struct npc_sunreaver_pyromancerAI : public ScriptedAI
    {
        npc_sunreaver_pyromancerAI(Creature* creature) : ScriptedAI(creature) {}

        void JustEngagedWith(Unit* /*who*/) override
        {
            events.ScheduleEvent(CASTING_FIREBALL, 5s);
            events.ScheduleEvent(CASTING_FIREBLAST, 14s);
            events.ScheduleEvent(CASTING_PYROBLAST, 20s);
        }

        void JustDied(Unit* killer) override
        {
            KillCredit(killer);
        }

        void Reset() override
        {
            events.Reset();

            DoCastSelf(SPELL_FIRE_ARMOR);
        }

        void UpdateAI(uint32 diff) override
        {
            // Combat
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case CASTING_FIREBALL:
                        DoCast(SPELL_FIREBALL);
                        events.RescheduleEvent(CASTING_FIREBALL, 5s, 8s);
                        break;

                    case CASTING_FIREBLAST:
                        if (Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_FIREBLAST);
                        events.RescheduleEvent(CASTING_FIREBLAST, 14s, 28s);
                        break;

                    case CASTING_PYROBLAST:
                        DoCast(SPELL_PYROBLAST);
                        events.RescheduleEvent(CASTING_PYROBLAST, 18s, 30s);
                        break;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }

            DoMeleeAttackIfReady();
        }

        private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sunreaver_pyromancerAI(creature);
    }
};

class npc_sunreaver_frosthand : public CreatureScript
{
    public:
    npc_sunreaver_frosthand() : CreatureScript("npc_sunreaver_frosthand") {}

    struct npc_sunreaver_frosthandAI : public ScriptedAI
    {
        npc_sunreaver_frosthandAI(Creature* creature) : ScriptedAI(creature) {}

        void JustEngagedWith(Unit* /*who*/) override
        {
            events.ScheduleEvent(CASTING_FROSTBOLT, 5s);
            events.ScheduleEvent(CASTING_ICE_LANCE, 14s);
            events.ScheduleEvent(CASTING_FROST_CONE, 20s);
        }

        void JustDied(Unit* killer) override
        {
            KillCredit(killer);
        }

        void Reset() override
        {
            events.Reset();

            DoCastSelf(SPELL_FROST_ARMOR);
        }

        void UpdateAI(uint32 diff) override
        {
            // Combat
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case CASTING_FROSTBOLT:
                        DoCast(SPELL_FROSTBOLT);
                        events.RescheduleEvent(CASTING_FROSTBOLT, 5s, 8s);
                        break;

                    case CASTING_ICE_LANCE:
                        if (Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_ICE_LANCE);
                        events.RescheduleEvent(CASTING_ICE_LANCE, 14s, 28s);
                        break;

                    case CASTING_FROST_CONE:
                        DoCast(SPELL_FROST_CONE);
                        events.RescheduleEvent(CASTING_FROST_CONE, 18s, 30s);
                        break;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }

            DoMeleeAttackIfReady();
        }

        private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sunreaver_frosthandAI(creature);
    }
};

class npc_magister_brasael : public CreatureScript
{
    public:
    npc_magister_brasael() : CreatureScript("npc_magister_brasael") {}

    struct npc_magister_brasaelAI : public ScriptedAI
    {
        npc_magister_brasaelAI(Creature* creature) : ScriptedAI(creature), phase(1) { }

        void JustEngagedWith(Unit* /*who*/) override
        {
            Talk(SAY_BRASAEL_AGGRO);

            events.ScheduleEvent(CASTING_SCORCH, 5s);
            events.ScheduleEvent(CASTING_DRAGON_BREATH, 14s);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
        {
            if (phase != 2 && HealthBelowPct(50))
            {
                phase = 2;

                events.CancelEvent(CASTING_DRAGON_BREATH);
                events.ScheduleEvent(CASTING_POSTCOMBUSTION, 1s);
                events.ScheduleEvent(CASTING_METEOR, 5s);
            }
        }

        void JustDied(Unit* killer) override
        {
            KillCredit(killer);
        }

        void Reset() override
        {
            events.Reset();

            DoCastSelf(SPELL_FIRE_ARMOR);

            phase = 1;
        }

        void UpdateAI(uint32 diff) override
        {
            // Combat
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case CASTING_SCORCH:
                        DoCast(SPELL_SCORCH);
                        events.RescheduleEvent(CASTING_SCORCH, 5s, 8s);
                        break;

                    case CASTING_DRAGON_BREATH:
                        DoCast(SPELL_DRAGON_BREATH);
                        events.RescheduleEvent(CASTING_DRAGON_BREATH, 14s, 28s);
                        break;

                    case CASTING_POSTCOMBUSTION:
                        DoCastSelf(SPELL_POSTCOMBUSTION);
                        events.RescheduleEvent(CASTING_POSTCOMBUSTION, 20s, 28s);
                        break;

                    case CASTING_METEOR:
                        DoCastVictim(SPELL_METEOR);
                        events.RescheduleEvent(CASTING_METEOR, 30s, 48s);
                        break;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }

            DoMeleeAttackIfReady();
        }

        private:
        EventMap events;
        uint8 phase;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_magister_brasaelAI(creature);
    }
};

void AddSC_npcs_sunreaver()
{
    new npc_sunreaver_assassin();
    new npc_sunreaver_duelist();
    new npc_sunreaver_pyromancer();
    new npc_sunreaver_frosthand();
    new npc_magister_brasael();
}
