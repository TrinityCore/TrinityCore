/*
 * Copyright (C) 2009 Trinity <http://www.trinitycore.org/>
 *
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
SDName: boss_krikthir_the_gatewatcher
SDAuthor: LordVanMartin
SD%Complete: 0
SDComment: Placeholder
SDCategory: Azjol Nerub
EndScriptData */

/*** SQL START ***
update creature_template set scriptname = 'boss_krik_thir' where entry = '';
*** SQL END ***/

#include "precompiled.h"
#include "def_azjol_nerub.h"

#define SPELL_MIND_FLAY                     52586
#define H_SPELL_MIND_FLAY                   59367
#define SPELL_CURSE_OF_FATIGUE              52592
#define H_SPELL_CURSE_OF_FATIGUE            59368
#define SPELL_FRENZY                        28747 // maybe 53361

#define MOB_SKITTERING_SWARMER              28735
#define MOB_SKITTERING_SWARMER_CONTROLLER   32593

#define SPELL_SUMMON_SKITTERING_SWARMER     52438//AOE Effekt 140, maybe 52439
#define SPELL_SUMMON_SKITTERING_SWARMER     52439//Summon 3x 28735

//Yell
#define SAY_AGGRO                                    -1601011
#define SAY_SLAY_1                                   -1601012
#define SAY_SLAY_2                                   -1601013
#define SAY_SLAY_3                                   -1601014
#define SAY_DEATH                                    -1601015
#define SAY_SEND_GROUP_1                             -1601018
#define SAY_SEND_GROUP_2                             -1601019
#define SAY_SEND_GROUP_3                             -1601020
#define SAY_SWARM_1                                  -1601016
#define SAY_SWARM_2                                  -1601017
#define SAY_PREFIGHT_1                               -1601021
#define SAY_PREFIGHT_2                               -1601022
#define SAY_PREFIGHT_3                               -1601023

struct TRINITY_DLL_DECL boss_krik_thirAI : public ScriptedAI
{
    boss_krik_thirAI(Creature *c) : ScriptedAI(c) {}

    void Reset() {}

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
    }

    void UpdateAI(const uint32 diff)
    {
        if(!UpdateVictim())
            return;

        if ((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) >= 10)
        {
            //Frenzy
        }

        DoMeleeAttackIfReady();
    }
    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, m_creature);
    }
    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;

        switch(rand()%3)
        {
            case 0: DoScriptText(SAY_SLAY_1, m_creature);break;
            case 1: DoScriptText(SAY_SLAY_2, m_creature);break;
            case 2: DoScriptText(SAY_SLAY_3, m_creature);break;
        }
    }
};

CreatureAI* GetAI_boss_krik_thir(Creature *_Creature)
{
    return new boss_krik_thirAI (_Creature);
}

void AddSC_boss_krik_thir()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_krik_thir";
    newscript->GetAI = &GetAI_boss_krik_thir;
    newscript->RegisterSelf();

}
