/*
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
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
SDName: Boss trollgore
SDAuthor: Tartalo
SD%Complete:
SDComment: TODO: spawn troll waves
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = 'boss_trollgore' where entry = '';
*** SQL END ***/
#include "precompiled.h"
#include "drak_tharon_keep.h"

enum Spells
{
    SPELL_INFECTED_WOUND                                   = 49637,
    SPELL_CRUSH                                            = 49639,
    SPELL_CORPSE_EXPLODE                                   = 49555,
    SPELL_CONSUME                                          = 49380,
    //Heroic spells
    H_SPELL_CORPSE_EXPLODE                                 = 59807,
    H_SPELL_CONSUME                                        = 59803
};
//not in db
enum Yells
{
    SAY_AGGRO                                              = -1600006,
    SAY_KILL                                               = -1600007,
    SAY_CONSUME                                            = -1600008,
    SAY_EXPLODE                                            = -1600009,
    SAY_DEATH                                              = -1600010
};
enum Achievements
{
    ACHIEV_CONSUMPTION_JUNCTION                            = 2151
};
enum Creatures
{
    NPC_DRAKKARI_INVADERS                                  = 22222
};

struct TRINITY_DLL_DECL boss_trollgoreAI : public ScriptedAI
{
    boss_trollgoreAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiConsumeTimer;
    uint32 uiAuraCountTimer;
    uint32 uiCrushTimer;
    uint32 uiInfectedWoundTimer;
    uint32 uiExplodeCorpseTimer;

    bool bAchiev;

    ScriptedInstance* pInstance;

    void Reset()
    {
        uiConsumeTimer = 15000;
        uiAuraCountTimer = 15500;
        uiCrushTimer = urand(1000,5000);
        uiInfectedWoundTimer = urand(6000,10000);
        uiExplodeCorpseTimer = 3000;

        bAchiev = HeroicMode;

        if (m_creature->HasAura(HEROIC(SPELL_CONSUME,H_SPELL_CONSUME)))
            m_creature->RemoveAura(HEROIC(SPELL_CONSUME,H_SPELL_CONSUME));
        
        if (pInstance)
            pInstance->SetData(DATA_TROLLGORE_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);

        if (pInstance)
            pInstance->SetData(DATA_TROLLGORE_EVENT, IN_PROGRESS);
    }
    void AttackStart(Unit* who) {}
    void MoveInLineOfSight(Unit* who) {}
    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (uiConsumeTimer < diff)
        {
            DoScriptText(SAY_CONSUME, m_creature);
            DoCast(HEROIC(SPELL_CONSUME,H_SPELL_CONSUME));
            uiConsumeTimer = 15000;
        } else uiConsumeTimer -= diff;

        if (bAchiev)
        {
            if (uiAuraCountTimer < diff)
            {
                if (m_creature->HasAura(HEROIC(SPELL_CONSUME,H_SPELL_CONSUME)))
                {
                    Aura *pConsumeAura = m_creature->GetAura(HEROIC(SPELL_CONSUME,H_SPELL_CONSUME));
                    if (pConsumeAura && pConsumeAura->GetStackAmount() > 9)
                        bAchiev = false;
                }
                uiAuraCountTimer = 16000;
            } else uiAuraCountTimer -= diff;
        }

        if (uiCrushTimer < diff)
        {
            DoCastVictim(SPELL_CRUSH);
            uiCrushTimer = urand(10000,15000);
        } else uiCrushTimer -= diff;

        if (uiInfectedWoundTimer < diff)
        {
            DoCastVictim(SPELL_INFECTED_WOUND);
            uiInfectedWoundTimer = urand(25000,35000);
        } else uiInfectedWoundTimer -= diff;

        if (uiExplodeCorpseTimer < diff)
        {
            DoCast(HEROIC(SPELL_CORPSE_EXPLODE,H_SPELL_CORPSE_EXPLODE));
            DoScriptText(SAY_EXPLODE, m_creature);
            uiExplodeCorpseTimer = urand(15000,19000);
        } uiExplodeCorpseTimer -= diff;

        DoMeleeAttackIfReady();
    }
    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, m_creature);

        if (pInstance)
        {
            if (bAchiev)
                pInstance->DoCompleteAchievement(ACHIEV_CONSUMPTION_JUNCTION);
            pInstance->SetData(DATA_TROLLGORE_EVENT, DONE);
        }
    }
    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;
        DoScriptText(SAY_KILL, m_creature);
    }
};

CreatureAI* GetAI_boss_trollgore(Creature* pCreature)
{
    return new boss_trollgoreAI (pCreature);
}

void AddSC_boss_trollgore()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_trollgore";
    newscript->GetAI = &GetAI_boss_trollgore;
    newscript->RegisterSelf();
}
