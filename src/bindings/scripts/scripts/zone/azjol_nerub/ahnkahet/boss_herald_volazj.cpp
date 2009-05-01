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
SDName: boss_herald_volazj
SDAuthor: LordVanMartin
SD%Complete: 0
SDComment:
SDCategory: Ahn'kahet
EndScriptData */

/*** SQL START ***
update creature_template set scriptname = 'boss_volazj' where entry = '';
*** SQL END ***/

#include "precompiled.h"
#include "def_ahnkahet.h"

//Spells
#define SPELL_INSANITY                         57496 //Dummy
#define INSANITY_VISUAL                        57561
#define SPELL_MIND_FLAY_N                      57941
#define SPELL_MIND_FLAY_H                      59974
#define SPELL_SHADOW_BOLT_VOLLEY_1             57942
#define SPELL_SHADOW_BOLT_VOLLEY_2             59975
#define SPELL_SHIVER_N                         57949
#define SPELL_SHIVER_H                         59978

//Yell
#define SAY_AGGRO                               -1619030
#define SAY_SLAY_1                              -1619031
#define SAY_SLAY_2                              -1619032
#define SAY_SLAY_3                              -1619033
#define SAY_DEATH_1                             -1619034
#define SAY_DEATH_2                             -1619035
#define SAY_PHASE                               -1619036

struct TRINITY_DLL_DECL boss_volazjAI : public ScriptedAI
{
    boss_volazjAI(Creature *c) : ScriptedAI(c) {}

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
        if(!UpdateVictim())
            return;

        phase =1;

        DoMeleeAttackIfReady();
    }
    void JustDied(Unit* killer)
    {
        if(phase == 1)
        DoScriptText(SAY_DEATH_1, m_creature);
        else
        DoScriptText(SAY_DEATH_2, m_creature);
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

CreatureAI* GetAI_boss_volazj(Creature *_Creature)
{
    return new boss_volazjAI (_Creature);
}

void AddSC_boss_volazj()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_volazj";
    newscript->GetAI = &GetAI_boss_volazj;
    newscript->RegisterSelf();
}
