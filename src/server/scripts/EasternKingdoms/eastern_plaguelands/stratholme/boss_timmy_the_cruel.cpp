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
SDName: boss_timmy_the_cruel
SD%Complete: 100
SDComment:
SDCategory: Stratholme
EndScriptData */

#include "scriptPCH.h"

#define SAY_SPAWN               -1900160

#define SPELL_RAVENOUSCLAW      17470
#define SPELL_ENRAGE            8599

#define TIMMY_ENTRY             10808

struct boss_timmy_the_cruelAI : public ScriptedAI
{
    boss_timmy_the_cruelAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiRavenousClawTimer;

    void Reset() override
    {
        m_uiRavenousClawTimer = 7000;
    }

    void UpdateAI(uint32 const diff) override
    {
        // Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        // Ravenous Claw
        if (m_uiRavenousClawTimer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_RAVENOUSCLAW) == CAST_OK)
                m_uiRavenousClawTimer = 12000;
        }
        else
            m_uiRavenousClawTimer -= diff;

        if (m_creature->GetHealthPercent() < 10.0f && !m_creature->HasAura(SPELL_ENRAGE))
            m_creature->CastSpell(m_creature, SPELL_ENRAGE, true);

        DoMeleeAttackIfReady();
    }

    void CorpseRemoved(uint32 &respawnDelay) override
    {
        m_creature->DeleteLater();
    }
};

CreatureAI* GetAI_boss_timmy_the_cruel(Creature* pCreature)
{
    return new boss_timmy_the_cruelAI(pCreature);
}

struct npc_crimson_guardsmanAI : public ScriptedAI
{
    npc_crimson_guardsmanAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
        m_bIsTimmySpawner = pCreature->GetDBTableGUIDLow() == 54070;
    }

    bool m_bIsTimmySpawner;
    uint32 m_uiDisarmTimer;
    uint32 m_uiShieldBashTimer;
    uint32 m_uiShieldChargeTimer;

    void Reset() override
    {
        m_uiDisarmTimer = 6000;
        m_uiShieldBashTimer = 4000;
        m_uiShieldChargeTimer = 1000;
    }

    void JustDied(Unit* pKiller) override
    {
        if (m_bIsTimmySpawner)
        {
            Creature* pTimmy =
                    m_creature->SummonCreature(TIMMY_ENTRY, 3614.7f, -3187.64f,
                                               131.406f, 0.0f,
                                               TEMPSUMMON_MANUAL_DESPAWN, 0);

            if (pTimmy)
            {
                pTimmy->MonsterYell(SAY_SPAWN, 0, pKiller);
                pTimmy->SetRespawnTime(9999999);
            }

            m_bIsTimmySpawner = false;
            m_creature->DeleteLater();
        }
    }

    void UpdateAI(uint32 const diff) override
    {
        // Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiDisarmTimer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), 6713) == CAST_OK)
                m_uiDisarmTimer = 15000;
        }
        else
            m_uiDisarmTimer -= diff;

        if (m_uiShieldBashTimer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), 11972) == CAST_OK)
                m_uiShieldBashTimer = 8000;
        }
        else
            m_uiShieldBashTimer -= diff;

        if (m_uiShieldChargeTimer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), 15749) == CAST_OK)
                m_uiShieldChargeTimer = 12000;
        }
        else
            m_uiShieldChargeTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_crimson_guardsman(Creature* pCreature)
{
    return new npc_crimson_guardsmanAI(pCreature);
}

void AddSC_boss_timmy_the_cruel()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "boss_timmy_the_cruel";
    newscript->GetAI = &GetAI_boss_timmy_the_cruel;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_crimson_guardsman";
    newscript->GetAI = &GetAI_npc_crimson_guardsman;
    newscript->RegisterSelf();
}
