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
SDName: boss_elder_nadox
SDAuthor: LordVanMartin
SD%Complete: 0
SDComment:
SDCategory: Ahn'kahet
EndScriptData */

/*** SQL START *** 
update creature_template set scriptname = 'boss_nadox' where entry = '';
*** SQL END ***/

#include "precompiled.h"
#include "def_ahnkahet.h"

#define SPELL_BROOD_PLAGUE                  56130
#define H_SPELL_BROOD_PLAGUE                59467
#define SPELL_BROOD_RAGE                    59465 //--> Heroic -- Enrages a Swarmer, increasing size and damage done.

#define MOB_AHNKAHAR_SWARMER                30178
#define SPELL_SUMMON_SWARMERS               56119//2x 30178

#define MOB_AHNKAHAR_SWARMER                30178
#define SPELL_SUMMON_SWARM_GUARD            56120//1x 30176
#define SPELL_DEADLY_POISON                 56145// Proc trigger
#define H_SPELL_DEADLY_POISON               59479// Proc trigger
#define SPELL_GUARDIAN_AURA                 56151

//randomly summons NPC 30178 and 30176 they can cast Sprint (56354)

//Yell
#define SAY_AGGRO                              -1619014
#define SAY_SLAY_1                             -1619015
#define SAY_SLAY_2                             -1619016
#define SAY_SLAY_3                             -1619017
#define SAY_DEATH                              -1619018
#define SAY_EGG_SAC_1                          -1619019
#define SAY_EGG_SAC_2                          -1619020

struct TRINITY_DLL_DECL boss_nadoxAI : public ScriptedAI
{
    boss_nadoxAI(Creature *c) : ScriptedAI(c) {}

    uint32 plague,
           summon;
    
    void Reset() {}
    
    void Aggro(Unit* who) 
    {
        DoScriptText(SAY_AGGRO, m_creature);
    }
    void AttackStart(Unit* who) {}
    void MoveInLineOfSight(Unit* who) {}
    void UpdateAI(const uint32 diff) 
    {
        //Return since we have no target
        if(!UpdateVictim())
            return;
   
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
    
    void summon_swarmer(){}
    void summon_guardian(){}
};

CreatureAI* GetAI_boss_nadox(Creature *_Creature)
{
    return new boss_nadoxAI (_Creature);
}

void AddSC_boss_nadox()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_nadox";
    newscript->GetAI = GetAI_boss_nadox;
    newscript->RegisterSelf();
}
