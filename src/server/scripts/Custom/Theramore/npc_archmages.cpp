#include "ScriptMgr.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "SpellInfo.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "CreatureAIImpl.h"
#include <iostream>

enum Spells
{
    SPELL_FIREBALL          = 100003,
    SPELL_FIREBLAST         = 100004,
    SPELL_PYROBLAST         = 100005,

    SPELL_FROSTBOLT         = 100006,
    SPELL_ICE_LANCE         = 100007,
    SPELL_ICE_BLOCK         = 100008,
    SPELL_HYPOTHERMIA       = 41425,
    SPELL_BLINK             = 57869,

    SPELL_ARCANE_BARRAGE    = 100009,
    SPELL_ARCANE_BLAST      = 100010,
    SPELL_ARCANE_PROJECTILE = 100011,
    SPELL_ARCANE_EXPLOSION  = 100012,
    SPELL_EVOCATION         = 100014
};

enum Casting
{
    CASTING_FIREBALL        = 1,
    CASTING_FIREBLAST,
    CASTING_PYROBLAST,

    CASTING_FROSTBOLT,
    CASTING_ICE_LANCE,
    CASTING_ICE_BLOCK,
    CASTING_BLINK,

    CASTING_ARCANE_BARRAGE,
    CASTING_ARCANE_BLAST,
    CASTING_ARCANE_PROJECTILE,
    CASTING_ARCANE_EXPLOSION,
    CASTING_EVOCATION,
};

class npc_archmage_fire : public CreatureScript
{
    public:
    npc_archmage_fire() : CreatureScript("npc_archmage_fire") {}

    struct npc_archmage_fireAI : public ScriptedAI
    {
        npc_archmage_fireAI(Creature* creature) : ScriptedAI(creature) {}

        void JustEngagedWith(Unit* /*who*/) override
        {
            events.ScheduleEvent(CASTING_FIREBALL, .5f);
            events.ScheduleEvent(CASTING_FIREBLAST, 8s, 14s);
            events.ScheduleEvent(CASTING_PYROBLAST, 12s, 24s);
        }

        void AttackStart(Unit* who) override
        {
            if (!who)
                return;

            if (me->Attack(who, false))
                SetCombatMovement(false);
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

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case CASTING_FIREBALL:
                        DoCastVictim(SPELL_FIREBALL);
                        events.RescheduleEvent(CASTING_FIREBALL, 1180);
                        break;

                    case CASTING_FIREBLAST:
                        if (Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_FIREBLAST);
                        events.RescheduleEvent(CASTING_FIREBLAST, 14s, 22s);
                        break;

                    case CASTING_PYROBLAST:
                        if (Unit * target = SelectTarget(SELECT_TARGET_MAXDISTANCE, 0))
                            DoCast(target, SPELL_PYROBLAST);
                        events.RescheduleEvent(CASTING_PYROBLAST, 22s, 35s);
                        break;
                }
            }
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature * creature) const override
    {
        return new npc_archmage_fireAI(creature);
    }
};

class npc_archmage_arcanes : public CreatureScript
{
    public:
    npc_archmage_arcanes() : CreatureScript("npc_archmage_arcanes") {}

    struct npc_archmage_arcanesAI : public ScriptedAI
    {
        npc_archmage_arcanesAI(Creature* creature) : ScriptedAI(creature) {}

        void JustEngagedWith(Unit* /*who*/) override
        {
            events.ScheduleEvent(CASTING_ARCANE_BLAST, .5f);
            events.ScheduleEvent(CASTING_EVOCATION, .5f);
            events.ScheduleEvent(CASTING_ARCANE_PROJECTILE, 2s);
            events.ScheduleEvent(CASTING_ARCANE_BARRAGE, 3s);
            events.ScheduleEvent(CASTING_ARCANE_EXPLOSION, 8s);
        }

        void AttackStart(Unit* who) override
        {
            if (!who)
                return;

            if (me->Attack(who, false))
                SetCombatMovement(false);
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

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case CASTING_ARCANE_BLAST:
                        if (Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_ARCANE_BLAST);
                        events.RescheduleEvent(CASTING_ARCANE_BLAST, 1s);
                        break;

                    case CASTING_ARCANE_PROJECTILE:
                        DoCastVictim(SPELL_ARCANE_PROJECTILE);
                        events.RescheduleEvent(CASTING_ARCANE_PROJECTILE, 8s, 14s);
                        break;

                    case CASTING_ARCANE_EXPLOSION:
                        DoCast(SPELL_ARCANE_EXPLOSION);
                        events.RescheduleEvent(CASTING_ARCANE_EXPLOSION, 14s, 24s);
                        break;

                    case CASTING_ARCANE_BARRAGE:
                        if (Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_ARCANE_BARRAGE);
                        events.RescheduleEvent(CASTING_ARCANE_BARRAGE, 28s, 32s);
                        break;

                    case CASTING_EVOCATION:
                    {
                        float manaPct = me->GetPower(POWER_MANA) * 100 / me->GetMaxPower(POWER_MANA);
                        if (manaPct <= 20)
                        {
                            me->InterruptNonMeleeSpells(true);
                            DoCast(SPELL_EVOCATION);
                            events.RescheduleEvent(CASTING_EVOCATION, 2min);
                        }
                        events.RescheduleEvent(CASTING_EVOCATION, 5s);
                        break;
                    }
                }
            }
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature * creature) const override
    {
        return new npc_archmage_arcanesAI(creature);
    }
};

class npc_archmage_frost : public CreatureScript
{
public:
    npc_archmage_frost() : CreatureScript("npc_archmage_frost") {}

    struct npc_archmage_frostAI : public ScriptedAI
    {
        npc_archmage_frostAI(Creature* creature) : ScriptedAI(creature) {}

        void JustEngagedWith(Unit* /*who*/) override
        {
            events.ScheduleEvent(CASTING_FROSTBOLT, .5f);
            events.ScheduleEvent(CASTING_ICE_LANCE, 8s, 14s);
        }

        void AttackStart(Unit* who) override
        {
            if (!who)
                return;

            if (me->Attack(who, false))
                DoStartMovement(who, 35.f);
        }

        void Reset() override
        {
            events.Reset();
            me->RemoveAurasDueToSpell(SPELL_HYPOTHERMIA);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
        {
            if (!me->HasAura(SPELL_HYPOTHERMIA) && HealthBelowPct(30))
            {
                me->InterruptNonMeleeSpells(false);
                DoCastSelf(SPELL_ICE_BLOCK);
                DoCastSelf(SPELL_HYPOTHERMIA);
                events.ScheduleEvent(CASTING_BLINK, 6s);
            }
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
                    // Frost
                    case CASTING_FROSTBOLT:
                        DoCastVictim(SPELL_FROSTBOLT);
                        events.RescheduleEvent(CASTING_FROSTBOLT, 1s);
                        break;

                    case CASTING_ICE_LANCE:
                        me->InterruptNonMeleeSpells(false);
                        if (Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_ICE_LANCE);
                        events.RescheduleEvent(CASTING_ICE_LANCE, 8s, 9s);
                        break;

                    case CASTING_BLINK:
                        me->InterruptNonMeleeSpells(false);
                        DoCast(SPELL_BLINK);
                        break;
                }
            }
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_archmage_frostAI(creature);
    }
};

void AddSC_npc_archmages()
{
    new npc_archmage_fire();
    new npc_archmage_arcanes();
    new npc_archmage_frost();
}
