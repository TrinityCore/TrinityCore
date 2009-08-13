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
SDName: boss_prince_taldaram
SDAuthor: LordVanMartin
SD%Complete: 0
SDComment:
SDCategory: Ahn'kahet
EndScriptData */

#include "precompiled.h"
#include "def_ahnkahet.h"

#define SPELL_BLOODTHIRST                   55968 //Trigger Spell + add aura
#define SPELL_CONJURE_FLAME_SPHERE          55931

#define SPELL_FLAME_SPHERE_SUMMON_1         55895// 1x 30106
#define H_SPELL_FLAME_SPHERE_SUMMON_1       59511// 1x 31686
#define H_SPELL_FLAME_SPHERE_SUMMON_2       59512// 1x 31687
#define SPELL_FLAME_SPHERE_SPAWN_EFFEKT     55891
#define SPELL_FLAME_SPHERE_VISUAL           55928
#define SPELL_FLAME_SPHERE_PERIODIC         55926
#define H_SPELL_FLAME_SPHERE_PERIODIC       59508
#define SPELL_FLAME_SPHERE_DEATH_EFFEKT     55947

#define SPELL_EMBRACE_OF_THE_VAMPYR         55959
#define H_SPELL_EMBRACE_OF_THE_VAMPYR       59513

#define SPELL_VANISH                        55964

//Yell
#define SAY_AGGRO                                -1619021
#define SAY_SLAY_1                               -1619022
#define SAY_SLAY_2                               -1619023
#define SAY_SLAY_3                               -1619024
#define SAY_DEATH                                -1619025
#define SAY_FEED_1                               -1619026
#define SAY_FEED_2                               -1619027
#define SAY_VANISH_1                             -1619028
#define SAY_VANISH_2                             -1619029

struct TRINITY_DLL_DECL boss_taldaramAI : public ScriptedAI
{
    boss_taldaramAI(Creature *c) : ScriptedAI(c) {}

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

CreatureAI* GetAI_boss_taldaram(Creature *_Creature)
{
    return new boss_taldaramAI (_Creature);
}

void AddSC_boss_taldaram()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_taldaram";
    newscript->GetAI = &GetAI_boss_taldaram;
    newscript->RegisterSelf();
}
