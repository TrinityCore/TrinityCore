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

/* Script Data Start
SDName: boss_amanitar
SDAuthor: LordVanMartin
SD%Complete: 0
SDComment:  Only appears in heroic mode
SDCategory: Ahn'kahet
Script Data End */

/*** SQL START *** 
update creature_template set scriptname = 'boss_amanitar' where entry = '';
*** SQL END ***/

#include "precompiled.h"
#include "def_ahnkahet.h"

#define SPELL_BASH                                   57094
#define SPELL_ENTANGLING_ROOTS                       57095
#define SPELL_MINI                                   57055
#define SPELL_VENOM_BOLT_VOLLEY                      57088        

struct TRINITY_DLL_DECL boss_amanitarAI : public ScriptedAI
{
    boss_amanitarAI(Creature *c) : ScriptedAI(c) {}
    
    void Reset() {}
    
    void EnterCombat(Unit* who) {}
    void AttackStart(Unit* who) {}
    void MoveInLineOfSight(Unit* who) {}
    void UpdateAI(const uint32 diff) 
    {
        //Return since we have no target
        if(!UpdateVictim())
            return;
            
        DoMeleeAttackIfReady();
    }
    
    void JustDied(Unit* killer)  {}

    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;
    }
};

CreatureAI* GetAI_boss_amanitar(Creature *_Creature)
{
    return new boss_amanitarAI (_Creature);
}

void AddSC_boss_amanitar()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_amanitar";
    newscript->GetAI = GetAI_boss_amanitar;
    newscript->RegisterSelf();
}
