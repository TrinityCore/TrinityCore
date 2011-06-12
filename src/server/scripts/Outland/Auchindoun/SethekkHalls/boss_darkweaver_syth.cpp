/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"

#define SAY_SUMMON                  -1556000

#define SAY_AGGRO_1                 -1556001
#define SAY_AGGRO_2                 -1556002
#define SAY_AGGRO_3                 -1556003

#define SAY_SLAY_1                  -1556004
#define SAY_SLAY_2                  -1556005

#define SAY_DEATH                   -1556006

#define SPELL_FROST_SHOCK           21401 //37865
#define SPELL_FLAME_SHOCK           34354
#define SPELL_SHADOW_SHOCK          30138
#define SPELL_ARCANE_SHOCK          37132

#define SPELL_CHAIN_LIGHTNING       15659 //15305

#define SPELL_SUMMON_SYTH_FIRE      33537                   // Spawns 19203
#define SPELL_SUMMON_SYTH_ARCANE    33538                   // Spawns 19205
#define SPELL_SUMMON_SYTH_FROST     33539                   // Spawns 19204
#define SPELL_SUMMON_SYTH_SHADOW    33540                   // Spawns 19206

#define SPELL_FLAME_BUFFET          DUNGEON_MODE(33526, 38141)
#define SPELL_ARCANE_BUFFET         DUNGEON_MODE(33527, 38138)
#define SPELL_FROST_BUFFET          DUNGEON_MODE(33528, 38142)
#define SPELL_SHADOW_BUFFET         DUNGEON_MODE(33529, 38143)

class boss_darkweaver_syth : public CreatureScript
{
public:
    boss_darkweaver_syth() : CreatureScript("boss_darkweaver_syth") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_darkweaver_sythAI (pCreature);
    }

    struct boss_darkweaver_sythAI : public ScriptedAI
    {
        boss_darkweaver_sythAI(Creature *c) : ScriptedAI(c)
        {
        }

        uint32 flameshock_timer;
        uint32 arcaneshock_timer;
        uint32 frostshock_timer;
        uint32 shadowshock_timer;
        uint32 chainlightning_timer;

        bool summon90;
        bool summon50;
        bool summon10;

        void Reset()
        {
            flameshock_timer = 2000;
            arcaneshock_timer = 4000;
            frostshock_timer = 6000;
            shadowshock_timer = 8000;
            chainlightning_timer = 15000;

            summon90 = false;
            summon50 = false;
            summon10 = false;
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(RAND(SAY_AGGRO_1, SAY_AGGRO_2, SAY_AGGRO_3), me);
        }

        void JustDied(Unit* /*Killer*/)
        {
            DoScriptText(SAY_DEATH, me);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            if (rand()%2)
                return;

            DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2), me);
        }

        void JustSummoned(Creature *summoned)
        {
            if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                summoned->AI()->AttackStart(pTarget);
        }

        void SythSummoning()
        {
            DoScriptText(SAY_SUMMON, me);

            if (me->IsNonMeleeSpellCasted(false))
                me->InterruptNonMeleeSpells(false);

            DoCast(me, SPELL_SUMMON_SYTH_ARCANE, true);   //front
            DoCast(me, SPELL_SUMMON_SYTH_FIRE, true);     //back
            DoCast(me, SPELL_SUMMON_SYTH_FROST, true);    //left
            DoCast(me, SPELL_SUMMON_SYTH_SHADOW, true);   //right
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

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

            if (flameshock_timer <= diff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, SPELL_FLAME_SHOCK);

                flameshock_timer = 10000 + rand()%5000;
            } else flameshock_timer -= diff;

            if (arcaneshock_timer <= diff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, SPELL_ARCANE_SHOCK);

                arcaneshock_timer = 10000 + rand()%5000;
            } else arcaneshock_timer -= diff;

            if (frostshock_timer <= diff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, SPELL_FROST_SHOCK);

                frostshock_timer = 10000 + rand()%5000;
            } else frostshock_timer -= diff;

            if (shadowshock_timer <= diff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, SPELL_SHADOW_SHOCK);

                shadowshock_timer = 10000 + rand()%5000;
            } else shadowshock_timer -= diff;

            if (chainlightning_timer <= diff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, SPELL_CHAIN_LIGHTNING);

                chainlightning_timer = 25000;
            } else chainlightning_timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

