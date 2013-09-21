/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Warlord_Kalithres
SD%Complete: 65
SDComment: Contains workarounds regarding warlord's rage spells not acting as expected. Both scripts here require review and fine tuning.
SDCategory: Coilfang Resevoir, The Steamvault
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "steam_vault.h"
#include "SpellInfo.h"

enum NagaDistiller
{
    SAY_INTRO                   = 0,
    SAY_REGEN                   = 1,
    SAY_AGGRO                   = 2,
    SAY_SLAY                    = 3,
    SAY_DEATH                   = 4,

    SPELL_SPELL_REFLECTION      = 31534,
    SPELL_IMPALE                = 39061,
    SPELL_WARLORDS_RAGE         = 37081,
    SPELL_WARLORDS_RAGE_NAGA    = 31543,

    SPELL_WARLORDS_RAGE_PROC    = 36453
};

class npc_naga_distiller : public CreatureScript
{
public:
    npc_naga_distiller() : CreatureScript("npc_naga_distiller") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_naga_distillerAI(creature);
    }

    struct npc_naga_distillerAI : public ScriptedAI
    {
        npc_naga_distillerAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        void Reset() OVERRIDE
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

            //hack, due to really weird spell behaviour :(
            if (instance)
            {
                if (instance->GetData(DATA_DISTILLER) == IN_PROGRESS)
                {
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                }
            }
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE {}

        void StartRageGen(Unit* /*caster*/)
        {
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

            DoCast(me, SPELL_WARLORDS_RAGE_NAGA, true);

            if (instance)
                instance->SetData(DATA_DISTILLER, IN_PROGRESS);
        }

        void DamageTaken(Unit* /*done_by*/, uint32 &damage) OVERRIDE
        {
            if (me->GetHealth() <= damage)
                if (instance)
                    instance->SetData(DATA_DISTILLER, DONE);
        }
    };

};

class boss_warlord_kalithresh : public CreatureScript
{
public:
    boss_warlord_kalithresh() : CreatureScript("boss_warlord_kalithresh") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new boss_warlord_kalithreshAI(creature);
    }

    struct boss_warlord_kalithreshAI : public ScriptedAI
    {
        boss_warlord_kalithreshAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 Reflection_Timer;
        uint32 Impale_Timer;
        uint32 Rage_Timer;
        bool CanRage;

        void Reset() OVERRIDE
        {
            Reflection_Timer = 10000;
            Impale_Timer = 7000+rand()%7000;
            Rage_Timer = 45000;
            CanRage = false;

            if (instance)
                instance->SetBossState(DATA_WARLORD_KALITHRESH, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            Talk(SAY_AGGRO);

            if (instance)
                instance->SetBossState(DATA_WARLORD_KALITHRESH, IN_PROGRESS);
        }

        void KilledUnit(Unit* /*victim*/) OVERRIDE
        {
            Talk(SAY_SLAY);
        }

        void SpellHit(Unit* /*caster*/, const SpellInfo* spell) OVERRIDE
        {
            //hack :(
            if (spell->Id == SPELL_WARLORDS_RAGE_PROC)
                if (instance)
                    if (instance->GetData(DATA_DISTILLER) == DONE)
                        me->RemoveAurasDueToSpell(SPELL_WARLORDS_RAGE_PROC);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            Talk(SAY_DEATH);

            if (instance)
                instance->SetBossState(DATA_WARLORD_KALITHRESH, DONE);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            if (Rage_Timer <= diff)
            {
                if (Creature* distiller = me->FindNearestCreature(17954, 100.0f))
                {
                    Talk(SAY_REGEN);
                    DoCast(me, SPELL_WARLORDS_RAGE);
                    CAST_AI(npc_naga_distiller::npc_naga_distillerAI, distiller->AI())->StartRageGen(me);
                }
                Rage_Timer = 3000+rand()%15000;
            } else Rage_Timer -= diff;

            //Reflection_Timer
            if (Reflection_Timer <= diff)
            {
                DoCast(me, SPELL_SPELL_REFLECTION);
                Reflection_Timer = 15000+rand()%10000;
            } else Reflection_Timer -= diff;

            //Impale_Timer
            if (Impale_Timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_IMPALE);

                Impale_Timer = 7500+rand()%5000;
            } else Impale_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_warlord_kalithresh()
{
    new npc_naga_distiller();
    new boss_warlord_kalithresh();
}
