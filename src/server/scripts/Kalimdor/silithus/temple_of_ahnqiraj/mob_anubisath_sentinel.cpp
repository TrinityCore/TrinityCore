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
SDName: mob_anubisath_sentinel
SD%Complete: 95
SDComment: Shadow storm is not properly implemented in core it should only target ppl outside of melee range.
SDCategory: Temple of Ahn'Qiraj
EndScriptData */

#include "scriptPCH.h"

enum
{
    SPELL_MENDING_BUFF =        2147,
    SPELL_KNOCK_BUFF =          21737,
    SPELL_KNOCK =               23382,
    SPELL_MANAB_BUFF =          812,
    SPELL_MANAB =               25779,

    SPELL_REFLECTAF_BUFF =      13022,
    SPELL_REFLECTSFr_BUFF =     19595,
    SPELL_THORNS_BUFF =         25777,

    SPELL_THUNDER_BUFF =        2834,
    SPELL_THUNDER =             23931,

    SPELL_MSTRIKE_BUFF =        9347,
    SPELL_MSTRIKE =             24573,

    SPELL_STORM_BUFF =          2148,
    SPELL_STORM =               26546,

    SPELL_ENRAGE =              24318,
    EMOTE_ENRAGE =              -1000003,

    SPELL_TRANSFER =            2400,
    EMOTE_TRANSFER =            -1388101,

    SPELL_HEAL_BRETHREN =       26565,

    NPC_SENTINEL =              15264
};

struct aqsentinelAI;

struct aqsentinelAI : public ScriptedAI
{
    uint32 m_abilitySpellId;
    uint32 m_uiKnock_Timer;
    bool m_bEnraged;
    bool m_bAlone;
    bool gatherOthersWhenAggro;
    ObjectGuidSet nearby;

    void selectAbility(int asel)
    {
        switch (asel)
        {
        case 0:
            m_abilitySpellId = SPELL_MENDING_BUFF;
            break;
        case 1:
            m_abilitySpellId = SPELL_MSTRIKE_BUFF;
            break;
        case 2:
            m_abilitySpellId = SPELL_STORM_BUFF;
            break;
        case 3:
            m_abilitySpellId = SPELL_REFLECTAF_BUFF;
            break;
        case 4:
            m_abilitySpellId = SPELL_REFLECTSFr_BUFF;
            break;
        case 5:
            m_abilitySpellId = SPELL_THORNS_BUFF;
            break;
        case 6:
            m_abilitySpellId = SPELL_THUNDER_BUFF;
            break;
        case 7:
            m_abilitySpellId = SPELL_KNOCK_BUFF;
            break;
        case 8:
            m_abilitySpellId = SPELL_MANAB_BUFF;
            break;
        }
    }

    aqsentinelAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        ClearBuddyList();
        m_bEnraged = false;
        m_abilitySpellId = 0;
        m_bAlone = false;
        Reset();
    }

    void MoveInLineOfSight(Unit* pWho) override
    {
        // Increase aggro radius
        if (pWho->GetTypeId() == TYPEID_PLAYER && !m_creature->IsInCombat() && m_creature->IsWithinDistInMap(pWho, 45.0f) && m_creature->IsWithinLOSInMap(pWho) && !pWho->HasAuraType(SPELL_AURA_FEIGN_DEATH))
        {
            AttackStart(pWho);
        }
        ScriptedAI::MoveInLineOfSight(pWho);
    }

    void ClearBuddyList()
    {
        nearby.clear();
    }

    void AddBuddyToList(Creature *buddy)
    {
        if (buddy == m_creature)
            return;

        if (nearby.find(buddy->GetObjectGuid()) != nearby.end())
            return;

        nearby.insert(buddy->GetObjectGuid());
    }

    void GiveBuddyMyList(ObjectGuid buddyGuid)
    {
        // Spread the buddy list. Add whoever is in my list to the buddy
        // as well.
        if (Creature* buddy = m_creature->GetMap()->GetCreature(buddyGuid))
        {
            if (aqsentinelAI* sentinelAI = dynamic_cast<aqsentinelAI*>(buddy->AI()))
            {
                for (const auto& guid : nearby)
                {
                    if (Creature* otherBuddy = m_creature->GetMap()->GetCreature(guid))
                    {
                        sentinelAI->AddBuddyToList(otherBuddy);
                    }
                }
                sentinelAI->AddBuddyToList(m_creature);
            }
        }
    }

    void SendMyListToBuddies()
    {
        for (const auto& guid : nearby)
        {
            GiveBuddyMyList(guid);
        }
    }

    void CallBuddiesToAttack(Unit *who)
    {
        for (const auto& guid : nearby)
        {
            if (Creature* creature = m_creature->GetMap()->GetCreature(guid))
            {
                if (creature->IsInCombat())
                    continue;

                creature->SetNoCallAssistance(true);
                if (creature->AI())
                    creature->AI()->AttackStart(who);
            }
        }
    }

    void AddSentinelsNear(Unit* source)
    {
        std::list<Creature*> assistList;
        GetCreatureListWithEntryInGrid(assistList, source, NPC_SENTINEL, 90.0f);

        if (assistList.empty())
            return;

        for (const auto& iter : assistList)
            AddBuddyToList(iter);
    }

    int pickAbilityRandom(std::vector<bool>& chosenAbilities)
    {
        for (int t = 0; t < 2; ++t)
        {
            for (int i = !t ? (rand() % 9) : 0; i < 9; ++i)
            {
                if (!chosenAbilities[i])
                {
                    chosenAbilities[i] = true;
                    return i;
                }
            }
        }
        return 0;                                           // should never happen
    }

    void GetOtherSentinels(Unit *who)
    {
        std::vector<bool> chosenAbilities(9);
        selectAbility(pickAbilityRandom(chosenAbilities));

        ClearBuddyList();
        AddSentinelsNear(m_creature);

        for (const auto& guid : nearby)
        {
            if (Creature* buddy = m_creature->GetMap()->GetCreature(guid))
            {
                if (aqsentinelAI* sentinelAI = dynamic_cast<aqsentinelAI*>(buddy->AI()))
                {
                    AddSentinelsNear(buddy);
                    sentinelAI->gatherOthersWhenAggro = false;
                    sentinelAI->selectAbility(pickAbilityRandom(chosenAbilities));
                }

            }
        }

        SendMyListToBuddies();
        CallBuddiesToAttack(who);
    }

    void Reset() override
    {
        if (!m_creature->IsDead())
        {
            for (const auto& guid : nearby)
            {
                if (Creature* buddy = m_creature->GetMap()->GetCreature(guid))
                {
                    if (buddy->IsDead())
                        buddy->Respawn();
                }
            }
        }

        ClearBuddyList();
        gatherOthersWhenAggro = true;
        m_uiKnock_Timer = 13000;
        m_bEnraged = false;
    }

    void GainSentinelAbility(uint32 id)
    {
        m_creature->AddAura(id);
    }

    // Threat reduction for Knock Away
    void SpellHitTarget(Unit* pTarget, SpellEntry const* pSpell) override
    {
        if ((pSpell->Id == SPELL_KNOCK) && pTarget->GetTypeId() == TYPEID_PLAYER)
        {
            if (m_creature->GetThreatManager().getThreat(m_creature->GetVictim()))
                m_creature->GetThreatManager().modifyThreatPercent(m_creature->GetVictim(), -20);
        }
    }

    void Aggro(Unit* pWho) override
    {
        if (gatherOthersWhenAggro)
            GetOtherSentinels(pWho);

        GainSentinelAbility(m_abilitySpellId);

        m_creature->SetInCombatWithZone();
    }

    // Transfer powers on death
    void JustDied(Unit* killer) override
    {
        m_bAlone = true;
        for (const auto& guid : nearby)
        {
            if (Creature* buddy = m_creature->GetMap()->GetCreature(guid))
            {
                if (buddy->IsDead())
                    continue;

                m_bAlone = false;

                DoCastSpellIfCan(buddy, SPELL_TRANSFER, CF_TRIGGERED);
                DoCastSpellIfCan(buddy, SPELL_HEAL_BRETHREN, CF_TRIGGERED);

                if (aqsentinelAI* sentinelAI = dynamic_cast<aqsentinelAI*>(buddy->AI()))
                {
                    sentinelAI->GainSentinelAbility(m_abilitySpellId);
                }
            }
        }

        if (!m_bAlone)
            DoScriptText(EMOTE_TRANSFER, m_creature);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        //Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_abilitySpellId == SPELL_KNOCK_BUFF)
        {
            if (m_uiKnock_Timer < uiDiff)
            {
                DoCastSpellIfCan(m_creature->GetVictim(), SPELL_KNOCK);
                m_uiKnock_Timer = 13000;
            }
            else
                m_uiKnock_Timer -= uiDiff;
        }

        if (!m_bEnraged && m_creature->GetHealthPercent() < 30.0f)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_ENRAGE) == CAST_OK)
            {
                DoScriptText(EMOTE_ENRAGE, m_creature);
                m_bEnraged = true;
            }
        }

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_mob_anubisath_sentinelAI(Creature* pCreature)
{
    return new aqsentinelAI(pCreature);
}

void AddSC_mob_anubisath_sentinel()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "mob_anubisath_sentinel";
    newscript->GetAI = &GetAI_mob_anubisath_sentinelAI;
    newscript->RegisterSelf();
}
