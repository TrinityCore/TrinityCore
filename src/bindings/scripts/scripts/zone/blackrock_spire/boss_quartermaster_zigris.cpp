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
SDName: Boss_Quartmaster_Zigris
SD%Complete: 100
SDComment: Needs revision
SDCategory: Blackrock Spire
EndScriptData */

#include "precompiled.h"

#define SPELL_SHOOT             16496
#define SPELL_STUNBOMB          16497
#define SPELL_HEALING_POTION    15504
#define SPELL_HOOKEDNET         15609

struct TRINITY_DLL_DECL boss_quatermasterzigrisAI : public ScriptedAI
{
    boss_quatermasterzigrisAI(Creature *c) : ScriptedAI(c) {}

    uint32 Shoot_Timer;
    uint32 StunBomb_Timer;
    //uint32 HelingPotion_Timer;

    void Reset()
    {
        Shoot_Timer = 1000;
        StunBomb_Timer = 16000;
        //HelingPotion_Timer = 25000;
    }

    void Aggro(Unit *who)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim() )
            return;

        //Shoot_Timer
        if (Shoot_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_SHOOT);
            Shoot_Timer = 500;
        }else Shoot_Timer -= diff;

        //StunBomb_Timer
        if (StunBomb_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_STUNBOMB);
            StunBomb_Timer = 14000;
        }else StunBomb_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_quatermasterzigris(Creature *_Creature)
{
    return new boss_quatermasterzigrisAI (_Creature);
}

void AddSC_boss_quatermasterzigris()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="quartermaster_zigris";
    newscript->GetAI = &GetAI_boss_quatermasterzigris;
    newscript->RegisterSelf();
}

