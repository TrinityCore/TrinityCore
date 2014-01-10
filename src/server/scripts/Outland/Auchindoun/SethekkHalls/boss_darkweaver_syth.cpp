/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* ScriptData
SDName: Boss_Darkweaver_Syth
SD%Complete: 85
SDComment: Shock spells/times need more work. Heroic partly implemented.
SDCategory: Auchindoun, Sethekk Halls
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "sethekk_halls.h"

enum Says
{
    SAY_SUMMON                  = 0,
    SAY_AGGRO                   = 1,
    SAY_SLAY                    = 2,
    SAY_DEATH                   = 3
};

enum Spells
{
    SPELL_FROST_SHOCK           = 21401, //37865
    SPELL_FLAME_SHOCK           = 34354,
    SPELL_SHADOW_SHOCK          = 30138,
    SPELL_ARCANE_SHOCK          = 37132,

    SPELL_CHAIN_LIGHTNING       = 15659, //15305

    SPELL_SUMMON_SYTH_FIRE      = 33537,                   // Spawns 19203
    SPELL_SUMMON_SYTH_ARCANE    = 33538,                   // Spawns 19205
    SPELL_SUMMON_SYTH_FROST     = 33539,                   // Spawns 19204
    SPELL_SUMMON_SYTH_SHADOW    = 33540,                   // Spawns 19206

    SPELL_FLAME_BUFFET          = 33526,
    SPELL_ARCANE_BUFFET         = 33527,
    SPELL_FROST_BUFFET          = 33528,
    SPELL_SHADOW_BUFFET         = 33529
};

enum Events
{
    EVENT_FLAME_SHOCK           = 1,
    EVENT_ARCANE_SHOCK          = 2,
    EVENT_FROST_SHOCK           = 3,
    EVENT_SHADOW_SHOCK          = 4,
    EVENT_CHAIN_LIGHTNING       = 5
};

class boss_darkweaver_syth : public CreatureScript
{
public:
    boss_darkweaver_syth() : CreatureScript("boss_darkweaver_syth") { }

    struct boss_darkweaver_sythAI : public BossAI
    {
        boss_darkweaver_sythAI(Creature* creature) : BossAI(creature, DATA_DARKWEAVER_SYTH) { }

        void Reset() OVERRIDE
        {
            _Reset();
            summon90 = false;
            summon50 = false;
            summon10 = false;
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            _EnterCombat();
            events.ScheduleEvent(EVENT_FLAME_SHOCK, 2000);
            events.ScheduleEvent(EVENT_ARCANE_SHOCK, 4000);
            events.ScheduleEvent(EVENT_FROST_SHOCK, 6000);
            events.ScheduleEvent(EVENT_SHADOW_SHOCK, 8000);
            events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 15000);

            Talk(SAY_AGGRO);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            _JustDied();
            Talk(SAY_DEATH);
        }

        void KilledUnit(Unit* who) OVERRIDE
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_SLAY);
        }

        void JustSummoned(Creature* summoned) OVERRIDE
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                summoned->AI()->AttackStart(target);
        }

        void SythSummoning()
        {
            Talk(SAY_SUMMON);

            if (me->IsNonMeleeSpellCast(false))
                me->InterruptNonMeleeSpells(false);

            DoCast(me, SPELL_SUMMON_SYTH_ARCANE, true);   //front
            DoCast(me, SPELL_SUMMON_SYTH_FIRE, true);     //back
            DoCast(me, SPELL_SUMMON_SYTH_FROST, true);    //left
            DoCast(me, SPELL_SUMMON_SYTH_SHADOW, true);   //right
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_FLAME_SHOCK:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_FLAME_SHOCK);
                        events.ScheduleEvent(EVENT_FLAME_SHOCK, urand(10000, 15000));
                        break;
                    case EVENT_ARCANE_SHOCK:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_ARCANE_SHOCK);
                        events.ScheduleEvent(EVENT_ARCANE_SHOCK, urand(10000, 15000));
                        break;
                    case EVENT_FROST_SHOCK:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_FROST_SHOCK);
                        events.ScheduleEvent(EVENT_FROST_SHOCK, urand(10000, 15000));
                        break;
                    case EVENT_SHADOW_SHOCK:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_SHADOW_SHOCK);
                        events.ScheduleEvent(EVENT_SHADOW_SHOCK, urand(10000, 15000));
                        break;
                    case EVENT_CHAIN_LIGHTNING:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_CHAIN_LIGHTNING);
                        events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 25000);
                        break;
                    default:
                        break;
                }
            }

            if (HealthBelowPct(90) && !summon90)
            {
                SythSummoning();
                summon90 = true;
            }

            if (HealthBelowPct(50) && !summon50)
            {
                SythSummoning();
                summon50 = true;
            }

            if (HealthBelowPct(10) && !summon10)
            {
                SythSummoning();
                summon10 = true;
            }

            DoMeleeAttackIfReady();
        }

        private:
            bool summon90;
            bool summon50;
            bool summon10;
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetSethekkHallsAI<boss_darkweaver_sythAI>(creature);
    }
};

