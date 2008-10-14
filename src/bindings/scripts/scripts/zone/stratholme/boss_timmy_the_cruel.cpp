/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: boss_timmy_the_cruel
SD%Complete: 100
SDComment: 
SDCategory: Stratholme
EndScriptData */

#include "precompiled.h"

#define SAY_SPAWN   "TIMMY!"

#define SPELL_RAVENOUSCLAW    17470

struct TRINITY_DLL_DECL boss_timmy_the_cruelAI : public ScriptedAI
{
    boss_timmy_the_cruelAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 RavenousClaw_Timer;
    bool HasYelled;

    void Reset()
    {
        RavenousClaw_Timer = 10000;
        HasYelled = false;
    }

    void Aggro(Unit *who)
    {
    }

    void MoveInLineOfSight(Unit *who)
    {
        if (!who || m_creature->getVictim())
            return;

        if (who->isTargetableForAttack() && who->isInAccessablePlaceFor(m_creature) && m_creature->IsHostileTo(who))
        {
            float attackRadius = m_creature->GetAttackDistance(who);
            if (m_creature->IsWithinDistInMap(who, attackRadius) && m_creature->GetDistanceZ(who) <= CREATURE_Z_ATTACK_RANGE && m_creature->IsWithinLOSInMap(who))
            {
                if(who->HasStealthAura())
                    who->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);

                if (!HasYelled)
                {
                    DoYell(SAY_SPAWN,LANG_UNIVERSAL,NULL);
                    HasYelled = true;
                }

                //Begin melee attack if we are within range
                DoStartAttackAndMovement(who);
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        //RavenousClaw
        if (RavenousClaw_Timer < diff)
        {
            //Cast
            DoCast(m_creature->getVictim(),SPELL_RAVENOUSCLAW);
            //15 seconds until we should cast this again
            RavenousClaw_Timer = 15000;
        }else RavenousClaw_Timer -= diff;

        DoMeleeAttackIfReady();
    }
}; 
CreatureAI* GetAI_boss_timmy_the_cruel(Creature *_Creature)
{
    return new boss_timmy_the_cruelAI (_Creature);
}


void AddSC_boss_timmy_the_cruel()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_timmy_the_cruel";
    newscript->GetAI = GetAI_boss_timmy_the_cruel;
    m_scripts[nrscripts++] = newscript;
}
