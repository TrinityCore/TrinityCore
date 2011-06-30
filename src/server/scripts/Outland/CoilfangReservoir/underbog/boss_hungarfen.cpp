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
SDName: Boss_Hungarfen
SD%Complete: 95
SDComment: Need confirmation if spell data are same in both modes. Summons should have faster rate in heroic
SDCategory: Coilfang Resevoir, Underbog
EndScriptData */

#include "ScriptPCH.h"

#define SPELL_FOUL_SPORES   31673
#define SPELL_ACID_GEYSER   38739

class boss_hungarfen : public CreatureScript
{
public:
    boss_hungarfen() : CreatureScript("boss_hungarfen") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_hungarfenAI (pCreature);
    }

    struct boss_hungarfenAI : public ScriptedAI
    {
        boss_hungarfenAI(Creature* c) : ScriptedAI(c)
        {
        }

        bool Root;
        uint32 Mushroom_Timer;
        uint32 AcidGeyser_Timer;

        void Reset()
        {
            Root = false;
            Mushroom_Timer = 5000;                              // 1 mushroom after 5s, then one per 10s. This should be different in heroic mode
            AcidGeyser_Timer = 10000;
        }

        void EnterCombat(Unit* /*who*/)
        {
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (!HealthAbovePct(20))
            {
                if (!Root)
                {
                    DoCast(me, SPELL_FOUL_SPORES);
                    Root = true;
                }
            }

            if (Mushroom_Timer <= diff)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    me->SummonCreature(17990, pTarget->GetPositionX()+(rand()%8), pTarget->GetPositionY()+(rand()%8), pTarget->GetPositionZ(), float(rand()%5), TEMPSUMMON_TIMED_DESPAWN, 22000);
                else
                    me->SummonCreature(17990, me->GetPositionX()+(rand()%8), me->GetPositionY()+(rand()%8), me->GetPositionZ(), float(rand()%5), TEMPSUMMON_TIMED_DESPAWN, 22000);

                Mushroom_Timer = 10000;
            } else Mushroom_Timer -= diff;

            if (AcidGeyser_Timer <= diff)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, SPELL_ACID_GEYSER);
                AcidGeyser_Timer = 10000+rand()%7500;
            } else AcidGeyser_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

#define SPELL_SPORE_CLOUD       34168
#define SPELL_PUTRID_MUSHROOM   31690
#define SPELL_GROW              31698

class mob_underbog_mushroom : public CreatureScript
{
public:
    mob_underbog_mushroom() : CreatureScript("mob_underbog_mushroom") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_underbog_mushroomAI (pCreature);
    }

    struct mob_underbog_mushroomAI : public ScriptedAI
    {
        mob_underbog_mushroomAI(Creature* c) : ScriptedAI(c) {}

        bool Stop;
        uint32 Grow_Timer;
        uint32 Shrink_Timer;

        void Reset()
        {
            Stop = false;
            Grow_Timer = 0;
            Shrink_Timer = 20000;

            DoCast(me, SPELL_PUTRID_MUSHROOM, true);
            DoCast(me, SPELL_SPORE_CLOUD, true);
        }

        void MoveInLineOfSight(Unit* /*who*/) {}

        void AttackStart(Unit* /*who*/) {}

        void EnterCombat(Unit* /*who*/) {}

        void UpdateAI(const uint32 diff)
        {
            if (Stop)
                return;

            if (Grow_Timer <= diff)
            {
                DoCast(me, SPELL_GROW);
                Grow_Timer = 3000;
            } else Grow_Timer -= diff;

            if (Shrink_Timer <= diff)
            {
                me->RemoveAurasDueToSpell(SPELL_GROW);
                Stop = true;
            } else Shrink_Timer -= diff;
        }
    };

};

void AddSC_boss_hungarfen()
{
    new boss_hungarfen();
    new mob_underbog_mushroom();
}
