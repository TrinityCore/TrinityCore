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
SDName: mob_anubisath_sentinel
SD%Complete: 95
SDComment: Shadow storm is not properly implemented in core it should only target ppl outside of melee range.
SDCategory: Temple of Ahn'Qiraj
EndScriptData */

#include "precompiled.h"
#include "WorldPacket.h"

#include "Item.h"
#include "Player.h"
#include "Spell.h"

#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"

#define SPELL_MENDING_BUFF      2147

#define SPELL_KNOCK_BUFF        21737
#define SPELL_KNOCK             25778
#define SPELL_MANAB_BUFF        812
#define SPELL_MANAB             25779

#define SPELL_REFLECTAF_BUFF    13022
#define SPELL_REFLECTSFr_BUFF   19595
#define SPELL_THORNS_BUFF       25777

#define SPELL_THUNDER_BUFF      2834
#define SPELL_THUNDER           8732

#define SPELL_MSTRIKE_BUFF      9347
#define SPELL_MSTRIKE           24573

#define SPELL_STORM_BUFF        2148
#define SPELL_STORM             26546

struct TRINITY_DLL_DECL aqsentinelAI;
class TRINITY_DLL_DECL SentinelAbilityAura : public Aura
{
    public:
        ~SentinelAbilityAura();
        Unit* GetTriggerTarget() const;
        SentinelAbilityAura(aqsentinelAI *abilityOwner, SpellEntry *spell, uint32 ability, uint32 eff);
    protected:
        aqsentinelAI *aOwner;
        int32 currentBasePoints;
        uint32 abilityId;
};

struct TRINITY_DLL_DECL aqsentinelAI : public ScriptedAI
{
    uint32 ability;
    int abselected;

    void selectAbility(int asel)
    {
        switch (asel)
        {
            case 0: ability = SPELL_MENDING_BUFF;break;
            case 1: ability = SPELL_KNOCK_BUFF;break;
            case 2: ability = SPELL_MANAB_BUFF;break;
            case 3: ability = SPELL_REFLECTAF_BUFF;break;
            case 4: ability = SPELL_REFLECTSFr_BUFF;break;
            case 5: ability = SPELL_THORNS_BUFF;break;
            case 6: ability = SPELL_THUNDER_BUFF;break;
            case 7: ability = SPELL_MSTRIKE_BUFF;break;
            case 8: ability = SPELL_STORM_BUFF;break;
        }
    }

    aqsentinelAI(Creature *c) : ScriptedAI(c)
    {
        ClearBudyList();
        abselected = 0;                                     // just initialization of variable
    }

    Creature *nearby[3];

    void ClearBudyList()
    {
        nearby[0] = nearby[1] = nearby[2] = NULL;
    }

    void AddBuddyToList(Creature *c)
    {
        if (c==m_creature)
            return;
        for (int i=0; i<3; ++i)
        {
            if (nearby[i] == c)
                return;
            if (!nearby[i])
            {
                nearby[i] = c;
                return;
            }
        }
    }

    void GiveBuddyMyList(Creature *c)
    {
        aqsentinelAI *cai = CAST_AI(aqsentinelAI, (c)->AI());
        for (int i=0; i<3; ++i)
            if (nearby[i] && nearby[i]!=c)
                cai->AddBuddyToList(nearby[i]);
        cai->AddBuddyToList(m_creature);
    }

    void SendMyListToBuddies()
    {
        for (int i=0; i<3; ++i)
            if (nearby[i])
                GiveBuddyMyList(nearby[i]);
    }

    void CallBuddiesToAttack(Unit *who)
    {
        for (int i=0; i<3; ++i)
        {
            Creature *c = nearby[i];
            if (c)
            {
                if (!c->isInCombat())
                {
                    c->SetNoCallAssistance(true);
                    if(c->AI())
                        c->AI()->AttackStart(who);
                }
            }
        }
    }

    void AddSentinelsNear(Unit *nears)
    {
        std::list<Creature*> assistList;
        m_creature->GetCreatureListWithEntryInGrid(assistList,15264,70.0f);

        if (assistList.empty())
            return;

        for(std::list<Creature*>::iterator iter = assistList.begin(); iter != assistList.end(); ++iter)
            AddBuddyToList((*iter));
    }