/* ELEMENTALS */
class npc_syth_fire : public CreatureScript
{
public:
    npc_syth_fire() : CreatureScript("npc_syth_fire") { }

    struct npc_syth_fireAI : public ScriptedAI
    {
        npc_syth_fireAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        uint32 flameshock_timer;
        uint32 flamebuffet_timer;

        void Reset() OVERRIDE
        {
            me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FIRE, true);
            flameshock_timer = 2500;
            flamebuffet_timer = 5000;
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE { }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            if (flameshock_timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_FLAME_SHOCK);

                flameshock_timer = 5000;
            } else flameshock_timer -= diff;

            if (flamebuffet_timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_FLAME_BUFFET);

                flamebuffet_timer = 5000;
            } else flamebuffet_timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_syth_fireAI(creature);
    }
};

class npc_syth_arcane : public CreatureScript
{
public:
    npc_syth_arcane() : CreatureScript("npc_syth_arcane") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_syth_arcaneAI(creature);
    }

    struct npc_syth_arcaneAI : public ScriptedAI
    {
        npc_syth_arcaneAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        uint32 arcaneshock_timer;
        uint32 arcanebuffet_timer;

        void Reset() OVERRIDE
        {
            me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_ARCANE, true);
            arcaneshock_timer = 2500;
            arcanebuffet_timer = 5000;
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE { }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            if (arcaneshock_timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_ARCANE_SHOCK);

                arcaneshock_timer = 5000;
            } else arcaneshock_timer -= diff;

            if (arcanebuffet_timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_ARCANE_BUFFET);

                arcanebuffet_timer = 5000;
            } else arcanebuffet_timer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

class npc_syth_frost : public CreatureScript
{
public:
    npc_syth_frost() : CreatureScript("npc_syth_frost") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_syth_frostAI(creature);
    }

    struct npc_syth_frostAI : public ScriptedAI
    {
        npc_syth_frostAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        uint32 frostshock_timer;
        uint32 frostbuffet_timer;

        void Reset() OVERRIDE
        {
            me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FROST, true);
            frostshock_timer = 2500;
            frostbuffet_timer = 5000;
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE { }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            if (frostshock_timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_FROST_SHOCK);

                frostshock_timer = 5000;
            } else frostshock_timer -= diff;

            if (frostbuffet_timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_FROST_BUFFET);

                frostbuffet_timer = 5000;
            } else frostbuffet_timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

class npc_syth_shadow : public CreatureScript
{
public:
    npc_syth_shadow() : CreatureScript("npc_syth_shadow") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_syth_shadowAI(creature);
    }

    struct npc_syth_shadowAI : public ScriptedAI
    {
        npc_syth_shadowAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        uint32 shadowshock_timer;
        uint32 shadowbuffet_timer;

        void Reset() OVERRIDE
        {
            me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_SHADOW, true);
            shadowshock_timer = 2500;
            shadowbuffet_timer = 5000;
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE { }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            if (shadowshock_timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_SHADOW_SHOCK);

                shadowshock_timer = 5000;
            } else shadowshock_timer -= diff;

            if (shadowbuffet_timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_SHADOW_BUFFET);

                shadowbuffet_timer = 5000;
            } else shadowbuffet_timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_darkweaver_syth()
{
    new boss_darkweaver_syth();
    new npc_syth_fire();
    new npc_syth_arcane();
    new npc_syth_frost();
    new npc_syth_shadow();
}
