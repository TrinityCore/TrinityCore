/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: Boss_Sulfuron_Harbringer
SD%Complete: 80
SDComment: Adds NYI
SDCategory: Molten Core
EndScriptData */

/*
    Sulfuron should walk to a random point ~10 yds behind him before casting Flamespear
*/

#include "scriptPCH.h"
#include "molten_core.h"

#define SPELL_DARKSTRIKE            19777
#define SPELL_DEMORALIZINGSHOUT     19778
#define SPELL_INSPIRE               19779
#define SPELL_KNOCKDOWN             19780
#define SPELL_FLAMESPEAR            19781

struct boss_sulfuronAI : public ScriptedAI
{
    boss_sulfuronAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    uint32 Darkstrike_Timer;
    uint32 DemoralizingShout_Timer;
    uint32 Inspire_Timer;
    uint32 Knockdown_Timer;
    uint32 Flamespear_Timer;
    ScriptedInstance* m_pInstance;

    void Reset() override
    {
        Darkstrike_Timer        = 10000;                     //These times are probably wrong
        DemoralizingShout_Timer = 15000;
        Inspire_Timer           = 13000;
        Knockdown_Timer         = 6000;
        Flamespear_Timer        = 2000;

        if (m_pInstance && m_creature->IsAlive())
            m_pInstance->SetData(TYPE_SULFURON, NOT_STARTED);
    }

    void Aggro(Unit* pWho) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_SULFURON, IN_PROGRESS);
        m_creature->SetInCombatWithZone();
    }

    void JustDied(Unit* pKiller) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_SULFURON, DONE);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //DemoralizingShout_Timer
        if (DemoralizingShout_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_DEMORALIZINGSHOUT) == CAST_OK)
                DemoralizingShout_Timer = urand(15000, 20000);
        }
        else DemoralizingShout_Timer -= diff;

        //Inspire_Timer
        if (Inspire_Timer < diff)
        {
            Creature* target = nullptr;
            std::list<Creature*> pList = DoFindFriendlyMissingBuff(45.0f, SPELL_INSPIRE);
            if (!pList.empty())
            {
                std::list<Creature*>::iterator i = pList.begin();
                advance(i, (rand() % pList.size()));
                target = (*i);
            }

            if (target)
            {
                if (DoCastSpellIfCan(target, SPELL_INSPIRE) != CAST_OK)
                    return;
            }

            if (DoCastSpellIfCan(m_creature, SPELL_INSPIRE) == CAST_OK)
                Inspire_Timer = urand(20000, 26000);
        }
        else Inspire_Timer -= diff;

        //Knockdown_Timer
        if (Knockdown_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_KNOCKDOWN) == CAST_OK)
                Knockdown_Timer = urand(12000, 15000);
        }
        else Knockdown_Timer -= diff;

        //Flamespear_Timer
        if (Flamespear_Timer < diff)
        {
            if (Unit* target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
            {
                if (DoCastSpellIfCan(target, SPELL_FLAMESPEAR) == CAST_OK)
                    Flamespear_Timer = urand(12000, 16000);
            }
        }
        else Flamespear_Timer -= diff;

        //DarkStrike_Timer
        if (Darkstrike_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_DARKSTRIKE) == CAST_OK)
                Darkstrike_Timer = urand(15000, 18000);
        }
        else Darkstrike_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_sulfuron(Creature* pCreature)
{
    return new boss_sulfuronAI(pCreature);
}

void AddSC_boss_sulfuron()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "boss_sulfuron";
    newscript->GetAI = &GetAI_boss_sulfuron;
    newscript->RegisterSelf();
}