    int pickAbilityRandom(bool *chosenAbilities)
    {
        for (int t = 0; t < 2; ++t)
        {
            for (int i = !t ? (rand()%9) : 0; i < 9; ++i)
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
        bool *chosenAbilities = new bool[9];
        memset(chosenAbilities, 0, 9*sizeof(bool));
        selectAbility(pickAbilityRandom(chosenAbilities));

        ClearBudyList();
        AddSentinelsNear(m_creature);
        int bli;
        for (bli = 0; bli < 3;bli++)
        {
            if (!nearby[bli])
                break;
            AddSentinelsNear(nearby[bli]);
            CAST_AI(aqsentinelAI, nearby[bli]->AI())->gatherOthersWhenAggro = false;
            CAST_AI(aqsentinelAI, nearby[bli]->AI())->selectAbility(pickAbilityRandom(chosenAbilities));
        }
        /*if (bli < 3)
            DoYell("I dont have enough buddies.", LANG_NEUTRAL, 0);*/
        SendMyListToBuddies();
        CallBuddiesToAttack(who);

        delete[] chosenAbilities;
    }

    bool gatherOthersWhenAggro;

    void Reset()
    {
        if (!m_creature->isDead())
        {
            for (int i=0; i<3; ++i)
            {
                if (!nearby[i])
                    continue;
                if (nearby[i]->isDead())
                    nearby[i]->Respawn();
            }
        }
        ClearBudyList();
        gatherOthersWhenAggro = true;
    }

    void GainSentinelAbility(uint32 id)
    {
        const SpellEntry *spell = GetSpellStore()->LookupEntry(id);
        uint8 eff_mask=0;
        for (int i=0; i<3; ++i)
        {
            if (!spell->Effect[i])
                continue;
            eff_mask=1<<i;
        }
        SentinelAbilityAura *a = new SentinelAbilityAura(this, (SpellEntry*)spell, id, eff_mask);
        m_creature->AddAura(a);
    }

    void EnterCombat(Unit *who)
    {
        if (gatherOthersWhenAggro)
            GetOtherSentinels(who);

        GainSentinelAbility(ability);
        DoZoneInCombat();
    }

    void JustDied(Unit* who)
    {
        for (int ni=0; ni<3; ni++)
        {
            Creature *sent = nearby[ni];
            if (!sent)
                continue;
            if (sent->isDead())
                continue;
            int h = sent->GetHealth() + (sent->GetMaxHealth() / 2);
            if (h > sent->GetMaxHealth())
                h = sent->GetMaxHealth();
            sent->SetHealth(h);
            CAST_AI(aqsentinelAI, sent->AI())->GainSentinelAbility(ability);
        }
    }

    Unit *GetHatedManaUser()
    {
        std::list<HostilReference*>::iterator i;
        for (i = m_creature->getThreatManager().getThreatList().begin();i != m_creature->getThreatManager().getThreatList().end(); ++i)
        {
            Unit* pUnit = Unit::GetUnit((*m_creature), (*i)->getUnitGuid());
            if (pUnit->getPowerType()==POWER_MANA)
                return pUnit;
        }
        return NULL;
    }
};
CreatureAI* GetAI_mob_anubisath_sentinelAI(Creature *_Creature)
{
    return new aqsentinelAI (_Creature);
}

void AddSC_mob_anubisath_sentinel()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="mob_anubisath_sentinel";
    newscript->GetAI = &GetAI_mob_anubisath_sentinelAI;
    newscript->RegisterSelf();
}

SentinelAbilityAura::~SentinelAbilityAura() {}
Unit* SentinelAbilityAura::GetTriggerTarget() const
{
    switch (abilityId)
    {
        case SPELL_KNOCK_BUFF:
        case SPELL_THUNDER_BUFF:
        case SPELL_MSTRIKE_BUFF:
        case SPELL_STORM_BUFF:
            return aOwner->m_creature->getVictim();

        case SPELL_MANAB_BUFF:
            return aOwner->GetHatedManaUser();

        case SPELL_MENDING_BUFF:
        case SPELL_REFLECTAF_BUFF:
        case SPELL_REFLECTSFr_BUFF:
        case SPELL_THORNS_BUFF:
        default:
            return aOwner->m_creature;
    }
}

SentinelAbilityAura::SentinelAbilityAura(aqsentinelAI *abilityOwner, SpellEntry *spell, uint32 ability, uint32 eff)
: Aura(spell, eff, NULL, abilityOwner->m_creature, abilityOwner->m_creature, NULL)
{
    aOwner = abilityOwner;
    abilityId = ability;
}

