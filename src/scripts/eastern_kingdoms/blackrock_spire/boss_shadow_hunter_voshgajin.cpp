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
SDName: Boss_Shadow_Hunter_Voshgajin
SD%Complete: 100
SDComment:
SDCategory: Blackrock Spire
EndScriptData */

#include "ScriptedPch.h"

#define SPELL_CURSEOFBLOOD      24673
#define SPELL_HEX               16708
#define SPELL_CLEAVE            20691

struct boss_shadowvoshAI : public ScriptedAI
{
    boss_shadowvoshAI(Creature *c) : ScriptedAI(c) {}

    uint32 CurseOfBlood_Timer;
    uint32 Hex_Timer;
    uint32 Cleave_Timer;

    void Reset()
    {
        CurseOfBlood_Timer = 2000;
        Hex_Timer = 8000;
        Cleave_Timer = 14000;

        //DoCast(m_creature, SPELL_ICEARMOR, true);
    }

    void EnterCombat(Unit *who){}

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        //CurseOfBlood_Timer
        if (CurseOfBlood_Timer <= diff)
        {
            DoCast(m_creature->getVictim(), SPELL_CURSEOFBLOOD);
            CurseOfBlood_Timer = 45000;
        } else CurseOfBlood_Timer -= diff;

        //Hex_Timer
        if (Hex_Timer <= diff)
        {
            if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                DoCast(pTarget, SPELL_HEX);
            Hex_Timer = 15000;
        } else Hex_Timer -= diff;

        //Cleave_Timer
        if (Cleave_Timer <= diff)
        {
            DoCast(m_creature->getVictim(), SPELL_CLEAVE);
            Cleave_Timer = 7000;
        } else Cleave_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_shadowvosh(Creature* pCreature)
{
    return new boss_shadowvoshAI (pCreature);
}

void AddSC_boss_shadowvosh()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_shadow_hunter_voshgajin";
    newscript->GetAI = &GetAI_boss_shadowvosh;
    newscript->RegisterSelf();
}

