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
SDName: boss_jedoga_shadowseeker
SDAuthor: LordVanMartin
SD%Complete: 0
SDComment:
SDCategory: Ahn'kahet
EndScriptData */

/*** SQL START *** 
update creature_template set scriptname = 'boss_jedoga' where entry = '';
*** SQL END ***/

#include "precompiled.h"
#include "def_ahnkahet.h"

#define SPELL_CYCLONE_STRIKE                    56855
#define H_SPELL_CYCLONE_STRIKE                  60030//kein unterschied zu 56855 außer das 60030 1,5sec cast ist
#define SPELL_LIGHTNING_BOLT                    56891
#define H_SPELL_LIGHTNING_BOLT                  60032
#define SPELL_THUNDERSHOCK                      56926//AOE works
#define H_SPELL_THUNDERSHOCK                    60029//AOE works
#define SPELL_GIFT_OF_THE_HERALD                56219//triggert if sucessfull sacreficed

#define SAY_AGGRO                                 -1619000
#define SAY_C_SACRIFICE_1                         -1619001
#define SAY_C_SACRIFICE_2                         -1619002
#define SAY_SACRIFICE_1                           -1619003
#define SAY_SACRIFICE_2                           -1619004
#define SAY_SLAY_1                                -1619005
#define SAY_SLAY_2                                -1619006
#define SAY_SLAY_3                                -1619007
#define SAY_DEATH                                 -1619008
#define SAY_PREACHING_1                           -1619009 
#define SAY_PREACHING_2                           -1619010
#define SAY_PREACHING_3                           -1619011
#define SAY_PREACHING_4                           -1619012
#define SAY_PREACHING_5                           -1619013

struct TRINITY_DLL_DECL boss_jedogaAI : public ScriptedAI
{
    boss_jedogaAI(Creature *c) : ScriptedAI(c) {}

    void Reset() {}
    void EnterCombat(Unit* who) 
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
};

CreatureAI* GetAI_boss_jedoga(Creature *_Creature)
{
    return new boss_jedogaAI (_Creature);
}

void AddSC_boss_jedoga()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_jedoga";
    newscript->GetAI = GetAI_boss_jedoga;
    newscript->RegisterSelf();
}
