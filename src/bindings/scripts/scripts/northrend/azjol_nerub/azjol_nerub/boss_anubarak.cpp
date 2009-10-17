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
SDName: boss_anubarak
SDAuthor: LordVanMartin
SD%Complete: 0
SDComment:
SDCategory: Azjol Nerub
EndScriptData */

/*** SQL START ***
update creature_template set scriptname = 'boss_anub_arak' where entry = '';
*** SQL END ***/

#include "precompiled.h"
#include "def_azjol_nerub.h"

//Spells
#define SPELL_CARRION_BEETLES                         53520
#define SPELL_LOCUST_SWARM                            53467
#define SPELL_IMPALE                                  53454
#define SPELL_POUND                                   53472

// not in db
//Yell
#define SAY_INTRO                                  -1601010
#define SAY_AGGRO                                  -1601000
#define SAY_SLAY_1                                 -1601001
#define SAY_SLAY_2                                 -1601002
#define SAY_SLAY_3                                 -1601003
#define SAY_LOCUST_1                               -1601005
#define SAY_LOCUST_2                               -1601006
#define SAY_LOCUST_3                               -1601007
#define SAY_SUBMERGE_1                             -1601008
#define SAY_SUBMERGE_2                             -1601009
#define SAY_DEATH                                  -1601004

struct TRINITY_DLL_DECL boss_anub_arakAI : public ScriptedAI
{
    boss_anub_arakAI(Creature *c) : ScriptedAI(c) {}

    uint32 phase;

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
        if (!UpdateVictim())
            return;

        phase =1;

        if ((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) <= 33)
            phase = 2;
        if ((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) == 15)
            phase = 3;

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

        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3), m_creature);
    }
};

CreatureAI* GetAI_boss_anub_arak(Creature* pCreature)
{
    return new boss_anub_arakAI (pCreature);
}

void AddSC_boss_anub_arak()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_anub_arak";
    newscript->GetAI = &GetAI_boss_anub_arak;
    newscript->RegisterSelf();
}
