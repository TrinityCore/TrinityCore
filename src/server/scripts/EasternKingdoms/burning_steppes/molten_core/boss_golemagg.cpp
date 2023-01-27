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
SDName: Boss_Golemagg
SD%Complete: 75
SDComment: Timers need to be confirmed, Golemagg's Trust need to be checked
SDCategory: Molten Core
EndScriptData */

/*
    Golemagg and his adds should evade if dogs are pulled too far away from Golemagg
*/

#include "scriptPCH.h"
#include "molten_core.h"

enum
{
    SPELL_MAGMASPLASH       = 13879,
    SPELL_PYROBLAST         = 20228,
    SPELL_EARTHQUAKE        = 19798,
    SPELL_ENRAGE            = 19953,
    SPELL_GOLEMAGG_TRUST    = 20553,

    // Core Rager
    EMOTE_LOWHP             = -1409002,
    SPELL_MANGLE            = 19820,
    SPELL_TRASH             = 3391
};

struct boss_golemaggAI : public ScriptedAI
{
    boss_golemaggAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 m_uiPyroblastTimer;
    uint32 m_uiEarthquakeTimer;
    uint32 TickTimer;
    bool m_bEnraged;

    void Reset() override
    {
        m_uiPyroblastTimer = 7 * IN_MILLISECONDS;            // These timers are probably wrong
        m_uiEarthquakeTimer = 3 * IN_MILLISECONDS;
        TickTimer = 10000;
        m_bEnraged = false;

        if (m_pInstance && m_creature->IsAlive())
            m_pInstance->SetData(TYPE_GOLEMAGG, NOT_STARTED);


        std::list<Creature*> ChiensListe;
        GetCreatureListWithEntryInGrid(ChiensListe, m_creature, 11672, 150.0f);
        if (!ChiensListe.empty())
        {
            for (const auto& itr : ChiensListe)
            {
                if (itr->GetDeathState() == ALIVE)
                    itr->DealDamage(itr, itr->GetHealth(), nullptr, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false);
                itr->Respawn();
            }
        }
        //    available in creature_addon
        //    m_creature->CastSpell(m_creature, SPELL_MAGMASPLASH, true);
    }

    void Aggro(Unit* pWho) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_GOLEMAGG, IN_PROGRESS);
    }

    void JustDied(Unit* pKiller) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_GOLEMAGG, DONE);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        // Pyroblast
        if (m_uiPyroblastTimer < uiDiff)
        {
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
            {
                if (DoCastSpellIfCan(pTarget, SPELL_PYROBLAST) == CAST_OK)
                    m_uiPyroblastTimer = (3 + rand() % 4) * IN_MILLISECONDS;
            }
        }
        else
            m_uiPyroblastTimer -= uiDiff;

        // Enrage
        if (!m_bEnraged && m_creature->GetHealthPercent() < 10.0f)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_ENRAGE) == CAST_OK)
                m_bEnraged = true;
        }

        if (TickTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_GOLEMAGG_TRUST) == CAST_OK)
                TickTimer = 2000;
        }
        else TickTimer -= uiDiff;

        // Earthquake
        if (m_bEnraged)
        {
            if (m_uiEarthquakeTimer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_EARTHQUAKE) == CAST_OK)
                    m_uiEarthquakeTimer = 3 * IN_MILLISECONDS;
            }
            else
                m_uiEarthquakeTimer -= uiDiff;
        }


        DoMeleeAttackIfReady();
    }
};

struct mob_core_ragerAI : public ScriptedAI
{
    mob_core_ragerAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;
    uint32 m_uiMangleTimer;
    uint32 TickTimer;

    void Reset() override
    {
        TickTimer = 1000;
        m_uiMangleTimer = 7 * IN_MILLISECONDS;               // These times are probably wrong
    }

    void DamageTaken(Unit* pDoneBy, uint32& uiDamage) override
    {
        if (m_pInstance)
        {
            if (Creature* pGolemagg = m_pInstance->instance->GetCreature(m_pInstance->GetData64(DATA_GOLEMAGG)))
            {
                if (pGolemagg->IsAlive())
                {
                    if (m_creature->GetHealthPercent() < 50.0f)
                    {
                        DoScriptText(EMOTE_LOWHP, m_creature);
                        m_creature->SetHealth(m_creature->GetMaxHealth());
                    }
                }
                else
                    m_creature->DisappearAndDie();
            }
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        // Mangle
        if (m_uiMangleTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_MANGLE) == CAST_OK)
                m_uiMangleTimer = 10 * IN_MILLISECONDS;
        }
        else
            m_uiMangleTimer -= uiDiff;

        if (TickTimer < uiDiff)
        {
            TickTimer = 1000;
            if (!m_creature->HasAura(SPELL_TRASH) && !(bool)(rand() % 10))
                m_creature->CastSpell(m_creature, SPELL_TRASH, true);
        }
        else TickTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_golemagg(Creature* pCreature)
{
    return new boss_golemaggAI(pCreature);
}

CreatureAI* GetAI_mob_core_rager(Creature* pCreature)
{
    return new mob_core_ragerAI(pCreature);
}

void AddSC_boss_golemagg()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "boss_golemagg";
    newscript->GetAI = &GetAI_boss_golemagg;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_core_rager";
    newscript->GetAI = &GetAI_mob_core_rager;
    newscript->RegisterSelf();
}
