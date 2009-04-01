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
SDName: Boss_Gehennas
SD%Complete: 90
SDComment: Adds MC NYI
SDCategory: Molten Core
EndScriptData */

#include "precompiled.h"

#define SPELL_SHADOWBOLT            19728
#define SPELL_RAINOFFIRE            19717
#define SPELL_GEHENNASCURSE         19716

struct TRINITY_DLL_DECL boss_gehennasAI : public ScriptedAI
{
    boss_gehennasAI(Creature *c) : ScriptedAI(c) {}

    uint32 ShadowBolt_Timer;
    uint32 RainOfFire_Timer;
    uint32 GehennasCurse_Timer;

    void Reset()
    {
        ShadowBolt_Timer = 6000;
        RainOfFire_Timer = 10000;
        GehennasCurse_Timer = 12000;
    }

    void Aggro(Unit *who) { }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //ShadowBolt_Timer
        if (ShadowBolt_Timer < diff)
        {
            if( Unit* bTarget = SelectUnit(SELECT_TARGET_RANDOM,1) )
                DoCast(bTarget,SPELL_SHADOWBOLT);
            ShadowBolt_Timer = 7000;
        }else ShadowBolt_Timer -= diff;

        //RainOfFire_Timer
        if (RainOfFire_Timer < diff)
        {
            if( Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0) )
                DoCast(target,SPELL_RAINOFFIRE);

            RainOfFire_Timer = 4000 + rand()%8000;
        }else RainOfFire_Timer -= diff;

        //GehennasCurse_Timer
        if (GehennasCurse_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_GEHENNASCURSE);
            GehennasCurse_Timer = 22000 + rand()%8000;
        }else GehennasCurse_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_gehennas(Creature *_Creature)
{
    return new boss_gehennasAI (_Creature);
}

void AddSC_boss_gehennas()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_gehennas";
    newscript->GetAI = &GetAI_boss_gehennas;
    newscript->RegisterSelf();
}

