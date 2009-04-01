/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Moira_Bronzbeard
SD%Complete: 90
SDComment: Healing of Emperor NYI
SDCategory: Blackrock Depths
EndScriptData */

#include "precompiled.h"

#define SPELL_HEAL              10917
#define SPELL_RENEW             10929
#define SPELL_SHIELD            10901
#define SPELL_MINDBLAST         10947
#define SPELL_SHADOWWORDPAIN    10894
#define SPELL_SMITE             10934

struct TRINITY_DLL_DECL boss_moira_bronzebeardAI : public ScriptedAI
{
    boss_moira_bronzebeardAI(Creature *c) : ScriptedAI(c) {}

    uint32 Heal_Timer;
    uint32 MindBlast_Timer;
    uint32 ShadowWordPain_Timer;
    uint32 Smite_Timer;
    Unit* PlayerHolder;
    Unit* Target;
    bool Heal;

    void Reset()
    {
        Target = NULL;
        Heal_Timer = 12000;                                 //These times are probably wrong
        MindBlast_Timer = 16000;
        ShadowWordPain_Timer = 2000;
        Smite_Timer = 8000;
    }

    void Aggro(Unit *who)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim() )
            return;

        //MindBlast_Timer
        if (MindBlast_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_MINDBLAST);
            MindBlast_Timer = 14000;
        }else MindBlast_Timer -= diff;

        //ShadowWordPain_Timer
        if (ShadowWordPain_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_SHADOWWORDPAIN);
            ShadowWordPain_Timer = 18000;
        }else ShadowWordPain_Timer -= diff;

        //Smite_Timer
        if (Smite_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_SMITE);
            Smite_Timer = 10000;
        }else Smite_Timer -= diff;

    }
};
CreatureAI* GetAI_boss_moira_bronzebeard(Creature *_Creature)
{
    return new boss_moira_bronzebeardAI (_Creature);
}

void AddSC_boss_moira_bronzebeard()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_moira_bronzebeard";
    newscript->GetAI = &GetAI_boss_moira_bronzebeard;
    newscript->RegisterSelf();
}

