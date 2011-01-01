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
SDName: Boss_Gyth
SD%Complete: 100
SDComment:
SDCategory: Blackrock Spire
EndScriptData */

#include "ScriptPCH.h"

#define SPELL_CORROSIVEACID      20667
#define SPELL_FREEZE             18763
#define SPELL_FLAMEBREATH        20712

class boss_gyth : public CreatureScript
{
public:
    boss_gyth() : CreatureScript("boss_gyth") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_gythAI (pCreature);
    }

    struct boss_gythAI : public ScriptedAI
    {
        boss_gythAI(Creature *c) : ScriptedAI(c) {}

        uint32 Aggro_Timer;
        uint32 Dragons_Timer;
        uint32 Orc_Timer;
        uint32 CorrosiveAcid_Timer;
        uint32 Freeze_Timer;
        uint32 Flamebreath_Timer;
        uint32 Line1Count;
        uint32 Line2Count;

        bool Event;
        bool SummonedDragons;
        bool SummonedOrcs;
        bool SummonedRend;
        bool bAggro;
        bool RootSelf;

        void Reset()
        {
            Dragons_Timer = 3000;
            Orc_Timer = 60000;
            Aggro_Timer = 60000;
            CorrosiveAcid_Timer = 8000;
            Freeze_Timer = 11000;
            Flamebreath_Timer = 4000;
            Event = false;
            SummonedDragons = false;
            SummonedOrcs= false;
            SummonedRend = false;
            bAggro = false;
            RootSelf = false;

            // how many times should the two lines of summoned creatures be spawned
            // min 2 x 2, max 7 lines of attack in total
            Line1Count = rand() % 4 + 2;
            if (Line1Count < 5)
                Line2Count = rand() % (5 - Line1Count) + 2;
            else
                Line2Count = 2;

            //Invisible for event start
            me->SetDisplayId(11686);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        void EnterCombat(Unit * /*who*/)
        {
        }

        void SummonCreatureWithRandomTarget(uint32 creatureId)
        {
            Unit* Summoned = me->SummonCreature(creatureId, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 240000);
            if (Summoned)
            {
                Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);
                if (pTarget)
                    Summoned->AddThreat(pTarget, 1.0f);
            }
        }

        void UpdateAI(const uint32 diff)
        {
            //char buf[200];

            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (!RootSelf)
            {
                //me->m_canMove = true;
                DoCast(me, 33356);
                RootSelf = true;
            }

            if (!bAggro && Line1Count == 0 && Line2Count == 0)
            {
                if (Aggro_Timer <= diff)
                {
                    bAggro = true;
                    // Visible now!
                    me->SetDisplayId(9723);
                    me->setFaction(14);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                } else Aggro_Timer -= diff;
            }

            // Summon Dragon pack. 2 Dragons and 3 Whelps
            if (!bAggro && !SummonedRend && Line1Count > 0)
            {
                if (Dragons_Timer <= diff)
                {
                    SummonCreatureWithRandomTarget(10372);
                    SummonCreatureWithRandomTarget(10372);
                    SummonCreatureWithRandomTarget(10442);
                    SummonCreatureWithRandomTarget(10442);
                    SummonCreatureWithRandomTarget(10442);
                    Line1Count = Line1Count - 1;
                    Dragons_Timer = 60000;
                } else Dragons_Timer -= diff;
            }

            //Summon Orc pack. 1 Orc Handler 1 Elite Dragonkin and 3 Whelps
            if (!bAggro && !SummonedRend && Line1Count == 0 && Line2Count > 0)
            {
                if (Orc_Timer <= diff)
                {
                    SummonCreatureWithRandomTarget(10447);
                    SummonCreatureWithRandomTarget(10317);
                    SummonCreatureWithRandomTarget(10442);
                    SummonCreatureWithRandomTarget(10442);
                    SummonCreatureWithRandomTarget(10442);
                    Line2Count = Line2Count - 1;
                    Orc_Timer = 60000;
                } else Orc_Timer -= diff;
            }

            // we take part in the fight
            if (bAggro)
            {
                // CorrosiveAcid_Timer
                if (CorrosiveAcid_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_CORROSIVEACID);
                    CorrosiveAcid_Timer = 7000;
                } else CorrosiveAcid_Timer -= diff;

                // Freeze_Timer
                if (Freeze_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_FREEZE);
                    Freeze_Timer = 16000;
                } else Freeze_Timer -= diff;

                // Flamebreath_Timer
                if (Flamebreath_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_FLAMEBREATH);
                    Flamebreath_Timer = 10500;
                } else Flamebreath_Timer -= diff;

                //Summon Rend
                if (!SummonedRend && HealthBelowPct(11) && me->GetHealth() > 0)
                {
                    //summon Rend and Change model to normal Gyth
                    //Interrupt any spell casting
                    me->InterruptNonMeleeSpells(false);
                    //Gyth model
                    me->SetDisplayId(9806);
                    me->SummonCreature(10429, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 900000);
                    SummonedRend = true;
                }

                DoMeleeAttackIfReady();
            }                                                   // end if Aggro
        }
    };

};


void AddSC_boss_gyth()
{
    new boss_gyth();
}
