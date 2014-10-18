/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
        boss_darkweaver_sythAI(Creature* creature) : BossAI(creature, DATA_DARKWEAVER_SYTH)
        {
            Initialize();
        }

        void Initialize()
        {
            _summon90 = false;
            _summon50 = false;
            _summon10 = false;
        }

        void Reset() override
        {
            Initialize();
            _Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            events.ScheduleEvent(EVENT_FLAME_SHOCK, 2000);
            events.ScheduleEvent(EVENT_ARCANE_SHOCK, 4000);
            events.ScheduleEvent(EVENT_FROST_SHOCK, 6000);
            events.ScheduleEvent(EVENT_SHADOW_SHOCK, 8000);
            events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 15000);

            Talk(SAY_AGGRO);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            Talk(SAY_DEATH);
        }

        void KilledUnit(Unit* who) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_SLAY);
        }

        void JustSummoned(Creature* summoned) override
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                summoned->AI()->AttackStart(target);

            summons.Summon(summoned);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (me->HealthBelowPctDamaged(90, damage) && !_summon90)
            {
                SythSummoning();
                _summon90 = true;
            }

            if (me->HealthBelowPctDamaged(50, damage) && !_summon50)
            {
                SythSummoning();
                _summon50 = true;
            }

            if (me->HealthBelowPctDamaged(10, damage) && !_summon10)
            {
                SythSummoning();
                _summon10 = true;
            }
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

        void ExecuteEvent(uint32 eventId) override
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

        private:
            bool _summon90;
            bool _summon50;
            bool _summon10;
    };

    CreatureAI* GetAI(Creature* creature) const override
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
            Initialize();
        }

        void Initialize()
        {
            flameshock_timer = 2500;
            flamebuffet_timer = 5000;
        }

        void Reset() override
        {
            Initialize();
            me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FIRE, true);
        }

        void UpdateAI(uint32 diff) override
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

        private:
            uint32 flameshock_timer;
            uint32 flamebuffet_timer;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_syth_fireAI(creature);
    }
};

class npc_syth_arcane : public CreatureScript
{
public:
    npc_syth_arcane() : CreatureScript("npc_syth_arcane") { }

    struct npc_syth_arcaneAI : public ScriptedAI
    {
        npc_syth_arcaneAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            arcaneshock_timer = 2500;
            arcanebuffet_timer = 5000;
        }

        void Reset() override
        {
            Initialize();
            me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_ARCANE, true);
        }

        void UpdateAI(uint32 diff) override
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

        private:
            uint32 arcaneshock_timer;
            uint32 arcanebuffet_timer;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_syth_arcaneAI(creature);
    }
};

class npc_syth_frost : public CreatureScript
{
public:
    npc_syth_frost() : CreatureScript("npc_syth_frost") { }

    struct npc_syth_frostAI : public ScriptedAI
    {
        npc_syth_frostAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            frostshock_timer = 2500;
            frostbuffet_timer = 5000;
        }

        void Reset() override
        {
            Initialize();
            me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FROST, true);
        }

        void UpdateAI(uint32 diff) override
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

        private:
            uint32 frostshock_timer;
            uint32 frostbuffet_timer;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_syth_frostAI(creature);
    }
};

class npc_syth_shadow : public CreatureScript
{
public:
    npc_syth_shadow() : CreatureScript("npc_syth_shadow") { }

    struct npc_syth_shadowAI : public ScriptedAI
    {
        npc_syth_shadowAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            shadowshock_timer = 2500;
            shadowbuffet_timer = 5000;
        }

        void Reset() override
        {
            Initialize();
            me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_SHADOW, true);
        }

        void UpdateAI(uint32 diff) override
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

        private:
            uint32 shadowshock_timer;
            uint32 shadowbuffet_timer;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_syth_shadowAI(creature);
    }
};

void AddSC_boss_darkweaver_syth()
{
    new boss_darkweaver_syth();
    new npc_syth_fire();
    new npc_syth_arcane();
    new npc_syth_frost();
    new npc_syth_shadow();
}
