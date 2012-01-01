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
SDName: Boss_Azuregos
SD%Complete: 90
SDComment: Teleport not included, spell reflect not effecting dots (Core problem)
SDCategory: Azshara
EndScriptData */

#include "ScriptPCH.h"

#define SAY_TELEPORT            -1000100

#define SPELL_MARKOFFROST        23182
#define SPELL_MANASTORM          21097
#define SPELL_CHILL              21098
#define SPELL_FROSTBREATH        21099
#define SPELL_REFLECT            22067
#define SPELL_CLEAVE              8255                      //Perhaps not right ID
#define SPELL_ENRAGE             23537

class boss_azuregos : public CreatureScript
{
public:
    boss_azuregos() : CreatureScript("boss_azuregos") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_azuregosAI (creature);
    }

    struct boss_azuregosAI : public ScriptedAI
    {
        boss_azuregosAI(Creature* c) : ScriptedAI(c) {}

        uint32 MarkOfFrost_Timer;
        uint32 ManaStorm_Timer;
        uint32 Chill_Timer;
        uint32 Breath_Timer;
        uint32 Teleport_Timer;
        uint32 Reflect_Timer;
        uint32 Cleave_Timer;
        uint32 Enrage_Timer;
        bool Enraged;

        void Reset()
        {
            MarkOfFrost_Timer = 35000;
            ManaStorm_Timer = urand(5000, 17000);
            Chill_Timer = urand(10000, 30000);
            Breath_Timer = urand(2000, 8000);
            Teleport_Timer = 30000;
            Reflect_Timer = urand(15000, 30000);
            Cleave_Timer = 7000;
            Enrage_Timer = 0;
            Enraged = false;
        }

        void EnterCombat(Unit* /*who*/) {}

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (Teleport_Timer <= diff)
            {
                DoScriptText(SAY_TELEPORT, me);
                std::list<HostileReference*>& m_threatlist = me->getThreatManager().getThreatList();
                std::list<HostileReference*>::const_iterator i = m_threatlist.begin();
                for (i = m_threatlist.begin(); i!= m_threatlist.end(); ++i)
                {
                    Unit* unit = Unit::GetUnit((*me), (*i)->getUnitGuid());
                    if (unit && (unit->GetTypeId() == TYPEID_PLAYER))
                    {
                        DoTeleportPlayer(unit, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ()+3, unit->GetOrientation());
                    }
                }

                DoResetThreat();
                Teleport_Timer = 30000;
            } else Teleport_Timer -= diff;

            //        //MarkOfFrost_Timer
            //        if (MarkOfFrost_Timer <= diff)
            //        {
            //            DoCast(me->getVictim(), SPELL_MARKOFFROST);
            //            MarkOfFrost_Timer = 25000;
            //        } else MarkOfFrost_Timer -= diff;

            //Chill_Timer
            if (Chill_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_CHILL);
                Chill_Timer = urand(13000, 25000);
            } else Chill_Timer -= diff;

            //Breath_Timer
            if (Breath_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_FROSTBREATH);
                Breath_Timer = urand(10000, 15000);
            } else Breath_Timer -= diff;

            //ManaStorm_Timer
            if (ManaStorm_Timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_MANASTORM);
                ManaStorm_Timer = urand(7500, 12500);
            } else ManaStorm_Timer -= diff;

            //Reflect_Timer
            if (Reflect_Timer <= diff)
            {
                DoCast(me, SPELL_REFLECT);
                Reflect_Timer = urand(20000, 35000);
            } else Reflect_Timer -= diff;

            //Cleave_Timer
            if (Cleave_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_CLEAVE);
                Cleave_Timer = 7000;
            } else Cleave_Timer -= diff;

            //Enrage_Timer
            if (HealthBelowPct(26) && !Enraged)
            {
                DoCast(me, SPELL_ENRAGE);
                Enraged = true;
            }

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_azuregos()
{
    new boss_azuregos();
}
