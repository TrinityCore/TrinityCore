/* Copyright (C) 2006 - 2011 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Broodlord_Lashlayer
SD%Complete: 100
SDComment:
SDCategory: Blackwing Lair
EndScriptData */

#include "scriptPCH.h"
#include "blackwing_lair.h"

enum
{
    SAY_AGGRO                   = -1469000,
    SAY_LEASH                   = -1469001,

    SPELL_CLEAVE                = 15284, //26350
    SPELL_KNOCK_AWAY            = 18670, //25778
    SPELL_BLAST_WAVE            = 23331,

    // World of Warcraft Client Patch 1.8.0 (2005-10-11)
    // - Fixed a bug that was causing Broodlord Lashlayer to do less damage 
    //   than intended with his Mortal Strike.
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_7_1
    SPELL_MORTAL_STRIKE         = 24573, // added to dbc in 1.7.0
#else
    SPELL_MORTAL_STRIKE         = 23847, // added to dbc in 1.6.0, removed in 1.8.0
#endif
    
};

struct boss_broodlordAI : public ScriptedAI
{
    boss_broodlordAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        m_bMobsDesactives = false;
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 m_uiCleaveTimer;
    uint32 m_uiBlastWaveTimer;
    uint32 m_uiMortalStrikeTimer;
    uint32 m_uiKnockAwayTimer;
    uint32 m_uiInCombatTimer;
    bool m_bMobsDesactives;

    void Reset() override
    {
        m_uiCleaveTimer         = 8000;                     // These times are probably wrong
        m_uiBlastWaveTimer      = 20000;
        m_uiMortalStrikeTimer   = 25000;
        m_uiKnockAwayTimer      = urand(20000, 25000);
        m_uiInCombatTimer       = 2000;
    }

    void Aggro(Unit* /*pWho*/) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_LASHLAYER, IN_PROGRESS);

        if (m_creature->IsAlive())
        {
            SetMobsDesactivated(true);
            DoScriptText(SAY_AGGRO, m_creature);
            m_creature->SetInCombatWithZone();
        }
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_LASHLAYER, DONE);

        SetMobsDesactivated(false);
    }

    void JustReachedHome() override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_LASHLAYER, FAIL);

        SetMobsDesactivated(false);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER && m_creature->IsWithinDistInMap(who, 40.0f) && m_creature->IsWithinLOSInMap(who) && !m_creature->IsInCombat()
                && who->IsInAccessablePlaceFor(m_creature) && !who->HasStealthAura())
            m_creature->SetInCombatWithZone();
    }

    void SpellHitTarget(Unit* pCaster, SpellEntry const* pSpell) override
    {
        if (pSpell->Id == SPELL_KNOCK_AWAY)
            m_creature->GetThreatManager().modifyThreatPercent(pCaster, -50);
    }

    void SetMobsDesactivated(bool on)
    {
        if (m_bMobsDesactives == on)
            return;

        std::vector<uint32> mobsEntries;
        std::vector<uint32>::iterator entriesIt;
        mobsEntries.push_back(12459); // Blackwing Warlock
        mobsEntries.push_back(13996); // Blackwing Technician
        mobsEntries.push_back(12457); // Blackwing Spellbinder
        mobsEntries.push_back(12461); // Death Talon Overseer

        for (entriesIt = mobsEntries.begin(); entriesIt != mobsEntries.end(); ++entriesIt)
        {
            std::list<Creature*> tmpMobsList;
            GetCreatureListWithEntryInGrid(tmpMobsList, m_creature, (*entriesIt), 300.0f);
            while (!tmpMobsList.empty())
            {
                Creature* curr = tmpMobsList.front();
                tmpMobsList.pop_front();
                // Creature summoned
                /*
                if (!curr->GetDBTableGUIDLow())
                    continue;
                */
                if (on)
                    curr->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_NPC);
                else
                    curr->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_NPC);
            }
        }
        m_bMobsDesactives = on;
        mobsEntries.clear();
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiInCombatTimer < uiDiff)
        {
            m_creature->SetInCombatWithZone();
            m_uiInCombatTimer = 2000;
        }
        else
            m_uiInCombatTimer -= uiDiff;


        // Cleave Timer
        if (m_uiCleaveTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CLEAVE) == CAST_OK)
                m_uiCleaveTimer = urand(13000, 20000);
        }
        else
            m_uiCleaveTimer -= uiDiff;

        // Blast Wave
        if (m_uiBlastWaveTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_BLAST_WAVE) == CAST_OK)
                m_uiBlastWaveTimer = urand(20000, 35000);
        }
        else
            m_uiBlastWaveTimer -= uiDiff;

        // Mortal Strike Timer
        if (m_uiMortalStrikeTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_MORTAL_STRIKE) == CAST_OK)
                m_uiMortalStrikeTimer = urand(20000, 30000);
        }
        else
            m_uiMortalStrikeTimer -= uiDiff;

        // Knock Away Timer
        if (m_uiKnockAwayTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_KNOCK_AWAY) == CAST_OK)
                m_uiKnockAwayTimer = urand(12000, 25000);
        }
        else
            m_uiKnockAwayTimer -= uiDiff;

        DoMeleeAttackIfReady();

        if (EnterEvadeIfOutOfCombatArea(uiDiff))
            DoScriptText(SAY_LEASH, m_creature);
    }
};

CreatureAI* GetAI_boss_broodlord(Creature* pCreature)
{
    return new boss_broodlordAI(pCreature);
}

void AddSC_boss_broodlord()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "boss_broodlord";
    pNewScript->GetAI = &GetAI_boss_broodlord;
    pNewScript->RegisterSelf();
}
