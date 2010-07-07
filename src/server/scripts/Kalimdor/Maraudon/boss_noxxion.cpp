/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Noxxion
SD%Complete: 100
SDComment:
SDCategory: Maraudon
EndScriptData */

#include "ScriptPCH.h"

#define SPELL_TOXICVOLLEY           21687
#define SPELL_UPPERCUT              22916

struct boss_noxxionAI : public ScriptedAI
{
    boss_noxxionAI(Creature *c) : ScriptedAI(c) {}

    uint32 ToxicVolley_Timer;
    uint32 Uppercut_Timer;
    uint32 Adds_Timer;
    uint32 Invisible_Timer;
    bool Invisible;

    void Reset()
    {
        ToxicVolley_Timer = 7000;
        Uppercut_Timer = 16000;
        Adds_Timer = 19000;
        Invisible_Timer = 15000;                            //Too much too low?
        Invisible = false;
    }

    void EnterCombat(Unit * /*who*/)
    {
    }

    void SummonAdds(Unit* pVictim)
    {
        if (Creature *Add = DoSpawnCreature(13456, irand(-7,7), irand(-7,7), 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 90000))
            Add->AI()->AttackStart(pVictim);
    }

    void UpdateAI(const uint32 diff)
    {
        if (Invisible && Invisible_Timer <= diff)
        {
            //Become visible again
            me->setFaction(14);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            //Noxxion model
            me->SetDisplayId(11172);
            Invisible = false;
            //me->m_canMove = true;
        } else if (Invisible)
        {
            Invisible_Timer -= diff;
            //Do nothing while invisible
            return;
        }

        //Return since we have no target
        if (!UpdateVictim())
            return;

        //ToxicVolley_Timer
        if (ToxicVolley_Timer <= diff)
        {
            DoCast(me->getVictim(), SPELL_TOXICVOLLEY);
            ToxicVolley_Timer = 9000;
        } else ToxicVolley_Timer -= diff;

        //Uppercut_Timer
        if (Uppercut_Timer <= diff)
        {
            DoCast(me->getVictim(), SPELL_UPPERCUT);
            Uppercut_Timer = 12000;
        } else Uppercut_Timer -= diff;

        //Adds_Timer
        if (!Invisible && Adds_Timer <= diff)
        {
            //Inturrupt any spell casting
            //me->m_canMove = true;
            me->InterruptNonMeleeSpells(false);
            me->setFaction(35);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            // Invisible Model
            me->SetDisplayId(11686);
            SummonAdds(me->getVictim());
            SummonAdds(me->getVictim());
            SummonAdds(me->getVictim());
            SummonAdds(me->getVictim());
            SummonAdds(me->getVictim());
            Invisible = true;
            Invisible_Timer = 15000;

            Adds_Timer = 40000;
        } else Adds_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_noxxion(Creature* pCreature)
{
    return new boss_noxxionAI (pCreature);
}

void AddSC_boss_noxxion()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_noxxion";
    newscript->GetAI = &GetAI_boss_noxxion;
    newscript->RegisterSelf();
}

