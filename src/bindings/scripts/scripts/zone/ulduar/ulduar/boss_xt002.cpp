/*
 * Copyright (C) 2008 - 2009 Trinity <http://www.trinitycore.org/>
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

#include "precompiled.h"
#include "def_ulduar.h"

#define SPELL_SEARING_LIGHT         63018
#define SPELL_SONIC_BOOM            38897

#define SAY_AGGRO                   -1000000
#define SAY_SLAY                    -1000001
struct TRINITY_DLL_DECL boss_xt002_AI : public ScriptedAI
{
    boss_xt002_AI(Creature *c) : ScriptedAI(c) {}

    uint32 SEARING_LIGHT_Timer;
    uint32 SONIC_BOOM_Timer;

    void Reset()
    {
        SEARING_LIGHT_Timer = 100;
        SONIC_BOOM_Timer = 20;
    }

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO,m_creature);
    }
    void KilledUnit(Unit* victim)
    {
        DoScriptText(SAY_SLAY, m_creature);
    }

    void JustDied(Unit *victim)
    {
        DoScriptText(SAY_SLAY, m_creature);
    }

    void MoveInLineOfSight(Unit* who) {}

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (SEARING_LIGHT_Timer < diff)
        {
            DoCast(m_creature,SPELL_SEARING_LIGHT);
            DoScriptText(SAY_SLAY, m_creature);
            SEARING_LIGHT_Timer = 50000;
        } else SEARING_LIGHT_Timer -= diff;

        if (SONIC_BOOM_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_SONIC_BOOM);
            SONIC_BOOM_Timer = 20000;
        } else SONIC_BOOM_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_xt002(Creature *_Creature)
{
    return new boss_xt002_AI (_Creature);
}
void AddSC_boss_xt002()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_xt002";
    newscript->GetAI = &GetAI_boss_xt002;
    newscript->RegisterSelf();
}