/* ELEMENTALS */
class mob_syth_fire : public CreatureScript
{
public:
    mob_syth_fire() : CreatureScript("mob_syth_fire") { }

    struct mob_syth_fireAI : public ScriptedAI
    {
        mob_syth_fireAI(Creature *c) : ScriptedAI(c)
        {
        }

        uint32 flameshock_timer;
        uint32 flamebuffet_timer;

        void Reset()
        {
            me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FIRE, true);
            flameshock_timer = 2500;
            flamebuffet_timer = 5000;
        }

        void EnterCombat(Unit* /*who*/) { }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (flameshock_timer <= diff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, SPELL_FLAME_SHOCK);

                flameshock_timer = 5000;
            } else flameshock_timer -= diff;

            if (flamebuffet_timer <= diff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, SPELL_FLAME_BUFFET);

                flamebuffet_timer = 5000;
            } else flamebuffet_timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_syth_fireAI (pCreature);
    }
};

class mob_syth_arcane : public CreatureScript
{
public:
    mob_syth_arcane() : CreatureScript("mob_syth_arcane") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_syth_arcaneAI (pCreature);
    }

    struct mob_syth_arcaneAI : public ScriptedAI
    {
        mob_syth_arcaneAI(Creature *c) : ScriptedAI(c)
        {
        }

        uint32 arcaneshock_timer;
        uint32 arcanebuffet_timer;

        void Reset()
        {
            me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_ARCANE, true);
            arcaneshock_timer = 2500;
            arcanebuffet_timer = 5000;
        }

        void EnterCombat(Unit* /*who*/) { }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (arcaneshock_timer <= diff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, SPELL_ARCANE_SHOCK);

                arcaneshock_timer = 5000;
            } else arcaneshock_timer -= diff;

            if (arcanebuffet_timer <= diff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, SPELL_ARCANE_BUFFET);

                arcanebuffet_timer = 5000;
            } else arcanebuffet_timer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

class mob_syth_frost : public CreatureScript
{
public:
    mob_syth_frost() : CreatureScript("mob_syth_frost") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_syth_frostAI (pCreature);
    }

    struct mob_syth_frostAI : public ScriptedAI
    {
        mob_syth_frostAI(Creature *c) : ScriptedAI(c)
        {
        }

        uint32 frostshock_timer;
        uint32 frostbuffet_timer;

        void Reset()
        {
            me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FROST, true);
            frostshock_timer = 2500;
            frostbuffet_timer = 5000;
        }

        void EnterCombat(Unit* /*who*/) { }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (frostshock_timer <= diff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, SPELL_FROST_SHOCK);

                frostshock_timer = 5000;
            } else frostshock_timer -= diff;

            if (frostbuffet_timer <= diff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, SPELL_FROST_BUFFET);

                frostbuffet_timer = 5000;
            } else frostbuffet_timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

class mob_syth_shadow : public CreatureScript
{
public:
    mob_syth_shadow() : CreatureScript("mob_syth_shadow") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_syth_shadowAI (pCreature);
    }

    struct mob_syth_shadowAI : public ScriptedAI
    {
        mob_syth_shadowAI(Creature *c) : ScriptedAI(c)
        {
        }

        uint32 shadowshock_timer;
        uint32 shadowbuffet_timer;

        void Reset()
        {
            me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_SHADOW, true);
            shadowshock_timer = 2500;
            shadowbuffet_timer = 5000;
        }

        void EnterCombat(Unit* /*who*/) { }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (shadowshock_timer <= diff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, SPELL_SHADOW_SHOCK);

                shadowshock_timer = 5000;
            } else shadowshock_timer -= diff;

            if (shadowbuffet_timer <= diff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, SPELL_SHADOW_BUFFET);

                shadowbuffet_timer = 5000;
            } else shadowbuffet_timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_darkweaver_syth()
{
    new boss_darkweaver_syth();
    new mob_syth_fire();
    new mob_syth_arcane();
    new mob_syth_frost();
    new mob_syth_shadow();
}
