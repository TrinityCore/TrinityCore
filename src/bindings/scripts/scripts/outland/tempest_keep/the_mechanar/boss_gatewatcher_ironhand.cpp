/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/* ScriptData
SDName: Boss_Gatewatcher_Ironhand
SD%Complete: 75
SDComment:
SDCategory: Tempest Keep, The Mechanar
EndScriptData */

#include "precompiled.h"

#define SAY_AGGRO_1                     -1554006
#define SAY_HAMMER_1                    -1554007
#define SAY_HAMMER_2                    -1554008
#define SAY_SLAY_1                      -1554009
#define SAY_SLAY_2                      -1554010
#define SAY_DEATH_1                     -1554011
#define EMOTE_HAMMER                    -1554012

// Spells to be casted
#define SPELL_SHADOW_POWER              35322
#define H_SPELL_SHADOW_POWER            39193
#define SPELL_HAMMER_PUNCH              35326
#define SPELL_JACKHAMMER                35327
#define H_SPELL_JACKHAMMER              39194
#define SPELL_STREAM_OF_MACHINE_FLUID   35311

// Gatewatcher Iron-Hand AI
struct TRINITY_DLL_DECL boss_gatewatcher_iron_handAI : public ScriptedAI
{
    boss_gatewatcher_iron_handAI(Creature *c) : ScriptedAI(c)
    {
        HeroicMode = c->GetMap()->IsHeroic();
    }

    bool HeroicMode;

    uint32 Shadow_Power_Timer;
    uint32 Jackhammer_Timer;
    uint32 Stream_of_Machine_Fluid_Timer;

    void Reset()
    {
        Shadow_Power_Timer = 25000;
        Jackhammer_Timer = 45000;
        Stream_of_Machine_Fluid_Timer = 55000;

    }
    void EnterCombat(Unit *who)
    {
        DoScriptText(SAY_AGGRO_1, m_creature);
    }

    void KilledUnit(Unit* victim)
    {
        if (rand()%2)
            return;

        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2), m_creature);
    }

    void JustDied(Unit* Killer)
    {
        DoScriptText(SAY_DEATH_1, m_creature);
        //TODO: Add door check/open code
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        //Shadow Power
        if (Shadow_Power_Timer <= diff)
        {
            DoCast(m_creature,HEROIC(SPELL_SHADOW_POWER, H_SPELL_SHADOW_POWER));
            Shadow_Power_Timer = 20000 + rand()%8000;
        } else Shadow_Power_Timer -= diff;

        //Jack Hammer
        if (Jackhammer_Timer <= diff)
        {
            //TODO: expect cast this about 5 times in a row (?), announce it by emote only once
            DoScriptText(EMOTE_HAMMER, m_creature);
            DoCast(m_creature->getVictim(),HEROIC(SPELL_JACKHAMMER, H_SPELL_JACKHAMMER));

            //chance to yell, but not same time as emote (after spell in fact casted)
            if (rand()%2)
                return;

            DoScriptText(RAND(SAY_HAMMER_1,SAY_HAMMER_2), m_creature);
            Jackhammer_Timer = 30000;
        } else Jackhammer_Timer -= diff;

        //Stream of Machine Fluid
        if (Stream_of_Machine_Fluid_Timer <= diff)
        {
            DoCast(m_creature->getVictim(),SPELL_STREAM_OF_MACHINE_FLUID);
            Stream_of_Machine_Fluid_Timer = 35000 + rand()%15000;
        } else Stream_of_Machine_Fluid_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_gatewatcher_iron_hand(Creature* pCreature)
{
    return new boss_gatewatcher_iron_handAI (pCreature);
}

void AddSC_boss_gatewatcher_iron_hand()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_gatewatcher_iron_hand";
    newscript->GetAI = &GetAI_boss_gatewatcher_iron_hand;
    newscript->RegisterSelf();
}

