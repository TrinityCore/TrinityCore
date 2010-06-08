/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: Boss_Interrogator_Vishas
SD%Complete: 100
SDComment:
SDCategory: Scarlet Monastery
EndScriptData */

#include "ScriptPCH.h"
#include "scarlet_monastery.h"

enum eEnums
{
    SAY_AGGRO               = -1189011,
    SAY_HEALTH1             = -1189012,
    SAY_HEALTH2             = -1189013,
    SAY_KILL                = -1189014,
    SAY_TRIGGER_VORREL      = -1189015,

    SPELL_SHADOWWORDPAIN    = 2767,
};

struct boss_interrogator_vishasAI : public ScriptedAI
{
    boss_interrogator_vishasAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = me->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    bool Yell30;
    bool Yell60;
    uint32 ShadowWordPain_Timer;

    void Reset()
    {
        ShadowWordPain_Timer = 5000;
    }

    void EnterCombat(Unit * /*who*/)
    {
        DoScriptText(SAY_AGGRO, me);
    }

    void KilledUnit(Unit* /*Victim*/)
    {
        DoScriptText(SAY_KILL, me);
    }

    void JustDied(Unit* /*Killer*/)
    {
        if (!pInstance)
            return;

        //Any other actions to do with vorrel? setStandState?
        if (Unit *vorrel = Unit::GetUnit(*me,pInstance->GetData64(DATA_VORREL)))
            DoScriptText(SAY_TRIGGER_VORREL, vorrel);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //If we are low on hp Do sayings
        if (!Yell60 && ((me->GetHealth()*100) / me->GetMaxHealth() <= 60))
        {
            DoScriptText(SAY_HEALTH1, me);
            Yell60 = true;
        }

        if (!Yell30 && ((me->GetHealth()*100) / me->GetMaxHealth() <= 30))
        {
            DoScriptText(SAY_HEALTH2, me);
            Yell30 = true;
        }

        //ShadowWordPain_Timer
        if (ShadowWordPain_Timer <= diff)
        {
            DoCast(me->getVictim(), SPELL_SHADOWWORDPAIN);
            ShadowWordPain_Timer = 5000 + rand()%10000;
        } else ShadowWordPain_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_interrogator_vishas(Creature* pCreature)
{
    return new boss_interrogator_vishasAI (pCreature);
}

void AddSC_boss_interrogator_vishas()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_interrogator_vishas";
    newscript->GetAI = &GetAI_boss_interrogator_vishas;
    newscript->RegisterSelf();
}

